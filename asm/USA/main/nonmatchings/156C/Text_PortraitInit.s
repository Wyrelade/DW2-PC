nonmatching Text_PortraitInit, 0x1C

glabel Text_PortraitInit
    /* 1EB0 800116B0 2C00838C */  lw         $v1, 0x2C($a0)
    /* 1EB4 800116B4 0000A28C */  lw         $v0, 0x0($a1)
    /* 1EB8 800116B8 00000000 */  nop
    /* 1EBC 800116BC 000062AC */  sw         $v0, 0x0($v1)
    /* 1EC0 800116C0 0400A28C */  lw         $v0, 0x4($a1)
    /* 1EC4 800116C4 0800E003 */  jr         $ra
    /* 1EC8 800116C8 040062AC */   sw        $v0, 0x4($v1)
endlabel Text_PortraitInit
