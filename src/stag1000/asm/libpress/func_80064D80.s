/*
 * void func_80064D80(u32 *, u32 *, u32 *);
 * Psy-Q libpress (MDEC run-length / VLC decode)
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel func_80064D80
    lui        $t0, %hi(D_800653A8)
    addiu      $t0, $t0, %lo(D_800653A8)
    addi       $a2, $a2, 0x800
    lui        $at, (0x10000 >> 16)
    add        $a3, $a2, $at
    bnez       $a0, .L80064DD4
     lw         $t1, 0x0($t0)
    lui        $t0, %hi(D_800653AC)
    addiu      $t0, $t0, %lo(D_800653AC)
    lw         $a0, 0x0($t0)
    lw         $a1, 0x4($t0)
    lw         $v0, 0x8($t0)
    lw         $v1, 0xC($t0)
    lw         $t4, 0x10($t0)
    lw         $t5, 0x14($t0)
    lw         $t7, 0x18($t0)
    lw         $t8, 0x1C($t0)
    lw         $t9, 0x20($t0)
    add        $t1, $t1, $t1
    b          .L80064F60
     add        $t6, $a1, $t1
.L80064DD4:
    add        $t5, $zero, $zero
    add        $t7, $zero, $zero
    add        $t8, $zero, $zero
    add        $t9, $zero, $zero
    add        $t1, $t1, $t1
    add        $t6, $a1, $t1
    lw         $t1, 0x0($a0)
    lhu        $t4, 0x4($a0)
    lhu        $t2, 0x6($a0)
    lhu        $v0, 0x8($a0)
    lhu        $v1, 0xA($a0)
    addi       $t2, $t2, -0x3
    bltz       $t2, .L80064E10
     sll        $t4, $t4, 10
    addi       $t5, $zero, 0x1
.L80064E10:
    addi       $a0, $a0, 0xC
    sll        $v0, $v0, 16
    or         $v0, $v0, $v1
    or         $v1, $zero, $zero
    sw         $t1, 0x0($a1)
    andi       $t1, $t1, 0xFFFF
    sll        $t1, $t1, 2
    addiu      $t1, $t1, 0x4
    add        $t1, $t1, $a1
    lui        $t0, %hi(D_800653D0)
    addiu      $t0, $t0, %lo(D_800653D0)
    sw         $t1, 0x0($t0)
    addi       $a1, $a1, 0x2
.L80064E44:
    beqz       $t5, .L80064F1C
     srl        $t0, $v0, 22
    xori       $at, $t0, 0x3FF
    beqz       $at, .L80065068
     addi       $a1, $a1, 0x2
    addi       $at, $t5, -0x3
    bltz       $at, .L80064E68
     addi       $at, $a2, -0x400
    addi       $at, $at, -0x400
.L80064E68:
    srl        $t0, $v0, 24
    sll        $t0, $t0, 2
    add        $t0, $t0, $at
    lhu        $t1, 0x0($t0)
    lhu        $t2, 0x2($t0)
    and        $t0, $zero, $zero
    beqz       $t2, .L80064EAC
     sllv       $v0, $v0, $t1
    addi       $at, $zero, 0x20
    sub        $at, $at, $t2
    srlv       $t0, $v0, $at
    bltz       $v0, .L80064EA8
     sllv       $v0, $v0, $t2
    addi       $t3, $zero, -0x1
    srlv       $t3, $t3, $at
    sub        $t0, $t0, $t3
.L80064EA8:
    add        $v1, $v1, $t2
.L80064EAC:
    add        $v1, $v1, $t1
    andi       $at, $v1, 0x10
    beqz       $at, .L80064ECC
     andi       $v1, $v1, 0xF
    lhu        $t1, 0x0($a0)
    addi       $a0, $a0, 0x2
    sllv       $t1, $t1, $v1
    or         $v0, $v0, $t1
.L80064ECC:
    addi       $at, $t5, -0x2
    bgtz       $at, .L80064EF4
     add        $t1, $t9, $t0
    beqz       $at, .L80064EEC
     add        $t1, $t8, $t0
    add        $t1, $t7, $t0
    b          .L80064EF8
     add        $t7, $t7, $t0
.L80064EEC:
    b          .L80064EF8
     add        $t8, $t8, $t0
.L80064EF4:
    add        $t9, $t9, $t0
.L80064EF8:
    sll        $t1, $t1, 2
    andi       $t1, $t1, 0x3FF
    or         $t1, $t4, $t1
    addi       $t5, $t5, 0x1
    addi       $at, $t5, -0x7
    bnez       $at, .L80064F54
     sh         $t1, 0x0($a1)
    b          .L80064F54
     addi       $t5, $t5, -0x6
.L80064F1C:
    xori       $at, $t0, 0x1FF
    beqz       $at, .L80065068
     addi       $a1, $a1, 0x2
    sll        $v0, $v0, 10
    addi       $v1, $v1, 0xA
    andi       $at, $v1, 0x10
    beqz       $at, .L80064F4C
     andi       $v1, $v1, 0xF
    lhu        $t1, 0x0($a0)
    addi       $a0, $a0, 0x2
    sllv       $t1, $t1, $v1
    or         $v0, $v0, $t1
.L80064F4C:
    or         $t0, $t4, $t0
    sh         $t0, 0x0($a1)
.L80064F54:
    subu       $at, $a1, $t6
    bgez       $at, .L80065098
     addi       $a1, $a1, 0x2
.L80064F60:
    srl        $t0, $v0, 19
    sll        $t0, $t0, 3
    add        $t0, $t0, $a2
    lw         $t1, 0x0($t0)
    nop
    bnez       $t1, .L80064FBC
     andi       $at, $t1, 0xFF
    sll        $v0, $v0, 8
    addi       $v1, $v1, 0x8
    andi       $at, $v1, 0x10
    beqz       $at, .L80064FA0
     andi       $v1, $v1, 0xF
    lhu        $t0, 0x0($a0)
    addi       $a0, $a0, 0x2
    sllv       $t0, $t0, $v1
    or         $v0, $v0, $t0
.L80064FA0:
    srl        $t0, $v0, 23
    sll        $t0, $t0, 2
    add        $t0, $t0, $a3
    lw         $t1, 0x0($t0)
    add        $t3, $zero, $zero
    b          .L80064FC0
     andi       $at, $t1, 0xFF
.L80064FBC:
    lw         $t3, 0x4($t0)
.L80064FC0:
    sllv       $v0, $v0, $at
    add        $v1, $v1, $at
    andi       $at, $v1, 0x10
    beqz       $at, .L80064FE4
     andi       $v1, $v1, 0xF
    lhu        $t0, 0x0($a0)
    addi       $a0, $a0, 0x2
    sllv       $t0, $t0, $v1
    or         $v0, $v0, $t0
.L80064FE4:
    srl        $t1, $t1, 16
    xori       $at, $t1, 0x7C1F
    beqz       $at, .L80065044
     xori       $at, $t1, 0xFE00
    beqz       $at, .L80064E44
     sh         $t1, 0x0($a1)
    beqz       $t3, .L80064F60
     addi       $a1, $a1, 0x2
    andi       $t2, $t3, 0xFFFF
    xori       $at, $t2, 0x7C1F
    beqz       $at, .L80065044
     xori       $at, $t2, 0xFE00
    beqz       $at, .L80064E44
     sh         $t2, 0x0($a1)
    srl        $t2, $t3, 16
    beqz       $t2, .L80064F60
     addi       $a1, $a1, 0x2
    xori       $at, $t2, 0x7C1F
    beqz       $at, .L80065044
     xori       $at, $t2, 0xFE00
    beqz       $at, .L80064E44
     sh         $t2, 0x0($a1)
    b          .L80064F60
     addi       $a1, $a1, 0x2
.L80065044:
    srl        $t0, $v0, 16
    sh         $t0, 0x0($a1)
    addi       $a1, $a1, 0x2
    lhu        $t0, 0x0($a0)
    addi       $a0, $a0, 0x2
    sll        $v0, $v0, 16
    sllv       $t0, $t0, $v1
    b          .L80064F60
     or         $v0, $v0, $t0
.L80065068:
    lui        $t0, %hi(D_800653D0)
    addiu      $t0, $t0, %lo(D_800653D0)
    lw         $t1, 0x0($t0)
    ori        $t0, $zero, 0xFE00
.L80065078:
    subu       $at, $a1, $t1
    bgez       $at, .L80065090
     nop
    sh         $t0, 0x0($a1)
    b          .L80065078
     addi       $a1, $a1, 0x2
.L80065090:
    jr         $ra
     add        $v0, $zero, $zero
.L80065098:
    lui        $t0, %hi(D_800653AC)
    addiu      $t0, $t0, %lo(D_800653AC)
    sw         $a0, 0x0($t0)
    sw         $a1, 0x4($t0)
    sw         $v0, 0x8($t0)
    sw         $v1, 0xC($t0)
    sw         $t4, 0x10($t0)
    sw         $t5, 0x14($t0)
    sw         $t7, 0x18($t0)
    sw         $t8, 0x1C($t0)
    sw         $t9, 0x20($t0)
    jr         $ra
     addi       $v0, $zero, 0x1
endlabel func_80064D80

    # alignment padding up to the next function
    nop
