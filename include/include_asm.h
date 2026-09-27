#ifndef INCLUDE_ASM_H
#define INCLUDE_ASM_H

#if !defined(M2CTX) && !defined(PERMUTER) && !defined(SKIP_ASM)

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
