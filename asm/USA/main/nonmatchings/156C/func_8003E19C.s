nonmatching func_8003E19C, 0x2A8

glabel func_8003E19C
    /* 2E99C 8003E19C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2E9A0 8003E1A0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2E9A4 8003E1A4 21808000 */  addu       $s0, $a0, $zero
    /* 2E9A8 8003E1A8 1800BFAF */  sw         $ra, 0x18($sp)
    /* 2E9AC 8003E1AC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2E9B0 8003E1B0 0000038E */  lw         $v1, 0x0($s0)
    /* 2E9B4 8003E1B4 00000000 */  nop
    /* 2E9B8 8003E1B8 3300622C */  sltiu      $v0, $v1, 0x33
    /* 2E9BC 8003E1BC 9B004010 */  beqz       $v0, .L8003E42C
    /* 2E9C0 8003E1C0 80100300 */   sll       $v0, $v1, 2
    /* 2E9C4 8003E1C4 0180013C */  lui        $at, %hi(jtbl_80010BA4)
    /* 2E9C8 8003E1C8 21082200 */  addu       $at, $at, $v0
    /* 2E9CC 8003E1CC A40B228C */  lw         $v0, %lo(jtbl_80010BA4)($at)
    /* 2E9D0 8003E1D0 00000000 */  nop
    /* 2E9D4 8003E1D4 08004000 */  jr         $v0
    /* 2E9D8 8003E1D8 00000000 */   nop
  jlabel .L8003E1DC
    /* 2E9DC 8003E1DC 0680013C */  lui        $at, %hi(D_80062F5C)
    /* 2E9E0 8003E1E0 5C2F20AC */  sw         $zero, %lo(D_80062F5C)($at)
    /* 2E9E4 8003E1E4 0680013C */  lui        $at, %hi(D_80062F60)
    /* 2E9E8 8003E1E8 602F20AC */  sw         $zero, %lo(D_80062F60)($at)
    /* 2E9EC 8003E1EC 0680013C */  lui        $at, %hi(D_80062F58)
    /* 2E9F0 8003E1F0 582F20AC */  sw         $zero, %lo(D_80062F58)($at)
    /* 2E9F4 8003E1F4 0680013C */  lui        $at, %hi(D_80062F68)
    /* 2E9F8 8003E1F8 682F20AC */  sw         $zero, %lo(D_80062F68)($at)
    /* 2E9FC 8003E1FC 0680013C */  lui        $at, %hi(D_80062F64)
    /* 2EA00 8003E200 642F20AC */  sw         $zero, %lo(D_80062F64)($at)
    /* 2EA04 8003E204 0000028E */  lw         $v0, 0x0($s0)
    /* 2EA08 8003E208 00000000 */  nop
    /* 2EA0C 8003E20C 01004224 */  addiu      $v0, $v0, 0x1
    /* 2EA10 8003E210 000002AE */  sw         $v0, 0x0($s0)
  jlabel .L8003E214
    /* 2EA14 8003E214 0480043C */  lui        $a0, %hi(Card_InfoTask)
    /* 2EA18 8003E218 89FE000C */  jal        Card_PushTask
    /* 2EA1C 8003E21C 18DE8424 */   addiu     $a0, $a0, %lo(Card_InfoTask)
    /* 2EA20 8003E220 0AF90008 */  j          .L8003E428
    /* 2EA24 8003E224 0A000224 */   addiu     $v0, $zero, 0xA
  jlabel .L8003E228
    /* 2EA28 8003E228 0680113C */  lui        $s1, %hi(D_80062F84)
    /* 2EA2C 8003E22C 842F3126 */  addiu      $s1, $s1, %lo(D_80062F84)
    /* 2EA30 8003E230 0000238E */  lw         $v1, 0x0($s1)
    /* 2EA34 8003E234 01000524 */  addiu      $a1, $zero, 0x1
    /* 2EA38 8003E238 4B006510 */  beq        $v1, $a1, .L8003E368
    /* 2EA3C 8003E23C 02006228 */   slti      $v0, $v1, 0x2
    /* 2EA40 8003E240 05004010 */  beqz       $v0, .L8003E258
    /* 2EA44 8003E244 03000224 */   addiu     $v0, $zero, 0x3
    /* 2EA48 8003E248 13006010 */  beqz       $v1, .L8003E298
    /* 2EA4C 8003E24C 01000224 */   addiu     $v0, $zero, 0x1
    /* 2EA50 8003E250 0CF90008 */  j          .L8003E430
    /* 2EA54 8003E254 00000000 */   nop
  .L8003E258:
    /* 2EA58 8003E258 43006214 */  bne        $v1, $v0, .L8003E368
    /* 2EA5C 8003E25C 00000000 */   nop
    /* 2EA60 8003E260 0C00228E */  lw         $v0, 0xC($s1)
    /* 2EA64 8003E264 0800238E */  lw         $v1, 0x8($s1)
    /* 2EA68 8003E268 FCFF2426 */  addiu      $a0, $s1, -0x4
    /* 2EA6C 8003E26C 0680013C */  lui        $at, %hi(D_80062F68)
    /* 2EA70 8003E270 682F25AC */  sw         $a1, %lo(D_80062F68)($at)
    /* 2EA74 8003E274 04104500 */  sllv       $v0, $a1, $v0
    /* 2EA78 8003E278 25186200 */  or         $v1, $v1, $v0
    /* 2EA7C 8003E27C A9FF000C */  jal        func_8003FEA4
    /* 2EA80 8003E280 0C0083AC */   sw        $v1, 0xC($a0)
    /* 2EA84 8003E284 0C00248E */  lw         $a0, 0xC($s1)
    /* 2EA88 8003E288 6DFE000C */  jal        _card_clear
    /* 2EA8C 8003E28C 00000000 */   nop
    /* 2EA90 8003E290 0AF90008 */  j          .L8003E428
    /* 2EA94 8003E294 15000224 */   addiu     $v0, $zero, 0x15
  .L8003E298:
    /* 2EA98 8003E298 0AF90008 */  j          .L8003E428
    /* 2EA9C 8003E29C 1E000224 */   addiu     $v0, $zero, 0x1E
  jlabel .L8003E2A0
    /* 2EAA0 8003E2A0 6600010C */  jal        Card_GetHwEventBits
    /* 2EAA4 8003E2A4 00000000 */   nop
    /* 2EAA8 8003E2A8 60004010 */  beqz       $v0, .L8003E42C
    /* 2EAAC 8003E2AC 00000000 */   nop
    /* 2EAB0 8003E2B0 2100010C */  jal        func_80040084
    /* 2EAB4 8003E2B4 00000000 */   nop
    /* 2EAB8 8003E2B8 1E000224 */  addiu      $v0, $zero, 0x1E
    /* 2EABC 8003E2BC 000002AE */  sw         $v0, 0x0($s0)
  jlabel .L8003E2C0
    /* 2EAC0 8003E2C0 A9FF000C */  jal        func_8003FEA4
    /* 2EAC4 8003E2C4 00000000 */   nop
    /* 2EAC8 8003E2C8 0680043C */  lui        $a0, %hi(D_80062F90)
    /* 2EACC 8003E2CC 902F848C */  lw         $a0, %lo(D_80062F90)($a0)
    /* 2EAD0 8003E2D0 69FE000C */  jal        _card_load
    /* 2EAD4 8003E2D4 00000000 */   nop
    /* 2EAD8 8003E2D8 0000028E */  lw         $v0, 0x0($s0)
    /* 2EADC 8003E2DC 0AF90008 */  j          .L8003E428
    /* 2EAE0 8003E2E0 01004224 */   addiu     $v0, $v0, 0x1
  jlabel .L8003E2E4
    /* 2EAE4 8003E2E4 5700010C */  jal        func_8004015C
    /* 2EAE8 8003E2E8 00000000 */   nop
    /* 2EAEC 8003E2EC 50004010 */  beqz       $v0, .L8003E430
    /* 2EAF0 8003E2F0 21100000 */   addu      $v0, $zero, $zero
    /* 2EAF4 8003E2F4 EBFF000C */  jal        func_8003FFAC
    /* 2EAF8 8003E2F8 00000000 */   nop
    /* 2EAFC 8003E2FC 21184000 */  addu       $v1, $v0, $zero
    /* 2EB00 8003E300 0680013C */  lui        $at, %hi(D_80062F64)
    /* 2EB04 8003E304 642F22AC */  sw         $v0, %lo(D_80062F64)($at)
    /* 2EB08 8003E308 01000424 */  addiu      $a0, $zero, 0x1
    /* 2EB0C 8003E30C 22006410 */  beq        $v1, $a0, .L8003E398
    /* 2EB10 8003E310 02006228 */   slti      $v0, $v1, 0x2
    /* 2EB14 8003E314 05004010 */  beqz       $v0, .L8003E32C
    /* 2EB18 8003E318 02000224 */   addiu     $v0, $zero, 0x2
    /* 2EB1C 8003E31C 09006010 */  beqz       $v1, .L8003E344
    /* 2EB20 8003E320 00000000 */   nop
    /* 2EB24 8003E324 EFF80008 */  j          .L8003E3BC
    /* 2EB28 8003E328 00000000 */   nop
  .L8003E32C:
    /* 2EB2C 8003E32C 18006210 */  beq        $v1, $v0, .L8003E390
    /* 2EB30 8003E330 04000224 */   addiu     $v0, $zero, 0x4
    /* 2EB34 8003E334 0E006210 */  beq        $v1, $v0, .L8003E370
    /* 2EB38 8003E338 00000000 */   nop
    /* 2EB3C 8003E33C EFF80008 */  j          .L8003E3BC
    /* 2EB40 8003E340 00000000 */   nop
  .L8003E344:
    /* 2EB44 8003E344 0680023C */  lui        $v0, %hi(D_80062F68)
    /* 2EB48 8003E348 682F428C */  lw         $v0, %lo(D_80062F68)($v0)
    /* 2EB4C 8003E34C 00000000 */  nop
    /* 2EB50 8003E350 02004010 */  beqz       $v0, .L8003E35C
    /* 2EB54 8003E354 21180000 */   addu      $v1, $zero, $zero
    /* 2EB58 8003E358 03000324 */  addiu      $v1, $zero, 0x3
  .L8003E35C:
    /* 2EB5C 8003E35C 0680023C */  lui        $v0, %hi(D_80062F80)
    /* 2EB60 8003E360 802F4224 */  addiu      $v0, $v0, %lo(D_80062F80)
    /* 2EB64 8003E364 040043AC */  sw         $v1, 0x4($v0)
  .L8003E368:
    /* 2EB68 8003E368 0CF90008 */  j          .L8003E430
    /* 2EB6C 8003E36C 01000224 */   addiu     $v0, $zero, 0x1
  .L8003E370:
    /* 2EB70 8003E370 A9FF000C */  jal        func_8003FEA4
    /* 2EB74 8003E374 00000000 */   nop
    /* 2EB78 8003E378 0680043C */  lui        $a0, %hi(D_80062F90)
    /* 2EB7C 8003E37C 902F848C */  lw         $a0, %lo(D_80062F90)($a0)
    /* 2EB80 8003E380 65FE000C */  jal        _card_info
    /* 2EB84 8003E384 00000000 */   nop
    /* 2EB88 8003E388 0AF90008 */  j          .L8003E428
    /* 2EB8C 8003E38C 32000224 */   addiu     $v0, $zero, 0x32
  .L8003E390:
    /* 2EB90 8003E390 0BF90008 */  j          .L8003E42C
    /* 2EB94 8003E394 000004AE */   sw        $a0, 0x0($s0)
  .L8003E398:
    /* 2EB98 8003E398 0680023C */  lui        $v0, %hi(D_80062F5C)
    /* 2EB9C 8003E39C 5C2F428C */  lw         $v0, %lo(D_80062F5C)($v0)
    /* 2EBA0 8003E3A0 00000000 */  nop
    /* 2EBA4 8003E3A4 01004224 */  addiu      $v0, $v0, 0x1
    /* 2EBA8 8003E3A8 0680013C */  lui        $at, %hi(D_80062F5C)
    /* 2EBAC 8003E3AC 5C2F22AC */  sw         $v0, %lo(D_80062F5C)($at)
    /* 2EBB0 8003E3B0 11004228 */  slti       $v0, $v0, 0x11
    /* 2EBB4 8003E3B4 1C004014 */  bnez       $v0, .L8003E428
    /* 2EBB8 8003E3B8 1E000224 */   addiu     $v0, $zero, 0x1E
  .L8003E3BC:
    /* 2EBBC 8003E3BC 0680043C */  lui        $a0, %hi(D_80062F64)
    /* 2EBC0 8003E3C0 642F848C */  lw         $a0, %lo(D_80062F64)($a0)
    /* 2EBC4 8003E3C4 06FD000C */  jal        func_8003F418
    /* 2EBC8 8003E3C8 00000000 */   nop
    /* 2EBCC 8003E3CC 21204000 */  addu       $a0, $v0, $zero
    /* 2EBD0 8003E3D0 01000224 */  addiu      $v0, $zero, 0x1
    /* 2EBD4 8003E3D4 0680033C */  lui        $v1, %hi(D_80062F80)
    /* 2EBD8 8003E3D8 802F6324 */  addiu      $v1, $v1, %lo(D_80062F80)
    /* 2EBDC 8003E3DC 0CF90008 */  j          .L8003E430
    /* 2EBE0 8003E3E0 040064AC */   sw        $a0, 0x4($v1)
  jlabel .L8003E3E4
    /* 2EBE4 8003E3E4 5700010C */  jal        func_8004015C
    /* 2EBE8 8003E3E8 00000000 */   nop
    /* 2EBEC 8003E3EC 10004010 */  beqz       $v0, .L8003E430
    /* 2EBF0 8003E3F0 21100000 */   addu      $v0, $zero, $zero
    /* 2EBF4 8003E3F4 EBFF000C */  jal        func_8003FFAC
    /* 2EBF8 8003E3F8 00000000 */   nop
    /* 2EBFC 8003E3FC 21184000 */  addu       $v1, $v0, $zero
    /* 2EC00 8003E400 0680013C */  lui        $at, %hi(D_80062F64)
    /* 2EC04 8003E404 642F22AC */  sw         $v0, %lo(D_80062F64)($at)
    /* 2EC08 8003E408 07006014 */  bnez       $v1, .L8003E428
    /* 2EC0C 8003E40C 01000224 */   addiu     $v0, $zero, 0x1
    /* 2EC10 8003E410 0680033C */  lui        $v1, %hi(D_80062F80)
    /* 2EC14 8003E414 802F6324 */  addiu      $v1, $v1, %lo(D_80062F80)
    /* 2EC18 8003E418 04000224 */  addiu      $v0, $zero, 0x4
    /* 2EC1C 8003E41C 040062AC */  sw         $v0, 0x4($v1)
    /* 2EC20 8003E420 0CF90008 */  j          .L8003E430
    /* 2EC24 8003E424 01000224 */   addiu     $v0, $zero, 0x1
  .L8003E428:
    /* 2EC28 8003E428 000002AE */  sw         $v0, 0x0($s0)
  jlabel .L8003E42C
    /* 2EC2C 8003E42C 21100000 */  addu       $v0, $zero, $zero
  .L8003E430:
    /* 2EC30 8003E430 1800BF8F */  lw         $ra, 0x18($sp)
    /* 2EC34 8003E434 1400B18F */  lw         $s1, 0x14($sp)
    /* 2EC38 8003E438 1000B08F */  lw         $s0, 0x10($sp)
    /* 2EC3C 8003E43C 0800E003 */  jr         $ra
    /* 2EC40 8003E440 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8003E19C
