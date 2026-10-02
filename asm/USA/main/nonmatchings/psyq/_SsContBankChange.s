nonmatching _SsContBankChange, 0x74

glabel _SsContBankChange
    /* 23454 80032C54 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 23458 80032C58 00240400 */  sll        $a0, $a0, 16
    /* 2345C 80032C5C 03240400 */  sra        $a0, $a0, 16
    /* 23460 80032C60 80180400 */  sll        $v1, $a0, 2
    /* 23464 80032C64 002C0500 */  sll        $a1, $a1, 16
    /* 23468 80032C68 032C0500 */  sra        $a1, $a1, 16
    /* 2346C 80032C6C 40100500 */  sll        $v0, $a1, 1
    /* 23470 80032C70 21104500 */  addu       $v0, $v0, $a1
    /* 23474 80032C74 80100200 */  sll        $v0, $v0, 2
    /* 23478 80032C78 23104500 */  subu       $v0, $v0, $a1
    /* 2347C 80032C7C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 23480 80032C80 1000B0AF */  sw         $s0, 0x10($sp)
    /* 23484 80032C84 0680103C */  lui        $s0, %hi(Snd_SeqScores)
    /* 23488 80032C88 21800302 */  addu       $s0, $s0, $v1
    /* 2348C 80032C8C 501C108E */  lw         $s0, %lo(Snd_SeqScores)($s0)
    /* 23490 80032C90 00110200 */  sll        $v0, $v0, 4
    /* 23494 80032C94 21800202 */  addu       $s0, $s0, $v0
    /* 23498 80032C98 0000028E */  lw         $v0, 0x0($s0)
    /* 2349C 80032C9C 00000000 */  nop
    /* 234A0 80032CA0 00004390 */  lbu        $v1, 0x0($v0)
    /* 234A4 80032CA4 01004224 */  addiu      $v0, $v0, 0x1
    /* 234A8 80032CA8 000002AE */  sw         $v0, 0x0($s0)
    /* 234AC 80032CAC 25C9000C */  jal        _SsReadDeltaValue
    /* 234B0 80032CB0 260003A2 */   sb        $v1, 0x26($s0)
    /* 234B4 80032CB4 900002AE */  sw         $v0, 0x90($s0)
    /* 234B8 80032CB8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 234BC 80032CBC 1000B08F */  lw         $s0, 0x10($sp)
    /* 234C0 80032CC0 0800E003 */  jr         $ra
    /* 234C4 80032CC4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _SsContBankChange
    /* 234C8 80032CC8 00000000 */  nop
    /* 234CC 80032CCC 00000000 */  nop
    /* 234D0 80032CD0 00000000 */  nop
