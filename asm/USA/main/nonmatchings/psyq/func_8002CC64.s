nonmatching func_8002CC64, 0x154

glabel func_8002CC64
    /* 1D464 8002CC64 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 1D468 8002CC68 5D00033C */  lui        $v1, (0x5D50AD >> 16)
    /* 1D46C 8002CC6C AD506334 */  ori        $v1, $v1, (0x5D50AD & 0xFFFF)
    /* 1D470 8002CC70 01000724 */  addiu      $a3, $zero, 0x1
    /* 1D474 8002CC74 04000A24 */  addiu      $t2, $zero, 0x4
    /* 1D478 8002CC78 2400A927 */  addiu      $t1, $sp, 0x24
    /* 1D47C 8002CC7C 2800A827 */  addiu      $t0, $sp, 0x28
    /* 1D480 8002CC80 0400A627 */  addiu      $a2, $sp, 0x4
    /* 1D484 8002CC84 21108300 */  addu       $v0, $a0, $v1
    /* 1D488 8002CC88 23208300 */  subu       $a0, $a0, $v1
    /* 1D48C 8002CC8C 0400A2AF */  sw         $v0, 0x4($sp)
    /* 1D490 8002CC90 2400A4AF */  sw         $a0, 0x24($sp)
  .L8002CC94:
    /* 1D494 8002CC94 1A00EA10 */  beq        $a3, $t2, .L8002CD00
    /* 1D498 8002CC98 00000000 */   nop
    /* 1D49C 8002CC9C 2000C38C */  lw         $v1, 0x20($a2)
    /* 1D4A0 8002CCA0 00000000 */  nop
    /* 1D4A4 8002CCA4 0B006004 */  bltz       $v1, .L8002CCD4
    /* 1D4A8 8002CCA8 80200700 */   sll       $a0, $a3, 2
    /* 1D4AC 8002CCAC 0000C28C */  lw         $v0, 0x0($a2)
    /* 1D4B0 8002CCB0 0718E300 */  srav       $v1, $v1, $a3
    /* 1D4B4 8002CCB4 23104300 */  subu       $v0, $v0, $v1
    /* 1D4B8 8002CCB8 0400C2AC */  sw         $v0, 0x4($a2)
    /* 1D4BC 8002CCBC 0000C28C */  lw         $v0, 0x0($a2)
    /* 1D4C0 8002CCC0 2000C38C */  lw         $v1, 0x20($a2)
    /* 1D4C4 8002CCC4 0710E200 */  srav       $v0, $v0, $a3
    /* 1D4C8 8002CCC8 23186200 */  subu       $v1, $v1, $v0
    /* 1D4CC 8002CCCC 66B30008 */  j          .L8002CD98
    /* 1D4D0 8002CCD0 000003AD */   sw        $v1, 0x0($t0)
  .L8002CCD4:
    /* 1D4D4 8002CCD4 0718E300 */  srav       $v1, $v1, $a3
    /* 1D4D8 8002CCD8 0000C28C */  lw         $v0, 0x0($a2)
    /* 1D4DC 8002CCDC 21202401 */  addu       $a0, $t1, $a0
    /* 1D4E0 8002CCE0 21104300 */  addu       $v0, $v0, $v1
    /* 1D4E4 8002CCE4 0400C2AC */  sw         $v0, 0x4($a2)
    /* 1D4E8 8002CCE8 0000C28C */  lw         $v0, 0x0($a2)
    /* 1D4EC 8002CCEC 2000C38C */  lw         $v1, 0x20($a2)
    /* 1D4F0 8002CCF0 0710E200 */  srav       $v0, $v0, $a3
    /* 1D4F4 8002CCF4 21186200 */  addu       $v1, $v1, $v0
    /* 1D4F8 8002CCF8 66B30008 */  j          .L8002CD98
    /* 1D4FC 8002CCFC 000083AC */   sw        $v1, 0x0($a0)
  .L8002CD00:
    /* 1D500 8002CD00 3000A48F */  lw         $a0, 0x30($sp)
    /* 1D504 8002CD04 00000000 */  nop
    /* 1D508 8002CD08 0F008004 */  bltz       $a0, .L8002CD48
    /* 1D50C 8002CD0C 03110400 */   sra       $v0, $a0, 4
    /* 1D510 8002CD10 1000A38F */  lw         $v1, 0x10($sp)
    /* 1D514 8002CD14 00000000 */  nop
    /* 1D518 8002CD18 23286200 */  subu       $a1, $v1, $v0
    /* 1D51C 8002CD1C 03110300 */  sra        $v0, $v1, 4
    /* 1D520 8002CD20 23188200 */  subu       $v1, $a0, $v0
    /* 1D524 8002CD24 1000A5AF */  sw         $a1, 0x10($sp)
    /* 1D528 8002CD28 15006004 */  bltz       $v1, .L8002CD80
    /* 1D52C 8002CD2C 3000A3AF */   sw        $v1, 0x30($sp)
    /* 1D530 8002CD30 03110300 */  sra        $v0, $v1, 4
    /* 1D534 8002CD34 2310A200 */  subu       $v0, $a1, $v0
    /* 1D538 8002CD38 1400A2AF */  sw         $v0, 0x14($sp)
    /* 1D53C 8002CD3C 03110500 */  sra        $v0, $a1, 4
    /* 1D540 8002CD40 65B30008 */  j          .L8002CD94
    /* 1D544 8002CD44 23106200 */   subu      $v0, $v1, $v0
  .L8002CD48:
    /* 1D548 8002CD48 1000A38F */  lw         $v1, 0x10($sp)
    /* 1D54C 8002CD4C 00000000 */  nop
    /* 1D550 8002CD50 21286200 */  addu       $a1, $v1, $v0
    /* 1D554 8002CD54 03110300 */  sra        $v0, $v1, 4
    /* 1D558 8002CD58 21188200 */  addu       $v1, $a0, $v0
    /* 1D55C 8002CD5C 1000A5AF */  sw         $a1, 0x10($sp)
    /* 1D560 8002CD60 07006004 */  bltz       $v1, .L8002CD80
    /* 1D564 8002CD64 3000A3AF */   sw        $v1, 0x30($sp)
    /* 1D568 8002CD68 03110300 */  sra        $v0, $v1, 4
    /* 1D56C 8002CD6C 2310A200 */  subu       $v0, $a1, $v0
    /* 1D570 8002CD70 1400A2AF */  sw         $v0, 0x14($sp)
    /* 1D574 8002CD74 03110500 */  sra        $v0, $a1, 4
    /* 1D578 8002CD78 65B30008 */  j          .L8002CD94
    /* 1D57C 8002CD7C 23106200 */   subu      $v0, $v1, $v0
  .L8002CD80:
    /* 1D580 8002CD80 03110300 */  sra        $v0, $v1, 4
    /* 1D584 8002CD84 2110A200 */  addu       $v0, $a1, $v0
    /* 1D588 8002CD88 1400A2AF */  sw         $v0, 0x14($sp)
    /* 1D58C 8002CD8C 03110500 */  sra        $v0, $a1, 4
    /* 1D590 8002CD90 21106200 */  addu       $v0, $v1, $v0
  .L8002CD94:
    /* 1D594 8002CD94 3400A2AF */  sw         $v0, 0x34($sp)
  .L8002CD98:
    /* 1D598 8002CD98 04000825 */  addiu      $t0, $t0, 0x4
    /* 1D59C 8002CD9C 0100E724 */  addiu      $a3, $a3, 0x1
    /* 1D5A0 8002CDA0 0700E228 */  slti       $v0, $a3, 0x7
    /* 1D5A4 8002CDA4 BBFF4014 */  bnez       $v0, .L8002CC94
    /* 1D5A8 8002CDA8 0400C624 */   addiu     $a2, $a2, 0x4
    /* 1D5AC 8002CDAC 1C00A28F */  lw         $v0, 0x1C($sp)
    /* 1D5B0 8002CDB0 0800E003 */  jr         $ra
    /* 1D5B4 8002CDB4 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_8002CC64
