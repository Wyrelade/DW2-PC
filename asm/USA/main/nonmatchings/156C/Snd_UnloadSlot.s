nonmatching Snd_UnloadSlot, 0x14C

glabel Snd_UnloadSlot
    /* ACA8 8001A4A8 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* ACAC 8001A4AC 2400B5AF */  sw         $s5, 0x24($sp)
    /* ACB0 8001A4B0 21A88000 */  addu       $s5, $a0, $zero
    /* ACB4 8001A4B4 0580023C */  lui        $v0, %hi(D_80054C48)
    /* ACB8 8001A4B8 484C4524 */  addiu      $a1, $v0, %lo(D_80054C48)
    /* ACBC 8001A4BC 40101500 */  sll        $v0, $s5, 1
    /* ACC0 8001A4C0 1000B0AF */  sw         $s0, 0x10($sp)
    /* ACC4 8001A4C4 21805500 */  addu       $s0, $v0, $s5
    /* ACC8 8001A4C8 80101000 */  sll        $v0, $s0, 2
    /* ACCC 8001A4CC 23105500 */  subu       $v0, $v0, $s5
    /* ACD0 8001A4D0 80100200 */  sll        $v0, $v0, 2
    /* ACD4 8001A4D4 21204500 */  addu       $a0, $v0, $a1
    /* ACD8 8001A4D8 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* ACDC 8001A4DC 2800B6AF */  sw         $s6, 0x28($sp)
    /* ACE0 8001A4E0 2000B4AF */  sw         $s4, 0x20($sp)
    /* ACE4 8001A4E4 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* ACE8 8001A4E8 1800B2AF */  sw         $s2, 0x18($sp)
    /* ACEC 8001A4EC 1400B1AF */  sw         $s1, 0x14($sp)
    /* ACF0 8001A4F0 08008384 */  lh         $v1, 0x8($a0)
    /* ACF4 8001A4F4 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* ACF8 8001A4F8 34006210 */  beq        $v1, $v0, .L8001A5CC
    /* ACFC 8001A4FC 00000000 */   nop
    /* AD00 8001A500 0A008284 */  lh         $v0, 0xA($a0)
    /* AD04 8001A504 00000000 */  nop
    /* AD08 8001A508 20004018 */  blez       $v0, .L8001A58C
    /* AD0C 8001A50C 21980000 */   addu      $s3, $zero, $zero
    /* AD10 8001A510 21B0A000 */  addu       $s6, $a1, $zero
    /* AD14 8001A514 21A00002 */  addu       $s4, $s0, $zero
    /* AD18 8001A518 21906002 */  addu       $s2, $s3, $zero
    /* AD1C 8001A51C 21800000 */  addu       $s0, $zero, $zero
  .L8001A520:
    /* AD20 8001A520 80101400 */  sll        $v0, $s4, 2
    /* AD24 8001A524 23105500 */  subu       $v0, $v0, $s5
    /* AD28 8001A528 80100200 */  sll        $v0, $v0, 2
    /* AD2C 8001A52C 21104202 */  addu       $v0, $s2, $v0
    /* AD30 8001A530 21885600 */  addu       $s1, $v0, $s6
  .L8001A534:
    /* AD34 8001A534 0C002486 */  lh         $a0, 0xC($s1)
    /* AD38 8001A538 002C1000 */  sll        $a1, $s0, 16
    /* AD3C 8001A53C 01001026 */  addiu      $s0, $s0, 0x1
    /* AD40 8001A540 A7D5000C */  jal        SsSepStop
    /* AD44 8001A544 032C0500 */   sra       $a1, $a1, 16
    /* AD48 8001A548 1000022A */  slti       $v0, $s0, 0x10
    /* AD4C 8001A54C F9FF4014 */  bnez       $v0, .L8001A534
    /* AD50 8001A550 00000000 */   nop
    /* AD54 8001A554 80801400 */  sll        $s0, $s4, 2
    /* AD58 8001A558 23801502 */  subu       $s0, $s0, $s5
    /* AD5C 8001A55C 80801000 */  sll        $s0, $s0, 2
    /* AD60 8001A560 21105002 */  addu       $v0, $s2, $s0
    /* AD64 8001A564 21105600 */  addu       $v0, $v0, $s6
    /* AD68 8001A568 0C004484 */  lh         $a0, 0xC($v0)
    /* AD6C 8001A56C 11CA000C */  jal        func_80032844
    /* AD70 8001A570 02005226 */   addiu     $s2, $s2, 0x2
    /* AD74 8001A574 21801602 */  addu       $s0, $s0, $s6
    /* AD78 8001A578 0A000286 */  lh         $v0, 0xA($s0)
    /* AD7C 8001A57C 01007326 */  addiu      $s3, $s3, 0x1
    /* AD80 8001A580 2A106202 */  slt        $v0, $s3, $v0
    /* AD84 8001A584 E6FF4014 */  bnez       $v0, .L8001A520
    /* AD88 8001A588 21800000 */   addu      $s0, $zero, $zero
  .L8001A58C:
    /* AD8C 8001A58C 0580023C */  lui        $v0, %hi(D_80054C48)
    /* AD90 8001A590 484C4224 */  addiu      $v0, $v0, %lo(D_80054C48)
    /* AD94 8001A594 40801500 */  sll        $s0, $s5, 1
    /* AD98 8001A598 21801502 */  addu       $s0, $s0, $s5
    /* AD9C 8001A59C 80801000 */  sll        $s0, $s0, 2
    /* ADA0 8001A5A0 23801502 */  subu       $s0, $s0, $s5
    /* ADA4 8001A5A4 80801000 */  sll        $s0, $s0, 2
    /* ADA8 8001A5A8 21800202 */  addu       $s0, $s0, $v0
    /* ADAC 8001A5AC 08000486 */  lh         $a0, 0x8($s0)
    /* ADB0 8001A5B0 65E6000C */  jal        SsVabClose
    /* ADB4 8001A5B4 00000000 */   nop
    /* ADB8 8001A5B8 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* ADBC 8001A5BC 040000AE */  sw         $zero, 0x4($s0)
    /* ADC0 8001A5C0 000002AE */  sw         $v0, 0x0($s0)
    /* ADC4 8001A5C4 0A0000A6 */  sh         $zero, 0xA($s0)
    /* ADC8 8001A5C8 080002A6 */  sh         $v0, 0x8($s0)
  .L8001A5CC:
    /* ADCC 8001A5CC 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* ADD0 8001A5D0 2800B68F */  lw         $s6, 0x28($sp)
    /* ADD4 8001A5D4 2400B58F */  lw         $s5, 0x24($sp)
    /* ADD8 8001A5D8 2000B48F */  lw         $s4, 0x20($sp)
    /* ADDC 8001A5DC 1C00B38F */  lw         $s3, 0x1C($sp)
    /* ADE0 8001A5E0 1800B28F */  lw         $s2, 0x18($sp)
    /* ADE4 8001A5E4 1400B18F */  lw         $s1, 0x14($sp)
    /* ADE8 8001A5E8 1000B08F */  lw         $s0, 0x10($sp)
    /* ADEC 8001A5EC 0800E003 */  jr         $ra
    /* ADF0 8001A5F0 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel Snd_UnloadSlot
