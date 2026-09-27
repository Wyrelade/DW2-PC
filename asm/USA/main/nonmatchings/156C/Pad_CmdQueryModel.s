nonmatching Pad_CmdQueryModel, 0x14

glabel Pad_CmdQueryModel
    /* 16D88 80026588 45000224 */  addiu      $v0, $zero, 0x45
    /* 16D8C 8002658C 370082A0 */  sb         $v0, 0x37($a0)
    /* 16D90 80026590 2C0080AC */  sw         $zero, 0x2C($a0)
    /* 16D94 80026594 0800E003 */  jr         $ra
    /* 16D98 80026598 360080A0 */   sb        $zero, 0x36($a0)
endlabel Pad_CmdQueryModel
