nonmatching _spu_Fw1ts, 0x5C

glabel _spu_Fw1ts
    /* 2B4AC 8003ACAC F8FFBD27 */  addiu      $sp, $sp, -0x8
    /* 2B4B0 8003ACB0 0D000224 */  addiu      $v0, $zero, 0xD
    /* 2B4B4 8003ACB4 0400A2AF */  sw         $v0, 0x4($sp)
    /* 2B4B8 8003ACB8 3BEB0008 */  j          .L8003ACEC
    /* 2B4BC 8003ACBC 0000A0AF */   sw        $zero, 0x0($sp)
  .L8003ACC0:
    /* 2B4C0 8003ACC0 0400A38F */  lw         $v1, 0x4($sp)
    /* 2B4C4 8003ACC4 00000000 */  nop
    /* 2B4C8 8003ACC8 40100300 */  sll        $v0, $v1, 1
    /* 2B4CC 8003ACCC 21104300 */  addu       $v0, $v0, $v1
    /* 2B4D0 8003ACD0 80100200 */  sll        $v0, $v0, 2
    /* 2B4D4 8003ACD4 21104300 */  addu       $v0, $v0, $v1
    /* 2B4D8 8003ACD8 0400A2AF */  sw         $v0, 0x4($sp)
    /* 2B4DC 8003ACDC 0000A28F */  lw         $v0, 0x0($sp)
    /* 2B4E0 8003ACE0 00000000 */  nop
    /* 2B4E4 8003ACE4 01004224 */  addiu      $v0, $v0, 0x1
    /* 2B4E8 8003ACE8 0000A2AF */  sw         $v0, 0x0($sp)
  .L8003ACEC:
    /* 2B4EC 8003ACEC 0000A28F */  lw         $v0, 0x0($sp)
    /* 2B4F0 8003ACF0 00000000 */  nop
    /* 2B4F4 8003ACF4 3C004228 */  slti       $v0, $v0, 0x3C
    /* 2B4F8 8003ACF8 F1FF4014 */  bnez       $v0, .L8003ACC0
    /* 2B4FC 8003ACFC 00000000 */   nop
    /* 2B500 8003AD00 0800E003 */  jr         $ra
    /* 2B504 8003AD04 0800BD27 */   addiu     $sp, $sp, 0x8
endlabel _spu_Fw1ts
    /* 2B508 8003AD08 00000000 */  nop
    /* 2B50C 8003AD0C 00000000 */  nop
    /* 2B510 8003AD10 00000000 */  nop
