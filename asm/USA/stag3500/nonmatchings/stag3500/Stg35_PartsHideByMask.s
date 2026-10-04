nonmatching Stg35_PartsHideByMask, 0x3C

glabel Stg35_PartsHideByMask
    /* 306C 800663CC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3070 800663D0 1400BFAF */  sw         $ra, 0x14($sp)
    /* 3074 800663D4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3078 800663D8 0000828C */  lw         $v0, 0x0($a0)
    /* 307C 800663DC 00000000 */  nop
    /* 3080 800663E0 0000448C */  lw         $a0, 0x0($v0)
    /* 3084 800663E4 688E000C */  jal        Cd_GetFileEntry
    /* 3088 800663E8 2180A000 */   addu      $s0, $a1, $zero
    /* 308C 800663EC 21204000 */  addu       $a0, $v0, $zero
    /* 3090 800663F0 4175000C */  jal        Gfx_HidePartsByMask
    /* 3094 800663F4 21280002 */   addu      $a1, $s0, $zero
    /* 3098 800663F8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 309C 800663FC 1000B08F */  lw         $s0, 0x10($sp)
    /* 30A0 80066400 0800E003 */  jr         $ra
    /* 30A4 80066404 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg35_PartsHideByMask
