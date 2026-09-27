nonmatching Pad_SetTimeout, 0x20

glabel Pad_SetTimeout
    /* 16E10 80026610 801F023C */  lui        $v0, (0x1F801120 >> 16)
    /* 16E14 80026614 20114234 */  ori        $v0, $v0, (0x1F801120 & 0xFFFF)
    /* 16E18 80026618 00004294 */  lhu        $v0, 0x0($v0)
    /* 16E1C 8002661C 0680013C */  lui        $at, %hi(D_80060050)
    /* 16E20 80026620 500024AC */  sw         $a0, %lo(D_80060050)($at)
    /* 16E24 80026624 0680013C */  lui        $at, %hi(D_8006004C)
    /* 16E28 80026628 0800E003 */  jr         $ra
    /* 16E2C 8002662C 4C0022AC */   sw        $v0, %lo(D_8006004C)($at)
endlabel Pad_SetTimeout
