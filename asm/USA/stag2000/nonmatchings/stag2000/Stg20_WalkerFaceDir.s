nonmatching Stg20_WalkerFaceDir, 0x20

glabel Stg20_WalkerFaceDir
    /* 7A0C 8006AD6C 0780023C */  lui        $v0, %hi(Stg20_DirAngles)
    /* 7A10 8006AD70 D8034224 */  addiu      $v0, $v0, %lo(Stg20_DirAngles)
    /* 7A14 8006AD74 40280500 */  sll        $a1, $a1, 1
    /* 7A18 8006AD78 2128A200 */  addu       $a1, $a1, $v0
    /* 7A1C 8006AD7C 3800838C */  lw         $v1, 0x38($a0)
    /* 7A20 8006AD80 0000A294 */  lhu        $v0, 0x0($a1)
    /* 7A24 8006AD84 0800E003 */  jr         $ra
    /* 7A28 8006AD88 420062A4 */   sh        $v0, 0x42($v1)
endlabel Stg20_WalkerFaceDir
