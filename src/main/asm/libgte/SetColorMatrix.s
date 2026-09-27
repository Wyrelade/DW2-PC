/*
 * void SetColorMatrix(S32 *);
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel SetColorMatrix
    lw         $t0, 0x0($a0)
    lw         $t1, 0x4($a0)
    lw         $t2, 0x8($a0)
    lw         $t3, 0xC($a0)
    lw         $t4, 0x10($a0)
    ctc2       $t0, $16
    ctc2       $t1, $17
    ctc2       $t2, $18
    ctc2       $t3, $19
    ctc2       $t4, $20
    jr         $ra
     nop
endlabel SetColorMatrix
