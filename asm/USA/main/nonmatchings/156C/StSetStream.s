nonmatching StSetStream, 0x84

glabel StSetStream
    /* 1E864 8002E064 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1E868 8002E068 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1E86C 8002E06C 21808000 */  addu       $s0, $a0, $zero
    /* 1E870 8002E070 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1E874 8002E074 2188E000 */  addu       $s1, $a3, $zero
    /* 1E878 8002E078 1800B2AF */  sw         $s2, 0x18($sp)
    /* 1E87C 8002E07C 3000B28F */  lw         $s2, 0x30($sp)
    /* 1E880 8002E080 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 1E884 8002E084 A9B8000C */  jal        StSetMask
    /* 1E888 8002E088 01000424 */   addiu     $a0, $zero, 0x1
    /* 1E88C 8002E08C 01001032 */  andi       $s0, $s0, 0x1
    /* 1E890 8002E090 0680013C */  lui        $at, %hi(D_80061B28)
    /* 1E894 8002E094 281B20AC */  sw         $zero, %lo(D_80061B28)($at)
    /* 1E898 8002E098 0680013C */  lui        $at, %hi(D_80061B50)
    /* 1E89C 8002E09C 501B31AC */  sw         $s1, %lo(D_80061B50)($at)
    /* 1E8A0 8002E0A0 0680013C */  lui        $at, %hi(D_80061B00)
    /* 1E8A4 8002E0A4 001B30AC */  sw         $s0, %lo(D_80061B00)($at)
    /* 1E8A8 8002E0A8 0680013C */  lui        $at, %hi(D_80061B10)
    /* 1E8AC 8002E0AC 101B20AC */  sw         $zero, %lo(D_80061B10)($at)
    /* 1E8B0 8002E0B0 0680013C */  lui        $at, %hi(D_80061B08)
    /* 1E8B4 8002E0B4 081B20AC */  sw         $zero, %lo(D_80061B08)($at)
    /* 1E8B8 8002E0B8 0680013C */  lui        $at, %hi(D_80061AFC)
    /* 1E8BC 8002E0BC FC1A20A4 */  sh         $zero, %lo(D_80061AFC)($at)
    /* 1E8C0 8002E0C0 0680013C */  lui        $at, %hi(D_80061AF8)
    /* 1E8C4 8002E0C4 F81A20AC */  sw         $zero, %lo(D_80061AF8)($at)
    /* 1E8C8 8002E0C8 0680013C */  lui        $at, %hi(D_80061B54)
    /* 1E8CC 8002E0CC 541B32AC */  sw         $s2, %lo(D_80061B54)($at)
    /* 1E8D0 8002E0D0 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 1E8D4 8002E0D4 1800B28F */  lw         $s2, 0x18($sp)
    /* 1E8D8 8002E0D8 1400B18F */  lw         $s1, 0x14($sp)
    /* 1E8DC 8002E0DC 1000B08F */  lw         $s0, 0x10($sp)
    /* 1E8E0 8002E0E0 0800E003 */  jr         $ra
    /* 1E8E4 8002E0E4 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel StSetStream
    /* 1E8E8 8002E0E8 00000000 */  nop
    /* 1E8EC 8002E0EC 00000000 */  nop
    /* 1E8F0 8002E0F0 00000000 */  nop
