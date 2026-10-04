nonmatching func_80064EF0, 0xE0

glabel func_80064EF0
    /* 1B90 80064EF0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1B94 80064EF4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 1B98 80064EF8 21908000 */  addu       $s2, $a0, $zero
    /* 1B9C 80064EFC 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 1BA0 80064F00 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1BA4 80064F04 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1BA8 80064F08 1800428E */  lw         $v0, 0x18($s2)
    /* 1BAC 80064F0C 00000000 */  nop
    /* 1BB0 80064F10 04004014 */  bnez       $v0, .L80064F24
    /* 1BB4 80064F14 2188A000 */   addu      $s1, $a1, $zero
    /* 1BB8 80064F18 84002586 */  lh         $a1, 0x84($s1)
    /* 1BBC 80064F1C EB9D010C */  jal        func_800677AC
    /* 1BC0 80064F20 04000424 */   addiu     $a0, $zero, 0x4
  .L80064F24:
    /* 1BC4 80064F24 21204002 */  addu       $a0, $s2, $zero
    /* 1BC8 80064F28 7E92010C */  jal        func_800649F8
    /* 1BCC 80064F2C 21282002 */   addu      $a1, $s1, $zero
    /* 1BD0 80064F30 21004014 */  bnez       $v0, .L80064FB8
    /* 1BD4 80064F34 00000000 */   nop
    /* 1BD8 80064F38 1800508E */  lw         $s0, 0x18($s2)
    /* 1BDC 80064F3C 00000000 */  nop
    /* 1BE0 80064F40 03000012 */  beqz       $s0, .L80064F50
    /* 1BE4 80064F44 01000224 */   addiu     $v0, $zero, 0x1
    /* 1BE8 80064F48 0C000212 */  beq        $s0, $v0, .L80064F7C
    /* 1BEC 80064F4C 00000000 */   nop
  .L80064F50:
    /* 1BF0 80064F50 21202002 */  addu       $a0, $s1, $zero
    /* 1BF4 80064F54 3992010C */  jal        func_800648E4
    /* 1BF8 80064F58 6D010524 */   addiu     $a1, $zero, 0x16D
    /* 1BFC 80064F5C 21202002 */  addu       $a0, $s1, $zero
    /* 1C00 80064F60 77010524 */  addiu      $a1, $zero, 0x177
    /* 1C04 80064F64 5792010C */  jal        func_8006495C
    /* 1C08 80064F68 01000624 */   addiu     $a2, $zero, 0x1
    /* 1C0C 80064F6C 6045000C */  jal        Task_NextState2
    /* 1C10 80064F70 21204002 */   addu      $a0, $s2, $zero
    /* 1C14 80064F74 EE930108 */  j          .L80064FB8
    /* 1C18 80064F78 00000000 */   nop
  .L80064F7C:
    /* 1C1C 80064F7C 0400248E */  lw         $a0, 0x4($s1)
    /* 1C20 80064F80 A94D000C */  jal        Text_WaitYesNo
    /* 1C24 80064F84 00000000 */   nop
    /* 1C28 80064F88 21184000 */  addu       $v1, $v0, $zero
    /* 1C2C 80064F8C FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 1C30 80064F90 07006210 */  beq        $v1, $v0, .L80064FB0
    /* 1C34 80064F94 21204002 */   addu      $a0, $s2, $zero
    /* 1C38 80064F98 07007014 */  bne        $v1, $s0, .L80064FB8
    /* 1C3C 80064F9C 00000000 */   nop
    /* 1C40 80064FA0 7045000C */  jal        Task_SetState0
    /* 1C44 80064FA4 02000524 */   addiu     $a1, $zero, 0x2
    /* 1C48 80064FA8 EE930108 */  j          .L80064FB8
    /* 1C4C 80064FAC 00000000 */   nop
  .L80064FB0:
    /* 1C50 80064FB0 7745000C */  jal        Task_SetState1
    /* 1C54 80064FB4 0A000524 */   addiu     $a1, $zero, 0xA
  .L80064FB8:
    /* 1C58 80064FB8 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 1C5C 80064FBC 1800B28F */  lw         $s2, 0x18($sp)
    /* 1C60 80064FC0 1400B18F */  lw         $s1, 0x14($sp)
    /* 1C64 80064FC4 1000B08F */  lw         $s0, 0x10($sp)
    /* 1C68 80064FC8 0800E003 */  jr         $ra
    /* 1C6C 80064FCC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80064EF0
