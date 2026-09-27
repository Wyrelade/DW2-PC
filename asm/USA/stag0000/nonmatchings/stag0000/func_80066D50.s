nonmatching func_80066D50, 0x60

glabel func_80066D50
    /* 39F0 80066D50 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 39F4 80066D54 1000B0AF */  sw         $s0, 0x10($sp)
    /* 39F8 80066D58 21808000 */  addu       $s0, $a0, $zero
    /* 39FC 80066D5C 8901043C */  lui        $a0, (0x1890000 >> 16)
    /* 3A00 80066D60 1800BFAF */  sw         $ra, 0x18($sp)
    /* 3A04 80066D64 688E000C */  jal        Cd_GetFileEntry
    /* 3A08 80066D68 1400B1AF */   sw        $s1, 0x14($sp)
    /* 3A0C 80066D6C 21884000 */  addu       $s1, $v0, $zero
    /* 3A10 80066D70 2C00028E */  lw         $v0, 0x2C($s0)
    /* 3A14 80066D74 0780033C */  lui        $v1, %hi(D_80068EC4)
    /* 3A18 80066D78 0C00428C */  lw         $v0, 0xC($v0)
    /* 3A1C 80066D7C C48E6324 */  addiu      $v1, $v1, %lo(D_80068EC4)
    /* 3A20 80066D80 80100200 */  sll        $v0, $v0, 2
    /* 3A24 80066D84 21104300 */  addu       $v0, $v0, $v1
    /* 3A28 80066D88 0000458C */  lw         $a1, 0x0($v0)
    /* 3A2C 80066D8C 4175000C */  jal        Gfx_HidePartsByMask
    /* 3A30 80066D90 21202002 */   addu      $a0, $s1, $zero
    /* 3A34 80066D94 2176000C */  jal        Gfx_DrawParts
    /* 3A38 80066D98 21202002 */   addu      $a0, $s1, $zero
    /* 3A3C 80066D9C 1800BF8F */  lw         $ra, 0x18($sp)
    /* 3A40 80066DA0 1400B18F */  lw         $s1, 0x14($sp)
    /* 3A44 80066DA4 1000B08F */  lw         $s0, 0x10($sp)
    /* 3A48 80066DA8 0800E003 */  jr         $ra
    /* 3A4C 80066DAC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80066D50
