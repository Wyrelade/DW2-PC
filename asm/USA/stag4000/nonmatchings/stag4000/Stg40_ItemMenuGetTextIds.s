nonmatching Stg40_ItemMenuGetTextIds, 0x18

glabel Stg40_ItemMenuGetTextIds
    /* 3AB8 80066E18 0780023C */  lui        $v0, %hi(Stg40_ItemMenuTask)
    /* 3ABC 80066E1C 702B428C */  lw         $v0, %lo(Stg40_ItemMenuTask)($v0)
    /* 3AC0 80066E20 00000000 */  nop
    /* 3AC4 80066E24 2C00428C */  lw         $v0, 0x2C($v0)
    /* 3AC8 80066E28 0800E003 */  jr         $ra
    /* 3ACC 80066E2C 28004224 */   addiu     $v0, $v0, 0x28
endlabel Stg40_ItemMenuGetTextIds
