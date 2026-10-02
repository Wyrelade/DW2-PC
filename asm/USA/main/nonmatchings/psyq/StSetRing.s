nonmatching StSetRing, 0x2C

glabel StSetRing
    /* 1E3D4 8002DBD4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1E3D8 8002DBD8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1E3DC 8002DBDC 0680013C */  lui        $at, %hi(D_80061B38)
    /* 1E3E0 8002DBE0 381B24AC */  sw         $a0, %lo(D_80061B38)($at)
    /* 1E3E4 8002DBE4 0680013C */  lui        $at, %hi(D_80061B3C)
    /* 1E3E8 8002DBE8 A5B7000C */  jal        StClearRing
    /* 1E3EC 8002DBEC 3C1B25AC */   sw        $a1, %lo(D_80061B3C)($at)
    /* 1E3F0 8002DBF0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1E3F4 8002DBF4 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 1E3F8 8002DBF8 0800E003 */  jr         $ra
    /* 1E3FC 8002DBFC 00000000 */   nop
endlabel StSetRing
    /* 1E400 8002DC00 00000000 */  nop
