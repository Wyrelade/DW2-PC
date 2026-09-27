nonmatching Task_TryRun, 0x30

glabel Task_TryRun
    /* 16A4 80010EA4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 16A8 80010EA8 05008010 */  beqz       $a0, .L80010EC0
    /* 16AC 80010EAC 1000BFAF */   sw        $ra, 0x10($sp)
    /* 16B0 80010EB0 C943000C */  jal        Task_Run
    /* 16B4 80010EB4 00000000 */   nop
    /* 16B8 80010EB8 B1430008 */  j          .L80010EC4
    /* 16BC 80010EBC 00000000 */   nop
  .L80010EC0:
    /* 16C0 80010EC0 21100000 */  addu       $v0, $zero, $zero
  .L80010EC4:
    /* 16C4 80010EC4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 16C8 80010EC8 00000000 */  nop
    /* 16CC 80010ECC 0800E003 */  jr         $ra
    /* 16D0 80010ED0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Task_TryRun
