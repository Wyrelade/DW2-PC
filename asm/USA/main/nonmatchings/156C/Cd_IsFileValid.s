nonmatching Cd_IsFileValid, 0x1C

glabel Cd_IsFileValid
    /* 14774 80023F74 0480023C */  lui        $v0, %hi(Cd_FileLba)
    /* 14778 80023F78 94374224 */  addiu      $v0, $v0, %lo(Cd_FileLba)
    /* 1477C 80023F7C 80200400 */  sll        $a0, $a0, 2
    /* 14780 80023F80 21208200 */  addu       $a0, $a0, $v0
    /* 14784 80023F84 0000828C */  lw         $v0, 0x0($a0)
    /* 14788 80023F88 0800E003 */  jr         $ra
    /* 1478C 80023F8C 2B100200 */   sltu      $v0, $zero, $v0
endlabel Cd_IsFileValid
