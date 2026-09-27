nonmatching func_80038B74, 0x70

glabel func_80038B74
    /* 29374 80038B74 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 29378 80038B78 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2937C 80038B7C 2188C000 */  addu       $s1, $a2, $zero
    /* 29380 80038B80 00240400 */  sll        $a0, $a0, 16
    /* 29384 80038B84 002C0500 */  sll        $a1, $a1, 16
    /* 29388 80038B88 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2938C 80038B8C 03840500 */  sra        $s0, $a1, 16
    /* 29390 80038B90 03240400 */  sra        $a0, $a0, 16
    /* 29394 80038B94 1800BFAF */  sw         $ra, 0x18($sp)
    /* 29398 80038B98 35E6000C */  jal        _SsVmVSetUp
    /* 2939C 80038B9C 21280002 */   addu      $a1, $s0, $zero
    /* 293A0 80038BA0 0B004014 */  bnez       $v0, .L80038BD0
    /* 293A4 80038BA4 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 293A8 80038BA8 0680023C */  lui        $v0, %hi(D_80062CFC)
    /* 293AC 80038BAC FC2C428C */  lw         $v0, %lo(D_80062CFC)($v0)
    /* 293B0 80038BB0 00191000 */  sll        $v1, $s0, 4
    /* 293B4 80038BB4 21106200 */  addu       $v0, $v1, $v0
    /* 293B8 80038BB8 010051A0 */  sb         $s1, 0x1($v0)
    /* 293BC 80038BBC 0680023C */  lui        $v0, %hi(D_80062CFC)
    /* 293C0 80038BC0 FC2C428C */  lw         $v0, %lo(D_80062CFC)($v0)
    /* 293C4 80038BC4 00000000 */  nop
    /* 293C8 80038BC8 21186200 */  addu       $v1, $v1, $v0
    /* 293CC 80038BCC 01006290 */  lbu        $v0, 0x1($v1)
  .L80038BD0:
    /* 293D0 80038BD0 1800BF8F */  lw         $ra, 0x18($sp)
    /* 293D4 80038BD4 1400B18F */  lw         $s1, 0x14($sp)
    /* 293D8 80038BD8 1000B08F */  lw         $s0, 0x10($sp)
    /* 293DC 80038BDC 0800E003 */  jr         $ra
    /* 293E0 80038BE0 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80038B74
