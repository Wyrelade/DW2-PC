/*
 * func_8003D8C4();
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel func_8003D8C4
    lui        $t1, %hi(jtbl_80062F18)
    lw         $t1, %lo(jtbl_80062F18)($t1)
    nop
    jr         $t1
     nop
    lui        $t1, %hi(jtbl_80062F1C)
    lw         $t1, %lo(jtbl_80062F1C)($t1)
    nop
    jr         $t1
     nop
endlabel func_8003D8C4
