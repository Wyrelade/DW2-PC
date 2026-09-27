/*
 * s32 lseek(s32, s32, s32);
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel lseek
    addiu      $t2, $zero, 0xB0
    jr         $t2
     addiu      $t1, $zero, 0x33         # B0(0x33)
endlabel lseek

    # alignment padding up to the next function
    nop
