/* Handwritten function */
nonmatching ApplyMatrixLV, 0x160

glabel ApplyMatrixLV
    /* 1D774 8002CF74 0000888C */  lw         $t0, 0x0($a0)
    /* 1D778 8002CF78 0400898C */  lw         $t1, 0x4($a0)
    /* 1D77C 8002CF7C 08008A8C */  lw         $t2, 0x8($a0)
    /* 1D780 8002CF80 0C008B8C */  lw         $t3, 0xC($a0)
    /* 1D784 8002CF84 10008C8C */  lw         $t4, 0x10($a0)
    /* 1D788 8002CF88 0000C848 */  ctc2       $t0, $0 /* handwritten instruction */
    /* 1D78C 8002CF8C 0008C948 */  ctc2       $t1, $1 /* handwritten instruction */
    /* 1D790 8002CF90 0010CA48 */  ctc2       $t2, $2 /* handwritten instruction */
    /* 1D794 8002CF94 0018CB48 */  ctc2       $t3, $3 /* handwritten instruction */
    /* 1D798 8002CF98 0020CC48 */  ctc2       $t4, $4 /* handwritten instruction */
    /* 1D79C 8002CF9C 0000A88C */  lw         $t0, 0x0($a1)
    /* 1D7A0 8002CFA0 0400A98C */  lw         $t1, 0x4($a1)
    /* 1D7A4 8002CFA4 0800AA8C */  lw         $t2, 0x8($a1)
    /* 1D7A8 8002CFA8 07000105 */  bgez       $t0, .L8002CFC8
    /* 1D7AC 8002CFAC 00000000 */   nop
    /* 1D7B0 8002CFB0 23400800 */  negu       $t0, $t0
    /* 1D7B4 8002CFB4 C35B0800 */  sra        $t3, $t0, 15
    /* 1D7B8 8002CFB8 23580B00 */  negu       $t3, $t3
    /* 1D7BC 8002CFBC FF7F0831 */  andi       $t0, $t0, 0x7FFF
    /* 1D7C0 8002CFC0 03000010 */  b          .L8002CFD0
    /* 1D7C4 8002CFC4 23400800 */   negu      $t0, $t0
  .L8002CFC8:
    /* 1D7C8 8002CFC8 C35B0800 */  sra        $t3, $t0, 15
    /* 1D7CC 8002CFCC FF7F0831 */  andi       $t0, $t0, 0x7FFF
  .L8002CFD0:
    /* 1D7D0 8002CFD0 07002105 */  bgez       $t1, .L8002CFF0
    /* 1D7D4 8002CFD4 00000000 */   nop
    /* 1D7D8 8002CFD8 23480900 */  negu       $t1, $t1
    /* 1D7DC 8002CFDC C3630900 */  sra        $t4, $t1, 15
    /* 1D7E0 8002CFE0 23600C00 */  negu       $t4, $t4
    /* 1D7E4 8002CFE4 FF7F2931 */  andi       $t1, $t1, 0x7FFF
    /* 1D7E8 8002CFE8 03000010 */  b          .L8002CFF8
    /* 1D7EC 8002CFEC 23480900 */   negu      $t1, $t1
  .L8002CFF0:
    /* 1D7F0 8002CFF0 C3630900 */  sra        $t4, $t1, 15
    /* 1D7F4 8002CFF4 FF7F2931 */  andi       $t1, $t1, 0x7FFF
  .L8002CFF8:
    /* 1D7F8 8002CFF8 07004105 */  bgez       $t2, .L8002D018
    /* 1D7FC 8002CFFC 00000000 */   nop
    /* 1D800 8002D000 23500A00 */  negu       $t2, $t2
    /* 1D804 8002D004 C36B0A00 */  sra        $t5, $t2, 15
    /* 1D808 8002D008 23680D00 */  negu       $t5, $t5
    /* 1D80C 8002D00C FF7F4A31 */  andi       $t2, $t2, 0x7FFF
    /* 1D810 8002D010 03000010 */  b          .L8002D020
    /* 1D814 8002D014 23500A00 */   negu      $t2, $t2
  .L8002D018:
    /* 1D818 8002D018 C36B0A00 */  sra        $t5, $t2, 15
    /* 1D81C 8002D01C FF7F4A31 */  andi       $t2, $t2, 0x7FFF
  .L8002D020:
    /* 1D820 8002D020 00488B48 */  mtc2       $t3, $9 /* handwritten instruction */
    /* 1D824 8002D024 00508C48 */  mtc2       $t4, $10 /* handwritten instruction */
    /* 1D828 8002D028 00588D48 */  mtc2       $t5, $11 /* handwritten instruction */
    /* 1D82C 8002D02C 00000000 */  nop
    /* 1D830 8002D030 12E0414A */  mvmva      0, 0, 3, 3, 0
    /* 1D834 8002D034 00C80B48 */  mfc2       $t3, $25 /* handwritten instruction */
    /* 1D838 8002D038 00D00C48 */  mfc2       $t4, $26 /* handwritten instruction */
    /* 1D83C 8002D03C 00D80D48 */  mfc2       $t5, $27 /* handwritten instruction */
    /* 1D840 8002D040 00488848 */  mtc2       $t0, $9 /* handwritten instruction */
    /* 1D844 8002D044 00508948 */  mtc2       $t1, $10 /* handwritten instruction */
    /* 1D848 8002D048 00588A48 */  mtc2       $t2, $11 /* handwritten instruction */
    /* 1D84C 8002D04C 00000000 */  nop
    /* 1D850 8002D050 12E0494A */  mvmva      1, 0, 3, 3, 0
    /* 1D854 8002D054 05006105 */  bgez       $t3, .L8002D06C
    /* 1D858 8002D058 00000000 */   nop
    /* 1D85C 8002D05C 23580B00 */  negu       $t3, $t3
    /* 1D860 8002D060 C0580B00 */  sll        $t3, $t3, 3
    /* 1D864 8002D064 02000010 */  b          .L8002D070
    /* 1D868 8002D068 23580B00 */   negu      $t3, $t3
  .L8002D06C:
    /* 1D86C 8002D06C C0580B00 */  sll        $t3, $t3, 3
  .L8002D070:
    /* 1D870 8002D070 05008105 */  bgez       $t4, .L8002D088
    /* 1D874 8002D074 00000000 */   nop
    /* 1D878 8002D078 23600C00 */  negu       $t4, $t4
    /* 1D87C 8002D07C C0600C00 */  sll        $t4, $t4, 3
    /* 1D880 8002D080 02000010 */  b          .L8002D08C
    /* 1D884 8002D084 23600C00 */   negu      $t4, $t4
  .L8002D088:
    /* 1D888 8002D088 C0600C00 */  sll        $t4, $t4, 3
  .L8002D08C:
    /* 1D88C 8002D08C 0500A105 */  bgez       $t5, .L8002D0A4
    /* 1D890 8002D090 00000000 */   nop
    /* 1D894 8002D094 23680D00 */  negu       $t5, $t5
    /* 1D898 8002D098 C0680D00 */  sll        $t5, $t5, 3
    /* 1D89C 8002D09C 02000010 */  b          .L8002D0A8
    /* 1D8A0 8002D0A0 23680D00 */   negu      $t5, $t5
  .L8002D0A4:
    /* 1D8A4 8002D0A4 C0680D00 */  sll        $t5, $t5, 3
  .L8002D0A8:
    /* 1D8A8 8002D0A8 00C80848 */  mfc2       $t0, $25 /* handwritten instruction */
    /* 1D8AC 8002D0AC 00D00948 */  mfc2       $t1, $26 /* handwritten instruction */
    /* 1D8B0 8002D0B0 00D80A48 */  mfc2       $t2, $27 /* handwritten instruction */
    /* 1D8B4 8002D0B4 21400B01 */  addu       $t0, $t0, $t3
    /* 1D8B8 8002D0B8 21482C01 */  addu       $t1, $t1, $t4
    /* 1D8BC 8002D0BC 21504D01 */  addu       $t2, $t2, $t5
    /* 1D8C0 8002D0C0 0000C8AC */  sw         $t0, 0x0($a2)
    /* 1D8C4 8002D0C4 0400C9AC */  sw         $t1, 0x4($a2)
    /* 1D8C8 8002D0C8 0800CAAC */  sw         $t2, 0x8($a2)
    /* 1D8CC 8002D0CC 0800E003 */  jr         $ra
    /* 1D8D0 8002D0D0 2110C000 */   addu      $v0, $a2, $zero
endlabel ApplyMatrixLV
