/*
 * void SetFarColor(s32, s32, s32);
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel SetFarColor
    sll        $a0, $a0, 4
    sll        $a1, $a1, 4
    sll        $a2, $a2, 4
    ctc2       $a0, $21
    ctc2       $a1, $22
    ctc2       $a2, $23
    jr         $ra
     nop
endlabel SetFarColor
