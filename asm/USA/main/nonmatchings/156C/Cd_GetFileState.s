nonmatching Cd_GetFileState, 0x40

glabel Cd_GetFileState
    /* 14370 80023B70 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 14374 80023B74 1000BFAF */  sw         $ra, 0x10($sp)
    /* 14378 80023B78 9E8E000C */  jal        Cd_FindCachedFile
    /* 1437C 80023B7C 00000000 */   nop
    /* 14380 80023B80 21204000 */  addu       $a0, $v0, $zero
    /* 14384 80023B84 03008014 */  bnez       $a0, .L80023B94
    /* 14388 80023B88 0680033C */   lui       $v1, %hi(D_8005F770)
    /* 1438C 80023B8C E88E0008 */  j          .L80023BA0
    /* 14390 80023B90 21100000 */   addu      $v0, $zero, $zero
  .L80023B94:
    /* 14394 80023B94 70F7638C */  lw         $v1, %lo(D_8005F770)($v1)
    /* 14398 80023B98 00008284 */  lh         $v0, 0x0($a0)
    /* 1439C 80023B9C 080083AC */  sw         $v1, 0x8($a0)
  .L80023BA0:
    /* 143A0 80023BA0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 143A4 80023BA4 00000000 */  nop
    /* 143A8 80023BA8 0800E003 */  jr         $ra
    /* 143AC 80023BAC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Cd_GetFileState
