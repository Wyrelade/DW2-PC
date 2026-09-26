nonmatching setjmp, 0x3C

glabel setjmp
    /* 21BE4 800313E4 00009FAC */  sw         $ra, 0x0($a0)
    /* 21BE8 800313E8 2C009CAC */  sw         $gp, 0x2C($a0)
    /* 21BEC 800313EC 04009DAC */  sw         $sp, 0x4($a0)
    /* 21BF0 800313F0 08009EAC */  sw         $fp, 0x8($a0)
    /* 21BF4 800313F4 0C0090AC */  sw         $s0, 0xC($a0)
    /* 21BF8 800313F8 100091AC */  sw         $s1, 0x10($a0)
    /* 21BFC 800313FC 140092AC */  sw         $s2, 0x14($a0)
    /* 21C00 80031400 180093AC */  sw         $s3, 0x18($a0)
    /* 21C04 80031404 1C0094AC */  sw         $s4, 0x1C($a0)
    /* 21C08 80031408 200095AC */  sw         $s5, 0x20($a0)
    /* 21C0C 8003140C 240096AC */  sw         $s6, 0x24($a0)
    /* 21C10 80031410 280097AC */  sw         $s7, 0x28($a0)
    /* 21C14 80031414 21100000 */  addu       $v0, $zero, $zero
    /* 21C18 80031418 0800E003 */  jr         $ra
    /* 21C1C 8003141C 00000000 */   nop
endlabel setjmp
