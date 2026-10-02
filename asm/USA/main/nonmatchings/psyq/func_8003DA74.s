nonmatching func_8003DA74, 0x44

glabel func_8003DA74
    /* 2E274 8003DA74 7410628C */  lw         $v0, 0x1074($v1)
    /* 2E278 8003DA78 00000000 */  nop
    /* 2E27C 8003DA7C 80004230 */  andi       $v0, $v0, 0x80
    /* 2E280 8003DA80 0B004010 */  beqz       $v0, .L8003DAB0
    /* 2E284 8003DA84 00000000 */   nop
  .L8003DA88:
    /* 2E288 8003DA88 4410628C */  lw         $v0, 0x1044($v1)
    /* 2E28C 8003DA8C 00000000 */  nop
    /* 2E290 8003DA90 80004230 */  andi       $v0, $v0, 0x80
    /* 2E294 8003DA94 FCFF4014 */  bnez       $v0, .L8003DA88
    /* 2E298 8003DA98 00000000 */   nop
    /* 2E29C 8003DA9C 0100023C */  lui        $v0, (0x10000 >> 16)
    /* 2E2A0 8003DAA0 FCDF428C */  lw         $v0, -0x2004($v0)
    /* 2E2A4 8003DAA4 00000000 */  nop
    /* 2E2A8 8003DAA8 08004000 */  jr         $v0
    /* 2E2AC 8003DAAC 00000000 */   nop
  .L8003DAB0:
    /* 2E2B0 8003DAB0 0800E003 */  jr         $ra
    /* 2E2B4 8003DAB4 00000000 */   nop
endlabel func_8003DA74
