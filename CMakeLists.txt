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

if(NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
    message(FATAL_ERROR "32-bit target only for now (P1.12 moves to 64-bit)")
endif()

set(OVERLAYS stag0000 stag1000 stag1100 stag2000 stag3000 stag3500 stag4000)

# Flags for the game C. -funsigned-char: PS1 GCC char is unsigned. -fpermissive: GCC 14+ makes
# implicit declarations, int <-> pointer conversions and pointer type mismatches errors; the
# decomp C has many (cast-heavy matching code), so they stay warnings and are counted.
set(DW2_GAME_FLAGS
    -m32 -funsigned-char -fno-strict-aliasing -fwrapv -fno-common -fpermissive
    -Wall
    "-Wa,-I${CMAKE_SOURCE_DIR}"   # INCLUDE_BIN .incbin paths are relative to the repo root
)
set(DW2_DEFS DW2_NATIVE VER_USA _LANGUAGE_C)
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
    file(WRITE ${script}
        "OUTPUT_FORMAT(pe-i386)\n"   # ld -r with -T would otherwise write a PE image (pei-i386)
        "SECTIONS {\n"
        "  .data$dw2ovl_${unit}_1 : { *(.data) *(.data$*) }\n"
        "  .data$dw2ovl_${unit}_2 : { *(.bss) *(.bss$*) *(COMMON) }\n"
        "}\n")
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

# SDL3 (host/): the prebuilt MinGW development release, unpacked at DW2_SDL3 (holds
# i686-w64-mingw32/lib/cmake/SDL3). SDL3.dll is copied next to dw2.exe.
set(DW2_SDL3 "D:/tools/SDL3" CACHE PATH "SDL3 MinGW development release root")
find_package(SDL3 3.2 REQUIRED CONFIG COMPONENTS SDL3-shared
    PATHS ${DW2_SDL3}/i686-w64-mingw32 ${DW2_SDL3} NO_DEFAULT_PATH)

# Psy-Q layer, host and backend.
file(GLOB PSYQ_SRC CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/psyq/*.c)
file(GLOB HOST_SRC CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/host/*.c)
# Emulated PS1 hardware (backend/psxgpu.c: the GPU).
file(GLOB BACKEND_SRC CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/backend/*.c)

add_executable(dw2 ${PSYQ_SRC} ${HOST_SRC} ${BACKEND_SRC} $<TARGET_OBJECTS:dw2_main> ${OVL_OBJECTS})
target_compile_options(dw2 PRIVATE -m32 -funsigned-char -fno-strict-aliasing -fwrapv -fno-common -Wall
    "-Wa,-I${CMAKE_SOURCE_DIR}")
target_compile_definitions(dw2 PRIVATE DW2_NATIVE)
target_include_directories(dw2 PRIVATE ${DW2_INCLUDES})
# 16 MB-aligned fixed image base: the whole image (globals, Ps1_Ram, the heap) lies in one
# 16 MB window, which the 24-bit OT links need (psyq/ps1mem.h, host/main.c checks it).
target_link_libraries(dw2 PRIVATE SDL3::SDL3-shared)
add_custom_command(TARGET dw2 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:SDL3::SDL3-shared> $<TARGET_FILE_DIR:dw2>)
target_link_options(dw2 PRIVATE -m32 -Wl,--image-base=0x01000000 -Wl,--disable-dynamicbase
    -Wl,-Map=${CMAKE_BINARY_DIR}/dw2.map)
# host/pak.c compiles in configs/USA/pack_manifest.txt (.incbin): rebuild it when the manifest changes.
set_source_files_properties(${CMAKE_SOURCE_DIR}/host/pak.c PROPERTIES
    OBJECT_DEPENDS ${CMAKE_SOURCE_DIR}/configs/USA/pack_manifest.txt)
