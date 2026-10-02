nonmatching MemCardCallback, 0x14

glabel MemCardCallback
    /* 2F978 8003F178 0680033C */  lui        $v1, %hi(D_80062FC4)
    /* 2F97C 8003F17C C42F6324 */  addiu      $v1, $v1, %lo(D_80062FC4)
    /* 2F980 8003F180 0000628C */  lw         $v0, 0x0($v1)
    /* 2F984 8003F184 0800E003 */  jr         $ra
    /* 2F988 8003F188 000064AC */   sw        $a0, 0x0($v1)
endlabel MemCardCallback
