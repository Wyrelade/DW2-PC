/*
 * InitPAD(a0, a1, a2, a3);
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel InitPAD
    addiu      $t2, $zero, 0xB0
    jr         $t2
     addiu      $t1, $zero, 0x12         # B0(0x12)
endlabel InitPAD

    # alignment padding up to the next function
    nop
