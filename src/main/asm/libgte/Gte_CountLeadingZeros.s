/*
 * e = 12 - Gte_CountLeadingZeros(x);
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel Gte_CountLeadingZeros
    mtc2       $a0, $30
    nop
    nop
    mfc2       $v0, $31
    jr         $ra
     nop
endlabel Gte_CountLeadingZeros

    # alignment padding up to the next function
    nop
    nop
