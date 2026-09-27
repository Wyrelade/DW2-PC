/*
 * void func_8003DAE0(void);
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel func_8003DAE0
    lui        $at, %hi(D_80062F30)
    sw         $ra, %lo(D_80062F30)($at)
    jal        EnterCriticalSection
     nop
    addiu      $t1, $zero, 0x56          # B0(0x56)
    addiu      $t2, $zero, 0xB0
    jalr       $t2
     nop
    lw         $v0, 0x18($v0)
    nop
    lw         $v1, 0x70($v0)
    nop
    andi       $t1, $v1, 0xFFFF
    sll        $t1, $t1, 16
    lw         $v1, 0x74($v0)
    nop
    andi       $t2, $v1, 0xFFFF
    addu       $v1, $t1, $t2
    addiu      $v0, $v1, 0x28
    lui        $t2, %hi(func_8003DAB8)
    addiu      $t2, $t2, %lo(func_8003DAB8)
    lui        $t1, %hi(func_8003DAB8 + 0x14)
    addiu      $t1, $t1, %lo(func_8003DAB8 + 0x14)
.L8003DB3C:
    lw         $v1, 0x0($t2)
    nop
    sw         $v1, 0x0($v0)
    addiu      $t2, $t2, 0x4
    bne        $t2, $t1, .L8003DB3C
     addiu      $v0, $v0, 0x4
    lui        $at, (0x10000 >> 16)
    jal        FlushCache
     sw         $v0, -0x2004($at)
    lui        $ra, %hi(D_80062F30)
    lw         $ra, %lo(D_80062F30)($ra)
    nop
    jr         $ra
     nop
endlabel func_8003DAE0
