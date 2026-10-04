nonmatching Stg20_TickOccupantMarks, 0x80

glabel Stg20_TickOccupantMarks
    /* 4548 800678A8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 454C 800678AC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 4550 800678B0 21880000 */  addu       $s1, $zero, $zero
    /* 4554 800678B4 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 4558 800678B8 1800B2AF */  sw         $s2, 0x18($sp)
    /* 455C 800678BC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 4560 800678C0 0400828C */  lw         $v0, 0x4($a0)
    /* 4564 800678C4 2180A000 */  addu       $s0, $a1, $zero
    /* 4568 800678C8 0100522C */  sltiu      $s2, $v0, 0x1
  .L800678CC:
    /* 456C 800678CC 1400028E */  lw         $v0, 0x14($s0)
    /* 4570 800678D0 00000000 */  nop
    /* 4574 800678D4 0A004010 */  beqz       $v0, .L80067900
    /* 4578 800678D8 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 457C 800678DC 04004014 */  bnez       $v0, .L800678F0
    /* 4580 800678E0 140002AE */   sw        $v0, 0x14($s0)
    /* 4584 800678E4 21200002 */  addu       $a0, $s0, $zero
    /* 4588 800678E8 3E9E0108 */  j          .L800678F8
    /* 458C 800678EC 21280000 */   addu      $a1, $zero, $zero
  .L800678F0:
    /* 4590 800678F0 21200002 */  addu       $a0, $s0, $zero
    /* 4594 800678F4 01000524 */  addiu      $a1, $zero, 0x1
  .L800678F8:
    /* 4598 800678F8 B68D010C */  jal        Stg20_MarkGridOccupant
    /* 459C 800678FC 21304002 */   addu      $a2, $s2, $zero
  .L80067900:
    /* 45A0 80067900 01003126 */  addiu      $s1, $s1, 0x1
    /* 45A4 80067904 0500222A */  slti       $v0, $s1, 0x5
    /* 45A8 80067908 F0FF4014 */  bnez       $v0, .L800678CC
    /* 45AC 8006790C 04001026 */   addiu     $s0, $s0, 0x4
    /* 45B0 80067910 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 45B4 80067914 1800B28F */  lw         $s2, 0x18($sp)
    /* 45B8 80067918 1400B18F */  lw         $s1, 0x14($sp)
    /* 45BC 8006791C 1000B08F */  lw         $s0, 0x10($sp)
    /* 45C0 80067920 0800E003 */  jr         $ra
    /* 45C4 80067924 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg20_TickOccupantMarks
