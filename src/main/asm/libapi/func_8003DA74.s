/*
 * func_8003DA74()
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel func_8003DA74
    lw         $v0, 0x1074($v1)
    nop
    andi       $v0, $v0, 0x80
    beqz       $v0, .L8003DAB0
     nop
.L8003DA88:
    lw         $v0, 0x1044($v1)
    nop
    andi       $v0, $v0, 0x80
    bnez       $v0, .L8003DA88
     nop
    lui        $v0, (0x10000 >> 16)
    lw         $v0, -0x2004($v0)
    nop
    jr         $v0
     nop
.L8003DAB0:
    jr         $ra
     nop
endlabel func_8003DA74
