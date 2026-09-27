/*
 * PopMatrix()
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel PopMatrix
    lui        $t6, %hi(D_80049ABC)
    lw         $t6, %lo(D_80049ABC)($t6)
    nop
    bgtz       $t6, .L8002D1B4
     nop
    lui        $at, %hi(D_80049AB0)
    sw         $ra, %lo(D_80049AB0)($at)
    lui        $a0, %hi(D_80049D71)
    jal        printf
     addiu      $a0, $a0, %lo(D_80049D71)
    lui        $ra, %hi(D_80049AB0)
    lw         $ra, %lo(D_80049AB0)($ra)
    nop
    jr         $ra
     nop
.L8002D1B4:
    addi       $t6, $t6, -0x20
    lui        $at, %hi(D_80049ABC)
    sw         $t6, %lo(D_80049ABC)($at)
    lui        $t7, %hi(D_80049AC0)
    addiu      $t7, $t7, %lo(D_80049AC0)
    addu       $t7, $t7, $t6
    lw         $t0, 0x0($t7)
    lw         $t1, 0x4($t7)
    ctc2       $t0, $0
    ctc2       $t1, $1
    lw         $t0, 0x8($t7)
    lw         $t1, 0xC($t7)
    ctc2       $t0, $2
    ctc2       $t1, $3
    lw         $t0, 0x10($t7)
    nop
    ctc2       $t0, $4
    nop
    lw         $t0, 0x14($t7)
    lw         $t1, 0x18($t7)
    lw         $t2, 0x1C($t7)
    ctc2       $t0, $5
    ctc2       $t1, $6
    ctc2       $t2, $7
    jr         $ra
     nop
endlabel PopMatrix

    # alignment padding up to the next function
    nop
    nop
