nonmatching Stg00_XaPlayTask, 0x234

glabel Stg00_XaPlayTask
    /* 4ABC 80067E1C B0FFBD27 */  addiu      $sp, $sp, -0x50
    /* 4AC0 80067E20 4000B2AF */  sw         $s2, 0x40($sp)
    /* 4AC4 80067E24 21908000 */  addu       $s2, $a0, $zero
    /* 4AC8 80067E28 4400B3AF */  sw         $s3, 0x44($sp)
    /* 4ACC 80067E2C 01001324 */  addiu      $s3, $zero, 0x1
    /* 4AD0 80067E30 4800BFAF */  sw         $ra, 0x48($sp)
    /* 4AD4 80067E34 3C00B1AF */  sw         $s1, 0x3C($sp)
    /* 4AD8 80067E38 3800B0AF */  sw         $s0, 0x38($sp)
    /* 4ADC 80067E3C 1000508E */  lw         $s0, 0x10($s2)
    /* 4AE0 80067E40 2C00518E */  lw         $s1, 0x2C($s2)
    /* 4AE4 80067E44 7B001312 */  beq        $s0, $s3, .L80068034
    /* 4AE8 80067E48 0200022A */   slti      $v0, $s0, 0x2
    /* 4AEC 80067E4C 03004014 */  bnez       $v0, .L80067E5C
    /* 4AF0 80067E50 02000224 */   addiu     $v0, $zero, 0x2
    /* 4AF4 80067E54 42000212 */  beq        $s0, $v0, .L80067F60
    /* 4AF8 80067E58 00000000 */   nop
  .L80067E5C:
    /* 4AFC 80067E5C 1400428E */  lw         $v0, 0x14($s2)
    /* 4B00 80067E60 00000000 */  nop
    /* 4B04 80067E64 03004010 */  beqz       $v0, .L80067E74
    /* 4B08 80067E68 00000000 */   nop
    /* 4B0C 80067E6C 2C005310 */  beq        $v0, $s3, .L80067F20
    /* 4B10 80067E70 01000424 */   addiu     $a0, $zero, 0x1
  .L80067E74:
    /* 4B14 80067E74 0000248E */  lw         $a0, 0x0($s1)
    /* 4B18 80067E78 EB8F000C */  jal        Cd_GetFileLba
    /* 4B1C 80067E7C 00000000 */   nop
    /* 4B20 80067E80 0780043C */  lui        $a0, %hi(Stg00_XaTrackStart)
    /* 4B24 80067E84 A08F8424 */  addiu      $a0, $a0, %lo(Stg00_XaTrackStart)
    /* 4B28 80067E88 0800238E */  lw         $v1, 0x8($s1)
    /* 4B2C 80067E8C 0780053C */  lui        $a1, %hi(Stg00_XaTrackLength)
    /* 4B30 80067E90 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 4B34 80067E94 80180300 */  sll        $v1, $v1, 2
    /* 4B38 80067E98 21186400 */  addu       $v1, $v1, $a0
    /* 4B3C 80067E9C 0000638C */  lw         $v1, 0x0($v1)
    /* 4B40 80067EA0 B88FA524 */  addiu      $a1, $a1, %lo(Stg00_XaTrackLength)
    /* 4B44 80067EA4 21104300 */  addu       $v0, $v0, $v1
    /* 4B48 80067EA8 0800238E */  lw         $v1, 0x8($s1)
    /* 4B4C 80067EAC 21300000 */  addu       $a2, $zero, $zero
    /* 4B50 80067EB0 0C0022AE */  sw         $v0, 0xC($s1)
    /* 4B54 80067EB4 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 4B58 80067EB8 80180300 */  sll        $v1, $v1, 2
    /* 4B5C 80067EBC 21186500 */  addu       $v1, $v1, $a1
    /* 4B60 80067EC0 0000638C */  lw         $v1, 0x0($v1)
    /* 4B64 80067EC4 0D000424 */  addiu      $a0, $zero, 0xD
    /* 4B68 80067EC8 21104300 */  addu       $v0, $v0, $v1
    /* 4B6C 80067ECC 100022AE */  sw         $v0, 0x10($s1)
    /* 4B70 80067ED0 1000B3A3 */  sb         $s3, 0x10($sp)
    /* 4B74 80067ED4 04002292 */  lbu        $v0, 0x4($s1)
    /* 4B78 80067ED8 1000A527 */  addiu      $a1, $sp, 0x10
    /* 4B7C 80067EDC 55C1000C */  jal        CdControl
    /* 4B80 80067EE0 1100A2A3 */   sb        $v0, 0x11($sp)
    /* 4B84 80067EE4 0E000424 */  addiu      $a0, $zero, 0xE
    /* 4B88 80067EE8 1800A527 */  addiu      $a1, $sp, 0x18
    /* 4B8C 80067EEC 21300000 */  addu       $a2, $zero, $zero
    /* 4B90 80067EF0 C8000224 */  addiu      $v0, $zero, 0xC8
    /* 4B94 80067EF4 F1C1000C */  jal        CdControlB
    /* 4B98 80067EF8 1800A2A3 */   sb        $v0, 0x18($sp)
    /* 4B9C 80067EFC 2000B027 */  addiu      $s0, $sp, 0x20
    /* 4BA0 80067F00 0C00248E */  lw         $a0, 0xC($s1)
    /* 4BA4 80067F04 E5C0000C */  jal        CdIntToPos
    /* 4BA8 80067F08 21280002 */   addu      $a1, $s0, $zero
    /* 4BAC 80067F0C 15000424 */  addiu      $a0, $zero, 0x15
    /* 4BB0 80067F10 A4C1000C */  jal        CdControlF
    /* 4BB4 80067F14 21280002 */   addu      $a1, $s0, $zero
    /* 4BB8 80067F18 E89F0108 */  j          .L80067FA0
    /* 4BBC 80067F1C 00000000 */   nop
  .L80067F20:
    /* 4BC0 80067F20 35C1000C */  jal        CdSync
    /* 4BC4 80067F24 2800A527 */   addiu     $a1, $sp, 0x28
    /* 4BC8 80067F28 21184000 */  addu       $v1, $v0, $zero
    /* 4BCC 80067F2C 02000224 */  addiu      $v0, $zero, 0x2
    /* 4BD0 80067F30 07006210 */  beq        $v1, $v0, .L80067F50
    /* 4BD4 80067F34 05000224 */   addiu     $v0, $zero, 0x5
    /* 4BD8 80067F38 3E006214 */  bne        $v1, $v0, .L80068034
    /* 4BDC 80067F3C 21204002 */   addu      $a0, $s2, $zero
    /* 4BE0 80067F40 7045000C */  jal        Task_SetState0
    /* 4BE4 80067F44 21280000 */   addu      $a1, $zero, $zero
    /* 4BE8 80067F48 0DA00108 */  j          .L80068034
    /* 4BEC 80067F4C 00000000 */   nop
  .L80067F50:
    /* 4BF0 80067F50 5145000C */  jal        Task_NextState0
    /* 4BF4 80067F54 21204002 */   addu      $a0, $s2, $zero
    /* 4BF8 80067F58 0DA00108 */  j          .L80068034
    /* 4BFC 80067F5C 00000000 */   nop
  .L80067F60:
    /* 4C00 80067F60 1400428E */  lw         $v0, 0x14($s2)
    /* 4C04 80067F64 00000000 */  nop
    /* 4C08 80067F68 03004010 */  beqz       $v0, .L80067F78
    /* 4C0C 80067F6C 00000000 */   nop
    /* 4C10 80067F70 0F005310 */  beq        $v0, $s3, .L80067FB0
    /* 4C14 80067F74 00000000 */   nop
  .L80067F78:
    /* 4C18 80067F78 0C00248E */  lw         $a0, 0xC($s1)
    /* 4C1C 80067F7C 2800B027 */  addiu      $s0, $sp, 0x28
    /* 4C20 80067F80 E5C0000C */  jal        CdIntToPos
    /* 4C24 80067F84 21280002 */   addu      $a1, $s0, $zero
    /* 4C28 80067F88 1B000424 */  addiu      $a0, $zero, 0x1B
    /* 4C2C 80067F8C 21280002 */  addu       $a1, $s0, $zero
    /* 4C30 80067F90 55C1000C */  jal        CdControl
    /* 4C34 80067F94 21300000 */   addu      $a2, $zero, $zero
    /* 4C38 80067F98 26005314 */  bne        $v0, $s3, .L80068034
    /* 4C3C 80067F9C 00000000 */   nop
  .L80067FA0:
    /* 4C40 80067FA0 5945000C */  jal        Task_NextState1
    /* 4C44 80067FA4 21204002 */   addu      $a0, $s2, $zero
    /* 4C48 80067FA8 0DA00108 */  j          .L80068034
    /* 4C4C 80067FAC 00000000 */   nop
  .L80067FB0:
    /* 4C50 80067FB0 2400428E */  lw         $v0, 0x24($s2)
    /* 4C54 80067FB4 00000000 */  nop
    /* 4C58 80067FB8 1F004230 */  andi       $v0, $v0, 0x1F
    /* 4C5C 80067FBC 1D004014 */  bnez       $v0, .L80068034
    /* 4C60 80067FC0 01000424 */   addiu     $a0, $zero, 0x1
    /* 4C64 80067FC4 35C1000C */  jal        CdSync
    /* 4C68 80067FC8 3000A527 */   addiu     $a1, $sp, 0x30
    /* 4C6C 80067FCC 21184000 */  addu       $v1, $v0, $zero
    /* 4C70 80067FD0 05007010 */  beq        $v1, $s0, .L80067FE8
    /* 4C74 80067FD4 05000224 */   addiu     $v0, $zero, 0x5
    /* 4C78 80067FD8 16006214 */  bne        $v1, $v0, .L80068034
    /* 4C7C 80067FDC 21204002 */   addu      $a0, $s2, $zero
    /* 4C80 80067FE0 07A00108 */  j          .L8006801C
    /* 4C84 80067FE4 00000000 */   nop
  .L80067FE8:
    /* 4C88 80067FE8 29C1000C */  jal        CdLastCom
    /* 4C8C 80067FEC 00000000 */   nop
    /* 4C90 80067FF0 11000324 */  addiu      $v1, $zero, 0x11
    /* 4C94 80067FF4 0D004314 */  bne        $v0, $v1, .L8006802C
    /* 4C98 80067FF8 11000424 */   addiu     $a0, $zero, 0x11
    /* 4C9C 80067FFC 59B7000C */  jal        CdPosToInt
    /* 4CA0 80068000 3500A427 */   addiu     $a0, $sp, 0x35
    /* 4CA4 80068004 1000238E */  lw         $v1, 0x10($s1)
    /* 4CA8 80068008 00000000 */  nop
    /* 4CAC 8006800C 2A104300 */  slt        $v0, $v0, $v1
    /* 4CB0 80068010 06004014 */  bnez       $v0, .L8006802C
    /* 4CB4 80068014 11000424 */   addiu     $a0, $zero, 0x11
    /* 4CB8 80068018 21204002 */  addu       $a0, $s2, $zero
  .L8006801C:
    /* 4CBC 8006801C 7045000C */  jal        Task_SetState0
    /* 4CC0 80068020 03000524 */   addiu     $a1, $zero, 0x3
    /* 4CC4 80068024 0DA00108 */  j          .L80068034
    /* 4CC8 80068028 00000000 */   nop
  .L8006802C:
    /* 4CCC 8006802C A4C1000C */  jal        CdControlF
    /* 4CD0 80068030 21280000 */   addu      $a1, $zero, $zero
  .L80068034:
    /* 4CD4 80068034 4800BF8F */  lw         $ra, 0x48($sp)
    /* 4CD8 80068038 4400B38F */  lw         $s3, 0x44($sp)
    /* 4CDC 8006803C 4000B28F */  lw         $s2, 0x40($sp)
    /* 4CE0 80068040 3C00B18F */  lw         $s1, 0x3C($sp)
    /* 4CE4 80068044 3800B08F */  lw         $s0, 0x38($sp)
    /* 4CE8 80068048 0800E003 */  jr         $ra
    /* 4CEC 8006804C 5000BD27 */   addiu     $sp, $sp, 0x50
endlabel Stg00_XaPlayTask
