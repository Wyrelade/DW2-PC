nonmatching func_8006E978, 0x1AC

glabel func_8006E978
    /* B618 8006E978 88FFBD27 */  addiu      $sp, $sp, -0x78
    /* B61C 8006E97C 6800B4AF */  sw         $s4, 0x68($sp)
    /* B620 8006E980 21A08000 */  addu       $s4, $a0, $zero
    /* B624 8006E984 5C00B1AF */  sw         $s1, 0x5C($sp)
    /* B628 8006E988 2188A000 */  addu       $s1, $a1, $zero
    /* B62C 8006E98C 21280000 */  addu       $a1, $zero, $zero
    /* B630 8006E990 3000A627 */  addiu      $a2, $sp, 0x30
    /* B634 8006E994 6000B2AF */  sw         $s2, 0x60($sp)
    /* B638 8006E998 2190A000 */  addu       $s2, $a1, $zero
    /* B63C 8006E99C 7000BFAF */  sw         $ra, 0x70($sp)
    /* B640 8006E9A0 6C00B5AF */  sw         $s5, 0x6C($sp)
    /* B644 8006E9A4 6400B3AF */  sw         $s3, 0x64($sp)
    /* B648 8006E9A8 5800B0AF */  sw         $s0, 0x58($sp)
    /* B64C 8006E9AC 2C00938E */  lw         $s3, 0x2C($s4)
    /* B650 8006E9B0 00000000 */  nop
    /* B654 8006E9B4 2C00648E */  lw         $a0, 0x2C($s3)
    /* B658 8006E9B8 3400958E */  lw         $s5, 0x34($s4)
    /* B65C 8006E9BC A97B000C */  jal        Skill_GetFxSet
    /* B660 8006E9C0 3800A727 */   addiu     $a3, $sp, 0x38
    /* B664 8006E9C4 4000B027 */  addiu      $s0, $sp, 0x40
    /* B668 8006E9C8 0C00848E */  lw         $a0, 0xC($s4)
    /* B66C 8006E9CC F979000C */  jal        Digi_GetCastFxOffsets
    /* B670 8006E9D0 21280002 */   addu      $a1, $s0, $zero
    /* B674 8006E9D4 40101100 */  sll        $v0, $s1, 1
    /* B678 8006E9D8 21105100 */  addu       $v0, $v0, $s1
    /* B67C 8006E9DC 40100200 */  sll        $v0, $v0, 1
    /* B680 8006E9E0 21800202 */  addu       $s0, $s0, $v0
    /* B684 8006E9E4 40181200 */  sll        $v1, $s2, 1
  .L8006E9E8:
    /* B688 8006E9E8 2110A303 */  addu       $v0, $sp, $v1
    /* B68C 8006E9EC 30004284 */  lh         $v0, 0x30($v0)
    /* B690 8006E9F0 00000000 */  nop
    /* B694 8006E9F4 3E004010 */  beqz       $v0, .L8006EAF0
    /* B698 8006E9F8 00000000 */   nop
    /* B69C 8006E9FC 1000A2AF */  sw         $v0, 0x10($sp)
    /* B6A0 8006EA00 2110A303 */  addu       $v0, $sp, $v1
    /* B6A4 8006EA04 38004284 */  lh         $v0, 0x38($v0)
    /* B6A8 8006EA08 00000000 */  nop
    /* B6AC 8006EA0C 1400A2AF */  sw         $v0, 0x14($sp)
    /* B6B0 8006EA10 1000668E */  lw         $a2, 0x10($s3)
    /* B6B4 8006EA14 00000000 */  nop
    /* B6B8 8006EA18 2400A6AF */  sw         $a2, 0x24($sp)
    /* B6BC 8006EA1C 0400638E */  lw         $v1, 0x4($s3)
    /* B6C0 8006EA20 00000000 */  nop
    /* B6C4 8006EA24 1800A3AF */  sw         $v1, 0x18($sp)
    /* B6C8 8006EA28 0800648E */  lw         $a0, 0x8($s3)
    /* B6CC 8006EA2C 00000000 */  nop
    /* B6D0 8006EA30 1C00A4AF */  sw         $a0, 0x1C($sp)
    /* B6D4 8006EA34 0C00658E */  lw         $a1, 0xC($s3)
    /* B6D8 8006EA38 78000224 */  addiu      $v0, $zero, 0x78
    /* B6DC 8006EA3C 2800A2AF */  sw         $v0, 0x28($sp)
    /* B6E0 8006EA40 01000224 */  addiu      $v0, $zero, 0x1
    /* B6E4 8006EA44 0F004212 */  beq        $s2, $v0, .L8006EA84
    /* B6E8 8006EA48 2000A5AF */   sw        $a1, 0x20($sp)
    /* B6EC 8006EA4C 0200422A */  slti       $v0, $s2, 0x2
    /* B6F0 8006EA50 22004010 */  beqz       $v0, .L8006EADC
    /* B6F4 8006EA54 07000424 */   addiu     $a0, $zero, 0x7
    /* B6F8 8006EA58 21004016 */  bnez       $s2, .L8006EAE0
    /* B6FC 8006EA5C 80281200 */   sll       $a1, $s2, 2
    /* B700 8006EA60 0C00848E */  lw         $a0, 0xC($s4)
    /* B704 8006EA64 E779000C */  jal        func_8001E79C
    /* B708 8006EA68 00000000 */   nop
    /* B70C 8006EA6C 1C00A38F */  lw         $v1, 0x1C($sp)
    /* B710 8006EA70 00000000 */  nop
    /* B714 8006EA74 80FD6324 */  addiu      $v1, $v1, -0x280
    /* B718 8006EA78 23186200 */  subu       $v1, $v1, $v0
    /* B71C 8006EA7C B6BA0108 */  j          .L8006EAD8
    /* B720 8006EA80 1C00A3AF */   sw        $v1, 0x1C($sp)
  .L8006EA84:
    /* B724 8006EA84 02000286 */  lh         $v0, 0x2($s0)
    /* B728 8006EA88 00000000 */  nop
    /* B72C 8006EA8C 23108200 */  subu       $v0, $a0, $v0
    /* B730 8006EA90 0900C014 */  bnez       $a2, .L8006EAB8
    /* B734 8006EA94 1C00A2AF */   sw        $v0, 0x1C($sp)
    /* B738 8006EA98 00000286 */  lh         $v0, 0x0($s0)
    /* B73C 8006EA9C 00000000 */  nop
    /* B740 8006EAA0 21106200 */  addu       $v0, $v1, $v0
    /* B744 8006EAA4 1800A2AF */  sw         $v0, 0x18($sp)
    /* B748 8006EAA8 04000386 */  lh         $v1, 0x4($s0)
    /* B74C 8006EAAC 00FFA224 */  addiu      $v0, $a1, -0x100
    /* B750 8006EAB0 B5BA0108 */  j          .L8006EAD4
    /* B754 8006EAB4 23104300 */   subu      $v0, $v0, $v1
  .L8006EAB8:
    /* B758 8006EAB8 00000286 */  lh         $v0, 0x0($s0)
    /* B75C 8006EABC 00000000 */  nop
    /* B760 8006EAC0 23106200 */  subu       $v0, $v1, $v0
    /* B764 8006EAC4 1800A2AF */  sw         $v0, 0x18($sp)
    /* B768 8006EAC8 04000386 */  lh         $v1, 0x4($s0)
    /* B76C 8006EACC 0001A224 */  addiu      $v0, $a1, 0x100
    /* B770 8006EAD0 21104300 */  addu       $v0, $v0, $v1
  .L8006EAD4:
    /* B774 8006EAD4 2000A2AF */  sw         $v0, 0x20($sp)
  .L8006EAD8:
    /* B778 8006EAD8 07000424 */  addiu      $a0, $zero, 0x7
  .L8006EADC:
    /* B77C 8006EADC 80281200 */  sll        $a1, $s2, 2
  .L8006EAE0:
    /* B780 8006EAE0 0400A524 */  addiu      $a1, $a1, 0x4
    /* B784 8006EAE4 2128A502 */  addu       $a1, $s5, $a1
    /* B788 8006EAE8 1F44000C */  jal        Task_Create
    /* B78C 8006EAEC 1000A627 */   addiu     $a2, $sp, 0x10
  .L8006EAF0:
    /* B790 8006EAF0 01005226 */  addiu      $s2, $s2, 0x1
    /* B794 8006EAF4 0300422A */  slti       $v0, $s2, 0x3
    /* B798 8006EAF8 BBFF4014 */  bnez       $v0, .L8006E9E8
    /* B79C 8006EAFC 40181200 */   sll       $v1, $s2, 1
    /* B7A0 8006EB00 7000BF8F */  lw         $ra, 0x70($sp)
    /* B7A4 8006EB04 6C00B58F */  lw         $s5, 0x6C($sp)
    /* B7A8 8006EB08 6800B48F */  lw         $s4, 0x68($sp)
    /* B7AC 8006EB0C 6400B38F */  lw         $s3, 0x64($sp)
    /* B7B0 8006EB10 6000B28F */  lw         $s2, 0x60($sp)
    /* B7B4 8006EB14 5C00B18F */  lw         $s1, 0x5C($sp)
    /* B7B8 8006EB18 5800B08F */  lw         $s0, 0x58($sp)
    /* B7BC 8006EB1C 0800E003 */  jr         $ra
    /* B7C0 8006EB20 7800BD27 */   addiu     $sp, $sp, 0x78
endlabel func_8006E978
