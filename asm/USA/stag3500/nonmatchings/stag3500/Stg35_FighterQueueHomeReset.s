nonmatching Stg35_FighterQueueHomeReset, 0x10

glabel Stg35_FighterQueueHomeReset
    /* 4198 800674F8 2C00838C */  lw         $v1, 0x2C($a0)
    /* 419C 800674FC 02000224 */  addiu      $v0, $zero, 0x2
    /* 41A0 80067500 0800E003 */  jr         $ra
    /* 41A4 80067504 300062AC */   sw        $v0, 0x30($v1)
endlabel Stg35_FighterQueueHomeReset
