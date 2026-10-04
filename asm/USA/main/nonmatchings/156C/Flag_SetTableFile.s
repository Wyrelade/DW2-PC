nonmatching Flag_SetTableFile, 0xC

glabel Flag_SetTableFile
    /* EA8C 8001E28C 0680023C */  lui        $v0, %hi(Flag_EntryIter)
    /* EA90 8001E290 0800E003 */  jr         $ra
    /* EA94 8001E294 60D544AC */   sw        $a0, %lo(Flag_EntryIter)($v0)
endlabel Flag_SetTableFile
