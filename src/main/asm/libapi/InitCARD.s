/*
 * void InitCARD(s32);
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel InitCARD
    addiu      $t2, $zero, 0xB0
    jr         $t2
     addiu      $t1, $zero, 0x4A         # B0(0x4A)
endlabel InitCARD

    # alignment padding up to the next function
    nop
