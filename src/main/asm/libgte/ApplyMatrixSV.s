/*
 * void ApplyMatrixSV(void *, SVec1D104 *, DVec1D104 *);
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel ApplyMatrixSV
    lw         $t0, 0x0($a0)
    lw         $t1, 0x4($a0)
    lw         $t2, 0x8($a0)
    lw         $t3, 0xC($a0)
    lw         $t4, 0x10($a0)
    ctc2       $t0, $0
    ctc2       $t1, $1
    ctc2       $t2, $2
    ctc2       $t3, $3
    ctc2       $t4, $4
    lwc2       $0, 0x0($a1)
    lwc2       $1, 0x4($a1)
    nop
    mvmva      1, 0, 0, 3, 0
    mfc2       $t0, $9
    mfc2       $t1, $10
    mfc2       $t2, $11
    sh         $t0, 0x0($a2)
    sh         $t1, 0x2($a2)
    sh         $t2, 0x4($a2)
    addu       $v0, $a2, $zero
    jr         $ra
     nop
endlabel ApplyMatrixSV

    # alignment padding up to the next function
    nop
