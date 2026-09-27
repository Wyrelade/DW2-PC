nonmatching func_8002F318, 0x280

glabel func_8002F318
    /* 1FB18 8002F318 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 1FB1C 8002F31C 3000B6AF */  sw         $s6, 0x30($sp)
    /* 1FB20 8002F320 21B08000 */  addu       $s6, $a0, $zero
    /* 1FB24 8002F324 3400B7AF */  sw         $s7, 0x34($sp)
    /* 1FB28 8002F328 21B8A000 */  addu       $s7, $a1, $zero
    /* 1FB2C 8002F32C FFFF0424 */  addiu      $a0, $zero, -0x1
    /* 1FB30 8002F330 3C00BFAF */  sw         $ra, 0x3C($sp)
    /* 1FB34 8002F334 3800BEAF */  sw         $fp, 0x38($sp)
    /* 1FB38 8002F338 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* 1FB3C 8002F33C 2800B4AF */  sw         $s4, 0x28($sp)
    /* 1FB40 8002F340 2400B3AF */  sw         $s3, 0x24($sp)
    /* 1FB44 8002F344 2000B2AF */  sw         $s2, 0x20($sp)
    /* 1FB48 8002F348 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 1FB4C 8002F34C ADC2000C */  jal        func_80030AB4
    /* 1FB50 8002F350 1800B0AF */   sw        $s0, 0x18($sp)
    /* 1FB54 8002F354 05801E3C */  lui        $fp, %hi(D_8004E6EC)
    /* 1FB58 8002F358 ECE6DE27 */  addiu      $fp, $fp, %lo(D_8004E6EC)
    /* 1FB5C 8002F35C 0580143C */  lui        $s4, %hi(D_8004E76C)
    /* 1FB60 8002F360 6CE79426 */  addiu      $s4, $s4, %lo(D_8004E76C)
    /* 1FB64 8002F364 0580123C */  lui        $s2, %hi(D_8004E9A4)
    /* 1FB68 8002F368 A4E95226 */  addiu      $s2, $s2, %lo(D_8004E9A4)
    /* 1FB6C 8002F36C 01005526 */  addiu      $s5, $s2, 0x1
    /* 1FB70 8002F370 02001324 */  addiu      $s3, $zero, 0x2
    /* 1FB74 8002F374 C0034224 */  addiu      $v0, $v0, 0x3C0
    /* 1FB78 8002F378 0680013C */  lui        $at, %hi(D_80061B80)
    /* 1FB7C 8002F37C 801B22AC */  sw         $v0, %lo(D_80061B80)($at)
    /* 1FB80 8002F380 0180023C */  lui        $v0, %hi(D_800108D8)
    /* 1FB84 8002F384 D8084224 */  addiu      $v0, $v0, %lo(D_800108D8)
    /* 1FB88 8002F388 0680013C */  lui        $at, %hi(D_80061B84)
    /* 1FB8C 8002F38C 841B20AC */  sw         $zero, %lo(D_80061B84)($at)
    /* 1FB90 8002F390 0680013C */  lui        $at, %hi(D_80061B88)
    /* 1FB94 8002F394 881B22AC */  sw         $v0, %lo(D_80061B88)($at)
  .L8002F398:
    /* 1FB98 8002F398 ADC2000C */  jal        func_80030AB4
    /* 1FB9C 8002F39C FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 1FBA0 8002F3A0 0680033C */  lui        $v1, %hi(D_80061B80)
    /* 1FBA4 8002F3A4 801B638C */  lw         $v1, %lo(D_80061B80)($v1)
    /* 1FBA8 8002F3A8 00000000 */  nop
    /* 1FBAC 8002F3AC 2A186200 */  slt        $v1, $v1, $v0
    /* 1FBB0 8002F3B0 0C006014 */  bnez       $v1, .L8002F3E4
    /* 1FBB4 8002F3B4 00000000 */   nop
    /* 1FBB8 8002F3B8 0680023C */  lui        $v0, %hi(D_80061B84)
    /* 1FBBC 8002F3BC 841B428C */  lw         $v0, %lo(D_80061B84)($v0)
    /* 1FBC0 8002F3C0 00000000 */  nop
    /* 1FBC4 8002F3C4 21184000 */  addu       $v1, $v0, $zero
    /* 1FBC8 8002F3C8 01004224 */  addiu      $v0, $v0, 0x1
    /* 1FBCC 8002F3CC 0680013C */  lui        $at, %hi(D_80061B84)
    /* 1FBD0 8002F3D0 841B22AC */  sw         $v0, %lo(D_80061B84)($at)
    /* 1FBD4 8002F3D4 3C00023C */  lui        $v0, (0x3C0000 >> 16)
    /* 1FBD8 8002F3D8 2A104300 */  slt        $v0, $v0, $v1
    /* 1FBDC 8002F3DC 1B004010 */  beqz       $v0, .L8002F44C
    /* 1FBE0 8002F3E0 00000000 */   nop
  .L8002F3E4:
    /* 1FBE4 8002F3E4 0180043C */  lui        $a0, %hi(D_80010850)
    /* 1FBE8 8002F3E8 CDC0000C */  jal        Debug_PutString
    /* 1FBEC 8002F3EC 50088424 */   addiu     $a0, $a0, %lo(D_80010850)
    /* 1FBF0 8002F3F0 00004492 */  lbu        $a0, 0x0($s2)
    /* 1FBF4 8002F3F4 01004292 */  lbu        $v0, 0x1($s2)
    /* 1FBF8 8002F3F8 0680053C */  lui        $a1, %hi(D_80061B88)
    /* 1FBFC 8002F3FC 881BA58C */  lw         $a1, %lo(D_80061B88)($a1)
    /* 1FC00 8002F400 80100200 */  sll        $v0, $v0, 2
    /* 1FC04 8002F404 21105400 */  addu       $v0, $v0, $s4
    /* 1FC08 8002F408 80200400 */  sll        $a0, $a0, 2
    /* 1FC0C 8002F40C 0000438C */  lw         $v1, 0x0($v0)
    /* 1FC10 8002F410 0580023C */  lui        $v0, %hi(D_8004E6E5)
    /* 1FC14 8002F414 E5E64290 */  lbu        $v0, %lo(D_8004E6E5)($v0)
    /* 1FC18 8002F418 21209400 */  addu       $a0, $a0, $s4
    /* 1FC1C 8002F41C 80100200 */  sll        $v0, $v0, 2
    /* 1FC20 8002F420 21105E00 */  addu       $v0, $v0, $fp
    /* 1FC24 8002F424 1000A3AF */  sw         $v1, 0x10($sp)
    /* 1FC28 8002F428 0000468C */  lw         $a2, 0x0($v0)
    /* 1FC2C 8002F42C 0000878C */  lw         $a3, 0x0($a0)
    /* 1FC30 8002F430 0180043C */  lui        $a0, %hi(D_80010860)
    /* 1FC34 8002F434 05A8000C */  jal        printf
    /* 1FC38 8002F438 60088424 */   addiu     $a0, $a0, %lo(D_80010860)
    /* 1FC3C 8002F43C 3DBF000C */  jal        CD_flush
    /* 1FC40 8002F440 00000000 */   nop
    /* 1FC44 8002F444 14BD0008 */  j          .L8002F450
    /* 1FC48 8002F448 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L8002F44C:
    /* 1FC4C 8002F44C 21100000 */  addu       $v0, $zero, $zero
  .L8002F450:
    /* 1FC50 8002F450 45004014 */  bnez       $v0, .L8002F568
    /* 1FC54 8002F454 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 1FC58 8002F458 8AC3000C */  jal        CheckCallback
    /* 1FC5C 8002F45C 00000000 */   nop
    /* 1FC60 8002F460 29004010 */  beqz       $v0, .L8002F508
    /* 1FC64 8002F464 00000000 */   nop
    /* 1FC68 8002F468 0580023C */  lui        $v0, %hi(D_8004E98C)
    /* 1FC6C 8002F46C 8CE9428C */  lw         $v0, %lo(D_8004E98C)($v0)
    /* 1FC70 8002F470 00000000 */  nop
    /* 1FC74 8002F474 00004290 */  lbu        $v0, 0x0($v0)
    /* 1FC78 8002F478 00000000 */  nop
    /* 1FC7C 8002F47C 03005130 */  andi       $s1, $v0, 0x3
  .L8002F480:
    /* 1FC80 8002F480 6DBB000C */  jal        func_8002EDB4
    /* 1FC84 8002F484 00000000 */   nop
    /* 1FC88 8002F488 21804000 */  addu       $s0, $v0, $zero
    /* 1FC8C 8002F48C 1A000012 */  beqz       $s0, .L8002F4F8
    /* 1FC90 8002F490 04000232 */   andi      $v0, $s0, 0x4
    /* 1FC94 8002F494 0B004010 */  beqz       $v0, .L8002F4C4
    /* 1FC98 8002F498 02000232 */   andi      $v0, $s0, 0x2
    /* 1FC9C 8002F49C 0580023C */  lui        $v0, %hi(D_8004E6CC)
    /* 1FCA0 8002F4A0 CCE6428C */  lw         $v0, %lo(D_8004E6CC)($v0)
    /* 1FCA4 8002F4A4 00000000 */  nop
    /* 1FCA8 8002F4A8 05004010 */  beqz       $v0, .L8002F4C0
    /* 1FCAC 8002F4AC 00000000 */   nop
    /* 1FCB0 8002F4B0 0000A492 */  lbu        $a0, 0x0($s5)
    /* 1FCB4 8002F4B4 0680053C */  lui        $a1, %hi(D_80061B70)
    /* 1FCB8 8002F4B8 09F84000 */  jalr       $v0
    /* 1FCBC 8002F4BC 701BA524 */   addiu     $a1, $a1, %lo(D_80061B70)
  .L8002F4C0:
    /* 1FCC0 8002F4C0 02000232 */  andi       $v0, $s0, 0x2
  .L8002F4C4:
    /* 1FCC4 8002F4C4 EEFF4010 */  beqz       $v0, .L8002F480
    /* 1FCC8 8002F4C8 00000000 */   nop
    /* 1FCCC 8002F4CC 0580023C */  lui        $v0, %hi(D_8004E6C8)
    /* 1FCD0 8002F4D0 C8E6428C */  lw         $v0, %lo(D_8004E6C8)($v0)
    /* 1FCD4 8002F4D4 00000000 */  nop
    /* 1FCD8 8002F4D8 E9FF4010 */  beqz       $v0, .L8002F480
    /* 1FCDC 8002F4DC 00000000 */   nop
    /* 1FCE0 8002F4E0 00004492 */  lbu        $a0, 0x0($s2)
    /* 1FCE4 8002F4E4 0680053C */  lui        $a1, %hi(D_80061B68)
    /* 1FCE8 8002F4E8 09F84000 */  jalr       $v0
    /* 1FCEC 8002F4EC 681BA524 */   addiu     $a1, $a1, %lo(D_80061B68)
    /* 1FCF0 8002F4F0 20BD0008 */  j          .L8002F480
    /* 1FCF4 8002F4F4 00000000 */   nop
  .L8002F4F8:
    /* 1FCF8 8002F4F8 0580023C */  lui        $v0, %hi(D_8004E98C)
    /* 1FCFC 8002F4FC 8CE9428C */  lw         $v0, %lo(D_8004E98C)($v0)
    /* 1FD00 8002F500 00000000 */  nop
    /* 1FD04 8002F504 000051A0 */  sb         $s1, 0x0($v0)
  .L8002F508:
    /* 1FD08 8002F508 00004292 */  lbu        $v0, 0x0($s2)
    /* 1FD0C 8002F50C 00000000 */  nop
    /* 1FD10 8002F510 FF004630 */  andi       $a2, $v0, 0xFF
    /* 1FD14 8002F514 0300D310 */  beq        $a2, $s3, .L8002F524
    /* 1FD18 8002F518 05000224 */   addiu     $v0, $zero, 0x5
    /* 1FD1C 8002F51C 1000C214 */  bne        $a2, $v0, .L8002F560
    /* 1FD20 8002F520 00000000 */   nop
  .L8002F524:
    /* 1FD24 8002F524 000053A2 */  sb         $s3, 0x0($s2)
    /* 1FD28 8002F528 2128E002 */  addu       $a1, $s7, $zero
    /* 1FD2C 8002F52C 0680043C */  lui        $a0, %hi(D_80061B68)
    /* 1FD30 8002F530 681B8424 */  addiu      $a0, $a0, %lo(D_80061B68)
    /* 1FD34 8002F534 0800A010 */  beqz       $a1, .L8002F558
    /* 1FD38 8002F538 07000324 */   addiu     $v1, $zero, 0x7
    /* 1FD3C 8002F53C FFFF0724 */  addiu      $a3, $zero, -0x1
  .L8002F540:
    /* 1FD40 8002F540 00008290 */  lbu        $v0, 0x0($a0)
    /* 1FD44 8002F544 01008424 */  addiu      $a0, $a0, 0x1
    /* 1FD48 8002F548 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 1FD4C 8002F54C 0000A2A0 */  sb         $v0, 0x0($a1)
    /* 1FD50 8002F550 FBFF6714 */  bne        $v1, $a3, .L8002F540
    /* 1FD54 8002F554 0100A524 */   addiu     $a1, $a1, 0x1
  .L8002F558:
    /* 1FD58 8002F558 5ABD0008 */  j          .L8002F568
    /* 1FD5C 8002F55C 2110C000 */   addu      $v0, $a2, $zero
  .L8002F560:
    /* 1FD60 8002F560 8DFFC012 */  beqz       $s6, .L8002F398
    /* 1FD64 8002F564 21100000 */   addu      $v0, $zero, $zero
  .L8002F568:
    /* 1FD68 8002F568 3C00BF8F */  lw         $ra, 0x3C($sp)
    /* 1FD6C 8002F56C 3800BE8F */  lw         $fp, 0x38($sp)
    /* 1FD70 8002F570 3400B78F */  lw         $s7, 0x34($sp)
    /* 1FD74 8002F574 3000B68F */  lw         $s6, 0x30($sp)
    /* 1FD78 8002F578 2C00B58F */  lw         $s5, 0x2C($sp)
    /* 1FD7C 8002F57C 2800B48F */  lw         $s4, 0x28($sp)
    /* 1FD80 8002F580 2400B38F */  lw         $s3, 0x24($sp)
    /* 1FD84 8002F584 2000B28F */  lw         $s2, 0x20($sp)
    /* 1FD88 8002F588 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 1FD8C 8002F58C 1800B08F */  lw         $s0, 0x18($sp)
    /* 1FD90 8002F590 0800E003 */  jr         $ra
    /* 1FD94 8002F594 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_8002F318
