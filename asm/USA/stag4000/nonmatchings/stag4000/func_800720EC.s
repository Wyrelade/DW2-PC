nonmatching func_800720EC, 0x10

glabel func_800720EC
    /* ED8C 800720EC 0780023C */  lui        $v0, %hi(D_80072B60)
    /* ED90 800720F0 602B428C */  lw         $v0, %lo(D_80072B60)($v0)
    /* ED94 800720F4 0800E003 */  jr         $ra
    /* ED98 800720F8 800140A4 */   sh        $zero, 0x180($v0)
endlabel func_800720EC
