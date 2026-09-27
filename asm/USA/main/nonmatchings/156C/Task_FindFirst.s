nonmatching Task_FindFirst, 0x34

glabel Task_FindFirst
    /* 1D10 80011510 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1D14 80011514 0580023C */  lui        $v0, %hi(Task_FindFilter)
    /* 1D18 80011518 380944AC */  sw         $a0, %lo(Task_FindFilter)($v0)
    /* 1D1C 8001151C 38094224 */  addiu      $v0, $v0, %lo(Task_FindFilter)
    /* 1D20 80011520 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1D24 80011524 040045AC */  sw         $a1, 0x4($v0)
    /* 1D28 80011528 080046AC */  sw         $a2, 0x8($v0)
    /* 1D2C 8001152C 1045000C */  jal        Task_FindNext
    /* 1D30 80011530 0C0040AC */   sw        $zero, 0xC($v0)
    /* 1D34 80011534 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1D38 80011538 00000000 */  nop
    /* 1D3C 8001153C 0800E003 */  jr         $ra
    /* 1D40 80011540 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Task_FindFirst
