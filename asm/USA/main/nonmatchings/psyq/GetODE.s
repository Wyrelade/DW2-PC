nonmatching GetODE, 0x30

glabel GetODE
    /* 189DC 800281DC 0580023C */  lui        $v0, %hi(D_80048F08)
    /* 189E0 800281E0 088F428C */  lw         $v0, %lo(D_80048F08)($v0)
    /* 189E4 800281E4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 189E8 800281E8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 189EC 800281EC 3800428C */  lw         $v0, 0x38($v0)
    /* 189F0 800281F0 00000000 */  nop
    /* 189F4 800281F4 09F84000 */  jalr       $v0
    /* 189F8 800281F8 00000000 */   nop
    /* 189FC 800281FC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 18A00 80028200 C2170200 */  srl        $v0, $v0, 31
    /* 18A04 80028204 0800E003 */  jr         $ra
    /* 18A08 80028208 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel GetODE
