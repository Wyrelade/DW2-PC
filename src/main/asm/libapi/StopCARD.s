/*
 * StopCARD();
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel StopCARD
    addiu      $t2, $zero, 0xB0
    jr         $t2
     addiu      $t1, $zero, 0x4C         # B0(0x4C)
endlabel StopCARD

    # alignment padding up to the next function
    nop
