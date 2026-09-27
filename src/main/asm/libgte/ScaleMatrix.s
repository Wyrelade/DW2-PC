/*
 * void ScaleMatrix(Obj209 *, s32 *);
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel ScaleMatrix
    lw         $t3, 0x0($a1)
    lw         $t4, 0x4($a1)
    lw         $t5, 0x8($a1)
    lw         $t0, 0x0($a0)
    nop
    andi       $t1, $t0, 0xFFFF
    sll        $t1, $t1, 16
    sra        $t1, $t1, 16
    multu      $t1, $t3
    mflo       $t1
    sra        $t1, $t1, 12
    andi       $t1, $t1, 0xFFFF
    sra        $t2, $t0, 16
    multu      $t2, $t4
    mflo       $t2
    sra        $t2, $t2, 12
    sll        $t2, $t2, 16
    or         $t1, $t1, $t2
    sw         $t1, 0x0($a0)
    lw         $t0, 0x4($a0)
    nop
    andi       $t1, $t0, 0xFFFF
    sll        $t1, $t1, 16
    sra        $t1, $t1, 16
    multu      $t1, $t5
    mflo       $t1
    sra        $t1, $t1, 12
    andi       $t1, $t1, 0xFFFF
    sra        $t2, $t0, 16
    multu      $t2, $t3
    mflo       $t2
    sra        $t2, $t2, 12
    sll        $t2, $t2, 16
    or         $t1, $t1, $t2
    sw         $t1, 0x4($a0)
    lw         $t0, 0x8($a0)
    nop
    andi       $t1, $t0, 0xFFFF
    sll        $t1, $t1, 16
    sra        $t1, $t1, 16
    multu      $t1, $t4
    mflo       $t1
    sra        $t1, $t1, 12
    andi       $t1, $t1, 0xFFFF
    sra        $t2, $t0, 16
    multu      $t2, $t5
    mflo       $t2
    sra        $t2, $t2, 12
    sll        $t2, $t2, 16
    or         $t1, $t1, $t2
    sw         $t1, 0x8($a0)
    lw         $t0, 0xC($a0)
    nop
    andi       $t1, $t0, 0xFFFF
    sll        $t1, $t1, 16
    sra        $t1, $t1, 16
    multu      $t1, $t3
    mflo       $t1
    sra        $t1, $t1, 12
    andi       $t1, $t1, 0xFFFF
    sra        $t2, $t0, 16
    multu      $t2, $t4
    mflo       $t2
    sra        $t2, $t2, 12
    sll        $t2, $t2, 16
    or         $t1, $t1, $t2
    sw         $t1, 0xC($a0)
    lw         $t0, 0x10($a0)
    nop
    andi       $t1, $t0, 0xFFFF
    sll        $t1, $t1, 16
    sra        $t1, $t1, 16
    multu      $t1, $t5
    mflo       $t1
    sra        $t1, $t1, 12
    sw         $t1, 0x10($a0)
    jr         $ra
     addu       $v0, $a0, $zero
endlabel ScaleMatrix

    # alignment padding up to the next function
    nop
    nop
