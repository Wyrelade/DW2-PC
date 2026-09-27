nonmatching func_80064A6C, 0x94

glabel func_80064A6C
    /* 170C 80064A6C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1710 80064A70 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1714 80064A74 21888000 */  addu       $s1, $a0, $zero
    /* 1718 80064A78 1800BFAF */  sw         $ra, 0x18($sp)
    /* 171C 80064A7C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1720 80064A80 1800228E */  lw         $v0, 0x18($s1)
    /* 1724 80064A84 00000000 */  nop
    /* 1728 80064A88 04004014 */  bnez       $v0, .L80064A9C
    /* 172C 80064A8C 2180A000 */   addu      $s0, $a1, $zero
    /* 1730 80064A90 84000586 */  lh         $a1, 0x84($s0)
    /* 1734 80064A94 EB9D010C */  jal        func_800677AC
    /* 1738 80064A98 04000424 */   addiu     $a0, $zero, 0x4
  .L80064A9C:
    /* 173C 80064A9C 21202002 */  addu       $a0, $s1, $zero
    /* 1740 80064AA0 7E92010C */  jal        func_800649F8
    /* 1744 80064AA4 21280002 */   addu      $a1, $s0, $zero
    /* 1748 80064AA8 10004014 */  bnez       $v0, .L80064AEC
    /* 174C 80064AAC 01000224 */   addiu     $v0, $zero, 0x1
    /* 1750 80064AB0 0680033C */  lui        $v1, %hi(D_8005F6F0)
    /* 1754 80064AB4 180022AE */  sw         $v0, 0x18($s1)
    /* 1758 80064AB8 7E000286 */  lh         $v0, 0x7E($s0)
    /* 175C 80064ABC F0F66324 */  addiu      $v1, $v1, %lo(D_8005F6F0)
    /* 1760 80064AC0 80110200 */  sll        $v0, $v0, 6
    /* 1764 80064AC4 21104300 */  addu       $v0, $v0, $v1
    /* 1768 80064AC8 1C00428C */  lw         $v0, 0x1C($v0)
    /* 176C 80064ACC 00000000 */  nop
    /* 1770 80064AD0 06004018 */  blez       $v0, .L80064AEC
    /* 1774 80064AD4 0B000424 */   addiu     $a0, $zero, 0xB
    /* 1778 80064AD8 A369000C */  jal        Snd_PlayById
    /* 177C 80064ADC 21280000 */   addu      $a1, $zero, $zero
    /* 1780 80064AE0 21202002 */  addu       $a0, $s1, $zero
    /* 1784 80064AE4 7045000C */  jal        Task_SetState0
    /* 1788 80064AE8 02000524 */   addiu     $a1, $zero, 0x2
  .L80064AEC:
    /* 178C 80064AEC 1800BF8F */  lw         $ra, 0x18($sp)
    /* 1790 80064AF0 1400B18F */  lw         $s1, 0x14($sp)
    /* 1794 80064AF4 1000B08F */  lw         $s0, 0x10($sp)
    /* 1798 80064AF8 0800E003 */  jr         $ra
    /* 179C 80064AFC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80064A6C
