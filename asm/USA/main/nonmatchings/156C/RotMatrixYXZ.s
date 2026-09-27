/* Handwritten function */
nonmatching RotMatrixYXZ, 0x1FC

glabel RotMatrixYXZ
    /* 1DF44 8002D744 04008884 */  lh         $t0, 0x4($a0)
    /* 1DF48 8002D748 25100500 */  or         $v0, $zero, $a1
    /* 1DF4C 8002D74C 0580033C */  lui        $v1, %hi(D_80049DC0)
    /* 1DF50 8002D750 C09D6324 */  addiu      $v1, $v1, %lo(D_80049DC0)
    /* 1DF54 8002D754 00008C8C */  lw         $t4, 0x0($a0)
    /* 1DF58 8002D758 C35F0800 */  sra        $t3, $t0, 31
    /* 1DF5C 8002D75C 20400B01 */  add        $t0, $t0, $t3 /* handwritten instruction */
    /* 1DF60 8002D760 26400B01 */  xor        $t0, $t0, $t3
    /* 1DF64 8002D764 80400800 */  sll        $t0, $t0, 2
    /* 1DF68 8002D768 FC3F0831 */  andi       $t0, $t0, 0x3FFC
    /* 1DF6C 8002D76C 20400301 */  add        $t0, $t0, $v1 /* handwritten instruction */
    /* 1DF70 8002D770 0000068D */  lw         $a2, 0x0($t0)
    /* 1DF74 8002D774 03440C00 */  sra        $t0, $t4, 16
    /* 1DF78 8002D778 C3570800 */  sra        $t2, $t0, 31
    /* 1DF7C 8002D77C 20400A01 */  add        $t0, $t0, $t2 /* handwritten instruction */
    /* 1DF80 8002D780 26400A01 */  xor        $t0, $t0, $t2
    /* 1DF84 8002D784 80400800 */  sll        $t0, $t0, 2
    /* 1DF88 8002D788 FC3F0831 */  andi       $t0, $t0, 0x3FFC
    /* 1DF8C 8002D78C 20400301 */  add        $t0, $t0, $v1 /* handwritten instruction */
    /* 1DF90 8002D790 0000058D */  lw         $a1, 0x0($t0)
    /* 1DF94 8002D794 00440C00 */  sll        $t0, $t4, 16
    /* 1DF98 8002D798 03440800 */  sra        $t0, $t0, 16
    /* 1DF9C 8002D79C C34F0800 */  sra        $t1, $t0, 31
    /* 1DFA0 8002D7A0 20400901 */  add        $t0, $t0, $t1 /* handwritten instruction */
    /* 1DFA4 8002D7A4 26400901 */  xor        $t0, $t0, $t1
    /* 1DFA8 8002D7A8 80400800 */  sll        $t0, $t0, 2
    /* 1DFAC 8002D7AC FC3F0831 */  andi       $t0, $t0, 0x3FFC
    /* 1DFB0 8002D7B0 20400301 */  add        $t0, $t0, $v1 /* handwritten instruction */
    /* 1DFB4 8002D7B4 0000048D */  lw         $a0, 0x0($t0)
    /* 1DFB8 8002D7B8 000C0600 */  sll        $at, $a2, 16
    /* 1DFBC 8002D7BC 03340600 */  sra        $a2, $a2, 16
    /* 1DFC0 8002D7C0 00340600 */  sll        $a2, $a2, 16
    /* 1DFC4 8002D7C4 20082B00 */  add        $at, $at, $t3 /* handwritten instruction */
    /* 1DFC8 8002D7C8 26082B00 */  xor        $at, $at, $t3
    /* 1DFCC 8002D7CC 020C0100 */  srl        $at, $at, 16
    /* 1DFD0 8002D7D0 2530C100 */  or         $a2, $a2, $at
    /* 1DFD4 8002D7D4 000C0500 */  sll        $at, $a1, 16
    /* 1DFD8 8002D7D8 032C0500 */  sra        $a1, $a1, 16
    /* 1DFDC 8002D7DC 002C0500 */  sll        $a1, $a1, 16
    /* 1DFE0 8002D7E0 20082A00 */  add        $at, $at, $t2 /* handwritten instruction */
    /* 1DFE4 8002D7E4 26082A00 */  xor        $at, $at, $t2
    /* 1DFE8 8002D7E8 020C0100 */  srl        $at, $at, 16
    /* 1DFEC 8002D7EC 2528A100 */  or         $a1, $a1, $at
    /* 1DFF0 8002D7F0 000C0400 */  sll        $at, $a0, 16
    /* 1DFF4 8002D7F4 03240400 */  sra        $a0, $a0, 16
    /* 1DFF8 8002D7F8 00240400 */  sll        $a0, $a0, 16
    /* 1DFFC 8002D7FC 20082900 */  add        $at, $at, $t1 /* handwritten instruction */
    /* 1E000 8002D800 26082900 */  xor        $at, $at, $t1
    /* 1E004 8002D804 020C0100 */  srl        $at, $at, 16
    /* 1E008 8002D808 25208100 */  or         $a0, $a0, $at
    /* 1E00C 8002D80C 03440500 */  sra        $t0, $a1, 16
    /* 1E010 8002D810 00408848 */  mtc2       $t0, $8 /* handwritten instruction */
    /* 1E014 8002D814 003C0400 */  sll        $a3, $a0, 16
    /* 1E018 8002D818 033C0700 */  sra        $a3, $a3, 16
    /* 1E01C 8002D81C 00488748 */  mtc2       $a3, $9 /* handwritten instruction */
    /* 1E020 8002D820 001C0600 */  sll        $v1, $a2, 16
    /* 1E024 8002D824 031C0300 */  sra        $v1, $v1, 16
    /* 1E028 8002D828 00508348 */  mtc2       $v1, $10 /* handwritten instruction */
    /* 1E02C 8002D82C 030C0600 */  sra        $at, $a2, 16
    /* 1E030 8002D830 00588148 */  mtc2       $at, $11 /* handwritten instruction */
    /* 1E034 8002D834 00000000 */  nop
    /* 1E038 8002D838 030C0400 */  sra        $at, $a0, 16
    /* 1E03C 8002D83C 3D00984B */  gpf        1
    /* 1E040 8002D840 18002800 */  mult       $at, $t0
    /* 1E044 8002D844 00480848 */  mfc2       $t0, $9 /* handwritten instruction */
    /* 1E048 8002D848 00500948 */  mfc2       $t1, $10 /* handwritten instruction */
    /* 1E04C 8002D84C 00740500 */  sll        $t6, $a1, 16
    /* 1E050 8002D850 00580A48 */  mfc2       $t2, $11 /* handwritten instruction */
    /* 1E054 8002D854 03740E00 */  sra        $t6, $t6, 16
    /* 1E058 8002D858 00408E48 */  mtc2       $t6, $8 /* handwritten instruction */
    /* 1E05C 8002D85C 00488748 */  mtc2       $a3, $9 /* handwritten instruction */
    /* 1E060 8002D860 00508348 */  mtc2       $v1, $10 /* handwritten instruction */
    /* 1E064 8002D864 030C0600 */  sra        $at, $a2, 16
    /* 1E068 8002D868 00588148 */  mtc2       $at, $11 /* handwritten instruction */
    /* 1E06C 8002D86C 00000000 */  nop
    /* 1E070 8002D870 3D00984B */  gpf        1
    /* 1E074 8002D874 12080000 */  mflo       $at
    /* 1E078 8002D878 030B0100 */  sra        $at, $at, 12
    /* 1E07C 8002D87C 100041A4 */  sh         $at, 0x10($v0)
    /* 1E080 8002D880 00480B48 */  mfc2       $t3, $9 /* handwritten instruction */
    /* 1E084 8002D884 00500C48 */  mfc2       $t4, $10 /* handwritten instruction */
    /* 1E088 8002D888 00580D48 */  mfc2       $t5, $11 /* handwritten instruction */
    /* 1E08C 8002D88C 030C0600 */  sra        $at, $a2, 16
    /* 1E090 8002D890 00408148 */  mtc2       $at, $8 /* handwritten instruction */
    /* 1E094 8002D894 030C0400 */  sra        $at, $a0, 16
    /* 1E098 8002D898 00488148 */  mtc2       $at, $9 /* handwritten instruction */
    /* 1E09C 8002D89C 18002E00 */  mult       $at, $t6
    /* 1E0A0 8002D8A0 00508B48 */  mtc2       $t3, $10 /* handwritten instruction */
    /* 1E0A4 8002D8A4 00588848 */  mtc2       $t0, $11 /* handwritten instruction */
    /* 1E0A8 8002D8A8 00000000 */  nop
    /* 1E0AC 8002D8AC 3D00984B */  gpf        1
    /* 1E0B0 8002D8B0 00480448 */  mfc2       $a0, $9 /* handwritten instruction */
    /* 1E0B4 8002D8B4 00500548 */  mfc2       $a1, $10 /* handwritten instruction */
    /* 1E0B8 8002D8B8 00580648 */  mfc2       $a2, $11 /* handwritten instruction */
    /* 1E0BC 8002D8BC 00408348 */  mtc2       $v1, $8 /* handwritten instruction */
    /* 1E0C0 8002D8C0 00488148 */  mtc2       $at, $9 /* handwritten instruction */
    /* 1E0C4 8002D8C4 00508B48 */  mtc2       $t3, $10 /* handwritten instruction */
    /* 1E0C8 8002D8C8 00588848 */  mtc2       $t0, $11 /* handwritten instruction */
    /* 1E0CC 8002D8CC 00000000 */  nop
    /* 1E0D0 8002D8D0 3D00984B */  gpf        1
    /* 1E0D4 8002D8D4 FFFF8430 */  andi       $a0, $a0, 0xFFFF
    /* 1E0D8 8002D8D8 22380700 */  neg        $a3, $a3 /* handwritten instruction */
    /* 1E0DC 8002D8DC 003C0700 */  sll        $a3, $a3, 16
    /* 1E0E0 8002D8E0 25208700 */  or         $a0, $a0, $a3
    /* 1E0E4 8002D8E4 080044AC */  sw         $a0, 0x8($v0)
    /* 1E0E8 8002D8E8 00480148 */  mfc2       $at, $9 /* handwritten instruction */
    /* 1E0EC 8002D8EC 2248A900 */  sub        $t1, $a1, $t1 /* handwritten instruction */
    /* 1E0F0 8002D8F0 00500E48 */  mfc2       $t6, $10 /* handwritten instruction */
    /* 1E0F4 8002D8F4 004C0900 */  sll        $t1, $t1, 16
    /* 1E0F8 8002D8F8 00580F48 */  mfc2       $t7, $11 /* handwritten instruction */
    /* 1E0FC 8002D8FC 20504E01 */  add        $t2, $t2, $t6 /* handwritten instruction */
    /* 1E100 8002D900 FFFF4A31 */  andi       $t2, $t2, 0xFFFF
    /* 1E104 8002D904 25482A01 */  or         $t1, $t1, $t2
    /* 1E108 8002D908 000049AC */  sw         $t1, 0x0($v0)
    /* 1E10C 8002D90C 12480000 */  mflo       $t1
    /* 1E110 8002D910 034B0900 */  sra        $t1, $t1, 12
    /* 1E114 8002D914 FFFF2931 */  andi       $t1, $t1, 0xFFFF
    /* 1E118 8002D918 000C0100 */  sll        $at, $at, 16
    /* 1E11C 8002D91C 25082900 */  or         $at, $at, $t1
    /* 1E120 8002D920 040041AC */  sw         $at, 0x4($v0)
    /* 1E124 8002D924 2268ED01 */  sub        $t5, $t7, $t5 /* handwritten instruction */
    /* 1E128 8002D928 FFFFAD31 */  andi       $t5, $t5, 0xFFFF
    /* 1E12C 8002D92C 2060CC00 */  add        $t4, $a2, $t4 /* handwritten instruction */
    /* 1E130 8002D930 00640C00 */  sll        $t4, $t4, 16
    /* 1E134 8002D934 25608D01 */  or         $t4, $t4, $t5
    /* 1E138 8002D938 0800E003 */  jr         $ra
    /* 1E13C 8002D93C 0C004CAC */   sw        $t4, 0xC($v0)
endlabel RotMatrixYXZ
    /* 1E140 8002D940 00000000 */  nop
