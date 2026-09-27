nonmatching Pad_Init, 0x30

glabel Pad_Init
    /* 138AC 800230AC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 138B0 800230B0 0680043C */  lui        $a0, %hi(D_8005F6A8)
    /* 138B4 800230B4 A8F68424 */  addiu      $a0, $a0, %lo(D_8005F6A8)
    /* 138B8 800230B8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 138BC 800230BC 9591000C */  jal        PadInitDirect
    /* 138C0 800230C0 22008524 */   addiu     $a1, $a0, 0x22
    /* 138C4 800230C4 5191000C */  jal        PadStartCom
    /* 138C8 800230C8 00000000 */   nop
    /* 138CC 800230CC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 138D0 800230D0 00000000 */  nop
    /* 138D4 800230D4 0800E003 */  jr         $ra
    /* 138D8 800230D8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Pad_Init
