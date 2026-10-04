nonmatching Flag_GetTableBase, 0x28

glabel Flag_GetTableBase
    /* EDC0 8001E5C0 0680023C */  lui        $v0, %hi(Flag_EntryIter)
    /* EDC4 8001E5C4 60D5448C */  lw         $a0, %lo(Flag_EntryIter)($v0)
    /* EDC8 8001E5C8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* EDCC 8001E5CC 1000BFAF */  sw         $ra, 0x10($sp)
    /* EDD0 8001E5D0 828E000C */  jal        Cd_GetFileOrNull
    /* EDD4 8001E5D4 00000000 */   nop
    /* EDD8 8001E5D8 1000BF8F */  lw         $ra, 0x10($sp)
    /* EDDC 8001E5DC 00000000 */  nop
    /* EDE0 8001E5E0 0800E003 */  jr         $ra
    /* EDE4 8001E5E4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Flag_GetTableBase
