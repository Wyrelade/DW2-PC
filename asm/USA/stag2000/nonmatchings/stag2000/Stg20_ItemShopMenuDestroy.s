nonmatching Stg20_ItemShopMenuDestroy, 0x34

glabel Stg20_ItemShopMenuDestroy
    /* 8A70 8006BDD0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 8A74 8006BDD4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 8A78 8006BDD8 21808000 */  addu       $s0, $a0, $zero
    /* 8A7C 8006BDDC 1400BFAF */  sw         $ra, 0x14($sp)
    /* 8A80 8006BDE0 2C00048E */  lw         $a0, 0x2C($s0)
    /* 8A84 8006BDE4 2C70000C */  jal        Text_CloseArray
    /* 8A88 8006BDE8 02000524 */   addiu     $a1, $zero, 0x2
    /* 8A8C 8006BDEC 5C44000C */  jal        Task_DefaultDestroy
    /* 8A90 8006BDF0 21200002 */   addu      $a0, $s0, $zero
    /* 8A94 8006BDF4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 8A98 8006BDF8 1000B08F */  lw         $s0, 0x10($sp)
    /* 8A9C 8006BDFC 0800E003 */  jr         $ra
    /* 8AA0 8006BE00 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg20_ItemShopMenuDestroy
