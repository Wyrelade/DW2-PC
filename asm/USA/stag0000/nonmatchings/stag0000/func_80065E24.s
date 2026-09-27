nonmatching func_80065E24, 0x260

glabel func_80065E24
    /* 2AC4 80065E24 98FFBD27 */  addiu      $sp, $sp, -0x68
    /* 2AC8 80065E28 6000BEAF */  sw         $fp, 0x60($sp)
    /* 2ACC 80065E2C 01000324 */  addiu      $v1, $zero, 0x1
    /* 2AD0 80065E30 6400BFAF */  sw         $ra, 0x64($sp)
    /* 2AD4 80065E34 5C00B7AF */  sw         $s7, 0x5C($sp)
    /* 2AD8 80065E38 5800B6AF */  sw         $s6, 0x58($sp)
    /* 2ADC 80065E3C 5400B5AF */  sw         $s5, 0x54($sp)
    /* 2AE0 80065E40 5000B4AF */  sw         $s4, 0x50($sp)
    /* 2AE4 80065E44 4C00B3AF */  sw         $s3, 0x4C($sp)
    /* 2AE8 80065E48 4800B2AF */  sw         $s2, 0x48($sp)
    /* 2AEC 80065E4C 4400B1AF */  sw         $s1, 0x44($sp)
    /* 2AF0 80065E50 4000B0AF */  sw         $s0, 0x40($sp)
    /* 2AF4 80065E54 1000828C */  lw         $v0, 0x10($a0)
    /* 2AF8 80065E58 2C00948C */  lw         $s4, 0x2C($a0)
    /* 2AFC 80065E5C 05004314 */  bne        $v0, $v1, .L80065E74
    /* 2B00 80065E60 21F00000 */   addu      $fp, $zero, $zero
    /* 2B04 80065E64 1400828C */  lw         $v0, 0x14($a0)
    /* 2B08 80065E68 00000000 */  nop
    /* 2B0C 80065E6C 79004010 */  beqz       $v0, .L80066054
    /* 2B10 80065E70 00000000 */   nop
  .L80065E74:
    /* 2B14 80065E74 2800838C */  lw         $v1, 0x28($a0)
    /* 2B18 80065E78 00000000 */  nop
    /* 2B1C 80065E7C 14006228 */  slti       $v0, $v1, 0x14
    /* 2B20 80065E80 03004010 */  beqz       $v0, .L80065E90
    /* 2B24 80065E84 28006228 */   slti      $v0, $v1, 0x28
    /* 2B28 80065E88 A7970108 */  j          .L80065E9C
    /* 2B2C 80065E8C 01001E24 */   addiu     $fp, $zero, 0x1
  .L80065E90:
    /* 2B30 80065E90 02004014 */  bnez       $v0, .L80065E9C
    /* 2B34 80065E94 D8FF6224 */   addiu     $v0, $v1, -0x28
    /* 2B38 80065E98 280082AC */  sw         $v0, 0x28($a0)
  .L80065E9C:
    /* 2B3C 80065E9C 688E000C */  jal        Cd_GetFileEntry
    /* 2B40 80065EA0 0B01043C */   lui       $a0, (0x10B0000 >> 16)
    /* 2B44 80065EA4 21280000 */  addu       $a1, $zero, $zero
    /* 2B48 80065EA8 0900C013 */  beqz       $fp, .L80065ED0
    /* 2B4C 80065EAC 21804000 */   addu      $s0, $v0, $zero
    /* 2B50 80065EB0 0800828E */  lw         $v0, 0x8($s4)
    /* 2B54 80065EB4 00000000 */  nop
    /* 2B58 80065EB8 05004014 */  bnez       $v0, .L80065ED0
    /* 2B5C 80065EBC 01000324 */   addiu     $v1, $zero, 0x1
    /* 2B60 80065EC0 0000828E */  lw         $v0, 0x0($s4)
    /* 2B64 80065EC4 00000000 */  nop
    /* 2B68 80065EC8 01004224 */  addiu      $v0, $v0, 0x1
    /* 2B6C 80065ECC 04284300 */  sllv       $a1, $v1, $v0
  .L80065ED0:
    /* 2B70 80065ED0 4175000C */  jal        Gfx_HidePartsByMask
    /* 2B74 80065ED4 21200002 */   addu      $a0, $s0, $zero
    /* 2B78 80065ED8 1000848E */  lw         $a0, 0x10($s4)
    /* 2B7C 80065EDC 3D7A000C */  jal        func_8001E8F4
    /* 2B80 80065EE0 00000000 */   nop
    /* 2B84 80065EE4 21200002 */  addu       $a0, $s0, $zero
    /* 2B88 80065EE8 20000524 */  addiu      $a1, $zero, 0x20
    /* 2B8C 80065EEC 04000624 */  addiu      $a2, $zero, 0x4
    /* 2B90 80065EF0 6D75000C */  jal        Gfx_SetPartsNumber
    /* 2B94 80065EF4 21384000 */   addu      $a3, $v0, $zero
    /* 2B98 80065EF8 2176000C */  jal        Gfx_DrawParts
    /* 2B9C 80065EFC 21200002 */   addu      $a0, $s0, $zero
    /* 2BA0 80065F00 0780033C */  lui        $v1, %hi(D_80068DB8)
    /* 2BA4 80065F04 0C00828E */  lw         $v0, 0xC($s4)
    /* 2BA8 80065F08 B88D6324 */  addiu      $v1, $v1, %lo(D_80068DB8)
    /* 2BAC 80065F0C C0100200 */  sll        $v0, $v0, 3
    /* 2BB0 80065F10 21104300 */  addu       $v0, $v0, $v1
    /* 2BB4 80065F14 0000448C */  lw         $a0, 0x0($v0)
    /* 2BB8 80065F18 688E000C */  jal        Cd_GetFileEntry
    /* 2BBC 80065F1C 00000000 */   nop
    /* 2BC0 80065F20 21280000 */  addu       $a1, $zero, $zero
    /* 2BC4 80065F24 0900C013 */  beqz       $fp, .L80065F4C
    /* 2BC8 80065F28 21804000 */   addu      $s0, $v0, $zero
    /* 2BCC 80065F2C 0800838E */  lw         $v1, 0x8($s4)
    /* 2BD0 80065F30 01000224 */  addiu      $v0, $zero, 0x1
    /* 2BD4 80065F34 05006214 */  bne        $v1, $v0, .L80065F4C
    /* 2BD8 80065F38 00000000 */   nop
    /* 2BDC 80065F3C 0400828E */  lw         $v0, 0x4($s4)
    /* 2BE0 80065F40 00000000 */  nop
    /* 2BE4 80065F44 01004224 */  addiu      $v0, $v0, 0x1
    /* 2BE8 80065F48 04284300 */  sllv       $a1, $v1, $v0
  .L80065F4C:
    /* 2BEC 80065F4C 4175000C */  jal        Gfx_HidePartsByMask
    /* 2BF0 80065F50 21200002 */   addu      $a0, $s0, $zero
    /* 2BF4 80065F54 2176000C */  jal        Gfx_DrawParts
    /* 2BF8 80065F58 21200002 */   addu      $a0, $s0, $zero
    /* 2BFC 80065F5C 21880000 */  addu       $s1, $zero, $zero
    /* 2C00 80065F60 1C001024 */  addiu      $s0, $zero, 0x1C
  .L80065F64:
    /* 2C04 80065F64 E26E000C */  jal        Text_Close
    /* 2C08 80065F68 21209002 */   addu      $a0, $s4, $s0
    /* 2C0C 80065F6C 01003126 */  addiu      $s1, $s1, 0x1
    /* 2C10 80065F70 0E00222A */  slti       $v0, $s1, 0xE
    /* 2C14 80065F74 FBFF4014 */  bnez       $v0, .L80065F64
    /* 2C18 80065F78 04001026 */   addiu     $s0, $s0, 0x4
    /* 2C1C 80065F7C 0C00838E */  lw         $v1, 0xC($s4)
    /* 2C20 80065F80 01000224 */  addiu      $v0, $zero, 0x1
    /* 2C24 80065F84 33006214 */  bne        $v1, $v0, .L80066054
    /* 2C28 80065F88 21880000 */   addu      $s1, $zero, $zero
    /* 2C2C 80065F8C 5C00968E */  lw         $s6, 0x5C($s4)
    /* 2C30 80065F90 21A82002 */  addu       $s5, $s1, $zero
    /* 2C34 80065F94 10001724 */  addiu      $s7, $zero, 0x10
  .L80065F98:
    /* 2C38 80065F98 21800000 */  addu       $s0, $zero, $zero
    /* 2C3C 80065F9C 3A001324 */  addiu      $s3, $zero, 0x3A
    /* 2C40 80065FA0 80101100 */  sll        $v0, $s1, 2
    /* 2C44 80065FA4 1C005224 */  addiu      $s2, $v0, 0x1C
  .L80065FA8:
    /* 2C48 80065FA8 0780083C */  lui        $t0, %hi(D_80068CE8)
    /* 2C4C 80065FAC E88C0825 */  addiu      $t0, $t0, %lo(D_80068CE8)
    /* 2C50 80065FB0 2110C802 */  addu       $v0, $s6, $t0
    /* 2C54 80065FB4 00004490 */  lbu        $a0, 0x0($v0)
    /* 2C58 80065FB8 617B000C */  jal        func_8001ED84
    /* 2C5C 80065FBC 0100D626 */   addiu     $s6, $s6, 0x1
    /* 2C60 80065FC0 2400A2AF */  sw         $v0, 0x24($sp)
    /* 2C64 80065FC4 1000A0AF */  sw         $zero, 0x10($sp)
    /* 2C68 80065FC8 1800B7A7 */  sh         $s7, 0x18($sp)
    /* 2C6C 80065FCC 1A00B3A7 */  sh         $s3, 0x1A($sp)
    /* 2C70 80065FD0 2800A0AF */  sw         $zero, 0x28($sp)
    /* 2C74 80065FD4 1C00A0AF */  sw         $zero, 0x1C($sp)
    /* 2C78 80065FD8 2000A0AF */  sw         $zero, 0x20($sp)
    /* 2C7C 80065FDC 6000828E */  lw         $v0, 0x60($s4)
    /* 2C80 80065FE0 00000000 */  nop
    /* 2C84 80065FE4 0E005514 */  bne        $v0, $s5, .L80066020
    /* 2C88 80065FE8 00000000 */   nop
    /* 2C8C 80065FEC 6400828E */  lw         $v0, 0x64($s4)
    /* 2C90 80065FF0 00000000 */  nop
    /* 2C94 80065FF4 0A005014 */  bne        $v0, $s0, .L80066020
    /* 2C98 80065FF8 00000000 */   nop
    /* 2C9C 80065FFC 0500C013 */  beqz       $fp, .L80066014
    /* 2CA0 80066000 01000224 */   addiu     $v0, $zero, 0x1
    /* 2CA4 80066004 0800838E */  lw         $v1, 0x8($s4)
    /* 2CA8 80066008 00000000 */  nop
    /* 2CAC 8006600C 0A006210 */  beq        $v1, $v0, .L80066038
    /* 2CB0 80066010 00000000 */   nop
  .L80066014:
    /* 2CB4 80066014 04000224 */  addiu      $v0, $zero, 0x4
    /* 2CB8 80066018 09980108 */  j          .L80066024
    /* 2CBC 8006601C 1400A2AF */   sw        $v0, 0x14($sp)
  .L80066020:
    /* 2CC0 80066020 1400A0AF */  sw         $zero, 0x14($sp)
  .L80066024:
    /* 2CC4 80066024 21209202 */  addu       $a0, $s4, $s2
    /* 2CC8 80066028 096F000C */  jal        Text_Open
    /* 2CCC 8006602C 1000A527 */   addiu     $a1, $sp, 0x10
    /* 2CD0 80066030 04005226 */  addiu      $s2, $s2, 0x4
    /* 2CD4 80066034 01003126 */  addiu      $s1, $s1, 0x1
  .L80066038:
    /* 2CD8 80066038 01001026 */  addiu      $s0, $s0, 0x1
    /* 2CDC 8006603C 0E00022A */  slti       $v0, $s0, 0xE
    /* 2CE0 80066040 D9FF4014 */  bnez       $v0, .L80065FA8
    /* 2CE4 80066044 09007326 */   addiu     $s3, $s3, 0x9
    /* 2CE8 80066048 0100B526 */  addiu      $s5, $s5, 0x1
    /* 2CEC 8006604C D2FFA01A */  blez       $s5, .L80065F98
    /* 2CF0 80066050 6E00F726 */   addiu     $s7, $s7, 0x6E
  .L80066054:
    /* 2CF4 80066054 6400BF8F */  lw         $ra, 0x64($sp)
    /* 2CF8 80066058 6000BE8F */  lw         $fp, 0x60($sp)
    /* 2CFC 8006605C 5C00B78F */  lw         $s7, 0x5C($sp)
    /* 2D00 80066060 5800B68F */  lw         $s6, 0x58($sp)
    /* 2D04 80066064 5400B58F */  lw         $s5, 0x54($sp)
    /* 2D08 80066068 5000B48F */  lw         $s4, 0x50($sp)
    /* 2D0C 8006606C 4C00B38F */  lw         $s3, 0x4C($sp)
    /* 2D10 80066070 4800B28F */  lw         $s2, 0x48($sp)
    /* 2D14 80066074 4400B18F */  lw         $s1, 0x44($sp)
    /* 2D18 80066078 4000B08F */  lw         $s0, 0x40($sp)
    /* 2D1C 8006607C 0800E003 */  jr         $ra
    /* 2D20 80066080 6800BD27 */   addiu     $sp, $sp, 0x68
endlabel func_80065E24
