nonmatching Stg40_ShowTrapEffectMsg, 0x11C

glabel Stg40_ShowTrapEffectMsg
    /* DFB0 80071310 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* DFB4 80071314 1000B0AF */  sw         $s0, 0x10($sp)
    /* DFB8 80071318 FD01103C */  lui        $s0, (0x1FD0011 >> 16)
    /* DFBC 8007131C 11001036 */  ori        $s0, $s0, (0x1FD0011 & 0xFFFF)
    /* DFC0 80071320 03008014 */  bnez       $a0, .L80071330
    /* DFC4 80071324 1400BFAF */   sw        $ra, 0x14($sp)
    /* DFC8 80071328 FD01103C */  lui        $s0, (0x1FD0047 >> 16)
    /* DFCC 8007132C 47001036 */  ori        $s0, $s0, (0x1FD0047 & 0xFFFF)
  .L80071330:
    /* DFD0 80071330 1100A22C */  sltiu      $v0, $a1, 0x11
    /* DFD4 80071334 26004010 */  beqz       $v0, .L800713D0
    /* DFD8 80071338 0680023C */   lui       $v0, %hi(jtbl_8006369C)
    /* DFDC 8007133C 9C364224 */  addiu      $v0, $v0, %lo(jtbl_8006369C)
    /* DFE0 80071340 80180500 */  sll        $v1, $a1, 2
    /* DFE4 80071344 21186200 */  addu       $v1, $v1, $v0
    /* DFE8 80071348 0000628C */  lw         $v0, 0x0($v1)
    /* DFEC 8007134C 00000000 */  nop
    /* DFF0 80071350 08004000 */  jr         $v0
    /* DFF4 80071354 00000000 */   nop
  jlabel .L80071358
    /* DFF8 80071358 0780023C */  lui        $v0, %hi(D_80072B60)
    /* DFFC 8007135C 602B428C */  lw         $v0, %lo(D_80072B60)($v0)
    /* E000 80071360 00000000 */  nop
    /* E004 80071364 5800458C */  lw         $a1, 0x58($v0)
    /* E008 80071368 579D010C */  jal        Stg40_NumToDigits
    /* E00C 8007136C 21200000 */   addu      $a0, $zero, $zero
    /* E010 80071370 01000424 */  addiu      $a0, $zero, 0x1
    /* E014 80071374 21280002 */  addu       $a1, $s0, $zero
    /* E018 80071378 0580033C */  lui        $v1, %hi(Save_GameStatePtr)
    /* E01C 8007137C 2007668C */  lw         $a2, %lo(Save_GameStatePtr)($v1)
    /* E020 80071380 21384000 */  addu       $a3, $v0, $zero
    /* E024 80071384 05C50108 */  j          .L80071414
    /* E028 80071388 D100C624 */   addiu     $a2, $a2, 0xD1
  jlabel .L8007138C
    /* E02C 8007138C 0780023C */  lui        $v0, %hi(D_80072B60)
    /* E030 80071390 602B428C */  lw         $v0, %lo(D_80072B60)($v0)
    /* E034 80071394 00000000 */  nop
    /* E038 80071398 5800458C */  lw         $a1, 0x58($v0)
    /* E03C 8007139C 579D010C */  jal        Stg40_NumToDigits
    /* E040 800713A0 21200000 */   addu      $a0, $zero, $zero
    /* E044 800713A4 01000424 */  addiu      $a0, $zero, 0x1
    /* E048 800713A8 03C50108 */  j          .L8007140C
    /* E04C 800713AC 21280402 */   addu      $a1, $s0, $a0
  jlabel .L800713B0
    /* E050 800713B0 01000424 */  addiu      $a0, $zero, 0x1
    /* E054 800713B4 21280502 */  addu       $a1, $s0, $a1
    /* E058 800713B8 04C50108 */  j          .L80071410
    /* E05C 800713BC 21300000 */   addu      $a2, $zero, $zero
  jlabel .L800713C0
    /* E060 800713C0 01000424 */  addiu      $a0, $zero, 0x1
    /* E064 800713C4 05000526 */  addiu      $a1, $s0, 0x5
    /* E068 800713C8 04C50108 */  j          .L80071410
    /* E06C 800713CC 21300000 */   addu      $a2, $zero, $zero
  jlabel .L800713D0
    /* E070 800713D0 0780033C */  lui        $v1, %hi(Stg40_TrapPartSlots)
    /* E074 800713D4 E0296324 */  addiu      $v1, $v1, %lo(Stg40_TrapPartSlots)
    /* E078 800713D8 FCFFA224 */  addiu      $v0, $a1, -0x4
    /* E07C 800713DC 40100200 */  sll        $v0, $v0, 1
    /* E080 800713E0 21104300 */  addu       $v0, $v0, $v1
    /* E084 800713E4 0580033C */  lui        $v1, %hi(Save_GameStatePtr)
    /* E088 800713E8 00004284 */  lh         $v0, 0x0($v0)
    /* E08C 800713EC 2007638C */  lw         $v1, %lo(Save_GameStatePtr)($v1)
    /* E090 800713F0 40100200 */  sll        $v0, $v0, 1
    /* E094 800713F4 21186200 */  addu       $v1, $v1, $v0
    /* E098 800713F8 2C006494 */  lhu        $a0, 0x2C($v1)
    /* E09C 800713FC 1278000C */  jal        Item_GetNameText
    /* E0A0 80071400 00000000 */   nop
    /* E0A4 80071404 01000424 */  addiu      $a0, $zero, 0x1
    /* E0A8 80071408 04000526 */  addiu      $a1, $s0, 0x4
  .L8007140C:
    /* E0AC 8007140C 21304000 */  addu       $a2, $v0, $zero
  .L80071410:
    /* E0B0 80071410 21380000 */  addu       $a3, $zero, $zero
  .L80071414:
    /* E0B4 80071414 849D010C */  jal        Stg40_MsgWinOpen
    /* E0B8 80071418 00000000 */   nop
    /* E0BC 8007141C 1400BF8F */  lw         $ra, 0x14($sp)
    /* E0C0 80071420 1000B08F */  lw         $s0, 0x10($sp)
    /* E0C4 80071424 0800E003 */  jr         $ra
    /* E0C8 80071428 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg40_ShowTrapEffectMsg
