/*
 * s32 firstfile();
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel firstfile
    addiu      $t2, $zero, 0xB0
    jr         $t2
     addiu      $t1, $zero, 0x42         # B0(0x42)
endlabel firstfile

    # alignment padding up to the next function
    nop
