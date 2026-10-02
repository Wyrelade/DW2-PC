nonmatching SsSepSetVol, 0x90

glabel SsSepSetVol
    /* 2644C 80035C4C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 26450 80035C50 21408000 */  addu       $t0, $a0, $zero
    /* 26454 80035C54 2148C000 */  addu       $t1, $a2, $zero
    /* 26458 80035C58 00240800 */  sll        $a0, $t0, 16
    /* 2645C 80035C5C 83230400 */  sra        $a0, $a0, 14
    /* 26460 80035C60 001C0500 */  sll        $v1, $a1, 16
    /* 26464 80035C64 031C0300 */  sra        $v1, $v1, 16
    /* 26468 80035C68 40100300 */  sll        $v0, $v1, 1
    /* 2646C 80035C6C 21104300 */  addu       $v0, $v0, $v1
    /* 26470 80035C70 80100200 */  sll        $v0, $v0, 2
    /* 26474 80035C74 23104300 */  subu       $v0, $v0, $v1
    /* 26478 80035C78 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2647C 80035C7C 0680033C */  lui        $v1, %hi(Snd_SeqScores)
    /* 26480 80035C80 21186400 */  addu       $v1, $v1, $a0
    /* 26484 80035C84 501C638C */  lw         $v1, %lo(Snd_SeqScores)($v1)
    /* 26488 80035C88 00110200 */  sll        $v0, $v0, 4
    /* 2648C 80035C8C 21206200 */  addu       $a0, $v1, $v0
    /* 26490 80035C90 9800838C */  lw         $v1, 0x98($a0)
    /* 26494 80035C94 01000224 */  addiu      $v0, $zero, 0x1
    /* 26498 80035C98 04006210 */  beq        $v1, $v0, .L80035CAC
    /* 2649C 80035C9C 2150E000 */   addu      $t2, $a3, $zero
    /* 264A0 80035CA0 580086A4 */  sh         $a2, 0x58($a0)
    /* 264A4 80035CA4 33D70008 */  j          .L80035CCC
    /* 264A8 80035CA8 5A0087A4 */   sh        $a3, 0x5A($a0)
  .L80035CAC:
    /* 264AC 80035CAC 00220500 */  sll        $a0, $a1, 8
    /* 264B0 80035CB0 25200401 */  or         $a0, $t0, $a0
    /* 264B4 80035CB4 00240400 */  sll        $a0, $a0, 16
    /* 264B8 80035CB8 03240400 */  sra        $a0, $a0, 16
    /* 264BC 80035CBC FFFF2531 */  andi       $a1, $t1, 0xFFFF
    /* 264C0 80035CC0 FFFF4631 */  andi       $a2, $t2, 0xFFFF
    /* 264C4 80035CC4 F9E2000C */  jal        _SsVmSetSeqVol
    /* 264C8 80035CC8 01000724 */   addiu     $a3, $zero, 0x1
  .L80035CCC:
    /* 264CC 80035CCC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 264D0 80035CD0 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 264D4 80035CD4 0800E003 */  jr         $ra
    /* 264D8 80035CD8 00000000 */   nop
endlabel SsSepSetVol
    /* 264DC 80035CDC 00000000 */  nop
    /* 264E0 80035CE0 00000000 */  nop
