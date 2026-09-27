nonmatching func_80029B9C, 0xEC

glabel func_80029B9C
    /* 1A39C 80029B9C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1A3A0 80029BA0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1A3A4 80029BA4 21808000 */  addu       $s0, $a0, $zero
    /* 1A3A8 80029BA8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1A3AC 80029BAC 2188A000 */  addu       $s1, $a1, $zero
    /* 1A3B0 80029BB0 0180043C */  lui        $a0, %hi(D_800103F8)
    /* 1A3B4 80029BB4 F8038424 */  addiu      $a0, $a0, %lo(D_800103F8)
    /* 1A3B8 80029BB8 1800BFAF */  sw         $ra, 0x18($sp)
    /* 1A3BC 80029BBC 3A9D000C */  jal        checkRECT
    /* 1A3C0 80029BC0 21280002 */   addu      $a1, $s0, $zero
    /* 1A3C4 80029BC4 ADC2000C */  jal        VSync
    /* 1A3C8 80029BC8 FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 1A3CC 80029BCC 0580033C */  lui        $v1, %hi(D_80049024)
    /* 1A3D0 80029BD0 2490638C */  lw         $v1, %lo(D_80049024)($v1)
    /* 1A3D4 80029BD4 F0004224 */  addiu      $v0, $v0, 0xF0
    /* 1A3D8 80029BD8 0580013C */  lui        $at, %hi(D_8004904C)
    /* 1A3DC 80029BDC 4C9022AC */  sw         $v0, %lo(D_8004904C)($at)
    /* 1A3E0 80029BE0 0580013C */  lui        $at, %hi(D_80049050)
    /* 1A3E4 80029BE4 509020AC */  sw         $zero, %lo(D_80049050)($at)
    /* 1A3E8 80029BE8 0000628C */  lw         $v0, 0x0($v1)
    /* 1A3EC 80029BEC 06A70008 */  j          .L80029C18
    /* 1A3F0 80029BF0 0001033C */   lui       $v1, (0x1000000 >> 16)
  .L80029BF4:
    /* 1A3F4 80029BF4 6EA6000C */  jal        func_800299B8
    /* 1A3F8 80029BF8 00000000 */   nop
    /* 1A3FC 80029BFC 1D004014 */  bnez       $v0, .L80029C74
    /* 1A400 80029C00 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 1A404 80029C04 0580023C */  lui        $v0, %hi(D_80049024)
    /* 1A408 80029C08 2490428C */  lw         $v0, %lo(D_80049024)($v0)
    /* 1A40C 80029C0C 00000000 */  nop
    /* 1A410 80029C10 0000428C */  lw         $v0, 0x0($v0)
    /* 1A414 80029C14 0001033C */  lui        $v1, (0x1000000 >> 16)
  .L80029C18:
    /* 1A418 80029C18 24104300 */  and        $v0, $v0, $v1
    /* 1A41C 80029C1C F5FF4014 */  bnez       $v0, .L80029BF4
    /* 1A420 80029C20 00000000 */   nop
    /* 1A424 80029C24 0580023C */  lui        $v0, %hi(D_80049018)
    /* 1A428 80029C28 1890428C */  lw         $v0, %lo(D_80049018)($v0)
    /* 1A42C 80029C2C 00000000 */  nop
    /* 1A430 80029C30 0000428C */  lw         $v0, 0x0($v0)
    /* 1A434 80029C34 0004033C */  lui        $v1, (0x4000000 >> 16)
    /* 1A438 80029C38 24104300 */  and        $v0, $v0, $v1
    /* 1A43C 80029C3C EDFF4010 */  beqz       $v0, .L80029BF4
    /* 1A440 80029C40 00000000 */   nop
    /* 1A444 80029C44 0380053C */  lui        $a1, %hi(func_80029FB4)
    /* 1A448 80029C48 B49FA524 */  addiu      $a1, $a1, %lo(func_80029FB4)
    /* 1A44C 80029C4C 4DC3000C */  jal        DMACallback
    /* 1A450 80029C50 02000424 */   addiu     $a0, $zero, 0x2
    /* 1A454 80029C54 0580023C */  lui        $v0, %hi(D_80048F08)
    /* 1A458 80029C58 088F428C */  lw         $v0, %lo(D_80048F08)($v0)
    /* 1A45C 80029C5C 21200002 */  addu       $a0, $s0, $zero
    /* 1A460 80029C60 2000428C */  lw         $v0, 0x20($v0)
    /* 1A464 80029C64 00000000 */  nop
    /* 1A468 80029C68 09F84000 */  jalr       $v0
    /* 1A46C 80029C6C 21282002 */   addu      $a1, $s1, $zero
    /* 1A470 80029C70 21100000 */  addu       $v0, $zero, $zero
  .L80029C74:
    /* 1A474 80029C74 1800BF8F */  lw         $ra, 0x18($sp)
    /* 1A478 80029C78 1400B18F */  lw         $s1, 0x14($sp)
    /* 1A47C 80029C7C 1000B08F */  lw         $s0, 0x10($sp)
    /* 1A480 80029C80 0800E003 */  jr         $ra
    /* 1A484 80029C84 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80029B9C
