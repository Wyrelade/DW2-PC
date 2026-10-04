nonmatching Stg20_TestSpecialFlag, 0x3EC

glabel Stg20_TestSpecialFlag
    /* 37E8 80066B48 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 37EC 80066B4C D8DC8324 */  addiu      $v1, $a0, -0x2328
    /* 37F0 80066B50 2400622C */  sltiu      $v0, $v1, 0x24
    /* 37F4 80066B54 F2004010 */  beqz       $v0, .L80066F20
    /* 37F8 80066B58 1000BFAF */   sw        $ra, 0x10($sp)
    /* 37FC 80066B5C 0680023C */  lui        $v0, %hi(jtbl_800633F8)
    /* 3800 80066B60 F8334224 */  addiu      $v0, $v0, %lo(jtbl_800633F8)
    /* 3804 80066B64 80180300 */  sll        $v1, $v1, 2
    /* 3808 80066B68 21186200 */  addu       $v1, $v1, $v0
    /* 380C 80066B6C 0000628C */  lw         $v0, 0x0($v1)
    /* 3810 80066B70 00000000 */  nop
    /* 3814 80066B74 08004000 */  jr         $v0
    /* 3818 80066B78 00000000 */   nop
  jlabel .L80066B7C
    /* 381C 80066B7C 078A000C */  jal        Item_GetBagCapacity
    /* 3820 80066B80 00000000 */   nop
    /* 3824 80066B84 21284000 */  addu       $a1, $v0, $zero
    /* 3828 80066B88 E500A018 */  blez       $a1, .L80066F20
    /* 382C 80066B8C 21180000 */   addu      $v1, $zero, $zero
    /* 3830 80066B90 0680023C */  lui        $v0, %hi(Save_GameState)
    /* 3834 80066B94 20E64424 */  addiu      $a0, $v0, %lo(Save_GameState)
  .L80066B98:
    /* 3838 80066B98 66008294 */  lhu        $v0, 0x66($a0)
    /* 383C 80066B9C 00000000 */  nop
    /* 3840 80066BA0 37004010 */  beqz       $v0, .L80066C80
    /* 3844 80066BA4 01006324 */   addiu     $v1, $v1, 0x1
    /* 3848 80066BA8 2A106500 */  slt        $v0, $v1, $a1
    /* 384C 80066BAC FAFF4014 */  bnez       $v0, .L80066B98
    /* 3850 80066BB0 02008424 */   addiu     $a0, $a0, 0x2
    /* 3854 80066BB4 C99B0108 */  j          .L80066F24
    /* 3858 80066BB8 21100000 */   addu      $v0, $zero, $zero
  jlabel .L80066BBC
    /* 385C 80066BBC 21280000 */  addu       $a1, $zero, $zero
    /* 3860 80066BC0 2130A000 */  addu       $a2, $a1, $zero
    /* 3864 80066BC4 2120A000 */  addu       $a0, $a1, $zero
    /* 3868 80066BC8 0680023C */  lui        $v0, %hi(Save_GameState)
    /* 386C 80066BCC 20E64324 */  addiu      $v1, $v0, %lo(Save_GameState)
  .L80066BD0:
    /* 3870 80066BD0 E4006290 */  lbu        $v0, 0xE4($v1)
    /* 3874 80066BD4 00000000 */  nop
    /* 3878 80066BD8 02004014 */  bnez       $v0, .L80066BE4
    /* 387C 80066BDC 00000000 */   nop
    /* 3880 80066BE0 01000624 */  addiu      $a2, $zero, 0x1
  .L80066BE4:
    /* 3884 80066BE4 0200422C */  sltiu      $v0, $v0, 0x2
    /* 3888 80066BE8 02004014 */  bnez       $v0, .L80066BF4
    /* 388C 80066BEC 00000000 */   nop
    /* 3890 80066BF0 0100A524 */  addiu      $a1, $a1, 0x1
  .L80066BF4:
    /* 3894 80066BF4 01008424 */  addiu      $a0, $a0, 0x1
    /* 3898 80066BF8 24008228 */  slti       $v0, $a0, 0x24
    /* 389C 80066BFC F4FF4014 */  bnez       $v0, .L80066BD0
    /* 38A0 80066C00 5C006324 */   addiu     $v1, $v1, 0x5C
    /* 38A4 80066C04 C700C010 */  beqz       $a2, .L80066F24
    /* 38A8 80066C08 21100000 */   addu      $v0, $zero, $zero
    /* 38AC 80066C0C C99B0108 */  j          .L80066F24
    /* 38B0 80066C10 0C00A228 */   slti      $v0, $a1, 0xC
  jlabel .L80066C14
    /* 38B4 80066C14 939A010C */  jal        Stg20_OwnsDigi
    /* 38B8 80066C18 DA000424 */   addiu     $a0, $zero, 0xDA
    /* 38BC 80066C1C C99B0108 */  j          .L80066F24
    /* 38C0 80066C20 00000000 */   nop
  jlabel .L80066C24
    /* 38C4 80066C24 939A010C */  jal        Stg20_OwnsDigi
    /* 38C8 80066C28 D1000424 */   addiu     $a0, $zero, 0xD1
    /* 38CC 80066C2C C99B0108 */  j          .L80066F24
    /* 38D0 80066C30 00000000 */   nop
  jlabel .L80066C34
    /* 38D4 80066C34 939A010C */  jal        Stg20_OwnsDigi
    /* 38D8 80066C38 43000424 */   addiu     $a0, $zero, 0x43
    /* 38DC 80066C3C C99B0108 */  j          .L80066F24
    /* 38E0 80066C40 00000000 */   nop
  jlabel .L80066C44
    /* 38E4 80066C44 21280000 */  addu       $a1, $zero, $zero
    /* 38E8 80066C48 0680023C */  lui        $v0, %hi(Save_GameState)
    /* 38EC 80066C4C 20E64424 */  addiu      $a0, $v0, %lo(Save_GameState)
  .L80066C50:
    /* 38F0 80066C50 E4008390 */  lbu        $v1, 0xE4($a0)
    /* 38F4 80066C54 0300A224 */  addiu      $v0, $a1, 0x3
    /* 38F8 80066C58 05006214 */  bne        $v1, $v0, .L80066C70
    /* 38FC 80066C5C 00000000 */   nop
    /* 3900 80066C60 FA008284 */  lh         $v0, 0xFA($a0)
    /* 3904 80066C64 00000000 */  nop
    /* 3908 80066C68 AE004014 */  bnez       $v0, .L80066F24
    /* 390C 80066C6C 21100000 */   addu      $v0, $zero, $zero
  .L80066C70:
    /* 3910 80066C70 0100A524 */  addiu      $a1, $a1, 0x1
    /* 3914 80066C74 0300A228 */  slti       $v0, $a1, 0x3
    /* 3918 80066C78 F5FF4014 */  bnez       $v0, .L80066C50
    /* 391C 80066C7C 5C008424 */   addiu     $a0, $a0, 0x5C
  .L80066C80:
    /* 3920 80066C80 C99B0108 */  j          .L80066F24
    /* 3924 80066C84 01000224 */   addiu     $v0, $zero, 0x1
  jlabel .L80066C88
    /* 3928 80066C88 0680023C */  lui        $v0, %hi(D_8005E64E)
    /* 392C 80066C8C 4EE64294 */  lhu        $v0, %lo(D_8005E64E)($v0)
    /* 3930 80066C90 00000000 */  nop
    /* 3934 80066C94 1000422C */  sltiu      $v0, $v0, 0x10
    /* 3938 80066C98 C99B0108 */  j          .L80066F24
    /* 393C 80066C9C 01004238 */   xori      $v0, $v0, 0x1
  jlabel .L80066CA0
    /* 3940 80066CA0 0680023C */  lui        $v0, %hi(D_8005E64E)
    /* 3944 80066CA4 4EE64294 */  lhu        $v0, %lo(D_8005E64E)($v0)
    /* 3948 80066CA8 00000000 */  nop
    /* 394C 80066CAC 1F00422C */  sltiu      $v0, $v0, 0x1F
    /* 3950 80066CB0 C99B0108 */  j          .L80066F24
    /* 3954 80066CB4 01004238 */   xori      $v0, $v0, 0x1
  jlabel .L80066CB8
    /* 3958 80066CB8 0680023C */  lui        $v0, %hi(D_8005F790)
    /* 395C 80066CBC 90F7428C */  lw         $v0, %lo(D_8005F790)($v0)
    /* 3960 80066CC0 00000000 */  nop
    /* 3964 80066CC4 2A034238 */  xori       $v0, $v0, 0x32A
    /* 3968 80066CC8 C99B0108 */  j          .L80066F24
    /* 396C 80066CCC 0100422C */   sltiu     $v0, $v0, 0x1
  jlabel .L80066CD0
    /* 3970 80066CD0 0680023C */  lui        $v0, %hi(D_8005F790)
    /* 3974 80066CD4 90F7428C */  lw         $v0, %lo(D_8005F790)($v0)
    /* 3978 80066CD8 00000000 */  nop
    /* 397C 80066CDC 2B034238 */  xori       $v0, $v0, 0x32B
    /* 3980 80066CE0 C99B0108 */  j          .L80066F24
    /* 3984 80066CE4 0100422C */   sltiu     $v0, $v0, 0x1
  jlabel .L80066CE8
    /* 3988 80066CE8 0680023C */  lui        $v0, %hi(Sys_State)
    /* 398C 80066CEC 70F74424 */  addiu      $a0, $v0, %lo(Sys_State)
    /* 3990 80066CF0 1800838C */  lw         $v1, 0x18($a0)
    /* 3994 80066CF4 01030224 */  addiu      $v0, $zero, 0x301
    /* 3998 80066CF8 05006214 */  bne        $v1, $v0, .L80066D10
    /* 399C 80066CFC 0680023C */   lui       $v0, %hi(Sys_State)
    /* 39A0 80066D00 2400838C */  lw         $v1, 0x24($a0)
    /* 39A4 80066D04 03000224 */  addiu      $v0, $zero, 0x3
    /* 39A8 80066D08 DDFF6210 */  beq        $v1, $v0, .L80066C80
    /* 39AC 80066D0C 0680023C */   lui       $v0, %hi(Sys_State)
  .L80066D10:
    /* 39B0 80066D10 70F74424 */  addiu      $a0, $v0, %lo(Sys_State)
    /* 39B4 80066D14 1800838C */  lw         $v1, 0x18($a0)
    /* 39B8 80066D18 21030224 */  addiu      $v0, $zero, 0x321
    /* 39BC 80066D1C 81006214 */  bne        $v1, $v0, .L80066F24
    /* 39C0 80066D20 21100000 */   addu      $v0, $zero, $zero
    /* 39C4 80066D24 2400848C */  lw         $a0, 0x24($a0)
    /* 39C8 80066D28 02000324 */  addiu      $v1, $zero, 0x2
    /* 39CC 80066D2C 7D008310 */  beq        $a0, $v1, .L80066F24
    /* 39D0 80066D30 01000224 */   addiu     $v0, $zero, 0x1
    /* 39D4 80066D34 C99B0108 */  j          .L80066F24
    /* 39D8 80066D38 21100000 */   addu      $v0, $zero, $zero
  jlabel .L80066D3C
    /* 39DC 80066D3C 0680023C */  lui        $v0, %hi(Sys_State)
    /* 39E0 80066D40 70F74424 */  addiu      $a0, $v0, %lo(Sys_State)
    /* 39E4 80066D44 1800838C */  lw         $v1, 0x18($a0)
    /* 39E8 80066D48 01030224 */  addiu      $v0, $zero, 0x301
    /* 39EC 80066D4C 05006214 */  bne        $v1, $v0, .L80066D64
    /* 39F0 80066D50 0680023C */   lui       $v0, %hi(Sys_State)
    /* 39F4 80066D54 2400838C */  lw         $v1, 0x24($a0)
    /* 39F8 80066D58 04000224 */  addiu      $v0, $zero, 0x4
    /* 39FC 80066D5C C8FF6210 */  beq        $v1, $v0, .L80066C80
    /* 3A00 80066D60 0680023C */   lui       $v0, %hi(Sys_State)
  .L80066D64:
    /* 3A04 80066D64 70F74424 */  addiu      $a0, $v0, %lo(Sys_State)
    /* 3A08 80066D68 1800838C */  lw         $v1, 0x18($a0)
    /* 3A0C 80066D6C 21030224 */  addiu      $v0, $zero, 0x321
    /* 3A10 80066D70 6C006214 */  bne        $v1, $v0, .L80066F24
    /* 3A14 80066D74 21100000 */   addu      $v0, $zero, $zero
    /* 3A18 80066D78 2400848C */  lw         $a0, 0x24($a0)
    /* 3A1C 80066D7C 03000324 */  addiu      $v1, $zero, 0x3
    /* 3A20 80066D80 68008310 */  beq        $a0, $v1, .L80066F24
    /* 3A24 80066D84 01000224 */   addiu     $v0, $zero, 0x1
    /* 3A28 80066D88 C99B0108 */  j          .L80066F24
    /* 3A2C 80066D8C 21100000 */   addu      $v0, $zero, $zero
  jlabel .L80066D90
    /* 3A30 80066D90 0680023C */  lui        $v0, %hi(D_8005E628)
    /* 3A34 80066D94 28E6428C */  lw         $v0, %lo(D_8005E628)($v0)
    /* 3A38 80066D98 00000000 */  nop
    /* 3A3C 80066D9C F4014228 */  slti       $v0, $v0, 0x1F4
    /* 3A40 80066DA0 C99B0108 */  j          .L80066F24
    /* 3A44 80066DA4 01004238 */   xori      $v0, $v0, 0x1
  jlabel .L80066DA8
    /* 3A48 80066DA8 0680023C */  lui        $v0, %hi(D_8005E628)
    /* 3A4C 80066DAC 28E6428C */  lw         $v0, %lo(D_8005E628)($v0)
    /* 3A50 80066DB0 00000000 */  nop
    /* 3A54 80066DB4 E8034228 */  slti       $v0, $v0, 0x3E8
    /* 3A58 80066DB8 C99B0108 */  j          .L80066F24
    /* 3A5C 80066DBC 01004238 */   xori      $v0, $v0, 0x1
  jlabel .L80066DC0
    /* 3A60 80066DC0 0680023C */  lui        $v0, %hi(D_8005E628)
    /* 3A64 80066DC4 28E6428C */  lw         $v0, %lo(D_8005E628)($v0)
    /* 3A68 80066DC8 00000000 */  nop
    /* 3A6C 80066DCC DC054228 */  slti       $v0, $v0, 0x5DC
    /* 3A70 80066DD0 C99B0108 */  j          .L80066F24
    /* 3A74 80066DD4 01004238 */   xori      $v0, $v0, 0x1
  jlabel .L80066DD8
    /* 3A78 80066DD8 0680023C */  lui        $v0, %hi(D_8005E628)
    /* 3A7C 80066DDC 28E6428C */  lw         $v0, %lo(D_8005E628)($v0)
    /* 3A80 80066DE0 00000000 */  nop
    /* 3A84 80066DE4 D0074228 */  slti       $v0, $v0, 0x7D0
    /* 3A88 80066DE8 C99B0108 */  j          .L80066F24
    /* 3A8C 80066DEC 01004238 */   xori      $v0, $v0, 0x1
  jlabel .L80066DF0
    /* 3A90 80066DF0 0680023C */  lui        $v0, %hi(D_8005E628)
    /* 3A94 80066DF4 28E6428C */  lw         $v0, %lo(D_8005E628)($v0)
    /* 3A98 80066DF8 00000000 */  nop
    /* 3A9C 80066DFC C4094228 */  slti       $v0, $v0, 0x9C4
    /* 3AA0 80066E00 C99B0108 */  j          .L80066F24
    /* 3AA4 80066E04 01004238 */   xori      $v0, $v0, 0x1
  jlabel .L80066E08
    /* 3AA8 80066E08 0680023C */  lui        $v0, %hi(D_8005E628)
    /* 3AAC 80066E0C 28E6428C */  lw         $v0, %lo(D_8005E628)($v0)
    /* 3AB0 80066E10 00000000 */  nop
    /* 3AB4 80066E14 B80B4228 */  slti       $v0, $v0, 0xBB8
    /* 3AB8 80066E18 C99B0108 */  j          .L80066F24
    /* 3ABC 80066E1C 01004238 */   xori      $v0, $v0, 0x1
  jlabel .L80066E20
    /* 3AC0 80066E20 0680023C */  lui        $v0, %hi(D_8005E628)
    /* 3AC4 80066E24 28E6428C */  lw         $v0, %lo(D_8005E628)($v0)
    /* 3AC8 80066E28 00000000 */  nop
    /* 3ACC 80066E2C AC0D4228 */  slti       $v0, $v0, 0xDAC
    /* 3AD0 80066E30 C99B0108 */  j          .L80066F24
    /* 3AD4 80066E34 01004238 */   xori      $v0, $v0, 0x1
  jlabel .L80066E38
    /* 3AD8 80066E38 0680023C */  lui        $v0, %hi(D_8005E628)
    /* 3ADC 80066E3C 28E6428C */  lw         $v0, %lo(D_8005E628)($v0)
    /* 3AE0 80066E40 00000000 */  nop
    /* 3AE4 80066E44 A00F4228 */  slti       $v0, $v0, 0xFA0
    /* 3AE8 80066E48 C99B0108 */  j          .L80066F24
    /* 3AEC 80066E4C 01004238 */   xori      $v0, $v0, 0x1
  jlabel .L80066E50
    /* 3AF0 80066E50 0680023C */  lui        $v0, %hi(D_8005E632)
    /* 3AF4 80066E54 32E64290 */  lbu        $v0, %lo(D_8005E632)($v0)
    /* 3AF8 80066E58 C99B0108 */  j          .L80066F24
    /* 3AFC 80066E5C 0200422C */   sltiu     $v0, $v0, 0x2
  jlabel .L80066E60
    /* 3B00 80066E60 0680023C */  lui        $v0, %hi(D_8005E632)
    /* 3B04 80066E64 32E64290 */  lbu        $v0, %lo(D_8005E632)($v0)
    /* 3B08 80066E68 C99B0108 */  j          .L80066F24
    /* 3B0C 80066E6C 0300422C */   sltiu     $v0, $v0, 0x3
  jlabel .L80066E70
    /* 3B10 80066E70 0680023C */  lui        $v0, %hi(D_8005E632)
    /* 3B14 80066E74 32E64290 */  lbu        $v0, %lo(D_8005E632)($v0)
    /* 3B18 80066E78 C99B0108 */  j          .L80066F24
    /* 3B1C 80066E7C 0400422C */   sltiu     $v0, $v0, 0x4
  jlabel .L80066E80
    /* 3B20 80066E80 0680023C */  lui        $v0, %hi(D_8005E632)
    /* 3B24 80066E84 32E64290 */  lbu        $v0, %lo(D_8005E632)($v0)
    /* 3B28 80066E88 C99B0108 */  j          .L80066F24
    /* 3B2C 80066E8C 0500422C */   sltiu     $v0, $v0, 0x5
  jlabel .L80066E90
    /* 3B30 80066E90 0680023C */  lui        $v0, %hi(D_8005E632)
    /* 3B34 80066E94 32E64290 */  lbu        $v0, %lo(D_8005E632)($v0)
    /* 3B38 80066E98 C99B0108 */  j          .L80066F24
    /* 3B3C 80066E9C 0600422C */   sltiu     $v0, $v0, 0x6
  jlabel .L80066EA0
    /* 3B40 80066EA0 0680023C */  lui        $v0, %hi(D_8005E632)
    /* 3B44 80066EA4 32E64290 */  lbu        $v0, %lo(D_8005E632)($v0)
    /* 3B48 80066EA8 C99B0108 */  j          .L80066F24
    /* 3B4C 80066EAC 0700422C */   sltiu     $v0, $v0, 0x7
  jlabel .L80066EB0
    /* 3B50 80066EB0 0680023C */  lui        $v0, %hi(D_8005E632)
    /* 3B54 80066EB4 32E64290 */  lbu        $v0, %lo(D_8005E632)($v0)
    /* 3B58 80066EB8 C99B0108 */  j          .L80066F24
    /* 3B5C 80066EBC 0800422C */   sltiu     $v0, $v0, 0x8
  jlabel .L80066EC0
    /* 3B60 80066EC0 0680023C */  lui        $v0, %hi(D_8005E632)
    /* 3B64 80066EC4 32E64290 */  lbu        $v0, %lo(D_8005E632)($v0)
    /* 3B68 80066EC8 C99B0108 */  j          .L80066F24
    /* 3B6C 80066ECC 0900422C */   sltiu     $v0, $v0, 0x9
  jlabel .L80066ED0
    /* 3B70 80066ED0 0680023C */  lui        $v0, %hi(D_8005E632)
    /* 3B74 80066ED4 32E64290 */  lbu        $v0, %lo(D_8005E632)($v0)
    /* 3B78 80066ED8 C99B0108 */  j          .L80066F24
    /* 3B7C 80066EDC 0A00422C */   sltiu     $v0, $v0, 0xA
  jlabel .L80066EE0
    /* 3B80 80066EE0 0680023C */  lui        $v0, %hi(D_8005E632)
    /* 3B84 80066EE4 32E64290 */  lbu        $v0, %lo(D_8005E632)($v0)
    /* 3B88 80066EE8 C99B0108 */  j          .L80066F24
    /* 3B8C 80066EEC 0B00422C */   sltiu     $v0, $v0, 0xB
  jlabel .L80066EF0
    /* 3B90 80066EF0 9E87000C */  jal        Flag_Test
    /* 3B94 80066EF4 C6020424 */   addiu     $a0, $zero, 0x2C6
    /* 3B98 80066EF8 0A004010 */  beqz       $v0, .L80066F24
    /* 3B9C 80066EFC 21100000 */   addu      $v0, $zero, $zero
    /* 3BA0 80066F00 9E87000C */  jal        Flag_Test
    /* 3BA4 80066F04 C7020424 */   addiu     $a0, $zero, 0x2C7
    /* 3BA8 80066F08 05004010 */  beqz       $v0, .L80066F20
    /* 3BAC 80066F0C 00000000 */   nop
    /* 3BB0 80066F10 9E87000C */  jal        Flag_Test
    /* 3BB4 80066F14 C8020424 */   addiu     $a0, $zero, 0x2C8
    /* 3BB8 80066F18 C99B0108 */  j          .L80066F24
    /* 3BBC 80066F1C 2B100200 */   sltu      $v0, $zero, $v0
  jlabel .L80066F20
    /* 3BC0 80066F20 21100000 */  addu       $v0, $zero, $zero
  .L80066F24:
    /* 3BC4 80066F24 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3BC8 80066F28 00000000 */  nop
    /* 3BCC 80066F2C 0800E003 */  jr         $ra
    /* 3BD0 80066F30 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg20_TestSpecialFlag
