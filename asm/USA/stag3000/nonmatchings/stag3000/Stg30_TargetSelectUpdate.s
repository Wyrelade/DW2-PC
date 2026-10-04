nonmatching Stg30_TargetSelectUpdate, 0x500

glabel Stg30_TargetSelectUpdate
    /* 3A50 80066DB0 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 3A54 80066DB4 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 3A58 80066DB8 21988000 */  addu       $s3, $a0, $zero
    /* 3A5C 80066DBC 01000224 */  addiu      $v0, $zero, 0x1
    /* 3A60 80066DC0 2000BFAF */  sw         $ra, 0x20($sp)
    /* 3A64 80066DC4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 3A68 80066DC8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3A6C 80066DCC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3A70 80066DD0 1000648E */  lw         $a0, 0x10($s3)
    /* 3A74 80066DD4 2C00718E */  lw         $s1, 0x2C($s3)
    /* 3A78 80066DD8 55008210 */  beq        $a0, $v0, .L80066F30
    /* 3A7C 80066DDC 02008228 */   slti      $v0, $a0, 0x2
    /* 3A80 80066DE0 2C014010 */  beqz       $v0, .L80067294
    /* 3A84 80066DE4 00000000 */   nop
    /* 3A88 80066DE8 2A018014 */  bnez       $a0, .L80067294
    /* 3A8C 80066DEC 0780103C */   lui       $s0, %hi(Stg30_Battle)
    /* 3A90 80066DF0 C03C1026 */  addiu      $s0, $s0, %lo(Stg30_Battle)
    /* 3A94 80066DF4 0800028E */  lw         $v0, 0x8($s0)
    /* 3A98 80066DF8 00000000 */  nop
    /* 3A9C 80066DFC 00110200 */  sll        $v0, $v0, 4
    /* 3AA0 80066E00 21105000 */  addu       $v0, $v0, $s0
    /* 3AA4 80066E04 B2024484 */  lh         $a0, 0x2B2($v0)
    /* 3AA8 80066E08 CF7B000C */  jal        Skill_GetTarget
    /* 3AAC 80066E0C 180024AE */   sw        $a0, 0x18($s1)
    /* 3AB0 80066E10 080022AE */  sw         $v0, 0x8($s1)
    /* 3AB4 80066E14 0800028E */  lw         $v0, 0x8($s0)
    /* 3AB8 80066E18 0800238E */  lw         $v1, 0x8($s1)
    /* 3ABC 80066E1C 00110200 */  sll        $v0, $v0, 4
    /* 3AC0 80066E20 21105000 */  addu       $v0, $v0, $s0
    /* 3AC4 80066E24 B4024284 */  lh         $v0, 0x2B4($v0)
    /* 3AC8 80066E28 00000000 */  nop
    /* 3ACC 80066E2C 140022AE */  sw         $v0, 0x14($s1)
    /* 3AD0 80066E30 0A00622C */  sltiu      $v0, $v1, 0xA
    /* 3AD4 80066E34 08004010 */  beqz       $v0, .L80066E58
    /* 3AD8 80066E38 0680023C */   lui       $v0, %hi(jtbl_800633FC)
    /* 3ADC 80066E3C FC334224 */  addiu      $v0, $v0, %lo(jtbl_800633FC)
    /* 3AE0 80066E40 80180300 */  sll        $v1, $v1, 2
    /* 3AE4 80066E44 21186200 */  addu       $v1, $v1, $v0
    /* 3AE8 80066E48 0000628C */  lw         $v0, 0x0($v1)
    /* 3AEC 80066E4C 00000000 */  nop
    /* 3AF0 80066E50 08004000 */  jr         $v0
    /* 3AF4 80066E54 00000000 */   nop
  jlabel .L80066E58
    /* 3AF8 80066E58 0780023C */  lui        $v0, %hi(D_80073CC8)
    /* 3AFC 80066E5C C83C428C */  lw         $v0, %lo(D_80073CC8)($v0)
    /* 3B00 80066E60 B59B0108 */  j          .L80066ED4
    /* 3B04 80066E64 040022AE */   sw        $v0, 0x4($s1)
  jlabel .L80066E68
    /* 3B08 80066E68 21200000 */  addu       $a0, $zero, $zero
    /* 3B0C 80066E6C 01000524 */  addiu      $a1, $zero, 0x1
    /* 3B10 80066E70 1400268E */  lw         $a2, 0x14($s1)
    /* 3B14 80066E74 02000224 */  addiu      $v0, $zero, 0x2
    /* 3B18 80066E78 0C0020AE */  sw         $zero, 0xC($s1)
    /* 3B1C 80066E7C 100022AE */  sw         $v0, 0x10($s1)
    /* 3B20 80066E80 AD9B0108 */  j          .L80066EB4
    /* 3B24 80066E84 1C0020AE */   sw        $zero, 0x1C($s1)
  jlabel .L80066E88
    /* 3B28 80066E88 B49B0108 */  j          .L80066ED0
    /* 3B2C 80066E8C 07000224 */   addiu     $v0, $zero, 0x7
  jlabel .L80066E90
    /* 3B30 80066E90 01000424 */  addiu      $a0, $zero, 0x1
    /* 3B34 80066E94 21288000 */  addu       $a1, $a0, $zero
    /* 3B38 80066E98 1400268E */  lw         $a2, 0x14($s1)
    /* 3B3C 80066E9C 03000224 */  addiu      $v0, $zero, 0x3
    /* 3B40 80066EA0 0C0022AE */  sw         $v0, 0xC($s1)
    /* 3B44 80066EA4 05000224 */  addiu      $v0, $zero, 0x5
    /* 3B48 80066EA8 100022AE */  sw         $v0, 0x10($s1)
    /* 3B4C 80066EAC 21108000 */  addu       $v0, $a0, $zero
    /* 3B50 80066EB0 1C0022AE */  sw         $v0, 0x1C($s1)
  .L80066EB4:
    /* 3B54 80066EB4 C7B8010C */  jal        Stg30_TargetFirst
    /* 3B58 80066EB8 00000000 */   nop
    /* 3B5C 80066EBC C19B0108 */  j          .L80066F04
    /* 3B60 80066EC0 040022AE */   sw        $v0, 0x4($s1)
  jlabel .L80066EC4
    /* 3B64 80066EC4 B49B0108 */  j          .L80066ED0
    /* 3B68 80066EC8 08000224 */   addiu     $v0, $zero, 0x8
  jlabel .L80066ECC
    /* 3B6C 80066ECC 09000224 */  addiu      $v0, $zero, 0x9
  .L80066ED0:
    /* 3B70 80066ED0 040022AE */  sw         $v0, 0x4($s1)
  .L80066ED4:
    /* 3B74 80066ED4 100022AE */  sw         $v0, 0x10($s1)
    /* 3B78 80066ED8 C19B0108 */  j          .L80066F04
    /* 3B7C 80066EDC 0C0022AE */   sw        $v0, 0xC($s1)
  jlabel .L80066EE0
    /* 3B80 80066EE0 21206002 */  addu       $a0, $s3, $zero
    /* 3B84 80066EE4 03000524 */  addiu      $a1, $zero, 0x3
    /* 3B88 80066EE8 0780023C */  lui        $v0, %hi(Stg30_Battle)
    /* 3B8C 80066EEC C03C4224 */  addiu      $v0, $v0, %lo(Stg30_Battle)
    /* 3B90 80066EF0 0C0040AC */  sw         $zero, 0xC($v0)
    /* 3B94 80066EF4 7045000C */  jal        Task_SetState0
    /* 3B98 80066EF8 140040AC */   sw        $zero, 0x14($v0)
    /* 3B9C 80066EFC A59C0108 */  j          .L80067294
    /* 3BA0 80066F00 00000000 */   nop
  .L80066F04:
    /* 3BA4 80066F04 5145000C */  jal        Task_NextState0
    /* 3BA8 80066F08 21206002 */   addu      $a0, $s3, $zero
    /* 3BAC 80066F0C A59C0108 */  j          .L80067294
    /* 3BB0 80066F10 00000000 */   nop
  .L80066F14:
    /* 3BB4 80066F14 21280000 */  addu       $a1, $zero, $zero
    /* 3BB8 80066F18 0780023C */  lui        $v0, %hi(Stg30_Battle)
    /* 3BBC 80066F1C 0400238E */  lw         $v1, 0x4($s1)
    /* 3BC0 80066F20 C03C4224 */  addiu      $v0, $v0, %lo(Stg30_Battle)
    /* 3BC4 80066F24 140040AC */  sw         $zero, 0x14($v0)
    /* 3BC8 80066F28 159C0108 */  j          .L80067054
    /* 3BCC 80066F2C 0C0043AC */   sw        $v1, 0xC($v0)
  .L80066F30:
    /* 3BD0 80066F30 0800238E */  lw         $v1, 0x8($s1)
    /* 3BD4 80066F34 00000000 */  nop
    /* 3BD8 80066F38 04006410 */  beq        $v1, $a0, .L80066F4C
    /* 3BDC 80066F3C 21900000 */   addu      $s2, $zero, $zero
    /* 3BE0 80066F40 05000224 */  addiu      $v0, $zero, 0x5
    /* 3BE4 80066F44 36006214 */  bne        $v1, $v0, .L80067020
    /* 3BE8 80066F48 0680023C */   lui       $v0, %hi(Pad_State)
  .L80066F4C:
    /* 3BEC 80066F4C 0680023C */  lui        $v0, %hi(D_8005F6F4)
    /* 3BF0 80066F50 F4F6428C */  lw         $v0, %lo(D_8005F6F4)($v0)
    /* 3BF4 80066F54 00000000 */  nop
    /* 3BF8 80066F58 17004018 */  blez       $v0, .L80066FB8
    /* 3BFC 80066F5C 0680023C */   lui       $v0, %hi(Pad_State)
    /* 3C00 80066F60 1C00248E */  lw         $a0, 0x1C($s1)
    /* 3C04 80066F64 0400308E */  lw         $s0, 0x4($s1)
    /* 3C08 80066F68 06008010 */  beqz       $a0, .L80066F84
    /* 3C0C 80066F6C 21280002 */   addu      $a1, $s0, $zero
    /* 3C10 80066F70 1400278E */  lw         $a3, 0x14($s1)
    /* 3C14 80066F74 F4B8010C */  jal        Stg30_TargetPrev
    /* 3C18 80066F78 01000624 */   addiu     $a2, $zero, 0x1
    /* 3C1C 80066F7C E69B0108 */  j          .L80066F98
    /* 3C20 80066F80 040022AE */   sw        $v0, 0x4($s1)
  .L80066F84:
    /* 3C24 80066F84 21200000 */  addu       $a0, $zero, $zero
    /* 3C28 80066F88 1400278E */  lw         $a3, 0x14($s1)
    /* 3C2C 80066F8C 1FB9010C */  jal        Stg30_TargetNext
    /* 3C30 80066F90 01000624 */   addiu     $a2, $zero, 0x1
    /* 3C34 80066F94 040022AE */  sw         $v0, 0x4($s1)
  .L80066F98:
    /* 3C38 80066F98 0400228E */  lw         $v0, 0x4($s1)
    /* 3C3C 80066F9C 00000000 */  nop
    /* 3C40 80066FA0 04005010 */  beq        $v0, $s0, .L80066FB4
    /* 3C44 80066FA4 12000424 */   addiu     $a0, $zero, 0x12
    /* 3C48 80066FA8 01001224 */  addiu      $s2, $zero, 0x1
    /* 3C4C 80066FAC A369000C */  jal        Snd_PlayById
    /* 3C50 80066FB0 21280000 */   addu      $a1, $zero, $zero
  .L80066FB4:
    /* 3C54 80066FB4 0680023C */  lui        $v0, %hi(Pad_State)
  .L80066FB8:
    /* 3C58 80066FB8 F0F6428C */  lw         $v0, %lo(Pad_State)($v0)
    /* 3C5C 80066FBC 00000000 */  nop
    /* 3C60 80066FC0 17004018 */  blez       $v0, .L80067020
    /* 3C64 80066FC4 0680023C */   lui       $v0, %hi(Pad_State)
    /* 3C68 80066FC8 1C00248E */  lw         $a0, 0x1C($s1)
    /* 3C6C 80066FCC 0400308E */  lw         $s0, 0x4($s1)
    /* 3C70 80066FD0 06008010 */  beqz       $a0, .L80066FEC
    /* 3C74 80066FD4 21280002 */   addu      $a1, $s0, $zero
    /* 3C78 80066FD8 1400278E */  lw         $a3, 0x14($s1)
    /* 3C7C 80066FDC 1FB9010C */  jal        Stg30_TargetNext
    /* 3C80 80066FE0 01000624 */   addiu     $a2, $zero, 0x1
    /* 3C84 80066FE4 009C0108 */  j          .L80067000
    /* 3C88 80066FE8 040022AE */   sw        $v0, 0x4($s1)
  .L80066FEC:
    /* 3C8C 80066FEC 21200000 */  addu       $a0, $zero, $zero
    /* 3C90 80066FF0 1400278E */  lw         $a3, 0x14($s1)
    /* 3C94 80066FF4 F4B8010C */  jal        Stg30_TargetPrev
    /* 3C98 80066FF8 01000624 */   addiu     $a2, $zero, 0x1
    /* 3C9C 80066FFC 040022AE */  sw         $v0, 0x4($s1)
  .L80067000:
    /* 3CA0 80067000 0400228E */  lw         $v0, 0x4($s1)
    /* 3CA4 80067004 00000000 */  nop
    /* 3CA8 80067008 04005010 */  beq        $v0, $s0, .L8006701C
    /* 3CAC 8006700C 12000424 */   addiu     $a0, $zero, 0x12
    /* 3CB0 80067010 01001224 */  addiu      $s2, $zero, 0x1
    /* 3CB4 80067014 A369000C */  jal        Snd_PlayById
    /* 3CB8 80067018 21280000 */   addu      $a1, $zero, $zero
  .L8006701C:
    /* 3CBC 8006701C 0680023C */  lui        $v0, %hi(Pad_State)
  .L80067020:
    /* 3CC0 80067020 F0F64324 */  addiu      $v1, $v0, %lo(Pad_State)
    /* 3CC4 80067024 1400628C */  lw         $v0, 0x14($v1)
    /* 3CC8 80067028 00000000 */  nop
    /* 3CCC 8006702C B9FF401C */  bgtz       $v0, .L80066F14
    /* 3CD0 80067030 0E000424 */   addiu     $a0, $zero, 0xE
    /* 3CD4 80067034 1C00628C */  lw         $v0, 0x1C($v1)
    /* 3CD8 80067038 00000000 */  nop
    /* 3CDC 8006703C 0A004018 */  blez       $v0, .L80067068
    /* 3CE0 80067040 0780033C */   lui       $v1, %hi(D_80073CD4)
    /* 3CE4 80067044 01000224 */  addiu      $v0, $zero, 0x1
    /* 3CE8 80067048 D43C62AC */  sw         $v0, %lo(D_80073CD4)($v1)
    /* 3CEC 8006704C 0B000424 */  addiu      $a0, $zero, 0xB
    /* 3CF0 80067050 21280000 */  addu       $a1, $zero, $zero
  .L80067054:
    /* 3CF4 80067054 A369000C */  jal        Snd_PlayById
    /* 3CF8 80067058 00000000 */   nop
    /* 3CFC 8006705C 21206002 */  addu       $a0, $s3, $zero
    /* 3D00 80067060 7045000C */  jal        Task_SetState0
    /* 3D04 80067064 03000524 */   addiu     $a1, $zero, 0x3
  .L80067068:
    /* 3D08 80067068 05004016 */  bnez       $s2, .L80067080
    /* 3D0C 8006706C 00000000 */   nop
    /* 3D10 80067070 0000228E */  lw         $v0, 0x0($s1)
    /* 3D14 80067074 00000000 */  nop
    /* 3D18 80067078 6F004014 */  bnez       $v0, .L80067238
    /* 3D1C 8006707C 00000000 */   nop
  .L80067080:
    /* 3D20 80067080 0800228E */  lw         $v0, 0x8($s1)
    /* 3D24 80067084 01000324 */  addiu      $v1, $zero, 0x1
    /* 3D28 80067088 000023AE */  sw         $v1, 0x0($s1)
    /* 3D2C 8006708C FFFF4324 */  addiu      $v1, $v0, -0x1
    /* 3D30 80067090 0800622C */  sltiu      $v0, $v1, 0x8
    /* 3D34 80067094 68004010 */  beqz       $v0, .L80067238
    /* 3D38 80067098 0680023C */   lui       $v0, %hi(jtbl_80063424)
    /* 3D3C 8006709C 24344224 */  addiu      $v0, $v0, %lo(jtbl_80063424)
    /* 3D40 800670A0 80180300 */  sll        $v1, $v1, 2
    /* 3D44 800670A4 21186200 */  addu       $v1, $v1, $v0
    /* 3D48 800670A8 0000628C */  lw         $v0, 0x0($v1)
    /* 3D4C 800670AC 00000000 */  nop
    /* 3D50 800670B0 08004000 */  jr         $v0
    /* 3D54 800670B4 00000000 */   nop
  jlabel .L800670B8
    /* 3D58 800670B8 0C00308E */  lw         $s0, 0xC($s1)
    /* 3D5C 800670BC 1000228E */  lw         $v0, 0x10($s1)
    /* 3D60 800670C0 00000000 */  nop
    /* 3D64 800670C4 2A105000 */  slt        $v0, $v0, $s0
    /* 3D68 800670C8 5B004014 */  bnez       $v0, .L80067238
    /* 3D6C 800670CC 09050424 */   addiu     $a0, $zero, 0x509
  .L800670D0:
    /* 3D70 800670D0 FFFF0524 */  addiu      $a1, $zero, -0x1
    /* 3D74 800670D4 4445000C */  jal        Task_FindFirst
    /* 3D78 800670D8 21300002 */   addu      $a2, $s0, $zero
    /* 3D7C 800670DC 21204000 */  addu       $a0, $v0, $zero
    /* 3D80 800670E0 0A008010 */  beqz       $a0, .L8006710C
    /* 3D84 800670E4 00000000 */   nop
    /* 3D88 800670E8 0400228E */  lw         $v0, 0x4($s1)
    /* 3D8C 800670EC 00000000 */  nop
    /* 3D90 800670F0 03005014 */  bne        $v0, $s0, .L80067100
    /* 3D94 800670F4 02000524 */   addiu     $a1, $zero, 0x2
    /* 3D98 800670F8 419C0108 */  j          .L80067104
    /* 3D9C 800670FC 08000624 */   addiu     $a2, $zero, 0x8
  .L80067100:
    /* 3DA0 80067100 07000624 */  addiu      $a2, $zero, 0x7
  .L80067104:
    /* 3DA4 80067104 7D45000C */  jal        Task_SetState01
    /* 3DA8 80067108 00000000 */   nop
  .L8006710C:
    /* 3DAC 8006710C 1000228E */  lw         $v0, 0x10($s1)
    /* 3DB0 80067110 01001026 */  addiu      $s0, $s0, 0x1
    /* 3DB4 80067114 2A105000 */  slt        $v0, $v0, $s0
    /* 3DB8 80067118 EDFF4010 */  beqz       $v0, .L800670D0
    /* 3DBC 8006711C 09050424 */   addiu     $a0, $zero, 0x509
    /* 3DC0 80067120 8E9C0108 */  j          .L80067238
    /* 3DC4 80067124 00000000 */   nop
  jlabel .L80067128
    /* 3DC8 80067128 21800000 */  addu       $s0, $zero, $zero
    /* 3DCC 8006712C 0780023C */  lui        $v0, %hi(Stg30_Battle)
    /* 3DD0 80067130 C03C5224 */  addiu      $s2, $v0, %lo(Stg30_Battle)
    /* 3DD4 80067134 09050424 */  addiu      $a0, $zero, 0x509
  .L80067138:
    /* 3DD8 80067138 FFFF0524 */  addiu      $a1, $zero, -0x1
    /* 3DDC 8006713C 4445000C */  jal        Task_FindFirst
    /* 3DE0 80067140 21300002 */   addu      $a2, $s0, $zero
    /* 3DE4 80067144 21204000 */  addu       $a0, $v0, $zero
    /* 3DE8 80067148 05008010 */  beqz       $a0, .L80067160
    /* 3DEC 8006714C 02000524 */   addiu     $a1, $zero, 0x2
    /* 3DF0 80067150 2E004286 */  lh         $v0, 0x2E($s2)
    /* 3DF4 80067154 00000000 */  nop
    /* 3DF8 80067158 02004014 */  bnez       $v0, .L80067164
    /* 3DFC 8006715C 08000624 */   addiu     $a2, $zero, 0x8
  .L80067160:
    /* 3E00 80067160 07000624 */  addiu      $a2, $zero, 0x7
  .L80067164:
    /* 3E04 80067164 7D45000C */  jal        Task_SetState01
    /* 3E08 80067168 5C005226 */   addiu     $s2, $s2, 0x5C
    /* 3E0C 8006716C 01001026 */  addiu      $s0, $s0, 0x1
    /* 3E10 80067170 0300022A */  slti       $v0, $s0, 0x3
    /* 3E14 80067174 F0FF4014 */  bnez       $v0, .L80067138
    /* 3E18 80067178 09050424 */   addiu     $a0, $zero, 0x509
    /* 3E1C 8006717C 8E9C0108 */  j          .L80067238
    /* 3E20 80067180 00000000 */   nop
  jlabel .L80067184
    /* 3E24 80067184 03001024 */  addiu      $s0, $zero, 0x3
    /* 3E28 80067188 0780023C */  lui        $v0, %hi(Stg30_Battle)
    /* 3E2C 8006718C C03C4224 */  addiu      $v0, $v0, %lo(Stg30_Battle)
    /* 3E30 80067190 14015224 */  addiu      $s2, $v0, 0x114
    /* 3E34 80067194 09050424 */  addiu      $a0, $zero, 0x509
  .L80067198:
    /* 3E38 80067198 FFFF0524 */  addiu      $a1, $zero, -0x1
    /* 3E3C 8006719C 4445000C */  jal        Task_FindFirst
    /* 3E40 800671A0 21300002 */   addu      $a2, $s0, $zero
    /* 3E44 800671A4 21204000 */  addu       $a0, $v0, $zero
    /* 3E48 800671A8 05008010 */  beqz       $a0, .L800671C0
    /* 3E4C 800671AC 02000524 */   addiu     $a1, $zero, 0x2
    /* 3E50 800671B0 2E004286 */  lh         $v0, 0x2E($s2)
    /* 3E54 800671B4 00000000 */  nop
    /* 3E58 800671B8 02004014 */  bnez       $v0, .L800671C4
    /* 3E5C 800671BC 08000624 */   addiu     $a2, $zero, 0x8
  .L800671C0:
    /* 3E60 800671C0 07000624 */  addiu      $a2, $zero, 0x7
  .L800671C4:
    /* 3E64 800671C4 7D45000C */  jal        Task_SetState01
    /* 3E68 800671C8 5C005226 */   addiu     $s2, $s2, 0x5C
    /* 3E6C 800671CC 01001026 */  addiu      $s0, $s0, 0x1
    /* 3E70 800671D0 0600022A */  slti       $v0, $s0, 0x6
    /* 3E74 800671D4 F0FF4014 */  bnez       $v0, .L80067198
    /* 3E78 800671D8 09050424 */   addiu     $a0, $zero, 0x509
    /* 3E7C 800671DC 8E9C0108 */  j          .L80067238
    /* 3E80 800671E0 00000000 */   nop
  jlabel .L800671E4
    /* 3E84 800671E4 21800000 */  addu       $s0, $zero, $zero
    /* 3E88 800671E8 0780023C */  lui        $v0, %hi(Stg30_Battle)
    /* 3E8C 800671EC C03C5224 */  addiu      $s2, $v0, %lo(Stg30_Battle)
    /* 3E90 800671F0 09050424 */  addiu      $a0, $zero, 0x509
  .L800671F4:
    /* 3E94 800671F4 FFFF0524 */  addiu      $a1, $zero, -0x1
    /* 3E98 800671F8 4445000C */  jal        Task_FindFirst
    /* 3E9C 800671FC 21300002 */   addu      $a2, $s0, $zero
    /* 3EA0 80067200 21204000 */  addu       $a0, $v0, $zero
    /* 3EA4 80067204 05008010 */  beqz       $a0, .L8006721C
    /* 3EA8 80067208 02000524 */   addiu     $a1, $zero, 0x2
    /* 3EAC 8006720C 2E004286 */  lh         $v0, 0x2E($s2)
    /* 3EB0 80067210 00000000 */  nop
    /* 3EB4 80067214 02004014 */  bnez       $v0, .L80067220
    /* 3EB8 80067218 08000624 */   addiu     $a2, $zero, 0x8
  .L8006721C:
    /* 3EBC 8006721C 07000624 */  addiu      $a2, $zero, 0x7
  .L80067220:
    /* 3EC0 80067220 7D45000C */  jal        Task_SetState01
    /* 3EC4 80067224 5C005226 */   addiu     $s2, $s2, 0x5C
    /* 3EC8 80067228 01001026 */  addiu      $s0, $s0, 0x1
    /* 3ECC 8006722C 0600022A */  slti       $v0, $s0, 0x6
    /* 3ED0 80067230 F0FF4014 */  bnez       $v0, .L800671F4
    /* 3ED4 80067234 09050424 */   addiu     $a0, $zero, 0x509
  jlabel .L80067238
    /* 3ED8 80067238 0800228E */  lw         $v0, 0x8($s1)
    /* 3EDC 8006723C 00000000 */  nop
    /* 3EE0 80067240 FFFF4324 */  addiu      $v1, $v0, -0x1
    /* 3EE4 80067244 0800622C */  sltiu      $v0, $v1, 0x8
    /* 3EE8 80067248 12004010 */  beqz       $v0, .L80067294
    /* 3EEC 8006724C 0680023C */   lui       $v0, %hi(jtbl_80063444)
    /* 3EF0 80067250 44344224 */  addiu      $v0, $v0, %lo(jtbl_80063444)
    /* 3EF4 80067254 80180300 */  sll        $v1, $v1, 2
    /* 3EF8 80067258 21186200 */  addu       $v1, $v1, $v0
    /* 3EFC 8006725C 0000628C */  lw         $v0, 0x0($v1)
    /* 3F00 80067260 00000000 */  nop
    /* 3F04 80067264 08004000 */  jr         $v0
    /* 3F08 80067268 00000000 */   nop
  jlabel .L8006726C
    /* 3F0C 8006726C 0400248E */  lw         $a0, 0x4($s1)
    /* 3F10 80067270 A39C0108 */  j          .L8006728C
    /* 3F14 80067274 02008424 */   addiu     $a0, $a0, 0x2
  jlabel .L80067278
    /* 3F18 80067278 A39C0108 */  j          .L8006728C
    /* 3F1C 8006727C 08000424 */   addiu     $a0, $zero, 0x8
  jlabel .L80067280
    /* 3F20 80067280 A39C0108 */  j          .L8006728C
    /* 3F24 80067284 09000424 */   addiu     $a0, $zero, 0x9
  jlabel .L80067288
    /* 3F28 80067288 18000424 */  addiu      $a0, $zero, 0x18
  .L8006728C:
    /* 3F2C 8006728C 45C3010C */  jal        Stg30_SetCameraShot
    /* 3F30 80067290 00000000 */   nop
  jlabel .L80067294
    /* 3F34 80067294 2000BF8F */  lw         $ra, 0x20($sp)
    /* 3F38 80067298 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 3F3C 8006729C 1800B28F */  lw         $s2, 0x18($sp)
    /* 3F40 800672A0 1400B18F */  lw         $s1, 0x14($sp)
    /* 3F44 800672A4 1000B08F */  lw         $s0, 0x10($sp)
    /* 3F48 800672A8 0800E003 */  jr         $ra
    /* 3F4C 800672AC 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel Stg30_TargetSelectUpdate
