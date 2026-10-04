nonmatching Stg20_BeetlePartsDraw, 0x294

glabel Stg20_BeetlePartsDraw
    /* B3F4 8006E754 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* B3F8 8006E758 2000B4AF */  sw         $s4, 0x20($sp)
    /* B3FC 8006E75C 21A08000 */  addu       $s4, $a0, $zero
    /* B400 8006E760 2400BFAF */  sw         $ra, 0x24($sp)
    /* B404 8006E764 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* B408 8006E768 1800B2AF */  sw         $s2, 0x18($sp)
    /* B40C 8006E76C 1400B1AF */  sw         $s1, 0x14($sp)
    /* B410 8006E770 1000B0AF */  sw         $s0, 0x10($sp)
    /* B414 8006E774 2C00928E */  lw         $s2, 0x2C($s4)
    /* B418 8006E778 4FB6010C */  jal        Stg20_CalcBeetleHideMasks
    /* B41C 8006E77C 0780103C */   lui       $s0, %hi(Stg20_BodyDiagramParts)
    /* B420 8006E780 4800428E */  lw         $v0, 0x48($s2)
    /* B424 8006E784 74061026 */  addiu      $s0, $s0, %lo(Stg20_BodyDiagramParts)
    /* B428 8006E788 80100200 */  sll        $v0, $v0, 2
    /* B42C 8006E78C 21105000 */  addu       $v0, $v0, $s0
    /* B430 8006E790 0000448C */  lw         $a0, 0x0($v0)
    /* B434 8006E794 688E000C */  jal        Cd_GetFileEntry
    /* B438 8006E798 00000000 */   nop
    /* B43C 8006E79C 21884000 */  addu       $s1, $v0, $zero
    /* B440 8006E7A0 5400458E */  lw         $a1, 0x54($s2)
    /* B444 8006E7A4 4175000C */  jal        Gfx_HidePartsByMask
    /* B448 8006E7A8 21202002 */   addu      $a0, $s1, $zero
    /* B44C 8006E7AC 2176000C */  jal        Gfx_DrawParts
    /* B450 8006E7B0 21202002 */   addu      $a0, $s1, $zero
    /* B454 8006E7B4 4800428E */  lw         $v0, 0x48($s2)
    /* B458 8006E7B8 00000000 */  nop
    /* B45C 8006E7BC 80100200 */  sll        $v0, $v0, 2
    /* B460 8006E7C0 21105000 */  addu       $v0, $v0, $s0
    /* B464 8006E7C4 0C00448C */  lw         $a0, 0xC($v0)
    /* B468 8006E7C8 688E000C */  jal        Cd_GetFileEntry
    /* B46C 8006E7CC 00000000 */   nop
    /* B470 8006E7D0 21884000 */  addu       $s1, $v0, $zero
    /* B474 8006E7D4 5800458E */  lw         $a1, 0x58($s2)
    /* B478 8006E7D8 4175000C */  jal        Gfx_HidePartsByMask
    /* B47C 8006E7DC 21202002 */   addu      $a0, $s1, $zero
    /* B480 8006E7E0 2176000C */  jal        Gfx_DrawParts
    /* B484 8006E7E4 21202002 */   addu      $a0, $s1, $zero
    /* B488 8006E7E8 930C043C */  lui        $a0, (0xC93000A >> 16)
    /* B48C 8006E7EC 688E000C */  jal        Cd_GetFileEntry
    /* B490 8006E7F0 0A008434 */   ori       $a0, $a0, (0xC93000A & 0xFFFF)
    /* B494 8006E7F4 21884000 */  addu       $s1, $v0, $zero
    /* B498 8006E7F8 0000228E */  lw         $v0, 0x0($s1)
    /* B49C 8006E7FC 00000000 */  nop
    /* B4A0 8006E800 2C004010 */  beqz       $v0, .L8006E8B4
    /* B4A4 8006E804 21982002 */   addu      $s3, $s1, $zero
    /* B4A8 8006E808 03000824 */  addiu      $t0, $zero, 0x3
    /* B4AC 8006E80C 04000724 */  addiu      $a3, $zero, 0x4
    /* B4B0 8006E810 05000624 */  addiu      $a2, $zero, 0x5
    /* B4B4 8006E814 01000524 */  addiu      $a1, $zero, 0x1
    /* B4B8 8006E818 0F002426 */  addiu      $a0, $s1, 0xF
  .L8006E81C:
    /* B4BC 8006E81C 5000438E */  lw         $v1, 0x50($s2)
    /* B4C0 8006E820 00000000 */  nop
    /* B4C4 8006E824 0A006810 */  beq        $v1, $t0, .L8006E850
    /* B4C8 8006E828 04006228 */   slti      $v0, $v1, 0x4
    /* B4CC 8006E82C 05004014 */  bnez       $v0, .L8006E844
    /* B4D0 8006E830 00000000 */   nop
    /* B4D4 8006E834 0C006710 */  beq        $v1, $a3, .L8006E868
    /* B4D8 8006E838 00000000 */   nop
    /* B4DC 8006E83C 11006610 */  beq        $v1, $a2, .L8006E884
    /* B4E0 8006E840 00000000 */   nop
  .L8006E844:
    /* B4E4 8006E844 0D00828C */  lw         $v0, 0xD($a0)
    /* B4E8 8006E848 17BA0108 */  j          .L8006E85C
    /* B4EC 8006E84C 78004230 */   andi      $v0, $v0, 0x78
  .L8006E850:
    /* B4F0 8006E850 0D00828C */  lw         $v0, 0xD($a0)
    /* B4F4 8006E854 00000000 */  nop
    /* B4F8 8006E858 60004230 */  andi       $v0, $v0, 0x60
  .L8006E85C:
    /* B4FC 8006E85C 0100422C */  sltiu      $v0, $v0, 0x1
    /* B500 8006E860 22BA0108 */  j          .L8006E888
    /* B504 8006E864 000082A0 */   sb        $v0, 0x0($a0)
  .L8006E868:
    /* B508 8006E868 0D00828C */  lw         $v0, 0xD($a0)
    /* B50C 8006E86C 00000000 */  nop
    /* B510 8006E870 82110200 */  srl        $v0, $v0, 6
    /* B514 8006E874 01004238 */  xori       $v0, $v0, 0x1
    /* B518 8006E878 01004230 */  andi       $v0, $v0, 0x1
    /* B51C 8006E87C 22BA0108 */  j          .L8006E888
    /* B520 8006E880 000082A0 */   sb        $v0, 0x0($a0)
  .L8006E884:
    /* B524 8006E884 000085A0 */  sb         $a1, 0x0($a0)
  .L8006E888:
    /* B528 8006E888 0D00828C */  lw         $v0, 0xD($a0)
    /* B52C 8006E88C 00000000 */  nop
    /* B530 8006E890 02004230 */  andi       $v0, $v0, 0x2
    /* B534 8006E894 02004010 */  beqz       $v0, .L8006E8A0
    /* B538 8006E898 00000000 */   nop
    /* B53C 8006E89C 000080A0 */  sb         $zero, 0x0($a0)
  .L8006E8A0:
    /* B540 8006E8A0 28007326 */  addiu      $s3, $s3, 0x28
    /* B544 8006E8A4 0000628E */  lw         $v0, 0x0($s3)
    /* B548 8006E8A8 00000000 */  nop
    /* B54C 8006E8AC DBFF4014 */  bnez       $v0, .L8006E81C
    /* B550 8006E8B0 28008424 */   addiu     $a0, $a0, 0x28
  .L8006E8B4:
    /* B554 8006E8B4 2176000C */  jal        Gfx_DrawParts
    /* B558 8006E8B8 21202002 */   addu      $a0, $s1, $zero
    /* B55C 8006E8BC 930C043C */  lui        $a0, (0xC930009 >> 16)
    /* B560 8006E8C0 688E000C */  jal        Cd_GetFileEntry
    /* B564 8006E8C4 09008434 */   ori       $a0, $a0, (0xC930009 & 0xFFFF)
    /* B568 8006E8C8 2176000C */  jal        Gfx_DrawParts
    /* B56C 8006E8CC 21204000 */   addu      $a0, $v0, $zero
    /* B570 8006E8D0 B801428E */  lw         $v0, 0x1B8($s2)
    /* B574 8006E8D4 00000000 */  nop
    /* B578 8006E8D8 3B004010 */  beqz       $v0, .L8006E9C8
    /* B57C 8006E8DC 00000000 */   nop
    /* B580 8006E8E0 930C043C */  lui        $a0, (0xC93000B >> 16)
    /* B584 8006E8E4 688E000C */  jal        Cd_GetFileEntry
    /* B588 8006E8E8 0B008434 */   ori       $a0, $a0, (0xC93000B & 0xFFFF)
    /* B58C 8006E8EC 21884000 */  addu       $s1, $v0, $zero
    /* B590 8006E8F0 0000228E */  lw         $v0, 0x0($s1)
    /* B594 8006E8F4 00000000 */  nop
    /* B598 8006E8F8 31004010 */  beqz       $v0, .L8006E9C0
    /* B59C 8006E8FC 21982002 */   addu      $s3, $s1, $zero
    /* B5A0 8006E900 0F003026 */  addiu      $s0, $s1, 0xF
  .L8006E904:
    /* B5A4 8006E904 0D00028E */  lw         $v0, 0xD($s0)
    /* B5A8 8006E908 00000000 */  nop
    /* B5AC 8006E90C 02004230 */  andi       $v0, $v0, 0x2
    /* B5B0 8006E910 11004010 */  beqz       $v0, .L8006E958
    /* B5B4 8006E914 26000224 */   addiu     $v0, $zero, 0x26
    /* B5B8 8006E918 BC01438E */  lw         $v1, 0x1BC($s2)
    /* B5BC 8006E91C 04000524 */  addiu      $a1, $zero, 0x4
    /* B5C0 8006E920 F5FF02A6 */  sh         $v0, -0xB($s0)
    /* B5C4 8006E924 2B180300 */  sltu       $v1, $zero, $v1
    /* B5C8 8006E928 000003A2 */  sb         $v1, 0x0($s0)
    /* B5CC 8006E92C C001438E */  lw         $v1, 0x1C0($s2)
    /* B5D0 8006E930 21300000 */  addu       $a2, $zero, $zero
    /* B5D4 8006E934 40100300 */  sll        $v0, $v1, 1
    /* B5D8 8006E938 21104300 */  addu       $v0, $v0, $v1
    /* B5DC 8006E93C 80100200 */  sll        $v0, $v0, 2
    /* B5E0 8006E940 B0FF4224 */  addiu      $v0, $v0, -0x50
    /* B5E4 8006E944 F7FF02A6 */  sh         $v0, -0x9($s0)
    /* B5E8 8006E948 2800848E */  lw         $a0, 0x28($s4)
    /* B5EC 8006E94C FB88000C */  jal        Math_CycleRange
    /* B5F0 8006E950 03000724 */   addiu     $a3, $zero, 0x3
    /* B5F4 8006E954 FDFF02A2 */  sb         $v0, -0x3($s0)
  .L8006E958:
    /* B5F8 8006E958 0D00028E */  lw         $v0, 0xD($s0)
    /* B5FC 8006E95C 00000000 */  nop
    /* B600 8006E960 04004230 */  andi       $v0, $v0, 0x4
    /* B604 8006E964 05004010 */  beqz       $v0, .L8006E97C
    /* B608 8006E968 00000000 */   nop
    /* B60C 8006E96C C401428E */  lw         $v0, 0x1C4($s2)
    /* B610 8006E970 00000000 */  nop
    /* B614 8006E974 2B100200 */  sltu       $v0, $zero, $v0
    /* B618 8006E978 000002A2 */  sb         $v0, 0x0($s0)
  .L8006E97C:
    /* B61C 8006E97C 0D00028E */  lw         $v0, 0xD($s0)
    /* B620 8006E980 00000000 */  nop
    /* B624 8006E984 08004230 */  andi       $v0, $v0, 0x8
    /* B628 8006E988 08004010 */  beqz       $v0, .L8006E9AC
    /* B62C 8006E98C 00000000 */   nop
    /* B630 8006E990 E800428E */  lw         $v0, 0xE8($s2)
    /* B634 8006E994 C401438E */  lw         $v1, 0x1C4($s2)
    /* B638 8006E998 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* B63C 8006E99C 0A006324 */  addiu      $v1, $v1, 0xA
    /* B640 8006E9A0 2A104300 */  slt        $v0, $v0, $v1
    /* B644 8006E9A4 01004238 */  xori       $v0, $v0, 0x1
    /* B648 8006E9A8 000002A2 */  sb         $v0, 0x0($s0)
  .L8006E9AC:
    /* B64C 8006E9AC 28007326 */  addiu      $s3, $s3, 0x28
    /* B650 8006E9B0 0000628E */  lw         $v0, 0x0($s3)
    /* B654 8006E9B4 00000000 */  nop
    /* B658 8006E9B8 D2FF4014 */  bnez       $v0, .L8006E904
    /* B65C 8006E9BC 28001026 */   addiu     $s0, $s0, 0x28
  .L8006E9C0:
    /* B660 8006E9C0 2176000C */  jal        Gfx_DrawParts
    /* B664 8006E9C4 21202002 */   addu      $a0, $s1, $zero
  .L8006E9C8:
    /* B668 8006E9C8 2400BF8F */  lw         $ra, 0x24($sp)
    /* B66C 8006E9CC 2000B48F */  lw         $s4, 0x20($sp)
    /* B670 8006E9D0 1C00B38F */  lw         $s3, 0x1C($sp)
    /* B674 8006E9D4 1800B28F */  lw         $s2, 0x18($sp)
    /* B678 8006E9D8 1400B18F */  lw         $s1, 0x14($sp)
    /* B67C 8006E9DC 1000B08F */  lw         $s0, 0x10($sp)
    /* B680 8006E9E0 0800E003 */  jr         $ra
    /* B684 8006E9E4 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel Stg20_BeetlePartsDraw
