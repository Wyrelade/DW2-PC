nonmatching Text_PrintIdList, 0xC4

glabel Text_PrintIdList
    /* 3D58 80013558 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 3D5C 8001355C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 3D60 80013560 21908000 */  addu       $s2, $a0, $zero
    /* 3D64 80013564 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3D68 80013568 2180A000 */  addu       $s0, $a1, $zero
    /* 3D6C 8001356C 2400B5AF */  sw         $s5, 0x24($sp)
    /* 3D70 80013570 21A8C000 */  addu       $s5, $a2, $zero
    /* 3D74 80013574 2800BFAF */  sw         $ra, 0x28($sp)
    /* 3D78 80013578 2000B4AF */  sw         $s4, 0x20($sp)
    /* 3D7C 8001357C 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 3D80 80013580 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3D84 80013584 0000028E */  lw         $v0, 0x0($s0)
    /* 3D88 80013588 00000000 */  nop
    /* 3D8C 8001358C 19004010 */  beqz       $v0, .L800135F4
    /* 3D90 80013590 21980000 */   addu      $s3, $zero, $zero
    /* 3D94 80013594 FD01143C */  lui        $s4, (0x1FD0000 >> 16)
    /* 3D98 80013598 0600B124 */  addiu      $s1, $a1, 0x6
  .L8001359C:
    /* 3D9C 8001359C 0000048E */  lw         $a0, 0x0($s0)
    /* 3DA0 800135A0 01007326 */  addiu      $s3, $s3, 0x1
    /* 3DA4 800135A4 FF0F8430 */  andi       $a0, $a0, 0xFFF
    /* 3DA8 800135A8 688E000C */  jal        Cd_GetFileEntry
    /* 3DAC 800135AC 25209400 */   or        $a0, $a0, $s4
    /* 3DB0 800135B0 21204002 */  addu       $a0, $s2, $zero
    /* 3DB4 800135B4 FEFF2396 */  lhu        $v1, -0x2($s1)
    /* 3DB8 800135B8 00002796 */  lhu        $a3, 0x0($s1)
    /* 3DBC 800135BC 08003126 */  addiu      $s1, $s1, 0x8
    /* 3DC0 800135C0 0000068E */  lw         $a2, 0x0($s0)
    /* 3DC4 800135C4 21284000 */  addu       $a1, $v0, $zero
    /* 3DC8 800135C8 00F0C630 */  andi       $a2, $a2, 0xF000
    /* 3DCC 800135CC 83320600 */  sra        $a2, $a2, 10
    /* 3DD0 800135D0 003C0700 */  sll        $a3, $a3, 16
    /* 3DD4 800135D4 2530A602 */  or         $a2, $s5, $a2
    /* 3DD8 800135D8 3E4D000C */  jal        Text_OpenPacked
    /* 3DDC 800135DC 25386700 */   or        $a3, $v1, $a3
    /* 3DE0 800135E0 08001026 */  addiu      $s0, $s0, 0x8
    /* 3DE4 800135E4 0000028E */  lw         $v0, 0x0($s0)
    /* 3DE8 800135E8 00000000 */  nop
    /* 3DEC 800135EC EBFF4014 */  bnez       $v0, .L8001359C
    /* 3DF0 800135F0 04005226 */   addiu     $s2, $s2, 0x4
  .L800135F4:
    /* 3DF4 800135F4 21106002 */  addu       $v0, $s3, $zero
    /* 3DF8 800135F8 2800BF8F */  lw         $ra, 0x28($sp)
    /* 3DFC 800135FC 2400B58F */  lw         $s5, 0x24($sp)
    /* 3E00 80013600 2000B48F */  lw         $s4, 0x20($sp)
    /* 3E04 80013604 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 3E08 80013608 1800B28F */  lw         $s2, 0x18($sp)
    /* 3E0C 8001360C 1400B18F */  lw         $s1, 0x14($sp)
    /* 3E10 80013610 1000B08F */  lw         $s0, 0x10($sp)
    /* 3E14 80013614 0800E003 */  jr         $ra
    /* 3E18 80013618 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel Text_PrintIdList
