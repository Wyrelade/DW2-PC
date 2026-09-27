nonmatching Pad_CmdQueryComb, 0x20

glabel Pad_CmdQueryComb
    /* 16DDC 800265DC 47000224 */  addiu      $v0, $zero, 0x47
    /* 16DE0 800265E0 370082A0 */  sb         $v0, 0x37($a0)
    /* 16DE4 800265E4 24008224 */  addiu      $v0, $a0, 0x24
    /* 16DE8 800265E8 2C0082AC */  sw         $v0, 0x2C($a0)
    /* 16DEC 800265EC 01000224 */  addiu      $v0, $zero, 0x1
    /* 16DF0 800265F0 240085A0 */  sb         $a1, 0x24($a0)
    /* 16DF4 800265F4 0800E003 */  jr         $ra
    /* 16DF8 800265F8 360082A0 */   sb        $v0, 0x36($a0)
endlabel Pad_CmdQueryComb
