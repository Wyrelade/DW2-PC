#ifndef INCLUDE_ASM_H
#define INCLUDE_ASM_H

#ifdef DW2_NATIVE
/* Native build (DW2_NATIVE, CMakeLists.txt): no MIPS asm. What each macro means there:
 * - INCLUDE_ASM / INCLUDE_RODATA: nothing (no game C uses them; only main/psyq.c and
 *   stag1000_libpress.c, which the native build leaves out).
 * - ASM_SOURCE: nothing (crt0, replaced by host/main.c).
 * - SHIFT_TEST_PAD: nothing.
 * - INCLUDE_BIN: the same build-time extracted blob (assets/, configs/USA/include_bin.txt)
 *   pulled in by .incbin into the unit's .data under the C name. GCC writes top-level asm
 *   first, while in .text (default -ftoplevel-reorder), so the asm returns to .text.
 * - DATA_LABEL: nothing. Each alias name is a macro in the header that declares it, a real
 *   access to the object (a field, or a typed view at the offset of a blob). */
#define INCLUDE_ASM(FOLDER, NAME)
#define INCLUDE_RODATA(FOLDER, NAME)
#define ASM_SOURCE(FOLDER, NAME)
#define SHIFT_TEST_PAD(N)
#define DATA_LABEL(NAME, OBJECT, OFFSET)
#define NATIVE_ASM_STR_(x) #x
#define NATIVE_ASM_XSTR_(x) NATIVE_ASM_STR_(x)
#define NATIVE_ASM_NAME_(NAME) NATIVE_ASM_XSTR_(__USER_LABEL_PREFIX__) #NAME
#define INCLUDE_BIN(NAME, PATH) \
    __asm__( \
        ".data\n" \
        "    .balign 16\n" \
        "    .globl " NATIVE_ASM_NAME_(NAME) "\n" \
        NATIVE_ASM_NAME_(NAME) ":\n" \
        "    .incbin \"" PATH "\"\n" \
        ".text" \
    )
#else /* !DW2_NATIVE */

#if !defined(M2CTX) && !defined(PERMUTER) && !defined(SKIP_ASM)

#if !defined(INCLUDE_ASM) && defined(INCLUDE_ASM_IN_FUNC)
/* -G > 0: cc1 writes function text after file-scope asm, so the include sits in a
 * function whose own code maspsx drops (only the maspsx-keep lines survive). */
#define INCLUDE_ASM(FOLDER, NAME) \
    void __maspsx_include_asm_hack_##NAME() { \
        __asm__( \
            ".text # maspsx-keep\n" \
            "\t.align\t2 # maspsx-keep\n" \
            "\t.set noreorder # maspsx-keep\n" \
            "\t.set noat # maspsx-keep\n" \
            ".include \"" FOLDER "/" #NAME ".s\" # maspsx-keep\n" \
            "\t.set reorder # maspsx-keep\n" \
            "\t.set at # maspsx-keep\n" \
        ); \
    }
#if !defined(INCLUDE_RODATA)
/* same for rodata: file-scope asm would land in front of every cc1 jump table */
#define INCLUDE_RODATA(FOLDER, NAME) \
    void __maspsx_include_asm_hack_rodata_##NAME() { \
        __asm__( \
            ".section .rodata # maspsx-keep\n" \
            ".include \"" FOLDER "/" #NAME ".s\" # maspsx-keep\n" \
            ".section .text # maspsx-keep\n" \
        ); \
    }
#endif
#endif
#ifndef INCLUDE_ASM
#define INCLUDE_ASM(FOLDER, NAME) \
    __asm__( \
        ".section .text\n" \
        "    .set noat\n" \
        "    .set noreorder\n" \
        "    .include \"" FOLDER "/" #NAME ".s\"\n" \
        "    .set reorder\n" \
        "    .set at\n" \
    )
#endif
#ifndef INCLUDE_RODATA
#define INCLUDE_RODATA(FOLDER, NAME) \
    __asm__( \
        ".section .rodata\n" \
        "    .include \"" FOLDER "/" #NAME ".s\"\n" \
        ".section .text" \
    )
#endif

#if INCLUDE_ASM_USE_MACRO_INC
__asm__(".include \"include/macro.inc\"\n");
#else
__asm__(".include \"include/labels.inc\"\n");
#endif

#else

#ifndef INCLUDE_ASM
#define INCLUDE_ASM(FOLDER, NAME)
#endif
#ifndef INCLUDE_RODATA
#define INCLUDE_RODATA(FOLDER, NAME)
#endif

#endif /* !defined(M2CTX) && !defined(PERMUTER) */

/* SHIFT_TEST_PAD: shift test (tools/build_dw2.py --shift-test). Pads the start of the unit's
 * .rodata, .data and .text by N bytes, so every address behind it moves. That image does not
 * match retail; it has to run, which shows no code or data holds a fixed address. */
#if defined(SHIFT_TEST) && !defined(M2CTX) && !defined(PERMUTER)
#define SHIFT_TEST_PAD(N) \
    __asm__( \
        ".section .rodata\n.space " #N "\n" \
        ".section .data\n.space " #N "\n" \
        ".section .text\n.space " #N "\n" \
    )
#else
#define SHIFT_TEST_PAD(N)
#endif

/* INCLUDE_BIN: opaque game content (bitmaps, CLUTs, text, sound) inside a unit's .data, at
 * this spot in definition order (-G0 units: cc1 writes data in source order). The bytes are
 * not in the repo: tools/build_dw2.py extracts them from the disc files into assets/ as
 * configs/USA/include_bin.txt lists. NAME is a global label at the first byte. */
#if !defined(M2CTX) && !defined(PERMUTER)
#define INCLUDE_BIN(NAME, PATH) \
    __asm__( \
        ".section .data\n" \
        "    .align 2\n" \
        "    .global " #NAME "\n" \
        #NAME ":\n" \
        "    .incbin \"" PATH "\"\n" \
        ".previous" \
    )
/* DATA_LABEL: a global symbol OFFSET bytes into a data object or INCLUDE_BIN, for code that
 * refers to that spot by a symbol of its own type: a part of opaque content (the CLUT of a
 * TIM), or an object the code reads as a plain array (cc1 only keeps the retail codegen
 * when the code indexes an array-typed symbol, not a cast of the object's address). */
#define DATA_LABEL(NAME, OBJECT, OFFSET) \
    __asm__(".global " #NAME "\n.set " #NAME ", " #OBJECT " + " #OFFSET)
#else
#define INCLUDE_BIN(NAME, PATH)
#define DATA_LABEL(NAME, OBJECT, OFFSET)
#endif

/* ASM_SOURCE: a function that was hand-written assembly in the original build, restored as
 * readable source under src/ (tools/asm_restore.py). Included in place like INCLUDE_ASM, but it
 * is part of the decompiled object (not skipped under SKIP_ASM) and carries no NON_MATCHING mark. */
#if !defined(M2CTX) && !defined(PERMUTER)
#ifndef ASM_SOURCE
#define ASM_SOURCE(FOLDER, NAME) \
    __asm__( \
        ".section .text\n" \
        "    .set noat\n" \
        "    .set noreorder\n" \
        "    .include \"" FOLDER "/" #NAME ".s\"\n" \
        "    .set reorder\n" \
        "    .set at\n" \
    )
#endif
#if defined(SKIP_ASM)
__asm__(".include \"include/labels.inc\"\n");
#endif
#else
#ifndef ASM_SOURCE
#define ASM_SOURCE(FOLDER, NAME)
#endif
#endif

#endif /* DW2_NATIVE */

#endif /* INCLUDE_ASM_H */
