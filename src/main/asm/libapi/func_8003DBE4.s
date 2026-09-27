/*
 * void func_8003DBE4(void);
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel func_8003DBE4
    ori        $v0, $zero, 0xDF80
    lui        $t2, %hi(func_8003DA48)
    addiu      $t2, $t2, %lo(func_8003DA48)
    lui        $t1, %hi(func_8003DAB8)
    addiu      $t1, $t1, %lo(func_8003DAB8)
.L8003DBF8:
    lw         $v1, 0x0($t2)
    nop
    sw         $v1, 0x0($v0)
    addiu      $t2, $t2, 0x4
    bne        $t2, $t1, .L8003DBF8
     addiu      $v0, $v0, 0x4
    jr         $ra
     nop
endlabel func_8003DBE4

    # alignment padding up to the next function
    nop
    nop
    nop
