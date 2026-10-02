nonmatching func_8003DAE0, 0x94

glabel func_8003DAE0
    /* 2E2E0 8003DAE0 0680013C */  lui        $at, %hi(D_80062F30)
    /* 2E2E4 8003DAE4 302F3FAC */  sw         $ra, %lo(D_80062F30)($at)
    /* 2E2E8 8003DAE8 F19B000C */  jal        EnterCriticalSection
    /* 2E2EC 8003DAEC 00000000 */   nop
    /* 2E2F0 8003DAF0 56000924 */  addiu      $t1, $zero, 0x56
    /* 2E2F4 8003DAF4 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 2E2F8 8003DAF8 09F84001 */  jalr       $t2
    /* 2E2FC 8003DAFC 00000000 */   nop
    /* 2E300 8003DB00 1800428C */  lw         $v0, 0x18($v0)
    /* 2E304 8003DB04 00000000 */  nop
    /* 2E308 8003DB08 7000438C */  lw         $v1, 0x70($v0)
    /* 2E30C 8003DB0C 00000000 */  nop
    /* 2E310 8003DB10 FFFF6930 */  andi       $t1, $v1, 0xFFFF
    /* 2E314 8003DB14 004C0900 */  sll        $t1, $t1, 16
    /* 2E318 8003DB18 7400438C */  lw         $v1, 0x74($v0)
    /* 2E31C 8003DB1C 00000000 */  nop
    /* 2E320 8003DB20 FFFF6A30 */  andi       $t2, $v1, 0xFFFF
    /* 2E324 8003DB24 21182A01 */  addu       $v1, $t1, $t2
    /* 2E328 8003DB28 28006224 */  addiu      $v0, $v1, 0x28
    /* 2E32C 8003DB2C 04800A3C */  lui        $t2, %hi(func_8003DAB8)
    /* 2E330 8003DB30 B8DA4A25 */  addiu      $t2, $t2, %lo(func_8003DAB8)
    /* 2E334 8003DB34 0480093C */  lui        $t1, %hi(func_8003DAB8 + 0x14)
    /* 2E338 8003DB38 CCDA2925 */  addiu      $t1, $t1, %lo(func_8003DAB8 + 0x14)
  .L8003DB3C:
    /* 2E33C 8003DB3C 0000438D */  lw         $v1, 0x0($t2)
    /* 2E340 8003DB40 00000000 */  nop
    /* 2E344 8003DB44 000043AC */  sw         $v1, 0x0($v0)
    /* 2E348 8003DB48 04004A25 */  addiu      $t2, $t2, 0x4
    /* 2E34C 8003DB4C FBFF4915 */  bne        $t2, $t1, .L8003DB3C
    /* 2E350 8003DB50 04004224 */   addiu     $v0, $v0, 0x4
    /* 2E354 8003DB54 0100013C */  lui        $at, (0x10000 >> 16)
    /* 2E358 8003DB58 E9B6000C */  jal        FlushCache
    /* 2E35C 8003DB5C FCDF22AC */   sw        $v0, -0x2004($at)
    /* 2E360 8003DB60 06801F3C */  lui        $ra, %hi(D_80062F30)
    /* 2E364 8003DB64 302FFF8F */  lw         $ra, %lo(D_80062F30)($ra)
    /* 2E368 8003DB68 00000000 */  nop
    /* 2E36C 8003DB6C 0800E003 */  jr         $ra
    /* 2E370 8003DB70 00000000 */   nop
endlabel func_8003DAE0
