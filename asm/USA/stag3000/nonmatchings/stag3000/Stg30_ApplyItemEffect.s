nonmatching Stg30_ApplyItemEffect, 0x6B8

glabel Stg30_ApplyItemEffect
    /* A178 8006D4D8 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* A17C 8006D4DC 2000B4AF */  sw         $s4, 0x20($sp)
    /* A180 8006D4E0 21A08000 */  addu       $s4, $a0, $zero
    /* A184 8006D4E4 2800B6AF */  sw         $s6, 0x28($sp)
    /* A188 8006D4E8 21B0A000 */  addu       $s6, $a1, $zero
    /* A18C 8006D4EC 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* A190 8006D4F0 2198C000 */  addu       $s3, $a2, $zero
    /* A194 8006D4F4 2400B5AF */  sw         $s5, 0x24($sp)
    /* A198 8006D4F8 21A8E000 */  addu       $s5, $a3, $zero
    /* A19C 8006D4FC 40101400 */  sll        $v0, $s4, 1
    /* A1A0 8006D500 21105400 */  addu       $v0, $v0, $s4
    /* A1A4 8006D504 C0100200 */  sll        $v0, $v0, 3
    /* A1A8 8006D508 23105400 */  subu       $v0, $v0, $s4
    /* A1AC 8006D50C 80100200 */  sll        $v0, $v0, 2
    /* A1B0 8006D510 0780033C */  lui        $v1, %hi(D_80073CD8)
    /* A1B4 8006D514 D83C6324 */  addiu      $v1, $v1, %lo(D_80073CD8)
    /* A1B8 8006D518 1000B0AF */  sw         $s0, 0x10($sp)
    /* A1BC 8006D51C 21804300 */  addu       $s0, $v0, $v1
    /* A1C0 8006D520 80101400 */  sll        $v0, $s4, 2
    /* A1C4 8006D524 04036324 */  addiu      $v1, $v1, 0x304
    /* A1C8 8006D528 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* A1CC 8006D52C 1800B2AF */  sw         $s2, 0x18($sp)
    /* A1D0 8006D530 1400B1AF */  sw         $s1, 0x14($sp)
    /* A1D4 8006D534 01000492 */  lbu        $a0, 0x1($s0)
    /* A1D8 8006D538 4D76000C */  jal        Digi_GetType
    /* A1DC 8006D53C 21904300 */   addu      $s2, $v0, $v1
    /* A1E0 8006D540 21884000 */  addu       $s1, $v0, $zero
    /* A1E4 8006D544 03FFC326 */  addiu      $v1, $s6, -0xFD
    /* A1E8 8006D548 3100622C */  sltiu      $v0, $v1, 0x31
    /* A1EC 8006D54C 39004010 */  beqz       $v0, .L8006D634
    /* A1F0 8006D550 0680023C */   lui       $v0, %hi(jtbl_800635E0)
    /* A1F4 8006D554 E0354224 */  addiu      $v0, $v0, %lo(jtbl_800635E0)
    /* A1F8 8006D558 80180300 */  sll        $v1, $v1, 2
    /* A1FC 8006D55C 21186200 */  addu       $v1, $v1, $v0
    /* A200 8006D560 0000628C */  lw         $v0, 0x0($v1)
    /* A204 8006D564 00000000 */  nop
    /* A208 8006D568 08004000 */  jr         $v0
    /* A20C 8006D56C 00000000 */   nop
  jlabel .L8006D570
    /* A210 8006D570 8EB50108 */  j          .L8006D638
    /* A214 8006D574 28000524 */   addiu     $a1, $zero, 0x28
  jlabel .L8006D578
    /* A218 8006D578 8EB50108 */  j          .L8006D638
    /* A21C 8006D57C 50000524 */   addiu     $a1, $zero, 0x50
  jlabel .L8006D580
    /* A220 8006D580 8EB50108 */  j          .L8006D638
    /* A224 8006D584 A0000524 */   addiu     $a1, $zero, 0xA0
  jlabel .L8006D588
    /* A228 8006D588 14002012 */  beqz       $s1, .L8006D5DC
    /* A22C 8006D58C 21280000 */   addu      $a1, $zero, $zero
    /* A230 8006D590 83B50108 */  j          .L8006D60C
    /* A234 8006D594 04000224 */   addiu     $v0, $zero, 0x4
  jlabel .L8006D598
    /* A238 8006D598 17002012 */  beqz       $s1, .L8006D5F8
    /* A23C 8006D59C 21280000 */   addu      $a1, $zero, $zero
    /* A240 8006D5A0 83B50108 */  j          .L8006D60C
    /* A244 8006D5A4 04000224 */   addiu     $v0, $zero, 0x4
  jlabel .L8006D5A8
    /* A248 8006D5A8 01000224 */  addiu      $v0, $zero, 0x1
    /* A24C 8006D5AC 0B002212 */  beq        $s1, $v0, .L8006D5DC
    /* A250 8006D5B0 21280000 */   addu      $a1, $zero, $zero
    /* A254 8006D5B4 83B50108 */  j          .L8006D60C
    /* A258 8006D5B8 04000224 */   addiu     $v0, $zero, 0x4
  jlabel .L8006D5BC
    /* A25C 8006D5BC 01000224 */  addiu      $v0, $zero, 0x1
    /* A260 8006D5C0 0D002212 */  beq        $s1, $v0, .L8006D5F8
    /* A264 8006D5C4 21280000 */   addu      $a1, $zero, $zero
    /* A268 8006D5C8 83B50108 */  j          .L8006D60C
    /* A26C 8006D5CC 04000224 */   addiu     $v0, $zero, 0x4
  jlabel .L8006D5D0
    /* A270 8006D5D0 02000224 */  addiu      $v0, $zero, 0x2
    /* A274 8006D5D4 0C002216 */  bne        $s1, $v0, .L8006D608
    /* A278 8006D5D8 21280000 */   addu      $a1, $zero, $zero
  .L8006D5DC:
    /* A27C 8006D5DC 14000386 */  lh         $v1, 0x14($s0)
    /* A280 8006D5E0 16000286 */  lh         $v0, 0x16($s0)
    /* A284 8006D5E4 8EB50108 */  j          .L8006D638
    /* A288 8006D5E8 23286200 */   subu      $a1, $v1, $v0
  jlabel .L8006D5EC
    /* A28C 8006D5EC 02000224 */  addiu      $v0, $zero, 0x2
    /* A290 8006D5F0 05002216 */  bne        $s1, $v0, .L8006D608
    /* A294 8006D5F4 21280000 */   addu      $a1, $zero, $zero
  .L8006D5F8:
    /* A298 8006D5F8 18000386 */  lh         $v1, 0x18($s0)
    /* A29C 8006D5FC 1A000286 */  lh         $v0, 0x1A($s0)
    /* A2A0 8006D600 8EB50108 */  j          .L8006D638
    /* A2A4 8006D604 23286200 */   subu      $a1, $v1, $v0
  .L8006D608:
    /* A2A8 8006D608 04000224 */  addiu      $v0, $zero, 0x4
  .L8006D60C:
    /* A2AC 8006D60C 8EB50108 */  j          .L8006D638
    /* A2B0 8006D610 000062A6 */   sh        $v0, 0x0($s3)
  jlabel .L8006D614
    /* A2B4 8006D614 21208002 */  addu       $a0, $s4, $zero
    /* A2B8 8006D618 0680023C */  lui        $v0, %hi(D_8005E65E)
    /* A2BC 8006D61C 5EE64694 */  lhu        $a2, %lo(D_8005E65E)($v0)
    /* A2C0 8006D620 2128C002 */  addu       $a1, $s6, $zero
    /* A2C4 8006D624 BBB4010C */  jal        Stg30_CalcCannonDamage
    /* A2C8 8006D628 A0FFC624 */   addiu     $a2, $a2, -0x60
    /* A2CC 8006D62C 8EB50108 */  j          .L8006D638
    /* A2D0 8006D630 21284000 */   addu      $a1, $v0, $zero
  jlabel .L8006D634
    /* A2D4 8006D634 21280000 */  addu       $a1, $zero, $zero
  .L8006D638:
    /* A2D8 8006D638 03FFC326 */  addiu      $v1, $s6, -0xFD
    /* A2DC 8006D63C 3100622C */  sltiu      $v0, $v1, 0x31
    /* A2E0 8006D640 48014010 */  beqz       $v0, .L8006DB64
    /* A2E4 8006D644 0680023C */   lui       $v0, %hi(jtbl_800636A8)
    /* A2E8 8006D648 A8364224 */  addiu      $v0, $v0, %lo(jtbl_800636A8)
    /* A2EC 8006D64C 80180300 */  sll        $v1, $v1, 2
    /* A2F0 8006D650 21186200 */  addu       $v1, $v1, $v0
    /* A2F4 8006D654 0000628C */  lw         $v0, 0x0($v1)
    /* A2F8 8006D658 00000000 */  nop
    /* A2FC 8006D65C 08004000 */  jr         $v0
    /* A300 8006D660 00000000 */   nop
  jlabel .L8006D664
    /* A304 8006D664 16000296 */  lhu        $v0, 0x16($s0)
    /* A308 8006D668 14000386 */  lh         $v1, 0x14($s0)
    /* A30C 8006D66C 21104500 */  addu       $v0, $v0, $a1
    /* A310 8006D670 160002A6 */  sh         $v0, 0x16($s0)
    /* A314 8006D674 00140200 */  sll        $v0, $v0, 16
    /* A318 8006D678 03140200 */  sra        $v0, $v0, 16
    /* A31C 8006D67C 2A186200 */  slt        $v1, $v1, $v0
    /* A320 8006D680 14000296 */  lhu        $v0, 0x14($s0)
    /* A324 8006D684 37016010 */  beqz       $v1, .L8006DB64
    /* A328 8006D688 00000000 */   nop
    /* A32C 8006D68C D9B60108 */  j          .L8006DB64
    /* A330 8006D690 160002A6 */   sh        $v0, 0x16($s0)
  jlabel .L8006D694
    /* A334 8006D694 1A000296 */  lhu        $v0, 0x1A($s0)
    /* A338 8006D698 18000386 */  lh         $v1, 0x18($s0)
    /* A33C 8006D69C 21104500 */  addu       $v0, $v0, $a1
    /* A340 8006D6A0 1A0002A6 */  sh         $v0, 0x1A($s0)
    /* A344 8006D6A4 00140200 */  sll        $v0, $v0, 16
    /* A348 8006D6A8 03140200 */  sra        $v0, $v0, 16
    /* A34C 8006D6AC 2A186200 */  slt        $v1, $v1, $v0
    /* A350 8006D6B0 18000296 */  lhu        $v0, 0x18($s0)
    /* A354 8006D6B4 2B016010 */  beqz       $v1, .L8006DB64
    /* A358 8006D6B8 00000000 */   nop
    /* A35C 8006D6BC D9B60108 */  j          .L8006DB64
    /* A360 8006D6C0 1A0002A6 */   sh        $v0, 0x1A($s0)
  jlabel .L8006D6C4
    /* A364 8006D6C4 04000224 */  addiu      $v0, $zero, 0x4
    /* A368 8006D6C8 000062A6 */  sh         $v0, 0x0($s3)
    /* A36C 8006D6CC 02000224 */  addiu      $v0, $zero, 0x2
    /* A370 8006D6D0 0000A2A6 */  sh         $v0, 0x0($s5)
    /* A374 8006D6D4 0000428E */  lw         $v0, 0x0($s2)
    /* A378 8006D6D8 C4B50108 */  j          .L8006D710
    /* A37C 8006D6DC FEFF0324 */   addiu     $v1, $zero, -0x2
  jlabel .L8006D6E0
    /* A380 8006D6E0 04000224 */  addiu      $v0, $zero, 0x4
    /* A384 8006D6E4 000062A6 */  sh         $v0, 0x0($s3)
    /* A388 8006D6E8 0000A2A6 */  sh         $v0, 0x0($s5)
    /* A38C 8006D6EC 0000428E */  lw         $v0, 0x0($s2)
    /* A390 8006D6F0 C4B50108 */  j          .L8006D710
    /* A394 8006D6F4 FDFF0324 */   addiu     $v1, $zero, -0x3
  jlabel .L8006D6F8
    /* A398 8006D6F8 04000224 */  addiu      $v0, $zero, 0x4
    /* A39C 8006D6FC 000062A6 */  sh         $v0, 0x0($s3)
    /* A3A0 8006D700 06000224 */  addiu      $v0, $zero, 0x6
    /* A3A4 8006D704 0000A2A6 */  sh         $v0, 0x0($s5)
    /* A3A8 8006D708 0000428E */  lw         $v0, 0x0($s2)
    /* A3AC 8006D70C FBFF0324 */  addiu      $v1, $zero, -0x5
  .L8006D710:
    /* A3B0 8006D710 24104300 */  and        $v0, $v0, $v1
    /* A3B4 8006D714 D9B60108 */  j          .L8006DB64
    /* A3B8 8006D718 000042AE */   sw        $v0, 0x0($s2)
  jlabel .L8006D71C
    /* A3BC 8006D71C 04000224 */  addiu      $v0, $zero, 0x4
    /* A3C0 8006D720 000062A6 */  sh         $v0, 0x0($s3)
    /* A3C4 8006D724 0F010224 */  addiu      $v0, $zero, 0x10F
    /* A3C8 8006D728 0000A2A6 */  sh         $v0, 0x0($s5)
    /* A3CC 8006D72C D9B60108 */  j          .L8006DB64
    /* A3D0 8006D730 000040AE */   sw        $zero, 0x0($s2)
  jlabel .L8006D734
    /* A3D4 8006D734 04000224 */  addiu      $v0, $zero, 0x4
    /* A3D8 8006D738 000062A6 */  sh         $v0, 0x0($s3)
    /* A3DC 8006D73C 04020224 */  addiu      $v0, $zero, 0x204
    /* A3E0 8006D740 0000A2A6 */  sh         $v0, 0x0($s5)
    /* A3E4 8006D744 14000296 */  lhu        $v0, 0x14($s0)
    /* A3E8 8006D748 18000396 */  lhu        $v1, 0x18($s0)
    /* A3EC 8006D74C 160002A6 */  sh         $v0, 0x16($s0)
    /* A3F0 8006D750 D9B60108 */  j          .L8006DB64
    /* A3F4 8006D754 1A0003A6 */   sh        $v1, 0x1A($s0)
  jlabel .L8006D758
    /* A3F8 8006D758 0B002012 */  beqz       $s1, .L8006D788
    /* A3FC 8006D75C 04000224 */   addiu     $v0, $zero, 0x4
    /* A400 8006D760 D9B60108 */  j          .L8006DB64
    /* A404 8006D764 000062A6 */   sh        $v0, 0x0($s3)
  jlabel .L8006D768
    /* A408 8006D768 01000224 */  addiu      $v0, $zero, 0x1
    /* A40C 8006D76C 06002212 */  beq        $s1, $v0, .L8006D788
    /* A410 8006D770 04000224 */   addiu     $v0, $zero, 0x4
    /* A414 8006D774 D9B60108 */  j          .L8006DB64
    /* A418 8006D778 000062A6 */   sh        $v0, 0x0($s3)
  jlabel .L8006D77C
    /* A41C 8006D77C 02000224 */  addiu      $v0, $zero, 0x2
    /* A420 8006D780 EF002216 */  bne        $s1, $v0, .L8006DB40
    /* A424 8006D784 04000224 */   addiu     $v0, $zero, 0x4
  .L8006D788:
    /* A428 8006D788 14000296 */  lhu        $v0, 0x14($s0)
    /* A42C 8006D78C 00000000 */  nop
    /* A430 8006D790 160002A6 */  sh         $v0, 0x16($s0)
    /* A434 8006D794 18000224 */  addiu      $v0, $zero, 0x18
    /* A438 8006D798 D9B60108 */  j          .L8006DB64
    /* A43C 8006D79C 0000A2A6 */   sh        $v0, 0x0($s5)
  jlabel .L8006D7A0
    /* A440 8006D7A0 E6002016 */  bnez       $s1, .L8006DB3C
    /* A444 8006D7A4 EB51043C */   lui       $a0, (0x51EB851F >> 16)
    /* A448 8006D7A8 1E000386 */  lh         $v1, 0x1E($s0)
    /* A44C 8006D7AC 1F858434 */  ori        $a0, $a0, (0x51EB851F & 0xFFFF)
    /* A450 8006D7B0 00110300 */  sll        $v0, $v1, 4
    /* A454 8006D7B4 23104300 */  subu       $v0, $v0, $v1
    /* A458 8006D7B8 C0100200 */  sll        $v0, $v0, 3
    /* A45C 8006D7BC 18004400 */  mult       $v0, $a0
    /* A460 8006D7C0 C3170200 */  sra        $v0, $v0, 31
    /* A464 8006D7C4 10400000 */  mfhi       $t0
    /* A468 8006D7C8 43190800 */  sra        $v1, $t0, 5
    /* A46C 8006D7CC 23186200 */  subu       $v1, $v1, $v0
    /* A470 8006D7D0 0780023C */  lui        $v0, %hi(Stg30_Battle)
    /* A474 8006D7D4 C03C4224 */  addiu      $v0, $v0, %lo(Stg30_Battle)
    /* A478 8006D7D8 21108202 */  addu       $v0, $s4, $v0
    /* A47C 8006D7DC 1E0003A6 */  sh         $v1, 0x1E($s0)
    /* A480 8006D7E0 01000324 */  addiu      $v1, $zero, 0x1
    /* A484 8006D7E4 460343A0 */  sb         $v1, 0x346($v0)
    /* A488 8006D7E8 CEB60108 */  j          .L8006DB38
    /* A48C 8006D7EC 16000224 */   addiu     $v0, $zero, 0x16
  jlabel .L8006D7F0
    /* A490 8006D7F0 D2002016 */  bnez       $s1, .L8006DB3C
    /* A494 8006D7F4 EB51043C */   lui       $a0, (0x51EB851F >> 16)
    /* A498 8006D7F8 1E000386 */  lh         $v1, 0x1E($s0)
    /* A49C 8006D7FC 1F858434 */  ori        $a0, $a0, (0x51EB851F & 0xFFFF)
    /* A4A0 8006D800 80100300 */  sll        $v0, $v1, 2
    /* A4A4 8006D804 21104300 */  addu       $v0, $v0, $v1
    /* A4A8 8006D808 00110200 */  sll        $v0, $v0, 4
    /* A4AC 8006D80C 18004400 */  mult       $v0, $a0
    /* A4B0 8006D810 C3170200 */  sra        $v0, $v0, 31
    /* A4B4 8006D814 10400000 */  mfhi       $t0
    /* A4B8 8006D818 43190800 */  sra        $v1, $t0, 5
    /* A4BC 8006D81C 23186200 */  subu       $v1, $v1, $v0
    /* A4C0 8006D820 0780023C */  lui        $v0, %hi(Stg30_Battle)
    /* A4C4 8006D824 C03C4224 */  addiu      $v0, $v0, %lo(Stg30_Battle)
    /* A4C8 8006D828 21108202 */  addu       $v0, $s4, $v0
    /* A4CC 8006D82C 1E0003A6 */  sh         $v1, 0x1E($s0)
    /* A4D0 8006D830 01000324 */  addiu      $v1, $zero, 0x1
    /* A4D4 8006D834 400343A0 */  sb         $v1, 0x340($v0)
    /* A4D8 8006D838 CEB60108 */  j          .L8006DB38
    /* A4DC 8006D83C 0A000224 */   addiu     $v0, $zero, 0xA
  jlabel .L8006D840
    /* A4E0 8006D840 BE002016 */  bnez       $s1, .L8006DB3C
    /* A4E4 8006D844 EB51043C */   lui       $a0, (0x51EB851F >> 16)
    /* A4E8 8006D848 1C000386 */  lh         $v1, 0x1C($s0)
    /* A4EC 8006D84C 1F858434 */  ori        $a0, $a0, (0x51EB851F & 0xFFFF)
    /* A4F0 8006D850 00110300 */  sll        $v0, $v1, 4
    /* A4F4 8006D854 23104300 */  subu       $v0, $v0, $v1
    /* A4F8 8006D858 C0100200 */  sll        $v0, $v0, 3
    /* A4FC 8006D85C 18004400 */  mult       $v0, $a0
    /* A500 8006D860 C3170200 */  sra        $v0, $v0, 31
    /* A504 8006D864 10400000 */  mfhi       $t0
    /* A508 8006D868 43190800 */  sra        $v1, $t0, 5
    /* A50C 8006D86C 23186200 */  subu       $v1, $v1, $v0
    /* A510 8006D870 0780023C */  lui        $v0, %hi(Stg30_Battle)
    /* A514 8006D874 C03C4224 */  addiu      $v0, $v0, %lo(Stg30_Battle)
    /* A518 8006D878 21108202 */  addu       $v0, $s4, $v0
    /* A51C 8006D87C 1C0003A6 */  sh         $v1, 0x1C($s0)
    /* A520 8006D880 01000324 */  addiu      $v1, $zero, 0x1
    /* A524 8006D884 460343A0 */  sb         $v1, 0x346($v0)
    /* A528 8006D888 CEB60108 */  j          .L8006DB38
    /* A52C 8006D88C 15000224 */   addiu     $v0, $zero, 0x15
  jlabel .L8006D890
    /* A530 8006D890 AB002016 */  bnez       $s1, .L8006DB40
    /* A534 8006D894 04000224 */   addiu     $v0, $zero, 0x4
    /* A538 8006D898 EB51043C */  lui        $a0, (0x51EB851F >> 16)
    /* A53C 8006D89C 1C000386 */  lh         $v1, 0x1C($s0)
    /* A540 8006D8A0 1F858434 */  ori        $a0, $a0, (0x51EB851F & 0xFFFF)
    /* A544 8006D8A4 C0B60108 */  j          .L8006DB00
    /* A548 8006D8A8 80100300 */   sll       $v0, $v1, 2
  jlabel .L8006D8AC
    /* A54C 8006D8AC 01000224 */  addiu      $v0, $zero, 0x1
    /* A550 8006D8B0 A2002216 */  bne        $s1, $v0, .L8006DB3C
    /* A554 8006D8B4 EB51043C */   lui       $a0, (0x51EB851F >> 16)
    /* A558 8006D8B8 1E000386 */  lh         $v1, 0x1E($s0)
    /* A55C 8006D8BC 1F858434 */  ori        $a0, $a0, (0x51EB851F & 0xFFFF)
    /* A560 8006D8C0 00110300 */  sll        $v0, $v1, 4
    /* A564 8006D8C4 23104300 */  subu       $v0, $v0, $v1
    /* A568 8006D8C8 C0100200 */  sll        $v0, $v0, 3
    /* A56C 8006D8CC 18004400 */  mult       $v0, $a0
    /* A570 8006D8D0 C3170200 */  sra        $v0, $v0, 31
    /* A574 8006D8D4 10400000 */  mfhi       $t0
    /* A578 8006D8D8 43190800 */  sra        $v1, $t0, 5
    /* A57C 8006D8DC 23186200 */  subu       $v1, $v1, $v0
    /* A580 8006D8E0 0780023C */  lui        $v0, %hi(Stg30_Battle)
    /* A584 8006D8E4 C03C4224 */  addiu      $v0, $v0, %lo(Stg30_Battle)
    /* A588 8006D8E8 21108202 */  addu       $v0, $s4, $v0
    /* A58C 8006D8EC 1E0003A6 */  sh         $v1, 0x1E($s0)
    /* A590 8006D8F0 460351A0 */  sb         $s1, 0x346($v0)
    /* A594 8006D8F4 CEB60108 */  j          .L8006DB38
    /* A598 8006D8F8 16000224 */   addiu     $v0, $zero, 0x16
  jlabel .L8006D8FC
    /* A59C 8006D8FC 01000224 */  addiu      $v0, $zero, 0x1
    /* A5A0 8006D900 8E002216 */  bne        $s1, $v0, .L8006DB3C
    /* A5A4 8006D904 EB51043C */   lui       $a0, (0x51EB851F >> 16)
    /* A5A8 8006D908 1E000386 */  lh         $v1, 0x1E($s0)
    /* A5AC 8006D90C 1F858434 */  ori        $a0, $a0, (0x51EB851F & 0xFFFF)
    /* A5B0 8006D910 80100300 */  sll        $v0, $v1, 2
    /* A5B4 8006D914 21104300 */  addu       $v0, $v0, $v1
    /* A5B8 8006D918 00110200 */  sll        $v0, $v0, 4
    /* A5BC 8006D91C 18004400 */  mult       $v0, $a0
    /* A5C0 8006D920 C3170200 */  sra        $v0, $v0, 31
    /* A5C4 8006D924 10400000 */  mfhi       $t0
    /* A5C8 8006D928 43190800 */  sra        $v1, $t0, 5
    /* A5CC 8006D92C 23186200 */  subu       $v1, $v1, $v0
    /* A5D0 8006D930 0780023C */  lui        $v0, %hi(Stg30_Battle)
    /* A5D4 8006D934 C03C4224 */  addiu      $v0, $v0, %lo(Stg30_Battle)
    /* A5D8 8006D938 21108202 */  addu       $v0, $s4, $v0
    /* A5DC 8006D93C 1E0003A6 */  sh         $v1, 0x1E($s0)
    /* A5E0 8006D940 400351A0 */  sb         $s1, 0x340($v0)
    /* A5E4 8006D944 CEB60108 */  j          .L8006DB38
    /* A5E8 8006D948 0A000224 */   addiu     $v0, $zero, 0xA
  jlabel .L8006D94C
    /* A5EC 8006D94C 01000224 */  addiu      $v0, $zero, 0x1
    /* A5F0 8006D950 7A002216 */  bne        $s1, $v0, .L8006DB3C
    /* A5F4 8006D954 EB51043C */   lui       $a0, (0x51EB851F >> 16)
    /* A5F8 8006D958 1C000386 */  lh         $v1, 0x1C($s0)
    /* A5FC 8006D95C 1F858434 */  ori        $a0, $a0, (0x51EB851F & 0xFFFF)
    /* A600 8006D960 00110300 */  sll        $v0, $v1, 4
    /* A604 8006D964 23104300 */  subu       $v0, $v0, $v1
    /* A608 8006D968 C0100200 */  sll        $v0, $v0, 3
    /* A60C 8006D96C 18004400 */  mult       $v0, $a0
    /* A610 8006D970 C3170200 */  sra        $v0, $v0, 31
    /* A614 8006D974 10400000 */  mfhi       $t0
    /* A618 8006D978 43190800 */  sra        $v1, $t0, 5
    /* A61C 8006D97C 23186200 */  subu       $v1, $v1, $v0
    /* A620 8006D980 0780023C */  lui        $v0, %hi(Stg30_Battle)
    /* A624 8006D984 C03C4224 */  addiu      $v0, $v0, %lo(Stg30_Battle)
    /* A628 8006D988 21108202 */  addu       $v0, $s4, $v0
    /* A62C 8006D98C 1C0003A6 */  sh         $v1, 0x1C($s0)
    /* A630 8006D990 460351A0 */  sb         $s1, 0x346($v0)
    /* A634 8006D994 CEB60108 */  j          .L8006DB38
    /* A638 8006D998 15000224 */   addiu     $v0, $zero, 0x15
  jlabel .L8006D99C
    /* A63C 8006D99C 01000224 */  addiu      $v0, $zero, 0x1
    /* A640 8006D9A0 67002216 */  bne        $s1, $v0, .L8006DB40
    /* A644 8006D9A4 04000224 */   addiu     $v0, $zero, 0x4
    /* A648 8006D9A8 EB51043C */  lui        $a0, (0x51EB851F >> 16)
    /* A64C 8006D9AC 1C000386 */  lh         $v1, 0x1C($s0)
    /* A650 8006D9B0 1F858434 */  ori        $a0, $a0, (0x51EB851F & 0xFFFF)
    /* A654 8006D9B4 80100300 */  sll        $v0, $v1, 2
    /* A658 8006D9B8 21104300 */  addu       $v0, $v0, $v1
    /* A65C 8006D9BC 00110200 */  sll        $v0, $v0, 4
    /* A660 8006D9C0 18004400 */  mult       $v0, $a0
    /* A664 8006D9C4 C3170200 */  sra        $v0, $v0, 31
    /* A668 8006D9C8 10400000 */  mfhi       $t0
    /* A66C 8006D9CC 43190800 */  sra        $v1, $t0, 5
    /* A670 8006D9D0 23186200 */  subu       $v1, $v1, $v0
    /* A674 8006D9D4 0780023C */  lui        $v0, %hi(Stg30_Battle)
    /* A678 8006D9D8 C03C4224 */  addiu      $v0, $v0, %lo(Stg30_Battle)
    /* A67C 8006D9DC 21108202 */  addu       $v0, $s4, $v0
    /* A680 8006D9E0 1C0003A6 */  sh         $v1, 0x1C($s0)
    /* A684 8006D9E4 CDB60108 */  j          .L8006DB34
    /* A688 8006D9E8 400351A0 */   sb        $s1, 0x340($v0)
  jlabel .L8006D9EC
    /* A68C 8006D9EC 02000224 */  addiu      $v0, $zero, 0x2
    /* A690 8006D9F0 52002216 */  bne        $s1, $v0, .L8006DB3C
    /* A694 8006D9F4 EB51043C */   lui       $a0, (0x51EB851F >> 16)
    /* A698 8006D9F8 1E000386 */  lh         $v1, 0x1E($s0)
    /* A69C 8006D9FC 1F858434 */  ori        $a0, $a0, (0x51EB851F & 0xFFFF)
    /* A6A0 8006DA00 00110300 */  sll        $v0, $v1, 4
    /* A6A4 8006DA04 23104300 */  subu       $v0, $v0, $v1
    /* A6A8 8006DA08 C0100200 */  sll        $v0, $v0, 3
    /* A6AC 8006DA0C 18004400 */  mult       $v0, $a0
    /* A6B0 8006DA10 C3170200 */  sra        $v0, $v0, 31
    /* A6B4 8006DA14 10400000 */  mfhi       $t0
    /* A6B8 8006DA18 43190800 */  sra        $v1, $t0, 5
    /* A6BC 8006DA1C 23186200 */  subu       $v1, $v1, $v0
    /* A6C0 8006DA20 0780023C */  lui        $v0, %hi(Stg30_Battle)
    /* A6C4 8006DA24 C03C4224 */  addiu      $v0, $v0, %lo(Stg30_Battle)
    /* A6C8 8006DA28 21108202 */  addu       $v0, $s4, $v0
    /* A6CC 8006DA2C 1E0003A6 */  sh         $v1, 0x1E($s0)
    /* A6D0 8006DA30 01000324 */  addiu      $v1, $zero, 0x1
    /* A6D4 8006DA34 460343A0 */  sb         $v1, 0x346($v0)
    /* A6D8 8006DA38 CEB60108 */  j          .L8006DB38
    /* A6DC 8006DA3C 16000224 */   addiu     $v0, $zero, 0x16
  jlabel .L8006DA40
    /* A6E0 8006DA40 02000224 */  addiu      $v0, $zero, 0x2
    /* A6E4 8006DA44 3D002216 */  bne        $s1, $v0, .L8006DB3C
    /* A6E8 8006DA48 EB51043C */   lui       $a0, (0x51EB851F >> 16)
    /* A6EC 8006DA4C 1E000386 */  lh         $v1, 0x1E($s0)
    /* A6F0 8006DA50 1F858434 */  ori        $a0, $a0, (0x51EB851F & 0xFFFF)
    /* A6F4 8006DA54 04104300 */  sllv       $v0, $v1, $v0
    /* A6F8 8006DA58 21104300 */  addu       $v0, $v0, $v1
    /* A6FC 8006DA5C 00110200 */  sll        $v0, $v0, 4
    /* A700 8006DA60 18004400 */  mult       $v0, $a0
    /* A704 8006DA64 C3170200 */  sra        $v0, $v0, 31
    /* A708 8006DA68 10400000 */  mfhi       $t0
    /* A70C 8006DA6C 43190800 */  sra        $v1, $t0, 5
    /* A710 8006DA70 23186200 */  subu       $v1, $v1, $v0
    /* A714 8006DA74 0780023C */  lui        $v0, %hi(Stg30_Battle)
    /* A718 8006DA78 C03C4224 */  addiu      $v0, $v0, %lo(Stg30_Battle)
    /* A71C 8006DA7C 21108202 */  addu       $v0, $s4, $v0
    /* A720 8006DA80 1E0003A6 */  sh         $v1, 0x1E($s0)
    /* A724 8006DA84 01000324 */  addiu      $v1, $zero, 0x1
    /* A728 8006DA88 400343A0 */  sb         $v1, 0x340($v0)
    /* A72C 8006DA8C CEB60108 */  j          .L8006DB38
    /* A730 8006DA90 0A000224 */   addiu     $v0, $zero, 0xA
  jlabel .L8006DA94
    /* A734 8006DA94 02000224 */  addiu      $v0, $zero, 0x2
    /* A738 8006DA98 28002216 */  bne        $s1, $v0, .L8006DB3C
    /* A73C 8006DA9C EB51043C */   lui       $a0, (0x51EB851F >> 16)
    /* A740 8006DAA0 1C000386 */  lh         $v1, 0x1C($s0)
    /* A744 8006DAA4 1F858434 */  ori        $a0, $a0, (0x51EB851F & 0xFFFF)
    /* A748 8006DAA8 00110300 */  sll        $v0, $v1, 4
    /* A74C 8006DAAC 23104300 */  subu       $v0, $v0, $v1
    /* A750 8006DAB0 C0100200 */  sll        $v0, $v0, 3
    /* A754 8006DAB4 18004400 */  mult       $v0, $a0
    /* A758 8006DAB8 C3170200 */  sra        $v0, $v0, 31
    /* A75C 8006DABC 10400000 */  mfhi       $t0
    /* A760 8006DAC0 43190800 */  sra        $v1, $t0, 5
    /* A764 8006DAC4 23186200 */  subu       $v1, $v1, $v0
    /* A768 8006DAC8 0780023C */  lui        $v0, %hi(Stg30_Battle)
    /* A76C 8006DACC C03C4224 */  addiu      $v0, $v0, %lo(Stg30_Battle)
    /* A770 8006DAD0 21108202 */  addu       $v0, $s4, $v0
    /* A774 8006DAD4 1C0003A6 */  sh         $v1, 0x1C($s0)
    /* A778 8006DAD8 01000324 */  addiu      $v1, $zero, 0x1
    /* A77C 8006DADC 460343A0 */  sb         $v1, 0x346($v0)
    /* A780 8006DAE0 CEB60108 */  j          .L8006DB38
    /* A784 8006DAE4 15000224 */   addiu     $v0, $zero, 0x15
  jlabel .L8006DAE8
    /* A788 8006DAE8 02000224 */  addiu      $v0, $zero, 0x2
    /* A78C 8006DAEC 13002216 */  bne        $s1, $v0, .L8006DB3C
    /* A790 8006DAF0 EB51043C */   lui       $a0, (0x51EB851F >> 16)
    /* A794 8006DAF4 1C000386 */  lh         $v1, 0x1C($s0)
    /* A798 8006DAF8 1F858434 */  ori        $a0, $a0, (0x51EB851F & 0xFFFF)
    /* A79C 8006DAFC 04104300 */  sllv       $v0, $v1, $v0
  .L8006DB00:
    /* A7A0 8006DB00 21104300 */  addu       $v0, $v0, $v1
    /* A7A4 8006DB04 00110200 */  sll        $v0, $v0, 4
    /* A7A8 8006DB08 18004400 */  mult       $v0, $a0
    /* A7AC 8006DB0C C3170200 */  sra        $v0, $v0, 31
    /* A7B0 8006DB10 10400000 */  mfhi       $t0
    /* A7B4 8006DB14 43190800 */  sra        $v1, $t0, 5
    /* A7B8 8006DB18 23186200 */  subu       $v1, $v1, $v0
    /* A7BC 8006DB1C 0780023C */  lui        $v0, %hi(Stg30_Battle)
    /* A7C0 8006DB20 C03C4224 */  addiu      $v0, $v0, %lo(Stg30_Battle)
    /* A7C4 8006DB24 21108202 */  addu       $v0, $s4, $v0
    /* A7C8 8006DB28 1C0003A6 */  sh         $v1, 0x1C($s0)
    /* A7CC 8006DB2C 01000324 */  addiu      $v1, $zero, 0x1
    /* A7D0 8006DB30 400343A0 */  sb         $v1, 0x340($v0)
  .L8006DB34:
    /* A7D4 8006DB34 09000224 */  addiu      $v0, $zero, 0x9
  .L8006DB38:
    /* A7D8 8006DB38 0000A2A6 */  sh         $v0, 0x0($s5)
  .L8006DB3C:
    /* A7DC 8006DB3C 04000224 */  addiu      $v0, $zero, 0x4
  .L8006DB40:
    /* A7E0 8006DB40 D9B60108 */  j          .L8006DB64
    /* A7E4 8006DB44 000062A6 */   sh        $v0, 0x0($s3)
  jlabel .L8006DB48
    /* A7E8 8006DB48 16000286 */  lh         $v0, 0x16($s0)
    /* A7EC 8006DB4C 16000396 */  lhu        $v1, 0x16($s0)
    /* A7F0 8006DB50 2A104500 */  slt        $v0, $v0, $a1
    /* A7F4 8006DB54 02004014 */  bnez       $v0, .L8006DB60
    /* A7F8 8006DB58 21100000 */   addu      $v0, $zero, $zero
    /* A7FC 8006DB5C 23106500 */  subu       $v0, $v1, $a1
  .L8006DB60:
    /* A800 8006DB60 160002A6 */  sh         $v0, 0x16($s0)
  .L8006DB64:
    /* A804 8006DB64 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* A808 8006DB68 2800B68F */  lw         $s6, 0x28($sp)
    /* A80C 8006DB6C 2400B58F */  lw         $s5, 0x24($sp)
    /* A810 8006DB70 2000B48F */  lw         $s4, 0x20($sp)
    /* A814 8006DB74 1C00B38F */  lw         $s3, 0x1C($sp)
    /* A818 8006DB78 1800B28F */  lw         $s2, 0x18($sp)
    /* A81C 8006DB7C 1400B18F */  lw         $s1, 0x14($sp)
    /* A820 8006DB80 1000B08F */  lw         $s0, 0x10($sp)
    /* A824 8006DB84 2110A000 */  addu       $v0, $a1, $zero
    /* A828 8006DB88 0800E003 */  jr         $ra
    /* A82C 8006DB8C 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel Stg30_ApplyItemEffect
