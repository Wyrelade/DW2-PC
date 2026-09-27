/*
 * void MulMatrix2(ObjC0E4 *, ArgC0E4 *);
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel MulMatrix2
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
    lhu        $t0, 0x0($a1)
    lw         $t1, 0x4($a1)
    lw         $t2, 0xC($a1)
    lui        $at, (0xFFFF0000 >> 16)
    and        $t1, $t1, $at
    or         $t0, $t0, $t1
    mtc2       $t0, $0
    mtc2       $t2, $1
    nop
    mvmva      1, 0, 0, 3, 0
    lhu        $t0, 0x2($a1)
    lw         $t1, 0x8($a1)
    lh         $t2, 0xE($a1)
    sll        $t1, $t1, 16
    or         $t0, $t0, $t1
    mfc2       $t3, $9
    mfc2       $t4, $10
    mfc2       $t5, $11
    mtc2       $t0, $0
    mtc2       $t2, $1
    nop
    mvmva      1, 0, 0, 3, 0
    lhu        $t0, 0x4($a1)
    lw         $t1, 0x8($a1)
    lw         $t2, 0x10($a1)
    lui        $at, (0xFFFF0000 >> 16)
    and        $t1, $t1, $at
    or         $t0, $t0, $t1
    mfc2       $t6, $9
    mfc2       $t7, $10
    mfc2       $t8, $11
    mtc2       $t0, $0
    mtc2       $t2, $1
    nop
    mvmva      1, 0, 0, 3, 0
    andi       $t3, $t3, 0xFFFF
    sll        $t6, $t6, 16
    or         $t6, $t6, $t3
    sw         $t6, 0x0($a1)
    andi       $t5, $t5, 0xFFFF
    sll        $t8, $t8, 16
    or         $t8, $t8, $t5
    sw         $t8, 0xC($a1)
    mfc2       $t0, $9
    mfc2       $t1, $10
    andi       $t0, $t0, 0xFFFF
    sll        $t4, $t4, 16
    or         $t0, $t0, $t4
    sw         $t0, 0x4($a1)
    andi       $t7, $t7, 0xFFFF
    sll        $t1, $t1, 16
    or         $t1, $t1, $t7
    sw         $t1, 0x8($a1)
    swc2       $11, 0x10($a1)
    addu       $v0, $a1, $zero
    jr         $ra
     nop
endlabel MulMatrix2

    # alignment padding up to the next function
    nop
