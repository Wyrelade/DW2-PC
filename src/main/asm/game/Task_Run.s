/*
 * s32 Task_Run(s32);
 * runs one task's init/update/destroy callbacks on the scratchpad stack (C with an inline stack-switch in the original; restored as asm, PLAN 4b.4)
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel Task_Run
    addiu      $sp, $sp, -0x18
    sw         $s0, 0x10($sp)
    addu       $s0, $a0, $zero
    lui        $a0, %hi(Task_DescTable)
    sw         $ra, 0x14($sp)
    lw         $v1, 0x0($s0)
    addiu      $a0, $a0, %lo(Task_DescTable)
    sra        $v0, $v1, 8
    sll        $v0, $v0, 2
    addu       $v0, $v0, $a0
    andi       $v1, $v1, 0xFF
    lw         $v0, 0x0($v0)
    sll        $v1, $v1, 2
    addu       $v1, $v1, $v0
    lui        $v0, %hi(Sys_DrawPass)
    lw         $v0, %lo(Sys_DrawPass)($v0)
    lw         $a0, 0x0($v1)
    beqz       $v0, .L8001100C
     addiu      $v0, $zero, 0x3
    lw         $v0, 0xC($a0)
    nop
    beqz       $v0, .L80010FD4
     nop
    lw         $v0, 0x24($s0)
    nop
    beqz       $v0, .L80010FD4
     nop
    lw         $v1, 0x10($s0)
    nop
    beqz       $v1, .L80011060
     addiu      $v0, $zero, 0x3
    beq        $v1, $v0, .L80010FD4
     lui        $a1, (0x1F8003FC >> 16)
    ori        $a1, $a1, (0x1F8003FC & 0xFFFF)
    addu       $t0, $a1, $zero
    sw         $sp, 0x0($t0)
    addiu      $t0, $t0, -0x4
    addu       $sp, $t0, $zero
    lw         $v0, 0xC($a0)
    nop
    jalr       $v0
     addu       $a0, $s0, $zero
    addiu      $sp, $sp, 0x4
    lw         $sp, 0x0($sp)
.L80010FD4:
    lw         $v0, 0x10($s0)
    nop
    beqz       $v0, .L80011060
     lui        $v1, %hi(Sys_FrameDelta)
    lw         $v0, 0x24($s0)
    nop
    addiu      $v0, $v0, 0x1
    sw         $v0, 0x24($s0)
    lw         $v0, 0x28($s0)
    lw         $v1, %lo(Sys_FrameDelta)($v1)
    nop
    addu       $v0, $v0, $v1
    j          .L80011060
     sw         $v0, 0x28($s0)
.L8001100C:
    lw         $v1, 0x10($s0)
    nop
    bne        $v1, $v0, .L80011034
     lui        $a1, (0x1F8003FC >> 16)
    lw         $v0, 0x8($a0)
    nop
    jalr       $v0
     addu       $a0, $s0, $zero
    j          .L8001106C
     addu       $v0, $zero, $zero
.L80011034:
    ori        $a1, $a1, (0x1F8003FC & 0xFFFF)
    addu       $t0, $a1, $zero
    sw         $sp, 0x0($t0)
    addiu      $t0, $t0, -0x4
    addu       $sp, $t0, $zero
    lw         $v0, 0x4($a0)
    nop
    jalr       $v0
     addu       $a0, $s0, $zero
    addiu      $sp, $sp, 0x4
    lw         $sp, 0x0($sp)
.L80011060:
    jal        Task_RunChildren
     addu       $a0, $s0, $zero
    addu       $v0, $s0, $zero
.L8001106C:
    lw         $ra, 0x14($sp)
    lw         $s0, 0x10($sp)
    jr         $ra
     addiu      $sp, $sp, 0x18
endlabel Task_Run
