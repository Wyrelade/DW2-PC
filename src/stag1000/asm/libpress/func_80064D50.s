/*
 * func_80064D50()
 * Psy-Q libpress (MDEC run-length / VLC decode)
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel func_80064D50
    lui        $t0, %hi(D_800653A8)
    addiu      $t0, $t0, %lo(D_800653A8)
    addi       $at, $a0, -0x1
    blez       $at, .L80064D70
     lw         $v0, 0x0($t0)
    sll        $at, $a0, 1
    jr         $ra
     sw         $at, 0x0($t0)
.L80064D70:
    lui        $at, (0xFFFFFF >> 16)
    ori        $at, $at, (0xFFFFFF & 0xFFFF)
    jr         $ra
     sw         $at, 0x0($t0)
endlabel func_80064D50
