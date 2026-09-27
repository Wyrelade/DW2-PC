/*
 * s32 open(u8 *, s32);
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel open
    addiu      $t2, $zero, 0xB0
    jr         $t2
     addiu      $t1, $zero, 0x32         # B0(0x32)
endlabel open

    # alignment padding up to the next function
    nop
