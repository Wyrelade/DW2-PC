nonmatching func_80067530, 0x1C

glabel func_80067530
    /* 41D0 80067530 02000224 */  addiu      $v0, $zero, 0x2
    /* 41D4 80067534 100082AC */  sw         $v0, 0x10($a0)
    /* 41D8 80067538 140085AC */  sw         $a1, 0x14($a0)
    /* 41DC 8006753C 180080AC */  sw         $zero, 0x18($a0)
    /* 41E0 80067540 1C0080AC */  sw         $zero, 0x1C($a0)
    /* 41E4 80067544 0800E003 */  jr         $ra
    /* 41E8 80067548 200086AC */   sw        $a2, 0x20($a0)
endlabel func_80067530
