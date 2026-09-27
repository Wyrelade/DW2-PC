/*
 * void SetGeomOffset(s32, s32);
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel SetGeomOffset
    sll        $a0, $a0, 16
    sll        $a1, $a1, 16
    ctc2       $a0, $24
    ctc2       $a1, $25
    jr         $ra
     nop
endlabel SetGeomOffset

    # alignment padding up to the next function
    nop
    nop
