/*
 * SetBackColor()
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel SetBackColor
    sll        $a0, $a0, 4
    sll        $a1, $a1, 4
    sll        $a2, $a2, 4
    ctc2       $a0, $13
    ctc2       $a1, $14
    ctc2       $a2, $15
    jr         $ra
     nop
endlabel SetBackColor
