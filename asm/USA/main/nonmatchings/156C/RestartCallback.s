nonmatching RestartCallback, 0x30

glabel RestartCallback
    /* 215F8 80030DF8 0580023C */  lui        $v0, %hi(D_8004FB80)
    /* 215FC 80030DFC 80FB428C */  lw         $v0, %lo(D_8004FB80)($v0)
    /* 21600 80030E00 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 21604 80030E04 1000BFAF */  sw         $ra, 0x10($sp)
    /* 21608 80030E08 1800428C */  lw         $v0, 0x18($v0)
    /* 2160C 80030E0C 00000000 */  nop
    /* 21610 80030E10 09F84000 */  jalr       $v0
    /* 21614 80030E14 00000000 */   nop
    /* 21618 80030E18 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2161C 80030E1C 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 21620 80030E20 0800E003 */  jr         $ra
    /* 21624 80030E24 00000000 */   nop
endlabel RestartCallback
