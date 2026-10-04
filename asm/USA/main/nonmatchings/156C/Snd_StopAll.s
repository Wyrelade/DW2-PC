nonmatching Snd_StopAll, 0xD0

glabel Snd_StopAll
    /* AB40 8001A340 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* AB44 8001A344 2400B5AF */  sw         $s5, 0x24($sp)
    /* AB48 8001A348 21A80000 */  addu       $s5, $zero, $zero
    /* AB4C 8001A34C 0580023C */  lui        $v0, %hi(Snd_Slots)
    /* AB50 8001A350 2000B4AF */  sw         $s4, 0x20($sp)
    /* AB54 8001A354 484C5424 */  addiu      $s4, $v0, %lo(Snd_Slots)
    /* AB58 8001A358 2800BFAF */  sw         $ra, 0x28($sp)
    /* AB5C 8001A35C 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* AB60 8001A360 1800B2AF */  sw         $s2, 0x18($sp)
    /* AB64 8001A364 1400B1AF */  sw         $s1, 0x14($sp)
    /* AB68 8001A368 1000B0AF */  sw         $s0, 0x10($sp)
  .L8001A36C:
    /* AB6C 8001A36C 08008386 */  lh         $v1, 0x8($s4)
    /* AB70 8001A370 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* AB74 8001A374 15006210 */  beq        $v1, $v0, .L8001A3CC
    /* AB78 8001A378 00000000 */   nop
    /* AB7C 8001A37C 0A008286 */  lh         $v0, 0xA($s4)
    /* AB80 8001A380 00000000 */  nop
    /* AB84 8001A384 11004018 */  blez       $v0, .L8001A3CC
    /* AB88 8001A388 21880000 */   addu      $s1, $zero, $zero
    /* AB8C 8001A38C 21908002 */  addu       $s2, $s4, $zero
  .L8001A390:
    /* AB90 8001A390 21800000 */  addu       $s0, $zero, $zero
    /* AB94 8001A394 21984002 */  addu       $s3, $s2, $zero
  .L8001A398:
    /* AB98 8001A398 0C006486 */  lh         $a0, 0xC($s3)
    /* AB9C 8001A39C 002C1000 */  sll        $a1, $s0, 16
    /* ABA0 8001A3A0 01001026 */  addiu      $s0, $s0, 0x1
    /* ABA4 8001A3A4 A7D5000C */  jal        SsSepStop
    /* ABA8 8001A3A8 032C0500 */   sra       $a1, $a1, 16
    /* ABAC 8001A3AC 1000022A */  slti       $v0, $s0, 0x10
    /* ABB0 8001A3B0 F9FF4014 */  bnez       $v0, .L8001A398
    /* ABB4 8001A3B4 00000000 */   nop
    /* ABB8 8001A3B8 0A008286 */  lh         $v0, 0xA($s4)
    /* ABBC 8001A3BC 01003126 */  addiu      $s1, $s1, 0x1
    /* ABC0 8001A3C0 2A102202 */  slt        $v0, $s1, $v0
    /* ABC4 8001A3C4 F2FF4014 */  bnez       $v0, .L8001A390
    /* ABC8 8001A3C8 02005226 */   addiu     $s2, $s2, 0x2
  .L8001A3CC:
    /* ABCC 8001A3CC 0100B526 */  addiu      $s5, $s5, 0x1
    /* ABD0 8001A3D0 0300A22A */  slti       $v0, $s5, 0x3
    /* ABD4 8001A3D4 E5FF4014 */  bnez       $v0, .L8001A36C
    /* ABD8 8001A3D8 2C009426 */   addiu     $s4, $s4, 0x2C
    /* ABDC 8001A3DC C1D7000C */  jal        SsUtAllKeyOff
    /* ABE0 8001A3E0 21200000 */   addu      $a0, $zero, $zero
    /* ABE4 8001A3E4 2800BF8F */  lw         $ra, 0x28($sp)
    /* ABE8 8001A3E8 2400B58F */  lw         $s5, 0x24($sp)
    /* ABEC 8001A3EC 2000B48F */  lw         $s4, 0x20($sp)
    /* ABF0 8001A3F0 1C00B38F */  lw         $s3, 0x1C($sp)
    /* ABF4 8001A3F4 1800B28F */  lw         $s2, 0x18($sp)
    /* ABF8 8001A3F8 1400B18F */  lw         $s1, 0x14($sp)
    /* ABFC 8001A3FC 1000B08F */  lw         $s0, 0x10($sp)
    /* AC00 8001A400 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* AC04 8001A404 200082AF */  sw         $v0, %gp_rel(Snd_CurrentId)($gp)
    /* AC08 8001A408 0800E003 */  jr         $ra
    /* AC0C 8001A40C 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel Snd_StopAll
