nonmatching func_8006E690, 0xE0

glabel func_8006E690
    /* B330 8006E690 21400000 */  addu       $t0, $zero, $zero
    /* B334 8006E694 0780023C */  lui        $v0, %hi(D_80073CC0)
    /* B338 8006E698 C03C4624 */  addiu      $a2, $v0, %lo(D_80073CC0)
    /* B33C 8006E69C 2168C000 */  addu       $t5, $a2, $zero
    /* B340 8006E6A0 0780023C */  lui        $v0, %hi(D_80073A50)
    /* B344 8006E6A4 503A4C24 */  addiu      $t4, $v0, %lo(D_80073A50)
    /* B348 8006E6A8 21288001 */  addu       $a1, $t4, $zero
    /* B34C 8006E6AC 2150C000 */  addu       $t2, $a2, $zero
    /* B350 8006E6B0 2148A000 */  addu       $t1, $a1, $zero
    /* B354 8006E6B4 21384001 */  addu       $a3, $t2, $zero
    /* B358 8006E6B8 21582001 */  addu       $t3, $t1, $zero
  .L8006E6BC:
    /* B35C 8006E6BC 21186001 */  addu       $v1, $t3, $zero
    /* B360 8006E6C0 1800E224 */  addiu      $v0, $a3, 0x18
    /* B364 8006E6C4 6800E424 */  addiu      $a0, $a3, 0x68
  .L8006E6C8:
    /* B368 8006E6C8 00004E8C */  lw         $t6, 0x0($v0)
    /* B36C 8006E6CC 04004F8C */  lw         $t7, 0x4($v0)
    /* B370 8006E6D0 0800588C */  lw         $t8, 0x8($v0)
    /* B374 8006E6D4 0C00598C */  lw         $t9, 0xC($v0)
    /* B378 8006E6D8 00006EAC */  sw         $t6, 0x0($v1)
    /* B37C 8006E6DC 04006FAC */  sw         $t7, 0x4($v1)
    /* B380 8006E6E0 080078AC */  sw         $t8, 0x8($v1)
    /* B384 8006E6E4 0C0079AC */  sw         $t9, 0xC($v1)
    /* B388 8006E6E8 10004224 */  addiu      $v0, $v0, 0x10
    /* B38C 8006E6EC F6FF4414 */  bne        $v0, $a0, .L8006E6C8
    /* B390 8006E6F0 10006324 */   addiu     $v1, $v1, 0x10
    /* B394 8006E6F4 00004E8C */  lw         $t6, 0x0($v0)
    /* B398 8006E6F8 04004F8C */  lw         $t7, 0x4($v0)
    /* B39C 8006E6FC 0800588C */  lw         $t8, 0x8($v0)
    /* B3A0 8006E700 00006EAC */  sw         $t6, 0x0($v1)
    /* B3A4 8006E704 04006FAC */  sw         $t7, 0x4($v1)
    /* B3A8 8006E708 080078AC */  sw         $t8, 0x8($v1)
    /* B3AC 8006E70C 1C03428D */  lw         $v0, 0x31C($t2)
    /* B3B0 8006E710 04004A25 */  addiu      $t2, $t2, 0x4
    /* B3B4 8006E714 5C00E724 */  addiu      $a3, $a3, 0x5C
    /* B3B8 8006E718 21180D01 */  addu       $v1, $t0, $t5
    /* B3BC 8006E71C 280222AD */  sw         $v0, 0x228($t1)
    /* B3C0 8006E720 40036290 */  lbu        $v0, 0x340($v1)
    /* B3C4 8006E724 21200C01 */  addu       $a0, $t0, $t4
    /* B3C8 8006E728 400282A0 */  sb         $v0, 0x240($a0)
    /* B3CC 8006E72C 46036290 */  lbu        $v0, 0x346($v1)
    /* B3D0 8006E730 5C006B25 */  addiu      $t3, $t3, 0x5C
    /* B3D4 8006E734 460282A0 */  sb         $v0, 0x246($a0)
    /* B3D8 8006E738 5603C294 */  lhu        $v0, 0x356($a2)
    /* B3DC 8006E73C 01000825 */  addiu      $t0, $t0, 0x1
    /* B3E0 8006E740 4C02A2A4 */  sh         $v0, 0x24C($a1)
    /* B3E4 8006E744 6203C294 */  lhu        $v0, 0x362($a2)
    /* B3E8 8006E748 04002925 */  addiu      $t1, $t1, 0x4
    /* B3EC 8006E74C 5802A2A4 */  sh         $v0, 0x258($a1)
    /* B3F0 8006E750 6E03C294 */  lhu        $v0, 0x36E($a2)
    /* B3F4 8006E754 0200C624 */  addiu      $a2, $a2, 0x2
    /* B3F8 8006E758 6402A2A4 */  sh         $v0, 0x264($a1)
    /* B3FC 8006E75C 06000229 */  slti       $v0, $t0, 0x6
    /* B400 8006E760 D6FF4014 */  bnez       $v0, .L8006E6BC
    /* B404 8006E764 0200A524 */   addiu     $a1, $a1, 0x2
    /* B408 8006E768 0800E003 */  jr         $ra
    /* B40C 8006E76C 00000000 */   nop
endlabel func_8006E690
