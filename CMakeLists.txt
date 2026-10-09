# Native PC build (DW2_NATIVE): the game C of main and all 7 overlays linked into one program,
# with the Psy-Q layer in psyq/ and the host in host/. The matching PS1 build is
# tools/build_dw2.py and does not use this file.
#
# One command: venv/Scripts/python.exe tools/build_native.py (configures and builds with Ninja).

cmake_minimum_required(VERSION 3.20)
project(dw2_native C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

# Dev build (PD): the ImGui dev overlay (F2, host/devui.cpp) and every PD dev tool. OFF is the
# release client (tools/build_native.py --release): no dev tool compiled in; it keeps C++ and
# Dear ImGui (host/imgui/) for the F1 settings window only (PR.2). C and C++ test #if DW2_DEV.
option(DW2_DEV "dev build: ImGui dev overlay and PD dev tools" ON)
enable_language(CXX)
if(DW2_DEV)
    set(DW2_DEV_VALUE 1)
else()
    set(DW2_DEV_VALUE 0)
endif()

# Target: 32-bit (-m32, MinGW i686) or 64-bit (-m64, MinGW x86_64 or Linux gcc), picked by the
# compiler tools/build_native.py configures (--arch). Every build keeps the "low window" layout:
# the image, its globals, Ps1_Ram and the heap lie in one 16 MB window below 2 GB (fixed base,
# no ASLR), so the 24-bit OT links resolve and a pointer kept in a 32-bit game int round-trips.
if(CMAKE_SIZEOF_VOID_P EQUAL 4)
    # The i686 GCC keeps only a 4-byte aligned stack by default; SDL3.dll's SSE code needs 16 at
    # every call into it (PR.14). Keep 16 everywhere; the entry points realign (HOST_ENTRY).
    set(DW2_ARCH_FLAG -m32 -mpreferred-stack-boundary=4)
elseif(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(DW2_ARCH_FLAG -m64)
else()
    message(FATAL_ERROR "unsupported pointer size ${CMAKE_SIZEOF_VOID_P}")
endif()
if(WIN32)
    if(CMAKE_SIZEOF_VOID_P EQUAL 4)
        set(DW2_PE_FORMAT pe-i386)
        set(DW2_MINGW_TRIPLET i686-w64-mingw32)
    else()
        set(DW2_PE_FORMAT pe-x86-64)
        set(DW2_MINGW_TRIPLET x86_64-w64-mingw32)
    endif()
    set(DW2_PIE_FLAGS)
else()
    # ELF: a position-dependent executable, so the fixed base below holds.
    set(DW2_PIE_FLAGS -fno-pie)
endif()

set(OVERLAYS stag0000 stag1000 stag1100 stag2000 stag3000 stag3500 stag4000)

# Flags for the game C. -funsigned-char: PS1 GCC char is unsigned. -fpermissive: GCC 14+ makes
# implicit declarations, int <-> pointer conversions and pointer type mismatches errors; the
# decomp C has many (cast-heavy matching code), so they stay warnings and are counted.
set(DW2_GAME_FLAGS
    ${DW2_ARCH_FLAG} ${DW2_PIE_FLAGS} -funsigned-char -fno-strict-aliasing -fwrapv -fno-common -fpermissive
    -Wall
    "-Wa,-I${CMAKE_SOURCE_DIR}"   # INCLUDE_BIN .incbin paths are relative to the repo root
)
set(DW2_DEFS DW2_NATIVE DW2_DEV=${DW2_DEV_VALUE} VER_USA _LANGUAGE_C)
set(DW2_INCLUDES ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR})

function(dw2_game_objects target)
    add_library(${target} OBJECT ${ARGN})
    target_compile_options(${target} PRIVATE ${DW2_GAME_FLAGS})
    target_compile_definitions(${target} PRIVATE ${DW2_DEFS})
    target_include_directories(${target} PRIVATE ${DW2_INCLUDES})
endfunction()

# main: every src/main C file except psyq.c (the Psy-Q asm) and the crt0 asm sources.
file(GLOB MAIN_SRC CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/src/main/*.c)
list(FILTER MAIN_SRC EXCLUDE REGEX "/psyq\\.c$")
dw2_game_objects(dw2_main ${MAIN_SRC})

# Overlays. Retail Ovl_Load copies the overlay file over the overlay area at each scene switch,
# so its .data and .bss restart from their initial values. Here each overlay's objects are
# relinked (ld -r) so that its .data and .bss become the grouped sections
# .data$dw2ovl_<unit>_1 / _2; host/overlay.c brackets them with _0 / _3 markers. The final link
# sorts .data$* by name, so each overlay's data is one range that Ovl_Load restores.
set(OVL_OBJECTS)
foreach(unit ${OVERLAYS})
    file(GLOB OVL_SRC CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/src/${unit}/*.c)
    list(FILTER OVL_SRC EXCLUDE REGEX "/stag1000_libpress\\.c$")
    dw2_game_objects(dw2_${unit} ${OVL_SRC})

    set(script ${CMAKE_BINARY_DIR}/ovl_${unit}.ld)
    if(WIN32)
        file(WRITE ${script}
            "OUTPUT_FORMAT(${DW2_PE_FORMAT})
"   # ld -r with -T would otherwise write a PE image
            "SECTIONS {
"
            "  .data$dw2ovl_${unit}_1 : { *(.data) *(.data$*) }
"
            "  .data$dw2ovl_${unit}_2 : { *(.bss) *(.bss$*) *(COMMON) }
"
            "}
")
    else()
        # ELF: one section per overlay with a C-identifier name, so the final link defines
        # __start_dw2ovl_<unit> / __stop_dw2ovl_<unit> (host/overlay.c). The .bss goes in with
        # the .data (stored as zero bytes in the file).
        file(WRITE ${script}
            "SECTIONS {
"
            "  dw2ovl_${unit} : { *(.data) *(.data.*) *(.bss) *(.bss.*) *(COMMON) }
"
            "}
")
    endif()
    set(out ${CMAKE_BINARY_DIR}/ovl_${unit}.o)
    add_custom_command(
        OUTPUT ${out}
        COMMAND ${CMAKE_LINKER} -r -T ${script} -o ${out} $<TARGET_OBJECTS:dw2_${unit}>
        DEPENDS dw2_${unit} $<TARGET_OBJECTS:dw2_${unit}> ${script}
        COMMAND_EXPAND_LISTS
        COMMENT "Relinking ${unit} (overlay data range)")
    list(APPEND OVL_OBJECTS ${out})
endforeach()
set_source_files_properties(${OVL_OBJECTS} PROPERTIES EXTERNAL_OBJECT TRUE GENERATED TRUE)

# SDL3 (host/). Windows: the prebuilt MinGW development release, unpacked at DW2_SDL3 (holds
# i686-w64-mingw32 and x86_64-w64-mingw32 lib/cmake/SDL3); SDL3.dll is copied next to dw2.exe.
# Linux: the system package (libsdl3-dev).
if(WIN32)
    set(DW2_SDL3 "D:/tools/SDL3" CACHE PATH "SDL3 MinGW development release root")
    find_package(SDL3 3.2 REQUIRED CONFIG COMPONENTS SDL3-shared
        PATHS ${DW2_SDL3}/${DW2_MINGW_TRIPLET} NO_DEFAULT_PATH)
else()
    find_package(SDL3 3.2 REQUIRED CONFIG COMPONENTS SDL3-shared)
endif()

# Psy-Q layer, host and backend.
file(GLOB PSYQ_SRC CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/psyq/*.c)
file(GLOB HOST_SRC CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/host/*.c)
# Emulated PS1 hardware (backend/psxgpu.c: the GPU).
file(GLOB BACKEND_SRC CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/backend/*.c)

# ImGui layer (PR.2, release and dev): host/ui.cpp + host/settingsui.cpp (the F1 settings window)
# on Dear ImGui (pinned, host/imgui/README.txt) with its SDL3 platform and SDL_Renderer backends.
# Dev builds add host/devui.cpp (the PD.1 overlay, F2) and imgui_demo.cpp. No exceptions, RTTI or
# thread-safe statics: ImGui needs none, so nothing of the C++ runtime but what g++ links by itself.
set(UI_SRC ${CMAKE_SOURCE_DIR}/host/ui.cpp ${CMAKE_SOURCE_DIR}/host/settingsui.cpp)
set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/host/imgui)
set(IMGUI_SRC
    ${IMGUI_DIR}/imgui.cpp ${IMGUI_DIR}/imgui_draw.cpp ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/backends/imgui_impl_sdl3.cpp ${IMGUI_DIR}/backends/imgui_impl_sdlrenderer3.cpp)
if(DW2_DEV)
    list(APPEND UI_SRC ${CMAKE_SOURCE_DIR}/host/devui.cpp)
    list(APPEND IMGUI_SRC ${IMGUI_DIR}/imgui_demo.cpp)
endif()
add_library(dw2_imgui OBJECT ${IMGUI_SRC})
target_compile_options(dw2_imgui PRIVATE ${DW2_ARCH_FLAG} ${DW2_PIE_FLAGS} -fno-exceptions -fno-rtti
    -fno-threadsafe-statics)
if(NOT DW2_DEV)
    target_compile_definitions(dw2_imgui PRIVATE IMGUI_DISABLE_DEMO_WINDOWS)
endif()
target_include_directories(dw2_imgui PRIVATE ${IMGUI_DIR})
target_link_libraries(dw2_imgui PRIVATE SDL3::SDL3-shared)
set(DEV_SRC ${UI_SRC} $<TARGET_OBJECTS:dw2_imgui>)

# Windows: the program icon (host/dw2.rc -> misc/icon/dw2.ico) through windres. A custom command
# run from the repo root with relative paths: windres hands -I paths unquoted to its preprocessor,
# so the usual RC language support breaks on a source path with spaces.
set(ICON_SRC)
if(WIN32)
    get_filename_component(DW2_TOOLBIN ${CMAKE_C_COMPILER} DIRECTORY)
    find_program(DW2_WINDRES windres HINTS ${DW2_TOOLBIN} REQUIRED)
    set(ICON_SRC ${CMAKE_BINARY_DIR}/dw2_icon.o)
    add_custom_command(OUTPUT ${ICON_SRC}
        COMMAND ${DW2_WINDRES} -O coff host/dw2.rc ${ICON_SRC}
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        DEPENDS ${CMAKE_SOURCE_DIR}/host/dw2.rc ${CMAKE_SOURCE_DIR}/misc/icon/dw2.ico
        VERBATIM)
    set_source_files_properties(${ICON_SRC} PROPERTIES EXTERNAL_OBJECT TRUE GENERATED TRUE)
endif()
add_executable(dw2 ${PSYQ_SRC} ${HOST_SRC} ${BACKEND_SRC} ${DEV_SRC} ${ICON_SRC} $<TARGET_OBJECTS:dw2_main> ${OVL_OBJECTS})
target_compile_options(dw2 PRIVATE ${DW2_ARCH_FLAG} ${DW2_PIE_FLAGS} -fno-strict-aliasing -fwrapv -fno-common -Wall
    "-Wa,-I${CMAKE_SOURCE_DIR}"
    $<$<COMPILE_LANGUAGE:C>:-funsigned-char>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions -fno-rtti -fno-threadsafe-statics>)
target_compile_definitions(dw2 PRIVATE DW2_NATIVE DW2_DEV=${DW2_DEV_VALUE})
target_include_directories(dw2 PRIVATE ${CMAKE_SOURCE_DIR}/host/imgui)
target_include_directories(dw2 PRIVATE ${DW2_INCLUDES})
# 16 MB-aligned fixed image base: the whole image (globals, Ps1_Ram, the heap) lies in one
# 16 MB window, which the 24-bit OT links need (psyq/ps1mem.h, host/main.c checks it).
target_link_libraries(dw2 PRIVATE SDL3::SDL3-shared)
if(WIN32)
    add_custom_command(TARGET dw2 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:SDL3::SDL3-shared> $<TARGET_FILE_DIR:dw2>)
    # 64-bit PE: also no high-entropy ASLR, so the stack stays low as well.
    # The C++ runtime parts g++ links come in statically (no libstdc++ DLL to ship).
    target_link_options(dw2 PRIVATE -static-libstdc++ -static-libgcc)
    # Release: a GUI program, no console window next to the game (host/winconsole.c). Dev builds
    # keep the console for the logs.
    if(NOT DW2_DEV)
        target_link_options(dw2 PRIVATE -mwindows)
    endif()
    target_link_options(dw2 PRIVATE ${DW2_ARCH_FLAG} -Wl,--image-base=0x01000000 -Wl,--disable-dynamicbase
        $<$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>:-Wl,--disable-high-entropy-va>
        -Wl,-Map=${CMAKE_BINARY_DIR}/dw2.map)
else()
    # ELF: no PIE, first segment at 0x01000000 (same window as the PE builds).
    target_link_libraries(dw2 PRIVATE m)
    target_link_options(dw2 PRIVATE ${DW2_ARCH_FLAG} -no-pie -Wl,-Ttext-segment=0x01000000
        -Wl,-Map=${CMAKE_BINARY_DIR}/dw2.map)
    # A libSDL3.so.0 next to dw2 is found before the system one (player zip, PR.8).
    set_target_properties(dw2 PROPERTIES BUILD_RPATH "$ORIGIN")
endif()
# host/pak.c compiles in configs/USA/pack_manifest.txt (.incbin): rebuild it when the manifest changes.
set_source_files_properties(${CMAKE_SOURCE_DIR}/host/pak.c PROPERTIES
    OBJECT_DEPENDS ${CMAKE_SOURCE_DIR}/configs/USA/pack_manifest.txt)
# psyq/libgte.c pulls in the retail ratan_tbl (.incbin, configs/USA/include_bin_native.txt).
set_source_files_properties(${CMAKE_SOURCE_DIR}/psyq/libgte.c PROPERTIES
    OBJECT_DEPENDS ${CMAKE_SOURCE_DIR}/assets/main/ratan_tbl.bin)
# psyq/snd_hw.c pulls in the retail rodata / data image for the libsnd / libspu globals.
set_source_files_properties(${CMAKE_SOURCE_DIR}/psyq/snd_hw.c PROPERTIES
    OBJECT_DEPENDS "${CMAKE_SOURCE_DIR}/assets/main/retail_rodata.bin;${CMAKE_SOURCE_DIR}/assets/main/retail_data.bin")

# GTE model test (tests/gte_test.c): build/native/gte_test.exe, run from the repo root.
add_executable(gte_test ${CMAKE_SOURCE_DIR}/tests/gte_test.c ${CMAKE_SOURCE_DIR}/psyq/gte.c
    ${CMAKE_SOURCE_DIR}/psyq/libgte.c ${CMAKE_SOURCE_DIR}/psyq/psyq_log.c)
target_compile_options(gte_test PRIVATE ${DW2_ARCH_FLAG} -fno-strict-aliasing -fwrapv -Wall "-Wa,-I${CMAKE_SOURCE_DIR}")
target_include_directories(gte_test PRIVATE ${CMAKE_SOURCE_DIR}/psyq)
target_link_options(gte_test PRIVATE ${DW2_ARCH_FLAG})
if(NOT WIN32)
    target_link_libraries(gte_test PRIVATE m)
endif()
