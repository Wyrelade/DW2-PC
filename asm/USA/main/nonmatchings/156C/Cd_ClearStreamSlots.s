nonmatching Cd_ClearStreamSlots, 0x34

glabel Cd_ClearStreamSlots
    /* 1E9A4 8002E1A4 0A00A010 */  beqz       $a1, .L8002E1D0
    /* 1E9A8 8002E1A8 21300000 */   addu      $a2, $zero, $zero
  .L8002E1AC:
    /* 1E9AC 8002E1AC 2110C400 */  addu       $v0, $a2, $a0
    /* 1E9B0 8002E1B0 0100C624 */  addiu      $a2, $a2, 0x1
    /* 1E9B4 8002E1B4 0680033C */  lui        $v1, %hi(D_80061B38)
    /* 1E9B8 8002E1B8 381B638C */  lw         $v1, %lo(D_80061B38)($v1)
    /* 1E9BC 8002E1BC 40110200 */  sll        $v0, $v0, 5
    /* 1E9C0 8002E1C0 21186200 */  addu       $v1, $v1, $v0
    /* 1E9C4 8002E1C4 2B10C500 */  sltu       $v0, $a2, $a1
    /* 1E9C8 8002E1C8 F8FF4014 */  bnez       $v0, .L8002E1AC
    /* 1E9CC 8002E1CC 000060AC */   sw        $zero, 0x0($v1)
  .L8002E1D0:
    /* 1E9D0 8002E1D0 0800E003 */  jr         $ra
    /* 1E9D4 8002E1D4 00000000 */   nop
endlabel Cd_ClearStreamSlots
    /* 1E9D8 8002E1D8 00000000 */  nop
    /* 1E9DC 8002E1DC 00000000 */  nop
    /* 1E9E0 8002E1E0 00000000 */  nop
