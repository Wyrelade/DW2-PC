nonmatching func_8001A8D0, 0x24

glabel func_8001A8D0
    /* B0D0 8001A8D0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* B0D4 8001A8D4 7C00848F */  lw         $a0, %gp_rel(D_80050774)($gp)
    /* B0D8 8001A8D8 1000BFAF */  sw         $ra, 0x10($sp)
    /* B0DC 8001A8DC A369000C */  jal        Snd_PlayById
    /* B0E0 8001A8E0 01000524 */   addiu     $a1, $zero, 0x1
    /* B0E4 8001A8E4 1000BF8F */  lw         $ra, 0x10($sp)
    /* B0E8 8001A8E8 00000000 */  nop
    /* B0EC 8001A8EC 0800E003 */  jr         $ra
    /* B0F0 8001A8F0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001A8D0
