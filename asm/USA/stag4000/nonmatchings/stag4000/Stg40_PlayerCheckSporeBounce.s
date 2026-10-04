nonmatching Stg40_PlayerCheckSporeBounce, 0xDC

glabel Stg40_PlayerCheckSporeBounce
    /* 5900 80068C60 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 5904 80068C64 1400B1AF */  sw         $s1, 0x14($sp)
    /* 5908 80068C68 21888000 */  addu       $s1, $a0, $zero
    /* 590C 80068C6C 1800BFAF */  sw         $ra, 0x18($sp)
    /* 5910 80068C70 1000B0AF */  sw         $s0, 0x10($sp)
    /* 5914 80068C74 2C00228E */  lw         $v0, 0x2C($s1)
    /* 5918 80068C78 00000000 */  nop
    /* 591C 80068C7C 2C00508C */  lw         $s0, 0x2C($v0)
    /* 5920 80068C80 00000000 */  nop
    /* 5924 80068C84 18000426 */  addiu      $a0, $s0, 0x18
    /* 5928 80068C88 0A008294 */  lhu        $v0, 0xA($a0)
    /* 592C 80068C8C 00000000 */  nop
    /* 5930 80068C90 00140200 */  sll        $v0, $v0, 16
    /* 5934 80068C94 031C0200 */  sra        $v1, $v0, 16
    /* 5938 80068C98 C2170200 */  srl        $v0, $v0, 31
    /* 593C 80068C9C 21186200 */  addu       $v1, $v1, $v0
    /* 5940 80068CA0 08008284 */  lh         $v0, 0x8($a0)
    /* 5944 80068CA4 43180300 */  sra        $v1, $v1, 1
    /* 5948 80068CA8 1E004314 */  bne        $v0, $v1, .L80068D24
    /* 594C 80068CAC 21280000 */   addu      $a1, $zero, $zero
    /* 5950 80068CB0 1E008294 */  lhu        $v0, 0x1E($a0)
    /* 5954 80068CB4 00000000 */  nop
    /* 5958 80068CB8 01004230 */  andi       $v0, $v0, 0x1
    /* 595C 80068CBC 19004010 */  beqz       $v0, .L80068D24
    /* 5960 80068CC0 00000000 */   nop
    /* 5964 80068CC4 18000486 */  lh         $a0, 0x18($s0)
    /* 5968 80068CC8 1A000586 */  lh         $a1, 0x1A($s0)
    /* 596C 80068CCC 5DC2010C */  jal        Stg40_ClearCellOccupied
    /* 5970 80068CD0 00000000 */   nop
    /* 5974 80068CD4 18000696 */  lhu        $a2, 0x18($s0)
    /* 5978 80068CD8 1C000296 */  lhu        $v0, 0x1C($s0)
    /* 597C 80068CDC 1E000396 */  lhu        $v1, 0x1E($s0)
    /* 5980 80068CE0 1C0006A6 */  sh         $a2, 0x1C($s0)
    /* 5984 80068CE4 1A000696 */  lhu        $a2, 0x1A($s0)
    /* 5988 80068CE8 180002A6 */  sh         $v0, 0x18($s0)
    /* 598C 80068CEC 18000486 */  lh         $a0, 0x18($s0)
    /* 5990 80068CF0 1A0003A6 */  sh         $v1, 0x1A($s0)
    /* 5994 80068CF4 1A000586 */  lh         $a1, 0x1A($s0)
    /* 5998 80068CF8 0C000224 */  addiu      $v0, $zero, 0xC
    /* 599C 80068CFC 200002A6 */  sh         $v0, 0x20($s0)
    /* 59A0 80068D00 18000224 */  addiu      $v0, $zero, 0x18
    /* 59A4 80068D04 220002A6 */  sh         $v0, 0x22($s0)
    /* 59A8 80068D08 1E0006A6 */  sh         $a2, 0x1E($s0)
    /* 59AC 80068D0C 3FC2010C */  jal        Stg40_SetCellOccupied
    /* 59B0 80068D10 01000624 */   addiu     $a2, $zero, 0x1
    /* 59B4 80068D14 21202002 */  addu       $a0, $s1, $zero
    /* 59B8 80068D18 7745000C */  jal        Task_SetState1
    /* 59BC 80068D1C 0F000524 */   addiu     $a1, $zero, 0xF
    /* 59C0 80068D20 FFFF0524 */  addiu      $a1, $zero, -0x1
  .L80068D24:
    /* 59C4 80068D24 1800BF8F */  lw         $ra, 0x18($sp)
    /* 59C8 80068D28 1400B18F */  lw         $s1, 0x14($sp)
    /* 59CC 80068D2C 1000B08F */  lw         $s0, 0x10($sp)
    /* 59D0 80068D30 2110A000 */  addu       $v0, $a1, $zero
    /* 59D4 80068D34 0800E003 */  jr         $ra
    /* 59D8 80068D38 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg40_PlayerCheckSporeBounce
