/*
 * void close(s32);
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel close
    addiu      $t2, $zero, 0xB0
    jr         $t2
     addiu      $t1, $zero, 0x36         # B0(0x36)
endlabel close

    # alignment padding up to the next function
    nop
