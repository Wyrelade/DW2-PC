nonmatching Stg20_BeetleShopUpdate, 0x244

glabel Stg20_BeetleShopUpdate
    /* 2A14 80065D74 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2A18 80065D78 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2A1C 80065D7C 21888000 */  addu       $s1, $a0, $zero
    /* 2A20 80065D80 01000424 */  addiu      $a0, $zero, 0x1
    /* 2A24 80065D84 1800BFAF */  sw         $ra, 0x18($sp)
    /* 2A28 80065D88 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2A2C 80065D8C 1000238E */  lw         $v1, 0x10($s1)
    /* 2A30 80065D90 3400308E */  lw         $s0, 0x34($s1)
    /* 2A34 80065D94 17006410 */  beq        $v1, $a0, .L80065DF4
    /* 2A38 80065D98 02006228 */   slti      $v0, $v1, 0x2
    /* 2A3C 80065D9C 05004010 */  beqz       $v0, .L80065DB4
    /* 2A40 80065DA0 00000000 */   nop
    /* 2A44 80065DA4 08006010 */  beqz       $v1, .L80065DC8
    /* 2A48 80065DA8 0780023C */   lui       $v0, %hi(D_80070A00)
    /* 2A4C 80065DAC E9970108 */  j          .L80065FA4
    /* 2A50 80065DB0 00000000 */   nop
  .L80065DB4:
    /* 2A54 80065DB4 02000224 */  addiu      $v0, $zero, 0x2
    /* 2A58 80065DB8 62006210 */  beq        $v1, $v0, .L80065F44
    /* 2A5C 80065DBC 00000000 */   nop
    /* 2A60 80065DC0 E9970108 */  j          .L80065FA4
    /* 2A64 80065DC4 00000000 */   nop
  .L80065DC8:
    /* 2A68 80065DC8 000A40AC */  sw         $zero, %lo(D_80070A00)($v0)
    /* 2A6C 80065DCC 12030424 */  addiu      $a0, $zero, 0x312
    /* 2A70 80065DD0 21280002 */  addu       $a1, $s0, $zero
    /* 2A74 80065DD4 1F44000C */  jal        Task_Create
    /* 2A78 80065DD8 21300000 */   addu      $a2, $zero, $zero
    /* 2A7C 80065DDC 15030424 */  addiu      $a0, $zero, 0x315
    /* 2A80 80065DE0 04000526 */  addiu      $a1, $s0, 0x4
    /* 2A84 80065DE4 1F44000C */  jal        Task_Create
    /* 2A88 80065DE8 21300000 */   addu      $a2, $zero, $zero
    /* 2A8C 80065DEC A1970108 */  j          .L80065E84
    /* 2A90 80065DF0 00000000 */   nop
  .L80065DF4:
    /* 2A94 80065DF4 1400238E */  lw         $v1, 0x14($s1)
    /* 2A98 80065DF8 00000000 */  nop
    /* 2A9C 80065DFC 35006410 */  beq        $v1, $a0, .L80065ED4
    /* 2AA0 80065E00 02006228 */   slti      $v0, $v1, 0x2
    /* 2AA4 80065E04 03004014 */  bnez       $v0, .L80065E14
    /* 2AA8 80065E08 02000224 */   addiu     $v0, $zero, 0x2
    /* 2AAC 80065E0C 39006210 */  beq        $v1, $v0, .L80065EF4
    /* 2AB0 80065E10 00000000 */   nop
  .L80065E14:
    /* 2AB4 80065E14 1800228E */  lw         $v0, 0x18($s1)
    /* 2AB8 80065E18 00000000 */  nop
    /* 2ABC 80065E1C 03004010 */  beqz       $v0, .L80065E2C
    /* 2AC0 80065E20 00000000 */   nop
    /* 2AC4 80065E24 0E004410 */  beq        $v0, $a0, .L80065E60
    /* 2AC8 80065E28 00000000 */   nop
  .L80065E2C:
    /* 2ACC 80065E2C 0400028E */  lw         $v0, 0x4($s0)
    /* 2AD0 80065E30 00000000 */  nop
    /* 2AD4 80065E34 04004014 */  bnez       $v0, .L80065E48
    /* 2AD8 80065E38 04000526 */   addiu     $a1, $s0, 0x4
    /* 2ADC 80065E3C 15030424 */  addiu      $a0, $zero, 0x315
    /* 2AE0 80065E40 1F44000C */  jal        Task_Create
    /* 2AE4 80065E44 21300000 */   addu      $a2, $zero, $zero
  .L80065E48:
    /* 2AE8 80065E48 18030424 */  addiu      $a0, $zero, 0x318
    /* 2AEC 80065E4C 08000526 */  addiu      $a1, $s0, 0x8
    /* 2AF0 80065E50 1F44000C */  jal        Task_Create
    /* 2AF4 80065E54 21300000 */   addu      $a2, $zero, $zero
    /* 2AF8 80065E58 6045000C */  jal        Task_NextState2
    /* 2AFC 80065E5C 21202002 */   addu      $a0, $s1, $zero
  .L80065E60:
    /* 2B00 80065E60 0800028E */  lw         $v0, 0x8($s0)
    /* 2B04 80065E64 00000000 */  nop
    /* 2B08 80065E68 4E004014 */  bnez       $v0, .L80065FA4
    /* 2B0C 80065E6C 0780023C */   lui       $v0, %hi(Stg20_MenuState)
    /* 2B10 80065E70 B0094324 */  addiu      $v1, $v0, %lo(Stg20_MenuState)
    /* 2B14 80065E74 0800628C */  lw         $v0, 0x8($v1)
    /* 2B18 80065E78 00000000 */  nop
    /* 2B1C 80065E7C 05004010 */  beqz       $v0, .L80065E94
    /* 2B20 80065E80 00000000 */   nop
  .L80065E84:
    /* 2B24 80065E84 5145000C */  jal        Task_NextState0
    /* 2B28 80065E88 21202002 */   addu      $a0, $s1, $zero
    /* 2B2C 80065E8C E9970108 */  j          .L80065FA4
    /* 2B30 80065E90 00000000 */   nop
  .L80065E94:
    /* 2B34 80065E94 5000628C */  lw         $v0, 0x50($v1)
    /* 2B38 80065E98 00000000 */  nop
    /* 2B3C 80065E9C 09004014 */  bnez       $v0, .L80065EC4
    /* 2B40 80065EA0 21202002 */   addu      $a0, $s1, $zero
    /* 2B44 80065EA4 0400048E */  lw         $a0, 0x4($s0)
    /* 2B48 80065EA8 7045000C */  jal        Task_SetState0
    /* 2B4C 80065EAC 03000524 */   addiu     $a1, $zero, 0x3
    /* 2B50 80065EB0 21202002 */  addu       $a0, $s1, $zero
    /* 2B54 80065EB4 7745000C */  jal        Task_SetState1
    /* 2B58 80065EB8 01000524 */   addiu     $a1, $zero, 0x1
    /* 2B5C 80065EBC E9970108 */  j          .L80065FA4
    /* 2B60 80065EC0 00000000 */   nop
  .L80065EC4:
    /* 2B64 80065EC4 7745000C */  jal        Task_SetState1
    /* 2B68 80065EC8 02000524 */   addiu     $a1, $zero, 0x2
    /* 2B6C 80065ECC E9970108 */  j          .L80065FA4
    /* 2B70 80065ED0 00000000 */   nop
  .L80065ED4:
    /* 2B74 80065ED4 1800228E */  lw         $v0, 0x18($s1)
    /* 2B78 80065ED8 00000000 */  nop
    /* 2B7C 80065EDC 03004010 */  beqz       $v0, .L80065EEC
    /* 2B80 80065EE0 00000000 */   nop
    /* 2B84 80065EE4 0F004410 */  beq        $v0, $a0, .L80065F24
    /* 2B88 80065EE8 00000000 */   nop
  .L80065EEC:
    /* 2B8C 80065EEC C4970108 */  j          .L80065F10
    /* 2B90 80065EF0 1A030424 */   addiu     $a0, $zero, 0x31A
  .L80065EF4:
    /* 2B94 80065EF4 1800228E */  lw         $v0, 0x18($s1)
    /* 2B98 80065EF8 00000000 */  nop
    /* 2B9C 80065EFC 03004010 */  beqz       $v0, .L80065F0C
    /* 2BA0 80065F00 00000000 */   nop
    /* 2BA4 80065F04 07004410 */  beq        $v0, $a0, .L80065F24
    /* 2BA8 80065F08 00000000 */   nop
  .L80065F0C:
    /* 2BAC 80065F0C 1B030424 */  addiu      $a0, $zero, 0x31B
  .L80065F10:
    /* 2BB0 80065F10 08000526 */  addiu      $a1, $s0, 0x8
    /* 2BB4 80065F14 1F44000C */  jal        Task_Create
    /* 2BB8 80065F18 21300000 */   addu      $a2, $zero, $zero
    /* 2BBC 80065F1C 6045000C */  jal        Task_NextState2
    /* 2BC0 80065F20 21202002 */   addu      $a0, $s1, $zero
  .L80065F24:
    /* 2BC4 80065F24 0800028E */  lw         $v0, 0x8($s0)
    /* 2BC8 80065F28 00000000 */  nop
    /* 2BCC 80065F2C 1D004014 */  bnez       $v0, .L80065FA4
    /* 2BD0 80065F30 21202002 */   addu      $a0, $s1, $zero
    /* 2BD4 80065F34 7745000C */  jal        Task_SetState1
    /* 2BD8 80065F38 21280000 */   addu      $a1, $zero, $zero
    /* 2BDC 80065F3C E9970108 */  j          .L80065FA4
    /* 2BE0 80065F40 00000000 */   nop
  .L80065F44:
    /* 2BE4 80065F44 1400228E */  lw         $v0, 0x14($s1)
    /* 2BE8 80065F48 00000000 */  nop
    /* 2BEC 80065F4C 03004010 */  beqz       $v0, .L80065F5C
    /* 2BF0 80065F50 00000000 */   nop
    /* 2BF4 80065F54 07004410 */  beq        $v0, $a0, .L80065F74
    /* 2BF8 80065F58 00000000 */   nop
  .L80065F5C:
    /* 2BFC 80065F5C 4797010C */  jal        Stg20_RefillBeetleHpEp
    /* 2C00 80065F60 00000000 */   nop
    /* 2C04 80065F64 3C71000C */  jal        Gfx_FadeOutToBlack
    /* 2C08 80065F68 0A000424 */   addiu     $a0, $zero, 0xA
    /* 2C0C 80065F6C 5945000C */  jal        Task_NextState1
    /* 2C10 80065F70 21202002 */   addu      $a0, $s1, $zero
  .L80065F74:
    /* 2C14 80065F74 1800228E */  lw         $v0, 0x18($s1)
    /* 2C18 80065F78 00000000 */  nop
    /* 2C1C 80065F7C 01004224 */  addiu      $v0, $v0, 0x1
    /* 2C20 80065F80 180022AE */  sw         $v0, 0x18($s1)
    /* 2C24 80065F84 19004228 */  slti       $v0, $v0, 0x19
    /* 2C28 80065F88 06004014 */  bnez       $v0, .L80065FA4
    /* 2C2C 80065F8C 0680023C */   lui       $v0, %hi(Sys_State)
    /* 2C30 80065F90 70F74224 */  addiu      $v0, $v0, %lo(Sys_State)
    /* 2C34 80065F94 2000448C */  lw         $a0, 0x20($v0)
    /* 2C38 80065F98 07000324 */  addiu      $v1, $zero, 0x7
    /* 2C3C 80065F9C 240043AC */  sw         $v1, 0x24($v0)
    /* 2C40 80065FA0 1C0044AC */  sw         $a0, 0x1C($v0)
  .L80065FA4:
    /* 2C44 80065FA4 1800BF8F */  lw         $ra, 0x18($sp)
    /* 2C48 80065FA8 1400B18F */  lw         $s1, 0x14($sp)
    /* 2C4C 80065FAC 1000B08F */  lw         $s0, 0x10($sp)
    /* 2C50 80065FB0 0800E003 */  jr         $ra
    /* 2C54 80065FB4 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg20_BeetleShopUpdate
