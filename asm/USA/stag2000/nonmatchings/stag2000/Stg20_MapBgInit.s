nonmatching Stg20_MapBgInit, 0x24

glabel Stg20_MapBgInit
    /* 400 80063760 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 404 80063764 1000BFAF */  sw         $ra, 0x10($sp)
    /* 408 80063768 2C00828C */  lw         $v0, 0x2C($a0)
    /* 40C 8006376C 848D010C */  jal        Stg20_BuildMapGrid
    /* 410 80063770 000045AC */   sw        $a1, 0x0($v0)
    /* 414 80063774 1000BF8F */  lw         $ra, 0x10($sp)
    /* 418 80063778 00000000 */  nop
    /* 41C 8006377C 0800E003 */  jr         $ra
    /* 420 80063780 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg20_MapBgInit
