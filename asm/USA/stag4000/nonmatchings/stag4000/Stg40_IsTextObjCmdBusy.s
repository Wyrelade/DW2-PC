nonmatching Stg40_IsTextObjCmdBusy, 0x18

glabel Stg40_IsTextObjCmdBusy
    /* ED9C 800720FC 0780023C */  lui        $v0, %hi(Stg40_RootState)
    /* EDA0 80072100 602B428C */  lw         $v0, %lo(Stg40_RootState)($v0)
    /* EDA4 80072104 00000000 */  nop
    /* EDA8 80072108 80014284 */  lh         $v0, 0x180($v0)
    /* EDAC 8007210C 0800E003 */  jr         $ra
    /* EDB0 80072110 00000000 */   nop
endlabel Stg40_IsTextObjCmdBusy
