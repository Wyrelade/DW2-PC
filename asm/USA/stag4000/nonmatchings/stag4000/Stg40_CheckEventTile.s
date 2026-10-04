nonmatching Stg40_CheckEventTile, 0x98

glabel Stg40_CheckEventTile
    /* B36C 8006E6CC 21380000 */  addu       $a3, $zero, $zero
    /* B370 8006E6D0 0780043C */  lui        $a0, %hi(D_80072B60)
    /* B374 8006E6D4 602B838C */  lw         $v1, %lo(D_80072B60)($a0)
    /* B378 8006E6D8 2140E000 */  addu       $t0, $a3, $zero
    /* B37C 8006E6DC 6C01628C */  lw         $v0, 0x16C($v1)
    /* B380 8006E6E0 00000000 */  nop
    /* B384 8006E6E4 1D004010 */  beqz       $v0, .L8006E75C
    /* B388 8006E6E8 44016624 */   addiu     $a2, $v1, 0x144
    /* B38C 8006E6EC 21508000 */  addu       $t2, $a0, $zero
    /* B390 8006E6F0 FFFF0924 */  addiu      $t1, $zero, -0x1
    /* B394 8006E6F4 05800B3C */  lui        $t3, %hi(D_8005071C)
    /* B398 8006E6F8 02000C24 */  addiu      $t4, $zero, 0x2
    /* B39C 8006E6FC 46016524 */  addiu      $a1, $v1, 0x146
  .L8006E700:
    /* B3A0 8006E700 602B448D */  lw         $a0, %lo(D_80072B60)($t2)
    /* B3A4 8006E704 00000000 */  nop
    /* B3A8 8006E708 0400828C */  lw         $v0, 0x4($a0)
    /* B3AC 8006E70C 00000000 */  nop
    /* B3B0 8006E710 1800438C */  lw         $v1, 0x18($v0)
    /* B3B4 8006E714 0000C28C */  lw         $v0, 0x0($a2)
    /* B3B8 8006E718 00000000 */  nop
    /* B3BC 8006E71C 09006214 */  bne        $v1, $v0, .L8006E744
    /* B3C0 8006E720 0100E724 */   addiu     $a3, $a3, 0x1
    /* B3C4 8006E724 0200A28C */  lw         $v0, 0x2($a1)
    /* B3C8 8006E728 1C07638D */  lw         $v1, %lo(D_8005071C)($t3)
    /* B3CC 8006E72C FFFF0824 */  addiu      $t0, $zero, -0x1
    /* B3D0 8006E730 700182AC */  sw         $v0, 0x170($a0)
    /* B3D4 8006E734 0000A9A4 */  sh         $t1, 0x0($a1)
    /* B3D8 8006E738 0000C9A4 */  sh         $t1, 0x0($a2)
    /* B3DC 8006E73C D7B90108 */  j          .L8006E75C
    /* B3E0 8006E740 02006CA0 */   sb        $t4, 0x2($v1)
  .L8006E744:
    /* B3E4 8006E744 0800A524 */  addiu      $a1, $a1, 0x8
    /* B3E8 8006E748 6C01828C */  lw         $v0, 0x16C($a0)
    /* B3EC 8006E74C 00000000 */  nop
    /* B3F0 8006E750 2B10E200 */  sltu       $v0, $a3, $v0
    /* B3F4 8006E754 EAFF4014 */  bnez       $v0, .L8006E700
    /* B3F8 8006E758 0800C624 */   addiu     $a2, $a2, 0x8
  .L8006E75C:
    /* B3FC 8006E75C 0800E003 */  jr         $ra
    /* B400 8006E760 21100001 */   addu      $v0, $t0, $zero
endlabel Stg40_CheckEventTile
