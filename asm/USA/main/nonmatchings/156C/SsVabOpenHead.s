nonmatching SsVabOpenHead, 0x34

glabel SsVabOpenHead
    /* 2A244 80039A44 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2A248 80039A48 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2A24C 80039A4C 002C0500 */  sll        $a1, $a1, 16
    /* 2A250 80039A50 032C0500 */  sra        $a1, $a1, 16
    /* 2A254 80039A54 0480063C */  lui        $a2, %hi(func_80039A78)
    /* 2A258 80039A58 789AC624 */  addiu      $a2, $a2, %lo(func_80039A78)
    /* 2A25C 80039A5C D5E6000C */  jal        func_80039B54
    /* 2A260 80039A60 21380000 */   addu      $a3, $zero, $zero
    /* 2A264 80039A64 00140200 */  sll        $v0, $v0, 16
    /* 2A268 80039A68 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2A26C 80039A6C 03140200 */  sra        $v0, $v0, 16
    /* 2A270 80039A70 0800E003 */  jr         $ra
    /* 2A274 80039A74 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel SsVabOpenHead
