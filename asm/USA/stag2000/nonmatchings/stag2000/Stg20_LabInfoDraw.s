nonmatching Stg20_LabInfoDraw, 0x160

glabel Stg20_LabInfoDraw
    /* 62EC 8006964C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 62F0 80069650 1800BFAF */  sw         $ra, 0x18($sp)
    /* 62F4 80069654 1400B1AF */  sw         $s1, 0x14($sp)
    /* 62F8 80069658 1000B0AF */  sw         $s0, 0x10($sp)
    /* 62FC 8006965C 2C00918C */  lw         $s1, 0x2C($a0)
    /* 6300 80069660 120D043C */  lui        $a0, (0xD120008 >> 16)
    /* 6304 80069664 688E000C */  jal        Cd_GetFileEntry
    /* 6308 80069668 08008434 */   ori       $a0, $a0, (0xD120008 & 0xFFFF)
    /* 630C 8006966C 21804000 */  addu       $s0, $v0, $zero
    /* 6310 80069670 21200002 */  addu       $a0, $s0, $zero
    /* 6314 80069674 5C00228E */  lw         $v0, 0x5C($s1)
    /* 6318 80069678 02000524 */  addiu      $a1, $zero, 0x2
    /* 631C 8006967C 14004784 */  lh         $a3, 0x14($v0)
    /* 6320 80069680 6D75000C */  jal        Gfx_SetPartsNumber
    /* 6324 80069684 03000624 */   addiu     $a2, $zero, 0x3
    /* 6328 80069688 21200002 */  addu       $a0, $s0, $zero
    /* 632C 8006968C 5C00228E */  lw         $v0, 0x5C($s1)
    /* 6330 80069690 04000524 */  addiu      $a1, $zero, 0x4
    /* 6334 80069694 16004784 */  lh         $a3, 0x16($v0)
    /* 6338 80069698 6D75000C */  jal        Gfx_SetPartsNumber
    /* 633C 8006969C 03000624 */   addiu     $a2, $zero, 0x3
    /* 6340 800696A0 21200002 */  addu       $a0, $s0, $zero
    /* 6344 800696A4 5C00228E */  lw         $v0, 0x5C($s1)
    /* 6348 800696A8 08000524 */  addiu      $a1, $zero, 0x8
    /* 634C 800696AC 18004784 */  lh         $a3, 0x18($v0)
    /* 6350 800696B0 6D75000C */  jal        Gfx_SetPartsNumber
    /* 6354 800696B4 03000624 */   addiu     $a2, $zero, 0x3
    /* 6358 800696B8 21200002 */  addu       $a0, $s0, $zero
    /* 635C 800696BC 5C00228E */  lw         $v0, 0x5C($s1)
    /* 6360 800696C0 10000524 */  addiu      $a1, $zero, 0x10
    /* 6364 800696C4 1A004784 */  lh         $a3, 0x1A($v0)
    /* 6368 800696C8 6D75000C */  jal        Gfx_SetPartsNumber
    /* 636C 800696CC 03000624 */   addiu     $a2, $zero, 0x3
    /* 6370 800696D0 21200002 */  addu       $a0, $s0, $zero
    /* 6374 800696D4 5C00228E */  lw         $v0, 0x5C($s1)
    /* 6378 800696D8 20000524 */  addiu      $a1, $zero, 0x20
    /* 637C 800696DC 0D004790 */  lbu        $a3, 0xD($v0)
    /* 6380 800696E0 6D75000C */  jal        Gfx_SetPartsNumber
    /* 6384 800696E4 02000624 */   addiu     $a2, $zero, 0x2
    /* 6388 800696E8 21200002 */  addu       $a0, $s0, $zero
    /* 638C 800696EC 5C00228E */  lw         $v0, 0x5C($s1)
    /* 6390 800696F0 40000524 */  addiu      $a1, $zero, 0x40
    /* 6394 800696F4 1C004784 */  lh         $a3, 0x1C($v0)
    /* 6398 800696F8 6D75000C */  jal        Gfx_SetPartsNumber
    /* 639C 800696FC 03000624 */   addiu     $a2, $zero, 0x3
    /* 63A0 80069700 21200002 */  addu       $a0, $s0, $zero
    /* 63A4 80069704 5C00228E */  lw         $v0, 0x5C($s1)
    /* 63A8 80069708 80000524 */  addiu      $a1, $zero, 0x80
    /* 63AC 8006970C 1E004784 */  lh         $a3, 0x1E($v0)
    /* 63B0 80069710 6D75000C */  jal        Gfx_SetPartsNumber
    /* 63B4 80069714 03000624 */   addiu     $a2, $zero, 0x3
    /* 63B8 80069718 21200002 */  addu       $a0, $s0, $zero
    /* 63BC 8006971C 5C00228E */  lw         $v0, 0x5C($s1)
    /* 63C0 80069720 00010524 */  addiu      $a1, $zero, 0x100
    /* 63C4 80069724 20004784 */  lh         $a3, 0x20($v0)
    /* 63C8 80069728 6D75000C */  jal        Gfx_SetPartsNumber
    /* 63CC 8006972C 03000624 */   addiu     $a2, $zero, 0x3
    /* 63D0 80069730 21200002 */  addu       $a0, $s0, $zero
    /* 63D4 80069734 5C00228E */  lw         $v0, 0x5C($s1)
    /* 63D8 80069738 00020524 */  addiu      $a1, $zero, 0x200
    /* 63DC 8006973C 1000478C */  lw         $a3, 0x10($v0)
    /* 63E0 80069740 6D75000C */  jal        Gfx_SetPartsNumber
    /* 63E4 80069744 08000624 */   addiu     $a2, $zero, 0x8
    /* 63E8 80069748 5C00228E */  lw         $v0, 0x5C($s1)
    /* 63EC 8006974C 00000000 */  nop
    /* 63F0 80069750 0D004490 */  lbu        $a0, 0xD($v0)
    /* 63F4 80069754 0F004590 */  lbu        $a1, 0xF($v0)
    /* 63F8 80069758 1000468C */  lw         $a2, 0x10($v0)
    /* 63FC 8006975C 617A000C */  jal        Digi_GetExpToNextLevel
    /* 6400 80069760 00000000 */   nop
    /* 6404 80069764 21200002 */  addu       $a0, $s0, $zero
    /* 6408 80069768 00040524 */  addiu      $a1, $zero, 0x400
    /* 640C 8006976C 08000624 */  addiu      $a2, $zero, 0x8
    /* 6410 80069770 6D75000C */  jal        Gfx_SetPartsNumber
    /* 6414 80069774 21384000 */   addu      $a3, $v0, $zero
    /* 6418 80069778 21200002 */  addu       $a0, $s0, $zero
    /* 641C 8006977C 5C00228E */  lw         $v0, 0x5C($s1)
    /* 6420 80069780 00080524 */  addiu      $a1, $zero, 0x800
    /* 6424 80069784 0E004790 */  lbu        $a3, 0xE($v0)
    /* 6428 80069788 6D75000C */  jal        Gfx_SetPartsNumber
    /* 642C 8006978C 02000624 */   addiu     $a2, $zero, 0x2
    /* 6430 80069790 2176000C */  jal        Gfx_DrawParts
    /* 6434 80069794 21200002 */   addu      $a0, $s0, $zero
    /* 6438 80069798 1800BF8F */  lw         $ra, 0x18($sp)
    /* 643C 8006979C 1400B18F */  lw         $s1, 0x14($sp)
    /* 6440 800697A0 1000B08F */  lw         $s0, 0x10($sp)
    /* 6444 800697A4 0800E003 */  jr         $ra
    /* 6448 800697A8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg20_LabInfoDraw
