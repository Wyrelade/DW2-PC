nonmatching Card_GetHwEventBits, 0x3C

glabel Card_GetHwEventBits
    /* 30998 80040198 0680023C */  lui        $v0, %hi(D_80063094)
    /* 3099C 8004019C 9430428C */  lw         $v0, %lo(D_80063094)($v0)
    /* 309A0 800401A0 0680043C */  lui        $a0, %hi(D_80063090)
    /* 309A4 800401A4 9030848C */  lw         $a0, %lo(D_80063090)($a0)
    /* 309A8 800401A8 0680033C */  lui        $v1, %hi(D_80063098)
    /* 309AC 800401AC 9830638C */  lw         $v1, %lo(D_80063098)($v1)
    /* 309B0 800401B0 40100200 */  sll        $v0, $v0, 1
    /* 309B4 800401B4 21208200 */  addu       $a0, $a0, $v0
    /* 309B8 800401B8 80180300 */  sll        $v1, $v1, 2
    /* 309BC 800401BC 0680023C */  lui        $v0, %hi(D_8006309C)
    /* 309C0 800401C0 9C30428C */  lw         $v0, %lo(D_8006309C)($v0)
    /* 309C4 800401C4 21208300 */  addu       $a0, $a0, $v1
    /* 309C8 800401C8 C0100200 */  sll        $v0, $v0, 3
    /* 309CC 800401CC 0800E003 */  jr         $ra
    /* 309D0 800401D0 21108200 */   addu      $v0, $a0, $v0
endlabel Card_GetHwEventBits
