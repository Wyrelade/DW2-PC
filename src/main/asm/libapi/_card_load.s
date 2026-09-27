/*
 * void _card_load(s32);
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel _card_load
    addiu      $t2, $zero, 0xA0
    jr         $t2
     addiu      $t1, $zero, 0xAC         # A0(0xAC)
endlabel _card_load

    # alignment padding up to the next function
    nop
