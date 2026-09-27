/*
 * func_8002DAC4()
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel func_8002DAC4
    lui        $at, %hi(D_80061AE8)
    sw         $ra, %lo(D_80061AE8)($at)
    jal        EnterCriticalSection
     nop
    addiu      $t1, $zero, 0x56          # B0(0x56)
    addiu      $t2, $zero, 0xB0
    jalr       $t2
     nop
    lw         $v0, 0x18($v0)
    nop
    addiu      $v0, $v0, 0x28
    addu       $t7, $v0, $zero
    lui        $t2, %hi(func_8002DB70)
    addiu      $t2, $t2, %lo(func_8002DB70)
    lui        $t1, %hi(D_8002DB88)
    addiu      $t1, $t1, %lo(D_8002DB88)
.L8002DB04:
    lw         $v1, 0x0($t2)
    lw         $t3, 0x0($v0)
    addiu      $t2, $t2, 0x4
    bne        $v1, $t3, .L8002DB4C
     addiu      $v0, $v0, 0x4
    bne        $t2, $t1, .L8002DB04
     nop
    addu       $v0, $t7, $zero
    lui        $t2, %hi(D_8002DB88)
    addiu      $t2, $t2, %lo(D_8002DB88)
    lui        $t1, %hi(D_8002DBA0)
    addiu      $t1, $t1, %lo(D_8002DBA0)
.L8002DB34:
    lw         $v1, 0x0($t2)
    nop
    sw         $v1, 0x0($v0)
    addiu      $t2, $t2, 0x4
    bne        $t2, $t1, .L8002DB34
     addiu      $v0, $v0, 0x4
.L8002DB4C:
    jal        FlushCache
     nop
    jal        ExitCriticalSection
     nop
    lui        $ra, %hi(D_80061AE8)
    lw         $ra, %lo(D_80061AE8)($ra)
    nop
    jr         $ra
     nop
endlabel func_8002DAC4
