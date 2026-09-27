/*
 * void _new_card();
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel _new_card
    addiu      $t2, $zero, 0xB0
    jr         $t2
     addiu      $t1, $zero, 0x50         # B0(0x50)
endlabel _new_card

    # alignment padding up to the next function
    nop
