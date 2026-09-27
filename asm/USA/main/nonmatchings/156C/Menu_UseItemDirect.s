nonmatching Menu_UseItemDirect, 0xD4

glabel Menu_UseItemDirect
    /* 56A4 80014EA4 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 56A8 80014EA8 0580023C */  lui        $v0, %hi(Menu_Ctx)
    /* 56AC 80014EAC 6807428C */  lw         $v0, %lo(Menu_Ctx)($v0)
    /* 56B0 80014EB0 21300000 */  addu       $a2, $zero, $zero
    /* 56B4 80014EB4 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 56B8 80014EB8 2800B0AF */  sw         $s0, 0x28($sp)
    /* 56BC 80014EBC 2C00908C */  lw         $s0, 0x2C($a0)
    /* 56C0 80014EC0 08014484 */  lh         $a0, 0x108($v0)
    /* 56C4 80014EC4 0A014584 */  lh         $a1, 0x10A($v0)
    /* 56C8 80014EC8 DE49000C */  jal        Item_Use
    /* 56CC 80014ECC 2138C000 */   addu      $a3, $a2, $zero
    /* 56D0 80014ED0 1A004010 */  beqz       $v0, .L80014F3C
    /* 56D4 80014ED4 81000224 */   addiu     $v0, $zero, 0x81
    /* 56D8 80014ED8 FD01043C */  lui        $a0, (0x1FD00FD >> 16)
    /* 56DC 80014EDC FD008434 */  ori        $a0, $a0, (0x1FD00FD & 0xFFFF)
    /* 56E0 80014EE0 0B00888B */  lwl        $t0, %gp_rel(D_80050703)($gp)
    /* 56E4 80014EE4 0800889B */  lwr        $t0, %gp_rel(D_80050700)($gp)
    /* 56E8 80014EE8 00000000 */  nop
    /* 56EC 80014EEC 1F00A8AB */  swl        $t0, 0x1F($sp)
    /* 56F0 80014EF0 1C00A8BB */  swr        $t0, 0x1C($sp)
    /* 56F4 80014EF4 2100A0A3 */  sb         $zero, 0x21($sp)
    /* 56F8 80014EF8 688E000C */  jal        Cd_GetFileEntry
    /* 56FC 80014EFC 2000A2A3 */   sb        $v0, 0x20($sp)
    /* 5700 80014F00 0580033C */  lui        $v1, %hi(Menu_Ctx)
    /* 5704 80014F04 6807638C */  lw         $v1, %lo(Menu_Ctx)($v1)
    /* 5708 80014F08 1000A2AF */  sw         $v0, 0x10($sp)
    /* 570C 80014F0C 08016484 */  lh         $a0, 0x108($v1)
    /* 5710 80014F10 1278000C */  jal        func_8001E048
    /* 5714 80014F14 00000000 */   nop
    /* 5718 80014F18 50000426 */  addiu      $a0, $s0, 0x50
    /* 571C 80014F1C 1000A527 */  addiu      $a1, $sp, 0x10
    /* 5720 80014F20 1C4D000C */  jal        func_80013470
    /* 5724 80014F24 1400A2AF */   sw        $v0, 0x14($sp)
    /* 5728 80014F28 1D000424 */  addiu      $a0, $zero, 0x1D
    /* 572C 80014F2C A369000C */  jal        Snd_PlayById
    /* 5730 80014F30 21280000 */   addu      $a1, $zero, $zero
    /* 5734 80014F34 DA530008 */  j          .L80014F68
    /* 5738 80014F38 00000000 */   nop
  .L80014F3C:
    /* 573C 80014F3C FD01043C */  lui        $a0, (0x1FD00A0 >> 16)
    /* 5740 80014F40 688E000C */  jal        Cd_GetFileEntry
    /* 5744 80014F44 A0008434 */   ori       $a0, $a0, (0x1FD00A0 & 0xFFFF)
    /* 5748 80014F48 50000426 */  addiu      $a0, $s0, 0x50
    /* 574C 80014F4C 21284000 */  addu       $a1, $v0, $zero
    /* 5750 80014F50 81000624 */  addiu      $a2, $zero, 0x81
    /* 5754 80014F54 0A008797 */  lhu        $a3, %gp_rel(D_80050702)($gp)
    /* 5758 80014F58 08008297 */  lhu        $v0, %gp_rel(D_80050700)($gp)
    /* 575C 80014F5C 003C0700 */  sll        $a3, $a3, 16
    /* 5760 80014F60 3E4D000C */  jal        func_800134F8
    /* 5764 80014F64 25384700 */   or        $a3, $v0, $a3
  .L80014F68:
    /* 5768 80014F68 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 576C 80014F6C 2800B08F */  lw         $s0, 0x28($sp)
    /* 5770 80014F70 0800E003 */  jr         $ra
    /* 5774 80014F74 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel Menu_UseItemDirect
