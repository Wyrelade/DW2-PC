nonmatching Stg11_ModeMenuDraw, 0x118

glabel Stg11_ModeMenuDraw
    /* 8A8 80063C08 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 8AC 80063C0C 2400B5AF */  sw         $s5, 0x24($sp)
    /* 8B0 80063C10 21A88000 */  addu       $s5, $a0, $zero
    /* 8B4 80063C14 2800BFAF */  sw         $ra, 0x28($sp)
    /* 8B8 80063C18 2000B4AF */  sw         $s4, 0x20($sp)
    /* 8BC 80063C1C 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 8C0 80063C20 1800B2AF */  sw         $s2, 0x18($sp)
    /* 8C4 80063C24 1400B1AF */  sw         $s1, 0x14($sp)
    /* 8C8 80063C28 1000B0AF */  sw         $s0, 0x10($sp)
    /* 8CC 80063C2C 2C00B38E */  lw         $s3, 0x2C($s5)
    /* 8D0 80063C30 00000000 */  nop
    /* 8D4 80063C34 2800628E */  lw         $v0, 0x28($s3)
    /* 8D8 80063C38 00000000 */  nop
    /* 8DC 80063C3C 2F004010 */  beqz       $v0, .L80063CFC
    /* 8E0 80063C40 00000000 */   nop
    /* 8E4 80063C44 280D043C */  lui        $a0, (0xD280002 >> 16)
    /* 8E8 80063C48 688E000C */  jal        Cd_GetFileEntry
    /* 8EC 80063C4C 02008434 */   ori       $a0, $a0, (0xD280002 & 0xFFFF)
    /* 8F0 80063C50 21A04000 */  addu       $s4, $v0, $zero
    /* 8F4 80063C54 0000828E */  lw         $v0, 0x0($s4)
    /* 8F8 80063C58 00000000 */  nop
    /* 8FC 80063C5C 27004010 */  beqz       $v0, .L80063CFC
    /* 900 80063C60 21908002 */   addu      $s2, $s4, $zero
  .L80063C64:
    /* 904 80063C64 0000448E */  lw         $a0, 0x0($s2)
    /* 908 80063C68 688E000C */  jal        Cd_GetFileEntry
    /* 90C 80063C6C 00000000 */   nop
    /* 910 80063C70 17005416 */  bne        $s2, $s4, .L80063CD0
    /* 914 80063C74 21884000 */   addu      $s1, $v0, $zero
    /* 918 80063C78 280D043C */  lui        $a0, (0xD280004 >> 16)
    /* 91C 80063C7C 688E000C */  jal        Cd_GetFileEntry
    /* 920 80063C80 04008434 */   ori       $a0, $a0, (0xD280004 & 0xFFFF)
    /* 924 80063C84 21202002 */  addu       $a0, $s1, $zero
    /* 928 80063C88 20000524 */  addiu      $a1, $zero, 0x20
    /* 92C 80063C8C 10006626 */  addiu      $a2, $s3, 0x10
    /* 930 80063C90 21804000 */  addu       $s0, $v0, $zero
    /* 934 80063C94 CF4D000C */  jal        Menu_SetPartsGridPos
    /* 938 80063C98 14006726 */   addiu     $a3, $s3, 0x14
    /* 93C 80063C9C 21202002 */  addu       $a0, $s1, $zero
    /* 940 80063CA0 2800A68E */  lw         $a2, 0x28($s5)
    /* 944 80063CA4 20000524 */  addiu      $a1, $zero, 0x20
    /* 948 80063CA8 83300600 */  sra        $a2, $a2, 2
    /* 94C 80063CAC EE4D000C */  jal        Gfx_SetPartsPalette
    /* 950 80063CB0 0300C630 */   andi      $a2, $a2, 0x3
    /* 954 80063CB4 20006286 */  lh         $v0, 0x20($s3)
    /* 958 80063CB8 00000000 */  nop
    /* 95C 80063CBC 80100200 */  sll        $v0, $v0, 2
    /* 960 80063CC0 21105000 */  addu       $v0, $v0, $s0
    /* 964 80063CC4 FCFF458C */  lw         $a1, -0x4($v0)
    /* 968 80063CC8 4175000C */  jal        Gfx_HidePartsByMask
    /* 96C 80063CCC 21202002 */   addu      $a0, $s1, $zero
  .L80063CD0:
    /* 970 80063CD0 21202002 */  addu       $a0, $s1, $zero
    /* 974 80063CD4 00100524 */  addiu      $a1, $zero, 0x1000
    /* 978 80063CD8 2800668E */  lw         $a2, 0x28($s3)
    /* 97C 80063CDC 5475000C */  jal        Gfx_SetPartsScale
    /* 980 80063CE0 04005226 */   addiu     $s2, $s2, 0x4
    /* 984 80063CE4 2176000C */  jal        Gfx_DrawParts
    /* 988 80063CE8 21202002 */   addu      $a0, $s1, $zero
    /* 98C 80063CEC 0000428E */  lw         $v0, 0x0($s2)
    /* 990 80063CF0 00000000 */  nop
    /* 994 80063CF4 DBFF4014 */  bnez       $v0, .L80063C64
    /* 998 80063CF8 00000000 */   nop
  .L80063CFC:
    /* 99C 80063CFC 2800BF8F */  lw         $ra, 0x28($sp)
    /* 9A0 80063D00 2400B58F */  lw         $s5, 0x24($sp)
    /* 9A4 80063D04 2000B48F */  lw         $s4, 0x20($sp)
    /* 9A8 80063D08 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 9AC 80063D0C 1800B28F */  lw         $s2, 0x18($sp)
    /* 9B0 80063D10 1400B18F */  lw         $s1, 0x14($sp)
    /* 9B4 80063D14 1000B08F */  lw         $s0, 0x10($sp)
    /* 9B8 80063D18 0800E003 */  jr         $ra
    /* 9BC 80063D1C 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel Stg11_ModeMenuDraw
