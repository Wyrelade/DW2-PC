/*
 * void Sys_Start(void);
 * Program entry point (PSX-EXE pc0 = 0x80010D7C): the Psy-Q crt0 start-up code.
 * Clears .bss (0x80050758..0x80063360), picks the stack top from the RAM-size table below
 * (index 4), sets $gp (0x800506F8) and $fp, calls InitHeap on the memory after .bss, then main.
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel Sys_Start
    lui        $v0, 0x8005
    addiu      $v0, $v0, 0x758          # .bss start
    lui        $v1, 0x8006
    addiu      $v1, $v1, 0x3360         # .bss end
.LSys_Start_clear:
    sw         $zero, 0x0($v0)
    addiu      $v0, $v0, 0x4
    sltu       $at, $v0, $v1
    bnez       $at, .LSys_Start_clear
     nop
    addiu      $v0, $zero, 0x4          # RAM-size table index
    nop
    nop
    nop
    nop
    lui        $a0, 0x8001
    addiu      $a0, $a0, 0xE28          # RAM-size table (after endlabel)
    addu       $a0, $a0, $v0
    lw         $v0, 0x0($a0)
    lui        $t0, 0x8000
    or         $sp, $v0, $t0            # stack top = KSEG0 | RAM size
    lui        $a0, 0x8006
    addiu      $a0, $a0, 0x3360         # heap start = .bss end
    sll        $a0, $a0, 3
    srl        $a0, $a0, 3              # physical address
    lui        $v1, 0x8005
    lw         $v1, -0x3F0($v1)         # stack size (0x8004FC10)
    nop
    subu       $a1, $v0, $v1
    subu       $a1, $a1, $a0            # heap size = RAM size - stack size - heap start
    or         $a0, $a0, $t0
    lui        $at, 0x8005
    sw         $ra, 0x758($at)
    lui        $gp, 0x8005
    addiu      $gp, $gp, 0x6F8
    addu       $fp, $sp, $zero
    jal        InitHeap
     addi      $a0, $a0, 0x4
    lui        $ra, 0x8005
    lw         $ra, 0x758($ra)
    nop
    jal        func_80023550            # main
     nop
    break      0, 1
endlabel Sys_Start

    # RAM-size table read above (index 4 used)
    .word 0x00200000
    .word 0x00200000
    .word 0x00200000
    .word 0x00200000
