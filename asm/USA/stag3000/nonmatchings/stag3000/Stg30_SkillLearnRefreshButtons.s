nonmatching Stg30_SkillLearnRefreshButtons, 0xE4

glabel Stg30_SkillLearnRefreshButtons
    /* EC3C 80071F9C D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* EC40 80071FA0 2000B4AF */  sw         $s4, 0x20($sp)
    /* EC44 80071FA4 21A08000 */  addu       $s4, $a0, $zero
    /* EC48 80071FA8 1000B0AF */  sw         $s0, 0x10($sp)
    /* EC4C 80071FAC 21800000 */  addu       $s0, $zero, $zero
    /* EC50 80071FB0 0780023C */  lui        $v0, %hi(D_80073730)
    /* EC54 80071FB4 2400B5AF */  sw         $s5, 0x24($sp)
    /* EC58 80071FB8 30375524 */  addiu      $s5, $v0, %lo(D_80073730)
    /* EC5C 80071FBC 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* EC60 80071FC0 60001324 */  addiu      $s3, $zero, 0x60
    /* EC64 80071FC4 1800B2AF */  sw         $s2, 0x18($sp)
    /* EC68 80071FC8 64001224 */  addiu      $s2, $zero, 0x64
    /* EC6C 80071FCC 2800BFAF */  sw         $ra, 0x28($sp)
    /* EC70 80071FD0 1400B1AF */  sw         $s1, 0x14($sp)
    /* EC74 80071FD4 2C00918E */  lw         $s1, 0x2C($s4)
  .L80071FD8:
    /* EC78 80071FD8 E26E000C */  jal        Text_Close
    /* EC7C 80071FDC 21203202 */   addu      $a0, $s1, $s2
    /* EC80 80071FE0 C800228E */  lw         $v0, 0xC8($s1)
    /* EC84 80071FE4 00000000 */  nop
    /* EC88 80071FE8 0A004010 */  beqz       $v0, .L80072014
    /* EC8C 80071FEC 00000000 */   nop
    /* EC90 80071FF0 C400228E */  lw         $v0, 0xC4($s1)
    /* EC94 80071FF4 00000000 */  nop
    /* EC98 80071FF8 07005014 */  bne        $v0, $s0, .L80072018
    /* EC9C 80071FFC 00000000 */   nop
    /* ECA0 80072000 2800828E */  lw         $v0, 0x28($s4)
    /* ECA4 80072004 00000000 */  nop
    /* ECA8 80072008 10004230 */  andi       $v0, $v0, 0x10
    /* ECAC 8007200C 0E004014 */  bnez       $v0, .L80072048
    /* ECB0 80072010 00000000 */   nop
  .L80072014:
    /* ECB4 80072014 C400228E */  lw         $v0, 0xC4($s1)
  .L80072018:
    /* ECB8 80072018 00000000 */  nop
    /* ECBC 8007201C 02005014 */  bne        $v0, $s0, .L80072028
    /* ECC0 80072020 05000624 */   addiu     $a2, $zero, 0x5
    /* ECC4 80072024 04000624 */  addiu      $a2, $zero, 0x4
  .L80072028:
    /* ECC8 80072028 21107502 */  addu       $v0, $s3, $s5
    /* ECCC 8007202C 21203202 */  addu       $a0, $s1, $s2
    /* ECD0 80072030 88010526 */  addiu      $a1, $s0, 0x188
    /* ECD4 80072034 02004794 */  lhu        $a3, 0x2($v0)
    /* ECD8 80072038 00004294 */  lhu        $v0, 0x0($v0)
    /* ECDC 8007203C 003C0700 */  sll        $a3, $a3, 16
    /* ECE0 80072040 F26F000C */  jal        Text_OpenById
    /* ECE4 80072044 25384700 */   or        $a3, $v0, $a3
  .L80072048:
    /* ECE8 80072048 04007326 */  addiu      $s3, $s3, 0x4
    /* ECEC 8007204C 01001026 */  addiu      $s0, $s0, 0x1
    /* ECF0 80072050 0300022A */  slti       $v0, $s0, 0x3
    /* ECF4 80072054 E0FF4014 */  bnez       $v0, .L80071FD8
    /* ECF8 80072058 04005226 */   addiu     $s2, $s2, 0x4
    /* ECFC 8007205C 2800BF8F */  lw         $ra, 0x28($sp)
    /* ED00 80072060 2400B58F */  lw         $s5, 0x24($sp)
    /* ED04 80072064 2000B48F */  lw         $s4, 0x20($sp)
    /* ED08 80072068 1C00B38F */  lw         $s3, 0x1C($sp)
    /* ED0C 8007206C 1800B28F */  lw         $s2, 0x18($sp)
    /* ED10 80072070 1400B18F */  lw         $s1, 0x14($sp)
    /* ED14 80072074 1000B08F */  lw         $s0, 0x10($sp)
    /* ED18 80072078 0800E003 */  jr         $ra
    /* ED1C 8007207C 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel Stg30_SkillLearnRefreshButtons
