/*
 * void WaitEvent(s32);
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel WaitEvent
    addiu      $t2, $zero, 0xB0
    jr         $t2
     addiu      $t1, $zero, 0xA          # B0(0x0A)
endlabel WaitEvent

    # alignment padding up to the next function
    nop
