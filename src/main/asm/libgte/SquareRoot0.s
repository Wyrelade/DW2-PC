/*
 * s32 SquareRoot0(s32);
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel SquareRoot0
    mtc2       $a0, $30
    nop
    nop
    mfc2       $v0, $31
    addiu      $at, $zero, 0x20
    beq        $v0, $at, .L8002CF60
     nop
    andi       $t0, $v0, 0x1
    addiu      $at, $zero, -0x2
    and        $t2, $v0, $at
    addiu      $t1, $zero, 0x1F
    sub        $t1, $t1, $t2
    sra        $t1, $t1, 1
    addi       $t3, $t2, -0x18
    bltz       $t3, .L8002CF2C
     nop
    sllv       $t4, $a0, $t3
    b          .L8002CF38
.L8002CF2C:
     addiu      $t3, $zero, 0x18
    sub        $t3, $t3, $t2
    srav       $t4, $a0, $t3
.L8002CF38:
    addi       $t4, $t4, -0x40
    sll        $t4, $t4, 1
    lui        $t5, %hi(D_80049930)
    addu       $t5, $t5, $t4
    lh         $t5, %lo(D_80049930)($t5)
    nop
    sllv       $t5, $t5, $t1
    srl        $v0, $t5, 12
    jr         $ra
     nop
.L8002CF60:
    jr         $ra
     addiu      $v0, $zero, 0x0
endlabel SquareRoot0

    # alignment padding up to the next function
    nop
    nop
    nop
