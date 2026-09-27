nonmatching func_8002E2C4, 0x91C

glabel func_8002E2C4
    /* 1EAC4 8002E2C4 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 1EAC8 8002E2C8 0680023C */  lui        $v0, %hi(D_80061B14)
    /* 1EACC 8002E2CC 141B428C */  lw         $v0, %lo(D_80061B14)($v0)
    /* 1EAD0 8002E2D0 01000424 */  addiu      $a0, $zero, 0x1
    /* 1EAD4 8002E2D4 3E024410 */  beq        $v0, $a0, .L8002EBD0
    /* 1EAD8 8002E2D8 3800BFAF */   sw        $ra, 0x38($sp)
    /* 1EADC 8002E2DC 0680023C */  lui        $v0, %hi(D_80061B00)
    /* 1EAE0 8002E2E0 001B428C */  lw         $v0, %lo(D_80061B00)($v0)
    /* 1EAE4 8002E2E4 00000000 */  nop
    /* 1EAE8 8002E2E8 17004010 */  beqz       $v0, .L8002E348
    /* 1EAEC 8002E2EC 00000000 */   nop
    /* 1EAF0 8002E2F0 0580023C */  lui        $v0, %hi(D_8004E690)
    /* 1EAF4 8002E2F4 90E6428C */  lw         $v0, %lo(D_8004E690)($v0)
    /* 1EAF8 8002E2F8 00000000 */  nop
    /* 1EAFC 8002E2FC 0000428C */  lw         $v0, 0x0($v0)
    /* 1EB00 8002E300 0001033C */  lui        $v1, (0x1000000 >> 16)
    /* 1EB04 8002E304 24104300 */  and        $v0, $v0, $v1
    /* 1EB08 8002E308 0F004010 */  beqz       $v0, .L8002E348
    /* 1EB0C 8002E30C 00000000 */   nop
    /* 1EB10 8002E310 0680023C */  lui        $v0, %hi(D_80061B28)
    /* 1EB14 8002E314 281B428C */  lw         $v0, %lo(D_80061B28)($v0)
    /* 1EB18 8002E318 0680013C */  lui        $at, %hi(D_80061B04)
    /* 1EB1C 8002E31C 07004010 */  beqz       $v0, .L8002E33C
    /* 1EB20 8002E320 041B24AC */   sw        $a0, %lo(D_80061B04)($at)
    /* 1EB24 8002E324 0680023C */  lui        $v0, %hi(D_80061B18)
    /* 1EB28 8002E328 181B428C */  lw         $v0, %lo(D_80061B18)($v0)
    /* 1EB2C 8002E32C 00000000 */  nop
    /* 1EB30 8002E330 01004224 */  addiu      $v0, $v0, 0x1
    /* 1EB34 8002E334 0680013C */  lui        $at, %hi(D_80061B18)
    /* 1EB38 8002E338 181B22AC */  sw         $v0, %lo(D_80061B18)($at)
  .L8002E33C:
    /* 1EB3C 8002E33C 0580013C */  lui        $at, %hi(D_8004E6B8)
    /* 1EB40 8002E340 F4BA0008 */  j          .L8002EBD0
    /* 1EB44 8002E344 B8E624AC */   sw        $a0, %lo(D_8004E6B8)($at)
  .L8002E348:
    /* 1EB48 8002E348 3DC1000C */  jal        CdReady
    /* 1EB4C 8002E34C 3000A527 */   addiu     $a1, $sp, 0x30
    /* 1EB50 8002E350 05000324 */  addiu      $v1, $zero, 0x5
    /* 1EB54 8002E354 1E024310 */  beq        $v0, $v1, .L8002EBD0
    /* 1EB58 8002E358 00000000 */   nop
    /* 1EB5C 8002E35C 3000A293 */  lbu        $v0, 0x30($sp)
    /* 1EB60 8002E360 3100A393 */  lbu        $v1, 0x31($sp)
    /* 1EB64 8002E364 2200A2A7 */  sh         $v0, 0x22($sp)
    /* 1EB68 8002E368 2400A3A7 */  sh         $v1, 0x24($sp)
    /* 1EB6C 8002E36C 2200A297 */  lhu        $v0, 0x22($sp)
    /* 1EB70 8002E370 00000000 */  nop
    /* 1EB74 8002E374 04004230 */  andi       $v0, $v0, 0x4
    /* 1EB78 8002E378 04004010 */  beqz       $v0, .L8002E38C
    /* 1EB7C 8002E37C 03000224 */   addiu     $v0, $zero, 0x3
    /* 1EB80 8002E380 0580013C */  lui        $at, %hi(D_8004E6B8)
    /* 1EB84 8002E384 F4BA0008 */  j          .L8002EBD0
    /* 1EB88 8002E388 B8E622AC */   sw        $v0, %lo(D_8004E6B8)($at)
  .L8002E38C:
    /* 1EB8C 8002E38C 0680023C */  lui        $v0, %hi(D_80061B1C)
    /* 1EB90 8002E390 1C1B428C */  lw         $v0, %lo(D_80061B1C)($v0)
    /* 1EB94 8002E394 0680033C */  lui        $v1, %hi(D_80061B38)
    /* 1EB98 8002E398 381B638C */  lw         $v1, %lo(D_80061B38)($v1)
    /* 1EB9C 8002E39C 40110200 */  sll        $v0, $v0, 5
    /* 1EBA0 8002E3A0 21186200 */  addu       $v1, $v1, $v0
    /* 1EBA4 8002E3A4 0680013C */  lui        $at, %hi(D_80061B58)
    /* 1EBA8 8002E3A8 581B23AC */  sw         $v1, %lo(D_80061B58)($at)
    /* 1EBAC 8002E3AC 00006294 */  lhu        $v0, 0x0($v1)
    /* 1EBB0 8002E3B0 00000000 */  nop
    /* 1EBB4 8002E3B4 10004010 */  beqz       $v0, .L8002E3F8
    /* 1EBB8 8002E3B8 00000000 */   nop
    /* 1EBBC 8002E3BC 0680023C */  lui        $v0, %hi(D_80061B28)
    /* 1EBC0 8002E3C0 281B428C */  lw         $v0, %lo(D_80061B28)($v0)
    /* 1EBC4 8002E3C4 00000000 */  nop
    /* 1EBC8 8002E3C8 08004010 */  beqz       $v0, .L8002E3EC
    /* 1EBCC 8002E3CC 04000224 */   addiu     $v0, $zero, 0x4
    /* 1EBD0 8002E3D0 0680023C */  lui        $v0, %hi(D_80061B18)
    /* 1EBD4 8002E3D4 181B428C */  lw         $v0, %lo(D_80061B18)($v0)
    /* 1EBD8 8002E3D8 00000000 */  nop
    /* 1EBDC 8002E3DC 01004224 */  addiu      $v0, $v0, 0x1
    /* 1EBE0 8002E3E0 0680013C */  lui        $at, %hi(D_80061B18)
    /* 1EBE4 8002E3E4 181B22AC */  sw         $v0, %lo(D_80061B18)($at)
    /* 1EBE8 8002E3E8 04000224 */  addiu      $v0, $zero, 0x4
  .L8002E3EC:
    /* 1EBEC 8002E3EC 0580013C */  lui        $at, %hi(D_8004E6B8)
    /* 1EBF0 8002E3F0 F4BA0008 */  j          .L8002EBD0
    /* 1EBF4 8002E3F4 B8E622AC */   sw        $v0, %lo(D_8004E6B8)($at)
  .L8002E3F8:
    /* 1EBF8 8002E3F8 0580023C */  lui        $v0, %hi(D_8004E670)
    /* 1EBFC 8002E3FC 70E6428C */  lw         $v0, %lo(D_8004E670)($v0)
    /* 1EC00 8002E400 00000000 */  nop
    /* 1EC04 8002E404 000040A0 */  sb         $zero, 0x0($v0)
    /* 1EC08 8002E408 0580023C */  lui        $v0, %hi(D_8004E67C)
    /* 1EC0C 8002E40C 7CE6428C */  lw         $v0, %lo(D_8004E67C)($v0)
    /* 1EC10 8002E410 00000000 */  nop
    /* 1EC14 8002E414 000040A0 */  sb         $zero, 0x0($v0)
    /* 1EC18 8002E418 0580023C */  lui        $v0, %hi(D_8004E670)
    /* 1EC1C 8002E41C 70E6428C */  lw         $v0, %lo(D_8004E670)($v0)
    /* 1EC20 8002E420 0200043C */  lui        $a0, (0x20943 >> 16)
    /* 1EC24 8002E424 000040A0 */  sb         $zero, 0x0($v0)
    /* 1EC28 8002E428 0580033C */  lui        $v1, %hi(D_8004E67C)
    /* 1EC2C 8002E42C 7CE6638C */  lw         $v1, %lo(D_8004E67C)($v1)
    /* 1EC30 8002E430 80000224 */  addiu      $v0, $zero, 0x80
    /* 1EC34 8002E434 000062A0 */  sb         $v0, 0x0($v1)
    /* 1EC38 8002E438 0580023C */  lui        $v0, %hi(D_8004E680)
    /* 1EC3C 8002E43C 80E6428C */  lw         $v0, %lo(D_8004E680)($v0)
    /* 1EC40 8002E440 43098434 */  ori        $a0, $a0, (0x20943 & 0xFFFF)
    /* 1EC44 8002E444 000044AC */  sw         $a0, 0x0($v0)
    /* 1EC48 8002E448 0580033C */  lui        $v1, %hi(D_8004E684)
    /* 1EC4C 8002E44C 84E6638C */  lw         $v1, %lo(D_8004E684)($v1)
    /* 1EC50 8002E450 23130224 */  addiu      $v0, $zero, 0x1323
    /* 1EC54 8002E454 000062AC */  sw         $v0, 0x0($v1)
    /* 1EC58 8002E458 0680023C */  lui        $v0, %hi(D_80061B98)
    /* 1EC5C 8002E45C 981B428C */  lw         $v0, %lo(D_80061B98)($v0)
    /* 1EC60 8002E460 00000000 */  nop
    /* 1EC64 8002E464 14004014 */  bnez       $v0, .L8002E4B8
    /* 1EC68 8002E468 21200000 */   addu      $a0, $zero, $zero
    /* 1EC6C 8002E46C 2800A527 */  addiu      $a1, $sp, 0x28
  .L8002E470:
    /* 1EC70 8002E470 0580023C */  lui        $v0, %hi(D_8004E678)
    /* 1EC74 8002E474 78E6428C */  lw         $v0, %lo(D_8004E678)($v0)
    /* 1EC78 8002E478 2118A400 */  addu       $v1, $a1, $a0
    /* 1EC7C 8002E47C 00004290 */  lbu        $v0, 0x0($v0)
    /* 1EC80 8002E480 01008424 */  addiu      $a0, $a0, 0x1
    /* 1EC84 8002E484 000062A0 */  sb         $v0, 0x0($v1)
    /* 1EC88 8002E488 0400822C */  sltiu      $v0, $a0, 0x4
    /* 1EC8C 8002E48C F8FF4014 */  bnez       $v0, .L8002E470
    /* 1EC90 8002E490 00000000 */   nop
    /* 1EC94 8002E494 21200000 */  addu       $a0, $zero, $zero
    /* 1EC98 8002E498 0580033C */  lui        $v1, %hi(D_8004E678)
    /* 1EC9C 8002E49C 78E6638C */  lw         $v1, %lo(D_8004E678)($v1)
    /* 1ECA0 8002E4A0 00000000 */  nop
  .L8002E4A4:
    /* 1ECA4 8002E4A4 00006290 */  lbu        $v0, 0x0($v1)
    /* 1ECA8 8002E4A8 01008424 */  addiu      $a0, $a0, 0x1
    /* 1ECAC 8002E4AC 0800822C */  sltiu      $v0, $a0, 0x8
    /* 1ECB0 8002E4B0 FCFF4014 */  bnez       $v0, .L8002E4A4
    /* 1ECB4 8002E4B4 00000000 */   nop
  .L8002E4B8:
    /* 1ECB8 8002E4B8 0680023C */  lui        $v0, %hi(D_80061B28)
    /* 1ECBC 8002E4BC 281B428C */  lw         $v0, %lo(D_80061B28)($v0)
    /* 1ECC0 8002E4C0 00000000 */  nop
    /* 1ECC4 8002E4C4 0C004010 */  beqz       $v0, .L8002E4F8
    /* 1ECC8 8002E4C8 0011083C */   lui       $t0, (0x11000000 >> 16)
    /* 1ECCC 8002E4CC 08000624 */  addiu      $a2, $zero, 0x8
    /* 1ECD0 8002E4D0 21380000 */  addu       $a3, $zero, $zero
    /* 1ECD4 8002E4D4 0680053C */  lui        $a1, %hi(D_80061B18)
    /* 1ECD8 8002E4D8 181BA58C */  lw         $a1, %lo(D_80061B18)($a1)
    /* 1ECDC 8002E4DC 0680043C */  lui        $a0, %hi(D_80061B58)
    /* 1ECE0 8002E4E0 581B848C */  lw         $a0, %lo(D_80061B58)($a0)
    /* 1ECE4 8002E4E4 C02A0500 */  sll        $a1, $a1, 11
    /* 1ECE8 8002E4E8 F8BA000C */  jal        Mem_CopyWords
    /* 1ECEC 8002E4EC 21284500 */   addu      $a1, $v0, $a1
    /* 1ECF0 8002E4F0 47B90008 */  j          .L8002E51C
    /* 1ECF4 8002E4F4 00000000 */   nop
  .L8002E4F8:
    /* 1ECF8 8002E4F8 03000424 */  addiu      $a0, $zero, 0x3
    /* 1ECFC 8002E4FC 21300000 */  addu       $a2, $zero, $zero
    /* 1ED00 8002E500 0680053C */  lui        $a1, %hi(D_80061B58)
    /* 1ED04 8002E504 581BA58C */  lw         $a1, %lo(D_80061B58)($a1)
    /* 1ED08 8002E508 08000724 */  addiu      $a3, $zero, 0x8
    /* 1ED0C 8002E50C 1000A8AF */  sw         $t0, 0x10($sp)
    /* 1ED10 8002E510 1400A0AF */  sw         $zero, 0x14($sp)
    /* 1ED14 8002E514 03BB000C */  jal        func_8002EC0C
    /* 1ED18 8002E518 1800A0AF */   sw        $zero, 0x18($sp)
  .L8002E51C:
    /* 1ED1C 8002E51C 0580043C */  lui        $a0, %hi(D_8004E6A0)
    /* 1ED20 8002E520 A0E6848C */  lw         $a0, %lo(D_8004E6A0)($a0)
    /* 1ED24 8002E524 00000000 */  nop
    /* 1ED28 8002E528 0000828C */  lw         $v0, 0x0($a0)
    /* 1ED2C 8002E52C 0001033C */  lui        $v1, (0x1000000 >> 16)
    /* 1ED30 8002E530 24104300 */  and        $v0, $v0, $v1
    /* 1ED34 8002E534 07004010 */  beqz       $v0, .L8002E554
    /* 1ED38 8002E538 21188000 */   addu      $v1, $a0, $zero
    /* 1ED3C 8002E53C 0001043C */  lui        $a0, (0x1000000 >> 16)
  .L8002E540:
    /* 1ED40 8002E540 0000628C */  lw         $v0, 0x0($v1)
    /* 1ED44 8002E544 00000000 */  nop
    /* 1ED48 8002E548 24104400 */  and        $v0, $v0, $a0
    /* 1ED4C 8002E54C FCFF4014 */  bnez       $v0, .L8002E540
    /* 1ED50 8002E550 00000000 */   nop
  .L8002E554:
    /* 1ED54 8002E554 0200043C */  lui        $a0, (0x20843 >> 16)
    /* 1ED58 8002E558 43088434 */  ori        $a0, $a0, (0x20843 & 0xFFFF)
    /* 1ED5C 8002E55C 0680023C */  lui        $v0, %hi(D_80061B58)
    /* 1ED60 8002E560 581B428C */  lw         $v0, %lo(D_80061B58)($v0)
    /* 1ED64 8002E564 0580033C */  lui        $v1, %hi(D_8004E680)
    /* 1ED68 8002E568 80E6638C */  lw         $v1, %lo(D_8004E680)($v1)
    /* 1ED6C 8002E56C 2B00A58B */  lwl        $a1, 0x2B($sp)
    /* 1ED70 8002E570 2800A59B */  lwr        $a1, 0x28($sp)
    /* 1ED74 8002E574 00000000 */  nop
    /* 1ED78 8002E578 1F0045A8 */  swl        $a1, 0x1F($v0)
    /* 1ED7C 8002E57C 1C0045B8 */  swr        $a1, 0x1C($v0)
    /* 1ED80 8002E580 000064AC */  sw         $a0, 0x0($v1)
    /* 1ED84 8002E584 0580033C */  lui        $v1, %hi(D_8004E684)
    /* 1ED88 8002E588 84E6638C */  lw         $v1, %lo(D_8004E684)($v1)
    /* 1ED8C 8002E58C 25130224 */  addiu      $v0, $zero, 0x1325
    /* 1ED90 8002E590 000062AC */  sw         $v0, 0x0($v1)
    /* 1ED94 8002E594 0680033C */  lui        $v1, %hi(D_80061B30)
    /* 1ED98 8002E598 301B638C */  lw         $v1, %lo(D_80061B30)($v1)
    /* 1ED9C 8002E59C 01000224 */  addiu      $v0, $zero, 0x1
    /* 1EDA0 8002E5A0 1C006214 */  bne        $v1, $v0, .L8002E614
    /* 1EDA4 8002E5A4 00000000 */   nop
    /* 1EDA8 8002E5A8 0680043C */  lui        $a0, %hi(D_80061B0C)
    /* 1EDAC 8002E5AC 0C1B848C */  lw         $a0, %lo(D_80061B0C)($a0)
    /* 1EDB0 8002E5B0 00000000 */  nop
    /* 1EDB4 8002E5B4 17008010 */  beqz       $a0, .L8002E614
    /* 1EDB8 8002E5B8 00000000 */   nop
    /* 1EDBC 8002E5BC 0680033C */  lui        $v1, %hi(D_80061B58)
    /* 1EDC0 8002E5C0 581B638C */  lw         $v1, %lo(D_80061B58)($v1)
    /* 1EDC4 8002E5C4 00000000 */  nop
    /* 1EDC8 8002E5C8 08006294 */  lhu        $v0, 0x8($v1)
    /* 1EDCC 8002E5CC 00000000 */  nop
    /* 1EDD0 8002E5D0 0E008210 */  beq        $a0, $v0, .L8002E60C
    /* 1EDD4 8002E5D4 00000000 */   nop
    /* 1EDD8 8002E5D8 000060A4 */  sh         $zero, 0x0($v1)
    /* 1EDDC 8002E5DC 0680023C */  lui        $v0, %hi(D_80061B28)
    /* 1EDE0 8002E5E0 281B428C */  lw         $v0, %lo(D_80061B28)($v0)
    /* 1EDE4 8002E5E4 00000000 */  nop
    /* 1EDE8 8002E5E8 79014010 */  beqz       $v0, .L8002EBD0
    /* 1EDEC 8002E5EC 00000000 */   nop
    /* 1EDF0 8002E5F0 0680023C */  lui        $v0, %hi(D_80061B18)
    /* 1EDF4 8002E5F4 181B428C */  lw         $v0, %lo(D_80061B18)($v0)
    /* 1EDF8 8002E5F8 00000000 */  nop
    /* 1EDFC 8002E5FC 01004224 */  addiu      $v0, $v0, 0x1
    /* 1EE00 8002E600 0680013C */  lui        $at, %hi(D_80061B18)
    /* 1EE04 8002E604 F4BA0008 */  j          .L8002EBD0
    /* 1EE08 8002E608 181B22AC */   sw        $v0, %lo(D_80061B18)($at)
  .L8002E60C:
    /* 1EE0C 8002E60C 0680013C */  lui        $at, %hi(D_80061B30)
    /* 1EE10 8002E610 301B20AC */  sw         $zero, %lo(D_80061B30)($at)
  .L8002E614:
    /* 1EE14 8002E614 0680043C */  lui        $a0, %hi(D_80061B58)
    /* 1EE18 8002E618 581B848C */  lw         $a0, %lo(D_80061B58)($a0)
    /* 1EE1C 8002E61C 00000000 */  nop
    /* 1EE20 8002E620 00008394 */  lhu        $v1, 0x0($a0)
    /* 1EE24 8002E624 60010224 */  addiu      $v0, $zero, 0x160
    /* 1EE28 8002E628 08006214 */  bne        $v1, $v0, .L8002E64C
    /* 1EE2C 8002E62C 00000000 */   nop
    /* 1EE30 8002E630 02008294 */  lhu        $v0, 0x2($a0)
    /* 1EE34 8002E634 0680033C */  lui        $v1, %hi(D_80061B10)
    /* 1EE38 8002E638 101B638C */  lw         $v1, %lo(D_80061B10)($v1)
    /* 1EE3C 8002E63C 82120200 */  srl        $v0, $v0, 10
    /* 1EE40 8002E640 1F004230 */  andi       $v0, $v0, 0x1F
    /* 1EE44 8002E644 11004310 */  beq        $v0, $v1, .L8002E68C
    /* 1EE48 8002E648 00000000 */   nop
  .L8002E64C:
    /* 1EE4C 8002E64C 0680023C */  lui        $v0, %hi(D_80061B28)
    /* 1EE50 8002E650 281B428C */  lw         $v0, %lo(D_80061B28)($v0)
    /* 1EE54 8002E654 00000000 */  nop
    /* 1EE58 8002E658 04004010 */  beqz       $v0, .L8002E66C
    /* 1EE5C 8002E65C 00000000 */   nop
    /* 1EE60 8002E660 0680013C */  lui        $at, %hi(D_80061B18)
    /* 1EE64 8002E664 9CB90008 */  j          .L8002E670
    /* 1EE68 8002E668 181B20AC */   sw        $zero, %lo(D_80061B18)($at)
  .L8002E66C:
    /* 1EE6C 8002E66C 00008294 */  lhu        $v0, 0x0($a0)
  .L8002E670:
    /* 1EE70 8002E670 0680033C */  lui        $v1, %hi(D_80061B58)
    /* 1EE74 8002E674 581B638C */  lw         $v1, %lo(D_80061B58)($v1)
    /* 1EE78 8002E678 05000224 */  addiu      $v0, $zero, 0x5
    /* 1EE7C 8002E67C 0580013C */  lui        $at, %hi(D_8004E6B8)
    /* 1EE80 8002E680 B8E622AC */  sw         $v0, %lo(D_8004E6B8)($at)
    /* 1EE84 8002E684 F4BA0008 */  j          .L8002EBD0
    /* 1EE88 8002E688 000060A4 */   sh        $zero, 0x0($v1)
  .L8002E68C:
    /* 1EE8C 8002E68C 0680033C */  lui        $v1, %hi(D_80061AFC)
    /* 1EE90 8002E690 FC1A6384 */  lh         $v1, %lo(D_80061AFC)($v1)
    /* 1EE94 8002E694 04008294 */  lhu        $v0, 0x4($a0)
    /* 1EE98 8002E698 00000000 */  nop
    /* 1EE9C 8002E69C 0A006214 */  bne        $v1, $v0, .L8002E6C8
    /* 1EEA0 8002E6A0 00000000 */   nop
    /* 1EEA4 8002E6A4 0680033C */  lui        $v1, %hi(D_80061AF8)
    /* 1EEA8 8002E6A8 F81A638C */  lw         $v1, %lo(D_80061AF8)($v1)
    /* 1EEAC 8002E6AC 00000000 */  nop
    /* 1EEB0 8002E6B0 25006010 */  beqz       $v1, .L8002E748
    /* 1EEB4 8002E6B4 00000000 */   nop
    /* 1EEB8 8002E6B8 08008294 */  lhu        $v0, 0x8($a0)
    /* 1EEBC 8002E6BC 00000000 */  nop
    /* 1EEC0 8002E6C0 21006210 */  beq        $v1, $v0, .L8002E748
    /* 1EEC4 8002E6C4 00000000 */   nop
  .L8002E6C8:
    /* 1EEC8 8002E6C8 0680043C */  lui        $a0, %hi(D_80061B20)
    /* 1EECC 8002E6CC 201B848C */  lw         $a0, %lo(D_80061B20)($a0)
    /* 1EED0 8002E6D0 0680053C */  lui        $a1, %hi(D_80061B1C)
    /* 1EED4 8002E6D4 1C1BA58C */  lw         $a1, %lo(D_80061B1C)($a1)
    /* 1EED8 8002E6D8 0680013C */  lui        $at, %hi(D_80061AF8)
    /* 1EEDC 8002E6DC F81A20AC */  sw         $zero, %lo(D_80061AF8)($at)
    /* 1EEE0 8002E6E0 0680013C */  lui        $at, %hi(D_80061AFC)
    /* 1EEE4 8002E6E4 FC1A20A4 */  sh         $zero, %lo(D_80061AFC)($at)
    /* 1EEE8 8002E6E8 69B8000C */  jal        Cd_ClearStreamSlots
    /* 1EEEC 8002E6EC 2328A400 */   subu      $a1, $a1, $a0
    /* 1EEF0 8002E6F0 0680023C */  lui        $v0, %hi(D_80061B20)
    /* 1EEF4 8002E6F4 201B428C */  lw         $v0, %lo(D_80061B20)($v0)
    /* 1EEF8 8002E6F8 0680033C */  lui        $v1, %hi(D_80061B58)
    /* 1EEFC 8002E6FC 581B638C */  lw         $v1, %lo(D_80061B58)($v1)
    /* 1EF00 8002E700 0680013C */  lui        $at, %hi(D_80061B1C)
    /* 1EF04 8002E704 1C1B22AC */  sw         $v0, %lo(D_80061B1C)($at)
    /* 1EF08 8002E708 000060A4 */  sh         $zero, 0x0($v1)
    /* 1EF0C 8002E70C 0680023C */  lui        $v0, %hi(D_80061B28)
    /* 1EF10 8002E710 281B428C */  lw         $v0, %lo(D_80061B28)($v0)
    /* 1EF14 8002E714 00000000 */  nop
    /* 1EF18 8002E718 08004010 */  beqz       $v0, .L8002E73C
    /* 1EF1C 8002E71C 06000224 */   addiu     $v0, $zero, 0x6
    /* 1EF20 8002E720 0680023C */  lui        $v0, %hi(D_80061B18)
    /* 1EF24 8002E724 181B428C */  lw         $v0, %lo(D_80061B18)($v0)
    /* 1EF28 8002E728 00000000 */  nop
    /* 1EF2C 8002E72C 01004224 */  addiu      $v0, $v0, 0x1
    /* 1EF30 8002E730 0680013C */  lui        $at, %hi(D_80061B18)
    /* 1EF34 8002E734 181B22AC */  sw         $v0, %lo(D_80061B18)($at)
    /* 1EF38 8002E738 06000224 */  addiu      $v0, $zero, 0x6
  .L8002E73C:
    /* 1EF3C 8002E73C 0580013C */  lui        $at, %hi(D_8004E6B8)
    /* 1EF40 8002E740 F4BA0008 */  j          .L8002EBD0
    /* 1EF44 8002E744 B8E622AC */   sw        $v0, %lo(D_8004E6B8)($at)
  .L8002E748:
    /* 1EF48 8002E748 0680033C */  lui        $v1, %hi(D_80061B58)
    /* 1EF4C 8002E74C 581B638C */  lw         $v1, %lo(D_80061B58)($v1)
    /* 1EF50 8002E750 00000000 */  nop
    /* 1EF54 8002E754 04006294 */  lhu        $v0, 0x4($v1)
    /* 1EF58 8002E758 00000000 */  nop
    /* 1EF5C 8002E75C 8D004014 */  bnez       $v0, .L8002E994
    /* 1EF60 8002E760 0A000224 */   addiu     $v0, $zero, 0xA
    /* 1EF64 8002E764 08006294 */  lhu        $v0, 0x8($v1)
    /* 1EF68 8002E768 0680033C */  lui        $v1, %hi(D_80061B2C)
    /* 1EF6C 8002E76C 2C1B638C */  lw         $v1, %lo(D_80061B2C)($v1)
    /* 1EF70 8002E770 0680013C */  lui        $at, %hi(D_80061AFC)
    /* 1EF74 8002E774 FC1A20A4 */  sh         $zero, %lo(D_80061AFC)($at)
    /* 1EF78 8002E778 FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* 1EF7C 8002E77C 0680013C */  lui        $at, %hi(D_80061AF8)
    /* 1EF80 8002E780 F81A22AC */  sw         $v0, %lo(D_80061AF8)($at)
    /* 1EF84 8002E784 2B006010 */  beqz       $v1, .L8002E834
    /* 1EF88 8002E788 2B104300 */   sltu      $v0, $v0, $v1
    /* 1EF8C 8002E78C 29004014 */  bnez       $v0, .L8002E834
    /* 1EF90 8002E790 00000000 */   nop
    /* 1EF94 8002E794 0680043C */  lui        $a0, %hi(D_80061B20)
    /* 1EF98 8002E798 201B848C */  lw         $a0, %lo(D_80061B20)($a0)
    /* 1EF9C 8002E79C 0680053C */  lui        $a1, %hi(D_80061B1C)
    /* 1EFA0 8002E7A0 1C1BA58C */  lw         $a1, %lo(D_80061B1C)($a1)
    /* 1EFA4 8002E7A4 0680013C */  lui        $at, %hi(D_80061AF8)
    /* 1EFA8 8002E7A8 F81A20AC */  sw         $zero, %lo(D_80061AF8)($at)
    /* 1EFAC 8002E7AC 0680013C */  lui        $at, %hi(D_80061AFC)
    /* 1EFB0 8002E7B0 FC1A20A4 */  sh         $zero, %lo(D_80061AFC)($at)
    /* 1EFB4 8002E7B4 69B8000C */  jal        Cd_ClearStreamSlots
    /* 1EFB8 8002E7B8 2328A400 */   subu      $a1, $a1, $a0
    /* 1EFBC 8002E7BC 0680023C */  lui        $v0, %hi(D_80061B20)
    /* 1EFC0 8002E7C0 201B428C */  lw         $v0, %lo(D_80061B20)($v0)
    /* 1EFC4 8002E7C4 0680033C */  lui        $v1, %hi(D_80061B58)
    /* 1EFC8 8002E7C8 581B638C */  lw         $v1, %lo(D_80061B58)($v1)
    /* 1EFCC 8002E7CC 0680013C */  lui        $at, %hi(D_80061B1C)
    /* 1EFD0 8002E7D0 1C1B22AC */  sw         $v0, %lo(D_80061B1C)($at)
    /* 1EFD4 8002E7D4 000060A4 */  sh         $zero, 0x0($v1)
    /* 1EFD8 8002E7D8 0680033C */  lui        $v1, %hi(D_80061B54)
    /* 1EFDC 8002E7DC 541B638C */  lw         $v1, %lo(D_80061B54)($v1)
    /* 1EFE0 8002E7E0 01000224 */  addiu      $v0, $zero, 0x1
    /* 1EFE4 8002E7E4 0680013C */  lui        $at, %hi(D_80061B30)
    /* 1EFE8 8002E7E8 03006010 */  beqz       $v1, .L8002E7F8
    /* 1EFEC 8002E7EC 301B22AC */   sw        $v0, %lo(D_80061B30)($at)
    /* 1EFF0 8002E7F0 09F86000 */  jalr       $v1
    /* 1EFF4 8002E7F4 00000000 */   nop
  .L8002E7F8:
    /* 1EFF8 8002E7F8 0680023C */  lui        $v0, %hi(D_80061B28)
    /* 1EFFC 8002E7FC 281B428C */  lw         $v0, %lo(D_80061B28)($v0)
    /* 1F000 8002E800 00000000 */  nop
    /* 1F004 8002E804 08004010 */  beqz       $v0, .L8002E828
    /* 1F008 8002E808 07000224 */   addiu     $v0, $zero, 0x7
    /* 1F00C 8002E80C 0680023C */  lui        $v0, %hi(D_80061B18)
    /* 1F010 8002E810 181B428C */  lw         $v0, %lo(D_80061B18)($v0)
    /* 1F014 8002E814 00000000 */  nop
    /* 1F018 8002E818 01004224 */  addiu      $v0, $v0, 0x1
    /* 1F01C 8002E81C 0680013C */  lui        $at, %hi(D_80061B18)
    /* 1F020 8002E820 181B22AC */  sw         $v0, %lo(D_80061B18)($at)
    /* 1F024 8002E824 07000224 */  addiu      $v0, $zero, 0x7
  .L8002E828:
    /* 1F028 8002E828 0580013C */  lui        $at, %hi(D_8004E6B8)
    /* 1F02C 8002E82C F4BA0008 */  j          .L8002EBD0
    /* 1F030 8002E830 B8E622AC */   sw        $v0, %lo(D_8004E6B8)($at)
  .L8002E834:
    /* 1F034 8002E834 0680023C */  lui        $v0, %hi(D_80061B3C)
    /* 1F038 8002E838 3C1B428C */  lw         $v0, %lo(D_80061B3C)($v0)
    /* 1F03C 8002E83C 0680033C */  lui        $v1, %hi(D_80061B1C)
    /* 1F040 8002E840 1C1B638C */  lw         $v1, %lo(D_80061B1C)($v1)
    /* 1F044 8002E844 0680043C */  lui        $a0, %hi(D_80061B58)
    /* 1F048 8002E848 581B848C */  lw         $a0, %lo(D_80061B58)($a0)
    /* 1F04C 8002E84C 23104300 */  subu       $v0, $v0, $v1
    /* 1F050 8002E850 06008394 */  lhu        $v1, 0x6($a0)
    /* 1F054 8002E854 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 1F058 8002E858 2B104300 */  sltu       $v0, $v0, $v1
    /* 1F05C 8002E85C 48004010 */  beqz       $v0, .L8002E980
    /* 1F060 8002E860 00000000 */   nop
    /* 1F064 8002E864 0680023C */  lui        $v0, %hi(D_80061B2C)
    /* 1F068 8002E868 2C1B428C */  lw         $v0, %lo(D_80061B2C)($v0)
    /* 1F06C 8002E86C 00000000 */  nop
    /* 1F070 8002E870 19004014 */  bnez       $v0, .L8002E8D8
    /* 1F074 8002E874 01000224 */   addiu     $v0, $zero, 0x1
    /* 1F078 8002E878 000082A4 */  sh         $v0, 0x0($a0)
    /* 1F07C 8002E87C 0680033C */  lui        $v1, %hi(D_80061B54)
    /* 1F080 8002E880 541B638C */  lw         $v1, %lo(D_80061B54)($v1)
    /* 1F084 8002E884 01000224 */  addiu      $v0, $zero, 0x1
    /* 1F088 8002E888 0680013C */  lui        $at, %hi(D_80061B30)
    /* 1F08C 8002E88C 03006010 */  beqz       $v1, .L8002E89C
    /* 1F090 8002E890 301B22AC */   sw        $v0, %lo(D_80061B30)($at)
    /* 1F094 8002E894 09F86000 */  jalr       $v1
    /* 1F098 8002E898 00000000 */   nop
  .L8002E89C:
    /* 1F09C 8002E89C 0680023C */  lui        $v0, %hi(D_80061B28)
    /* 1F0A0 8002E8A0 281B428C */  lw         $v0, %lo(D_80061B28)($v0)
    /* 1F0A4 8002E8A4 00000000 */  nop
    /* 1F0A8 8002E8A8 08004010 */  beqz       $v0, .L8002E8CC
    /* 1F0AC 8002E8AC 08000224 */   addiu     $v0, $zero, 0x8
    /* 1F0B0 8002E8B0 0680023C */  lui        $v0, %hi(D_80061B18)
    /* 1F0B4 8002E8B4 181B428C */  lw         $v0, %lo(D_80061B18)($v0)
    /* 1F0B8 8002E8B8 00000000 */  nop
    /* 1F0BC 8002E8BC 01004224 */  addiu      $v0, $v0, 0x1
    /* 1F0C0 8002E8C0 0680013C */  lui        $at, %hi(D_80061B18)
    /* 1F0C4 8002E8C4 181B22AC */  sw         $v0, %lo(D_80061B18)($at)
    /* 1F0C8 8002E8C8 08000224 */  addiu      $v0, $zero, 0x8
  .L8002E8CC:
    /* 1F0CC 8002E8CC 0580013C */  lui        $at, %hi(D_8004E6B8)
    /* 1F0D0 8002E8D0 F4BA0008 */  j          .L8002EBD0
    /* 1F0D4 8002E8D4 B8E622AC */   sw        $v0, %lo(D_8004E6B8)($at)
  .L8002E8D8:
    /* 1F0D8 8002E8D8 0680023C */  lui        $v0, %hi(D_80061B38)
    /* 1F0DC 8002E8DC 381B428C */  lw         $v0, %lo(D_80061B38)($v0)
    /* 1F0E0 8002E8E0 00000000 */  nop
    /* 1F0E4 8002E8E4 00004284 */  lh         $v0, 0x0($v0)
    /* 1F0E8 8002E8E8 00000000 */  nop
    /* 1F0EC 8002E8EC 11004010 */  beqz       $v0, .L8002E934
    /* 1F0F0 8002E8F0 01000224 */   addiu     $v0, $zero, 0x1
    /* 1F0F4 8002E8F4 000080A4 */  sh         $zero, 0x0($a0)
    /* 1F0F8 8002E8F8 0680023C */  lui        $v0, %hi(D_80061B28)
    /* 1F0FC 8002E8FC 281B428C */  lw         $v0, %lo(D_80061B28)($v0)
    /* 1F100 8002E900 00000000 */  nop
    /* 1F104 8002E904 08004010 */  beqz       $v0, .L8002E928
    /* 1F108 8002E908 09000224 */   addiu     $v0, $zero, 0x9
    /* 1F10C 8002E90C 0680023C */  lui        $v0, %hi(D_80061B18)
    /* 1F110 8002E910 181B428C */  lw         $v0, %lo(D_80061B18)($v0)
    /* 1F114 8002E914 00000000 */  nop
    /* 1F118 8002E918 01004224 */  addiu      $v0, $v0, 0x1
    /* 1F11C 8002E91C 0680013C */  lui        $at, %hi(D_80061B18)
    /* 1F120 8002E920 181B22AC */  sw         $v0, %lo(D_80061B18)($at)
    /* 1F124 8002E924 09000224 */  addiu      $v0, $zero, 0x9
  .L8002E928:
    /* 1F128 8002E928 0580013C */  lui        $at, %hi(D_8004E6B8)
    /* 1F12C 8002E92C F4BA0008 */  j          .L8002EBD0
    /* 1F130 8002E930 B8E622AC */   sw        $v0, %lo(D_8004E6B8)($at)
  .L8002E934:
    /* 1F134 8002E934 000082A4 */  sh         $v0, 0x0($a0)
    /* 1F138 8002E938 0680053C */  lui        $a1, %hi(D_80061B38)
    /* 1F13C 8002E93C 381BA58C */  lw         $a1, %lo(D_80061B38)($a1)
    /* 1F140 8002E940 0680033C */  lui        $v1, %hi(D_80061B58)
    /* 1F144 8002E944 581B638C */  lw         $v1, %lo(D_80061B58)($v1)
    /* 1F148 8002E948 21200000 */  addu       $a0, $zero, $zero
    /* 1F14C 8002E94C 0680013C */  lui        $at, %hi(D_80061B1C)
    /* 1F150 8002E950 1C1B20AC */  sw         $zero, %lo(D_80061B1C)($at)
  .L8002E954:
    /* 1F154 8002E954 0000628C */  lw         $v0, 0x0($v1)
    /* 1F158 8002E958 04006324 */  addiu      $v1, $v1, 0x4
    /* 1F15C 8002E95C 01008424 */  addiu      $a0, $a0, 0x1
    /* 1F160 8002E960 0000A2AC */  sw         $v0, 0x0($a1)
    /* 1F164 8002E964 0800822C */  sltiu      $v0, $a0, 0x8
    /* 1F168 8002E968 FAFF4014 */  bnez       $v0, .L8002E954
    /* 1F16C 8002E96C 0400A524 */   addiu     $a1, $a1, 0x4
    /* 1F170 8002E970 0680023C */  lui        $v0, %hi(D_80061B38)
    /* 1F174 8002E974 381B428C */  lw         $v0, %lo(D_80061B38)($v0)
    /* 1F178 8002E978 0680013C */  lui        $at, %hi(D_80061B58)
    /* 1F17C 8002E97C 581B22AC */  sw         $v0, %lo(D_80061B58)($at)
  .L8002E980:
    /* 1F180 8002E980 0680023C */  lui        $v0, %hi(D_80061B1C)
    /* 1F184 8002E984 1C1B428C */  lw         $v0, %lo(D_80061B1C)($v0)
    /* 1F188 8002E988 0680013C */  lui        $at, %hi(D_80061B20)
    /* 1F18C 8002E98C 201B22AC */  sw         $v0, %lo(D_80061B20)($at)
    /* 1F190 8002E990 0A000224 */  addiu      $v0, $zero, 0xA
  .L8002E994:
    /* 1F194 8002E994 0580013C */  lui        $at, %hi(D_8004E6B8)
    /* 1F198 8002E998 B8E622AC */  sw         $v0, %lo(D_8004E6B8)($at)
    /* 1F19C 8002E99C 0680023C */  lui        $v0, %hi(D_80061AFC)
    /* 1F1A0 8002E9A0 FC1A4294 */  lhu        $v0, %lo(D_80061AFC)($v0)
    /* 1F1A4 8002E9A4 0680043C */  lui        $a0, %hi(D_80061B3C)
    /* 1F1A8 8002E9A8 3C1B848C */  lw         $a0, %lo(D_80061B3C)($a0)
    /* 1F1AC 8002E9AC 0680033C */  lui        $v1, %hi(D_80061B38)
    /* 1F1B0 8002E9B0 381B638C */  lw         $v1, %lo(D_80061B38)($v1)
    /* 1F1B4 8002E9B4 0680053C */  lui        $a1, %hi(D_80061B1C)
    /* 1F1B8 8002E9B8 1C1BA58C */  lw         $a1, %lo(D_80061B1C)($a1)
    /* 1F1BC 8002E9BC 01004224 */  addiu      $v0, $v0, 0x1
    /* 1F1C0 8002E9C0 40210400 */  sll        $a0, $a0, 5
    /* 1F1C4 8002E9C4 21186400 */  addu       $v1, $v1, $a0
    /* 1F1C8 8002E9C8 0680013C */  lui        $at, %hi(D_80061AFC)
    /* 1F1CC 8002E9CC FC1A22A4 */  sh         $v0, %lo(D_80061AFC)($at)
    /* 1F1D0 8002E9D0 80110500 */  sll        $v0, $a1, 6
    /* 1F1D4 8002E9D4 23104500 */  subu       $v0, $v0, $a1
    /* 1F1D8 8002E9D8 40110200 */  sll        $v0, $v0, 5
    /* 1F1DC 8002E9DC 0680043C */  lui        $a0, %hi(D_80061B00)
    /* 1F1E0 8002E9E0 001B848C */  lw         $a0, %lo(D_80061B00)($a0)
    /* 1F1E4 8002E9E4 21186200 */  addu       $v1, $v1, $v0
    /* 1F1E8 8002E9E8 0680013C */  lui        $at, %hi(D_80061B34)
    /* 1F1EC 8002E9EC 341B23AC */  sw         $v1, %lo(D_80061B34)($at)
    /* 1F1F0 8002E9F0 0B008010 */  beqz       $a0, .L8002EA20
    /* 1F1F4 8002E9F4 0011083C */   lui       $t0, (0x11000000 >> 16)
    /* 1F1F8 8002E9F8 0200033C */  lui        $v1, (0x20943 >> 16)
    /* 1F1FC 8002E9FC 0580023C */  lui        $v0, %hi(D_8004E680)
    /* 1F200 8002EA00 80E6428C */  lw         $v0, %lo(D_8004E680)($v0)
    /* 1F204 8002EA04 43096334 */  ori        $v1, $v1, (0x20943 & 0xFFFF)
    /* 1F208 8002EA08 000043AC */  sw         $v1, 0x0($v0)
    /* 1F20C 8002EA0C 0580033C */  lui        $v1, %hi(D_8004E684)
    /* 1F210 8002EA10 84E6638C */  lw         $v1, %lo(D_8004E684)($v1)
    /* 1F214 8002EA14 23130224 */  addiu      $v0, $zero, 0x1323
    /* 1F218 8002EA18 8FBA0008 */  j          .L8002EA3C
    /* 1F21C 8002EA1C 000062AC */   sw        $v0, 0x0($v1)
  .L8002EA20:
    /* 1F220 8002EA20 0221033C */  lui        $v1, (0x21020843 >> 16)
    /* 1F224 8002EA24 43086334 */  ori        $v1, $v1, (0x21020843 & 0xFFFF)
    /* 1F228 8002EA28 4011083C */  lui        $t0, (0x11400100 >> 16)
    /* 1F22C 8002EA2C 0580023C */  lui        $v0, %hi(D_8004E680)
    /* 1F230 8002EA30 80E6428C */  lw         $v0, %lo(D_8004E680)($v0)
    /* 1F234 8002EA34 00010835 */  ori        $t0, $t0, (0x11400100 & 0xFFFF)
    /* 1F238 8002EA38 000043AC */  sw         $v1, 0x0($v0)
  .L8002EA3C:
    /* 1F23C 8002EA3C 0680023C */  lui        $v0, %hi(D_80061B58)
    /* 1F240 8002EA40 581B428C */  lw         $v0, %lo(D_80061B58)($v0)
    /* 1F244 8002EA44 00000000 */  nop
    /* 1F248 8002EA48 06004394 */  lhu        $v1, 0x6($v0)
    /* 1F24C 8002EA4C 04004294 */  lhu        $v0, 0x4($v0)
    /* 1F250 8002EA50 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 1F254 8002EA54 29006214 */  bne        $v1, $v0, .L8002EAFC
    /* 1F258 8002EA58 01000324 */   addiu     $v1, $zero, 0x1
    /* 1F25C 8002EA5C 0680023C */  lui        $v0, %hi(D_80061B28)
    /* 1F260 8002EA60 281B428C */  lw         $v0, %lo(D_80061B28)($v0)
    /* 1F264 8002EA64 0680013C */  lui        $at, %hi(D_80061B14)
    /* 1F268 8002EA68 141B23AC */  sw         $v1, %lo(D_80061B14)($at)
    /* 1F26C 8002EA6C 11004010 */  beqz       $v0, .L8002EAB4
    /* 1F270 8002EA70 F8010624 */   addiu     $a2, $zero, 0x1F8
    /* 1F274 8002EA74 01000724 */  addiu      $a3, $zero, 0x1
    /* 1F278 8002EA78 0680053C */  lui        $a1, %hi(D_80061B18)
    /* 1F27C 8002EA7C 181BA58C */  lw         $a1, %lo(D_80061B18)($a1)
    /* 1F280 8002EA80 0680043C */  lui        $a0, %hi(D_80061B34)
    /* 1F284 8002EA84 341B848C */  lw         $a0, %lo(D_80061B34)($a0)
    /* 1F288 8002EA88 C02A0500 */  sll        $a1, $a1, 11
    /* 1F28C 8002EA8C 21284500 */  addu       $a1, $v0, $a1
    /* 1F290 8002EA90 F8BA000C */  jal        Mem_CopyWords
    /* 1F294 8002EA94 2000A524 */   addiu     $a1, $a1, 0x20
    /* 1F298 8002EA98 0680023C */  lui        $v0, %hi(D_80061B18)
    /* 1F29C 8002EA9C 181B428C */  lw         $v0, %lo(D_80061B18)($v0)
    /* 1F2A0 8002EAA0 00000000 */  nop
    /* 1F2A4 8002EAA4 01004224 */  addiu      $v0, $v0, 0x1
    /* 1F2A8 8002EAA8 0680013C */  lui        $at, %hi(D_80061B18)
    /* 1F2AC 8002EAAC B6BA0008 */  j          .L8002EAD8
    /* 1F2B0 8002EAB0 181B22AC */   sw        $v0, %lo(D_80061B18)($at)
  .L8002EAB4:
    /* 1F2B4 8002EAB4 03000424 */  addiu      $a0, $zero, 0x3
    /* 1F2B8 8002EAB8 21300000 */  addu       $a2, $zero, $zero
    /* 1F2BC 8002EABC 0680053C */  lui        $a1, %hi(D_80061B34)
    /* 1F2C0 8002EAC0 341BA58C */  lw         $a1, %lo(D_80061B34)($a1)
    /* 1F2C4 8002EAC4 F8010724 */  addiu      $a3, $zero, 0x1F8
    /* 1F2C8 8002EAC8 1000A8AF */  sw         $t0, 0x10($sp)
    /* 1F2CC 8002EACC 1400A3AF */  sw         $v1, 0x14($sp)
    /* 1F2D0 8002EAD0 03BB000C */  jal        func_8002EC0C
    /* 1F2D4 8002EAD4 1800A0AF */   sw        $zero, 0x18($sp)
  .L8002EAD8:
    /* 1F2D8 8002EAD8 0680023C */  lui        $v0, %hi(D_80061B08)
    /* 1F2DC 8002EADC 081B428C */  lw         $v0, %lo(D_80061B08)($v0)
    /* 1F2E0 8002EAE0 0680013C */  lui        $at, %hi(D_80061AFC)
    /* 1F2E4 8002EAE4 FC1A20A4 */  sh         $zero, %lo(D_80061AFC)($at)
    /* 1F2E8 8002EAE8 0680013C */  lui        $at, %hi(D_80061AF8)
    /* 1F2EC 8002EAEC F81A20AC */  sw         $zero, %lo(D_80061AF8)($at)
    /* 1F2F0 8002EAF0 0680013C */  lui        $at, %hi(D_80061B10)
    /* 1F2F4 8002EAF4 DDBA0008 */  j          .L8002EB74
    /* 1F2F8 8002EAF8 101B22AC */   sw        $v0, %lo(D_80061B10)($at)
  .L8002EAFC:
    /* 1F2FC 8002EAFC 0680023C */  lui        $v0, %hi(D_80061B28)
    /* 1F300 8002EB00 281B428C */  lw         $v0, %lo(D_80061B28)($v0)
    /* 1F304 8002EB04 00000000 */  nop
    /* 1F308 8002EB08 11004010 */  beqz       $v0, .L8002EB50
    /* 1F30C 8002EB0C F8010624 */   addiu     $a2, $zero, 0x1F8
    /* 1F310 8002EB10 21380000 */  addu       $a3, $zero, $zero
    /* 1F314 8002EB14 0680053C */  lui        $a1, %hi(D_80061B18)
    /* 1F318 8002EB18 181BA58C */  lw         $a1, %lo(D_80061B18)($a1)
    /* 1F31C 8002EB1C 0680043C */  lui        $a0, %hi(D_80061B34)
    /* 1F320 8002EB20 341B848C */  lw         $a0, %lo(D_80061B34)($a0)
    /* 1F324 8002EB24 C02A0500 */  sll        $a1, $a1, 11
    /* 1F328 8002EB28 21284500 */  addu       $a1, $v0, $a1
    /* 1F32C 8002EB2C F8BA000C */  jal        Mem_CopyWords
    /* 1F330 8002EB30 2000A524 */   addiu     $a1, $a1, 0x20
    /* 1F334 8002EB34 0680023C */  lui        $v0, %hi(D_80061B18)
    /* 1F338 8002EB38 181B428C */  lw         $v0, %lo(D_80061B18)($v0)
    /* 1F33C 8002EB3C 00000000 */  nop
    /* 1F340 8002EB40 01004224 */  addiu      $v0, $v0, 0x1
    /* 1F344 8002EB44 0680013C */  lui        $at, %hi(D_80061B18)
    /* 1F348 8002EB48 DDBA0008 */  j          .L8002EB74
    /* 1F34C 8002EB4C 181B22AC */   sw        $v0, %lo(D_80061B18)($at)
  .L8002EB50:
    /* 1F350 8002EB50 03000424 */  addiu      $a0, $zero, 0x3
    /* 1F354 8002EB54 21300000 */  addu       $a2, $zero, $zero
    /* 1F358 8002EB58 0680053C */  lui        $a1, %hi(D_80061B34)
    /* 1F35C 8002EB5C 341BA58C */  lw         $a1, %lo(D_80061B34)($a1)
    /* 1F360 8002EB60 F8010724 */  addiu      $a3, $zero, 0x1F8
    /* 1F364 8002EB64 1000A8AF */  sw         $t0, 0x10($sp)
    /* 1F368 8002EB68 1400A0AF */  sw         $zero, 0x14($sp)
    /* 1F36C 8002EB6C 03BB000C */  jal        func_8002EC0C
    /* 1F370 8002EB70 1800A0AF */   sw        $zero, 0x18($sp)
  .L8002EB74:
    /* 1F374 8002EB74 0580033C */  lui        $v1, %hi(D_8004E684)
    /* 1F378 8002EB78 84E6638C */  lw         $v1, %lo(D_8004E684)($v1)
    /* 1F37C 8002EB7C 25130224 */  addiu      $v0, $zero, 0x1325
    /* 1F380 8002EB80 000062AC */  sw         $v0, 0x0($v1)
    /* 1F384 8002EB84 0680033C */  lui        $v1, %hi(D_80061B58)
    /* 1F388 8002EB88 581B638C */  lw         $v1, %lo(D_80061B58)($v1)
    /* 1F38C 8002EB8C 03000224 */  addiu      $v0, $zero, 0x3
    /* 1F390 8002EB90 000062A4 */  sh         $v0, 0x0($v1)
    /* 1F394 8002EB94 0680023C */  lui        $v0, %hi(D_80061B1C)
    /* 1F398 8002EB98 1C1B428C */  lw         $v0, %lo(D_80061B1C)($v0)
    /* 1F39C 8002EB9C 0680033C */  lui        $v1, %hi(D_80061B28)
    /* 1F3A0 8002EBA0 281B638C */  lw         $v1, %lo(D_80061B28)($v1)
    /* 1F3A4 8002EBA4 01004224 */  addiu      $v0, $v0, 0x1
    /* 1F3A8 8002EBA8 0680013C */  lui        $at, %hi(D_80061B1C)
    /* 1F3AC 8002EBAC 08006010 */  beqz       $v1, .L8002EBD0
    /* 1F3B0 8002EBB0 1C1B22AC */   sw        $v0, %lo(D_80061B1C)($at)
    /* 1F3B4 8002EBB4 0680023C */  lui        $v0, %hi(D_80061B14)
    /* 1F3B8 8002EBB8 141B428C */  lw         $v0, %lo(D_80061B14)($v0)
    /* 1F3BC 8002EBBC 00000000 */  nop
    /* 1F3C0 8002EBC0 03004010 */  beqz       $v0, .L8002EBD0
    /* 1F3C4 8002EBC4 00000000 */   nop
    /* 1F3C8 8002EBC8 DDB7000C */  jal        func_8002DF74
    /* 1F3CC 8002EBCC 00000000 */   nop
  .L8002EBD0:
    /* 1F3D0 8002EBD0 3800BF8F */  lw         $ra, 0x38($sp)
    /* 1F3D4 8002EBD4 4000BD27 */  addiu      $sp, $sp, 0x40
    /* 1F3D8 8002EBD8 0800E003 */  jr         $ra
    /* 1F3DC 8002EBDC 00000000 */   nop
endlabel func_8002E2C4
