nonmatching Stg35_WinBannerDraw, 0x40

glabel Stg35_WinBannerDraw
    /* 70AC 8006A40C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 70B0 8006A410 1400B1AF */  sw         $s1, 0x14($sp)
    /* 70B4 8006A414 21880000 */  addu       $s1, $zero, $zero
    /* 70B8 8006A418 1800BFAF */  sw         $ra, 0x18($sp)
    /* 70BC 8006A41C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 70C0 8006A420 2C00908C */  lw         $s0, 0x2C($a0)
  .L8006A424:
    /* 70C4 8006A424 6C98010C */  jal        Stg35_PartsDraw
    /* 70C8 8006A428 21200002 */   addu      $a0, $s0, $zero
    /* 70CC 8006A42C 01003126 */  addiu      $s1, $s1, 0x1
    /* 70D0 8006A430 FCFF201A */  blez       $s1, .L8006A424
    /* 70D4 8006A434 04001026 */   addiu     $s0, $s0, 0x4
    /* 70D8 8006A438 1800BF8F */  lw         $ra, 0x18($sp)
    /* 70DC 8006A43C 1400B18F */  lw         $s1, 0x14($sp)
    /* 70E0 8006A440 1000B08F */  lw         $s0, 0x10($sp)
    /* 70E4 8006A444 0800E003 */  jr         $ra
    /* 70E8 8006A448 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg35_WinBannerDraw
