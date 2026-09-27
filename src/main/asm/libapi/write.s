/*
 * s32 write(s32, u8 *, s32);
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel write
    addiu      $t2, $zero, 0xB0
    jr         $t2
     addiu      $t1, $zero, 0x35         # B0(0x35)
endlabel write

    # alignment padding up to the next function
    nop
