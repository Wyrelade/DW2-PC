nonmatching Cd_LoadFileSync, 0x48

glabel Cd_LoadFileSync
    /* 14568 80023D68 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1456C 80023D6C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 14570 80023D70 21808000 */  addu       $s0, $a0, $zero
    /* 14574 80023D74 1800BFAF */  sw         $ra, 0x18($sp)
    /* 14578 80023D78 FD8E000C */  jal        Cd_QueueFile
    /* 1457C 80023D7C 1400B1AF */   sw        $s1, 0x14($sp)
    /* 14580 80023D80 03001124 */  addiu      $s1, $zero, 0x3
  .L80023D84:
    /* 14584 80023D84 1D8F000C */  jal        Cd_ServiceQueue
    /* 14588 80023D88 00000000 */   nop
    /* 1458C 80023D8C DC8E000C */  jal        Cd_GetFileState
    /* 14590 80023D90 21200002 */   addu      $a0, $s0, $zero
    /* 14594 80023D94 FBFF5114 */  bne        $v0, $s1, .L80023D84
    /* 14598 80023D98 00000000 */   nop
    /* 1459C 80023D9C 1800BF8F */  lw         $ra, 0x18($sp)
    /* 145A0 80023DA0 1400B18F */  lw         $s1, 0x14($sp)
    /* 145A4 80023DA4 1000B08F */  lw         $s0, 0x10($sp)
    /* 145A8 80023DA8 0800E003 */  jr         $ra
    /* 145AC 80023DAC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Cd_LoadFileSync
