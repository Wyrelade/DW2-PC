nonmatching _SsSetProgramChange, 0x6C

glabel _SsSetProgramChange
    /* 251B4 800349B4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 251B8 800349B8 00240400 */  sll        $a0, $a0, 16
    /* 251BC 800349BC 03240400 */  sra        $a0, $a0, 16
    /* 251C0 800349C0 80180400 */  sll        $v1, $a0, 2
    /* 251C4 800349C4 002C0500 */  sll        $a1, $a1, 16
    /* 251C8 800349C8 032C0500 */  sra        $a1, $a1, 16
    /* 251CC 800349CC 40100500 */  sll        $v0, $a1, 1
    /* 251D0 800349D0 21104500 */  addu       $v0, $v0, $a1
    /* 251D4 800349D4 80100200 */  sll        $v0, $v0, 2
    /* 251D8 800349D8 23104500 */  subu       $v0, $v0, $a1
    /* 251DC 800349DC 1400BFAF */  sw         $ra, 0x14($sp)
    /* 251E0 800349E0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 251E4 800349E4 0680103C */  lui        $s0, %hi(Snd_SeqScores)
    /* 251E8 800349E8 21800302 */  addu       $s0, $s0, $v1
    /* 251EC 800349EC 501C108E */  lw         $s0, %lo(Snd_SeqScores)($s0)
    /* 251F0 800349F0 00110200 */  sll        $v0, $v0, 4
    /* 251F4 800349F4 21800202 */  addu       $s0, $s0, $v0
    /* 251F8 800349F8 17000292 */  lbu        $v0, 0x17($s0)
    /* 251FC 800349FC 00000000 */  nop
    /* 25200 80034A00 21100202 */  addu       $v0, $s0, $v0
    /* 25204 80034A04 25C9000C */  jal        _SsReadDeltaValue
    /* 25208 80034A08 370046A0 */   sb        $a2, 0x37($v0)
    /* 2520C 80034A0C 900002AE */  sw         $v0, 0x90($s0)
    /* 25210 80034A10 1400BF8F */  lw         $ra, 0x14($sp)
    /* 25214 80034A14 1000B08F */  lw         $s0, 0x10($sp)
    /* 25218 80034A18 0800E003 */  jr         $ra
    /* 2521C 80034A1C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _SsSetProgramChange
    /* 25220 80034A20 00000000 */  nop
