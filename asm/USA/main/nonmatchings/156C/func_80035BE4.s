nonmatching func_80035BE4, 0x68

glabel func_80035BE4
    /* 263E4 80035BE4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 263E8 80035BE8 2140C000 */  addu       $t0, $a2, $zero
    /* 263EC 80035BEC 2148A000 */  addu       $t1, $a1, $zero
    /* 263F0 80035BF0 00240400 */  sll        $a0, $a0, 16
    /* 263F4 80035BF4 03240400 */  sra        $a0, $a0, 16
    /* 263F8 80035BF8 80100400 */  sll        $v0, $a0, 2
    /* 263FC 80035BFC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 26400 80035C00 0680073C */  lui        $a3, %hi(Snd_SeqScores)
    /* 26404 80035C04 2138E200 */  addu       $a3, $a3, $v0
    /* 26408 80035C08 501CE78C */  lw         $a3, %lo(Snd_SeqScores)($a3)
    /* 2640C 80035C0C 00000000 */  nop
    /* 26410 80035C10 9800E38C */  lw         $v1, 0x98($a3)
    /* 26414 80035C14 01000224 */  addiu      $v0, $zero, 0x1
    /* 26418 80035C18 04006210 */  beq        $v1, $v0, .L80035C2C
    /* 2641C 80035C1C 21300001 */   addu      $a2, $t0, $zero
    /* 26420 80035C20 5800E5A4 */  sh         $a1, 0x58($a3)
    /* 26424 80035C24 0FD70008 */  j          .L80035C3C
    /* 26428 80035C28 5A00E8A4 */   sh        $t0, 0x5A($a3)
  .L80035C2C:
    /* 2642C 80035C2C FFFF2531 */  andi       $a1, $t1, 0xFFFF
    /* 26430 80035C30 FFFFC630 */  andi       $a2, $a2, 0xFFFF
    /* 26434 80035C34 F9E2000C */  jal        _SsVmSetSeqVol
    /* 26438 80035C38 01000724 */   addiu     $a3, $zero, 0x1
  .L80035C3C:
    /* 2643C 80035C3C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 26440 80035C40 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 26444 80035C44 0800E003 */  jr         $ra
    /* 26448 80035C48 00000000 */   nop
endlabel func_80035BE4
