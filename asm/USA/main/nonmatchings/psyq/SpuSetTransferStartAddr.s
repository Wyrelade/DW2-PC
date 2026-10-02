nonmatching SpuSetTransferStartAddr, 0x5C

glabel SpuSetTransferStartAddr
    /* 2CF74 8003C774 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2CF78 8003C778 21288000 */  addu       $a1, $a0, $zero
    /* 2CF7C 8003C77C 0700023C */  lui        $v0, (0x7EFE8 >> 16)
    /* 2CF80 8003C780 E8EF4234 */  ori        $v0, $v0, (0x7EFE8 & 0xFFFF)
    /* 2CF84 8003C784 F0EFA324 */  addiu      $v1, $a1, -0x1010
    /* 2CF88 8003C788 2B104300 */  sltu       $v0, $v0, $v1
    /* 2CF8C 8003C78C 0B004014 */  bnez       $v0, .L8003C7BC
    /* 2CF90 8003C790 1000BFAF */   sw        $ra, 0x10($sp)
    /* 2CF94 8003C794 C9EA000C */  jal        _spu_FsetRXXa
    /* 2CF98 8003C798 FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 2CF9C 8003C79C 0580013C */  lui        $at, %hi(D_8004FE40)
    /* 2CFA0 8003C7A0 40FE22A4 */  sh         $v0, %lo(D_8004FE40)($at)
    /* 2CFA4 8003C7A4 0580033C */  lui        $v1, %hi(D_8004FE40)
    /* 2CFA8 8003C7A8 40FE6394 */  lhu        $v1, %lo(D_8004FE40)($v1)
    /* 2CFAC 8003C7AC 0580023C */  lui        $v0, %hi(D_8004FE50)
    /* 2CFB0 8003C7B0 50FE428C */  lw         $v0, %lo(D_8004FE50)($v0)
    /* 2CFB4 8003C7B4 F0F10008 */  j          .L8003C7C0
    /* 2CFB8 8003C7B8 04104300 */   sllv      $v0, $v1, $v0
  .L8003C7BC:
    /* 2CFBC 8003C7BC 21100000 */  addu       $v0, $zero, $zero
  .L8003C7C0:
    /* 2CFC0 8003C7C0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2CFC4 8003C7C4 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 2CFC8 8003C7C8 0800E003 */  jr         $ra
    /* 2CFCC 8003C7CC 00000000 */   nop
endlabel SpuSetTransferStartAddr
    /* 2CFD0 8003C7D0 00000000 */  nop
