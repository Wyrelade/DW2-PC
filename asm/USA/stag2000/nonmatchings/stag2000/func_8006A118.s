nonmatching func_8006A118, 0x2C

glabel func_8006A118
    /* 6DB8 8006A118 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6DBC 8006A11C 120D043C */  lui        $a0, (0xD120007 >> 16)
    /* 6DC0 8006A120 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6DC4 8006A124 688E000C */  jal        Cd_GetFileEntry
    /* 6DC8 8006A128 07008434 */   ori       $a0, $a0, (0xD120007 & 0xFFFF)
    /* 6DCC 8006A12C 2176000C */  jal        Gfx_DrawParts
    /* 6DD0 8006A130 21204000 */   addu      $a0, $v0, $zero
    /* 6DD4 8006A134 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6DD8 8006A138 00000000 */  nop
    /* 6DDC 8006A13C 0800E003 */  jr         $ra
    /* 6DE0 8006A140 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006A118
