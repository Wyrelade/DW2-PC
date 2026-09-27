/*
 * _bu_init();
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel _bu_init
    addiu      $t2, $zero, 0xA0
    jr         $t2
     addiu      $t1, $zero, 0x70         # A0(0x70)
endlabel _bu_init

    # alignment padding up to the next function
    nop
