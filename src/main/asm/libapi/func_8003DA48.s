/*
 * func_8003DA48()
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel func_8003DA48
    lhu        $t7, 0xA($v1)
    lui        $t0, (0x0 >> 16)
    or         $t8, $t7, $v0
    ori        $t9, $t8, 0x12
    sh         $t9, 0xA($v1)
    addiu      $t0, $zero, 0x28
.L8003DA60:
    addiu      $t0, $t0, -0x1
    bnez       $t0, .L8003DA60
     nop
    jr         $ra
     nop
endlabel func_8003DA48
