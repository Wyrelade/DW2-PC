nonmatching _SsContExternal, 0x84

glabel _SsContExternal
    /* 23B94 80033394 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 23B98 80033398 FF00C630 */  andi       $a2, $a2, 0xFF
    /* 23B9C 8003339C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 23BA0 800333A0 00940400 */  sll        $s2, $a0, 16
    /* 23BA4 800333A4 2120C000 */  addu       $a0, $a2, $zero
    /* 23BA8 800333A8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 23BAC 800333AC 008C0500 */  sll        $s1, $a1, 16
    /* 23BB0 800333B0 21288000 */  addu       $a1, $a0, $zero
    /* 23BB4 800333B4 03941200 */  sra        $s2, $s2, 16
    /* 23BB8 800333B8 80181200 */  sll        $v1, $s2, 2
    /* 23BBC 800333BC 038C1100 */  sra        $s1, $s1, 16
    /* 23BC0 800333C0 40101100 */  sll        $v0, $s1, 1
    /* 23BC4 800333C4 21105100 */  addu       $v0, $v0, $s1
    /* 23BC8 800333C8 80100200 */  sll        $v0, $v0, 2
    /* 23BCC 800333CC 23105100 */  subu       $v0, $v0, $s1
    /* 23BD0 800333D0 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 23BD4 800333D4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 23BD8 800333D8 0680103C */  lui        $s0, %hi(Snd_SeqScores)
    /* 23BDC 800333DC 21800302 */  addu       $s0, $s0, $v1
    /* 23BE0 800333E0 501C108E */  lw         $s0, %lo(Snd_SeqScores)($s0)
    /* 23BE4 800333E4 00110200 */  sll        $v0, $v0, 4
    /* 23BE8 800333E8 F9D8000C */  jal        SsUtSetReverbDepth
    /* 23BEC 800333EC 21800202 */   addu      $s0, $s0, $v0
    /* 23BF0 800333F0 21204002 */  addu       $a0, $s2, $zero
    /* 23BF4 800333F4 25C9000C */  jal        _SsReadDeltaValue
    /* 23BF8 800333F8 21282002 */   addu      $a1, $s1, $zero
    /* 23BFC 800333FC 900002AE */  sw         $v0, 0x90($s0)
    /* 23C00 80033400 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 23C04 80033404 1800B28F */  lw         $s2, 0x18($sp)
    /* 23C08 80033408 1400B18F */  lw         $s1, 0x14($sp)
    /* 23C0C 8003340C 1000B08F */  lw         $s0, 0x10($sp)
    /* 23C10 80033410 0800E003 */  jr         $ra
    /* 23C14 80033414 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _SsContExternal
    /* 23C18 80033418 00000000 */  nop
    /* 23C1C 8003341C 00000000 */  nop
    /* 23C20 80033420 00000000 */  nop
