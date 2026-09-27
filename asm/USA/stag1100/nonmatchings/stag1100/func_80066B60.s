nonmatching func_80066B60, 0xA4

glabel func_80066B60
    /* 3800 80066B60 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3804 80066B64 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3808 80066B68 21808000 */  addu       $s0, $a0, $zero
    /* 380C 80066B6C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 3810 80066B70 2C00068E */  lw         $a2, 0x2C($s0)
    /* 3814 80066B74 00000000 */  nop
    /* 3818 80066B78 A001C284 */  lh         $v0, 0x1A0($a2)
    /* 381C 80066B7C A001C394 */  lhu        $v1, 0x1A0($a2)
    /* 3820 80066B80 09004014 */  bnez       $v0, .L80066BA8
    /* 3824 80066B84 FFFF6224 */   addiu     $v0, $v1, -0x1
    /* 3828 80066B88 0B000424 */  addiu      $a0, $zero, 0xB
    /* 382C 80066B8C A369000C */  jal        Snd_PlayById
    /* 3830 80066B90 21280000 */   addu      $a1, $zero, $zero
    /* 3834 80066B94 21200002 */  addu       $a0, $s0, $zero
    /* 3838 80066B98 7045000C */  jal        Task_SetState0
    /* 383C 80066B9C 02000524 */   addiu     $a1, $zero, 0x2
    /* 3840 80066BA0 FD9A0108 */  j          .L80066BF4
    /* 3844 80066BA4 00000000 */   nop
  .L80066BA8:
    /* 3848 80066BA8 A001C2A4 */  sh         $v0, 0x1A0($a2)
    /* 384C 80066BAC 00140200 */  sll        $v0, $v0, 16
    /* 3850 80066BB0 C3130200 */  sra        $v0, $v0, 15
    /* 3854 80066BB4 2110C200 */  addu       $v0, $a2, $v0
    /* 3858 80066BB8 0B000424 */  addiu      $a0, $zero, 0xB
    /* 385C 80066BBC A2014284 */  lh         $v0, 0x1A2($v0)
    /* 3860 80066BC0 02000324 */  addiu      $v1, $zero, 0x2
    /* 3864 80066BC4 C0100200 */  sll        $v0, $v0, 3
    /* 3868 80066BC8 21104600 */  addu       $v0, $v0, $a2
    /* 386C 80066BCC 6E0043A0 */  sb         $v1, 0x6E($v0)
    /* 3870 80066BD0 A001C284 */  lh         $v0, 0x1A0($a2)
    /* 3874 80066BD4 21280000 */  addu       $a1, $zero, $zero
    /* 3878 80066BD8 40100200 */  sll        $v0, $v0, 1
    /* 387C 80066BDC 2110C200 */  addu       $v0, $a2, $v0
    /* 3880 80066BE0 A369000C */  jal        Snd_PlayById
    /* 3884 80066BE4 A20140A4 */   sh        $zero, 0x1A2($v0)
    /* 3888 80066BE8 21200002 */  addu       $a0, $s0, $zero
    /* 388C 80066BEC 7745000C */  jal        Task_SetState1
    /* 3890 80066BF0 01000524 */   addiu     $a1, $zero, 0x1
  .L80066BF4:
    /* 3894 80066BF4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 3898 80066BF8 1000B08F */  lw         $s0, 0x10($sp)
    /* 389C 80066BFC 0800E003 */  jr         $ra
    /* 38A0 80066C00 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80066B60
