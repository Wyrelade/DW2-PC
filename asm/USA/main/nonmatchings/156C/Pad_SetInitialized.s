nonmatching Pad_SetInitialized, 0xC

glabel Pad_SetInitialized
    /* 2DE04 8003D604 0580013C */  lui        $at, %hi(D_800506B8)
    /* 2DE08 8003D608 0800E003 */  jr         $ra
    /* 2DE0C 8003D60C B80624AC */   sw        $a0, %lo(D_800506B8)($at)
endlabel Pad_SetInitialized
