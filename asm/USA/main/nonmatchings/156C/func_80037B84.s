nonmatching func_80037B84, 0x4C

glabel func_80037B84
    /* 28384 80037B84 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 28388 80037B88 0680033C */  lui        $v1, %hi(D_80062D29)
    /* 2838C 80037B8C 292D6324 */  addiu      $v1, $v1, %lo(D_80062D29)
    /* 28390 80037B90 1000BFAF */  sw         $ra, 0x10($sp)
    /* 28394 80037B94 00006790 */  lbu        $a3, 0x0($v1)
    /* 28398 80037B98 00000000 */  nop
    /* 2839C 80037B9C FF00E230 */  andi       $v0, $a3, 0xFF
    /* 283A0 80037BA0 8000422C */  sltiu      $v0, $v0, 0x80
    /* 283A4 80037BA4 02004014 */  bnez       $v0, .L80037BB0
    /* 283A8 80037BA8 00000000 */   nop
    /* 283AC 80037BAC 7F000724 */  addiu      $a3, $zero, 0x7F
  .L80037BB0:
    /* 283B0 80037BB0 F1FF6480 */  lb         $a0, -0xF($v1)
    /* 283B4 80037BB4 FFFF6690 */  lbu        $a2, -0x1($v1)
    /* 283B8 80037BB8 0EDF000C */  jal        SsPitchFromNote
    /* 283BC 80037BBC 21280000 */   addu      $a1, $zero, $zero
    /* 283C0 80037BC0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 283C4 80037BC4 FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* 283C8 80037BC8 0800E003 */  jr         $ra
    /* 283CC 80037BCC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80037B84
