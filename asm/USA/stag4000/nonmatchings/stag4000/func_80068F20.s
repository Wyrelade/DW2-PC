nonmatching func_80068F20, 0x9C

glabel func_80068F20
    /* 5BC0 80068F20 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 5BC4 80068F24 1800B2AF */  sw         $s2, 0x18($sp)
    /* 5BC8 80068F28 21908000 */  addu       $s2, $a0, $zero
    /* 5BCC 80068F2C 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 5BD0 80068F30 1400B1AF */  sw         $s1, 0x14($sp)
    /* 5BD4 80068F34 1000B0AF */  sw         $s0, 0x10($sp)
    /* 5BD8 80068F38 2C00518E */  lw         $s1, 0x2C($s2)
    /* 5BDC 80068F3C 00000000 */  nop
    /* 5BE0 80068F40 2C00308E */  lw         $s0, 0x2C($s1)
    /* 5BE4 80068F44 12C3010C */  jal        func_80070C48
    /* 5BE8 80068F48 00000000 */   nop
    /* 5BEC 80068F4C 00140200 */  sll        $v0, $v0, 16
    /* 5BF0 80068F50 07000392 */  lbu        $v1, 0x7($s0)
    /* 5BF4 80068F54 03140200 */  sra        $v0, $v0, 16
    /* 5BF8 80068F58 09004314 */  bne        $v0, $v1, .L80068F80
    /* 5BFC 80068F5C 00000000 */   nop
    /* 5C00 80068F60 2C00248E */  lw         $a0, 0x2C($s1)
    /* 5C04 80068F64 81A1010C */  jal        func_80068604
    /* 5C08 80068F68 00000000 */   nop
    /* 5C0C 80068F6C 01000324 */  addiu      $v1, $zero, 0x1
    /* 5C10 80068F70 09004314 */  bne        $v0, $v1, .L80068F98
    /* 5C14 80068F74 21204002 */   addu      $a0, $s2, $zero
    /* 5C18 80068F78 E7A30108 */  j          .L80068F9C
    /* 5C1C 80068F7C 02000524 */   addiu     $a1, $zero, 0x2
  .L80068F80:
    /* 5C20 80068F80 CCB8010C */  jal        func_8006E330
    /* 5C24 80068F84 00000000 */   nop
    /* 5C28 80068F88 03004010 */  beqz       $v0, .L80068F98
    /* 5C2C 80068F8C 21204002 */   addu      $a0, $s2, $zero
    /* 5C30 80068F90 E7A30108 */  j          .L80068F9C
    /* 5C34 80068F94 04000524 */   addiu     $a1, $zero, 0x4
  .L80068F98:
    /* 5C38 80068F98 21280000 */  addu       $a1, $zero, $zero
  .L80068F9C:
    /* 5C3C 80068F9C 7745000C */  jal        Task_SetState1
    /* 5C40 80068FA0 00000000 */   nop
    /* 5C44 80068FA4 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 5C48 80068FA8 1800B28F */  lw         $s2, 0x18($sp)
    /* 5C4C 80068FAC 1400B18F */  lw         $s1, 0x14($sp)
    /* 5C50 80068FB0 1000B08F */  lw         $s0, 0x10($sp)
    /* 5C54 80068FB4 0800E003 */  jr         $ra
    /* 5C58 80068FB8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80068F20
