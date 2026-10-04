nonmatching Stg20_SetSpecialFlag, 0x54C

glabel Stg20_SetSpecialFlag
    /* 3BD4 80066F34 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 3BD8 80066F38 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 3BDC 80066F3C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 3BE0 80066F40 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3BE4 80066F44 4801A010 */  beqz       $a1, .L80067468
    /* 3BE8 80066F48 1000B0AF */   sw        $s0, 0x10($sp)
    /* 3BEC 80066F4C 74DC8324 */  addiu      $v1, $a0, -0x238C
    /* 3BF0 80066F50 3700622C */  sltiu      $v0, $v1, 0x37
    /* 3BF4 80066F54 44014010 */  beqz       $v0, .L80067468
    /* 3BF8 80066F58 0680023C */   lui       $v0, %hi(jtbl_80063488)
    /* 3BFC 80066F5C 88344224 */  addiu      $v0, $v0, %lo(jtbl_80063488)
    /* 3C00 80066F60 80180300 */  sll        $v1, $v1, 2
    /* 3C04 80066F64 21186200 */  addu       $v1, $v1, $v0
    /* 3C08 80066F68 0000628C */  lw         $v0, 0x0($v1)
    /* 3C0C 80066F6C 00000000 */  nop
    /* 3C10 80066F70 08004000 */  jr         $v0
    /* 3C14 80066F74 00000000 */   nop
  jlabel .L80066F78
    /* 3C18 80066F78 0680033C */  lui        $v1, %hi(D_8005E64C)
    /* 3C1C 80066F7C EB000224 */  addiu      $v0, $zero, 0xEB
    /* 3C20 80066F80 1A9D0108 */  j          .L80067468
    /* 3C24 80066F84 4CE662A4 */   sh        $v0, %lo(D_8005E64C)($v1)
  jlabel .L80066F88
    /* 3C28 80066F88 0680033C */  lui        $v1, %hi(D_8005E64C)
    /* 3C2C 80066F8C EC000224 */  addiu      $v0, $zero, 0xEC
    /* 3C30 80066F90 1A9D0108 */  j          .L80067468
    /* 3C34 80066F94 4CE662A4 */   sh        $v0, %lo(D_8005E64C)($v1)
  jlabel .L80066F98
    /* 3C38 80066F98 0680033C */  lui        $v1, %hi(D_8005E66E)
    /* 3C3C 80066F9C 76000224 */  addiu      $v0, $zero, 0x76
    /* 3C40 80066FA0 1A9D0108 */  j          .L80067468
    /* 3C44 80066FA4 6EE662A4 */   sh        $v0, %lo(D_8005E66E)($v1)
  jlabel .L80066FA8
    /* 3C48 80066FA8 EB99010C */  jal        Stg20_ApplyStartPreset
    /* 3C4C 80066FAC 21200000 */   addu      $a0, $zero, $zero
    /* 3C50 80066FB0 1A9D0108 */  j          .L80067468
    /* 3C54 80066FB4 00000000 */   nop
  jlabel .L80066FB8
    /* 3C58 80066FB8 EB99010C */  jal        Stg20_ApplyStartPreset
    /* 3C5C 80066FBC 01000424 */   addiu     $a0, $zero, 0x1
    /* 3C60 80066FC0 1A9D0108 */  j          .L80067468
    /* 3C64 80066FC4 00000000 */   nop
  jlabel .L80066FC8
    /* 3C68 80066FC8 A79A010C */  jal        Stg20_AddBits
    /* 3C6C 80066FCC D0070424 */   addiu     $a0, $zero, 0x7D0
    /* 3C70 80066FD0 1A9D0108 */  j          .L80067468
    /* 3C74 80066FD4 00000000 */   nop
  jlabel .L80066FD8
    /* 3C78 80066FD8 A79A010C */  jal        Stg20_AddBits
    /* 3C7C 80066FDC E8030424 */   addiu     $a0, $zero, 0x3E8
    /* 3C80 80066FE0 1A9D0108 */  j          .L80067468
    /* 3C84 80066FE4 00000000 */   nop
  jlabel .L80066FE8
    /* 3C88 80066FE8 B89A010C */  jal        Stg20_RemoveOwnedDigi
    /* 3C8C 80066FEC 54000424 */   addiu     $a0, $zero, 0x54
    /* 3C90 80066FF0 4688000C */  jal        Digi_AddNew
    /* 3C94 80066FF4 BF000424 */   addiu     $a0, $zero, 0xBF
    /* 3C98 80066FF8 1A9D0108 */  j          .L80067468
    /* 3C9C 80066FFC 00000000 */   nop
  jlabel .L80067000
    /* 3CA0 80067000 B89A010C */  jal        Stg20_RemoveOwnedDigi
    /* 3CA4 80067004 C5000424 */   addiu     $a0, $zero, 0xC5
    /* 3CA8 80067008 4688000C */  jal        Digi_AddNew
    /* 3CAC 8006700C C0000424 */   addiu     $a0, $zero, 0xC0
    /* 3CB0 80067010 1A9D0108 */  j          .L80067468
    /* 3CB4 80067014 00000000 */   nop
  jlabel .L80067018
    /* 3CB8 80067018 B89A010C */  jal        Stg20_RemoveOwnedDigi
    /* 3CBC 8006701C 0B000424 */   addiu     $a0, $zero, 0xB
    /* 3CC0 80067020 4688000C */  jal        Digi_AddNew
    /* 3CC4 80067024 C1000424 */   addiu     $a0, $zero, 0xC1
    /* 3CC8 80067028 1A9D0108 */  j          .L80067468
    /* 3CCC 8006702C 00000000 */   nop
  jlabel .L80067030
    /* 3CD0 80067030 B89A010C */  jal        Stg20_RemoveOwnedDigi
    /* 3CD4 80067034 16000424 */   addiu     $a0, $zero, 0x16
    /* 3CD8 80067038 4688000C */  jal        Digi_AddNew
    /* 3CDC 8006703C C2000424 */   addiu     $a0, $zero, 0xC2
    /* 3CE0 80067040 1A9D0108 */  j          .L80067468
    /* 3CE4 80067044 00000000 */   nop
  jlabel .L80067048
    /* 3CE8 80067048 B89A010C */  jal        Stg20_RemoveOwnedDigi
    /* 3CEC 8006704C 4F000424 */   addiu     $a0, $zero, 0x4F
    /* 3CF0 80067050 4688000C */  jal        Digi_AddNew
    /* 3CF4 80067054 C3000424 */   addiu     $a0, $zero, 0xC3
    /* 3CF8 80067058 1A9D0108 */  j          .L80067468
    /* 3CFC 8006705C 00000000 */   nop
  jlabel .L80067060
    /* 3D00 80067060 B89A010C */  jal        Stg20_RemoveOwnedDigi
    /* 3D04 80067064 85000424 */   addiu     $a0, $zero, 0x85
    /* 3D08 80067068 4688000C */  jal        Digi_AddNew
    /* 3D0C 8006706C C4000424 */   addiu     $a0, $zero, 0xC4
    /* 3D10 80067070 1A9D0108 */  j          .L80067468
    /* 3D14 80067074 00000000 */   nop
  jlabel .L80067078
    /* 3D18 80067078 B89A010C */  jal        Stg20_RemoveOwnedDigi
    /* 3D1C 8006707C EA000424 */   addiu     $a0, $zero, 0xEA
    /* 3D20 80067080 4688000C */  jal        Digi_AddNew
    /* 3D24 80067084 C5000424 */   addiu     $a0, $zero, 0xC5
    /* 3D28 80067088 1A9D0108 */  j          .L80067468
    /* 3D2C 8006708C 00000000 */   nop
  jlabel .L80067090
    /* 3D30 80067090 B89A010C */  jal        Stg20_RemoveOwnedDigi
    /* 3D34 80067094 CC000424 */   addiu     $a0, $zero, 0xCC
    /* 3D38 80067098 4688000C */  jal        Digi_AddNew
    /* 3D3C 8006709C C6000424 */   addiu     $a0, $zero, 0xC6
    /* 3D40 800670A0 1A9D0108 */  j          .L80067468
    /* 3D44 800670A4 00000000 */   nop
  jlabel .L800670A8
    /* 3D48 800670A8 B89A010C */  jal        Stg20_RemoveOwnedDigi
    /* 3D4C 800670AC 1A000424 */   addiu     $a0, $zero, 0x1A
    /* 3D50 800670B0 4688000C */  jal        Digi_AddNew
    /* 3D54 800670B4 C7000424 */   addiu     $a0, $zero, 0xC7
    /* 3D58 800670B8 1A9D0108 */  j          .L80067468
    /* 3D5C 800670BC 00000000 */   nop
  jlabel .L800670C0
    /* 3D60 800670C0 A79A010C */  jal        Stg20_AddBits
    /* 3D64 800670C4 0CFE0424 */   addiu     $a0, $zero, -0x1F4
    /* 3D68 800670C8 1A9D0108 */  j          .L80067468
    /* 3D6C 800670CC 00000000 */   nop
  jlabel .L800670D0
    /* 3D70 800670D0 A79A010C */  jal        Stg20_AddBits
    /* 3D74 800670D4 18FC0424 */   addiu     $a0, $zero, -0x3E8
    /* 3D78 800670D8 1A9D0108 */  j          .L80067468
    /* 3D7C 800670DC 00000000 */   nop
  jlabel .L800670E0
    /* 3D80 800670E0 A79A010C */  jal        Stg20_AddBits
    /* 3D84 800670E4 24FA0424 */   addiu     $a0, $zero, -0x5DC
    /* 3D88 800670E8 1A9D0108 */  j          .L80067468
    /* 3D8C 800670EC 00000000 */   nop
  jlabel .L800670F0
    /* 3D90 800670F0 A79A010C */  jal        Stg20_AddBits
    /* 3D94 800670F4 30F80424 */   addiu     $a0, $zero, -0x7D0
    /* 3D98 800670F8 1A9D0108 */  j          .L80067468
    /* 3D9C 800670FC 00000000 */   nop
  jlabel .L80067100
    /* 3DA0 80067100 A79A010C */  jal        Stg20_AddBits
    /* 3DA4 80067104 3CF60424 */   addiu     $a0, $zero, -0x9C4
    /* 3DA8 80067108 1A9D0108 */  j          .L80067468
    /* 3DAC 8006710C 00000000 */   nop
  jlabel .L80067110
    /* 3DB0 80067110 A79A010C */  jal        Stg20_AddBits
    /* 3DB4 80067114 48F40424 */   addiu     $a0, $zero, -0xBB8
    /* 3DB8 80067118 1A9D0108 */  j          .L80067468
    /* 3DBC 8006711C 00000000 */   nop
  jlabel .L80067120
    /* 3DC0 80067120 A79A010C */  jal        Stg20_AddBits
    /* 3DC4 80067124 54F20424 */   addiu     $a0, $zero, -0xDAC
    /* 3DC8 80067128 1A9D0108 */  j          .L80067468
    /* 3DCC 8006712C 00000000 */   nop
  jlabel .L80067130
    /* 3DD0 80067130 A79A010C */  jal        Stg20_AddBits
    /* 3DD4 80067134 60F00424 */   addiu     $a0, $zero, -0xFA0
    /* 3DD8 80067138 1A9D0108 */  j          .L80067468
    /* 3DDC 8006713C 00000000 */   nop
  jlabel .L80067140
    /* 3DE0 80067140 0680033C */  lui        $v1, %hi(D_8005E632)
    /* 3DE4 80067144 01000224 */  addiu      $v0, $zero, 0x1
    /* 3DE8 80067148 1A9D0108 */  j          .L80067468
    /* 3DEC 8006714C 32E662A0 */   sb        $v0, %lo(D_8005E632)($v1)
  jlabel .L80067150
    /* 3DF0 80067150 0680033C */  lui        $v1, %hi(D_8005E632)
    /* 3DF4 80067154 02000224 */  addiu      $v0, $zero, 0x2
    /* 3DF8 80067158 1A9D0108 */  j          .L80067468
    /* 3DFC 8006715C 32E662A0 */   sb        $v0, %lo(D_8005E632)($v1)
  jlabel .L80067160
    /* 3E00 80067160 0680033C */  lui        $v1, %hi(D_8005E632)
    /* 3E04 80067164 03000224 */  addiu      $v0, $zero, 0x3
    /* 3E08 80067168 1A9D0108 */  j          .L80067468
    /* 3E0C 8006716C 32E662A0 */   sb        $v0, %lo(D_8005E632)($v1)
  jlabel .L80067170
    /* 3E10 80067170 0680033C */  lui        $v1, %hi(D_8005E632)
    /* 3E14 80067174 04000224 */  addiu      $v0, $zero, 0x4
    /* 3E18 80067178 1A9D0108 */  j          .L80067468
    /* 3E1C 8006717C 32E662A0 */   sb        $v0, %lo(D_8005E632)($v1)
  jlabel .L80067180
    /* 3E20 80067180 0680033C */  lui        $v1, %hi(D_8005E632)
    /* 3E24 80067184 05000224 */  addiu      $v0, $zero, 0x5
    /* 3E28 80067188 1A9D0108 */  j          .L80067468
    /* 3E2C 8006718C 32E662A0 */   sb        $v0, %lo(D_8005E632)($v1)
  jlabel .L80067190
    /* 3E30 80067190 0680033C */  lui        $v1, %hi(D_8005E632)
    /* 3E34 80067194 06000224 */  addiu      $v0, $zero, 0x6
    /* 3E38 80067198 1A9D0108 */  j          .L80067468
    /* 3E3C 8006719C 32E662A0 */   sb        $v0, %lo(D_8005E632)($v1)
  jlabel .L800671A0
    /* 3E40 800671A0 0680033C */  lui        $v1, %hi(D_8005E632)
    /* 3E44 800671A4 07000224 */  addiu      $v0, $zero, 0x7
    /* 3E48 800671A8 1A9D0108 */  j          .L80067468
    /* 3E4C 800671AC 32E662A0 */   sb        $v0, %lo(D_8005E632)($v1)
  jlabel .L800671B0
    /* 3E50 800671B0 0680033C */  lui        $v1, %hi(D_8005E632)
    /* 3E54 800671B4 08000224 */  addiu      $v0, $zero, 0x8
    /* 3E58 800671B8 1A9D0108 */  j          .L80067468
    /* 3E5C 800671BC 32E662A0 */   sb        $v0, %lo(D_8005E632)($v1)
  jlabel .L800671C0
    /* 3E60 800671C0 0680033C */  lui        $v1, %hi(D_8005E632)
    /* 3E64 800671C4 09000224 */  addiu      $v0, $zero, 0x9
    /* 3E68 800671C8 1A9D0108 */  j          .L80067468
    /* 3E6C 800671CC 32E662A0 */   sb        $v0, %lo(D_8005E632)($v1)
  jlabel .L800671D0
    /* 3E70 800671D0 0680033C */  lui        $v1, %hi(D_8005E632)
    /* 3E74 800671D4 0A000224 */  addiu      $v0, $zero, 0xA
    /* 3E78 800671D8 1A9D0108 */  j          .L80067468
    /* 3E7C 800671DC 32E662A0 */   sb        $v0, %lo(D_8005E632)($v1)
  jlabel .L800671E0
    /* 3E80 800671E0 0680023C */  lui        $v0, %hi(D_8005E631)
    /* 3E84 800671E4 1A9D0108 */  j          .L80067468
    /* 3E88 800671E8 31E640A0 */   sb        $zero, %lo(D_8005E631)($v0)
  jlabel .L800671EC
    /* 3E8C 800671EC 0680033C */  lui        $v1, %hi(D_8005E631)
    /* 3E90 800671F0 01000224 */  addiu      $v0, $zero, 0x1
    /* 3E94 800671F4 1A9D0108 */  j          .L80067468
    /* 3E98 800671F8 31E662A0 */   sb        $v0, %lo(D_8005E631)($v1)
  jlabel .L800671FC
    /* 3E9C 800671FC 0680033C */  lui        $v1, %hi(D_8005E631)
    /* 3EA0 80067200 02000224 */  addiu      $v0, $zero, 0x2
    /* 3EA4 80067204 1A9D0108 */  j          .L80067468
    /* 3EA8 80067208 31E662A0 */   sb        $v0, %lo(D_8005E631)($v1)
  jlabel .L8006720C
    /* 3EAC 8006720C 21880000 */  addu       $s1, $zero, $zero
    /* 3EB0 80067210 C2001224 */  addiu      $s2, $zero, 0xC2
    /* 3EB4 80067214 0680023C */  lui        $v0, %hi(Save_GameState)
    /* 3EB8 80067218 20E65024 */  addiu      $s0, $v0, %lo(Save_GameState)
  .L8006721C:
    /* 3EBC 8006721C 078A000C */  jal        Item_GetBagCapacity
    /* 3EC0 80067220 00000000 */   nop
    /* 3EC4 80067224 2A102202 */  slt        $v0, $s1, $v0
    /* 3EC8 80067228 8F004010 */  beqz       $v0, .L80067468
    /* 3ECC 8006722C 21180002 */   addu      $v1, $s0, $zero
    /* 3ED0 80067230 66006294 */  lhu        $v0, 0x66($v1)
    /* 3ED4 80067234 00000000 */  nop
    /* 3ED8 80067238 81005210 */  beq        $v0, $s2, .L80067440
    /* 3EDC 8006723C 01003126 */   addiu     $s1, $s1, 0x1
    /* 3EE0 80067240 879C0108 */  j          .L8006721C
    /* 3EE4 80067244 02007024 */   addiu     $s0, $v1, 0x2
  jlabel .L80067248
    /* 3EE8 80067248 12000624 */  addiu      $a2, $zero, 0x12
    /* 3EEC 8006724C 0680023C */  lui        $v0, %hi(Save_GameState)
    /* 3EF0 80067250 20E64224 */  addiu      $v0, $v0, %lo(Save_GameState)
    /* 3EF4 80067254 2A004394 */  lhu        $v1, 0x2A($v0)
    /* 3EF8 80067258 26004494 */  lhu        $a0, 0x26($v0)
    /* 3EFC 8006725C 21284600 */  addu       $a1, $v0, $a2
    /* 3F00 80067260 280043A4 */  sh         $v1, 0x28($v0)
    /* 3F04 80067264 240044A4 */  sh         $a0, 0x24($v0)
  .L80067268:
    /* 3F08 80067268 5200A0A0 */  sb         $zero, 0x52($a1)
    /* 3F0C 8006726C FFFFC624 */  addiu      $a2, $a2, -0x1
    /* 3F10 80067270 FDFFC104 */  bgez       $a2, .L80067268
    /* 3F14 80067274 FFFFA524 */   addiu     $a1, $a1, -0x1
    /* 3F18 80067278 21300000 */  addu       $a2, $zero, $zero
    /* 3F1C 8006727C 0680023C */  lui        $v0, %hi(Save_GameState)
    /* 3F20 80067280 20E64424 */  addiu      $a0, $v0, %lo(Save_GameState)
  .L80067284:
    /* 3F24 80067284 E4008290 */  lbu        $v0, 0xE4($a0)
    /* 3F28 80067288 00000000 */  nop
    /* 3F2C 8006728C 05004010 */  beqz       $v0, .L800672A4
    /* 3F30 80067290 00000000 */   nop
    /* 3F34 80067294 F8008294 */  lhu        $v0, 0xF8($a0)
    /* 3F38 80067298 FC008394 */  lhu        $v1, 0xFC($a0)
    /* 3F3C 8006729C FA0082A4 */  sh         $v0, 0xFA($a0)
    /* 3F40 800672A0 FE0083A4 */  sh         $v1, 0xFE($a0)
  .L800672A4:
    /* 3F44 800672A4 0100C624 */  addiu      $a2, $a2, 0x1
    /* 3F48 800672A8 2400C228 */  slti       $v0, $a2, 0x24
    /* 3F4C 800672AC F5FF4014 */  bnez       $v0, .L80067284
    /* 3F50 800672B0 5C008424 */   addiu     $a0, $a0, 0x5C
    /* 3F54 800672B4 1A9D0108 */  j          .L80067468
    /* 3F58 800672B8 00000000 */   nop
  jlabel .L800672BC
    /* 3F5C 800672BC 5B020424 */  addiu      $a0, $zero, 0x25B
    /* 3F60 800672C0 7188000C */  jal        Flag_Set
    /* 3F64 800672C4 21280000 */   addu      $a1, $zero, $zero
    /* 3F68 800672C8 5C020424 */  addiu      $a0, $zero, 0x25C
    /* 3F6C 800672CC 7188000C */  jal        Flag_Set
    /* 3F70 800672D0 21280000 */   addu      $a1, $zero, $zero
    /* 3F74 800672D4 5D020424 */  addiu      $a0, $zero, 0x25D
    /* 3F78 800672D8 7188000C */  jal        Flag_Set
    /* 3F7C 800672DC 21280000 */   addu      $a1, $zero, $zero
    /* 3F80 800672E0 62020424 */  addiu      $a0, $zero, 0x262
    /* 3F84 800672E4 7188000C */  jal        Flag_Set
    /* 3F88 800672E8 01000524 */   addiu     $a1, $zero, 0x1
    /* 3F8C 800672EC 63020424 */  addiu      $a0, $zero, 0x263
    /* 3F90 800672F0 7188000C */  jal        Flag_Set
    /* 3F94 800672F4 01000524 */   addiu     $a1, $zero, 0x1
    /* 3F98 800672F8 64020424 */  addiu      $a0, $zero, 0x264
    /* 3F9C 800672FC 7188000C */  jal        Flag_Set
    /* 3FA0 80067300 01000524 */   addiu     $a1, $zero, 0x1
    /* 3FA4 80067304 1A9D0108 */  j          .L80067468
    /* 3FA8 80067308 00000000 */   nop
  jlabel .L8006730C
    /* 3FAC 8006730C 0680033C */  lui        $v1, %hi(Save_GameState)
    /* 3FB0 80067310 20E66324 */  addiu      $v1, $v1, %lo(Save_GameState)
    /* 3FB4 80067314 880F6294 */  lhu        $v0, 0xF88($v1)
    /* 3FB8 80067318 00000000 */  nop
    /* 3FBC 8006731C 01004224 */  addiu      $v0, $v0, 0x1
    /* 3FC0 80067320 1A9D0108 */  j          .L80067468
    /* 3FC4 80067324 880F62A4 */   sh        $v0, 0xF88($v1)
  jlabel .L80067328
    /* 3FC8 80067328 0680033C */  lui        $v1, %hi(Save_GameState)
    /* 3FCC 8006732C 20E66324 */  addiu      $v1, $v1, %lo(Save_GameState)
    /* 3FD0 80067330 520F6294 */  lhu        $v0, 0xF52($v1)
    /* 3FD4 80067334 00000000 */  nop
    /* 3FD8 80067338 01004224 */  addiu      $v0, $v0, 0x1
    /* 3FDC 8006733C 1A9D0108 */  j          .L80067468
    /* 3FE0 80067340 520F62A4 */   sh        $v0, 0xF52($v1)
  jlabel .L80067344
    /* 3FE4 80067344 0680033C */  lui        $v1, %hi(Save_GameState)
    /* 3FE8 80067348 20E66324 */  addiu      $v1, $v1, %lo(Save_GameState)
    /* 3FEC 8006734C 800F6294 */  lhu        $v0, 0xF80($v1)
    /* 3FF0 80067350 00000000 */  nop
    /* 3FF4 80067354 01004224 */  addiu      $v0, $v0, 0x1
    /* 3FF8 80067358 1A9D0108 */  j          .L80067468
    /* 3FFC 8006735C 800F62A4 */   sh        $v0, 0xF80($v1)
  jlabel .L80067360
    /* 4000 80067360 0680033C */  lui        $v1, %hi(Save_GameState)
    /* 4004 80067364 20E66324 */  addiu      $v1, $v1, %lo(Save_GameState)
    /* 4008 80067368 540F6294 */  lhu        $v0, 0xF54($v1)
    /* 400C 8006736C 00000000 */  nop
    /* 4010 80067370 01004224 */  addiu      $v0, $v0, 0x1
    /* 4014 80067374 1A9D0108 */  j          .L80067468
    /* 4018 80067378 540F62A4 */   sh        $v0, 0xF54($v1)
  jlabel .L8006737C
    /* 401C 8006737C 0680033C */  lui        $v1, %hi(Save_GameState)
    /* 4020 80067380 20E66324 */  addiu      $v1, $v1, %lo(Save_GameState)
    /* 4024 80067384 920F6294 */  lhu        $v0, 0xF92($v1)
    /* 4028 80067388 00000000 */  nop
    /* 402C 8006738C 01004224 */  addiu      $v0, $v0, 0x1
    /* 4030 80067390 1A9D0108 */  j          .L80067468
    /* 4034 80067394 920F62A4 */   sh        $v0, 0xF92($v1)
  jlabel .L80067398
    /* 4038 80067398 0680033C */  lui        $v1, %hi(Save_GameState)
    /* 403C 8006739C 20E66324 */  addiu      $v1, $v1, %lo(Save_GameState)
    /* 4040 800673A0 940F6294 */  lhu        $v0, 0xF94($v1)
    /* 4044 800673A4 00000000 */  nop
    /* 4048 800673A8 01004224 */  addiu      $v0, $v0, 0x1
    /* 404C 800673AC 1A9D0108 */  j          .L80067468
    /* 4050 800673B0 940F62A4 */   sh        $v0, 0xF94($v1)
  jlabel .L800673B4
    /* 4054 800673B4 0680033C */  lui        $v1, %hi(Save_GameState)
    /* 4058 800673B8 20E66324 */  addiu      $v1, $v1, %lo(Save_GameState)
    /* 405C 800673BC 7A0F6294 */  lhu        $v0, 0xF7A($v1)
    /* 4060 800673C0 00000000 */  nop
    /* 4064 800673C4 01004224 */  addiu      $v0, $v0, 0x1
    /* 4068 800673C8 1A9D0108 */  j          .L80067468
    /* 406C 800673CC 7A0F62A4 */   sh        $v0, 0xF7A($v1)
  jlabel .L800673D0
    /* 4070 800673D0 0680033C */  lui        $v1, %hi(Save_GameState)
    /* 4074 800673D4 20E66324 */  addiu      $v1, $v1, %lo(Save_GameState)
    /* 4078 800673D8 840F6294 */  lhu        $v0, 0xF84($v1)
    /* 407C 800673DC 00000000 */  nop
    /* 4080 800673E0 01004224 */  addiu      $v0, $v0, 0x1
    /* 4084 800673E4 1A9D0108 */  j          .L80067468
    /* 4088 800673E8 840F62A4 */   sh        $v0, 0xF84($v1)
  jlabel .L800673EC
    /* 408C 800673EC 0680033C */  lui        $v1, %hi(Save_GameState)
    /* 4090 800673F0 20E66324 */  addiu      $v1, $v1, %lo(Save_GameState)
    /* 4094 800673F4 660E6294 */  lhu        $v0, 0xE66($v1)
    /* 4098 800673F8 00000000 */  nop
    /* 409C 800673FC 01004224 */  addiu      $v0, $v0, 0x1
    /* 40A0 80067400 1A9D0108 */  j          .L80067468
    /* 40A4 80067404 660E62A4 */   sh        $v0, 0xE66($v1)
  jlabel .L80067408
    /* 40A8 80067408 0680033C */  lui        $v1, %hi(Save_GameState)
    /* 40AC 8006740C 20E66324 */  addiu      $v1, $v1, %lo(Save_GameState)
    /* 40B0 80067410 720E6294 */  lhu        $v0, 0xE72($v1)
    /* 40B4 80067414 00000000 */  nop
    /* 40B8 80067418 01004224 */  addiu      $v0, $v0, 0x1
    /* 40BC 8006741C 1A9D0108 */  j          .L80067468
    /* 40C0 80067420 720E62A4 */   sh        $v0, 0xE72($v1)
  jlabel .L80067424
    /* 40C4 80067424 0680033C */  lui        $v1, %hi(Save_GameState)
    /* 40C8 80067428 20E66324 */  addiu      $v1, $v1, %lo(Save_GameState)
    /* 40CC 8006742C 300E6294 */  lhu        $v0, 0xE30($v1)
    /* 40D0 80067430 00000000 */  nop
    /* 40D4 80067434 01004224 */  addiu      $v0, $v0, 0x1
    /* 40D8 80067438 1A9D0108 */  j          .L80067468
    /* 40DC 8006743C 300E62A4 */   sh        $v0, 0xE30($v1)
  .L80067440:
    /* 40E0 80067440 AB89000C */  jal        Item_SortList
    /* 40E4 80067444 660000A6 */   sh        $zero, 0x66($s0)
    /* 40E8 80067448 1A9D0108 */  j          .L80067468
    /* 40EC 8006744C 00000000 */   nop
  jlabel .L80067450
    /* 40F0 80067450 0680033C */  lui        $v1, %hi(Save_GameState)
    /* 40F4 80067454 20E66324 */  addiu      $v1, $v1, %lo(Save_GameState)
    /* 40F8 80067458 3C0E6294 */  lhu        $v0, 0xE3C($v1)
    /* 40FC 8006745C 00000000 */  nop
    /* 4100 80067460 01004224 */  addiu      $v0, $v0, 0x1
    /* 4104 80067464 3C0E62A4 */  sh         $v0, 0xE3C($v1)
  jlabel .L80067468
    /* 4108 80067468 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 410C 8006746C 1800B28F */  lw         $s2, 0x18($sp)
    /* 4110 80067470 1400B18F */  lw         $s1, 0x14($sp)
    /* 4114 80067474 1000B08F */  lw         $s0, 0x10($sp)
    /* 4118 80067478 0800E003 */  jr         $ra
    /* 411C 8006747C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg20_SetSpecialFlag
