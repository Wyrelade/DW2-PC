nonmatching Stg35_PlayHitReactSound, 0x38

glabel Stg35_PlayHitReactSound
    /* 3868 80066BC8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 386C 80066BCC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 3870 80066BD0 0C00848C */  lw         $a0, 0xC($a0)
    /* 3874 80066BD4 347A000C */  jal        func_8001E8D0
    /* 3878 80066BD8 00000000 */   nop
    /* 387C 80066BDC 02004014 */  bnez       $v0, .L80066BE8
    /* 3880 80066BE0 05020424 */   addiu     $a0, $zero, 0x205
    /* 3884 80066BE4 04020424 */  addiu      $a0, $zero, 0x204
  .L80066BE8:
    /* 3888 80066BE8 A369000C */  jal        Snd_PlayById
    /* 388C 80066BEC 21280000 */   addu      $a1, $zero, $zero
    /* 3890 80066BF0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3894 80066BF4 00000000 */  nop
    /* 3898 80066BF8 0800E003 */  jr         $ra
    /* 389C 80066BFC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg35_PlayHitReactSound
