nonmatching func_80069C94, 0x2F0

glabel func_80069C94
    /* 6934 80069C94 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 6938 80069C98 1400B1AF */  sw         $s1, 0x14($sp)
    /* 693C 80069C9C 21888000 */  addu       $s1, $a0, $zero
    /* 6940 80069CA0 0780023C */  lui        $v0, %hi(D_80072B60)
    /* 6944 80069CA4 1800BFAF */  sw         $ra, 0x18($sp)
    /* 6948 80069CA8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 694C 80069CAC 2C00238E */  lw         $v1, 0x2C($s1)
    /* 6950 80069CB0 02000424 */  addiu      $a0, $zero, 0x2
    /* 6954 80069CB4 2C00658C */  lw         $a1, 0x2C($v1)
    /* 6958 80069CB8 1800238E */  lw         $v1, 0x18($s1)
    /* 695C 80069CBC 602B468C */  lw         $a2, %lo(D_80072B60)($v0)
    /* 6960 80069CC0 37006410 */  beq        $v1, $a0, .L80069DA0
    /* 6964 80069CC4 03006228 */   slti      $v0, $v1, 0x3
    /* 6968 80069CC8 07004010 */  beqz       $v0, .L80069CE8
    /* 696C 80069CCC 64000224 */   addiu     $v0, $zero, 0x64
    /* 6970 80069CD0 10006010 */  beqz       $v1, .L80069D14
    /* 6974 80069CD4 01000224 */   addiu     $v0, $zero, 0x1
    /* 6978 80069CD8 19006210 */  beq        $v1, $v0, .L80069D40
    /* 697C 80069CDC 0C020424 */   addiu     $a0, $zero, 0x20C
    /* 6980 80069CE0 47A70108 */  j          .L80069D1C
    /* 6984 80069CE4 0780023C */   lui       $v0, %hi(D_80072AA4)
  .L80069CE8:
    /* 6988 80069CE8 89006210 */  beq        $v1, $v0, .L80069F10
    /* 698C 80069CEC 65006228 */   slti      $v0, $v1, 0x65
    /* 6990 80069CF0 05004010 */  beqz       $v0, .L80069D08
    /* 6994 80069CF4 3C000224 */   addiu     $v0, $zero, 0x3C
    /* 6998 80069CF8 79006210 */  beq        $v1, $v0, .L80069EE0
    /* 699C 80069CFC 0C020424 */   addiu     $a0, $zero, 0x20C
    /* 69A0 80069D00 47A70108 */  j          .L80069D1C
    /* 69A4 80069D04 0780023C */   lui       $v0, %hi(D_80072AA4)
  .L80069D08:
    /* 69A8 80069D08 65000224 */  addiu      $v0, $zero, 0x65
    /* 69AC 80069D0C 8C006210 */  beq        $v1, $v0, .L80069F40
    /* 69B0 80069D10 0780023C */   lui       $v0, %hi(D_80072AA4)
  .L80069D14:
    /* 69B4 80069D14 0C020424 */  addiu      $a0, $zero, 0x20C
    /* 69B8 80069D18 0780023C */  lui        $v0, %hi(D_80072AA4)
  .L80069D1C:
    /* 69BC 80069D1C A42A458C */  lw         $a1, %lo(D_80072AA4)($v0)
    /* 69C0 80069D20 21300000 */  addu       $a2, $zero, $zero
    /* 69C4 80069D24 1F44000C */  jal        Task_Create
    /* 69C8 80069D28 1400A524 */   addiu     $a1, $a1, 0x14
    /* 69CC 80069D2C 21202002 */  addu       $a0, $s1, $zero
    /* 69D0 80069D30 37B9010C */  jal        func_8006E4DC
    /* 69D4 80069D34 28000524 */   addiu     $a1, $zero, 0x28
    /* 69D8 80069D38 CCA70108 */  j          .L80069F30
    /* 69DC 80069D3C 00000000 */   nop
  .L80069D40:
    /* 69E0 80069D40 AC00C28C */  lw         $v0, 0xAC($a2)
    /* 69E4 80069D44 00000000 */  nop
    /* 69E8 80069D48 80100200 */  sll        $v0, $v0, 2
    /* 69EC 80069D4C 2110C200 */  addu       $v0, $a2, $v0
    /* 69F0 80069D50 8000428C */  lw         $v0, 0x80($v0)
    /* 69F4 80069D54 10000524 */  addiu      $a1, $zero, 0x10
    /* 69F8 80069D58 1400438C */  lw         $v1, 0x14($v0)
    /* 69FC 80069D5C 18004424 */  addiu      $a0, $v0, 0x18
    /* 6A00 80069D60 4000C2AC */  sw         $v0, 0x40($a2)
    /* 6A04 80069D64 7094010C */  jal        func_800651C0
    /* 6A08 80069D68 3C00C3AC */   sw        $v1, 0x3C($a2)
    /* 6A0C 80069D6C 0780103C */  lui        $s0, %hi(D_80072AA4)
    /* 6A10 80069D70 A42A028E */  lw         $v0, %lo(D_80072AA4)($s0)
    /* 6A14 80069D74 00000000 */  nop
    /* 6A18 80069D78 1400448C */  lw         $a0, 0x14($v0)
    /* 6A1C 80069D7C 7045000C */  jal        Task_SetState0
    /* 6A20 80069D80 02000524 */   addiu     $a1, $zero, 0x2
    /* 6A24 80069D84 A42A028E */  lw         $v0, %lo(D_80072AA4)($s0)
    /* 6A28 80069D88 00000000 */  nop
    /* 6A2C 80069D8C 1400448C */  lw         $a0, 0x14($v0)
    /* 6A30 80069D90 7745000C */  jal        Task_SetState1
    /* 6A34 80069D94 64000524 */   addiu     $a1, $zero, 0x64
    /* 6A38 80069D98 CCA70108 */  j          .L80069F30
    /* 6A3C 80069D9C 00000000 */   nop
  .L80069DA0:
    /* 6A40 80069DA0 1C00228E */  lw         $v0, 0x1C($s1)
    /* 6A44 80069DA4 00000000 */  nop
    /* 6A48 80069DA8 0B004014 */  bnez       $v0, .L80069DD8
    /* 6A4C 80069DAC 0680023C */   lui       $v0, %hi(Pad_State)
    /* 6A50 80069DB0 8C94010C */  jal        func_80065230
    /* 6A54 80069DB4 00000000 */   nop
    /* 6A58 80069DB8 06004010 */  beqz       $v0, .L80069DD4
    /* 6A5C 80069DBC 12000424 */   addiu     $a0, $zero, 0x12
    /* 6A60 80069DC0 A369000C */  jal        Snd_PlayById
    /* 6A64 80069DC4 21280000 */   addu      $a1, $zero, $zero
    /* 6A68 80069DC8 21202002 */  addu       $a0, $s1, $zero
    /* 6A6C 80069DCC 8A45000C */  jal        Task_SetState3
    /* 6A70 80069DD0 01000524 */   addiu     $a1, $zero, 0x1
  .L80069DD4:
    /* 6A74 80069DD4 0680023C */  lui        $v0, %hi(Pad_State)
  .L80069DD8:
    /* 6A78 80069DD8 F0F64324 */  addiu      $v1, $v0, %lo(Pad_State)
    /* 6A7C 80069DDC 1C00628C */  lw         $v0, 0x1C($v1)
    /* 6A80 80069DE0 00000000 */  nop
    /* 6A84 80069DE4 08004018 */  blez       $v0, .L80069E08
    /* 6A88 80069DE8 0B000424 */   addiu     $a0, $zero, 0xB
    /* 6A8C 80069DEC A369000C */  jal        Snd_PlayById
    /* 6A90 80069DF0 21280000 */   addu      $a1, $zero, $zero
    /* 6A94 80069DF4 21202002 */  addu       $a0, $s1, $zero
    /* 6A98 80069DF8 8545000C */  jal        Task_SetState2
    /* 6A9C 80069DFC 64000524 */   addiu     $a1, $zero, 0x64
    /* 6AA0 80069E00 DCA70108 */  j          .L80069F70
    /* 6AA4 80069E04 00000000 */   nop
  .L80069E08:
    /* 6AA8 80069E08 1800628C */  lw         $v0, 0x18($v1)
    /* 6AAC 80069E0C 00000000 */  nop
    /* 6AB0 80069E10 15004018 */  blez       $v0, .L80069E68
    /* 6AB4 80069E14 0780023C */   lui       $v0, %hi(D_80072B60)
    /* 6AB8 80069E18 602B448C */  lw         $a0, %lo(D_80072B60)($v0)
    /* 6ABC 80069E1C 00000000 */  nop
    /* 6AC0 80069E20 A800868C */  lw         $a2, 0xA8($a0)
    /* 6AC4 80069E24 00000000 */  nop
    /* 6AC8 80069E28 0200C228 */  slti       $v0, $a2, 0x2
    /* 6ACC 80069E2C 0F004014 */  bnez       $v0, .L80069E6C
    /* 6AD0 80069E30 0680023C */   lui       $v0, %hi(D_8005F704)
    /* 6AD4 80069E34 AC00828C */  lw         $v0, 0xAC($a0)
    /* 6AD8 80069E38 00000000 */  nop
    /* 6ADC 80069E3C 01004324 */  addiu      $v1, $v0, 0x1
    /* 6AE0 80069E40 2A106600 */  slt        $v0, $v1, $a2
    /* 6AE4 80069E44 02004010 */  beqz       $v0, .L80069E50
    /* 6AE8 80069E48 21280000 */   addu      $a1, $zero, $zero
    /* 6AEC 80069E4C 21286000 */  addu       $a1, $v1, $zero
  .L80069E50:
    /* 6AF0 80069E50 AC0085AC */  sw         $a1, 0xAC($a0)
    /* 6AF4 80069E54 21202002 */  addu       $a0, $s1, $zero
    /* 6AF8 80069E58 8545000C */  jal        Task_SetState2
    /* 6AFC 80069E5C 01000524 */   addiu     $a1, $zero, 0x1
    /* 6B00 80069E60 DCA70108 */  j          .L80069F70
    /* 6B04 80069E64 00000000 */   nop
  .L80069E68:
    /* 6B08 80069E68 0680023C */  lui        $v0, %hi(D_8005F704)
  .L80069E6C:
    /* 6B0C 80069E6C 04F7428C */  lw         $v0, %lo(D_8005F704)($v0)
    /* 6B10 80069E70 00000000 */  nop
    /* 6B14 80069E74 3E004018 */  blez       $v0, .L80069F70
    /* 6B18 80069E78 0780043C */   lui       $a0, %hi(D_80072858)
    /* 6B1C 80069E7C 48BA010C */  jal        func_8006E920
    /* 6B20 80069E80 58288424 */   addiu     $a0, $a0, %lo(D_80072858)
    /* 6B24 80069E84 0A004010 */  beqz       $v0, .L80069EB0
    /* 6B28 80069E88 01000424 */   addiu     $a0, $zero, 0x1
    /* 6B2C 80069E8C 21284000 */  addu       $a1, $v0, $zero
    /* 6B30 80069E90 21300000 */  addu       $a2, $zero, $zero
    /* 6B34 80069E94 849D010C */  jal        func_80067610
    /* 6B38 80069E98 2138C000 */   addu      $a3, $a2, $zero
    /* 6B3C 80069E9C 21202002 */  addu       $a0, $s1, $zero
    /* 6B40 80069EA0 8545000C */  jal        Task_SetState2
    /* 6B44 80069EA4 3C000524 */   addiu     $a1, $zero, 0x3C
    /* 6B48 80069EA8 DCA70108 */  j          .L80069F70
    /* 6B4C 80069EAC 00000000 */   nop
  .L80069EB0:
    /* 6B50 80069EB0 21202002 */  addu       $a0, $s1, $zero
    /* 6B54 80069EB4 7745000C */  jal        Task_SetState1
    /* 6B58 80069EB8 11000524 */   addiu     $a1, $zero, 0x11
    /* 6B5C 80069EBC 0780043C */  lui        $a0, %hi(D_80072B60)
    /* 6B60 80069EC0 602B838C */  lw         $v1, %lo(D_80072B60)($a0)
    /* 6B64 80069EC4 01000224 */  addiu      $v0, $zero, 0x1
    /* 6B68 80069EC8 E40062A0 */  sb         $v0, 0xE4($v1)
    /* 6B6C 80069ECC 602B838C */  lw         $v1, %lo(D_80072B60)($a0)
    /* 6B70 80069ED0 00000000 */  nop
    /* 6B74 80069ED4 B0006290 */  lbu        $v0, 0xB0($v1)
    /* 6B78 80069ED8 DCA70108 */  j          .L80069F70
    /* 6B7C 80069EDC E00062A0 */   sb        $v0, 0xE0($v1)
  .L80069EE0:
    /* 6B80 80069EE0 C19D010C */  jal        func_80067704
    /* 6B84 80069EE4 01000424 */   addiu     $a0, $zero, 0x1
    /* 6B88 80069EE8 01000324 */  addiu      $v1, $zero, 0x1
    /* 6B8C 80069EEC 20004314 */  bne        $v0, $v1, .L80069F70
    /* 6B90 80069EF0 21202002 */   addu      $a0, $s1, $zero
    /* 6B94 80069EF4 8545000C */  jal        Task_SetState2
    /* 6B98 80069EF8 02000524 */   addiu     $a1, $zero, 0x2
    /* 6B9C 80069EFC 21202002 */  addu       $a0, $s1, $zero
    /* 6BA0 80069F00 8A45000C */  jal        Task_SetState3
    /* 6BA4 80069F04 01000524 */   addiu     $a1, $zero, 0x1
    /* 6BA8 80069F08 DCA70108 */  j          .L80069F70
    /* 6BAC 80069F0C 00000000 */   nop
  .L80069F10:
    /* 6BB0 80069F10 4D94010C */  jal        func_80065134
    /* 6BB4 80069F14 1800A424 */   addiu     $a0, $a1, 0x18
    /* 6BB8 80069F18 0780023C */  lui        $v0, %hi(D_80072AA4)
    /* 6BBC 80069F1C A42A428C */  lw         $v0, %lo(D_80072AA4)($v0)
    /* 6BC0 80069F20 00000000 */  nop
    /* 6BC4 80069F24 1400448C */  lw         $a0, 0x14($v0)
    /* 6BC8 80069F28 7045000C */  jal        Task_SetState0
    /* 6BCC 80069F2C 02000524 */   addiu     $a1, $zero, 0x2
  .L80069F30:
    /* 6BD0 80069F30 6045000C */  jal        Task_NextState2
    /* 6BD4 80069F34 21202002 */   addu      $a0, $s1, $zero
    /* 6BD8 80069F38 DCA70108 */  j          .L80069F70
    /* 6BDC 80069F3C 00000000 */   nop
  .L80069F40:
    /* 6BE0 80069F40 A42A428C */  lw         $v0, %lo(D_80072AA4)($v0)
    /* 6BE4 80069F44 00000000 */  nop
    /* 6BE8 80069F48 1400428C */  lw         $v0, 0x14($v0)
    /* 6BEC 80069F4C 00000000 */  nop
    /* 6BF0 80069F50 07004014 */  bnez       $v0, .L80069F70
    /* 6BF4 80069F54 0580023C */   lui       $v0, %hi(Save_GameStatePtr)
    /* 6BF8 80069F58 2007428C */  lw         $v0, %lo(Save_GameStatePtr)($v0)
    /* 6BFC 80069F5C 21202002 */  addu       $a0, $s1, $zero
    /* 6C00 80069F60 00004290 */  lbu        $v0, 0x0($v0)
    /* 6C04 80069F64 01000524 */  addiu      $a1, $zero, 0x1
    /* 6C08 80069F68 7745000C */  jal        Task_SetState1
    /* 6C0C 80069F6C 7E00C2A4 */   sh        $v0, 0x7E($a2)
  .L80069F70:
    /* 6C10 80069F70 1800BF8F */  lw         $ra, 0x18($sp)
    /* 6C14 80069F74 1400B18F */  lw         $s1, 0x14($sp)
    /* 6C18 80069F78 1000B08F */  lw         $s0, 0x10($sp)
    /* 6C1C 80069F7C 0800E003 */  jr         $ra
    /* 6C20 80069F80 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80069C94
