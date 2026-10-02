nonmatching func_8002DAC4, 0xAC

glabel func_8002DAC4
    /* 1E2C4 8002DAC4 0680013C */  lui        $at, %hi(D_80061AE8)
    /* 1E2C8 8002DAC8 E81A3FAC */  sw         $ra, %lo(D_80061AE8)($at)
    /* 1E2CC 8002DACC F19B000C */  jal        EnterCriticalSection
    /* 1E2D0 8002DAD0 00000000 */   nop
    /* 1E2D4 8002DAD4 56000924 */  addiu      $t1, $zero, 0x56
    /* 1E2D8 8002DAD8 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 1E2DC 8002DADC 09F84001 */  jalr       $t2
    /* 1E2E0 8002DAE0 00000000 */   nop
    /* 1E2E4 8002DAE4 1800428C */  lw         $v0, 0x18($v0)
    /* 1E2E8 8002DAE8 00000000 */  nop
    /* 1E2EC 8002DAEC 28004224 */  addiu      $v0, $v0, 0x28
    /* 1E2F0 8002DAF0 21784000 */  addu       $t7, $v0, $zero
    /* 1E2F4 8002DAF4 03800A3C */  lui        $t2, %hi(func_8002DB70)
    /* 1E2F8 8002DAF8 70DB4A25 */  addiu      $t2, $t2, %lo(func_8002DB70)
    /* 1E2FC 8002DAFC 0380093C */  lui        $t1, %hi(D_8002DB88)
    /* 1E300 8002DB00 88DB2925 */  addiu      $t1, $t1, %lo(D_8002DB88)
  .L8002DB04:
    /* 1E304 8002DB04 0000438D */  lw         $v1, 0x0($t2)
    /* 1E308 8002DB08 00004B8C */  lw         $t3, 0x0($v0)
    /* 1E30C 8002DB0C 04004A25 */  addiu      $t2, $t2, 0x4
    /* 1E310 8002DB10 0E006B14 */  bne        $v1, $t3, .L8002DB4C
    /* 1E314 8002DB14 04004224 */   addiu     $v0, $v0, 0x4
    /* 1E318 8002DB18 FAFF4915 */  bne        $t2, $t1, .L8002DB04
    /* 1E31C 8002DB1C 00000000 */   nop
    /* 1E320 8002DB20 2110E001 */  addu       $v0, $t7, $zero
    /* 1E324 8002DB24 03800A3C */  lui        $t2, %hi(D_8002DB88)
    /* 1E328 8002DB28 88DB4A25 */  addiu      $t2, $t2, %lo(D_8002DB88)
    /* 1E32C 8002DB2C 0380093C */  lui        $t1, %hi(D_8002DBA0)
    /* 1E330 8002DB30 A0DB2925 */  addiu      $t1, $t1, %lo(D_8002DBA0)
  .L8002DB34:
    /* 1E334 8002DB34 0000438D */  lw         $v1, 0x0($t2)
    /* 1E338 8002DB38 00000000 */  nop
    /* 1E33C 8002DB3C 000043AC */  sw         $v1, 0x0($v0)
    /* 1E340 8002DB40 04004A25 */  addiu      $t2, $t2, 0x4
    /* 1E344 8002DB44 FBFF4915 */  bne        $t2, $t1, .L8002DB34
    /* 1E348 8002DB48 04004224 */   addiu     $v0, $v0, 0x4
  .L8002DB4C:
    /* 1E34C 8002DB4C E9B6000C */  jal        FlushCache
    /* 1E350 8002DB50 00000000 */   nop
    /* 1E354 8002DB54 F59B000C */  jal        ExitCriticalSection
    /* 1E358 8002DB58 00000000 */   nop
    /* 1E35C 8002DB5C 06801F3C */  lui        $ra, %hi(D_80061AE8)
    /* 1E360 8002DB60 E81AFF8F */  lw         $ra, %lo(D_80061AE8)($ra)
    /* 1E364 8002DB64 00000000 */  nop
    /* 1E368 8002DB68 0800E003 */  jr         $ra
    /* 1E36C 8002DB6C 00000000 */   nop
endlabel func_8002DAC4
