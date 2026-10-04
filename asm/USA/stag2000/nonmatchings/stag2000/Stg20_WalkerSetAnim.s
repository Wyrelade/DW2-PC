nonmatching Stg20_WalkerSetAnim, 0x40

glabel Stg20_WalkerSetAnim
    /* 76AC 8006AA0C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 76B0 8006AA10 1000BFAF */  sw         $ra, 0x10($sp)
    /* 76B4 8006AA14 0400828C */  lw         $v0, 0x4($a0)
    /* 76B8 8006AA18 2C00838C */  lw         $v1, 0x2C($a0)
    /* 76BC 8006AA1C 07004004 */  bltz       $v0, .L8006AA3C
    /* 76C0 8006AA20 00000000 */   nop
    /* 76C4 8006AA24 2C00628C */  lw         $v0, 0x2C($v1)
    /* 76C8 8006AA28 00000000 */  nop
    /* 76CC 8006AA2C 03004510 */  beq        $v0, $a1, .L8006AA3C
    /* 76D0 8006AA30 00000000 */   nop
    /* 76D4 8006AA34 6A7C000C */  jal        Anim_SetModelAnim
    /* 76D8 8006AA38 2C0065AC */   sw        $a1, 0x2C($v1)
  .L8006AA3C:
    /* 76DC 8006AA3C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 76E0 8006AA40 00000000 */  nop
    /* 76E4 8006AA44 0800E003 */  jr         $ra
    /* 76E8 8006AA48 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg20_WalkerSetAnim
