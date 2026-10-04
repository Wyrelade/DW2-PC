nonmatching Stg35_VsMenuDraw, 0x88

glabel Stg35_VsMenuDraw
    /* 12D8 80064638 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 12DC 8006463C 21108000 */  addu       $v0, $a0, $zero
    /* 12E0 80064640 06000524 */  addiu      $a1, $zero, 0x6
    /* 12E4 80064644 21300000 */  addu       $a2, $zero, $zero
    /* 12E8 80064648 1400BFAF */  sw         $ra, 0x14($sp)
    /* 12EC 8006464C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 12F0 80064650 2800448C */  lw         $a0, 0x28($v0)
    /* 12F4 80064654 2C00508C */  lw         $s0, 0x2C($v0)
    /* 12F8 80064658 FB88000C */  jal        Math_CycleRange
    /* 12FC 8006465C 07000724 */   addiu     $a3, $zero, 0x7
    /* 1300 80064660 21200002 */  addu       $a0, $s0, $zero
    /* 1304 80064664 2A000524 */  addiu      $a1, $zero, 0x2A
    /* 1308 80064668 4899010C */  jal        Stg35_PartsSetPalette
    /* 130C 8006466C 21304000 */   addu      $a2, $v0, $zero
    /* 1310 80064670 6C98010C */  jal        Stg35_PartsDraw
    /* 1314 80064674 21200002 */   addu      $a0, $s0, $zero
    /* 1318 80064678 6C98010C */  jal        Stg35_PartsDraw
    /* 131C 8006467C 04000426 */   addiu     $a0, $s0, 0x4
    /* 1320 80064680 3400028E */  lw         $v0, 0x34($s0)
    /* 1324 80064684 00000000 */  nop
    /* 1328 80064688 03004010 */  beqz       $v0, .L80064698
    /* 132C 8006468C 00000000 */   nop
    /* 1330 80064690 6C98010C */  jal        Stg35_PartsDraw
    /* 1334 80064694 08000426 */   addiu     $a0, $s0, 0x8
  .L80064698:
    /* 1338 80064698 3800028E */  lw         $v0, 0x38($s0)
    /* 133C 8006469C 00000000 */  nop
    /* 1340 800646A0 03004010 */  beqz       $v0, .L800646B0
    /* 1344 800646A4 00000000 */   nop
    /* 1348 800646A8 6C98010C */  jal        Stg35_PartsDraw
    /* 134C 800646AC 0C000426 */   addiu     $a0, $s0, 0xC
  .L800646B0:
    /* 1350 800646B0 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1354 800646B4 1000B08F */  lw         $s0, 0x10($sp)
    /* 1358 800646B8 0800E003 */  jr         $ra
    /* 135C 800646BC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg35_VsMenuDraw
