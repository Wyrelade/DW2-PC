nonmatching setIntrVSync, 0x2C

glabel setIntrVSync
    /* 21D28 80031528 0580023C */  lui        $v0, %hi(Sys_VSyncCallbacks)
    /* 21D2C 8003152C A0FB4224 */  addiu      $v0, $v0, %lo(Sys_VSyncCallbacks)
    /* 21D30 80031530 80200400 */  sll        $a0, $a0, 2
    /* 21D34 80031534 21208200 */  addu       $a0, $a0, $v0
    /* 21D38 80031538 0000828C */  lw         $v0, 0x0($a0)
    /* 21D3C 8003153C 00000000 */  nop
    /* 21D40 80031540 0200A210 */  beq        $a1, $v0, .L8003154C
    /* 21D44 80031544 00000000 */   nop
    /* 21D48 80031548 000085AC */  sw         $a1, 0x0($a0)
  .L8003154C:
    /* 21D4C 8003154C 0800E003 */  jr         $ra
    /* 21D50 80031550 00000000 */   nop
endlabel setIntrVSync
