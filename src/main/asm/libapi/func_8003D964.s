/*
 * func_8003D964();
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel func_8003D964
    lui        $at, %hi(D_80062F20)
    sw         $ra, %lo(D_80062F20)($at)
    jal        EnterCriticalSection
     nop
    addiu      $t1, $zero, 0x57          # B0(0x57)
    addiu      $t2, $zero, 0xB0
    jalr       $t2
     nop
    addiu      $t2, $zero, 0x9
    lw         $v0, 0x16C($v0)
    nop
    addi       $v1, $v0, 0x62C
.L8003D994:
    sw         $zero, 0x0($v1)
    addiu      $v1, $v1, 0x4
    addiu      $t2, $t2, -0x1
    bnez       $t2, .L8003D994
     nop
    jal        FlushCache
     nop
    jal        ExitCriticalSection
     nop
    lui        $ra, %hi(D_80062F20)
    lw         $ra, %lo(D_80062F20)($ra)
    nop
    jr         $ra
     nop
endlabel func_8003D964

    # alignment padding up to the next function
    nop
    nop
