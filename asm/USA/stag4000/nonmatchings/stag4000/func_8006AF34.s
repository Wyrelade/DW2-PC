nonmatching func_8006AF34, 0x2D8

glabel func_8006AF34
    /* 7BD4 8006AF34 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 7BD8 8006AF38 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 7BDC 8006AF3C 21888000 */  addu       $s1, $a0, $zero
    /* 7BE0 8006AF40 2000BFAF */  sw         $ra, 0x20($sp)
    /* 7BE4 8006AF44 1800B0AF */  sw         $s0, 0x18($sp)
    /* 7BE8 8006AF48 1800238E */  lw         $v1, 0x18($s1)
    /* 7BEC 8006AF4C 00000000 */  nop
    /* 7BF0 8006AF50 0500622C */  sltiu      $v0, $v1, 0x5
    /* 7BF4 8006AF54 08004010 */  beqz       $v0, .L8006AF78
    /* 7BF8 8006AF58 0680023C */   lui       $v0, %hi(jtbl_8006343C)
    /* 7BFC 8006AF5C 3C344224 */  addiu      $v0, $v0, %lo(jtbl_8006343C)
    /* 7C00 8006AF60 80180300 */  sll        $v1, $v1, 2
    /* 7C04 8006AF64 21186200 */  addu       $v1, $v1, $v0
    /* 7C08 8006AF68 0000628C */  lw         $v0, 0x0($v1)
    /* 7C0C 8006AF6C 00000000 */  nop
    /* 7C10 8006AF70 08004000 */  jr         $v0
    /* 7C14 8006AF74 00000000 */   nop
  jlabel .L8006AF78
    /* 7C18 8006AF78 0780103C */  lui        $s0, %hi(D_80072B60)
    /* 7C1C 8006AF7C 602B028E */  lw         $v0, %lo(D_80072B60)($s0)
    /* 7C20 8006AF80 21202002 */  addu       $a0, $s1, $zero
    /* 7C24 8006AF84 E20040A0 */  sb         $zero, 0xE2($v0)
    /* 7C28 8006AF88 602B028E */  lw         $v0, %lo(D_80072B60)($s0)
    /* 7C2C 8006AF8C 28000524 */  addiu      $a1, $zero, 0x28
    /* 7C30 8006AF90 37B9010C */  jal        func_8006E4DC
    /* 7C34 8006AF94 E30040A0 */   sb        $zero, 0xE3($v0)
    /* 7C38 8006AF98 0B020424 */  addiu      $a0, $zero, 0x20B
    /* 7C3C 8006AF9C 0780023C */  lui        $v0, %hi(D_80072AA4)
    /* 7C40 8006AFA0 1000A627 */  addiu      $a2, $sp, 0x10
    /* 7C44 8006AFA4 602B038E */  lw         $v1, %lo(D_80072B60)($s0)
    /* 7C48 8006AFA8 A42A458C */  lw         $a1, %lo(D_80072AA4)($v0)
    /* 7C4C 8006AFAC E4006290 */  lbu        $v0, 0xE4($v1)
    /* 7C50 8006AFB0 1000A524 */  addiu      $a1, $a1, 0x10
    /* 7C54 8006AFB4 2B100200 */  sltu       $v0, $zero, $v0
    /* 7C58 8006AFB8 1F44000C */  jal        Task_Create
    /* 7C5C 8006AFBC 1000A2AF */   sw        $v0, 0x10($sp)
    /* 7C60 8006AFC0 37000424 */  addiu      $a0, $zero, 0x37
    /* 7C64 8006AFC4 A369000C */  jal        Snd_PlayById
    /* 7C68 8006AFC8 21280000 */   addu      $a1, $zero, $zero
    /* 7C6C 8006AFCC 44AB010C */  jal        func_8006AD10
    /* 7C70 8006AFD0 00000000 */   nop
    /* 7C74 8006AFD4 FEAB0108 */  j          .L8006AFF8
    /* 7C78 8006AFD8 00000000 */   nop
  jlabel .L8006AFDC
    /* 7C7C 8006AFDC 1C00228E */  lw         $v0, 0x1C($s1)
    /* 7C80 8006AFE0 00000000 */  nop
    /* 7C84 8006AFE4 21184000 */  addu       $v1, $v0, $zero
    /* 7C88 8006AFE8 01004224 */  addiu      $v0, $v0, 0x1
    /* 7C8C 8006AFEC 09006328 */  slti       $v1, $v1, 0x9
    /* 7C90 8006AFF0 81006014 */  bnez       $v1, .L8006B1F8
    /* 7C94 8006AFF4 1C0022AE */   sw        $v0, 0x1C($s1)
  .L8006AFF8:
    /* 7C98 8006AFF8 6045000C */  jal        Task_NextState2
    /* 7C9C 8006AFFC 21202002 */   addu      $a0, $s1, $zero
    /* 7CA0 8006B000 7EAC0108 */  j          .L8006B1F8
    /* 7CA4 8006B004 00000000 */   nop
  jlabel .L8006B008
    /* 7CA8 8006B008 9DAB010C */  jal        func_8006AE74
    /* 7CAC 8006B00C 00000000 */   nop
    /* 7CB0 8006B010 0680023C */  lui        $v0, %hi(D_8005F6F0)
    /* 7CB4 8006B014 F0F64324 */  addiu      $v1, $v0, %lo(D_8005F6F0)
    /* 7CB8 8006B018 1C00628C */  lw         $v0, 0x1C($v1)
    /* 7CBC 8006B01C 00000000 */  nop
    /* 7CC0 8006B020 0C004018 */  blez       $v0, .L8006B054
    /* 7CC4 8006B024 0B000424 */   addiu     $a0, $zero, 0xB
    /* 7CC8 8006B028 A369000C */  jal        Snd_PlayById
    /* 7CCC 8006B02C 21280000 */   addu      $a1, $zero, $zero
    /* 7CD0 8006B030 21202002 */  addu       $a0, $s1, $zero
    /* 7CD4 8006B034 8545000C */  jal        Task_SetState2
    /* 7CD8 8006B038 04000524 */   addiu     $a1, $zero, 0x4
    /* 7CDC 8006B03C 41AC0108 */  j          .L8006B104
    /* 7CE0 8006B040 00000000 */   nop
  .L8006B044:
    /* 7CE4 8006B044 8A89000C */  jal        Item_CompactBag
    /* 7CE8 8006B048 000080A4 */   sh        $zero, 0x0($a0)
    /* 7CEC 8006B04C 2FAC0108 */  j          .L8006B0BC
    /* 7CF0 8006B050 0780023C */   lui       $v0, %hi(D_80072B60)
  .L8006B054:
    /* 7CF4 8006B054 1400628C */  lw         $v0, 0x14($v1)
    /* 7CF8 8006B058 00000000 */  nop
    /* 7CFC 8006B05C 29004018 */  blez       $v0, .L8006B104
    /* 7D00 8006B060 21280000 */   addu      $a1, $zero, $zero
    /* 7D04 8006B064 0780043C */  lui        $a0, %hi(D_80072B60)
    /* 7D08 8006B068 602B838C */  lw         $v1, %lo(D_80072B60)($a0)
    /* 7D0C 8006B06C 00000000 */  nop
    /* 7D10 8006B070 E2006290 */  lbu        $v0, 0xE2($v1)
    /* 7D14 8006B074 00000000 */  nop
    /* 7D18 8006B078 21106200 */  addu       $v0, $v1, $v0
    /* 7D1C 8006B07C B0004290 */  lbu        $v0, 0xB0($v0)
    /* 7D20 8006B080 00000000 */  nop
    /* 7D24 8006B084 E00062A0 */  sb         $v0, 0xE0($v1)
    /* 7D28 8006B088 0580023C */  lui        $v0, %hi(D_80050720)
    /* 7D2C 8006B08C 2007428C */  lw         $v0, %lo(D_80050720)($v0)
    /* 7D30 8006B090 602B838C */  lw         $v1, %lo(D_80072B60)($a0)
    /* 7D34 8006B094 66004424 */  addiu      $a0, $v0, 0x66
    /* 7D38 8006B098 E0006390 */  lbu        $v1, 0xE0($v1)
  .L8006B09C:
    /* 7D3C 8006B09C 00008294 */  lhu        $v0, 0x0($a0)
    /* 7D40 8006B0A0 00000000 */  nop
    /* 7D44 8006B0A4 E7FF4310 */  beq        $v0, $v1, .L8006B044
    /* 7D48 8006B0A8 0100A524 */   addiu     $a1, $a1, 0x1
    /* 7D4C 8006B0AC 3000A228 */  slti       $v0, $a1, 0x30
    /* 7D50 8006B0B0 FAFF4014 */  bnez       $v0, .L8006B09C
    /* 7D54 8006B0B4 02008424 */   addiu     $a0, $a0, 0x2
    /* 7D58 8006B0B8 0780023C */  lui        $v0, %hi(D_80072B60)
  .L8006B0BC:
    /* 7D5C 8006B0BC 602B428C */  lw         $v0, %lo(D_80072B60)($v0)
    /* 7D60 8006B0C0 00000000 */  nop
    /* 7D64 8006B0C4 E4004290 */  lbu        $v0, 0xE4($v0)
    /* 7D68 8006B0C8 00000000 */  nop
    /* 7D6C 8006B0CC 08004010 */  beqz       $v0, .L8006B0F0
    /* 7D70 8006B0D0 08000524 */   addiu     $a1, $zero, 0x8
    /* 7D74 8006B0D4 2C00228E */  lw         $v0, 0x2C($s1)
    /* 7D78 8006B0D8 00000000 */  nop
    /* 7D7C 8006B0DC 2C00448C */  lw         $a0, 0x2C($v0)
    /* 7D80 8006B0E0 7094010C */  jal        func_800651C0
    /* 7D84 8006B0E4 18008424 */   addiu     $a0, $a0, 0x18
    /* 7D88 8006B0E8 3DAC0108 */  j          .L8006B0F4
    /* 7D8C 8006B0EC 0E000424 */   addiu     $a0, $zero, 0xE
  .L8006B0F0:
    /* 7D90 8006B0F0 0A000424 */  addiu      $a0, $zero, 0xA
  .L8006B0F4:
    /* 7D94 8006B0F4 A369000C */  jal        Snd_PlayById
    /* 7D98 8006B0F8 21280000 */   addu      $a1, $zero, $zero
    /* 7D9C 8006B0FC 6045000C */  jal        Task_NextState2
    /* 7DA0 8006B100 21202002 */   addu      $a0, $s1, $zero
  .L8006B104:
    /* 7DA4 8006B104 1800238E */  lw         $v1, 0x18($s1)
    /* 7DA8 8006B108 02000224 */  addiu      $v0, $zero, 0x2
    /* 7DAC 8006B10C 3A006210 */  beq        $v1, $v0, .L8006B1F8
    /* 7DB0 8006B110 0780023C */   lui       $v0, %hi(D_80072AA4)
    /* 7DB4 8006B114 A42A428C */  lw         $v0, %lo(D_80072AA4)($v0)
    /* 7DB8 8006B118 00000000 */  nop
    /* 7DBC 8006B11C 1000448C */  lw         $a0, 0x10($v0)
    /* 7DC0 8006B120 7045000C */  jal        Task_SetState0
    /* 7DC4 8006B124 02000524 */   addiu     $a1, $zero, 0x2
    /* 7DC8 8006B128 7EAC0108 */  j          .L8006B1F8
    /* 7DCC 8006B12C 00000000 */   nop
  jlabel .L8006B130
    /* 7DD0 8006B130 0780023C */  lui        $v0, %hi(D_80072AA4)
    /* 7DD4 8006B134 A42A428C */  lw         $v0, %lo(D_80072AA4)($v0)
    /* 7DD8 8006B138 00000000 */  nop
    /* 7DDC 8006B13C 1000428C */  lw         $v0, 0x10($v0)
    /* 7DE0 8006B140 00000000 */  nop
    /* 7DE4 8006B144 2C004014 */  bnez       $v0, .L8006B1F8
    /* 7DE8 8006B148 0780023C */   lui       $v0, %hi(D_80072B60)
    /* 7DEC 8006B14C 602B428C */  lw         $v0, %lo(D_80072B60)($v0)
    /* 7DF0 8006B150 00000000 */  nop
    /* 7DF4 8006B154 E4004290 */  lbu        $v0, 0xE4($v0)
    /* 7DF8 8006B158 00000000 */  nop
    /* 7DFC 8006B15C 05004014 */  bnez       $v0, .L8006B174
    /* 7E00 8006B160 21202002 */   addu      $a0, $s1, $zero
    /* 7E04 8006B164 7745000C */  jal        Task_SetState1
    /* 7E08 8006B168 12000524 */   addiu     $a1, $zero, 0x12
    /* 7E0C 8006B16C 7EAC0108 */  j          .L8006B1F8
    /* 7E10 8006B170 00000000 */   nop
  .L8006B174:
    /* 7E14 8006B174 7745000C */  jal        Task_SetState1
    /* 7E18 8006B178 1B000524 */   addiu     $a1, $zero, 0x1B
    /* 7E1C 8006B17C 7EAC0108 */  j          .L8006B1F8
    /* 7E20 8006B180 00000000 */   nop
  jlabel .L8006B184
    /* 7E24 8006B184 0780023C */  lui        $v0, %hi(D_80072AA4)
    /* 7E28 8006B188 A42A428C */  lw         $v0, %lo(D_80072AA4)($v0)
    /* 7E2C 8006B18C 00000000 */  nop
    /* 7E30 8006B190 1000428C */  lw         $v0, 0x10($v0)
    /* 7E34 8006B194 00000000 */  nop
    /* 7E38 8006B198 17004014 */  bnez       $v0, .L8006B1F8
    /* 7E3C 8006B19C 0780103C */   lui       $s0, %hi(D_80072B60)
    /* 7E40 8006B1A0 602B028E */  lw         $v0, %lo(D_80072B60)($s0)
    /* 7E44 8006B1A4 00000000 */  nop
    /* 7E48 8006B1A8 E4004290 */  lbu        $v0, 0xE4($v0)
    /* 7E4C 8006B1AC 00000000 */  nop
    /* 7E50 8006B1B0 09004014 */  bnez       $v0, .L8006B1D8
    /* 7E54 8006B1B4 21202002 */   addu      $a0, $s1, $zero
    /* 7E58 8006B1B8 7745000C */  jal        Task_SetState1
    /* 7E5C 8006B1BC 01000524 */   addiu     $a1, $zero, 0x1
    /* 7E60 8006B1C0 0580023C */  lui        $v0, %hi(D_80050720)
    /* 7E64 8006B1C4 2007428C */  lw         $v0, %lo(D_80050720)($v0)
    /* 7E68 8006B1C8 602B038E */  lw         $v1, %lo(D_80072B60)($s0)
    /* 7E6C 8006B1CC 00004290 */  lbu        $v0, 0x0($v0)
    /* 7E70 8006B1D0 7EAC0108 */  j          .L8006B1F8
    /* 7E74 8006B1D4 7E0062A4 */   sh        $v0, 0x7E($v1)
  .L8006B1D8:
    /* 7E78 8006B1D8 7745000C */  jal        Task_SetState1
    /* 7E7C 8006B1DC 1A000524 */   addiu     $a1, $zero, 0x1A
    /* 7E80 8006B1E0 21202002 */  addu       $a0, $s1, $zero
    /* 7E84 8006B1E4 8545000C */  jal        Task_SetState2
    /* 7E88 8006B1E8 02000524 */   addiu     $a1, $zero, 0x2
    /* 7E8C 8006B1EC 21202002 */  addu       $a0, $s1, $zero
    /* 7E90 8006B1F0 8A45000C */  jal        Task_SetState3
    /* 7E94 8006B1F4 01000524 */   addiu     $a1, $zero, 0x1
  .L8006B1F8:
    /* 7E98 8006B1F8 2000BF8F */  lw         $ra, 0x20($sp)
    /* 7E9C 8006B1FC 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 7EA0 8006B200 1800B08F */  lw         $s0, 0x18($sp)
    /* 7EA4 8006B204 0800E003 */  jr         $ra
    /* 7EA8 8006B208 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8006AF34
