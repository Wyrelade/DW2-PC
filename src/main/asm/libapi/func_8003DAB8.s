/*
 * func_8003DAB8()
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel func_8003DAB8
    lui        $v0, %hi(D_A000DFAC)
    addiu      $v0, $v0, %lo(D_A000DFAC)
    jr         $v0
     nop
    nop
    lui        $t0, %hi(D_A000DF80)
    addiu      $t0, $t0, %lo(D_A000DF80)
    jalr       $t0
     nop
endlabel func_8003DAB8

    # alignment padding up to the next function
    nop
