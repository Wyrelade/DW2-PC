nonmatching Gfx_TexSlotTaskKill, 0x3C

glabel Gfx_TexSlotTaskKill
    /* 23B0 80011BB0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 23B4 80011BB4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 23B8 80011BB8 21808000 */  addu       $s0, $a0, $zero
    /* 23BC 80011BBC 1400BFAF */  sw         $ra, 0x14($sp)
    /* 23C0 80011BC0 2C00028E */  lw         $v0, 0x2C($s0)
    /* 23C4 80011BC4 00000000 */  nop
    /* 23C8 80011BC8 0000448C */  lw         $a0, 0x0($v0)
    /* 23CC 80011BCC A073000C */  jal        Gfx_ReleaseTexSlot
    /* 23D0 80011BD0 00000000 */   nop
    /* 23D4 80011BD4 5C44000C */  jal        Task_DefaultDestroy
    /* 23D8 80011BD8 21200002 */   addu      $a0, $s0, $zero
    /* 23DC 80011BDC 1400BF8F */  lw         $ra, 0x14($sp)
    /* 23E0 80011BE0 1000B08F */  lw         $s0, 0x10($sp)
    /* 23E4 80011BE4 0800E003 */  jr         $ra
    /* 23E8 80011BE8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Gfx_TexSlotTaskKill
