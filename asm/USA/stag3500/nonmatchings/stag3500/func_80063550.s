nonmatching func_80063550, 0x34

glabel func_80063550
    /* 1F0 80063550 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1F4 80063554 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1F8 80063558 21808000 */  addu       $s0, $a0, $zero
    /* 1FC 8006355C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 200 80063560 2C00048E */  lw         $a0, 0x2C($s0)
    /* 204 80063564 5A98010C */  jal        func_80066168
    /* 208 80063568 00000000 */   nop
    /* 20C 8006356C 5C44000C */  jal        Task_DefaultDestroy
    /* 210 80063570 21200002 */   addu      $a0, $s0, $zero
    /* 214 80063574 1400BF8F */  lw         $ra, 0x14($sp)
    /* 218 80063578 1000B08F */  lw         $s0, 0x10($sp)
    /* 21C 8006357C 0800E003 */  jr         $ra
    /* 220 80063580 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80063550
