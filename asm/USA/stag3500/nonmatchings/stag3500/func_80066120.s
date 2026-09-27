nonmatching func_80066120, 0x48

glabel func_80066120
    /* 2DC0 80066120 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2DC4 80066124 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2DC8 80066128 21808000 */  addu       $s0, $a0, $zero
    /* 2DCC 8006612C 24000424 */  addiu      $a0, $zero, 0x24
    /* 2DD0 80066130 1400BFAF */  sw         $ra, 0x14($sp)
    /* 2DD4 80066134 CF8B000C */  jal        Mem_Alloc
    /* 2DD8 80066138 02000524 */   addiu     $a1, $zero, 0x2
    /* 2DDC 8006613C 21204000 */  addu       $a0, $v0, $zero
    /* 2DE0 80066140 24000524 */  addiu      $a1, $zero, 0x24
    /* 2DE4 80066144 E38B000C */  jal        Mem_Zero
    /* 2DE8 80066148 000004AE */   sw        $a0, 0x0($s0)
    /* 2DEC 8006614C 0000038E */  lw         $v1, 0x0($s0)
    /* 2DF0 80066150 00100224 */  addiu      $v0, $zero, 0x1000
    /* 2DF4 80066154 080062AC */  sw         $v0, 0x8($v1)
    /* 2DF8 80066158 1400BF8F */  lw         $ra, 0x14($sp)
    /* 2DFC 8006615C 1000B08F */  lw         $s0, 0x10($sp)
    /* 2E00 80066160 0800E003 */  jr         $ra
    /* 2E04 80066164 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80066120
