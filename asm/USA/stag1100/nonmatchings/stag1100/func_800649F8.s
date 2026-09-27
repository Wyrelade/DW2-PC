nonmatching func_800649F8, 0x74

glabel func_800649F8
    /* 1698 800649F8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 169C 800649FC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 16A0 80064A00 21888000 */  addu       $s1, $a0, $zero
    /* 16A4 80064A04 1800B2AF */  sw         $s2, 0x18($sp)
    /* 16A8 80064A08 2190A000 */  addu       $s2, $a1, $zero
    /* 16AC 80064A0C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 16B0 80064A10 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 16B4 80064A14 069E010C */  jal        func_80067818
    /* 16B8 80064A18 21800000 */   addu      $s0, $zero, $zero
    /* 16BC 80064A1C 21184000 */  addu       $v1, $v0, $zero
    /* 16C0 80064A20 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 16C4 80064A24 0B006210 */  beq        $v1, $v0, .L80064A54
    /* 16C8 80064A28 21100002 */   addu      $v0, $s0, $zero
    /* 16CC 80064A2C 05006014 */  bnez       $v1, .L80064A44
    /* 16D0 80064A30 21202002 */   addu      $a0, $s1, $zero
    /* 16D4 80064A34 7745000C */  jal        Task_SetState1
    /* 16D8 80064A38 03000524 */   addiu     $a1, $zero, 0x3
    /* 16DC 80064A3C 94920108 */  j          .L80064A50
    /* 16E0 80064A40 FFFF1024 */   addiu     $s0, $zero, -0x1
  .L80064A44:
    /* 16E4 80064A44 84004586 */  lh         $a1, 0x84($s2)
    /* 16E8 80064A48 EB9D010C */  jal        func_800677AC
    /* 16EC 80064A4C 04000424 */   addiu     $a0, $zero, 0x4
  .L80064A50:
    /* 16F0 80064A50 21100002 */  addu       $v0, $s0, $zero
  .L80064A54:
    /* 16F4 80064A54 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 16F8 80064A58 1800B28F */  lw         $s2, 0x18($sp)
    /* 16FC 80064A5C 1400B18F */  lw         $s1, 0x14($sp)
    /* 1700 80064A60 1000B08F */  lw         $s0, 0x10($sp)
    /* 1704 80064A64 0800E003 */  jr         $ra
    /* 1708 80064A68 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800649F8
