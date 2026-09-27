/*
 * void _card_info(s32);
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel _card_info
    addiu      $t2, $zero, 0xA0
    jr         $t2
     addiu      $t1, $zero, 0xAB         # A0(0xAB)
endlabel _card_info

    # alignment padding up to the next function
    nop
