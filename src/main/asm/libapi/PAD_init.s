/*
 * PAD_init(a0, a1, a2, a3);
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel PAD_init
    addiu      $t2, $zero, 0xB0
    jr         $t2
     addiu      $t1, $zero, 0x15         # B0(0x15)
endlabel PAD_init

    # alignment padding up to the next function
    nop
