nonmatching Stg40_EndTextObjCmd, 0x10

glabel Stg40_EndTextObjCmd
    /* ED8C 800720EC 0780023C */  lui        $v0, %hi(Stg40_RootState)
    /* ED90 800720F0 602B428C */  lw         $v0, %lo(Stg40_RootState)($v0)
    /* ED94 800720F4 0800E003 */  jr         $ra
    /* ED98 800720F8 800140A4 */   sh        $zero, 0x180($v0)
endlabel Stg40_EndTextObjCmd
