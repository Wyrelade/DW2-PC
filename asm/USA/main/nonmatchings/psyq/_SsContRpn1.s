nonmatching _SsContRpn1, 0x6C

glabel _SsContRpn1
    /* 23E64 80033664 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 23E68 80033668 00240400 */  sll        $a0, $a0, 16
    /* 23E6C 8003366C 03240400 */  sra        $a0, $a0, 16
    /* 23E70 80033670 80180400 */  sll        $v1, $a0, 2
    /* 23E74 80033674 002C0500 */  sll        $a1, $a1, 16
    /* 23E78 80033678 032C0500 */  sra        $a1, $a1, 16
    /* 23E7C 8003367C 40100500 */  sll        $v0, $a1, 1
    /* 23E80 80033680 21104500 */  addu       $v0, $v0, $a1
    /* 23E84 80033684 80100200 */  sll        $v0, $v0, 2
    /* 23E88 80033688 23104500 */  subu       $v0, $v0, $a1
    /* 23E8C 8003368C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 23E90 80033690 1000B0AF */  sw         $s0, 0x10($sp)
    /* 23E94 80033694 0680103C */  lui        $s0, %hi(Snd_SeqScores)
    /* 23E98 80033698 21800302 */  addu       $s0, $s0, $v1
    /* 23E9C 8003369C 501C108E */  lw         $s0, %lo(Snd_SeqScores)($s0)
    /* 23EA0 800336A0 00110200 */  sll        $v0, $v0, 4
    /* 23EA4 800336A4 21800202 */  addu       $s0, $s0, $v0
    /* 23EA8 800336A8 1E000292 */  lbu        $v0, 0x1E($s0)
    /* 23EAC 800336AC 180006A2 */  sb         $a2, 0x18($s0)
    /* 23EB0 800336B0 01004224 */  addiu      $v0, $v0, 0x1
    /* 23EB4 800336B4 25C9000C */  jal        _SsReadDeltaValue
    /* 23EB8 800336B8 1E0002A2 */   sb        $v0, 0x1E($s0)
    /* 23EBC 800336BC 900002AE */  sw         $v0, 0x90($s0)
    /* 23EC0 800336C0 1400BF8F */  lw         $ra, 0x14($sp)
    /* 23EC4 800336C4 1000B08F */  lw         $s0, 0x10($sp)
    /* 23EC8 800336C8 0800E003 */  jr         $ra
    /* 23ECC 800336CC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _SsContRpn1
    /* 23ED0 800336D0 00000000 */  nop
