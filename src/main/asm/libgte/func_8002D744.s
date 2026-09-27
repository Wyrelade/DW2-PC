/*
 * void func_8002D744(void *, Obj209 *);
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel func_8002D744
    lh         $t0, 0x4($a0)
    or         $v0, $zero, $a1
    lui        $v1, %hi(D_80049DC0)
    addiu      $v1, $v1, %lo(D_80049DC0)
    lw         $t4, 0x0($a0)
    sra        $t3, $t0, 31
    add        $t0, $t0, $t3
    xor        $t0, $t0, $t3
    sll        $t0, $t0, 2
    andi       $t0, $t0, 0x3FFC
    add        $t0, $t0, $v1
    lw         $a2, 0x0($t0)
    sra        $t0, $t4, 16
    sra        $t2, $t0, 31
    add        $t0, $t0, $t2
    xor        $t0, $t0, $t2
    sll        $t0, $t0, 2
    andi       $t0, $t0, 0x3FFC
    add        $t0, $t0, $v1
    lw         $a1, 0x0($t0)
    sll        $t0, $t4, 16
    sra        $t0, $t0, 16
    sra        $t1, $t0, 31
    add        $t0, $t0, $t1
    xor        $t0, $t0, $t1
    sll        $t0, $t0, 2
    andi       $t0, $t0, 0x3FFC
    add        $t0, $t0, $v1
    lw         $a0, 0x0($t0)
    sll        $at, $a2, 16
    sra        $a2, $a2, 16
    sll        $a2, $a2, 16
    add        $at, $at, $t3
    xor        $at, $at, $t3
    srl        $at, $at, 16
    or         $a2, $a2, $at
    sll        $at, $a1, 16
    sra        $a1, $a1, 16
    sll        $a1, $a1, 16
    add        $at, $at, $t2
    xor        $at, $at, $t2
    srl        $at, $at, 16
    or         $a1, $a1, $at
    sll        $at, $a0, 16
    sra        $a0, $a0, 16
    sll        $a0, $a0, 16
    add        $at, $at, $t1
    xor        $at, $at, $t1
    srl        $at, $at, 16
    or         $a0, $a0, $at
    sra        $t0, $a1, 16
    mtc2       $t0, $8
    sll        $a3, $a0, 16
    sra        $a3, $a3, 16
    mtc2       $a3, $9
    sll        $v1, $a2, 16
    sra        $v1, $v1, 16
    mtc2       $v1, $10
    sra        $at, $a2, 16
    mtc2       $at, $11
    nop
    sra        $at, $a0, 16
    gpf        1
    mult       $at, $t0
    mfc2       $t0, $9
    mfc2       $t1, $10
    sll        $t6, $a1, 16
    mfc2       $t2, $11
    sra        $t6, $t6, 16
    mtc2       $t6, $8
    mtc2       $a3, $9
    mtc2       $v1, $10
    sra        $at, $a2, 16
    mtc2       $at, $11
    nop
    gpf        1
    mflo       $at
    sra        $at, $at, 12
    sh         $at, 0x10($v0)
    mfc2       $t3, $9
    mfc2       $t4, $10
    mfc2       $t5, $11
    sra        $at, $a2, 16
    mtc2       $at, $8
    sra        $at, $a0, 16
    mtc2       $at, $9
    mult       $at, $t6
    mtc2       $t3, $10
    mtc2       $t0, $11
    nop
    gpf        1
    mfc2       $a0, $9
    mfc2       $a1, $10
    mfc2       $a2, $11
    mtc2       $v1, $8
    mtc2       $at, $9
    mtc2       $t3, $10
    mtc2       $t0, $11
    nop
    gpf        1
    andi       $a0, $a0, 0xFFFF
    neg        $a3, $a3
    sll        $a3, $a3, 16
    or         $a0, $a0, $a3
    sw         $a0, 0x8($v0)
    mfc2       $at, $9
    sub        $t1, $a1, $t1
    mfc2       $t6, $10
    sll        $t1, $t1, 16
    mfc2       $t7, $11
    add        $t2, $t2, $t6
    andi       $t2, $t2, 0xFFFF
    or         $t1, $t1, $t2
    sw         $t1, 0x0($v0)
    mflo       $t1
    sra        $t1, $t1, 12
    andi       $t1, $t1, 0xFFFF
    sll        $at, $at, 16
    or         $at, $at, $t1
    sw         $at, 0x4($v0)
    sub        $t5, $t7, $t5
    andi       $t5, $t5, 0xFFFF
    add        $t4, $a2, $t4
    sll        $t4, $t4, 16
    or         $t4, $t4, $t5
    jr         $ra
     sw         $t4, 0xC($v0)
endlabel func_8002D744

    # alignment padding up to the next function
    nop
