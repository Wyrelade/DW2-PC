nonmatching Gfx_HidePartsByMask, 0x4C

glabel Gfx_HidePartsByMask
    /* DD04 8001D504 0000828C */  lw         $v0, 0x0($a0)
    /* DD08 8001D508 00000000 */  nop
    /* DD0C 8001D50C 0E004010 */  beqz       $v0, .L8001D548
    /* DD10 8001D510 01000324 */   addiu     $v1, $zero, 0x1
  .L8001D514:
    /* DD14 8001D514 1C00828C */  lw         $v0, 0x1C($a0)
    /* DD18 8001D518 00000000 */  nop
    /* DD1C 8001D51C 24104500 */  and        $v0, $v0, $a1
    /* DD20 8001D520 03004010 */  beqz       $v0, .L8001D530
    /* DD24 8001D524 00000000 */   nop
    /* DD28 8001D528 4D750008 */  j          .L8001D534
    /* DD2C 8001D52C 0F0080A0 */   sb        $zero, 0xF($a0)
  .L8001D530:
    /* DD30 8001D530 0F0083A0 */  sb         $v1, 0xF($a0)
  .L8001D534:
    /* DD34 8001D534 28008424 */  addiu      $a0, $a0, 0x28
    /* DD38 8001D538 0000828C */  lw         $v0, 0x0($a0)
    /* DD3C 8001D53C 00000000 */  nop
    /* DD40 8001D540 F4FF4014 */  bnez       $v0, .L8001D514
    /* DD44 8001D544 00000000 */   nop
  .L8001D548:
    /* DD48 8001D548 0800E003 */  jr         $ra
    /* DD4C 8001D54C 00000000 */   nop
endlabel Gfx_HidePartsByMask
