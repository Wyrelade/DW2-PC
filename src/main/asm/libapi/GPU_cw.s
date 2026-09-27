/*
 * void GPU_cw(s32);
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel GPU_cw
    addiu      $t2, $zero, 0xA0
    jr         $t2
     addiu      $t1, $zero, 0x49         # A0(0x49)
endlabel GPU_cw

    # alignment padding up to the next function
    nop
