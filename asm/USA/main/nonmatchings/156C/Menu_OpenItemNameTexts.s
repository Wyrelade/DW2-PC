nonmatching Menu_OpenItemNameTexts, 0x15C

glabel Menu_OpenItemNameTexts
    /* 5A98 80015298 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 5A9C 8001529C 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* 5AA0 800152A0 21A8A000 */  addu       $s5, $a1, $zero
    /* 5AA4 800152A4 3000BFAF */  sw         $ra, 0x30($sp)
    /* 5AA8 800152A8 2800B4AF */  sw         $s4, 0x28($sp)
    /* 5AAC 800152AC 2400B3AF */  sw         $s3, 0x24($sp)
    /* 5AB0 800152B0 2000B2AF */  sw         $s2, 0x20($sp)
    /* 5AB4 800152B4 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 5AB8 800152B8 1800B0AF */  sw         $s0, 0x18($sp)
    /* 5ABC 800152BC 2C00948C */  lw         $s4, 0x2C($a0)
    /* 5AC0 800152C0 21880000 */  addu       $s1, $zero, $zero
    /* 5AC4 800152C4 21908002 */  addu       $s2, $s4, $zero
    /* 5AC8 800152C8 FD01043C */  lui        $a0, (0x1FD0098 >> 16)
  .L800152CC:
    /* 5ACC 800152CC 688E000C */  jal        Cd_GetFileEntry
    /* 5AD0 800152D0 98008434 */   ori       $a0, $a0, (0x1FD0098 & 0xFFFF)
    /* 5AD4 800152D4 21284000 */  addu       $a1, $v0, $zero
    /* 5AD8 800152D8 7400828F */  lw         $v0, %gp_rel(D_8005076C)($gp)
    /* 5ADC 800152DC 00000000 */  nop
    /* 5AE0 800152E0 21105100 */  addu       $v0, $v0, $s1
    /* 5AE4 800152E4 00005090 */  lbu        $s0, 0x0($v0)
    /* 5AE8 800152E8 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 5AEC 800152EC 14000212 */  beq        $s0, $v0, .L80015340
    /* 5AF0 800152F0 21980000 */   addu      $s3, $zero, $zero
    /* 5AF4 800152F4 0580023C */  lui        $v0, %hi(D_80050720)
    /* 5AF8 800152F8 2007428C */  lw         $v0, %lo(D_80050720)($v0)
    /* 5AFC 800152FC 40181000 */  sll        $v1, $s0, 1
    /* 5B00 80015300 21184300 */  addu       $v1, $v0, $v1
    /* 5B04 80015304 2C006294 */  lhu        $v0, 0x2C($v1)
    /* 5B08 80015308 00000000 */  nop
    /* 5B0C 8001530C 0C004010 */  beqz       $v0, .L80015340
    /* 5B10 80015310 00000000 */   nop
    /* 5B14 80015314 1278000C */  jal        Item_GetNameText
    /* 5B18 80015318 21204000 */   addu      $a0, $v0, $zero
    /* 5B1C 8001531C 0580033C */  lui        $v1, %hi(D_80050720)
    /* 5B20 80015320 2007638C */  lw         $v1, %lo(D_80050720)($v1)
    /* 5B24 80015324 00000000 */  nop
    /* 5B28 80015328 21187000 */  addu       $v1, $v1, $s0
    /* 5B2C 8001532C 52006390 */  lbu        $v1, 0x52($v1)
    /* 5B30 80015330 00000000 */  nop
    /* 5B34 80015334 02006010 */  beqz       $v1, .L80015340
    /* 5B38 80015338 21284000 */   addu      $a1, $v0, $zero
    /* 5B3C 8001533C 03001324 */  addiu      $s3, $zero, 0x3
  .L80015340:
    /* 5B40 80015340 8E008386 */  lh         $v1, 0x8E($s4)
    /* 5B44 80015344 00000000 */  nop
    /* 5B48 80015348 1A002302 */  div        $zero, $s1, $v1
    /* 5B4C 8001534C 12180000 */  mflo       $v1
    /* 5B50 80015350 00000000 */  nop
    /* 5B54 80015354 40100300 */  sll        $v0, $v1, 1
    /* 5B58 80015358 21104300 */  addu       $v0, $v0, $v1
    /* 5B5C 8001535C 00110200 */  sll        $v0, $v0, 4
    /* 5B60 80015360 21104300 */  addu       $v0, $v0, $v1
    /* 5B64 80015364 40100200 */  sll        $v0, $v0, 1
    /* 5B68 80015368 88004224 */  addiu      $v0, $v0, 0x88
    /* 5B6C 8001536C 1000A2A7 */  sh         $v0, 0x10($sp)
    /* 5B70 80015370 8E008286 */  lh         $v0, 0x8E($s4)
    /* 5B74 80015374 00000000 */  nop
    /* 5B78 80015378 1A002202 */  div        $zero, $s1, $v0
    /* 5B7C 8001537C 10180000 */  mfhi       $v1
    /* 5B80 80015380 21204002 */  addu       $a0, $s2, $zero
    /* 5B84 80015384 2130A002 */  addu       $a2, $s5, $zero
    /* 5B88 80015388 01003126 */  addiu      $s1, $s1, 0x1
    /* 5B8C 8001538C 40100300 */  sll        $v0, $v1, 1
    /* 5B90 80015390 21104300 */  addu       $v0, $v0, $v1
    /* 5B94 80015394 80100200 */  sll        $v0, $v0, 2
    /* 5B98 80015398 32004224 */  addiu      $v0, $v0, 0x32
    /* 5B9C 8001539C 1200A2A7 */  sh         $v0, 0x12($sp)
    /* 5BA0 800153A0 FFFF4730 */  andi       $a3, $v0, 0xFFFF
    /* 5BA4 800153A4 1000A297 */  lhu        $v0, 0x10($sp)
    /* 5BA8 800153A8 003C0700 */  sll        $a3, $a3, 16
    /* 5BAC 800153AC 3E4D000C */  jal        Text_OpenPacked
    /* 5BB0 800153B0 25384700 */   or        $a3, $v0, $a3
    /* 5BB4 800153B4 21286002 */  addu       $a1, $s3, $zero
    /* 5BB8 800153B8 0000448E */  lw         $a0, 0x0($s2)
    /* 5BBC 800153BC 9D6F000C */  jal        Text_SetColor
    /* 5BC0 800153C0 04005226 */   addiu     $s2, $s2, 0x4
    /* 5BC4 800153C4 1400222A */  slti       $v0, $s1, 0x14
    /* 5BC8 800153C8 C0FF4014 */  bnez       $v0, .L800152CC
    /* 5BCC 800153CC FD01043C */   lui       $a0, (0x1FD0098 >> 16)
    /* 5BD0 800153D0 3000BF8F */  lw         $ra, 0x30($sp)
    /* 5BD4 800153D4 2C00B58F */  lw         $s5, 0x2C($sp)
    /* 5BD8 800153D8 2800B48F */  lw         $s4, 0x28($sp)
    /* 5BDC 800153DC 2400B38F */  lw         $s3, 0x24($sp)
    /* 5BE0 800153E0 2000B28F */  lw         $s2, 0x20($sp)
    /* 5BE4 800153E4 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 5BE8 800153E8 1800B08F */  lw         $s0, 0x18($sp)
    /* 5BEC 800153EC 0800E003 */  jr         $ra
    /* 5BF0 800153F0 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel Menu_OpenItemNameTexts
