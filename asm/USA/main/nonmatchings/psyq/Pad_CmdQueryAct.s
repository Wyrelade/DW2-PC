nonmatching Pad_CmdQueryAct, 0x20

glabel Pad_CmdQueryAct
    /* 16DBC 800265BC 46000224 */  addiu      $v0, $zero, 0x46
    /* 16DC0 800265C0 370082A0 */  sb         $v0, 0x37($a0)
    /* 16DC4 800265C4 24008224 */  addiu      $v0, $a0, 0x24
    /* 16DC8 800265C8 2C0082AC */  sw         $v0, 0x2C($a0)
    /* 16DCC 800265CC 01000224 */  addiu      $v0, $zero, 0x1
    /* 16DD0 800265D0 240085A0 */  sb         $a1, 0x24($a0)
    /* 16DD4 800265D4 0800E003 */  jr         $ra
    /* 16DD8 800265D8 360082A0 */   sb        $v0, 0x36($a0)
endlabel Pad_CmdQueryAct
