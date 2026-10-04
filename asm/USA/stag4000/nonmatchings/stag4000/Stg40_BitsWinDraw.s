nonmatching Stg40_BitsWinDraw, 0x78

glabel Stg40_BitsWinDraw
    /* 3A18 80066D78 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 3A1C 80066D7C 1800BFAF */  sw         $ra, 0x18($sp)
    /* 3A20 80066D80 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3A24 80066D84 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3A28 80066D88 2C00918C */  lw         $s1, 0x2C($a0)
    /* 3A2C 80066D8C 00000000 */  nop
    /* 3A30 80066D90 0400228E */  lw         $v0, 0x4($s1)
    /* 3A34 80066D94 00000000 */  nop
    /* 3A38 80066D98 10004010 */  beqz       $v0, .L80066DDC
    /* 3A3C 80066D9C 00000000 */   nop
    /* 3A40 80066DA0 D407043C */  lui        $a0, (0x7D40002 >> 16)
    /* 3A44 80066DA4 688E000C */  jal        Cd_GetFileEntry
    /* 3A48 80066DA8 02008434 */   ori       $a0, $a0, (0x7D40002 & 0xFFFF)
    /* 3A4C 80066DAC 21804000 */  addu       $s0, $v0, $zero
    /* 3A50 80066DB0 21200002 */  addu       $a0, $s0, $zero
    /* 3A54 80066DB4 02000524 */  addiu      $a1, $zero, 0x2
    /* 3A58 80066DB8 0800278E */  lw         $a3, 0x8($s1)
    /* 3A5C 80066DBC 6D75000C */  jal        Gfx_SetPartsNumber
    /* 3A60 80066DC0 08000624 */   addiu     $a2, $zero, 0x8
    /* 3A64 80066DC4 21200002 */  addu       $a0, $s0, $zero
    /* 3A68 80066DC8 0400268E */  lw         $a2, 0x4($s1)
    /* 3A6C 80066DCC 5475000C */  jal        Gfx_SetPartsScale
    /* 3A70 80066DD0 00100524 */   addiu     $a1, $zero, 0x1000
    /* 3A74 80066DD4 2176000C */  jal        Gfx_DrawParts
    /* 3A78 80066DD8 21200002 */   addu      $a0, $s0, $zero
  .L80066DDC:
    /* 3A7C 80066DDC 1800BF8F */  lw         $ra, 0x18($sp)
    /* 3A80 80066DE0 1400B18F */  lw         $s1, 0x14($sp)
    /* 3A84 80066DE4 1000B08F */  lw         $s0, 0x10($sp)
    /* 3A88 80066DE8 0800E003 */  jr         $ra
    /* 3A8C 80066DEC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg40_BitsWinDraw
