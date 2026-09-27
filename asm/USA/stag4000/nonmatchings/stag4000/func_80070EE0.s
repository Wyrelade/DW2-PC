nonmatching func_80070EE0, 0x10C

glabel func_80070EE0
    /* DB80 80070EE0 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* DB84 80070EE4 2400B5AF */  sw         $s5, 0x24($sp)
    /* DB88 80070EE8 21A88000 */  addu       $s5, $a0, $zero
    /* DB8C 80070EEC 2800B6AF */  sw         $s6, 0x28($sp)
    /* DB90 80070EF0 21B00000 */  addu       $s6, $zero, $zero
    /* DB94 80070EF4 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* DB98 80070EF8 2000B4AF */  sw         $s4, 0x20($sp)
    /* DB9C 80070EFC 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* DBA0 80070F00 1800B2AF */  sw         $s2, 0x18($sp)
    /* DBA4 80070F04 1400B1AF */  sw         $s1, 0x14($sp)
    /* DBA8 80070F08 1000B0AF */  sw         $s0, 0x10($sp)
    /* DBAC 80070F0C 0000A28E */  lw         $v0, 0x0($s5)
    /* DBB0 80070F10 00000000 */  nop
    /* DBB4 80070F14 2A004010 */  beqz       $v0, .L80070FC0
    /* DBB8 80070F18 2188A002 */   addu      $s1, $s5, $zero
  .L80070F1C:
    /* DBBC 80070F1C 0000A38E */  lw         $v1, 0x0($s5)
    /* DBC0 80070F20 00000000 */  nop
    /* DBC4 80070F24 2B107100 */  sltu       $v0, $v1, $s1
    /* DBC8 80070F28 20004010 */  beqz       $v0, .L80070FAC
    /* DBCC 80070F2C 21107100 */   addu      $v0, $v1, $s1
    /* DBD0 80070F30 21980000 */  addu       $s3, $zero, $zero
    /* DBD4 80070F34 21A04000 */  addu       $s4, $v0, $zero
    /* DBD8 80070F38 0000A2AE */  sw         $v0, 0x0($s5)
    /* DBDC 80070F3C 0000828E */  lw         $v0, 0x0($s4)
    /* DBE0 80070F40 08001224 */  addiu      $s2, $zero, 0x8
    /* DBE4 80070F44 21105100 */  addu       $v0, $v0, $s1
    /* DBE8 80070F48 000082AE */  sw         $v0, 0x0($s4)
  .L80070F4C:
    /* DBEC 80070F4C 21282002 */  addu       $a1, $s1, $zero
    /* DBF0 80070F50 21109202 */  addu       $v0, $s4, $s2
    /* DBF4 80070F54 04005226 */  addiu      $s2, $s2, 0x4
    /* DBF8 80070F58 0000508C */  lw         $s0, 0x0($v0)
    /* DBFC 80070F5C 01007326 */  addiu      $s3, $s3, 0x1
    /* DC00 80070F60 21801102 */  addu       $s0, $s0, $s1
    /* DC04 80070F64 21200002 */  addu       $a0, $s0, $zero
    /* DC08 80070F68 B0C3010C */  jal        func_80070EC0
    /* DC0C 80070F6C 000050AC */   sw        $s0, 0x0($v0)
    /* DC10 80070F70 04000426 */  addiu      $a0, $s0, 0x4
    /* DC14 80070F74 B0C3010C */  jal        func_80070EC0
    /* DC18 80070F78 21282002 */   addu      $a1, $s1, $zero
    /* DC1C 80070F7C 08000426 */  addiu      $a0, $s0, 0x8
    /* DC20 80070F80 B0C3010C */  jal        func_80070EC0
    /* DC24 80070F84 21282002 */   addu      $a1, $s1, $zero
    /* DC28 80070F88 0C000426 */  addiu      $a0, $s0, 0xC
    /* DC2C 80070F8C B0C3010C */  jal        func_80070EC0
    /* DC30 80070F90 21282002 */   addu      $a1, $s1, $zero
    /* DC34 80070F94 10000426 */  addiu      $a0, $s0, 0x10
    /* DC38 80070F98 B0C3010C */  jal        func_80070EC0
    /* DC3C 80070F9C 21282002 */   addu      $a1, $s1, $zero
    /* DC40 80070FA0 0800622A */  slti       $v0, $s3, 0x8
    /* DC44 80070FA4 E9FF4014 */  bnez       $v0, .L80070F4C
    /* DC48 80070FA8 00000000 */   nop
  .L80070FAC:
    /* DC4C 80070FAC 0400B526 */  addiu      $s5, $s5, 0x4
    /* DC50 80070FB0 0000A28E */  lw         $v0, 0x0($s5)
    /* DC54 80070FB4 00000000 */  nop
    /* DC58 80070FB8 D8FF4014 */  bnez       $v0, .L80070F1C
    /* DC5C 80070FBC 0100D626 */   addiu     $s6, $s6, 0x1
  .L80070FC0:
    /* DC60 80070FC0 2110C002 */  addu       $v0, $s6, $zero
    /* DC64 80070FC4 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* DC68 80070FC8 2800B68F */  lw         $s6, 0x28($sp)
    /* DC6C 80070FCC 2400B58F */  lw         $s5, 0x24($sp)
    /* DC70 80070FD0 2000B48F */  lw         $s4, 0x20($sp)
    /* DC74 80070FD4 1C00B38F */  lw         $s3, 0x1C($sp)
    /* DC78 80070FD8 1800B28F */  lw         $s2, 0x18($sp)
    /* DC7C 80070FDC 1400B18F */  lw         $s1, 0x14($sp)
    /* DC80 80070FE0 1000B08F */  lw         $s0, 0x10($sp)
    /* DC84 80070FE4 0800E003 */  jr         $ra
    /* DC88 80070FE8 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_80070EE0
