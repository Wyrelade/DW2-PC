nonmatching Menu_UseItemOnTarget, 0x11C

glabel Menu_UseItemOnTarget
    /* 5F70 80015770 0680023C */  lui        $v0, %hi(D_8005F704)
    /* 5F74 80015774 04F7428C */  lw         $v0, %lo(D_8005F704)($v0)
    /* 5F78 80015778 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 5F7C 8001577C 3000B2AF */  sw         $s2, 0x30($sp)
    /* 5F80 80015780 21908000 */  addu       $s2, $a0, $zero
    /* 5F84 80015784 3400BFAF */  sw         $ra, 0x34($sp)
    /* 5F88 80015788 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 5F8C 8001578C 2800B0AF */  sw         $s0, 0x28($sp)
    /* 5F90 80015790 2C00518E */  lw         $s1, 0x2C($s2)
    /* 5F94 80015794 37004018 */  blez       $v0, .L80015874
    /* 5F98 80015798 88002426 */   addiu     $a0, $s1, 0x88
    /* 5F9C 8001579C 9C4E000C */  jal        Menu_GridIndexColMajor
    /* 5FA0 800157A0 8C002526 */   addiu     $a1, $s1, 0x8C
    /* 5FA4 800157A4 7400838F */  lw         $v1, %gp_rel(D_8005076C)($gp)
    /* 5FA8 800157A8 00000000 */  nop
    /* 5FAC 800157AC 21186200 */  addu       $v1, $v1, $v0
    /* 5FB0 800157B0 00007090 */  lbu        $s0, 0x0($v1)
    /* 5FB4 800157B4 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 5FB8 800157B8 2B000212 */  beq        $s0, $v0, .L80015868
    /* 5FBC 800157BC 21300002 */   addu      $a2, $s0, $zero
    /* 5FC0 800157C0 0580023C */  lui        $v0, %hi(Menu_Ctx)
    /* 5FC4 800157C4 6807428C */  lw         $v0, %lo(Menu_Ctx)($v0)
    /* 5FC8 800157C8 00000000 */  nop
    /* 5FCC 800157CC 08014484 */  lh         $a0, 0x108($v0)
    /* 5FD0 800157D0 0A014584 */  lh         $a1, 0x10A($v0)
    /* 5FD4 800157D4 DE49000C */  jal        Item_Use
    /* 5FD8 800157D8 21380000 */   addu      $a3, $zero, $zero
    /* 5FDC 800157DC 22004010 */  beqz       $v0, .L80015868
    /* 5FE0 800157E0 FD01043C */   lui       $a0, (0x1FD00FC >> 16)
    /* 5FE4 800157E4 FC008434 */  ori        $a0, $a0, (0x1FD00FC & 0xFFFF)
    /* 5FE8 800157E8 81000224 */  addiu      $v0, $zero, 0x81
    /* 5FEC 800157EC 0B00888B */  lwl        $t0, %gp_rel(D_80050703)($gp)
    /* 5FF0 800157F0 0800889B */  lwr        $t0, %gp_rel(D_80050700)($gp)
    /* 5FF4 800157F4 00000000 */  nop
    /* 5FF8 800157F8 1F00A8AB */  swl        $t0, 0x1F($sp)
    /* 5FFC 800157FC 1C00A8BB */  swr        $t0, 0x1C($sp)
    /* 6000 80015800 2100A0A3 */  sb         $zero, 0x21($sp)
    /* 6004 80015804 688E000C */  jal        Cd_GetFileEntry
    /* 6008 80015808 2000A2A3 */   sb        $v0, 0x20($sp)
    /* 600C 8001580C 1000A2AF */  sw         $v0, 0x10($sp)
    /* 6010 80015810 0580023C */  lui        $v0, %hi(D_80050720)
    /* 6014 80015814 2007428C */  lw         $v0, %lo(D_80050720)($v0)
    /* 6018 80015818 40181000 */  sll        $v1, $s0, 1
    /* 601C 8001581C 21104300 */  addu       $v0, $v0, $v1
    /* 6020 80015820 2C004494 */  lhu        $a0, 0x2C($v0)
    /* 6024 80015824 1278000C */  jal        func_8001E048
    /* 6028 80015828 00000000 */   nop
    /* 602C 8001582C 50002426 */  addiu      $a0, $s1, 0x50
    /* 6030 80015830 1000A527 */  addiu      $a1, $sp, 0x10
    /* 6034 80015834 1C4D000C */  jal        func_80013470
    /* 6038 80015838 1400A2AF */   sw        $v0, 0x14($sp)
    /* 603C 8001583C 21204002 */  addu       $a0, $s2, $zero
    /* 6040 80015840 A654000C */  jal        func_80015298
    /* 6044 80015844 21280000 */   addu      $a1, $zero, $zero
    /* 6048 80015848 1D000424 */  addiu      $a0, $zero, 0x1D
    /* 604C 8001584C A369000C */  jal        Snd_PlayById
    /* 6050 80015850 21280000 */   addu      $a1, $zero, $zero
    /* 6054 80015854 21204002 */  addu       $a0, $s2, $zero
    /* 6058 80015858 7745000C */  jal        Task_SetState1
    /* 605C 8001585C 03000524 */   addiu     $a1, $zero, 0x3
    /* 6060 80015860 1D560008 */  j          .L80015874
    /* 6064 80015864 00000000 */   nop
  .L80015868:
    /* 6068 80015868 10000424 */  addiu      $a0, $zero, 0x10
    /* 606C 8001586C A369000C */  jal        Snd_PlayById
    /* 6070 80015870 21280000 */   addu      $a1, $zero, $zero
  .L80015874:
    /* 6074 80015874 3400BF8F */  lw         $ra, 0x34($sp)
    /* 6078 80015878 3000B28F */  lw         $s2, 0x30($sp)
    /* 607C 8001587C 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 6080 80015880 2800B08F */  lw         $s0, 0x28($sp)
    /* 6084 80015884 0800E003 */  jr         $ra
    /* 6088 80015888 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel Menu_UseItemOnTarget
