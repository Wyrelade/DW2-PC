/*
 * void Sys_Start(void);
 * Program entry point (PSX-EXE pc0): the Psy-Q crt0 start-up code.
 * Clears .bss (D_80050758 up to Ovl_LoadArea), picks the stack top from the RAM-size table
 * below (index 4), sets $gp (_gp) and $fp, calls InitHeap on the memory after .bss, then main.
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel Sys_Start
    lui        $v0, %hi(D_80050758)
    addiu      $v0, $v0, %lo(D_80050758)    # .bss start
    lui        $v1, %hi(Ovl_LoadArea)
    addiu      $v1, $v1, %lo(Ovl_LoadArea)  # .bss end
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
    lui        $a0, %hi(.LSys_Start_ramsize)
    addiu      $a0, $a0, %lo(.LSys_Start_ramsize)
    addu       $a0, $a0, $v0
    lw         $v0, 0x0($a0)
    lui        $t0, 0x8000
    or         $sp, $v0, $t0            # stack top = KSEG0 | RAM size
    lui        $a0, %hi(Ovl_LoadArea)
    addiu      $a0, $a0, %lo(Ovl_LoadArea)  # heap start = .bss end
    sll        $a0, $a0, 3
    srl        $a0, $a0, 3              # physical address
    lui        $v1, %hi(D_8004FC10)
    lw         $v1, %lo(D_8004FC10)($v1)    # stack size
    nop
    subu       $a1, $v0, $v1
    subu       $a1, $a1, $a0            # heap size = RAM size - stack size - heap start
    or         $a0, $a0, $t0
    lui        $at, %hi(D_80050758)
    sw         $ra, %lo(D_80050758)($at)
    lui        $gp, %hi(_gp)
    addiu      $gp, $gp, %lo(_gp)
    addu       $fp, $sp, $zero
    jal        InitHeap
     addi      $a0, $a0, 0x4
    lui        $ra, %hi(D_80050758)
    lw         $ra, %lo(D_80050758)($ra)
    nop
    jal        Sys_Main            # main
     nop
    break      0, 1
endlabel Sys_Start

    # RAM-size table read above (index 4 used)
.LSys_Start_ramsize:
    .word 0x00200000
    .word 0x00200000
    .word 0x00200000
    .word 0x00200000
