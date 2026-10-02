nonmatching def_cbsync, 0x28

glabel def_cbsync
    /* 1E4D0 8002DCD0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1E4D4 8002DCD4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1E4D8 8002DCD8 00F0043C */  lui        $a0, (0xF0000003 >> 16)
    /* 1E4DC 8002DCDC 03008434 */  ori        $a0, $a0, (0xF0000003 & 0xFFFF)
    /* 1E4E0 8002DCE0 55B7000C */  jal        DeliverEvent
    /* 1E4E4 8002DCE4 20000524 */   addiu     $a1, $zero, 0x20
    /* 1E4E8 8002DCE8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1E4EC 8002DCEC 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 1E4F0 8002DCF0 0800E003 */  jr         $ra
    /* 1E4F4 8002DCF4 00000000 */   nop
endlabel def_cbsync
