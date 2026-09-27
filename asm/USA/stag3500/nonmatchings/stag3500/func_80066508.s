nonmatching func_80066508, 0x18

glabel func_80066508
    /* 31A8 80066508 0000828C */  lw         $v0, 0x0($a0)
    /* 31AC 8006650C 02000324 */  addiu      $v1, $zero, 0x2
    /* 31B0 80066510 040043AC */  sw         $v1, 0x4($v0)
    /* 31B4 80066514 00100324 */  addiu      $v1, $zero, 0x1000
    /* 31B8 80066518 0800E003 */  jr         $ra
    /* 31BC 8006651C 080043AC */   sw        $v1, 0x8($v0)
endlabel func_80066508
