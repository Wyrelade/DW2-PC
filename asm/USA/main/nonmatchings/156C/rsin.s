nonmatching rsin, 0x3C

glabel rsin
    /* 1D2F4 8002CAF4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1D2F8 8002CAF8 05008004 */  bltz       $a0, .L8002CB10
    /* 1D2FC 8002CAFC 1000BFAF */   sw        $ra, 0x10($sp)
    /* 1D300 8002CB00 CCB2000C */  jal        sin_1
    /* 1D304 8002CB04 FF0F8430 */   andi      $a0, $a0, 0xFFF
    /* 1D308 8002CB08 C8B20008 */  j          .L8002CB20
    /* 1D30C 8002CB0C 00000000 */   nop
  .L8002CB10:
    /* 1D310 8002CB10 23200400 */  negu       $a0, $a0
    /* 1D314 8002CB14 CCB2000C */  jal        sin_1
    /* 1D318 8002CB18 FF0F8430 */   andi      $a0, $a0, 0xFFF
    /* 1D31C 8002CB1C 23100200 */  negu       $v0, $v0
  .L8002CB20:
    /* 1D320 8002CB20 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1D324 8002CB24 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 1D328 8002CB28 0800E003 */  jr         $ra
    /* 1D32C 8002CB2C 00000000 */   nop
endlabel rsin
