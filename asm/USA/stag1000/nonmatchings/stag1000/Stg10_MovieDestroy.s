nonmatching Stg10_MovieDestroy, 0xD8

glabel Stg10_MovieDestroy
    /* 101C 8006437C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1020 80064380 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1024 80064384 21808000 */  addu       $s0, $a0, $zero
    /* 1028 80064388 09000424 */  addiu      $a0, $zero, 0x9
    /* 102C 8006438C 21280000 */  addu       $a1, $zero, $zero
    /* 1030 80064390 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1034 80064394 F1C1000C */  jal        CdControlB
    /* 1038 80064398 2130A000 */   addu      $a2, $a1, $zero
    /* 103C 8006439C 5792010C */  jal        DecDCToutCallback
    /* 1040 800643A0 21200000 */   addu      $a0, $zero, $zero
    /* 1044 800643A4 BDB7000C */  jal        StUnSetRing
    /* 1048 800643A8 00000000 */   nop
    /* 104C 800643AC 0680023C */  lui        $v0, %hi(Stg10_StrRingBuf)
    /* 1050 800643B0 E861448C */  lw         $a0, %lo(Stg10_StrRingBuf)($v0)
    /* 1054 800643B4 618B000C */  jal        Mem_Free
    /* 1058 800643B8 00000000 */   nop
    /* 105C 800643BC 0680023C */  lui        $v0, %hi(Stg10_VlcBuf0)
    /* 1060 800643C0 EC61448C */  lw         $a0, %lo(Stg10_VlcBuf0)($v0)
    /* 1064 800643C4 618B000C */  jal        Mem_Free
    /* 1068 800643C8 00000000 */   nop
    /* 106C 800643CC 0680023C */  lui        $v0, %hi(Stg10_VlcBuf1)
    /* 1070 800643D0 F061448C */  lw         $a0, %lo(Stg10_VlcBuf1)($v0)
    /* 1074 800643D4 618B000C */  jal        Mem_Free
    /* 1078 800643D8 00000000 */   nop
    /* 107C 800643DC 0680023C */  lui        $v0, %hi(Stg10_ImgBuf0)
    /* 1080 800643E0 F461448C */  lw         $a0, %lo(Stg10_ImgBuf0)($v0)
    /* 1084 800643E4 618B000C */  jal        Mem_Free
    /* 1088 800643E8 00000000 */   nop
    /* 108C 800643EC 0680023C */  lui        $v0, %hi(Stg10_ImgBuf1)
    /* 1090 800643F0 F861448C */  lw         $a0, %lo(Stg10_ImgBuf1)($v0)
    /* 1094 800643F4 618B000C */  jal        Mem_Free
    /* 1098 800643F8 00000000 */   nop
    /* 109C 800643FC 0680023C */  lui        $v0, %hi(Stg10_VlcTable)
    /* 10A0 80064400 4062448C */  lw         $a0, %lo(Stg10_VlcTable)($v0)
    /* 10A4 80064404 618B000C */  jal        Mem_Free
    /* 10A8 80064408 00000000 */   nop
    /* 10AC 8006440C 21200002 */  addu       $a0, $s0, $zero
    /* 10B0 80064410 0580023C */  lui        $v0, %hi(D_80050741)
    /* 10B4 80064414 5C44000C */  jal        Task_DefaultDestroy
    /* 10B8 80064418 410740A0 */   sb        $zero, %lo(D_80050741)($v0)
    /* 10BC 8006441C 419C000C */  jal        ResetGraph
    /* 10C0 80064420 01000424 */   addiu     $a0, $zero, 0x1
    /* 10C4 80064424 0680043C */  lui        $a0, %hi(Stg10_VramClearRect2)
    /* 10C8 80064428 28528424 */  addiu      $a0, $a0, %lo(Stg10_VramClearRect2)
    /* 10CC 8006442C 21280000 */  addu       $a1, $zero, $zero
    /* 10D0 80064430 2130A000 */  addu       $a2, $a1, $zero
    /* 10D4 80064434 A59D000C */  jal        ClearImage2
    /* 10D8 80064438 2138A000 */   addu      $a3, $a1, $zero
    /* 10DC 8006443C 209D000C */  jal        DrawSync
    /* 10E0 80064440 21200000 */   addu      $a0, $zero, $zero
    /* 10E4 80064444 1400BF8F */  lw         $ra, 0x14($sp)
    /* 10E8 80064448 1000B08F */  lw         $s0, 0x10($sp)
    /* 10EC 8006444C 0800E003 */  jr         $ra
    /* 10F0 80064450 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg10_MovieDestroy
