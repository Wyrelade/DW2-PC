nonmatching func_80065E64, 0x1C4

glabel func_80065E64
    /* 2B04 80065E64 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2B08 80065E68 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2B0C 80065E6C 21888000 */  addu       $s1, $a0, $zero
    /* 2B10 80065E70 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 2B14 80065E74 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2B18 80065E78 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2B1C 80065E7C 1800228E */  lw         $v0, 0x18($s1)
    /* 2B20 80065E80 00000000 */  nop
    /* 2B24 80065E84 04004014 */  bnez       $v0, .L80065E98
    /* 2B28 80065E88 2180A000 */   addu      $s0, $a1, $zero
    /* 2B2C 80065E8C 84000586 */  lh         $a1, 0x84($s0)
    /* 2B30 80065E90 EB9D010C */  jal        func_800677AC
    /* 2B34 80065E94 04000424 */   addiu     $a0, $zero, 0x4
  .L80065E98:
    /* 2B38 80065E98 21202002 */  addu       $a0, $s1, $zero
    /* 2B3C 80065E9C 7E92010C */  jal        func_800649F8
    /* 2B40 80065EA0 21280002 */   addu      $a1, $s0, $zero
    /* 2B44 80065EA4 07004010 */  beqz       $v0, .L80065EC4
    /* 2B48 80065EA8 38000426 */   addiu     $a0, $s0, 0x38
    /* 2B4C 80065EAC 2C70000C */  jal        Text_CloseArray
    /* 2B50 80065EB0 0B000524 */   addiu     $a1, $zero, 0xB
    /* 2B54 80065EB4 E26E000C */  jal        Text_Close
    /* 2B58 80065EB8 0C000426 */   addiu     $a0, $s0, 0xC
    /* 2B5C 80065EBC 04980108 */  j          .L80066010
    /* 2B60 80065EC0 00000000 */   nop
  .L80065EC4:
    /* 2B64 80065EC4 1800238E */  lw         $v1, 0x18($s1)
    /* 2B68 80065EC8 01001224 */  addiu      $s2, $zero, 0x1
    /* 2B6C 80065ECC 16007210 */  beq        $v1, $s2, .L80065F28
    /* 2B70 80065ED0 02006228 */   slti      $v0, $v1, 0x2
    /* 2B74 80065ED4 06004014 */  bnez       $v0, .L80065EF0
    /* 2B78 80065ED8 21200002 */   addu      $a0, $s0, $zero
    /* 2B7C 80065EDC 02000224 */  addiu      $v0, $zero, 0x2
    /* 2B80 80065EE0 15006210 */  beq        $v1, $v0, .L80065F38
    /* 2B84 80065EE4 03000224 */   addiu     $v0, $zero, 0x3
    /* 2B88 80065EE8 3A006210 */  beq        $v1, $v0, .L80065FD4
    /* 2B8C 80065EEC 00000000 */   nop
  .L80065EF0:
    /* 2B90 80065EF0 21280000 */  addu       $a1, $zero, $zero
    /* 2B94 80065EF4 02000224 */  addiu      $v0, $zero, 0x2
    /* 2B98 80065EF8 860002A6 */  sh         $v0, 0x86($s0)
    /* 2B9C 80065EFC 05000224 */  addiu      $v0, $zero, 0x5
    /* 2BA0 80065F00 3992010C */  jal        func_800648E4
    /* 2BA4 80065F04 6E0002A6 */   sh        $v0, 0x6E($s0)
    /* 2BA8 80065F08 21202002 */  addu       $a0, $s1, $zero
    /* 2BAC 80065F0C 0090010C */  jal        func_80064000
    /* 2BB0 80065F10 21280002 */   addu      $a1, $s0, $zero
    /* 2BB4 80065F14 21202002 */  addu       $a0, $s1, $zero
    /* 2BB8 80065F18 C190010C */  jal        func_80064304
    /* 2BBC 80065F1C 21280002 */   addu      $a1, $s0, $zero
    /* 2BC0 80065F20 E9970108 */  j          .L80065FA4
    /* 2BC4 80065F24 00000000 */   nop
  .L80065F28:
    /* 2BC8 80065F28 21200002 */  addu       $a0, $s0, $zero
    /* 2BCC 80065F2C B6010524 */  addiu      $a1, $zero, 0x1B6
    /* 2BD0 80065F30 E7970108 */  j          .L80065F9C
    /* 2BD4 80065F34 21300000 */   addu      $a2, $zero, $zero
  .L80065F38:
    /* 2BD8 80065F38 68000426 */  addiu      $a0, $s0, 0x68
    /* 2BDC 80065F3C 7E000686 */  lh         $a2, 0x7E($s0)
    /* 2BE0 80065F40 304E000C */  jal        Menu_MoveGridCursor
    /* 2BE4 80065F44 6C000526 */   addiu     $a1, $s0, 0x6C
    /* 2BE8 80065F48 1A004014 */  bnez       $v0, .L80065FB4
    /* 2BEC 80065F4C 21200002 */   addu      $a0, $s0, $zero
    /* 2BF0 80065F50 0680023C */  lui        $v0, %hi(D_8005F6F0)
    /* 2BF4 80065F54 7E000386 */  lh         $v1, 0x7E($s0)
    /* 2BF8 80065F58 F0F64224 */  addiu      $v0, $v0, %lo(D_8005F6F0)
    /* 2BFC 80065F5C 80190300 */  sll        $v1, $v1, 6
    /* 2C00 80065F60 21186200 */  addu       $v1, $v1, $v0
    /* 2C04 80065F64 1400628C */  lw         $v0, 0x14($v1)
    /* 2C08 80065F68 00000000 */  nop
    /* 2C0C 80065F6C 05004018 */  blez       $v0, .L80065F84
    /* 2C10 80065F70 21202002 */   addu      $a0, $s1, $zero
    /* 2C14 80065F74 2391010C */  jal        func_8006448C
    /* 2C18 80065F78 21280002 */   addu      $a1, $s0, $zero
    /* 2C1C 80065F7C 04980108 */  j          .L80066010
    /* 2C20 80065F80 00000000 */   nop
  .L80065F84:
    /* 2C24 80065F84 1C00628C */  lw         $v0, 0x1C($v1)
    /* 2C28 80065F88 00000000 */  nop
    /* 2C2C 80065F8C 20004018 */  blez       $v0, .L80066010
    /* 2C30 80065F90 21200002 */   addu      $a0, $s0, $zero
    /* 2C34 80065F94 B8010524 */  addiu      $a1, $zero, 0x1B8
    /* 2C38 80065F98 01000624 */  addiu      $a2, $zero, 0x1
  .L80065F9C:
    /* 2C3C 80065F9C 5792010C */  jal        func_8006495C
    /* 2C40 80065FA0 00000000 */   nop
  .L80065FA4:
    /* 2C44 80065FA4 6045000C */  jal        Task_NextState2
    /* 2C48 80065FA8 21202002 */   addu      $a0, $s1, $zero
    /* 2C4C 80065FAC 04980108 */  j          .L80066010
    /* 2C50 80065FB0 00000000 */   nop
  .L80065FB4:
    /* 2C54 80065FB4 B6010524 */  addiu      $a1, $zero, 0x1B6
    /* 2C58 80065FB8 5792010C */  jal        func_8006495C
    /* 2C5C 80065FBC 21300000 */   addu      $a2, $zero, $zero
    /* 2C60 80065FC0 0D000424 */  addiu      $a0, $zero, 0xD
    /* 2C64 80065FC4 A369000C */  jal        Snd_PlayById
    /* 2C68 80065FC8 21280000 */   addu      $a1, $zero, $zero
    /* 2C6C 80065FCC 04980108 */  j          .L80066010
    /* 2C70 80065FD0 00000000 */   nop
  .L80065FD4:
    /* 2C74 80065FD4 0400048E */  lw         $a0, 0x4($s0)
    /* 2C78 80065FD8 A94D000C */  jal        func_800136A4
    /* 2C7C 80065FDC 00000000 */   nop
    /* 2C80 80065FE0 21184000 */  addu       $v1, $v0, $zero
    /* 2C84 80065FE4 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 2C88 80065FE8 07006210 */  beq        $v1, $v0, .L80066008
    /* 2C8C 80065FEC 21202002 */   addu      $a0, $s1, $zero
    /* 2C90 80065FF0 07007214 */  bne        $v1, $s2, .L80066010
    /* 2C94 80065FF4 00000000 */   nop
    /* 2C98 80065FF8 7045000C */  jal        Task_SetState0
    /* 2C9C 80065FFC 02000524 */   addiu     $a1, $zero, 0x2
    /* 2CA0 80066000 04980108 */  j          .L80066010
    /* 2CA4 80066004 00000000 */   nop
  .L80066008:
    /* 2CA8 80066008 8545000C */  jal        Task_SetState2
    /* 2CAC 8006600C 01000524 */   addiu     $a1, $zero, 0x1
  .L80066010:
    /* 2CB0 80066010 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 2CB4 80066014 1800B28F */  lw         $s2, 0x18($sp)
    /* 2CB8 80066018 1400B18F */  lw         $s1, 0x14($sp)
    /* 2CBC 8006601C 1000B08F */  lw         $s0, 0x10($sp)
    /* 2CC0 80066020 0800E003 */  jr         $ra
    /* 2CC4 80066024 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80065E64
