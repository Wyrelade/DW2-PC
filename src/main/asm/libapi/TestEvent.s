/*
 * r = TestEvent(D_8004FDB0);
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel TestEvent
    addiu      $t2, $zero, 0xB0
    jr         $t2
     addiu      $t1, $zero, 0xB          # B0(0x0B)
endlabel TestEvent

    # alignment padding up to the next function
    nop
