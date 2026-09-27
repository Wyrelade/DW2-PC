/*
 * StartPAD();
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel StartPAD
    addiu      $t2, $zero, 0xB0
    jr         $t2
     addiu      $t1, $zero, 0x13         # B0(0x13)
endlabel StartPAD

    # alignment padding up to the next function
    nop
