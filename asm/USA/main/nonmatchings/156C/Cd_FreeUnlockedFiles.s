nonmatching Cd_FreeUnlockedFiles, 0x7C

glabel Cd_FreeUnlockedFiles
    /* 146F8 80023EF8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 146FC 80023EFC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 14700 80023F00 21880000 */  addu       $s1, $zero, $zero
    /* 14704 80023F04 0680023C */  lui        $v0, %hi(D_8005F8C8)
    /* 14708 80023F08 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1470C 80023F0C C8F85024 */  addiu      $s0, $v0, %lo(D_8005F8C8)
    /* 14710 80023F10 1800BFAF */  sw         $ra, 0x18($sp)
  .L80023F14:
    /* 14714 80023F14 0400028E */  lw         $v0, 0x4($s0)
    /* 14718 80023F18 00000000 */  nop
    /* 1471C 80023F1C 0C004010 */  beqz       $v0, .L80023F50
    /* 14720 80023F20 00000000 */   nop
    /* 14724 80023F24 02000286 */  lh         $v0, 0x2($s0)
    /* 14728 80023F28 00000000 */  nop
    /* 1472C 80023F2C 08004014 */  bnez       $v0, .L80023F50
    /* 14730 80023F30 00000000 */   nop
    /* 14734 80023F34 0C00048E */  lw         $a0, 0xC($s0)
    /* 14738 80023F38 618B000C */  jal        Mem_Free
    /* 1473C 80023F3C 00000000 */   nop
    /* 14740 80023F40 040000AE */  sw         $zero, 0x4($s0)
    /* 14744 80023F44 0C0000AE */  sw         $zero, 0xC($s0)
    /* 14748 80023F48 080000AE */  sw         $zero, 0x8($s0)
    /* 1474C 80023F4C 000000A6 */  sh         $zero, 0x0($s0)
  .L80023F50:
    /* 14750 80023F50 01003126 */  addiu      $s1, $s1, 0x1
    /* 14754 80023F54 5000222A */  slti       $v0, $s1, 0x50
    /* 14758 80023F58 EEFF4014 */  bnez       $v0, .L80023F14
    /* 1475C 80023F5C 10001026 */   addiu     $s0, $s0, 0x10
    /* 14760 80023F60 1800BF8F */  lw         $ra, 0x18($sp)
    /* 14764 80023F64 1400B18F */  lw         $s1, 0x14($sp)
    /* 14768 80023F68 1000B08F */  lw         $s0, 0x10($sp)
    /* 1476C 80023F6C 0800E003 */  jr         $ra
    /* 14770 80023F70 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Cd_FreeUnlockedFiles
