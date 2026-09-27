/*
 * DeliverEvent(0xF0000009, 0x20);
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel DeliverEvent
    addiu      $t2, $zero, 0xB0
    jr         $t2
     addiu      $t1, $zero, 0x7          # B0(0x07)
endlabel DeliverEvent

    # alignment padding up to the next function
    nop
