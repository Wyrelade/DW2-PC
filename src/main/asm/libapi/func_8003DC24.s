/*
 * func_8003DC24();
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel func_8003DC24
    lui        $at, %hi(D_80062F40)
    sw         $ra, %lo(D_80062F40)($at)
    jal        EnterCriticalSection
     nop
    addiu      $t1, $zero, 0x56          # B0(0x56)
    addiu      $t2, $zero, 0xB0
    jalr       $t2
     nop
    lw         $v0, 0x18($v0)
    lui        $t2, %hi(D_8003DC94)
    addiu      $t2, $t2, %lo(D_8003DC94)
    lui        $t1, %hi(D_8003DCA0)
    addiu      $t1, $t1, %lo(D_8003DCA0)
.L8003DC58:
    lw         $v1, 0x0($t2)
    nop
    sw         $v1, 0x70($v0)
    addiu      $t2, $t2, 0x4
    bne        $t2, $t1, .L8003DC58
     addiu      $v0, $v0, 0x4
    jal        FlushCache
     nop
    jal        ExitCriticalSection
     nop
    lui        $ra, %hi(D_80062F40)
    lw         $ra, %lo(D_80062F40)($ra)
    nop
    jr         $ra
     nop
endlabel func_8003DC24

    # alignment padding up to the next function
    alabel D_8003DC94
    nop
    nop
    nop
    alabel D_8003DCA0
    nop
