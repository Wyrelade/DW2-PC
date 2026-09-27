/*
 * s32 OpenEvent(s32, s32, s32, s32);
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel OpenEvent
    addiu      $t2, $zero, 0xB0
    jr         $t2
     addiu      $t1, $zero, 0x8          # B0(0x08)
endlabel OpenEvent

    # alignment padding up to the next function
    nop
