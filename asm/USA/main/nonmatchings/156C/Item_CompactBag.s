nonmatching Item_CompactBag, 0x84

glabel Item_CompactBag
    /* 12E28 80022628 2800828F */  lw         $v0, %gp_rel(Save_GameStatePtr)($gp)
    /* 12E2C 8002262C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 12E30 80022630 2000B4AF */  sw         $s4, 0x20($sp)
    /* 12E34 80022634 21A00000 */  addu       $s4, $zero, $zero
    /* 12E38 80022638 2400BFAF */  sw         $ra, 0x24($sp)
    /* 12E3C 8002263C 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 12E40 80022640 1800B2AF */  sw         $s2, 0x18($sp)
    /* 12E44 80022644 1400B1AF */  sw         $s1, 0x14($sp)
    /* 12E48 80022648 1000B0AF */  sw         $s0, 0x10($sp)
    /* 12E4C 8002264C 66005024 */  addiu      $s0, $v0, 0x66
    /* 12E50 80022650 21980002 */  addu       $s3, $s0, $zero
  .L80022654:
    /* 12E54 80022654 00001296 */  lhu        $s2, 0x0($s0)
    /* 12E58 80022658 000000A6 */  sh         $zero, 0x0($s0)
    /* 12E5C 8002265C FFFF5132 */  andi       $s1, $s2, 0xFFFF
    /* 12E60 80022660 4278000C */  jal        Item_CheckId
    /* 12E64 80022664 21202002 */   addu      $a0, $s1, $zero
    /* 12E68 80022668 04004014 */  bnez       $v0, .L8002267C
    /* 12E6C 8002266C 00000000 */   nop
    /* 12E70 80022670 02002012 */  beqz       $s1, .L8002267C
    /* 12E74 80022674 000072A6 */   sh        $s2, 0x0($s3)
    /* 12E78 80022678 02007326 */  addiu      $s3, $s3, 0x2
  .L8002267C:
    /* 12E7C 8002267C 01009426 */  addiu      $s4, $s4, 0x1
    /* 12E80 80022680 3000822A */  slti       $v0, $s4, 0x30
    /* 12E84 80022684 F3FF4014 */  bnez       $v0, .L80022654
    /* 12E88 80022688 02001026 */   addiu     $s0, $s0, 0x2
    /* 12E8C 8002268C 2400BF8F */  lw         $ra, 0x24($sp)
    /* 12E90 80022690 2000B48F */  lw         $s4, 0x20($sp)
    /* 12E94 80022694 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 12E98 80022698 1800B28F */  lw         $s2, 0x18($sp)
    /* 12E9C 8002269C 1400B18F */  lw         $s1, 0x14($sp)
    /* 12EA0 800226A0 1000B08F */  lw         $s0, 0x10($sp)
    /* 12EA4 800226A4 0800E003 */  jr         $ra
    /* 12EA8 800226A8 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel Item_CompactBag
