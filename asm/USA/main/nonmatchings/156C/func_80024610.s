nonmatching func_80024610, 0x44

glabel func_80024610
    /* 14E10 80024610 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 14E14 80024614 1000BFAF */  sw         $ra, 0x10($sp)
    /* 14E18 80024618 F19B000C */  jal        EnterCriticalSection
    /* 14E1C 8002461C 00000000 */   nop
    /* 14E20 80024620 03000424 */  addiu      $a0, $zero, 0x3
    /* 14E24 80024624 019C000C */  jal        ChangeClearRCnt
    /* 14E28 80024628 01000524 */   addiu     $a1, $zero, 0x1
    /* 14E2C 8002462C 0580053C */  lui        $a1, %hi(D_80048E78)
    /* 14E30 80024630 788EA524 */  addiu      $a1, $a1, %lo(D_80048E78)
    /* 14E34 80024634 FD9B000C */  jal        SysDeqIntRP
    /* 14E38 80024638 02000424 */   addiu     $a0, $zero, 0x2
    /* 14E3C 8002463C F59B000C */  jal        ExitCriticalSection
    /* 14E40 80024640 00000000 */   nop
    /* 14E44 80024644 1000BF8F */  lw         $ra, 0x10($sp)
    /* 14E48 80024648 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 14E4C 8002464C 0800E003 */  jr         $ra
    /* 14E50 80024650 00000000 */   nop
endlabel func_80024610
