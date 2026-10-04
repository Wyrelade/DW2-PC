nonmatching Snd_StopById, 0x98

glabel Snd_StopById
    /* AC10 8001A410 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* AC14 8001A414 1000B0AF */  sw         $s0, 0x10($sp)
    /* AC18 8001A418 21808000 */  addu       $s0, $a0, $zero
    /* AC1C 8001A41C 1400B1AF */  sw         $s1, 0x14($sp)
    /* AC20 8001A420 FFFF1124 */  addiu      $s1, $zero, -0x1
    /* AC24 8001A424 1B001112 */  beq        $s0, $s1, .L8001A494
    /* AC28 8001A428 1800BFAF */   sw        $ra, 0x18($sp)
    /* AC2C 8001A42C 031A1000 */  sra        $v1, $s0, 8
    /* AC30 8001A430 03111000 */  sra        $v0, $s0, 4
    /* AC34 8001A434 0F004430 */  andi       $a0, $v0, 0xF
    /* AC38 8001A438 0580023C */  lui        $v0, %hi(Snd_Slots)
    /* AC3C 8001A43C 484C4624 */  addiu      $a2, $v0, %lo(Snd_Slots)
    /* AC40 8001A440 40100300 */  sll        $v0, $v1, 1
    /* AC44 8001A444 21104300 */  addu       $v0, $v0, $v1
    /* AC48 8001A448 80100200 */  sll        $v0, $v0, 2
    /* AC4C 8001A44C 23104300 */  subu       $v0, $v0, $v1
    /* AC50 8001A450 80180200 */  sll        $v1, $v0, 2
    /* AC54 8001A454 21106600 */  addu       $v0, $v1, $a2
    /* AC58 8001A458 0400428C */  lw         $v0, 0x4($v0)
    /* AC5C 8001A45C 00000000 */  nop
    /* AC60 8001A460 07004014 */  bnez       $v0, .L8001A480
    /* AC64 8001A464 0F000532 */   andi      $a1, $s0, 0xF
    /* AC68 8001A468 40100400 */  sll        $v0, $a0, 1
    /* AC6C 8001A46C 21104300 */  addu       $v0, $v0, $v1
    /* AC70 8001A470 21104600 */  addu       $v0, $v0, $a2
    /* AC74 8001A474 0C004484 */  lh         $a0, 0xC($v0)
    /* AC78 8001A478 A7D5000C */  jal        SsSepStop
    /* AC7C 8001A47C 00000000 */   nop
  .L8001A480:
    /* AC80 8001A480 2000828F */  lw         $v0, %gp_rel(Snd_CurrentId)($gp)
    /* AC84 8001A484 00000000 */  nop
    /* AC88 8001A488 02005014 */  bne        $v0, $s0, .L8001A494
    /* AC8C 8001A48C 00000000 */   nop
    /* AC90 8001A490 200091AF */  sw         $s1, %gp_rel(Snd_CurrentId)($gp)
  .L8001A494:
    /* AC94 8001A494 1800BF8F */  lw         $ra, 0x18($sp)
    /* AC98 8001A498 1400B18F */  lw         $s1, 0x14($sp)
    /* AC9C 8001A49C 1000B08F */  lw         $s0, 0x10($sp)
    /* ACA0 8001A4A0 0800E003 */  jr         $ra
    /* ACA4 8001A4A4 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Snd_StopById
