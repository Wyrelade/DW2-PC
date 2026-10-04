nonmatching Stg20_GetPartFitMsg, 0x1F4

glabel Stg20_GetPartFitMsg
    /* 8E64 8006C1C4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 8E68 8006C1C8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 8E6C 8006C1CC 1400BFAF */  sw         $ra, 0x14($sp)
    /* 8E70 8006C1D0 63B0010C */  jal        Stg20_IsPartInstalled
    /* 8E74 8006C1D4 21808000 */   addu      $s0, $a0, $zero
    /* 8E78 8006C1D8 73004014 */  bnez       $v0, .L8006C3A8
    /* 8E7C 8006C1DC 32010224 */   addiu     $v0, $zero, 0x132
    /* 8E80 8006C1E0 0780043C */  lui        $a0, %hi(Stg20_PartsAnyBody)
    /* 8E84 8006C1E4 FC048424 */  addiu      $a0, $a0, %lo(Stg20_PartsAnyBody)
    /* 8E88 8006C1E8 53B0010C */  jal        Stg20_ByteListHas
    /* 8E8C 8006C1EC 21280002 */   addu      $a1, $s0, $zero
    /* 8E90 8006C1F0 6D004014 */  bnez       $v0, .L8006C3A8
    /* 8E94 8006C1F4 31010224 */   addiu     $v0, $zero, 0x131
    /* 8E98 8006C1F8 0780043C */  lui        $a0, %hi(Stg20_ShooterGunAmmo)
    /* 8E9C 8006C1FC 30058424 */  addiu      $a0, $a0, %lo(Stg20_ShooterGunAmmo)
    /* 8EA0 8006C200 53B0010C */  jal        Stg20_ByteListHas
    /* 8EA4 8006C204 21280002 */   addu      $a1, $s0, $zero
    /* 8EA8 8006C208 07004010 */  beqz       $v0, .L8006C228
    /* 8EAC 8006C20C 0680023C */   lui       $v0, %hi(D_8005E65C)
    /* 8EB0 8006C210 5CE64394 */  lhu        $v1, %lo(D_8005E65C)($v0)
    /* 8EB4 8006C214 00000000 */  nop
    /* 8EB8 8006C218 63006014 */  bnez       $v1, .L8006C3A8
    /* 8EBC 8006C21C 2F010224 */   addiu     $v0, $zero, 0x12F
    /* 8EC0 8006C220 EAB00108 */  j          .L8006C3A8
    /* 8EC4 8006C224 30010224 */   addiu     $v0, $zero, 0x130
  .L8006C228:
    /* 8EC8 8006C228 0780043C */  lui        $a0, %hi(Stg20_ZCannonAmmo)
    /* 8ECC 8006C22C 48058424 */  addiu      $a0, $a0, %lo(Stg20_ZCannonAmmo)
    /* 8ED0 8006C230 53B0010C */  jal        Stg20_ByteListHas
    /* 8ED4 8006C234 21280002 */   addu      $a1, $s0, $zero
    /* 8ED8 8006C238 07004010 */  beqz       $v0, .L8006C258
    /* 8EDC 8006C23C 0680023C */   lui       $v0, %hi(D_8005E65E)
    /* 8EE0 8006C240 5EE64394 */  lhu        $v1, %lo(D_8005E65E)($v0)
    /* 8EE4 8006C244 00000000 */  nop
    /* 8EE8 8006C248 57006014 */  bnez       $v1, .L8006C3A8
    /* 8EEC 8006C24C 2F010224 */   addiu     $v0, $zero, 0x12F
    /* 8EF0 8006C250 EAB00108 */  j          .L8006C3A8
    /* 8EF4 8006C254 33010224 */   addiu     $v0, $zero, 0x133
  .L8006C258:
    /* 8EF8 8006C258 0780043C */  lui        $a0, %hi(Stg20_MissileGunAmmo)
    /* 8EFC 8006C25C A4058424 */  addiu      $a0, $a0, %lo(Stg20_MissileGunAmmo)
    /* 8F00 8006C260 53B0010C */  jal        Stg20_ByteListHas
    /* 8F04 8006C264 21280002 */   addu      $a1, $s0, $zero
    /* 8F08 8006C268 07004010 */  beqz       $v0, .L8006C288
    /* 8F0C 8006C26C 0680023C */   lui       $v0, %hi(D_8005E662)
    /* 8F10 8006C270 62E64394 */  lhu        $v1, %lo(D_8005E662)($v0)
    /* 8F14 8006C274 00000000 */  nop
    /* 8F18 8006C278 4B006014 */  bnez       $v1, .L8006C3A8
    /* 8F1C 8006C27C 2F010224 */   addiu     $v0, $zero, 0x12F
    /* 8F20 8006C280 EAB00108 */  j          .L8006C3A8
    /* 8F24 8006C284 35010224 */   addiu     $v0, $zero, 0x135
  .L8006C288:
    /* 8F28 8006C288 0780043C */  lui        $a0, %hi(Stg20_RCannonAmmo)
    /* 8F2C 8006C28C B4058424 */  addiu      $a0, $a0, %lo(Stg20_RCannonAmmo)
    /* 8F30 8006C290 53B0010C */  jal        Stg20_ByteListHas
    /* 8F34 8006C294 21280002 */   addu      $a1, $s0, $zero
    /* 8F38 8006C298 07004010 */  beqz       $v0, .L8006C2B8
    /* 8F3C 8006C29C 0680023C */   lui       $v0, %hi(D_8005E660)
    /* 8F40 8006C2A0 60E64394 */  lhu        $v1, %lo(D_8005E660)($v0)
    /* 8F44 8006C2A4 00000000 */  nop
    /* 8F48 8006C2A8 3F006014 */  bnez       $v1, .L8006C3A8
    /* 8F4C 8006C2AC 2F010224 */   addiu     $v0, $zero, 0x12F
    /* 8F50 8006C2B0 EAB00108 */  j          .L8006C3A8
    /* 8F54 8006C2B4 36010224 */   addiu     $v0, $zero, 0x136
  .L8006C2B8:
    /* 8F58 8006C2B8 0780043C */  lui        $a0, %hi(Stg20_PartsAdmantOnly)
    /* 8F5C 8006C2BC 54058424 */  addiu      $a0, $a0, %lo(Stg20_PartsAdmantOnly)
    /* 8F60 8006C2C0 53B0010C */  jal        Stg20_ByteListHas
    /* 8F64 8006C2C4 21280002 */   addu      $a1, $s0, $zero
    /* 8F68 8006C2C8 07004010 */  beqz       $v0, .L8006C2E8
    /* 8F6C 8006C2CC 0680033C */   lui       $v1, %hi(D_8005E64C)
    /* 8F70 8006C2D0 4CE66494 */  lhu        $a0, %lo(D_8005E64C)($v1)
    /* 8F74 8006C2D4 EC000324 */  addiu      $v1, $zero, 0xEC
    /* 8F78 8006C2D8 33008310 */  beq        $a0, $v1, .L8006C3A8
    /* 8F7C 8006C2DC 31010224 */   addiu     $v0, $zero, 0x131
    /* 8F80 8006C2E0 EAB00108 */  j          .L8006C3A8
    /* 8F84 8006C2E4 34010224 */   addiu     $v0, $zero, 0x134
  .L8006C2E8:
    /* 8F88 8006C2E8 0780043C */  lui        $a0, %hi(Stg20_PartsSteelOnly)
    /* 8F8C 8006C2EC 70058424 */  addiu      $a0, $a0, %lo(Stg20_PartsSteelOnly)
    /* 8F90 8006C2F0 53B0010C */  jal        Stg20_ByteListHas
    /* 8F94 8006C2F4 21280002 */   addu      $a1, $s0, $zero
    /* 8F98 8006C2F8 07004010 */  beqz       $v0, .L8006C318
    /* 8F9C 8006C2FC 0680033C */   lui       $v1, %hi(D_8005E64C)
    /* 8FA0 8006C300 4CE66494 */  lhu        $a0, %lo(D_8005E64C)($v1)
    /* 8FA4 8006C304 EA000324 */  addiu      $v1, $zero, 0xEA
    /* 8FA8 8006C308 27008310 */  beq        $a0, $v1, .L8006C3A8
    /* 8FAC 8006C30C 31010224 */   addiu     $v0, $zero, 0x131
    /* 8FB0 8006C310 EAB00108 */  j          .L8006C3A8
    /* 8FB4 8006C314 34010224 */   addiu     $v0, $zero, 0x134
  .L8006C318:
    /* 8FB8 8006C318 0780043C */  lui        $a0, %hi(Stg20_PartsTitanOnly)
    /* 8FBC 8006C31C 88058424 */  addiu      $a0, $a0, %lo(Stg20_PartsTitanOnly)
    /* 8FC0 8006C320 53B0010C */  jal        Stg20_ByteListHas
    /* 8FC4 8006C324 21280002 */   addu      $a1, $s0, $zero
    /* 8FC8 8006C328 07004010 */  beqz       $v0, .L8006C348
    /* 8FCC 8006C32C 0680033C */   lui       $v1, %hi(D_8005E64C)
    /* 8FD0 8006C330 4CE66494 */  lhu        $a0, %lo(D_8005E64C)($v1)
    /* 8FD4 8006C334 EB000324 */  addiu      $v1, $zero, 0xEB
    /* 8FD8 8006C338 1B008310 */  beq        $a0, $v1, .L8006C3A8
    /* 8FDC 8006C33C 31010224 */   addiu     $v0, $zero, 0x131
    /* 8FE0 8006C340 EAB00108 */  j          .L8006C3A8
    /* 8FE4 8006C344 34010224 */   addiu     $v0, $zero, 0x134
  .L8006C348:
    /* 8FE8 8006C348 0780043C */  lui        $a0, %hi(Stg20_PartsNotAdmant)
    /* 8FEC 8006C34C 80058424 */  addiu      $a0, $a0, %lo(Stg20_PartsNotAdmant)
    /* 8FF0 8006C350 53B0010C */  jal        Stg20_ByteListHas
    /* 8FF4 8006C354 21280002 */   addu      $a1, $s0, $zero
    /* 8FF8 8006C358 05004010 */  beqz       $v0, .L8006C370
    /* 8FFC 8006C35C 31010224 */   addiu     $v0, $zero, 0x131
    /* 9000 8006C360 0680033C */  lui        $v1, %hi(D_8005E64C)
    /* 9004 8006C364 4CE66494 */  lhu        $a0, %lo(D_8005E64C)($v1)
    /* 9008 8006C368 E7B00108 */  j          .L8006C39C
    /* 900C 8006C36C EC000324 */   addiu     $v1, $zero, 0xEC
  .L8006C370:
    /* 9010 8006C370 0780043C */  lui        $a0, %hi(Stg20_PartsNotSteel)
    /* 9014 8006C374 94058424 */  addiu      $a0, $a0, %lo(Stg20_PartsNotSteel)
    /* 9018 8006C378 53B0010C */  jal        Stg20_ByteListHas
    /* 901C 8006C37C 21280002 */   addu      $a1, $s0, $zero
    /* 9020 8006C380 03004014 */  bnez       $v0, .L8006C390
    /* 9024 8006C384 31010224 */   addiu     $v0, $zero, 0x131
    /* 9028 8006C388 EAB00108 */  j          .L8006C3A8
    /* 902C 8006C38C 21100000 */   addu      $v0, $zero, $zero
  .L8006C390:
    /* 9030 8006C390 0680033C */  lui        $v1, %hi(D_8005E64C)
    /* 9034 8006C394 4CE66494 */  lhu        $a0, %lo(D_8005E64C)($v1)
    /* 9038 8006C398 EA000324 */  addiu      $v1, $zero, 0xEA
  .L8006C39C:
    /* 903C 8006C39C 02008314 */  bne        $a0, $v1, .L8006C3A8
    /* 9040 8006C3A0 00000000 */   nop
    /* 9044 8006C3A4 34010224 */  addiu      $v0, $zero, 0x134
  .L8006C3A8:
    /* 9048 8006C3A8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 904C 8006C3AC 1000B08F */  lw         $s0, 0x10($sp)
    /* 9050 8006C3B0 0800E003 */  jr         $ra
    /* 9054 8006C3B4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg20_GetPartFitMsg
