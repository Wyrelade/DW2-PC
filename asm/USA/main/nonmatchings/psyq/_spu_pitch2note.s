nonmatching _spu_pitch2note, 0x130

glabel _spu_pitch2note
    /* 2D7D4 8003CFD4 FFFFC230 */  andi       $v0, $a2, 0xFFFF
    /* 2D7D8 8003CFD8 0040422C */  sltiu      $v0, $v0, 0x4000
    /* 2D7DC 8003CFDC 02004014 */  bnez       $v0, .L8003CFE8
    /* 2D7E0 8003CFE0 21580000 */   addu      $t3, $zero, $zero
    /* 2D7E4 8003CFE4 FF3F0624 */  addiu      $a2, $zero, 0x3FFF
  .L8003CFE8:
    /* 2D7E8 8003CFE8 21380000 */  addu       $a3, $zero, $zero
    /* 2D7EC 8003CFEC FFFFC330 */  andi       $v1, $a2, 0xFFFF
    /* 2D7F0 8003CFF0 0710E300 */  srav       $v0, $v1, $a3
  .L8003CFF4:
    /* 2D7F4 8003CFF4 01004230 */  andi       $v0, $v0, 0x1
    /* 2D7F8 8003CFF8 02004010 */  beqz       $v0, .L8003D004
    /* 2D7FC 8003CFFC 00000000 */   nop
    /* 2D800 8003D000 2158E000 */  addu       $t3, $a3, $zero
  .L8003D004:
    /* 2D804 8003D004 0100E724 */  addiu      $a3, $a3, 0x1
    /* 2D808 8003D008 0E00E228 */  slti       $v0, $a3, 0xE
    /* 2D80C 8003D00C F9FF4014 */  bnez       $v0, .L8003CFF4
    /* 2D810 8003D010 0710E300 */   srav      $v0, $v1, $a3
    /* 2D814 8003D014 FFFFC330 */  andi       $v1, $a2, 0xFFFF
    /* 2D818 8003D018 0F000224 */  addiu      $v0, $zero, 0xF
    /* 2D81C 8003D01C 23104B00 */  subu       $v0, $v0, $t3
    /* 2D820 8003D020 04304300 */  sllv       $a2, $v1, $v0
    /* 2D824 8003D024 0B000724 */  addiu      $a3, $zero, 0xB
    /* 2D828 8003D028 FFFFC330 */  andi       $v1, $a2, 0xFFFF
    /* 2D82C 8003D02C 0580083C */  lui        $t0, %hi(D_800502AE)
    /* 2D830 8003D030 AE020825 */  addiu      $t0, $t0, %lo(D_800502AE)
  .L8003D034:
    /* 2D834 8003D034 00000295 */  lhu        $v0, 0x0($t0)
    /* 2D838 8003D038 00000000 */  nop
    /* 2D83C 8003D03C 2B106200 */  sltu       $v0, $v1, $v0
    /* 2D840 8003D040 03004014 */  bnez       $v0, .L8003D050
    /* 2D844 8003D044 00000000 */   nop
    /* 2D848 8003D048 17F40008 */  j          .L8003D05C
    /* 2D84C 8003D04C 2150E000 */   addu      $t2, $a3, $zero
  .L8003D050:
    /* 2D850 8003D050 FFFFE724 */  addiu      $a3, $a3, -0x1
    /* 2D854 8003D054 F7FFE104 */  bgez       $a3, .L8003D034
    /* 2D858 8003D058 FEFF0825 */   addiu     $t0, $t0, -0x2
  .L8003D05C:
    /* 2D85C 8003D05C FFFFC330 */  andi       $v1, $a2, 0xFFFF
    /* 2D860 8003D060 FFFF4231 */  andi       $v0, $t2, 0xFFFF
    /* 2D864 8003D064 40100200 */  sll        $v0, $v0, 1
    /* 2D868 8003D068 0580013C */  lui        $at, %hi(D_80050298)
    /* 2D86C 8003D06C 21082200 */  addu       $at, $at, $v0
    /* 2D870 8003D070 98022294 */  lhu        $v0, %lo(D_80050298)($at)
    /* 2D874 8003D074 C01B0300 */  sll        $v1, $v1, 15
    /* 2D878 8003D078 1B006200 */  divu       $zero, $v1, $v0
    /* 2D87C 8003D07C 02004014 */  bnez       $v0, .L8003D088
    /* 2D880 8003D080 00000000 */   nop
    /* 2D884 8003D084 0D000700 */  break      7
  .L8003D088:
    /* 2D888 8003D088 12180000 */  mflo       $v1
    /* 2D88C 8003D08C 7F000724 */  addiu      $a3, $zero, 0x7F
    /* 2D890 8003D090 0580063C */  lui        $a2, %hi(D_800503AE)
    /* 2D894 8003D094 AE03C624 */  addiu      $a2, $a2, %lo(D_800503AE)
    /* 2D898 8003D098 FFFF6330 */  andi       $v1, $v1, 0xFFFF
  .L8003D09C:
    /* 2D89C 8003D09C 0000C294 */  lhu        $v0, 0x0($a2)
    /* 2D8A0 8003D0A0 00000000 */  nop
    /* 2D8A4 8003D0A4 2B106200 */  sltu       $v0, $v1, $v0
    /* 2D8A8 8003D0A8 03004014 */  bnez       $v0, .L8003D0B8
    /* 2D8AC 8003D0AC 00000000 */   nop
    /* 2D8B0 8003D0B0 31F40008 */  j          .L8003D0C4
    /* 2D8B4 8003D0B4 2148E000 */   addu      $t1, $a3, $zero
  .L8003D0B8:
    /* 2D8B8 8003D0B8 FFFFE724 */  addiu      $a3, $a3, -0x1
    /* 2D8BC 8003D0BC F7FFE104 */  bgez       $a3, .L8003D09C
    /* 2D8C0 8003D0C0 FEFFC624 */   addiu     $a2, $a2, -0x2
  .L8003D0C4:
    /* 2D8C4 8003D0C4 01002225 */  addiu      $v0, $t1, 0x1
    /* 2D8C8 8003D0C8 2148A200 */  addu       $t1, $a1, $v0
    /* 2D8CC 8003D0CC F4FF6325 */  addiu      $v1, $t3, -0xC
    /* 2D8D0 8003D0D0 40100300 */  sll        $v0, $v1, 1
    /* 2D8D4 8003D0D4 21104300 */  addu       $v0, $v0, $v1
    /* 2D8D8 8003D0D8 80100200 */  sll        $v0, $v0, 2
    /* 2D8DC 8003D0DC 21108200 */  addu       $v0, $a0, $v0
    /* 2D8E0 8003D0E0 21104201 */  addu       $v0, $t2, $v0
    /* 2D8E4 8003D0E4 FFFF2431 */  andi       $a0, $t1, 0xFFFF
    /* 2D8E8 8003D0E8 C2190400 */  srl        $v1, $a0, 7
    /* 2D8EC 8003D0EC 21504300 */  addu       $t2, $v0, $v1
    /* 2D8F0 8003D0F0 FFFF4231 */  andi       $v0, $t2, 0xFFFF
    /* 2D8F4 8003D0F4 00120200 */  sll        $v0, $v0, 8
    /* 2D8F8 8003D0F8 7E008430 */  andi       $a0, $a0, 0x7E
    /* 2D8FC 8003D0FC 0800E003 */  jr         $ra
    /* 2D900 8003D100 25104400 */   or        $v0, $v0, $a0
endlabel _spu_pitch2note
