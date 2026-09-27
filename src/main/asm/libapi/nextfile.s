/*
 * s32 nextfile(Ent3EF1C *);
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel nextfile
    addiu      $t2, $zero, 0xB0
    jr         $t2
     addiu      $t1, $zero, 0x43         # B0(0x43)
endlabel nextfile

    # alignment padding up to the next function
    nop
