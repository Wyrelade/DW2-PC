nonmatching func_80066778, 0x58

glabel func_80066778
    /* 3418 80066778 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 341C 8006677C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3420 80066780 2180A000 */  addu       $s0, $a1, $zero
    /* 3424 80066784 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 3428 80066788 1800B2AF */  sw         $s2, 0x18($sp)
    /* 342C 8006678C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3430 80066790 0000828C */  lw         $v0, 0x0($a0)
    /* 3434 80066794 2188C000 */  addu       $s1, $a2, $zero
    /* 3438 80066798 0000448C */  lw         $a0, 0x0($v0)
    /* 343C 8006679C 688E000C */  jal        Cd_GetFileEntry
    /* 3440 800667A0 2190E000 */   addu      $s2, $a3, $zero
    /* 3444 800667A4 21204000 */  addu       $a0, $v0, $zero
    /* 3448 800667A8 21280002 */  addu       $a1, $s0, $zero
    /* 344C 800667AC 21302002 */  addu       $a2, $s1, $zero
    /* 3450 800667B0 6D75000C */  jal        Gfx_SetPartsNumber
    /* 3454 800667B4 21384002 */   addu      $a3, $s2, $zero
    /* 3458 800667B8 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 345C 800667BC 1800B28F */  lw         $s2, 0x18($sp)
    /* 3460 800667C0 1400B18F */  lw         $s1, 0x14($sp)
    /* 3464 800667C4 1000B08F */  lw         $s0, 0x10($sp)
    /* 3468 800667C8 0800E003 */  jr         $ra
    /* 346C 800667CC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80066778
