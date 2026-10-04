nonmatching Stg30_PlayHitReactSound, 0x38

glabel Stg30_PlayHitReactSound
    /* B8FC 8006EC5C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* B900 8006EC60 1000BFAF */  sw         $ra, 0x10($sp)
    /* B904 8006EC64 0C00848C */  lw         $a0, 0xC($a0)
    /* B908 8006EC68 347A000C */  jal        func_8001E8D0
    /* B90C 8006EC6C 00000000 */   nop
    /* B910 8006EC70 02004014 */  bnez       $v0, .L8006EC7C
    /* B914 8006EC74 05020424 */   addiu     $a0, $zero, 0x205
    /* B918 8006EC78 04020424 */  addiu      $a0, $zero, 0x204
  .L8006EC7C:
    /* B91C 8006EC7C A369000C */  jal        Snd_PlayById
    /* B920 8006EC80 21280000 */   addu      $a1, $zero, $zero
    /* B924 8006EC84 1000BF8F */  lw         $ra, 0x10($sp)
    /* B928 8006EC88 00000000 */  nop
    /* B92C 8006EC8C 0800E003 */  jr         $ra
    /* B930 8006EC90 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg30_PlayHitReactSound
