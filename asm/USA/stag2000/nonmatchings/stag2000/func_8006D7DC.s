nonmatching func_8006D7DC, 0x160

glabel func_8006D7DC
    /* A47C 8006D7DC D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* A480 8006D7E0 2000B4AF */  sw         $s4, 0x20($sp)
    /* A484 8006D7E4 21A08000 */  addu       $s4, $a0, $zero
    /* A488 8006D7E8 2400BFAF */  sw         $ra, 0x24($sp)
    /* A48C 8006D7EC 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* A490 8006D7F0 1800B2AF */  sw         $s2, 0x18($sp)
    /* A494 8006D7F4 1400B1AF */  sw         $s1, 0x14($sp)
    /* A498 8006D7F8 1000B0AF */  sw         $s0, 0x10($sp)
    /* A49C 8006D7FC 2C00928E */  lw         $s2, 0x2C($s4)
    /* A4A0 8006D800 00000000 */  nop
    /* A4A4 8006D804 5C00428E */  lw         $v0, 0x5C($s2)
    /* A4A8 8006D808 00000000 */  nop
    /* A4AC 8006D80C 43004010 */  beqz       $v0, .L8006D91C
    /* A4B0 8006D810 21880000 */   addu      $s1, $zero, $zero
    /* A4B4 8006D814 5C0040AE */  sw         $zero, 0x5C($s2)
    /* A4B8 8006D818 20001024 */  addiu      $s0, $zero, 0x20
  .L8006D81C:
    /* A4BC 8006D81C E26E000C */  jal        Text_Close
    /* A4C0 8006D820 21205002 */   addu      $a0, $s2, $s0
    /* A4C4 8006D824 01003126 */  addiu      $s1, $s1, 0x1
    /* A4C8 8006D828 0A00222A */  slti       $v0, $s1, 0xA
    /* A4CC 8006D82C FBFF4014 */  bnez       $v0, .L8006D81C
    /* A4D0 8006D830 04001026 */   addiu     $s0, $s0, 0x4
    /* A4D4 8006D834 21880000 */  addu       $s1, $zero, $zero
    /* A4D8 8006D838 0780023C */  lui        $v0, %hi(D_800705DC)
    /* A4DC 8006D83C DC055324 */  addiu      $s3, $v0, %lo(D_800705DC)
    /* A4E0 8006D840 20001024 */  addiu      $s0, $zero, 0x20
  .L8006D844:
    /* A4E4 8006D844 C401428E */  lw         $v0, 0x1C4($s2)
    /* A4E8 8006D848 00000000 */  nop
    /* A4EC 8006D84C 21102202 */  addu       $v0, $s1, $v0
    /* A4F0 8006D850 40100200 */  sll        $v0, $v0, 1
    /* A4F4 8006D854 21104202 */  addu       $v0, $s2, $v0
    /* A4F8 8006D858 EC004484 */  lh         $a0, 0xEC($v0)
    /* A4FC 8006D85C 00000000 */  nop
    /* A500 8006D860 15008010 */  beqz       $a0, .L8006D8B8
    /* A504 8006D864 00000000 */   nop
    /* A508 8006D868 1278000C */  jal        Item_GetNameText
    /* A50C 8006D86C 00000000 */   nop
    /* A510 8006D870 21205002 */  addu       $a0, $s2, $s0
    /* A514 8006D874 21284000 */  addu       $a1, $v0, $zero
    /* A518 8006D878 21101302 */  addu       $v0, $s0, $s3
    /* A51C 8006D87C 04001026 */  addiu      $s0, $s0, 0x4
    /* A520 8006D880 02004794 */  lhu        $a3, 0x2($v0)
    /* A524 8006D884 00004394 */  lhu        $v1, 0x0($v0)
    /* A528 8006D888 C401428E */  lw         $v0, 0x1C4($s2)
    /* A52C 8006D88C 003C0700 */  sll        $a3, $a3, 16
    /* A530 8006D890 25386700 */  or         $a3, $v1, $a3
    /* A534 8006D894 21102202 */  addu       $v0, $s1, $v0
    /* A538 8006D898 21104202 */  addu       $v0, $s2, $v0
    /* A53C 8006D89C 72014690 */  lbu        $a2, 0x172($v0)
    /* A540 8006D8A0 01003126 */  addiu      $s1, $s1, 0x1
    /* A544 8006D8A4 3E4D000C */  jal        Text_OpenPacked
    /* A548 8006D8A8 80300600 */   sll       $a2, $a2, 2
    /* A54C 8006D8AC 0A00222A */  slti       $v0, $s1, 0xA
    /* A550 8006D8B0 E4FF4014 */  bnez       $v0, .L8006D844
    /* A554 8006D8B4 00000000 */   nop
  .L8006D8B8:
    /* A558 8006D8B8 1800838E */  lw         $v1, 0x18($s4)
    /* A55C 8006D8BC 02000224 */  addiu      $v0, $zero, 0x2
    /* A560 8006D8C0 16006214 */  bne        $v1, $v0, .L8006D91C
    /* A564 8006D8C4 1C005026 */   addiu     $s0, $s2, 0x1C
    /* A568 8006D8C8 E26E000C */  jal        Text_Close
    /* A56C 8006D8CC 21200002 */   addu      $a0, $s0, $zero
    /* A570 8006D8D0 C401428E */  lw         $v0, 0x1C4($s2)
    /* A574 8006D8D4 C001438E */  lw         $v1, 0x1C0($s2)
    /* A578 8006D8D8 00000000 */  nop
    /* A57C 8006D8DC 21104300 */  addu       $v0, $v0, $v1
    /* A580 8006D8E0 40100200 */  sll        $v0, $v0, 1
    /* A584 8006D8E4 21104202 */  addu       $v0, $s2, $v0
    /* A588 8006D8E8 EC004584 */  lh         $a1, 0xEC($v0)
    /* A58C 8006D8EC 00000000 */  nop
    /* A590 8006D8F0 0A00A010 */  beqz       $a1, .L8006D91C
    /* A594 8006D8F4 21200002 */   addu      $a0, $s0, $zero
    /* A598 8006D8F8 E803A524 */  addiu      $a1, $a1, 0x3E8
    /* A59C 8006D8FC 21380000 */  addu       $a3, $zero, $zero
    /* A5A0 8006D900 0780023C */  lui        $v0, %hi(D_800705DC)
    /* A5A4 8006D904 DC054224 */  addiu      $v0, $v0, %lo(D_800705DC)
    /* A5A8 8006D908 1E004694 */  lhu        $a2, 0x1E($v0)
    /* A5AC 8006D90C 1C004294 */  lhu        $v0, 0x1C($v0)
    /* A5B0 8006D910 00340600 */  sll        $a2, $a2, 16
    /* A5B4 8006D914 B0B4010C */  jal        func_8006D2C0
    /* A5B8 8006D918 25304600 */   or        $a2, $v0, $a2
  .L8006D91C:
    /* A5BC 8006D91C 2400BF8F */  lw         $ra, 0x24($sp)
    /* A5C0 8006D920 2000B48F */  lw         $s4, 0x20($sp)
    /* A5C4 8006D924 1C00B38F */  lw         $s3, 0x1C($sp)
    /* A5C8 8006D928 1800B28F */  lw         $s2, 0x18($sp)
    /* A5CC 8006D92C 1400B18F */  lw         $s1, 0x14($sp)
    /* A5D0 8006D930 1000B08F */  lw         $s0, 0x10($sp)
    /* A5D4 8006D934 0800E003 */  jr         $ra
    /* A5D8 8006D938 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8006D7DC
