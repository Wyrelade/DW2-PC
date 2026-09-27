/*
 * func_8003D8EC();
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel func_8003D8EC
    lui        $at, %hi(D_80062F10)
    sw         $ra, %lo(D_80062F10)($at)
    jal        EnterCriticalSection
     nop
    addiu      $t1, $zero, 0x57
    addiu      $t2, $zero, 0xB0
    jalr       $t2
     nop
    lw         $v0, 0x16C($v0)
    addiu      $t1, $zero, 0xB           # B0(0x0B)
    addi       $v1, $v0, 0x884
    lui        $at, %hi(jtbl_80062F18)
    sw         $v1, %lo(jtbl_80062F18)($at)
    addi       $v1, $v0, 0x894
    lui        $at, %hi(jtbl_80062F1C)
    sw         $v1, %lo(jtbl_80062F1C)($at)
.L8003D92C:
    sw         $zero, 0x594($v0)
    addiu      $v0, $v0, 0x4
    addiu      $t1, $t1, -0x1
    bnez       $t1, .L8003D92C
     nop
    jal        FlushCache
     nop
    lui        $ra, %hi(D_80062F10)
    lw         $ra, %lo(D_80062F10)($ra)
    nop
    jr         $ra
     nop
endlabel func_8003D8EC

    # alignment padding up to the next function
    nop
    nop
