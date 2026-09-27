/*
 * RotTransPers(&v[0], &p->xy[0], &pz, &flag);
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel RotTransPers
    lwc2       $0, 0x0($a0)
    lwc2       $1, 0x4($a0)
    nop
    rtps
    swc2       $14, 0x0($a1)
    swc2       $8, 0x0($a2)
    cfc2       $v1, $31
    mfc2       $v0, $19
    sw         $v1, 0x0($a3)
    jr         $ra
     sra        $v0, $v0, 2
endlabel RotTransPers

    # alignment padding up to the next function
    nop
