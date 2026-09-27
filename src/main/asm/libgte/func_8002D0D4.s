/*
 * func_8002D0D4()
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel func_8002D0D4
    lui        $t6, %hi(D_80049ABC)
    lw         $t6, %lo(D_80049ABC)($t6)
    nop
    slti       $at, $t6, 0x280
    bnez       $at, .L8002D114
     nop
    lui        $at, %hi(D_80049AB0)
    sw         $ra, %lo(D_80049AB0)($at)
    lui        $a0, %hi(D_80049D40)
    jal        printf
     addiu      $a0, $a0, %lo(D_80049D40)
    lui        $ra, %hi(D_80049AB0)
    lw         $ra, %lo(D_80049AB0)($ra)
    nop
    jr         $ra
     nop
.L8002D114:
    lui        $t7, %hi(D_80049AC0)
    addiu      $t7, $t7, %lo(D_80049AC0)
    addu       $t7, $t7, $t6
    cfc2       $t0, $0
    cfc2       $t1, $1
    sw         $t0, 0x0($t7)
    sw         $t1, 0x4($t7)
    cfc2       $t0, $2
    cfc2       $t1, $3
    sw         $t0, 0x8($t7)
    sw         $t1, 0xC($t7)
    cfc2       $t0, $4
    nop
    sw         $t0, 0x10($t7)
    cfc2       $t0, $5
    cfc2       $t1, $6
    cfc2       $t2, $7
    sw         $t0, 0x14($t7)
    sw         $t1, 0x18($t7)
    sw         $t2, 0x1C($t7)
    addi       $t6, $t6, 0x20
    lui        $at, %hi(D_80049ABC)
    sw         $t6, %lo(D_80049ABC)($at)
    jr         $ra
     nop
endlabel func_8002D0D4
