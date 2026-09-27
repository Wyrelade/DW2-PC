nonmatching Math_RampToOne, 0x30

glabel Math_RampToOne
    /* 3EE4 800136E4 0000A28C */  lw         $v0, 0x0($a1)
    /* 3EE8 800136E8 00000000 */  nop
    /* 3EEC 800136EC 33034224 */  addiu      $v0, $v0, 0x333
    /* 3EF0 800136F0 0000A2AC */  sw         $v0, 0x0($a1)
    /* 3EF4 800136F4 00104228 */  slti       $v0, $v0, 0x1000
    /* 3EF8 800136F8 03004010 */  beqz       $v0, .L80013708
    /* 3EFC 800136FC 00100224 */   addiu     $v0, $zero, 0x1000
    /* 3F00 80013700 0800E003 */  jr         $ra
    /* 3F04 80013704 01000224 */   addiu     $v0, $zero, 0x1
  .L80013708:
    /* 3F08 80013708 0000A2AC */  sw         $v0, 0x0($a1)
    /* 3F0C 8001370C 0800E003 */  jr         $ra
    /* 3F10 80013710 21100000 */   addu      $v0, $zero, $zero
endlabel Math_RampToOne
