nonmatching Stg00_CameraTask, 0x54

glabel Stg00_CameraTask
    /* 54D0 80068830 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 54D4 80068834 1400B1AF */  sw         $s1, 0x14($sp)
    /* 54D8 80068838 21888000 */  addu       $s1, $a0, $zero
    /* 54DC 8006883C 1800BFAF */  sw         $ra, 0x18($sp)
    /* 54E0 80068840 1000B0AF */  sw         $s0, 0x10($sp)
    /* 54E4 80068844 1000228E */  lw         $v0, 0x10($s1)
    /* 54E8 80068848 00000000 */  nop
    /* 54EC 8006884C 08004014 */  bnez       $v0, .L80068870
    /* 54F0 80068850 21200000 */   addu      $a0, $zero, $zero
    /* 54F4 80068854 2C00308E */  lw         $s0, 0x2C($s1)
    /* 54F8 80068858 09AD000C */  jal        GsInitCoordinate2
    /* 54FC 8006885C 1C000526 */   addiu     $a1, $s0, 0x1C
    /* 5500 80068860 21202002 */  addu       $a0, $s1, $zero
    /* 5504 80068864 01000224 */  addiu      $v0, $zero, 0x1
    /* 5508 80068868 5145000C */  jal        Task_NextState0
    /* 550C 8006886C 840002AE */   sw        $v0, 0x84($s0)
  .L80068870:
    /* 5510 80068870 1800BF8F */  lw         $ra, 0x18($sp)
    /* 5514 80068874 1400B18F */  lw         $s1, 0x14($sp)
    /* 5518 80068878 1000B08F */  lw         $s0, 0x10($sp)
    /* 551C 8006887C 0800E003 */  jr         $ra
    /* 5520 80068880 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg00_CameraTask
