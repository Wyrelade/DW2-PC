/*
 * void ChangeClearRCnt(s32, s32);
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel ChangeClearRCnt
    addiu      $t2, $zero, 0xC0
    jr         $t2
     addiu      $t1, $zero, 0xA          # C0(0x0A)
endlabel ChangeClearRCnt

    # alignment padding up to the next function
    nop
