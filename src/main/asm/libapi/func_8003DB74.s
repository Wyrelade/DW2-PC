/*
 * void func_8003DB74(void);
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel func_8003DB74
    lui        $at, %hi(D_80062F30)
    sw         $ra, %lo(D_80062F30)($at)
    jal        EnterCriticalSection
     nop
    addiu      $t1, $zero, 0x57
    addiu      $t2, $zero, 0xB0
    jalr       $t2
     nop
    lw         $v0, 0x16C($v0)
    nop
    lw         $v1, 0x9C8($v0)
    lui        $t2, %hi(func_8003DAB8 + 0x14)
    addiu      $t2, $t2, %lo(func_8003DAB8 + 0x14)
    lui        $t1, %hi(func_8003DAE0)
    addiu      $t1, $t1, %lo(func_8003DAE0)
.L8003DBB0:
    lw         $t0, 0x0($t2)
    nop
    sw         $t0, 0x9C8($v0)
    addiu      $t2, $t2, 0x4
    bne        $t2, $t1, .L8003DBB0
     addiu      $v0, $v0, 0x4
    jal        FlushCache
     nop
    lui        $ra, %hi(D_80062F30)
    lw         $ra, %lo(D_80062F30)($ra)
    nop
    jr         $ra
     nop
endlabel func_8003DB74
