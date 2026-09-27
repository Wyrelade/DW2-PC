nonmatching func_8003770C, 0x34

glabel func_8003770C
    /* 27F0C 8003770C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 27F10 80037710 1000BFAF */  sw         $ra, 0x10($sp)
    /* 27F14 80037714 00140400 */  sll        $v0, $a0, 16
    /* 27F18 80037718 001C0500 */  sll        $v1, $a1, 16
    /* 27F1C 8003771C FFFFC730 */  andi       $a3, $a2, 0xFFFF
    /* 27F20 80037720 21000424 */  addiu      $a0, $zero, 0x21
    /* 27F24 80037724 032C0200 */  sra        $a1, $v0, 16
    /* 27F28 80037728 30DD000C */  jal        _SsVmKeyOff
    /* 27F2C 8003772C 03340300 */   sra       $a2, $v1, 16
    /* 27F30 80037730 1000BF8F */  lw         $ra, 0x10($sp)
    /* 27F34 80037734 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 27F38 80037738 0800E003 */  jr         $ra
    /* 27F3C 8003773C 00000000 */   nop
endlabel func_8003770C
    /* 27F40 80037740 00000000 */  nop
