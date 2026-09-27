nonmatching _SsContRpn2, 0x6C

glabel _SsContRpn2
    /* 23ED4 800336D4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 23ED8 800336D8 00240400 */  sll        $a0, $a0, 16
    /* 23EDC 800336DC 03240400 */  sra        $a0, $a0, 16
    /* 23EE0 800336E0 80180400 */  sll        $v1, $a0, 2
    /* 23EE4 800336E4 002C0500 */  sll        $a1, $a1, 16
    /* 23EE8 800336E8 032C0500 */  sra        $a1, $a1, 16
    /* 23EEC 800336EC 40100500 */  sll        $v0, $a1, 1
    /* 23EF0 800336F0 21104500 */  addu       $v0, $v0, $a1
    /* 23EF4 800336F4 80100200 */  sll        $v0, $v0, 2
    /* 23EF8 800336F8 23104500 */  subu       $v0, $v0, $a1
    /* 23EFC 800336FC 1400BFAF */  sw         $ra, 0x14($sp)
    /* 23F00 80033700 1000B0AF */  sw         $s0, 0x10($sp)
    /* 23F04 80033704 0680103C */  lui        $s0, %hi(Snd_SeqScores)
    /* 23F08 80033708 21800302 */  addu       $s0, $s0, $v1
    /* 23F0C 8003370C 501C108E */  lw         $s0, %lo(Snd_SeqScores)($s0)
    /* 23F10 80033710 00110200 */  sll        $v0, $v0, 4
    /* 23F14 80033714 21800202 */  addu       $s0, $s0, $v0
    /* 23F18 80033718 1E000292 */  lbu        $v0, 0x1E($s0)
    /* 23F1C 8003371C 190006A2 */  sb         $a2, 0x19($s0)
    /* 23F20 80033720 01004224 */  addiu      $v0, $v0, 0x1
    /* 23F24 80033724 25C9000C */  jal        _SsReadDeltaValue
    /* 23F28 80033728 1E0002A2 */   sb        $v0, 0x1E($s0)
    /* 23F2C 8003372C 900002AE */  sw         $v0, 0x90($s0)
    /* 23F30 80033730 1400BF8F */  lw         $ra, 0x14($sp)
    /* 23F34 80033734 1000B08F */  lw         $s0, 0x10($sp)
    /* 23F38 80033738 0800E003 */  jr         $ra
    /* 23F3C 8003373C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _SsContRpn2
    /* 23F40 80033740 00000000 */  nop
