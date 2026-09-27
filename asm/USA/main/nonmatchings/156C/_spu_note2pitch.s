nonmatching _spu_note2pitch, 0xD0

glabel _spu_note2pitch
    /* 2D704 8003CF04 2138E500 */  addu       $a3, $a3, $a1
    /* 2D708 8003CF08 AA2A053C */  lui        $a1, (0x2AAAAAAB >> 16)
    /* 2D70C 8003CF0C ABAAA534 */  ori        $a1, $a1, (0x2AAAAAAB & 0xFFFF)
    /* 2D710 8003CF10 FFFFE330 */  andi       $v1, $a3, 0xFFFF
    /* 2D714 8003CF14 C2110300 */  srl        $v0, $v1, 7
    /* 2D718 8003CF18 2130C200 */  addu       $a2, $a2, $v0
    /* 2D71C 8003CF1C 2330C400 */  subu       $a2, $a2, $a0
    /* 2D720 8003CF20 00340600 */  sll        $a2, $a2, 16
    /* 2D724 8003CF24 03240600 */  sra        $a0, $a2, 16
    /* 2D728 8003CF28 18008500 */  mult       $a0, $a1
    /* 2D72C 8003CF2C 7F006730 */  andi       $a3, $v1, 0x7F
    /* 2D730 8003CF30 C3370600 */  sra        $a2, $a2, 31
    /* 2D734 8003CF34 10400000 */  mfhi       $t0
    /* 2D738 8003CF38 43100800 */  sra        $v0, $t0, 1
    /* 2D73C 8003CF3C 23284600 */  subu       $a1, $v0, $a2
    /* 2D740 8003CF40 FEFFA624 */  addiu      $a2, $a1, -0x2
    /* 2D744 8003CF44 40100500 */  sll        $v0, $a1, 1
    /* 2D748 8003CF48 21104500 */  addu       $v0, $v0, $a1
    /* 2D74C 8003CF4C 80100200 */  sll        $v0, $v0, 2
    /* 2D750 8003CF50 23208200 */  subu       $a0, $a0, $v0
    /* 2D754 8003CF54 00140400 */  sll        $v0, $a0, 16
    /* 2D758 8003CF58 03004104 */  bgez       $v0, .L8003CF68
    /* 2D75C 8003CF5C 21188000 */   addu      $v1, $a0, $zero
    /* 2D760 8003CF60 0C008324 */  addiu      $v1, $a0, 0xC
    /* 2D764 8003CF64 FDFFA624 */  addiu      $a2, $a1, -0x3
  .L8003CF68:
    /* 2D768 8003CF68 001C0300 */  sll        $v1, $v1, 16
    /* 2D76C 8003CF6C C31B0300 */  sra        $v1, $v1, 15
    /* 2D770 8003CF70 FFFFE230 */  andi       $v0, $a3, 0xFFFF
    /* 2D774 8003CF74 40100200 */  sll        $v0, $v0, 1
    /* 2D778 8003CF78 0580013C */  lui        $at, %hi(D_80050298)
    /* 2D77C 8003CF7C 21082300 */  addu       $at, $at, $v1
    /* 2D780 8003CF80 98022394 */  lhu        $v1, %lo(D_80050298)($at)
    /* 2D784 8003CF84 0580013C */  lui        $at, %hi(D_800502B0)
    /* 2D788 8003CF88 21082200 */  addu       $at, $at, $v0
    /* 2D78C 8003CF8C B0022294 */  lhu        $v0, %lo(D_800502B0)($at)
    /* 2D790 8003CF90 00000000 */  nop
    /* 2D794 8003CF94 18006200 */  mult       $v1, $v0
    /* 2D798 8003CF98 00140600 */  sll        $v0, $a2, 16
    /* 2D79C 8003CF9C 03140200 */  sra        $v0, $v0, 16
    /* 2D7A0 8003CFA0 12400000 */  mflo       $t0
    /* 2D7A4 8003CFA4 03004004 */  bltz       $v0, .L8003CFB4
    /* 2D7A8 8003CFA8 032C0800 */   sra       $a1, $t0, 16
    /* 2D7AC 8003CFAC F3F30008 */  j          .L8003CFCC
    /* 2D7B0 8003CFB0 FF3F0524 */   addiu     $a1, $zero, 0x3FFF
  .L8003CFB4:
    /* 2D7B4 8003CFB4 23200200 */  negu       $a0, $v0
    /* 2D7B8 8003CFB8 FFFF8324 */  addiu      $v1, $a0, -0x1
    /* 2D7BC 8003CFBC 01000224 */  addiu      $v0, $zero, 0x1
    /* 2D7C0 8003CFC0 04106200 */  sllv       $v0, $v0, $v1
    /* 2D7C4 8003CFC4 2128A200 */  addu       $a1, $a1, $v0
    /* 2D7C8 8003CFC8 06288500 */  srlv       $a1, $a1, $a0
  .L8003CFCC:
    /* 2D7CC 8003CFCC 0800E003 */  jr         $ra
    /* 2D7D0 8003CFD0 FFFFA230 */   andi      $v0, $a1, 0xFFFF
endlabel _spu_note2pitch
