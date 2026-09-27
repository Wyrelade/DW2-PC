/*
 * void func_8003DA04(void);
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel func_8003DA04
    lui        $at, %hi(D_80062F30)
    sw         $ra, %lo(D_80062F30)($at)
    addiu      $t1, $zero, 0x57
    addiu      $t2, $zero, 0xB0
    jalr       $t2
     nop
    addiu      $t2, $zero, 0x9
    lw         $v0, 0x16C($v0)
    nop
    addi       $v1, $v0, 0x1988
    jal        FlushCache
     sw         $zero, 0x0($v1)
    lui        $ra, %hi(D_80062F30)
    lw         $ra, %lo(D_80062F30)($ra)
    nop
    jr         $ra
     nop
endlabel func_8003DA04
