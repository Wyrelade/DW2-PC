nonmatching func_80064B94, 0x1C

glabel func_80064B94
    /* 1834 80064B94 02000224 */  addiu      $v0, $zero, 0x2
    /* 1838 80064B98 100082AC */  sw         $v0, 0x10($a0)
    /* 183C 80064B9C 140085AC */  sw         $a1, 0x14($a0)
    /* 1840 80064BA0 180080AC */  sw         $zero, 0x18($a0)
    /* 1844 80064BA4 1C0080AC */  sw         $zero, 0x1C($a0)
    /* 1848 80064BA8 0800E003 */  jr         $ra
    /* 184C 80064BAC 200086AC */   sw        $a2, 0x20($a0)
endlabel func_80064B94
