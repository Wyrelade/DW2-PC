/*
 * s32 SetTransMatrix();
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel SetTransMatrix
    lw         $t0, 0x14($a0)
    lw         $t1, 0x18($a0)
    lw         $t2, 0x1C($a0)
    ctc2       $t0, $5
    ctc2       $t1, $6
    ctc2       $t2, $7
    jr         $ra
     nop
endlabel SetTransMatrix
