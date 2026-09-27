/*
 * void EnableEvent(s32);
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel EnableEvent
    addiu      $t2, $zero, 0xB0
    jr         $t2
     addiu      $t1, $zero, 0xC          # B0(0x0C)
endlabel EnableEvent

    # alignment padding up to the next function
    nop
