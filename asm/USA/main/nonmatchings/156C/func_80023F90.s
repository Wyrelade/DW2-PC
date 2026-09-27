nonmatching func_80023F90, 0x1C

glabel func_80023F90
    /* 14790 80023F90 0480023C */  lui        $v0, %hi(Cd_FileSectors)
    /* 14794 80023F94 00714224 */  addiu      $v0, $v0, %lo(Cd_FileSectors)
    /* 14798 80023F98 40200400 */  sll        $a0, $a0, 1
    /* 1479C 80023F9C 21208200 */  addu       $a0, $a0, $v0
    /* 147A0 80023FA0 00008294 */  lhu        $v0, 0x0($a0)
    /* 147A4 80023FA4 0800E003 */  jr         $ra
    /* 147A8 80023FA8 00000000 */   nop
endlabel func_80023F90
