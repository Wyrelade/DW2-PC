/*
 * void ChangeClearPAD(s32);
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel ChangeClearPAD
    addiu      $t2, $zero, 0xB0
    jr         $t2
     addiu      $t1, $zero, 0x5B         # B0(0x5B)
endlabel ChangeClearPAD

    # alignment padding up to the next function
    nop
