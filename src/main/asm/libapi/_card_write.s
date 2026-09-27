/*
 * s32 _card_write();
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel _card_write
    addiu      $t2, $zero, 0xB0
    jr         $t2
     addiu      $t1, $zero, 0x4E         # B0(0x4E)
endlabel _card_write

    # alignment padding up to the next function
    nop
