nonmatching Stg11_CloseSlotText, 0x30

glabel Stg11_CloseSlotText
    /* 1554 800648B4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1558 800648B8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 155C 800648BC 2180A000 */  addu       $s0, $a1, $zero
    /* 1560 800648C0 10000426 */  addiu      $a0, $s0, 0x10
    /* 1564 800648C4 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1568 800648C8 2C70000C */  jal        Text_CloseArray
    /* 156C 800648CC 09000524 */   addiu     $a1, $zero, 0x9
    /* 1570 800648D0 860000A6 */  sh         $zero, 0x86($s0)
    /* 1574 800648D4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1578 800648D8 1000B08F */  lw         $s0, 0x10($sp)
    /* 157C 800648DC 0800E003 */  jr         $ra
    /* 1580 800648E0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg11_CloseSlotText
