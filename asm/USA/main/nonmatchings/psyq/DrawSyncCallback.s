nonmatching DrawSyncCallback, 0x60

glabel DrawSyncCallback
    /* 17B88 80027388 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 17B8C 8002738C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 17B90 80027390 0580103C */  lui        $s0, %hi(D_80048F12)
    /* 17B94 80027394 128F1026 */  addiu      $s0, $s0, %lo(D_80048F12)
    /* 17B98 80027398 1800BFAF */  sw         $ra, 0x18($sp)
    /* 17B9C 8002739C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 17BA0 800273A0 00000292 */  lbu        $v0, 0x0($s0)
    /* 17BA4 800273A4 00000000 */  nop
    /* 17BA8 800273A8 0200422C */  sltiu      $v0, $v0, 0x2
    /* 17BAC 800273AC 07004014 */  bnez       $v0, .L800273CC
    /* 17BB0 800273B0 21888000 */   addu      $s1, $a0, $zero
    /* 17BB4 800273B4 0580023C */  lui        $v0, %hi(D_80048F0C)
    /* 17BB8 800273B8 0C8F428C */  lw         $v0, %lo(D_80048F0C)($v0)
    /* 17BBC 800273BC 0180043C */  lui        $a0, %hi(D_80010290)
    /* 17BC0 800273C0 90028424 */  addiu      $a0, $a0, %lo(D_80010290)
    /* 17BC4 800273C4 09F84000 */  jalr       $v0
    /* 17BC8 800273C8 21282002 */   addu      $a1, $s1, $zero
  .L800273CC:
    /* 17BCC 800273CC 0A00028E */  lw         $v0, 0xA($s0)
    /* 17BD0 800273D0 0A0011AE */  sw         $s1, 0xA($s0)
    /* 17BD4 800273D4 1800BF8F */  lw         $ra, 0x18($sp)
    /* 17BD8 800273D8 1400B18F */  lw         $s1, 0x14($sp)
    /* 17BDC 800273DC 1000B08F */  lw         $s0, 0x10($sp)
    /* 17BE0 800273E0 0800E003 */  jr         $ra
    /* 17BE4 800273E4 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel DrawSyncCallback
