nonmatching Stg20_ShopBitsDraw, 0x48

glabel Stg20_ShopBitsDraw
    /* 88C4 8006BC24 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 88C8 8006BC28 D60D043C */  lui        $a0, (0xDD60000 >> 16)
    /* 88CC 8006BC2C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 88D0 8006BC30 688E000C */  jal        Cd_GetFileEntry
    /* 88D4 8006BC34 1000B0AF */   sw        $s0, 0x10($sp)
    /* 88D8 8006BC38 21804000 */  addu       $s0, $v0, $zero
    /* 88DC 8006BC3C 21200002 */  addu       $a0, $s0, $zero
    /* 88E0 8006BC40 0680023C */  lui        $v0, %hi(D_8005E628)
    /* 88E4 8006BC44 02000524 */  addiu      $a1, $zero, 0x2
    /* 88E8 8006BC48 28E6478C */  lw         $a3, %lo(D_8005E628)($v0)
    /* 88EC 8006BC4C 6D75000C */  jal        Gfx_SetPartsNumber
    /* 88F0 8006BC50 08000624 */   addiu     $a2, $zero, 0x8
    /* 88F4 8006BC54 2176000C */  jal        Gfx_DrawParts
    /* 88F8 8006BC58 21200002 */   addu      $a0, $s0, $zero
    /* 88FC 8006BC5C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 8900 8006BC60 1000B08F */  lw         $s0, 0x10($sp)
    /* 8904 8006BC64 0800E003 */  jr         $ra
    /* 8908 8006BC68 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg20_ShopBitsDraw
