nonmatching Stg11_CardRunOp, 0xEC

glabel Stg11_CardRunOp
    /* 4C04 80067F64 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 4C08 80067F68 1800B2AF */  sw         $s2, 0x18($sp)
    /* 4C0C 80067F6C 21908000 */  addu       $s2, $a0, $zero
    /* 4C10 80067F70 01000224 */  addiu      $v0, $zero, 0x1
    /* 4C14 80067F74 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 4C18 80067F78 1400B1AF */  sw         $s1, 0x14($sp)
    /* 4C1C 80067F7C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 4C20 80067F80 1800438E */  lw         $v1, 0x18($s2)
    /* 4C24 80067F84 2C00508E */  lw         $s0, 0x2C($s2)
    /* 4C28 80067F88 24006210 */  beq        $v1, $v0, .L8006801C
    /* 4C2C 80067F8C 02006228 */   slti      $v0, $v1, 0x2
    /* 4C30 80067F90 04004014 */  bnez       $v0, .L80067FA4
    /* 4C34 80067F94 21204002 */   addu      $a0, $s2, $zero
    /* 4C38 80067F98 0A000224 */  addiu      $v0, $zero, 0xA
    /* 4C3C 80067F9C 09006210 */  beq        $v1, $v0, .L80067FC4
    /* 4C40 80067FA0 00000000 */   nop
  .L80067FA4:
    /* 4C44 80067FA4 0A000524 */  addiu      $a1, $zero, 0xA
    /* 4C48 80067FA8 0000028E */  lw         $v0, 0x0($s0)
    /* 4C4C 80067FAC FFFF0324 */  addiu      $v1, $zero, -0x1
    /* 4C50 80067FB0 C0100200 */  sll        $v0, $v0, 3
    /* 4C54 80067FB4 21100202 */  addu       $v0, $s0, $v0
    /* 4C58 80067FB8 240043AC */  sw         $v1, 0x24($v0)
    /* 4C5C 80067FBC 05A00108 */  j          .L80068014
    /* 4C60 80067FC0 080000AE */   sw        $zero, 0x8($s0)
  .L80067FC4:
    /* 4C64 80067FC4 0000068E */  lw         $a2, 0x0($s0)
    /* 4C68 80067FC8 00000000 */  nop
    /* 4C6C 80067FCC C0100600 */  sll        $v0, $a2, 3
    /* 4C70 80067FD0 24004224 */  addiu      $v0, $v0, 0x24
    /* 4C74 80067FD4 21880202 */  addu       $s1, $s0, $v0
    /* 4C78 80067FD8 0500A228 */  slti       $v0, $a1, 0x5
    /* 4C7C 80067FDC 05004010 */  beqz       $v0, .L80067FF4
    /* 4C80 80067FE0 00000000 */   nop
    /* 4C84 80067FE4 D59E010C */  jal        Stg11_CardAsyncOp
    /* 4C88 80067FE8 21200002 */   addu      $a0, $s0, $zero
    /* 4C8C 80067FEC 00A00108 */  j          .L80068000
    /* 4C90 80067FF0 000022AE */   sw        $v0, 0x0($s1)
  .L80067FF4:
    /* 4C94 80067FF4 4E9E010C */  jal        Stg11_CardFileOp
    /* 4C98 80067FF8 21200002 */   addu      $a0, $s0, $zero
    /* 4C9C 80067FFC 000022AE */  sw         $v0, 0x0($s1)
  .L80068000:
    /* 4CA0 80068000 0000238E */  lw         $v1, 0x0($s1)
    /* 4CA4 80068004 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 4CA8 80068008 04006210 */  beq        $v1, $v0, .L8006801C
    /* 4CAC 8006800C 21204002 */   addu      $a0, $s2, $zero
    /* 4CB0 80068010 01000524 */  addiu      $a1, $zero, 0x1
  .L80068014:
    /* 4CB4 80068014 8545000C */  jal        Task_SetState2
    /* 4CB8 80068018 00000000 */   nop
  .L8006801C:
    /* 4CBC 8006801C 0000028E */  lw         $v0, 0x0($s0)
    /* 4CC0 80068020 00000000 */  nop
    /* 4CC4 80068024 C0100200 */  sll        $v0, $v0, 3
    /* 4CC8 80068028 21100202 */  addu       $v0, $s0, $v0
    /* 4CCC 8006802C 2400428C */  lw         $v0, 0x24($v0)
    /* 4CD0 80068030 00000000 */  nop
    /* 4CD4 80068034 040002AE */  sw         $v0, 0x4($s0)
    /* 4CD8 80068038 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 4CDC 8006803C 1800B28F */  lw         $s2, 0x18($sp)
    /* 4CE0 80068040 1400B18F */  lw         $s1, 0x14($sp)
    /* 4CE4 80068044 1000B08F */  lw         $s0, 0x10($sp)
    /* 4CE8 80068048 0800E003 */  jr         $ra
    /* 4CEC 8006804C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg11_CardRunOp
