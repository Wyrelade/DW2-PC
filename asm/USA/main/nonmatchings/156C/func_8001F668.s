nonmatching func_8001F668, 0x2A4

glabel func_8001F668
    /* FE68 8001F668 48FFBD27 */  addiu      $sp, $sp, -0xB8
    /* FE6C 8001F66C 9800B2AF */  sw         $s2, 0x98($sp)
    /* FE70 8001F670 21908000 */  addu       $s2, $a0, $zero
    /* FE74 8001F674 A800B6AF */  sw         $s6, 0xA8($sp)
    /* FE78 8001F678 21B0A000 */  addu       $s6, $a1, $zero
    /* FE7C 8001F67C B000BEAF */  sw         $fp, 0xB0($sp)
    /* FE80 8001F680 21F0C000 */  addu       $fp, $a2, $zero
    /* FE84 8001F684 9400B1AF */  sw         $s1, 0x94($sp)
    /* FE88 8001F688 2188E000 */  addu       $s1, $a3, $zero
    /* FE8C 8001F68C 21200000 */  addu       $a0, $zero, $zero
    /* FE90 8001F690 1800A527 */  addiu      $a1, $sp, 0x18
    /* FE94 8001F694 B400BFAF */  sw         $ra, 0xB4($sp)
    /* FE98 8001F698 AC00B7AF */  sw         $s7, 0xAC($sp)
    /* FE9C 8001F69C A400B5AF */  sw         $s5, 0xA4($sp)
    /* FEA0 8001F6A0 A000B4AF */  sw         $s4, 0xA0($sp)
    /* FEA4 8001F6A4 9C00B3AF */  sw         $s3, 0x9C($sp)
    /* FEA8 8001F6A8 09AD000C */  jal        GsInitCoordinate2
    /* FEAC 8001F6AC 9000B0AF */   sw        $s0, 0x90($sp)
    /* FEB0 8001F6B0 1800A427 */  addiu      $a0, $sp, 0x18
    /* FEB4 8001F6B4 6800B027 */  addiu      $s0, $sp, 0x68
    /* FEB8 8001F6B8 65AF000C */  jal        GsGetLs
    /* FEBC 8001F6BC 21280002 */   addu      $a1, $s0, $zero
    /* FEC0 8001F6C0 25AD000C */  jal        GsSetLsMatrix
    /* FEC4 8001F6C4 21200002 */   addu      $a0, $s0, $zero
    /* FEC8 8001F6C8 0680023C */  lui        $v0, %hi(D_8005F770)
    /* FECC 8001F6CC 70F75724 */  addiu      $s7, $v0, %lo(D_8005F770)
    /* FED0 8001F6D0 80881100 */  sll        $s1, $s1, 2
    /* FED4 8001F6D4 21883702 */  addu       $s1, $s1, $s7
    /* FED8 8001F6D8 2C00F38E */  lw         $s3, 0x2C($s7)
    /* FEDC 8001F6DC 3801348E */  lw         $s4, 0x138($s1)
    /* FEE0 8001F6E0 0300498A */  lwl        $t1, 0x3($s2)
    /* FEE4 8001F6E4 0000499A */  lwr        $t1, 0x0($s2)
    /* FEE8 8001F6E8 00000000 */  nop
    /* FEEC 8001F6EC 070069AA */  swl        $t1, 0x7($s3)
    /* FEF0 8001F6F0 040069BA */  swr        $t1, 0x4($s3)
    /* FEF4 8001F6F4 CDAA000C */  jal        SetPolyF4
    /* FEF8 8001F6F8 21206002 */   addu      $a0, $s3, $zero
    /* FEFC 8001F6FC 0400C233 */  andi       $v0, $fp, 0x4
    /* FF00 8001F700 05004010 */  beqz       $v0, .L8001F718
    /* FF04 8001F704 21A86002 */   addu      $s5, $s3, $zero
    /* FF08 8001F708 07006292 */  lbu        $v0, 0x7($s3)
    /* FF0C 8001F70C 00000000 */  nop
    /* FF10 8001F710 02004234 */  ori        $v0, $v0, 0x2
    /* FF14 8001F714 070062A2 */  sb         $v0, 0x7($s3)
  .L8001F718:
    /* FF18 8001F718 2120C002 */  addu       $a0, $s6, $zero
    /* FF1C 8001F71C 08006526 */  addiu      $a1, $s3, 0x8
    /* FF20 8001F720 8800B027 */  addiu      $s0, $sp, 0x88
    /* FF24 8001F724 21300002 */  addu       $a2, $s0, $zero
    /* FF28 8001F728 8C00B227 */  addiu      $s2, $sp, 0x8C
    /* FF2C 8001F72C B5B5000C */  jal        RotTransPers
    /* FF30 8001F730 21384002 */   addu      $a3, $s2, $zero
    /* FF34 8001F734 0800C426 */  addiu      $a0, $s6, 0x8
    /* FF38 8001F738 0C006526 */  addiu      $a1, $s3, 0xC
    /* FF3C 8001F73C 21300002 */  addu       $a2, $s0, $zero
    /* FF40 8001F740 21384002 */  addu       $a3, $s2, $zero
    /* FF44 8001F744 FF00113C */  lui        $s1, (0xFFFFFF >> 16)
    /* FF48 8001F748 FFFF3136 */  ori        $s1, $s1, (0xFFFFFF & 0xFFFF)
    /* FF4C 8001F74C 08006296 */  lhu        $v0, 0x8($s3)
    /* FF50 8001F750 0A006896 */  lhu        $t0, 0xA($s3)
    /* FF54 8001F754 00140200 */  sll        $v0, $v0, 16
    /* FF58 8001F758 031C0200 */  sra        $v1, $v0, 16
    /* FF5C 8001F75C C2170200 */  srl        $v0, $v0, 31
    /* FF60 8001F760 21186200 */  addu       $v1, $v1, $v0
    /* FF64 8001F764 43180300 */  sra        $v1, $v1, 1
    /* FF68 8001F768 00440800 */  sll        $t0, $t0, 16
    /* FF6C 8001F76C 03140800 */  sra        $v0, $t0, 16
    /* FF70 8001F770 C2470800 */  srl        $t0, $t0, 31
    /* FF74 8001F774 21104800 */  addu       $v0, $v0, $t0
    /* FF78 8001F778 43100200 */  sra        $v0, $v0, 1
    /* FF7C 8001F77C 080063A6 */  sh         $v1, 0x8($s3)
    /* FF80 8001F780 B5B5000C */  jal        RotTransPers
    /* FF84 8001F784 0A0062A6 */   sh        $v0, 0xA($s3)
    /* FF88 8001F788 1000C426 */  addiu      $a0, $s6, 0x10
    /* FF8C 8001F78C 10006526 */  addiu      $a1, $s3, 0x10
    /* FF90 8001F790 21300002 */  addu       $a2, $s0, $zero
    /* FF94 8001F794 21384002 */  addu       $a3, $s2, $zero
    /* FF98 8001F798 0C006296 */  lhu        $v0, 0xC($s3)
    /* FF9C 8001F79C 0E006896 */  lhu        $t0, 0xE($s3)
    /* FFA0 8001F7A0 00140200 */  sll        $v0, $v0, 16
    /* FFA4 8001F7A4 031C0200 */  sra        $v1, $v0, 16
    /* FFA8 8001F7A8 C2170200 */  srl        $v0, $v0, 31
    /* FFAC 8001F7AC 21186200 */  addu       $v1, $v1, $v0
    /* FFB0 8001F7B0 43180300 */  sra        $v1, $v1, 1
    /* FFB4 8001F7B4 00440800 */  sll        $t0, $t0, 16
    /* FFB8 8001F7B8 03140800 */  sra        $v0, $t0, 16
    /* FFBC 8001F7BC C2470800 */  srl        $t0, $t0, 31
    /* FFC0 8001F7C0 21104800 */  addu       $v0, $v0, $t0
    /* FFC4 8001F7C4 43100200 */  sra        $v0, $v0, 1
    /* FFC8 8001F7C8 0C0063A6 */  sh         $v1, 0xC($s3)
    /* FFCC 8001F7CC B5B5000C */  jal        RotTransPers
    /* FFD0 8001F7D0 0E0062A6 */   sh        $v0, 0xE($s3)
    /* FFD4 8001F7D4 1800C426 */  addiu      $a0, $s6, 0x18
    /* FFD8 8001F7D8 14006526 */  addiu      $a1, $s3, 0x14
    /* FFDC 8001F7DC 21300002 */  addu       $a2, $s0, $zero
    /* FFE0 8001F7E0 21384002 */  addu       $a3, $s2, $zero
    /* FFE4 8001F7E4 10006296 */  lhu        $v0, 0x10($s3)
    /* FFE8 8001F7E8 12006896 */  lhu        $t0, 0x12($s3)
    /* FFEC 8001F7EC 00140200 */  sll        $v0, $v0, 16
    /* FFF0 8001F7F0 031C0200 */  sra        $v1, $v0, 16
    /* FFF4 8001F7F4 C2170200 */  srl        $v0, $v0, 31
    /* FFF8 8001F7F8 21186200 */  addu       $v1, $v1, $v0
    /* FFFC 8001F7FC 43180300 */  sra        $v1, $v1, 1
    /* 10000 8001F800 00440800 */  sll        $t0, $t0, 16
    /* 10004 8001F804 03140800 */  sra        $v0, $t0, 16
    /* 10008 8001F808 C2470800 */  srl        $t0, $t0, 31
    /* 1000C 8001F80C 21104800 */  addu       $v0, $v0, $t0
    /* 10010 8001F810 43100200 */  sra        $v0, $v0, 1
    /* 10014 8001F814 100063A6 */  sh         $v1, 0x10($s3)
    /* 10018 8001F818 B5B5000C */  jal        RotTransPers
    /* 1001C 8001F81C 120062A6 */   sh        $v0, 0x12($s3)
    /* 10020 8001F820 21280000 */  addu       $a1, $zero, $zero
    /* 10024 8001F824 2130A000 */  addu       $a2, $a1, $zero
    /* 10028 8001F828 0300C733 */  andi       $a3, $fp, 0x3
    /* 1002C 8001F82C 40390700 */  sll        $a3, $a3, 5
    /* 10030 8001F830 00FF103C */  lui        $s0, (0xFF000000 >> 16)
    /* 10034 8001F834 14006296 */  lhu        $v0, 0x14($s3)
    /* 10038 8001F838 16006496 */  lhu        $a0, 0x16($s3)
    /* 1003C 8001F83C 00140200 */  sll        $v0, $v0, 16
    /* 10040 8001F840 031C0200 */  sra        $v1, $v0, 16
    /* 10044 8001F844 C2170200 */  srl        $v0, $v0, 31
    /* 10048 8001F848 21186200 */  addu       $v1, $v1, $v0
    /* 1004C 8001F84C 43180300 */  sra        $v1, $v1, 1
    /* 10050 8001F850 00240400 */  sll        $a0, $a0, 16
    /* 10054 8001F854 03140400 */  sra        $v0, $a0, 16
    /* 10058 8001F858 C2270400 */  srl        $a0, $a0, 31
    /* 1005C 8001F85C 21104400 */  addu       $v0, $v0, $a0
    /* 10060 8001F860 140063A6 */  sh         $v1, 0x14($s3)
    /* 10064 8001F864 0000638E */  lw         $v1, 0x0($s3)
    /* 10068 8001F868 43100200 */  sra        $v0, $v0, 1
    /* 1006C 8001F86C 160062A6 */  sh         $v0, 0x16($s3)
    /* 10070 8001F870 0000828E */  lw         $v0, 0x0($s4)
    /* 10074 8001F874 24187000 */  and        $v1, $v1, $s0
    /* 10078 8001F878 24105100 */  and        $v0, $v0, $s1
    /* 1007C 8001F87C 25186200 */  or         $v1, $v1, $v0
    /* 10080 8001F880 000063AE */  sw         $v1, 0x0($s3)
    /* 10084 8001F884 24187102 */  and        $v1, $s3, $s1
    /* 10088 8001F888 18007326 */  addiu      $s3, $s3, 0x18
    /* 1008C 8001F88C 0000828E */  lw         $v0, 0x0($s4)
    /* 10090 8001F890 21206002 */  addu       $a0, $s3, $zero
    /* 10094 8001F894 24105000 */  and        $v0, $v0, $s0
    /* 10098 8001F898 25104300 */  or         $v0, $v0, $v1
    /* 1009C 8001F89C 000082AE */  sw         $v0, 0x0($s4)
    /* 100A0 8001F8A0 EDAA000C */  jal        SetDrawMode
    /* 100A4 8001F8A4 1000A0AF */   sw        $zero, 0x10($sp)
    /* 100A8 8001F8A8 1800A38E */  lw         $v1, 0x18($s5)
    /* 100AC 8001F8AC 0000828E */  lw         $v0, 0x0($s4)
    /* 100B0 8001F8B0 24187000 */  and        $v1, $v1, $s0
    /* 100B4 8001F8B4 24105100 */  and        $v0, $v0, $s1
    /* 100B8 8001F8B8 25186200 */  or         $v1, $v1, $v0
    /* 100BC 8001F8BC 24887102 */  and        $s1, $s3, $s1
    /* 100C0 8001F8C0 1800A3AE */  sw         $v1, 0x18($s5)
    /* 100C4 8001F8C4 0000828E */  lw         $v0, 0x0($s4)
    /* 100C8 8001F8C8 2400B326 */  addiu      $s3, $s5, 0x24
    /* 100CC 8001F8CC 24105000 */  and        $v0, $v0, $s0
    /* 100D0 8001F8D0 25105100 */  or         $v0, $v0, $s1
    /* 100D4 8001F8D4 000082AE */  sw         $v0, 0x0($s4)
    /* 100D8 8001F8D8 2C00F3AE */  sw         $s3, 0x2C($s7)
    /* 100DC 8001F8DC B400BF8F */  lw         $ra, 0xB4($sp)
    /* 100E0 8001F8E0 B000BE8F */  lw         $fp, 0xB0($sp)
    /* 100E4 8001F8E4 AC00B78F */  lw         $s7, 0xAC($sp)
    /* 100E8 8001F8E8 A800B68F */  lw         $s6, 0xA8($sp)
    /* 100EC 8001F8EC A400B58F */  lw         $s5, 0xA4($sp)
    /* 100F0 8001F8F0 A000B48F */  lw         $s4, 0xA0($sp)
    /* 100F4 8001F8F4 9C00B38F */  lw         $s3, 0x9C($sp)
    /* 100F8 8001F8F8 9800B28F */  lw         $s2, 0x98($sp)
    /* 100FC 8001F8FC 9400B18F */  lw         $s1, 0x94($sp)
    /* 10100 8001F900 9000B08F */  lw         $s0, 0x90($sp)
    /* 10104 8001F904 0800E003 */  jr         $ra
    /* 10108 8001F908 B800BD27 */   addiu     $sp, $sp, 0xB8
endlabel func_8001F668
