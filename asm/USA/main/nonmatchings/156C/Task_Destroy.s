nonmatching Task_Destroy, 0x50

glabel Task_Destroy
    /* 16D4 80010ED4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 16D8 80010ED8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 16DC 80010EDC 21808000 */  addu       $s0, $a0, $zero
    /* 16E0 80010EE0 1400BFAF */  sw         $ra, 0x14($sp)
    /* 16E4 80010EE4 0000048E */  lw         $a0, 0x0($s0)
    /* 16E8 80010EE8 00000000 */  nop
    /* 16EC 80010EEC 09008010 */  beqz       $a0, .L80010F14
    /* 16F0 80010EF0 00000000 */   nop
    /* 16F4 80010EF4 7045000C */  jal        Task_SetState0
    /* 16F8 80010EF8 03000524 */   addiu     $a1, $zero, 0x3
  .L80010EFC:
    /* 16FC 80010EFC 0000048E */  lw         $a0, 0x0($s0)
    /* 1700 80010F00 A943000C */  jal        Task_TryRun
    /* 1704 80010F04 00000000 */   nop
    /* 1708 80010F08 FCFF4014 */  bnez       $v0, .L80010EFC
    /* 170C 80010F0C 000002AE */   sw        $v0, 0x0($s0)
    /* 1710 80010F10 000000AE */  sw         $zero, 0x0($s0)
  .L80010F14:
    /* 1714 80010F14 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1718 80010F18 1000B08F */  lw         $s0, 0x10($sp)
    /* 171C 80010F1C 0800E003 */  jr         $ra
    /* 1720 80010F20 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Task_Destroy
