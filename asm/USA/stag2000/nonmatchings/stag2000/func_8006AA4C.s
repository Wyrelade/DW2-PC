nonmatching func_8006AA4C, 0xC0

glabel func_8006AA4C
    /* 76EC 8006AA4C 0000A284 */  lh         $v0, 0x0($a1)
    /* 76F0 8006AA50 2C00888C */  lw         $t0, 0x2C($a0)
    /* 76F4 8006AA54 21380000 */  addu       $a3, $zero, $zero
    /* 76F8 8006AA58 0C0082AC */  sw         $v0, 0xC($a0)
    /* 76FC 8006AA5C 0200A284 */  lh         $v0, 0x2($a1)
    /* 7700 8006AA60 2130A000 */  addu       $a2, $a1, $zero
    /* 7704 8006AA64 000002AD */  sw         $v0, 0x0($t0)
    /* 7708 8006AA68 1C00A28C */  lw         $v0, 0x1C($a1)
    /* 770C 8006AA6C 21180001 */  addu       $v1, $t0, $zero
    /* 7710 8006AA70 1C0002AD */  sw         $v0, 0x1C($t0)
  .L8006AA74:
    /* 7714 8006AA74 0700C988 */  lwl        $t1, 0x7($a2)
    /* 7718 8006AA78 0400C998 */  lwr        $t1, 0x4($a2)
    /* 771C 8006AA7C 00000000 */  nop
    /* 7720 8006AA80 070069A8 */  swl        $t1, 0x7($v1)
    /* 7724 8006AA84 040069B8 */  swr        $t1, 0x4($v1)
    /* 7728 8006AA88 0400C624 */  addiu      $a2, $a2, 0x4
    /* 772C 8006AA8C 0100E724 */  addiu      $a3, $a3, 0x1
    /* 7730 8006AA90 0600E228 */  slti       $v0, $a3, 0x6
    /* 7734 8006AA94 F7FF4014 */  bnez       $v0, .L8006AA74
    /* 7738 8006AA98 04006324 */   addiu     $v1, $v1, 0x4
    /* 773C 8006AA9C 01000224 */  addiu      $v0, $zero, 0x1
    /* 7740 8006AAA0 040082AC */  sw         $v0, 0x4($a0)
    /* 7744 8006AAA4 0000A384 */  lh         $v1, 0x0($a1)
    /* 7748 8006AAA8 F2010224 */  addiu      $v0, $zero, 0x1F2
    /* 774C 8006AAAC 04006214 */  bne        $v1, $v0, .L8006AAC0
    /* 7750 8006AAB0 F3010224 */   addiu     $v0, $zero, 0x1F3
    /* 7754 8006AAB4 FDFF0224 */  addiu      $v0, $zero, -0x3
    /* 7758 8006AAB8 B8AA0108 */  j          .L8006AAE0
    /* 775C 8006AABC 040082AC */   sw        $v0, 0x4($a0)
  .L8006AAC0:
    /* 7760 8006AAC0 04006214 */  bne        $v1, $v0, .L8006AAD4
    /* 7764 8006AAC4 F4010224 */   addiu     $v0, $zero, 0x1F4
    /* 7768 8006AAC8 FEFF0224 */  addiu      $v0, $zero, -0x2
    /* 776C 8006AACC B8AA0108 */  j          .L8006AAE0
    /* 7770 8006AAD0 040082AC */   sw        $v0, 0x4($a0)
  .L8006AAD4:
    /* 7774 8006AAD4 03006214 */  bne        $v1, $v0, .L8006AAE4
    /* 7778 8006AAD8 01000224 */   addiu     $v0, $zero, 0x1
    /* 777C 8006AADC 040080AC */  sw         $zero, 0x4($a0)
  .L8006AAE0:
    /* 7780 8006AAE0 01000224 */  addiu      $v0, $zero, 0x1
  .L8006AAE4:
    /* 7784 8006AAE4 640002AD */  sw         $v0, 0x64($t0)
    /* 7788 8006AAE8 0000A294 */  lhu        $v0, 0x0($a1)
    /* 778C 8006AAEC 00000000 */  nop
    /* 7790 8006AAF0 0FFE4224 */  addiu      $v0, $v0, -0x1F1
    /* 7794 8006AAF4 0300422C */  sltiu      $v0, $v0, 0x3
    /* 7798 8006AAF8 02004010 */  beqz       $v0, .L8006AB04
    /* 779C 8006AAFC 00000000 */   nop
    /* 77A0 8006AB00 640000AD */  sw         $zero, 0x64($t0)
  .L8006AB04:
    /* 77A4 8006AB04 0800E003 */  jr         $ra
    /* 77A8 8006AB08 00000000 */   nop
endlabel func_8006AA4C
