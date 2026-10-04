nonmatching Stg30_BannerDraw, 0xD0

glabel Stg30_BannerDraw
    /* 63C 8006399C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 640 800639A0 1800B2AF */  sw         $s2, 0x18($sp)
    /* 644 800639A4 21908000 */  addu       $s2, $a0, $zero
    /* 648 800639A8 0780023C */  lui        $v0, %hi(Stg30_BannerParts)
    /* 64C 800639AC 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 650 800639B0 1400B1AF */  sw         $s1, 0x14($sp)
    /* 654 800639B4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 658 800639B8 0800438E */  lw         $v1, 0x8($s2)
    /* 65C 800639BC C82F4224 */  addiu      $v0, $v0, %lo(Stg30_BannerParts)
    /* 660 800639C0 80180300 */  sll        $v1, $v1, 2
    /* 664 800639C4 21186200 */  addu       $v1, $v1, $v0
    /* 668 800639C8 0000648C */  lw         $a0, 0x0($v1)
    /* 66C 800639CC 688E000C */  jal        Cd_GetFileEntry
    /* 670 800639D0 00000000 */   nop
    /* 674 800639D4 21884000 */  addu       $s1, $v0, $zero
    /* 678 800639D8 0000228E */  lw         $v0, 0x0($s1)
    /* 67C 800639DC 00000000 */  nop
    /* 680 800639E0 0C004010 */  beqz       $v0, .L80063A14
    /* 684 800639E4 21802002 */   addu      $s0, $s1, $zero
    /* 688 800639E8 04000524 */  addiu      $a1, $zero, 0x4
  .L800639EC:
    /* 68C 800639EC 21300000 */  addu       $a2, $zero, $zero
    /* 690 800639F0 2800448E */  lw         $a0, 0x28($s2)
    /* 694 800639F4 FB88000C */  jal        Math_CycleRange
    /* 698 800639F8 07000724 */   addiu     $a3, $zero, 0x7
    /* 69C 800639FC 0C0002A2 */  sb         $v0, 0xC($s0)
    /* 6A0 80063A00 28001026 */  addiu      $s0, $s0, 0x28
    /* 6A4 80063A04 0000028E */  lw         $v0, 0x0($s0)
    /* 6A8 80063A08 00000000 */  nop
    /* 6AC 80063A0C F7FF4014 */  bnez       $v0, .L800639EC
    /* 6B0 80063A10 04000524 */   addiu     $a1, $zero, 0x4
  .L80063A14:
    /* 6B4 80063A14 0800438E */  lw         $v1, 0x8($s2)
    /* 6B8 80063A18 03000224 */  addiu      $v0, $zero, 0x3
    /* 6BC 80063A1C 0B006214 */  bne        $v1, $v0, .L80063A4C
    /* 6C0 80063A20 0780023C */   lui       $v0, %hi(Stg30_Battle)
    /* 6C4 80063A24 C03C428C */  lw         $v0, %lo(Stg30_Battle)($v0)
    /* 6C8 80063A28 00000000 */  nop
    /* 6CC 80063A2C 03004010 */  beqz       $v0, .L80063A3C
    /* 6D0 80063A30 01000524 */   addiu     $a1, $zero, 0x1
    /* 6D4 80063A34 918E0108 */  j          .L80063A44
    /* 6D8 80063A38 21202002 */   addu      $a0, $s1, $zero
  .L80063A3C:
    /* 6DC 80063A3C 21202002 */  addu       $a0, $s1, $zero
    /* 6E0 80063A40 02000524 */  addiu      $a1, $zero, 0x2
  .L80063A44:
    /* 6E4 80063A44 4175000C */  jal        Gfx_HidePartsByMask
    /* 6E8 80063A48 00000000 */   nop
  .L80063A4C:
    /* 6EC 80063A4C 2176000C */  jal        Gfx_DrawParts
    /* 6F0 80063A50 21202002 */   addu      $a0, $s1, $zero
    /* 6F4 80063A54 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 6F8 80063A58 1800B28F */  lw         $s2, 0x18($sp)
    /* 6FC 80063A5C 1400B18F */  lw         $s1, 0x14($sp)
    /* 700 80063A60 1000B08F */  lw         $s0, 0x10($sp)
    /* 704 80063A64 0800E003 */  jr         $ra
    /* 708 80063A68 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg30_BannerDraw
