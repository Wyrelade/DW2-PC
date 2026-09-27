nonmatching func_80066E1C, 0x1CC

glabel func_80066E1C
    /* 3ABC 80066E1C 78FFBD27 */  addiu      $sp, $sp, -0x88
    /* 3AC0 80066E20 7C00B5AF */  sw         $s5, 0x7C($sp)
    /* 3AC4 80066E24 21A88000 */  addu       $s5, $a0, $zero
    /* 3AC8 80066E28 6C00B1AF */  sw         $s1, 0x6C($sp)
    /* 3ACC 80066E2C 2188A000 */  addu       $s1, $a1, $zero
    /* 3AD0 80066E30 21280000 */  addu       $a1, $zero, $zero
    /* 3AD4 80066E34 3000A627 */  addiu      $a2, $sp, 0x30
    /* 3AD8 80066E38 7000B2AF */  sw         $s2, 0x70($sp)
    /* 3ADC 80066E3C 2190A000 */  addu       $s2, $a1, $zero
    /* 3AE0 80066E40 8000BFAF */  sw         $ra, 0x80($sp)
    /* 3AE4 80066E44 7800B4AF */  sw         $s4, 0x78($sp)
    /* 3AE8 80066E48 7400B3AF */  sw         $s3, 0x74($sp)
    /* 3AEC 80066E4C 6800B0AF */  sw         $s0, 0x68($sp)
    /* 3AF0 80066E50 2C00B38E */  lw         $s3, 0x2C($s5)
    /* 3AF4 80066E54 00000000 */  nop
    /* 3AF8 80066E58 2C00648E */  lw         $a0, 0x2C($s3)
    /* 3AFC 80066E5C 3400B48E */  lw         $s4, 0x34($s5)
    /* 3B00 80066E60 A97B000C */  jal        func_8001EEA4
    /* 3B04 80066E64 3800A727 */   addiu     $a3, $sp, 0x38
    /* 3B08 80066E68 4000B027 */  addiu      $s0, $sp, 0x40
    /* 3B0C 80066E6C 0C00A48E */  lw         $a0, 0xC($s5)
    /* 3B10 80066E70 F979000C */  jal        func_8001E7E4
    /* 3B14 80066E74 21280002 */   addu      $a1, $s0, $zero
    /* 3B18 80066E78 40101100 */  sll        $v0, $s1, 1
    /* 3B1C 80066E7C 21105100 */  addu       $v0, $v0, $s1
    /* 3B20 80066E80 40100200 */  sll        $v0, $v0, 1
    /* 3B24 80066E84 21800202 */  addu       $s0, $s0, $v0
    /* 3B28 80066E88 40181200 */  sll        $v1, $s2, 1
  .L80066E8C:
    /* 3B2C 80066E8C 2110A303 */  addu       $v0, $sp, $v1
    /* 3B30 80066E90 30004284 */  lh         $v0, 0x30($v0)
    /* 3B34 80066E94 00000000 */  nop
    /* 3B38 80066E98 3E004010 */  beqz       $v0, .L80066F94
    /* 3B3C 80066E9C 00000000 */   nop
    /* 3B40 80066EA0 1000A2AF */  sw         $v0, 0x10($sp)
    /* 3B44 80066EA4 2110A303 */  addu       $v0, $sp, $v1
    /* 3B48 80066EA8 38004284 */  lh         $v0, 0x38($v0)
    /* 3B4C 80066EAC 00000000 */  nop
    /* 3B50 80066EB0 1400A2AF */  sw         $v0, 0x14($sp)
    /* 3B54 80066EB4 1000668E */  lw         $a2, 0x10($s3)
    /* 3B58 80066EB8 00000000 */  nop
    /* 3B5C 80066EBC 2400A6AF */  sw         $a2, 0x24($sp)
    /* 3B60 80066EC0 0400638E */  lw         $v1, 0x4($s3)
    /* 3B64 80066EC4 00000000 */  nop
    /* 3B68 80066EC8 1800A3AF */  sw         $v1, 0x18($sp)
    /* 3B6C 80066ECC 0800648E */  lw         $a0, 0x8($s3)
    /* 3B70 80066ED0 00000000 */  nop
    /* 3B74 80066ED4 1C00A4AF */  sw         $a0, 0x1C($sp)
    /* 3B78 80066ED8 0C00658E */  lw         $a1, 0xC($s3)
    /* 3B7C 80066EDC 78000224 */  addiu      $v0, $zero, 0x78
    /* 3B80 80066EE0 2800A2AF */  sw         $v0, 0x28($sp)
    /* 3B84 80066EE4 01000224 */  addiu      $v0, $zero, 0x1
    /* 3B88 80066EE8 0F004212 */  beq        $s2, $v0, .L80066F28
    /* 3B8C 80066EEC 2000A5AF */   sw        $a1, 0x20($sp)
    /* 3B90 80066EF0 0200422A */  slti       $v0, $s2, 0x2
    /* 3B94 80066EF4 22004010 */  beqz       $v0, .L80066F80
    /* 3B98 80066EF8 07000424 */   addiu     $a0, $zero, 0x7
    /* 3B9C 80066EFC 21004016 */  bnez       $s2, .L80066F84
    /* 3BA0 80066F00 80281200 */   sll       $a1, $s2, 2
    /* 3BA4 80066F04 0C00A48E */  lw         $a0, 0xC($s5)
    /* 3BA8 80066F08 E779000C */  jal        func_8001E79C
    /* 3BAC 80066F0C 00000000 */   nop
    /* 3BB0 80066F10 1C00A38F */  lw         $v1, 0x1C($sp)
    /* 3BB4 80066F14 00000000 */  nop
    /* 3BB8 80066F18 80FD6324 */  addiu      $v1, $v1, -0x280
    /* 3BBC 80066F1C 23186200 */  subu       $v1, $v1, $v0
    /* 3BC0 80066F20 DF9B0108 */  j          .L80066F7C
    /* 3BC4 80066F24 1C00A3AF */   sw        $v1, 0x1C($sp)
  .L80066F28:
    /* 3BC8 80066F28 02000286 */  lh         $v0, 0x2($s0)
    /* 3BCC 80066F2C 00000000 */  nop
    /* 3BD0 80066F30 23108200 */  subu       $v0, $a0, $v0
    /* 3BD4 80066F34 0900C014 */  bnez       $a2, .L80066F5C
    /* 3BD8 80066F38 1C00A2AF */   sw        $v0, 0x1C($sp)
    /* 3BDC 80066F3C 00000286 */  lh         $v0, 0x0($s0)
    /* 3BE0 80066F40 00000000 */  nop
    /* 3BE4 80066F44 21106200 */  addu       $v0, $v1, $v0
    /* 3BE8 80066F48 1800A2AF */  sw         $v0, 0x18($sp)
    /* 3BEC 80066F4C 04000386 */  lh         $v1, 0x4($s0)
    /* 3BF0 80066F50 00FFA224 */  addiu      $v0, $a1, -0x100
    /* 3BF4 80066F54 DE9B0108 */  j          .L80066F78
    /* 3BF8 80066F58 23104300 */   subu      $v0, $v0, $v1
  .L80066F5C:
    /* 3BFC 80066F5C 00000286 */  lh         $v0, 0x0($s0)
    /* 3C00 80066F60 00000000 */  nop
    /* 3C04 80066F64 23106200 */  subu       $v0, $v1, $v0
    /* 3C08 80066F68 1800A2AF */  sw         $v0, 0x18($sp)
    /* 3C0C 80066F6C 04000386 */  lh         $v1, 0x4($s0)
    /* 3C10 80066F70 0001A224 */  addiu      $v0, $a1, 0x100
    /* 3C14 80066F74 21104300 */  addu       $v0, $v0, $v1
  .L80066F78:
    /* 3C18 80066F78 2000A2AF */  sw         $v0, 0x20($sp)
  .L80066F7C:
    /* 3C1C 80066F7C 07000424 */  addiu      $a0, $zero, 0x7
  .L80066F80:
    /* 3C20 80066F80 80281200 */  sll        $a1, $s2, 2
  .L80066F84:
    /* 3C24 80066F84 0400A524 */  addiu      $a1, $a1, 0x4
    /* 3C28 80066F88 21288502 */  addu       $a1, $s4, $a1
    /* 3C2C 80066F8C 1F44000C */  jal        Task_Create
    /* 3C30 80066F90 1000A627 */   addiu     $a2, $sp, 0x10
  .L80066F94:
    /* 3C34 80066F94 01005226 */  addiu      $s2, $s2, 0x1
    /* 3C38 80066F98 0300422A */  slti       $v0, $s2, 0x3
    /* 3C3C 80066F9C BBFF4014 */  bnez       $v0, .L80066E8C
    /* 3C40 80066FA0 40181200 */   sll       $v1, $s2, 1
    /* 3C44 80066FA4 0B010424 */  addiu      $a0, $zero, 0x10B
    /* 3C48 80066FA8 10008526 */  addiu      $a1, $s4, 0x10
    /* 3C4C 80066FAC 2C00628E */  lw         $v0, 0x2C($s3)
    /* 3C50 80066FB0 5800A627 */  addiu      $a2, $sp, 0x58
    /* 3C54 80066FB4 5800A0AF */  sw         $zero, 0x58($sp)
    /* 3C58 80066FB8 6000A0AF */  sw         $zero, 0x60($sp)
    /* 3C5C 80066FBC 1F44000C */  jal        Task_Create
    /* 3C60 80066FC0 5C00A2AF */   sw        $v0, 0x5C($sp)
    /* 3C64 80066FC4 8000BF8F */  lw         $ra, 0x80($sp)
    /* 3C68 80066FC8 7C00B58F */  lw         $s5, 0x7C($sp)
    /* 3C6C 80066FCC 7800B48F */  lw         $s4, 0x78($sp)
    /* 3C70 80066FD0 7400B38F */  lw         $s3, 0x74($sp)
    /* 3C74 80066FD4 7000B28F */  lw         $s2, 0x70($sp)
    /* 3C78 80066FD8 6C00B18F */  lw         $s1, 0x6C($sp)
    /* 3C7C 80066FDC 6800B08F */  lw         $s0, 0x68($sp)
    /* 3C80 80066FE0 0800E003 */  jr         $ra
    /* 3C84 80066FE4 8800BD27 */   addiu     $sp, $sp, 0x88
endlabel func_80066E1C
