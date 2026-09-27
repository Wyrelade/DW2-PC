nonmatching func_8002ACC8, 0x11C

glabel func_8002ACC8
    /* 1B4C8 8002ACC8 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 1B4CC 8002ACCC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1B4D0 8002ACD0 21888000 */  addu       $s1, $a0, $zero
    /* 1B4D4 8002ACD4 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 1B4D8 8002ACD8 2198A000 */  addu       $s3, $a1, $zero
    /* 1B4DC 8002ACDC 2000B4AF */  sw         $s4, 0x20($sp)
    /* 1B4E0 8002ACE0 21A0C000 */  addu       $s4, $a2, $zero
    /* 1B4E4 8002ACE4 21200000 */  addu       $a0, $zero, $zero
    /* 1B4E8 8002ACE8 1800B2AF */  sw         $s2, 0x18($sp)
    /* 1B4EC 8002ACEC 21908002 */  addu       $s2, $s4, $zero
    /* 1B4F0 8002ACF0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1B4F4 8002ACF4 2180E000 */  addu       $s0, $a3, $zero
    /* 1B4F8 8002ACF8 02111200 */  srl        $v0, $s2, 4
    /* 1B4FC 8002ACFC 03004230 */  andi       $v0, $v0, 0x3
    /* 1B500 8002AD00 2400B5AF */  sw         $s5, 0x24($sp)
    /* 1B504 8002AD04 4000B597 */  lhu        $s5, 0x40($sp)
    /* 1B508 8002AD08 03000324 */  addiu      $v1, $zero, 0x3
    /* 1B50C 8002AD0C 02004314 */  bne        $v0, $v1, .L8002AD18
    /* 1B510 8002AD10 2800BFAF */   sw        $ra, 0x28($sp)
    /* 1B514 8002AD14 03000424 */  addiu      $a0, $zero, 0x3
  .L8002AD18:
    /* 1B518 8002AD18 419C000C */  jal        func_80027104
    /* 1B51C 8002AD1C 00000000 */   nop
    /* 1B520 8002AD20 0680023C */  lui        $v0, %hi(D_80061910)
    /* 1B524 8002AD24 10194224 */  addiu      $v0, $v0, %lo(D_80061910)
    /* 1B528 8002AD28 F8FF4424 */  addiu      $a0, $v0, -0x8
    /* 1B52C 8002AD2C 020040A4 */  sh         $zero, 0x2($v0)
    /* 1B530 8002AD30 000040A4 */  sh         $zero, 0x0($v0)
    /* 1B534 8002AD34 0A0040A4 */  sh         $zero, 0xA($v0)
    /* 1B538 8002AD38 080040A4 */  sh         $zero, 0x8($v0)
    /* 1B53C 8002AD3C 060040A4 */  sh         $zero, 0x6($v0)
    /* 1B540 8002AD40 040040A4 */  sh         $zero, 0x4($v0)
    /* 1B544 8002AD44 0C0040A4 */  sh         $zero, 0xC($v0)
    /* 1B548 8002AD48 0E0050A0 */  sb         $s0, 0xE($v0)
    /* 1B54C 8002AD4C 0F0040A0 */  sb         $zero, 0xF($v0)
    /* 1B550 8002AD50 B99E000C */  jal        func_80027AE4
    /* 1B554 8002AD54 100040A0 */   sb        $zero, 0x10($v0)
    /* 1B558 8002AD58 0680103C */  lui        $s0, %hi(D_80061968)
    /* 1B55C 8002AD5C 68191026 */  addiu      $s0, $s0, %lo(D_80061968)
    /* 1B560 8002AD60 08000226 */  addiu      $v0, $s0, 0x8
    /* 1B564 8002AD64 000000A6 */  sh         $zero, 0x0($s0)
    /* 1B568 8002AD68 020000A6 */  sh         $zero, 0x2($s0)
    /* 1B56C 8002AD6C 040011A6 */  sh         $s1, 0x4($s0)
    /* 1B570 8002AD70 060013A6 */  sh         $s3, 0x6($s0)
    /* 1B574 8002AD74 080000A6 */  sh         $zero, 0x8($s0)
    /* 1B578 8002AD78 020040A4 */  sh         $zero, 0x2($v0)
    /* 1B57C 8002AD7C 040040A4 */  sh         $zero, 0x4($v0)
    /* 1B580 8002AD80 0EC6000C */  jal        GetVideoMode
    /* 1B584 8002AD84 060040A4 */   sh        $zero, 0x6($v0)
    /* 1B588 8002AD88 21184000 */  addu       $v1, $v0, $zero
    /* 1B58C 8002AD8C 01000224 */  addiu      $v0, $zero, 0x1
    /* 1B590 8002AD90 04006214 */  bne        $v1, $v0, .L8002ADA4
    /* 1B594 8002AD94 21200002 */   addu      $a0, $s0, $zero
    /* 1B598 8002AD98 18000224 */  addiu      $v0, $zero, 0x18
    /* 1B59C 8002AD9C 0A0002A6 */  sh         $v0, 0xA($s0)
    /* 1B5A0 8002ADA0 120003A2 */  sb         $v1, 0x12($s0)
  .L8002ADA4:
    /* 1B5A4 8002ADA4 01004232 */  andi       $v0, $s2, 0x1
    /* 1B5A8 8002ADA8 100082A0 */  sb         $v0, 0x10($a0)
    /* 1B5AC 8002ADAC 04008232 */  andi       $v0, $s4, 0x4
    /* 1B5B0 8002ADB0 0680013C */  lui        $at, %hi(D_8006198E)
    /* 1B5B4 8002ADB4 8E1922A4 */  sh         $v0, %lo(D_8006198E)($at)
    /* 1B5B8 8002ADB8 2C9F000C */  jal        func_80027CB0
    /* 1B5BC 8002ADBC 110095A0 */   sb        $s5, 0x11($a0)
    /* 1B5C0 8002ADC0 2800BF8F */  lw         $ra, 0x28($sp)
    /* 1B5C4 8002ADC4 2400B58F */  lw         $s5, 0x24($sp)
    /* 1B5C8 8002ADC8 2000B48F */  lw         $s4, 0x20($sp)
    /* 1B5CC 8002ADCC 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 1B5D0 8002ADD0 1800B28F */  lw         $s2, 0x18($sp)
    /* 1B5D4 8002ADD4 1400B18F */  lw         $s1, 0x14($sp)
    /* 1B5D8 8002ADD8 1000B08F */  lw         $s0, 0x10($sp)
    /* 1B5DC 8002ADDC 0800E003 */  jr         $ra
    /* 1B5E0 8002ADE0 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_8002ACC8
