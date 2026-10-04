nonmatching Bug_CompactMemBugs, 0x58

glabel Bug_CompactMemBugs
    /* 2704 80011F04 21180000 */  addu       $v1, $zero, $zero
    /* 2708 80011F08 21286000 */  addu       $a1, $v1, $zero
  .L80011F0C:
    /* 270C 80011F0C 0580023C */  lui        $v0, %hi(D_8005071C)
    /* 2710 80011F10 1C07428C */  lw         $v0, %lo(D_8005071C)($v0)
    /* 2714 80011F14 00000000 */  nop
    /* 2718 80011F18 21104300 */  addu       $v0, $v0, $v1
    /* 271C 80011F1C A90B4490 */  lbu        $a0, 0xBA9($v0)
    /* 2720 80011F20 00000000 */  nop
    /* 2724 80011F24 07008010 */  beqz       $a0, .L80011F44
    /* 2728 80011F28 A90B40A0 */   sb        $zero, 0xBA9($v0)
    /* 272C 80011F2C 0580023C */  lui        $v0, %hi(D_8005071C)
    /* 2730 80011F30 1C07428C */  lw         $v0, %lo(D_8005071C)($v0)
    /* 2734 80011F34 00000000 */  nop
    /* 2738 80011F38 21104500 */  addu       $v0, $v0, $a1
    /* 273C 80011F3C 0100A524 */  addiu      $a1, $a1, 0x1
    /* 2740 80011F40 A90B44A0 */  sb         $a0, 0xBA9($v0)
  .L80011F44:
    /* 2744 80011F44 01006324 */  addiu      $v1, $v1, 0x1
    /* 2748 80011F48 0C006228 */  slti       $v0, $v1, 0xC
    /* 274C 80011F4C EFFF4014 */  bnez       $v0, .L80011F0C
    /* 2750 80011F50 00000000 */   nop
    /* 2754 80011F54 0800E003 */  jr         $ra
    /* 2758 80011F58 00000000 */   nop
endlabel Bug_CompactMemBugs
