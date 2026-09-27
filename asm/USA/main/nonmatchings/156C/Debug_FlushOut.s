nonmatching Debug_FlushOut, 0x3C

glabel Debug_FlushOut
    /* 1B040 8002A840 0580063C */  lui        $a2, %hi(D_80049064)
    /* 1B044 8002A844 6490C68C */  lw         $a2, %lo(D_80049064)($a2)
    /* 1B048 8002A848 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1B04C 8002A84C 0700C018 */  blez       $a2, .L8002A86C
    /* 1B050 8002A850 1000BFAF */   sw        $ra, 0x10($sp)
    /* 1B054 8002A854 0680053C */  lui        $a1, %hi(D_800618B0)
    /* 1B058 8002A858 B018A524 */  addiu      $a1, $a1, %lo(D_800618B0)
    /* 1B05C 8002A85C 69AA000C */  jal        write
    /* 1B060 8002A860 01000424 */   addiu     $a0, $zero, 0x1
    /* 1B064 8002A864 0580013C */  lui        $at, %hi(D_80049064)
    /* 1B068 8002A868 649020AC */  sw         $zero, %lo(D_80049064)($at)
  .L8002A86C:
    /* 1B06C 8002A86C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1B070 8002A870 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 1B074 8002A874 0800E003 */  jr         $ra
    /* 1B078 8002A878 00000000 */   nop
endlabel Debug_FlushOut
