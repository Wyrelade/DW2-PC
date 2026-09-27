nonmatching func_80066E48, 0x1FC

glabel func_80066E48
    /* 3AE8 80066E48 A8FFBD27 */  addiu      $sp, $sp, -0x58
    /* 3AEC 80066E4C 4C00B3AF */  sw         $s3, 0x4C($sp)
    /* 3AF0 80066E50 21988000 */  addu       $s3, $a0, $zero
    /* 3AF4 80066E54 5000BFAF */  sw         $ra, 0x50($sp)
    /* 3AF8 80066E58 4800B2AF */  sw         $s2, 0x48($sp)
    /* 3AFC 80066E5C 4400B1AF */  sw         $s1, 0x44($sp)
    /* 3B00 80066E60 4000B0AF */  sw         $s0, 0x40($sp)
    /* 3B04 80066E64 2C00728E */  lw         $s2, 0x2C($s3)
    /* 3B08 80066E68 00000000 */  nop
    /* 3B0C 80066E6C 2000428E */  lw         $v0, 0x20($s2)
    /* 3B10 80066E70 00000000 */  nop
    /* 3B14 80066E74 02004010 */  beqz       $v0, .L80066E80
    /* 3B18 80066E78 06000524 */   addiu     $a1, $zero, 0x6
    /* 3B1C 80066E7C 07000524 */  addiu      $a1, $zero, 0x7
  .L80066E80:
    /* 3B20 80066E80 1000638E */  lw         $v1, 0x10($s3)
    /* 3B24 80066E84 01000424 */  addiu      $a0, $zero, 0x1
    /* 3B28 80066E88 0E006410 */  beq        $v1, $a0, .L80066EC4
    /* 3B2C 80066E8C 02006228 */   slti      $v0, $v1, 0x2
    /* 3B30 80066E90 03004014 */  bnez       $v0, .L80066EA0
    /* 3B34 80066E94 02000224 */   addiu     $v0, $zero, 0x2
    /* 3B38 80066E98 51006210 */  beq        $v1, $v0, .L80066FE0
    /* 3B3C 80066E9C 00000000 */   nop
  .L80066EA0:
    /* 3B40 80066EA0 2270000C */  jal        Mem_FillWordsNeg1
    /* 3B44 80066EA4 21204002 */   addu      $a0, $s2, $zero
    /* 3B48 80066EA8 21206002 */  addu       $a0, $s3, $zero
    /* 3B4C 80066EAC 0780023C */  lui        $v0, %hi(D_80072B70)
    /* 3B50 80066EB0 1C0040AE */  sw         $zero, 0x1C($s2)
    /* 3B54 80066EB4 5145000C */  jal        Task_NextState0
    /* 3B58 80066EB8 702B44AC */   sw        $a0, %lo(D_80072B70)($v0)
    /* 3B5C 80066EBC 0A9C0108 */  j          .L80067028
    /* 3B60 80066EC0 00000000 */   nop
  .L80066EC4:
    /* 3B64 80066EC4 1400628E */  lw         $v0, 0x14($s3)
    /* 3B68 80066EC8 00000000 */  nop
    /* 3B6C 80066ECC 03004010 */  beqz       $v0, .L80066EDC
    /* 3B70 80066ED0 00000000 */   nop
    /* 3B74 80066ED4 3A004410 */  beq        $v0, $a0, .L80066FC0
    /* 3B78 80066ED8 00000000 */   nop
  .L80066EDC:
    /* 3B7C 80066EDC 21206002 */  addu       $a0, $s3, $zero
    /* 3B80 80066EE0 B94D000C */  jal        Math_RampToOne
    /* 3B84 80066EE4 1C004526 */   addiu     $a1, $s2, 0x1C
    /* 3B88 80066EE8 4F004014 */  bnez       $v0, .L80067028
    /* 3B8C 80066EEC 1B000224 */   addiu     $v0, $zero, 0x1B
    /* 3B90 80066EF0 1800A2A7 */  sh         $v0, 0x18($sp)
    /* 3B94 80066EF4 33000224 */  addiu      $v0, $zero, 0x33
    /* 3B98 80066EF8 1A00A2A7 */  sh         $v0, 0x1A($sp)
    /* 3B9C 80066EFC 0C000224 */  addiu      $v0, $zero, 0xC
    /* 3BA0 80066F00 1000A0AF */  sw         $zero, 0x10($sp)
    /* 3BA4 80066F04 1400A0AF */  sw         $zero, 0x14($sp)
    /* 3BA8 80066F08 1C00A0AF */  sw         $zero, 0x1C($sp)
    /* 3BAC 80066F0C 2000A2AF */  sw         $v0, 0x20($sp)
    /* 3BB0 80066F10 2800A0AF */  sw         $zero, 0x28($sp)
    /* 3BB4 80066F14 44004292 */  lbu        $v0, 0x44($s2)
    /* 3BB8 80066F18 00000000 */  nop
    /* 3BBC 80066F1C 13004010 */  beqz       $v0, .L80066F6C
    /* 3BC0 80066F20 21880000 */   addu      $s1, $zero, $zero
    /* 3BC4 80066F24 21804002 */  addu       $s0, $s2, $zero
  .L80066F28:
    /* 3BC8 80066F28 21200002 */  addu       $a0, $s0, $zero
    /* 3BCC 80066F2C 2800028E */  lw         $v0, 0x28($s0)
    /* 3BD0 80066F30 1000A527 */  addiu      $a1, $sp, 0x10
    /* 3BD4 80066F34 096F000C */  jal        Text_Open
    /* 3BD8 80066F38 2400A2AF */   sw        $v0, 0x24($sp)
    /* 3BDC 80066F3C 0000048E */  lw         $a0, 0x0($s0)
    /* 3BE0 80066F40 D66F000C */  jal        Text_SetOtLayer
    /* 3BE4 80066F44 02000524 */   addiu     $a1, $zero, 0x2
    /* 3BE8 80066F48 1A00A297 */  lhu        $v0, 0x1A($sp)
    /* 3BEC 80066F4C 01003126 */  addiu      $s1, $s1, 0x1
    /* 3BF0 80066F50 0C004224 */  addiu      $v0, $v0, 0xC
    /* 3BF4 80066F54 1A00A2A7 */  sh         $v0, 0x1A($sp)
    /* 3BF8 80066F58 44004292 */  lbu        $v0, 0x44($s2)
    /* 3BFC 80066F5C 00000000 */  nop
    /* 3C00 80066F60 2A102202 */  slt        $v0, $s1, $v0
    /* 3C04 80066F64 F0FF4014 */  bnez       $v0, .L80066F28
    /* 3C08 80066F68 04001026 */   addiu     $s0, $s0, 0x4
  .L80066F6C:
    /* 3C0C 80066F6C 2000428E */  lw         $v0, 0x20($s2)
    /* 3C10 80066F70 00000000 */  nop
    /* 3C14 80066F74 10004010 */  beqz       $v0, .L80066FB8
    /* 3C18 80066F78 18004426 */   addiu     $a0, $s2, 0x18
    /* 3C1C 80066F7C 1000A527 */  addiu      $a1, $sp, 0x10
    /* 3C20 80066F80 01000224 */  addiu      $v0, $zero, 0x1
    /* 3C24 80066F84 1000A2AF */  sw         $v0, 0x10($sp)
    /* 3C28 80066F88 4000438E */  lw         $v1, 0x40($s2)
    /* 3C2C 80066F8C 10000224 */  addiu      $v0, $zero, 0x10
    /* 3C30 80066F90 1800A2A7 */  sh         $v0, 0x18($sp)
    /* 3C34 80066F94 8A000224 */  addiu      $v0, $zero, 0x8A
    /* 3C38 80066F98 1A00A2A7 */  sh         $v0, 0x1A($sp)
    /* 3C3C 80066F9C 1C00A0AF */  sw         $zero, 0x1C($sp)
    /* 3C40 80066FA0 2000A0AF */  sw         $zero, 0x20($sp)
    /* 3C44 80066FA4 096F000C */  jal        Text_Open
    /* 3C48 80066FA8 2400A3AF */   sw        $v1, 0x24($sp)
    /* 3C4C 80066FAC 1800448E */  lw         $a0, 0x18($s2)
    /* 3C50 80066FB0 D66F000C */  jal        Text_SetOtLayer
    /* 3C54 80066FB4 02000524 */   addiu     $a1, $zero, 0x2
  .L80066FB8:
    /* 3C58 80066FB8 009C0108 */  j          .L80067000
    /* 3C5C 80066FBC 240040AE */   sw        $zero, 0x24($s2)
  .L80066FC0:
    /* 3C60 80066FC0 2400428E */  lw         $v0, 0x24($s2)
    /* 3C64 80066FC4 00000000 */  nop
    /* 3C68 80066FC8 17004010 */  beqz       $v0, .L80067028
    /* 3C6C 80066FCC 21206002 */   addu      $a0, $s3, $zero
    /* 3C70 80066FD0 7745000C */  jal        Task_SetState1
    /* 3C74 80066FD4 21280000 */   addu      $a1, $zero, $zero
    /* 3C78 80066FD8 0A9C0108 */  j          .L80067028
    /* 3C7C 80066FDC 00000000 */   nop
  .L80066FE0:
    /* 3C80 80066FE0 1400628E */  lw         $v0, 0x14($s3)
    /* 3C84 80066FE4 00000000 */  nop
    /* 3C88 80066FE8 03004010 */  beqz       $v0, .L80066FF8
    /* 3C8C 80066FEC 00000000 */   nop
    /* 3C90 80066FF0 07004410 */  beq        $v0, $a0, .L80067010
    /* 3C94 80066FF4 21206002 */   addu      $a0, $s3, $zero
  .L80066FF8:
    /* 3C98 80066FF8 2C70000C */  jal        Text_CloseArray
    /* 3C9C 80066FFC 21204002 */   addu      $a0, $s2, $zero
  .L80067000:
    /* 3CA0 80067000 5945000C */  jal        Task_NextState1
    /* 3CA4 80067004 21206002 */   addu      $a0, $s3, $zero
    /* 3CA8 80067008 0A9C0108 */  j          .L80067028
    /* 3CAC 8006700C 00000000 */   nop
  .L80067010:
    /* 3CB0 80067010 C54D000C */  jal        Math_RampToZero
    /* 3CB4 80067014 1C004526 */   addiu     $a1, $s2, 0x1C
    /* 3CB8 80067018 03004014 */  bnez       $v0, .L80067028
    /* 3CBC 8006701C 21206002 */   addu      $a0, $s3, $zero
    /* 3CC0 80067020 7045000C */  jal        Task_SetState0
    /* 3CC4 80067024 03000524 */   addiu     $a1, $zero, 0x3
  .L80067028:
    /* 3CC8 80067028 5000BF8F */  lw         $ra, 0x50($sp)
    /* 3CCC 8006702C 4C00B38F */  lw         $s3, 0x4C($sp)
    /* 3CD0 80067030 4800B28F */  lw         $s2, 0x48($sp)
    /* 3CD4 80067034 4400B18F */  lw         $s1, 0x44($sp)
    /* 3CD8 80067038 4000B08F */  lw         $s0, 0x40($sp)
    /* 3CDC 8006703C 0800E003 */  jr         $ra
    /* 3CE0 80067040 5800BD27 */   addiu     $sp, $sp, 0x58
endlabel func_80066E48
