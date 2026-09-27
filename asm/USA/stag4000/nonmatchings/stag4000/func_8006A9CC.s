nonmatching func_8006A9CC, 0x17C

glabel func_8006A9CC
    /* 766C 8006A9CC D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 7670 8006A9D0 1400B1AF */  sw         $s1, 0x14($sp)
    /* 7674 8006A9D4 21888000 */  addu       $s1, $a0, $zero
    /* 7678 8006A9D8 01000224 */  addiu      $v0, $zero, 0x1
    /* 767C 8006A9DC 2000BFAF */  sw         $ra, 0x20($sp)
    /* 7680 8006A9E0 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 7684 8006A9E4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 7688 8006A9E8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 768C 8006A9EC 2C00328E */  lw         $s2, 0x2C($s1)
    /* 7690 8006A9F0 1800238E */  lw         $v1, 0x18($s1)
    /* 7694 8006A9F4 3C00308E */  lw         $s0, 0x3C($s1)
    /* 7698 8006A9F8 2C00538E */  lw         $s3, 0x2C($s2)
    /* 769C 8006A9FC 2C006210 */  beq        $v1, $v0, .L8006AAB0
    /* 76A0 8006AA00 02006228 */   slti      $v0, $v1, 0x2
    /* 76A4 8006AA04 04004014 */  bnez       $v0, .L8006AA18
    /* 76A8 8006AA08 0580023C */   lui       $v0, %hi(D_8005071C)
    /* 76AC 8006AA0C 02000224 */  addiu      $v0, $zero, 0x2
    /* 76B0 8006AA10 33006210 */  beq        $v1, $v0, .L8006AAE0
    /* 76B4 8006AA14 0580023C */   lui       $v0, %hi(D_8005071C)
  .L8006AA18:
    /* 76B8 8006AA18 1C07428C */  lw         $v0, %lo(D_8005071C)($v0)
    /* 76BC 8006AA1C 00000000 */  nop
    /* 76C0 8006AA20 01004390 */  lbu        $v1, 0x1($v0)
    /* 76C4 8006AA24 02000224 */  addiu      $v0, $zero, 0x2
    /* 76C8 8006AA28 06006214 */  bne        $v1, $v0, .L8006AA44
    /* 76CC 8006AA2C 03000224 */   addiu     $v0, $zero, 0x3
    /* 76D0 8006AA30 23000424 */  addiu      $a0, $zero, 0x23
    /* 76D4 8006AA34 A369000C */  jal        Snd_PlayById
    /* 76D8 8006AA38 21280000 */   addu      $a1, $zero, $zero
    /* 76DC 8006AA3C 98AA0108 */  j          .L8006AA60
    /* 76E0 8006AA40 360040A6 */   sh        $zero, 0x36($s2)
  .L8006AA44:
    /* 76E4 8006AA44 02006214 */  bne        $v1, $v0, .L8006AA50
    /* 76E8 8006AA48 1F000424 */   addiu     $a0, $zero, 0x1F
    /* 76EC 8006AA4C 18000424 */  addiu      $a0, $zero, 0x18
  .L8006AA50:
    /* 76F0 8006AA50 A369000C */  jal        Snd_PlayById
    /* 76F4 8006AA54 21280000 */   addu      $a1, $zero, $zero
    /* 76F8 8006AA58 01000224 */  addiu      $v0, $zero, 0x1
    /* 76FC 8006AA5C 360042A6 */  sh         $v0, 0x36($s2)
  .L8006AA60:
    /* 7700 8006AA60 21202002 */  addu       $a0, $s1, $zero
    /* 7704 8006AA64 01000224 */  addiu      $v0, $zero, 0x1
    /* 7708 8006AA68 340002A6 */  sh         $v0, 0x34($s0)
    /* 770C 8006AA6C 20000224 */  addiu      $v0, $zero, 0x20
    /* 7710 8006AA70 360002A6 */  sh         $v0, 0x36($s0)
    /* 7714 8006AA74 0680023C */  lui        $v0, %hi(D_80063438)
    /* 7718 8006AA78 38344924 */  addiu      $t1, $v0, %lo(D_80063438)
    /* 771C 8006AA7C 03002689 */  lwl        $a2, 0x3($t1)
    /* 7720 8006AA80 00002699 */  lwr        $a2, 0x0($t1)
    /* 7724 8006AA84 00000000 */  nop
    /* 7728 8006AA88 3B0006AA */  swl        $a2, 0x3B($s0)
    /* 772C 8006AA8C 380006BA */  swr        $a2, 0x38($s0)
    /* 7730 8006AA90 37B9010C */  jal        func_8006E4DC
    /* 7734 8006AA94 28000524 */   addiu     $a1, $zero, 0x28
    /* 7738 8006AA98 0000628E */  lw         $v0, 0x0($s3)
    /* 773C 8006AA9C 21202002 */  addu       $a0, $s1, $zero
    /* 7740 8006AAA0 80004234 */  ori        $v0, $v0, 0x80
    /* 7744 8006AAA4 000062AE */  sw         $v0, 0x0($s3)
    /* 7748 8006AAA8 B6AA0108 */  j          .L8006AAD8
    /* 774C 8006AAAC 260040A2 */   sb        $zero, 0x26($s2)
  .L8006AAB0:
    /* 7750 8006AAB0 1C00228E */  lw         $v0, 0x1C($s1)
    /* 7754 8006AAB4 00000000 */  nop
    /* 7758 8006AAB8 21184000 */  addu       $v1, $v0, $zero
    /* 775C 8006AABC 01004224 */  addiu      $v0, $v0, 0x1
    /* 7760 8006AAC0 3C006328 */  slti       $v1, $v1, 0x3C
    /* 7764 8006AAC4 06006014 */  bnez       $v1, .L8006AAE0
    /* 7768 8006AAC8 1C0022AE */   sw        $v0, 0x1C($s1)
    /* 776C 8006AACC 3C71000C */  jal        Gfx_FadeOutToBlack
    /* 7770 8006AAD0 08000424 */   addiu     $a0, $zero, 0x8
    /* 7774 8006AAD4 21202002 */  addu       $a0, $s1, $zero
  .L8006AAD8:
    /* 7778 8006AAD8 6045000C */  jal        Task_NextState2
    /* 777C 8006AADC 00000000 */   nop
  .L8006AAE0:
    /* 7780 8006AAE0 3800628E */  lw         $v0, 0x38($s3)
    /* 7784 8006AAE4 00000000 */  nop
    /* 7788 8006AAE8 AFFF4224 */  addiu      $v0, $v0, -0x51
    /* 778C 8006AAEC 02004104 */  bgez       $v0, .L8006AAF8
    /* 7790 8006AAF0 00000000 */   nop
    /* 7794 8006AAF4 21100000 */  addu       $v0, $zero, $zero
  .L8006AAF8:
    /* 7798 8006AAF8 380062AE */  sw         $v0, 0x38($s3)
    /* 779C 8006AAFC 400062AE */  sw         $v0, 0x40($s3)
    /* 77A0 8006AB00 38000392 */  lbu        $v1, 0x38($s0)
    /* 77A4 8006AB04 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 77A8 8006AB08 08006210 */  beq        $v1, $v0, .L8006AB2C
    /* 77AC 8006AB0C 01006224 */   addiu     $v0, $v1, 0x1
    /* 77B0 8006AB10 380002A2 */  sb         $v0, 0x38($s0)
    /* 77B4 8006AB14 39000292 */  lbu        $v0, 0x39($s0)
    /* 77B8 8006AB18 3A000392 */  lbu        $v1, 0x3A($s0)
    /* 77BC 8006AB1C 01004224 */  addiu      $v0, $v0, 0x1
    /* 77C0 8006AB20 01006324 */  addiu      $v1, $v1, 0x1
    /* 77C4 8006AB24 390002A2 */  sb         $v0, 0x39($s0)
    /* 77C8 8006AB28 3A0003A2 */  sb         $v1, 0x3A($s0)
  .L8006AB2C:
    /* 77CC 8006AB2C 2000BF8F */  lw         $ra, 0x20($sp)
    /* 77D0 8006AB30 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 77D4 8006AB34 1800B28F */  lw         $s2, 0x18($sp)
    /* 77D8 8006AB38 1400B18F */  lw         $s1, 0x14($sp)
    /* 77DC 8006AB3C 1000B08F */  lw         $s0, 0x10($sp)
    /* 77E0 8006AB40 0800E003 */  jr         $ra
    /* 77E4 8006AB44 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8006A9CC
