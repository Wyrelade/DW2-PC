nonmatching AddPrim, 0x3C

glabel AddPrim
    /* 1B2F4 8002AAF4 FF00063C */  lui        $a2, (0xFFFFFF >> 16)
    /* 1B2F8 8002AAF8 FFFFC634 */  ori        $a2, $a2, (0xFFFFFF & 0xFFFF)
    /* 1B2FC 8002AAFC 00FF073C */  lui        $a3, (0xFF000000 >> 16)
    /* 1B300 8002AB00 0000A38C */  lw         $v1, 0x0($a1)
    /* 1B304 8002AB04 0000828C */  lw         $v0, 0x0($a0)
    /* 1B308 8002AB08 24186700 */  and        $v1, $v1, $a3
    /* 1B30C 8002AB0C 24104600 */  and        $v0, $v0, $a2
    /* 1B310 8002AB10 25186200 */  or         $v1, $v1, $v0
    /* 1B314 8002AB14 0000A3AC */  sw         $v1, 0x0($a1)
    /* 1B318 8002AB18 0000828C */  lw         $v0, 0x0($a0)
    /* 1B31C 8002AB1C 2428A600 */  and        $a1, $a1, $a2
    /* 1B320 8002AB20 24104700 */  and        $v0, $v0, $a3
    /* 1B324 8002AB24 25104500 */  or         $v0, $v0, $a1
    /* 1B328 8002AB28 0800E003 */  jr         $ra
    /* 1B32C 8002AB2C 000082AC */   sw        $v0, 0x0($a0)
endlabel AddPrim
    /* 1B330 8002AB30 00000000 */  nop
