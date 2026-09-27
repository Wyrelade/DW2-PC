nonmatching Pad_CmdQueryMode, 0x20

glabel Pad_CmdQueryMode
    /* 16D9C 8002659C 4C000224 */  addiu      $v0, $zero, 0x4C
    /* 16DA0 800265A0 370082A0 */  sb         $v0, 0x37($a0)
    /* 16DA4 800265A4 24008224 */  addiu      $v0, $a0, 0x24
    /* 16DA8 800265A8 2C0082AC */  sw         $v0, 0x2C($a0)
    /* 16DAC 800265AC 01000224 */  addiu      $v0, $zero, 0x1
    /* 16DB0 800265B0 240085A0 */  sb         $a1, 0x24($a0)
    /* 16DB4 800265B4 0800E003 */  jr         $ra
    /* 16DB8 800265B8 360082A0 */   sb        $v0, 0x36($a0)
endlabel Pad_CmdQueryMode
