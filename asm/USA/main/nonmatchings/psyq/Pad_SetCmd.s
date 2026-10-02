nonmatching Pad_SetCmd, 0x10

glabel Pad_SetCmd
    /* 164B8 80025CB8 370085A0 */  sb         $a1, 0x37($a0)
    /* 164BC 80025CBC 2C0086AC */  sw         $a2, 0x2C($a0)
    /* 164C0 80025CC0 0800E003 */  jr         $ra
    /* 164C4 80025CC4 360087A0 */   sb        $a3, 0x36($a0)
endlabel Pad_SetCmd
