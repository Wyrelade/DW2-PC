#ifndef INCLUDE_ASM_H
#define INCLUDE_ASM_H

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

#endif /* INCLUDE_ASM_H */
