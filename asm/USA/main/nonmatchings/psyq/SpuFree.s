nonmatching SpuFree, 0x7C

glabel SpuFree
    /* 2BB74 8003B374 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2BB78 8003B378 0580033C */  lui        $v1, %hi(D_8004FE88)
    /* 2BB7C 8003B37C 88FE638C */  lw         $v1, %lo(D_8004FE88)($v1)
    /* 2BB80 8003B380 21300000 */  addu       $a2, $zero, $zero
    /* 2BB84 8003B384 14006018 */  blez       $v1, .L8003B3D8
    /* 2BB88 8003B388 1000BFAF */   sw        $ra, 0x10($sp)
    /* 2BB8C 8003B38C 0040093C */  lui        $t1, (0x40000000 >> 16)
    /* 2BB90 8003B390 0080023C */  lui        $v0, (0x80000000 >> 16)
    /* 2BB94 8003B394 25408200 */  or         $t0, $a0, $v0
    /* 2BB98 8003B398 21386000 */  addu       $a3, $v1, $zero
    /* 2BB9C 8003B39C 0580053C */  lui        $a1, %hi(Spu_MemList)
    /* 2BBA0 8003B3A0 90FEA58C */  lw         $a1, %lo(Spu_MemList)($a1)
    /* 2BBA4 8003B3A4 00000000 */  nop
  .L8003B3A8:
    /* 2BBA8 8003B3A8 0000A38C */  lw         $v1, 0x0($a1)
    /* 2BBAC 8003B3AC 00000000 */  nop
    /* 2BBB0 8003B3B0 24106900 */  and        $v0, $v1, $t1
    /* 2BBB4 8003B3B4 08004014 */  bnez       $v0, .L8003B3D8
    /* 2BBB8 8003B3B8 00000000 */   nop
    /* 2BBBC 8003B3BC 03006414 */  bne        $v1, $a0, .L8003B3CC
    /* 2BBC0 8003B3C0 0100C624 */   addiu     $a2, $a2, 0x1
    /* 2BBC4 8003B3C4 F6EC0008 */  j          .L8003B3D8
    /* 2BBC8 8003B3C8 0000A8AC */   sw        $t0, 0x0($a1)
  .L8003B3CC:
    /* 2BBCC 8003B3CC 2A10C700 */  slt        $v0, $a2, $a3
    /* 2BBD0 8003B3D0 F5FF4014 */  bnez       $v0, .L8003B3A8
    /* 2BBD4 8003B3D4 0800A524 */   addiu     $a1, $a1, 0x8
  .L8003B3D8:
    /* 2BBD8 8003B3D8 1DEC000C */  jal        _spu_gcSPU
    /* 2BBDC 8003B3DC 00000000 */   nop
    /* 2BBE0 8003B3E0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2BBE4 8003B3E4 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 2BBE8 8003B3E8 0800E003 */  jr         $ra
    /* 2BBEC 8003B3EC 00000000 */   nop
endlabel SpuFree
    /* 2BBF0 8003B3F0 00000000 */  nop
