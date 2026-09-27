nonmatching func_80013470, 0x88

glabel func_80013470
    /* 3C70 80013470 B8FFBD27 */  addiu      $sp, $sp, -0x48
    /* 3C74 80013474 4000BFAF */  sw         $ra, 0x40($sp)
    /* 3C78 80013478 0000A28C */  lw         $v0, 0x0($a1)
    /* 3C7C 8001347C 00000000 */  nop
    /* 3C80 80013480 2400A2AF */  sw         $v0, 0x24($sp)
    /* 3C84 80013484 1000A290 */  lbu        $v0, 0x10($a1)
    /* 3C88 80013488 00000000 */  nop
    /* 3C8C 8001348C C2110200 */  srl        $v0, $v0, 7
    /* 3C90 80013490 1000A2AF */  sw         $v0, 0x10($sp)
    /* 3C94 80013494 1100A290 */  lbu        $v0, 0x11($a1)
    /* 3C98 80013498 00000000 */  nop
    /* 3C9C 8001349C 1400A2AF */  sw         $v0, 0x14($sp)
    /* 3CA0 800134A0 0C00A294 */  lhu        $v0, 0xC($a1)
    /* 3CA4 800134A4 00000000 */  nop
    /* 3CA8 800134A8 1800A2A7 */  sh         $v0, 0x18($sp)
    /* 3CAC 800134AC 0E00A294 */  lhu        $v0, 0xE($a1)
    /* 3CB0 800134B0 1C00A0AF */  sw         $zero, 0x1C($sp)
    /* 3CB4 800134B4 2000A0AF */  sw         $zero, 0x20($sp)
    /* 3CB8 800134B8 1A00A2A7 */  sh         $v0, 0x1A($sp)
    /* 3CBC 800134BC 1000A290 */  lbu        $v0, 0x10($a1)
    /* 3CC0 800134C0 00000000 */  nop
    /* 3CC4 800134C4 7F004230 */  andi       $v0, $v0, 0x7F
    /* 3CC8 800134C8 2800A2AF */  sw         $v0, 0x28($sp)
    /* 3CCC 800134CC 0400A28C */  lw         $v0, 0x4($a1)
    /* 3CD0 800134D0 00000000 */  nop
    /* 3CD4 800134D4 2C00A2AF */  sw         $v0, 0x2C($sp)
    /* 3CD8 800134D8 0800A28C */  lw         $v0, 0x8($a1)
    /* 3CDC 800134DC 1000A527 */  addiu      $a1, $sp, 0x10
    /* 3CE0 800134E0 096F000C */  jal        Text_Open
    /* 3CE4 800134E4 3000A2AF */   sw        $v0, 0x30($sp)
    /* 3CE8 800134E8 4000BF8F */  lw         $ra, 0x40($sp)
    /* 3CEC 800134EC 00000000 */  nop
    /* 3CF0 800134F0 0800E003 */  jr         $ra
    /* 3CF4 800134F4 4800BD27 */   addiu     $sp, $sp, 0x48
endlabel func_80013470
