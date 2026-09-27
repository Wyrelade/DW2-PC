/*
 * void func_8002CE5C(void);
 * cop0/GTE setup (enables COP2 in SR)
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel func_8002CE5C
    lui        $at, %hi(D_80049920)
    sw         $ra, %lo(D_80049920)($at)
    jal        func_8002DAC4
     nop
    lui        $ra, %hi(D_80049920)
    lw         $ra, %lo(D_80049920)($ra)
    nop
    mfc0       $v0, $12
    lui        $v1, (0x40000000 >> 16)
    or         $v0, $v0, $v1
    mtc0       $v0, $12
    nop
    addiu      $t0, $zero, 0x155
    ctc2       $t0, $29
    nop
    addiu      $t0, $zero, 0x100
    ctc2       $t0, $30
    nop
    addiu      $t0, $zero, 0x3E8
    ctc2       $t0, $26
    nop
    addiu      $t0, $zero, -0x1062
    ctc2       $t0, $27
    nop
    lui        $t0, (0x1400000 >> 16)
    ctc2       $t0, $28
    nop
    ctc2       $zero, $24
    ctc2       $zero, $25
    nop
    jr         $ra
     nop
endlabel func_8002CE5C

    # alignment padding up to the next function
    nop
    nop
