nonmatching Stg40_PlayerShowMsg, 0x80

glabel Stg40_PlayerShowMsg
    /* 4DDC 8006813C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 4DE0 80068140 1800B2AF */  sw         $s2, 0x18($sp)
    /* 4DE4 80068144 3800B28F */  lw         $s2, 0x38($sp)
    /* 4DE8 80068148 1000B0AF */  sw         $s0, 0x10($sp)
    /* 4DEC 8006814C 21808000 */  addu       $s0, $a0, $zero
    /* 4DF0 80068150 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 4DF4 80068154 3C00B38F */  lw         $s3, 0x3C($sp)
    /* 4DF8 80068158 2000B4AF */  sw         $s4, 0x20($sp)
    /* 4DFC 8006815C 21A0C000 */  addu       $s4, $a2, $zero
    /* 4E00 80068160 1400B1AF */  sw         $s1, 0x14($sp)
    /* 4E04 80068164 2400BFAF */  sw         $ra, 0x24($sp)
    /* 4E08 80068168 37B9010C */  jal        Stg40_ObjSetAnim
    /* 4E0C 8006816C 2188E000 */   addu      $s1, $a3, $zero
    /* 4E10 80068170 21200002 */  addu       $a0, $s0, $zero
    /* 4E14 80068174 7745000C */  jal        Task_SetState1
    /* 4E18 80068178 0B000524 */   addiu     $a1, $zero, 0xB
    /* 4E1C 8006817C 01000424 */  addiu      $a0, $zero, 0x1
    /* 4E20 80068180 0780023C */  lui        $v0, %hi(D_80072B60)
    /* 4E24 80068184 21282002 */  addu       $a1, $s1, $zero
    /* 4E28 80068188 602B428C */  lw         $v0, %lo(D_80072B60)($v0)
    /* 4E2C 8006818C 21304002 */  addu       $a2, $s2, $zero
    /* 4E30 80068190 21386002 */  addu       $a3, $s3, $zero
    /* 4E34 80068194 849D010C */  jal        Stg40_MsgWinOpen
    /* 4E38 80068198 380054AC */   sw        $s4, 0x38($v0)
    /* 4E3C 8006819C 2400BF8F */  lw         $ra, 0x24($sp)
    /* 4E40 800681A0 2000B48F */  lw         $s4, 0x20($sp)
    /* 4E44 800681A4 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 4E48 800681A8 1800B28F */  lw         $s2, 0x18($sp)
    /* 4E4C 800681AC 1400B18F */  lw         $s1, 0x14($sp)
    /* 4E50 800681B0 1000B08F */  lw         $s0, 0x10($sp)
    /* 4E54 800681B4 0800E003 */  jr         $ra
    /* 4E58 800681B8 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel Stg40_PlayerShowMsg
