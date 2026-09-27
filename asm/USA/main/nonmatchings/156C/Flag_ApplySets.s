nonmatching Flag_ApplySets, 0x64

glabel Flag_ApplySets
    /* 12B88 80022388 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 12B8C 8002238C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 12B90 80022390 21880000 */  addu       $s1, $zero, $zero
    /* 12B94 80022394 1800B2AF */  sw         $s2, 0x18($sp)
    /* 12B98 80022398 FFFF1224 */  addiu      $s2, $zero, -0x1
    /* 12B9C 8002239C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 12BA0 800223A0 21808000 */  addu       $s0, $a0, $zero
    /* 12BA4 800223A4 1C00BFAF */  sw         $ra, 0x1C($sp)
  .L800223A8:
    /* 12BA8 800223A8 00000486 */  lh         $a0, 0x0($s0)
    /* 12BAC 800223AC 00000000 */  nop
    /* 12BB0 800223B0 04009210 */  beq        $a0, $s2, .L800223C4
    /* 12BB4 800223B4 00000000 */   nop
    /* 12BB8 800223B8 02000586 */  lh         $a1, 0x2($s0)
    /* 12BBC 800223BC 7188000C */  jal        Flag_Set
    /* 12BC0 800223C0 00000000 */   nop
  .L800223C4:
    /* 12BC4 800223C4 01003126 */  addiu      $s1, $s1, 0x1
    /* 12BC8 800223C8 0600222A */  slti       $v0, $s1, 0x6
    /* 12BCC 800223CC F6FF4014 */  bnez       $v0, .L800223A8
    /* 12BD0 800223D0 04001026 */   addiu     $s0, $s0, 0x4
    /* 12BD4 800223D4 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 12BD8 800223D8 1800B28F */  lw         $s2, 0x18($sp)
    /* 12BDC 800223DC 1400B18F */  lw         $s1, 0x14($sp)
    /* 12BE0 800223E0 1000B08F */  lw         $s0, 0x10($sp)
    /* 12BE4 800223E4 0800E003 */  jr         $ra
    /* 12BE8 800223E8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Flag_ApplySets
