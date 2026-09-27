nonmatching Pad_CmdConfigMode, 0x20

glabel Pad_CmdConfigMode
    /* 16D68 80026568 43000224 */  addiu      $v0, $zero, 0x43
    /* 16D6C 8002656C 370082A0 */  sb         $v0, 0x37($a0)
    /* 16D70 80026570 24008224 */  addiu      $v0, $a0, 0x24
    /* 16D74 80026574 2C0082AC */  sw         $v0, 0x2C($a0)
    /* 16D78 80026578 01000224 */  addiu      $v0, $zero, 0x1
    /* 16D7C 8002657C 240085A0 */  sb         $a1, 0x24($a0)
    /* 16D80 80026580 0800E003 */  jr         $ra
    /* 16D84 80026584 360082A0 */   sb        $v0, 0x36($a0)
endlabel Pad_CmdConfigMode
