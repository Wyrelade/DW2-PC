nonmatching func_8003DB74, 0x70

glabel func_8003DB74
    /* 2E374 8003DB74 0680013C */  lui        $at, %hi(D_80062F30)
    /* 2E378 8003DB78 302F3FAC */  sw         $ra, %lo(D_80062F30)($at)
    /* 2E37C 8003DB7C F19B000C */  jal        EnterCriticalSection
    /* 2E380 8003DB80 00000000 */   nop
    /* 2E384 8003DB84 57000924 */  addiu      $t1, $zero, 0x57
    /* 2E388 8003DB88 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 2E38C 8003DB8C 09F84001 */  jalr       $t2
    /* 2E390 8003DB90 00000000 */   nop
    /* 2E394 8003DB94 6C01428C */  lw         $v0, 0x16C($v0)
    /* 2E398 8003DB98 00000000 */  nop
    /* 2E39C 8003DB9C C809438C */  lw         $v1, 0x9C8($v0)
    /* 2E3A0 8003DBA0 04800A3C */  lui        $t2, %hi(func_8003DAB8 + 0x14)
    /* 2E3A4 8003DBA4 CCDA4A25 */  addiu      $t2, $t2, %lo(func_8003DAB8 + 0x14)
    /* 2E3A8 8003DBA8 0480093C */  lui        $t1, %hi(func_8003DAE0)
    /* 2E3AC 8003DBAC E0DA2925 */  addiu      $t1, $t1, %lo(func_8003DAE0)
  .L8003DBB0:
    /* 2E3B0 8003DBB0 0000488D */  lw         $t0, 0x0($t2)
    /* 2E3B4 8003DBB4 00000000 */  nop
    /* 2E3B8 8003DBB8 C80948AC */  sw         $t0, 0x9C8($v0)
    /* 2E3BC 8003DBBC 04004A25 */  addiu      $t2, $t2, 0x4
    /* 2E3C0 8003DBC0 FBFF4915 */  bne        $t2, $t1, .L8003DBB0
    /* 2E3C4 8003DBC4 04004224 */   addiu     $v0, $v0, 0x4
    /* 2E3C8 8003DBC8 E9B6000C */  jal        FlushCache
    /* 2E3CC 8003DBCC 00000000 */   nop
    /* 2E3D0 8003DBD0 06801F3C */  lui        $ra, %hi(D_80062F30)
    /* 2E3D4 8003DBD4 302FFF8F */  lw         $ra, %lo(D_80062F30)($ra)
    /* 2E3D8 8003DBD8 00000000 */  nop
    /* 2E3DC 8003DBDC 0800E003 */  jr         $ra
    /* 2E3E0 8003DBE0 00000000 */   nop
endlabel func_8003DB74
