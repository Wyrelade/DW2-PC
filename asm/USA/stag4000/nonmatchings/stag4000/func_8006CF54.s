nonmatching func_8006CF54, 0x194

glabel func_8006CF54
    /* 9BF4 8006CF54 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 9BF8 8006CF58 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 9BFC 8006CF5C 21888000 */  addu       $s1, $a0, $zero
    /* 9C00 8006CF60 2000BFAF */  sw         $ra, 0x20($sp)
    /* 9C04 8006CF64 1800B0AF */  sw         $s0, 0x18($sp)
    /* 9C08 8006CF68 2C00228E */  lw         $v0, 0x2C($s1)
    /* 9C0C 8006CF6C 00000000 */  nop
    /* 9C10 8006CF70 2C00508C */  lw         $s0, 0x2C($v0)
    /* 9C14 8006CF74 00000000 */  nop
    /* 9C18 8006CF78 18000486 */  lh         $a0, 0x18($s0)
    /* 9C1C 8006CF7C 1A000586 */  lh         $a1, 0x1A($s0)
    /* 9C20 8006CF80 3FC2010C */  jal        func_800708FC
    /* 9C24 8006CF84 01000624 */   addiu     $a2, $zero, 0x1
    /* 9C28 8006CF88 18000486 */  lh         $a0, 0x18($s0)
    /* 9C2C 8006CF8C 1A000586 */  lh         $a1, 0x1A($s0)
    /* 9C30 8006CF90 F8C0010C */  jal        func_800703E0
    /* 9C34 8006CF94 00000000 */   nop
    /* 9C38 8006CF98 00204230 */  andi       $v0, $v0, 0x2000
    /* 9C3C 8006CF9C 05004010 */  beqz       $v0, .L8006CFB4
    /* 9C40 8006CFA0 00000000 */   nop
    /* 9C44 8006CFA4 0000028E */  lw         $v0, 0x0($s0)
    /* 9C48 8006CFA8 00000000 */  nop
    /* 9C4C 8006CFAC 00104234 */  ori        $v0, $v0, 0x1000
    /* 9C50 8006CFB0 000002AE */  sw         $v0, 0x0($s0)
  .L8006CFB4:
    /* 9C54 8006CFB4 0000028E */  lw         $v0, 0x0($s0)
    /* 9C58 8006CFB8 00000000 */  nop
    /* 9C5C 8006CFBC 00104230 */  andi       $v0, $v0, 0x1000
    /* 9C60 8006CFC0 07004010 */  beqz       $v0, .L8006CFE0
    /* 9C64 8006CFC4 FFFF0624 */   addiu     $a2, $zero, -0x1
    /* 9C68 8006CFC8 18000486 */  lh         $a0, 0x18($s0)
    /* 9C6C 8006CFCC 1A000586 */  lh         $a1, 0x1A($s0)
    /* 9C70 8006CFD0 08000292 */  lbu        $v0, 0x8($s0)
    /* 9C74 8006CFD4 2138C000 */  addu       $a3, $a2, $zero
    /* 9C78 8006CFD8 FDBA010C */  jal        func_8006EBF4
    /* 9C7C 8006CFDC 1000A2AF */   sw        $v0, 0x10($sp)
  .L8006CFE0:
    /* 9C80 8006CFE0 1400238E */  lw         $v1, 0x14($s1)
    /* 9C84 8006CFE4 00000000 */  nop
    /* 9C88 8006CFE8 0700622C */  sltiu      $v0, $v1, 0x7
    /* 9C8C 8006CFEC 08004010 */  beqz       $v0, .L8006D010
    /* 9C90 8006CFF0 0680023C */   lui       $v0, %hi(jtbl_8006358C)
    /* 9C94 8006CFF4 8C354224 */  addiu      $v0, $v0, %lo(jtbl_8006358C)
    /* 9C98 8006CFF8 80180300 */  sll        $v1, $v1, 2
    /* 9C9C 8006CFFC 21186200 */  addu       $v1, $v1, $v0
    /* 9CA0 8006D000 0000628C */  lw         $v0, 0x0($v1)
    /* 9CA4 8006D004 00000000 */  nop
    /* 9CA8 8006D008 08004000 */  jr         $v0
    /* 9CAC 8006D00C 00000000 */   nop
  jlabel .L8006D010
    /* 9CB0 8006D010 21202002 */  addu       $a0, $s1, $zero
    /* 9CB4 8006D014 37B9010C */  jal        func_8006E4DC
    /* 9CB8 8006D018 28000524 */   addiu     $a1, $zero, 0x28
    /* 9CBC 8006D01C 21202002 */  addu       $a0, $s1, $zero
    /* 9CC0 8006D020 0000028E */  lw         $v0, 0x0($s0)
    /* 9CC4 8006D024 01000524 */  addiu      $a1, $zero, 0x1
    /* 9CC8 8006D028 00404234 */  ori        $v0, $v0, 0x4000
    /* 9CCC 8006D02C 33B40108 */  j          .L8006D0CC
    /* 9CD0 8006D030 000002AE */   sw        $v0, 0x0($s0)
  jlabel .L8006D034
    /* 9CD4 8006D034 18000486 */  lh         $a0, 0x18($s0)
    /* 9CD8 8006D038 1A000586 */  lh         $a1, 0x1A($s0)
    /* 9CDC 8006D03C 5DC2010C */  jal        func_80070974
    /* 9CE0 8006D040 00000000 */   nop
    /* 9CE4 8006D044 FFFF0424 */  addiu      $a0, $zero, -0x1
    /* 9CE8 8006D048 18000686 */  lh         $a2, 0x18($s0)
    /* 9CEC 8006D04C 1A000786 */  lh         $a3, 0x1A($s0)
    /* 9CF0 8006D050 08000292 */  lbu        $v0, 0x8($s0)
    /* 9CF4 8006D054 21288000 */  addu       $a1, $a0, $zero
    /* 9CF8 8006D058 FDBA010C */  jal        func_8006EBF4
    /* 9CFC 8006D05C 1000A2AF */   sw        $v0, 0x10($sp)
    /* 9D00 8006D060 21202002 */  addu       $a0, $s1, $zero
    /* 9D04 8006D064 03000524 */  addiu      $a1, $zero, 0x3
    /* 9D08 8006D068 7045000C */  jal        Task_SetState0
    /* 9D0C 8006D06C 000000AE */   sw        $zero, 0x0($s0)
    /* 9D10 8006D070 35B40108 */  j          .L8006D0D4
    /* 9D14 8006D074 00000000 */   nop
  jlabel .L8006D078
    /* 9D18 8006D078 1800308E */  lw         $s0, 0x18($s1)
    /* 9D1C 8006D07C 00000000 */  nop
    /* 9D20 8006D080 03000012 */  beqz       $s0, .L8006D090
    /* 9D24 8006D084 01000224 */   addiu     $v0, $zero, 0x1
    /* 9D28 8006D088 0B000212 */  beq        $s0, $v0, .L8006D0B8
    /* 9D2C 8006D08C 00000000 */   nop
  .L8006D090:
    /* 9D30 8006D090 21202002 */  addu       $a0, $s1, $zero
    /* 9D34 8006D094 37B9010C */  jal        func_8006E4DC
    /* 9D38 8006D098 2B000524 */   addiu     $a1, $zero, 0x2B
    /* 9D3C 8006D09C 35000424 */  addiu      $a0, $zero, 0x35
    /* 9D40 8006D0A0 A369000C */  jal        Snd_PlayById
    /* 9D44 8006D0A4 21280000 */   addu      $a1, $zero, $zero
    /* 9D48 8006D0A8 6045000C */  jal        Task_NextState2
    /* 9D4C 8006D0AC 21202002 */   addu      $a0, $s1, $zero
    /* 9D50 8006D0B0 35B40108 */  j          .L8006D0D4
    /* 9D54 8006D0B4 00000000 */   nop
  .L8006D0B8:
    /* 9D58 8006D0B8 62B9010C */  jal        func_8006E588
    /* 9D5C 8006D0BC 21202002 */   addu      $a0, $s1, $zero
    /* 9D60 8006D0C0 04005014 */  bne        $v0, $s0, .L8006D0D4
    /* 9D64 8006D0C4 21202002 */   addu      $a0, $s1, $zero
    /* 9D68 8006D0C8 02000524 */  addiu      $a1, $zero, 0x2
  .L8006D0CC:
    /* 9D6C 8006D0CC 7745000C */  jal        Task_SetState1
    /* 9D70 8006D0D0 00000000 */   nop
  jlabel .L8006D0D4
    /* 9D74 8006D0D4 2000BF8F */  lw         $ra, 0x20($sp)
    /* 9D78 8006D0D8 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 9D7C 8006D0DC 1800B08F */  lw         $s0, 0x18($sp)
    /* 9D80 8006D0E0 0800E003 */  jr         $ra
    /* 9D84 8006D0E4 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8006CF54
