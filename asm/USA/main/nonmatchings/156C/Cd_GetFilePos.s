nonmatching Cd_GetFilePos, 0x34

glabel Cd_GetFilePos
    /* 147C8 80023FC8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 147CC 80023FCC 0480023C */  lui        $v0, %hi(Cd_FileLba)
    /* 147D0 80023FD0 94374224 */  addiu      $v0, $v0, %lo(Cd_FileLba)
    /* 147D4 80023FD4 80200400 */  sll        $a0, $a0, 2
    /* 147D8 80023FD8 21208200 */  addu       $a0, $a0, $v0
    /* 147DC 80023FDC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 147E0 80023FE0 0000848C */  lw         $a0, 0x0($a0)
    /* 147E4 80023FE4 E5C0000C */  jal        CdIntToPos
    /* 147E8 80023FE8 00000000 */   nop
    /* 147EC 80023FEC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 147F0 80023FF0 00000000 */  nop
    /* 147F4 80023FF4 0800E003 */  jr         $ra
    /* 147F8 80023FF8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Cd_GetFilePos
