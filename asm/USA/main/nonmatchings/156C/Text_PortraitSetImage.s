nonmatching Text_PortraitSetImage, 0xC

glabel Text_PortraitSetImage
    /* 2358 80011B58 2C00828C */  lw         $v0, 0x2C($a0)
    /* 235C 80011B5C 0800E003 */  jr         $ra
    /* 2360 80011B60 000045AC */   sw        $a1, 0x0($v0)
endlabel Text_PortraitSetImage
