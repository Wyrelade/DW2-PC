nonmatching func_80066E30, 0x18

glabel func_80066E30
    /* 3AD0 80066E30 2C00838C */  lw         $v1, 0x2C($a0)
    /* 3AD4 80066E34 0780023C */  lui        $v0, %hi(D_80072B70)
    /* 3AD8 80066E38 702B44AC */  sw         $a0, %lo(D_80072B70)($v0)
    /* 3ADC 80066E3C 0000A28C */  lw         $v0, 0x0($a1)
    /* 3AE0 80066E40 0800E003 */  jr         $ra
    /* 3AE4 80066E44 200062AC */   sw        $v0, 0x20($v1)
endlabel func_80066E30
