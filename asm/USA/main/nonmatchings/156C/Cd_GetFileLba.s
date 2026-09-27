nonmatching Cd_GetFileLba, 0x1C

glabel Cd_GetFileLba
    /* 147AC 80023FAC 0480023C */  lui        $v0, %hi(Cd_FileLba)
    /* 147B0 80023FB0 94374224 */  addiu      $v0, $v0, %lo(Cd_FileLba)
    /* 147B4 80023FB4 80200400 */  sll        $a0, $a0, 2
    /* 147B8 80023FB8 21208200 */  addu       $a0, $a0, $v0
    /* 147BC 80023FBC 0000828C */  lw         $v0, 0x0($a0)
    /* 147C0 80023FC0 0800E003 */  jr         $ra
    /* 147C4 80023FC4 00000000 */   nop
endlabel Cd_GetFileLba
