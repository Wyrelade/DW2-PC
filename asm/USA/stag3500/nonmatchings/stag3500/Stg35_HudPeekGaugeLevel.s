nonmatching Stg35_HudPeekGaugeLevel, 0x94

glabel Stg35_HudPeekGaugeLevel
    /* 5940 80068CA0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 5944 80068CA4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 5948 80068CA8 21808000 */  addu       $s0, $a0, $zero
    /* 594C 80068CAC 08070424 */  addiu      $a0, $zero, 0x708
    /* 5950 80068CB0 FFFF0524 */  addiu      $a1, $zero, -0x1
    /* 5954 80068CB4 1400BFAF */  sw         $ra, 0x14($sp)
    /* 5958 80068CB8 4445000C */  jal        Task_FindFirst
    /* 595C 80068CBC 2130A000 */   addu      $a2, $a1, $zero
    /* 5960 80068CC0 17004010 */  beqz       $v0, .L80068D20
    /* 5964 80068CC4 00000000 */   nop
    /* 5968 80068CC8 2C00438C */  lw         $v1, 0x2C($v0)
    /* 596C 80068CCC 80101000 */  sll        $v0, $s0, 2
    /* 5970 80068CD0 21106200 */  addu       $v0, $v1, $v0
    /* 5974 80068CD4 5400428C */  lw         $v0, 0x54($v0)
    /* 5978 80068CD8 00000000 */  nop
    /* 597C 80068CDC 03004104 */  bgez       $v0, .L80068CEC
    /* 5980 80068CE0 03230200 */   sra       $a0, $v0, 12
    /* 5984 80068CE4 FF0F4224 */  addiu      $v0, $v0, 0xFFF
    /* 5988 80068CE8 03230200 */  sra        $a0, $v0, 12
  .L80068CEC:
    /* 598C 80068CEC 05000224 */  addiu      $v0, $zero, 0x5
    /* 5990 80068CF0 23104400 */  subu       $v0, $v0, $a0
    /* 5994 80068CF4 80100200 */  sll        $v0, $v0, 2
    /* 5998 80068CF8 21106200 */  addu       $v0, $v1, $v0
    /* 599C 80068CFC 5C00428C */  lw         $v0, 0x5C($v0)
    /* 59A0 80068D00 00000000 */  nop
    /* 59A4 80068D04 06004010 */  beqz       $v0, .L80068D20
    /* 59A8 80068D08 06000224 */   addiu     $v0, $zero, 0x6
    /* 59AC 80068D0C 21184000 */  addu       $v1, $v0, $zero
    /* 59B0 80068D10 04008310 */  beq        $a0, $v1, .L80068D24
    /* 59B4 80068D14 00000000 */   nop
    /* 59B8 80068D18 49A30108 */  j          .L80068D24
    /* 59BC 80068D1C 21108000 */   addu      $v0, $a0, $zero
  .L80068D20:
    /* 59C0 80068D20 21100000 */  addu       $v0, $zero, $zero
  .L80068D24:
    /* 59C4 80068D24 1400BF8F */  lw         $ra, 0x14($sp)
    /* 59C8 80068D28 1000B08F */  lw         $s0, 0x10($sp)
    /* 59CC 80068D2C 0800E003 */  jr         $ra
    /* 59D0 80068D30 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg35_HudPeekGaugeLevel
