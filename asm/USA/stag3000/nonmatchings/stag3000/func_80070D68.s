nonmatching func_80070D68, 0x24

glabel func_80070D68
    /* DA08 80070D68 2C00838C */  lw         $v1, 0x2C($a0)
    /* DA0C 80070D6C 0000A28C */  lw         $v0, 0x0($a1)
    /* DA10 80070D70 00000000 */  nop
    /* DA14 80070D74 000062AC */  sw         $v0, 0x0($v1)
    /* DA18 80070D78 0000A28C */  lw         $v0, 0x0($a1)
    /* DA1C 80070D7C 00000000 */  nop
    /* DA20 80070D80 0800428C */  lw         $v0, 0x8($v0)
    /* DA24 80070D84 0800E003 */  jr         $ra
    /* DA28 80070D88 080082AC */   sw        $v0, 0x8($a0)
endlabel func_80070D68
