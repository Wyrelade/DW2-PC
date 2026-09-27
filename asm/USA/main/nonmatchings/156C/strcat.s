nonmatching strcat, 0xA4

glabel strcat
    /* 30074 8003F874 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 30078 8003F878 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3007C 8003F87C 21888000 */  addu       $s1, $a0, $zero
    /* 30080 8003F880 1800B2AF */  sw         $s2, 0x18($sp)
    /* 30084 8003F884 2190A000 */  addu       $s2, $a1, $zero
    /* 30088 8003F888 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 3008C 8003F88C 1B002012 */  beqz       $s1, .L8003F8FC
    /* 30090 8003F890 1000B0AF */   sw        $s0, 0x10($sp)
    /* 30094 8003F894 1A004012 */  beqz       $s2, .L8003F900
    /* 30098 8003F898 21100000 */   addu      $v0, $zero, $zero
    /* 3009C 8003F89C 6DAA000C */  jal        func_8002A9B4
    /* 300A0 8003F8A0 21202002 */   addu      $a0, $s1, $zero
    /* 300A4 8003F8A4 21204002 */  addu       $a0, $s2, $zero
    /* 300A8 8003F8A8 6DAA000C */  jal        func_8002A9B4
    /* 300AC 8003F8AC 21802202 */   addu      $s0, $s1, $v0
    /* 300B0 8003F8B0 21104202 */  addu       $v0, $s2, $v0
    /* 300B4 8003F8B4 11000212 */  beq        $s0, $v0, .L8003F8FC
    /* 300B8 8003F8B8 21182002 */   addu      $v1, $s1, $zero
    /* 300BC 8003F8BC 00006280 */  lb         $v0, 0x0($v1)
    /* 300C0 8003F8C0 00000000 */  nop
    /* 300C4 8003F8C4 05004010 */  beqz       $v0, .L8003F8DC
    /* 300C8 8003F8C8 01007124 */   addiu     $s1, $v1, 0x1
  .L8003F8CC:
    /* 300CC 8003F8CC 00002282 */  lb         $v0, 0x0($s1)
    /* 300D0 8003F8D0 00000000 */  nop
    /* 300D4 8003F8D4 FDFF4014 */  bnez       $v0, .L8003F8CC
    /* 300D8 8003F8D8 01003126 */   addiu     $s1, $s1, 0x1
  .L8003F8DC:
    /* 300DC 8003F8DC FFFF3126 */  addiu      $s1, $s1, -0x1
  .L8003F8E0:
    /* 300E0 8003F8E0 00004292 */  lbu        $v0, 0x0($s2)
    /* 300E4 8003F8E4 01005226 */  addiu      $s2, $s2, 0x1
    /* 300E8 8003F8E8 000022A2 */  sb         $v0, 0x0($s1)
    /* 300EC 8003F8EC FCFF4014 */  bnez       $v0, .L8003F8E0
    /* 300F0 8003F8F0 01003126 */   addiu     $s1, $s1, 0x1
    /* 300F4 8003F8F4 40FE0008 */  j          .L8003F900
    /* 300F8 8003F8F8 21106000 */   addu      $v0, $v1, $zero
  .L8003F8FC:
    /* 300FC 8003F8FC 21100000 */  addu       $v0, $zero, $zero
  .L8003F900:
    /* 30100 8003F900 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 30104 8003F904 1800B28F */  lw         $s2, 0x18($sp)
    /* 30108 8003F908 1400B18F */  lw         $s1, 0x14($sp)
    /* 3010C 8003F90C 1000B08F */  lw         $s0, 0x10($sp)
    /* 30110 8003F910 0800E003 */  jr         $ra
    /* 30114 8003F914 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel strcat
    /* 30118 8003F918 00000000 */  nop
    /* 3011C 8003F91C 00000000 */  nop
    /* 30120 8003F920 00000000 */  nop
