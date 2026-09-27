nonmatching Gfx_SetPartsScale, 0x64

glabel Gfx_SetPartsScale
    /* DD50 8001D550 21188000 */  addu       $v1, $a0, $zero
    /* DD54 8001D554 0000628C */  lw         $v0, 0x0($v1)
    /* DD58 8001D558 00000000 */  nop
    /* DD5C 8001D55C 13004010 */  beqz       $v0, .L8001D5AC
    /* DD60 8001D560 00100824 */   addiu     $t0, $zero, 0x1000
    /* DD64 8001D564 01000724 */  addiu      $a3, $zero, 0x1
    /* DD68 8001D568 14008424 */  addiu      $a0, $a0, 0x14
  .L8001D56C:
    /* DD6C 8001D56C 0300A810 */  beq        $a1, $t0, .L8001D57C
    /* DD70 8001D570 00000000 */   nop
    /* DD74 8001D574 60750008 */  j          .L8001D580
    /* DD78 8001D578 FAFF80A0 */   sb        $zero, -0x6($a0)
  .L8001D57C:
    /* DD7C 8001D57C FAFF87A0 */  sb         $a3, -0x6($a0)
  .L8001D580:
    /* DD80 8001D580 0300C810 */  beq        $a2, $t0, .L8001D590
    /* DD84 8001D584 FCFF85AC */   sw        $a1, -0x4($a0)
    /* DD88 8001D588 65750008 */  j          .L8001D594
    /* DD8C 8001D58C FAFF80A0 */   sb        $zero, -0x6($a0)
  .L8001D590:
    /* DD90 8001D590 FAFF87A0 */  sb         $a3, -0x6($a0)
  .L8001D594:
    /* DD94 8001D594 28006324 */  addiu      $v1, $v1, 0x28
    /* DD98 8001D598 000086AC */  sw         $a2, 0x0($a0)
    /* DD9C 8001D59C 0000628C */  lw         $v0, 0x0($v1)
    /* DDA0 8001D5A0 00000000 */  nop
    /* DDA4 8001D5A4 F1FF4014 */  bnez       $v0, .L8001D56C
    /* DDA8 8001D5A8 28008424 */   addiu     $a0, $a0, 0x28
  .L8001D5AC:
    /* DDAC 8001D5AC 0800E003 */  jr         $ra
    /* DDB0 8001D5B0 00000000 */   nop
endlabel Gfx_SetPartsScale
