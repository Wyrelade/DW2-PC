nonmatching MemCardStop, 0x40

glabel MemCardStop
    /* 2E570 8003DD70 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2E574 8003DD74 0680033C */  lui        $v1, %hi(D_80062F80)
    /* 2E578 8003DD78 802F6324 */  addiu      $v1, $v1, %lo(D_80062F80)
    /* 2E57C 8003DD7C 1000BFAF */  sw         $ra, 0x10($sp)
  .L8003DD80:
    /* 2E580 8003DD80 0000628C */  lw         $v0, 0x0($v1)
    /* 2E584 8003DD84 00000000 */  nop
    /* 2E588 8003DD88 FDFF4014 */  bnez       $v0, .L8003DD80
    /* 2E58C 8003DD8C 07000424 */   addiu     $a0, $zero, 0x7
    /* 2E590 8003DD90 66C3000C */  jal        VSyncCallbacks
    /* 2E594 8003DD94 21280000 */   addu      $a1, $zero, $zero
    /* 2E598 8003DD98 7CFF000C */  jal        Card_CloseEvents
    /* 2E59C 8003DD9C 00000000 */   nop
    /* 2E5A0 8003DDA0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2E5A4 8003DDA4 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 2E5A8 8003DDA8 0800E003 */  jr         $ra
    /* 2E5AC 8003DDAC 00000000 */   nop
endlabel MemCardStop
