nonmatching Stg00_ResetToHomePos, 0x2C

glabel Stg00_ResetToHomePos
    /* 409C 800673FC 2C00838C */  lw         $v1, 0x2C($a0)
    /* 40A0 80067400 3800848C */  lw         $a0, 0x38($a0)
    /* 40A4 80067404 0400628C */  lw         $v0, 0x4($v1)
    /* 40A8 80067408 00000000 */  nop
    /* 40AC 8006740C 300082AC */  sw         $v0, 0x30($a0)
    /* 40B0 80067410 0800628C */  lw         $v0, 0x8($v1)
    /* 40B4 80067414 00000000 */  nop
    /* 40B8 80067418 340082AC */  sw         $v0, 0x34($a0)
    /* 40BC 8006741C 0C00628C */  lw         $v0, 0xC($v1)
    /* 40C0 80067420 0800E003 */  jr         $ra
    /* 40C4 80067424 380082AC */   sw        $v0, 0x38($a0)
endlabel Stg00_ResetToHomePos
