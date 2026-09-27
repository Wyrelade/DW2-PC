nonmatching restartIntr, 0x78

glabel restartIntr
    /* 21AF8 800312F8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 21AFC 800312FC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 21B00 80031300 0580103C */  lui        $s0, %hi(D_8004EAF8)
    /* 21B04 80031304 F8EA1026 */  addiu      $s0, $s0, %lo(D_8004EAF8)
    /* 21B08 80031308 1400BFAF */  sw         $ra, 0x14($sp)
    /* 21B0C 8003130C 00000296 */  lhu        $v0, 0x0($s0)
    /* 21B10 80031310 00000000 */  nop
    /* 21B14 80031314 11004014 */  bnez       $v0, .L8003135C
    /* 21B18 80031318 00000000 */   nop
    /* 21B1C 8003131C F5C4000C */  jal        HookEntryInt
    /* 21B20 80031320 38000426 */   addiu     $a0, $s0, 0x38
    /* 21B24 80031324 0580043C */  lui        $a0, %hi(Sys_IntrMaskPtr)
    /* 21B28 80031328 88FB848C */  lw         $a0, %lo(Sys_IntrMaskPtr)($a0)
    /* 21B2C 8003132C 32000396 */  lhu        $v1, 0x32($s0)
    /* 21B30 80031330 01000224 */  addiu      $v0, $zero, 0x1
    /* 21B34 80031334 000002A6 */  sh         $v0, 0x0($s0)
    /* 21B38 80031338 000083A4 */  sh         $v1, 0x0($a0)
    /* 21B3C 8003133C 0580033C */  lui        $v1, %hi(D_8004FB8C)
    /* 21B40 80031340 8CFB638C */  lw         $v1, %lo(D_8004FB8C)($v1)
    /* 21B44 80031344 3400028E */  lw         $v0, 0x34($s0)
    /* 21B48 80031348 00000000 */  nop
    /* 21B4C 8003134C F59B000C */  jal        ExitCriticalSection
    /* 21B50 80031350 000062AC */   sw        $v0, 0x0($v1)
    /* 21B54 80031354 D8C40008 */  j          .L80031360
    /* 21B58 80031358 21100002 */   addu      $v0, $s0, $zero
  .L8003135C:
    /* 21B5C 8003135C 21100000 */  addu       $v0, $zero, $zero
  .L80031360:
    /* 21B60 80031360 1400BF8F */  lw         $ra, 0x14($sp)
    /* 21B64 80031364 1000B08F */  lw         $s0, 0x10($sp)
    /* 21B68 80031368 0800E003 */  jr         $ra
    /* 21B6C 8003136C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel restartIntr
