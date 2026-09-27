nonmatching func_8003D770, 0x78

glabel func_8003D770
    /* 2DF70 8003D770 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2DF74 8003D774 1400BFAF */  sw         $ra, 0x14($sp)
    /* 2DF78 8003D778 F19B000C */  jal        EnterCriticalSection
    /* 2DF7C 8003D77C 1000B0AF */   sw        $s0, 0x10($sp)
    /* 2DF80 8003D780 01000424 */  addiu      $a0, $zero, 0x1
    /* 2DF84 8003D784 0680033C */  lui        $v1, %hi(D_80062F04)
    /* 2DF88 8003D788 042F6324 */  addiu      $v1, $v1, %lo(D_80062F04)
    /* 2DF8C 8003D78C FCFF7024 */  addiu      $s0, $v1, -0x4
    /* 2DF90 8003D790 0480023C */  lui        $v0, %hi(func_8003D7E8)
    /* 2DF94 8003D794 E8D74224 */  addiu      $v0, $v0, %lo(func_8003D7E8)
    /* 2DF98 8003D798 000062AC */  sw         $v0, 0x0($v1)
    /* 2DF9C 8003D79C 0480023C */  lui        $v0, %hi(func_8003D850)
    /* 2DFA0 8003D7A0 50D84224 */  addiu      $v0, $v0, %lo(func_8003D850)
    /* 2DFA4 8003D7A4 040062AC */  sw         $v0, 0x4($v1)
    /* 2DFA8 8003D7A8 0680013C */  lui        $at, %hi(D_80062F00)
    /* 2DFAC 8003D7AC 002F20AC */  sw         $zero, %lo(D_80062F00)($at)
    /* 2DFB0 8003D7B0 0680013C */  lui        $at, %hi(D_80062F0C)
    /* 2DFB4 8003D7B4 0C2F20AC */  sw         $zero, %lo(D_80062F0C)($at)
    /* 2DFB8 8003D7B8 FD9B000C */  jal        SysDeqIntRP
    /* 2DFBC 8003D7BC 21280002 */   addu      $a1, $s0, $zero
    /* 2DFC0 8003D7C0 01000424 */  addiu      $a0, $zero, 0x1
    /* 2DFC4 8003D7C4 F99B000C */  jal        SysEnqIntRP
    /* 2DFC8 8003D7C8 21280002 */   addu      $a1, $s0, $zero
    /* 2DFCC 8003D7CC F59B000C */  jal        ExitCriticalSection
    /* 2DFD0 8003D7D0 00000000 */   nop
    /* 2DFD4 8003D7D4 01000224 */  addiu      $v0, $zero, 0x1
    /* 2DFD8 8003D7D8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 2DFDC 8003D7DC 1000B08F */  lw         $s0, 0x10($sp)
    /* 2DFE0 8003D7E0 0800E003 */  jr         $ra
    /* 2DFE4 8003D7E4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8003D770
