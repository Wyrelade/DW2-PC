nonmatching func_8006A6EC, 0x15C

glabel func_8006A6EC
    /* 738C 8006A6EC 0780023C */  lui        $v0, %hi(D_80072B60)
    /* 7390 8006A6F0 602B428C */  lw         $v0, %lo(D_80072B60)($v0)
    /* 7394 8006A6F4 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 7398 8006A6F8 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 739C 8006A6FC 21988000 */  addu       $s3, $a0, $zero
    /* 73A0 8006A700 2000BFAF */  sw         $ra, 0x20($sp)
    /* 73A4 8006A704 1800B2AF */  sw         $s2, 0x18($sp)
    /* 73A8 8006A708 1400B1AF */  sw         $s1, 0x14($sp)
    /* 73AC 8006A70C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 73B0 8006A710 3C00528C */  lw         $s2, 0x3C($v0)
    /* 73B4 8006A714 4000428C */  lw         $v0, 0x40($v0)
    /* 73B8 8006A718 1800708E */  lw         $s0, 0x18($s3)
    /* 73BC 8006A71C 1000518C */  lw         $s1, 0x10($v0)
    /* 73C0 8006A720 03000012 */  beqz       $s0, .L8006A730
    /* 73C4 8006A724 01000224 */   addiu     $v0, $zero, 0x1
    /* 73C8 8006A728 3A000212 */  beq        $s0, $v0, .L8006A814
    /* 73CC 8006A72C 00000000 */   nop
  .L8006A730:
    /* 73D0 8006A730 00002292 */  lbu        $v0, 0x0($s1)
    /* 73D4 8006A734 00000000 */  nop
    /* 73D8 8006A738 0B004014 */  bnez       $v0, .L8006A768
    /* 73DC 8006A73C 01000424 */   addiu     $a0, $zero, 0x1
    /* 73E0 8006A740 FD01053C */  lui        $a1, (0x1FD004E >> 16)
    /* 73E4 8006A744 4E00A534 */  ori        $a1, $a1, (0x1FD004E & 0xFFFF)
    /* 73E8 8006A748 21300000 */  addu       $a2, $zero, $zero
    /* 73EC 8006A74C 849D010C */  jal        func_80067610
    /* 73F0 8006A750 2138C000 */   addu      $a3, $a2, $zero
    /* 73F4 8006A754 21204002 */  addu       $a0, $s2, $zero
    /* 73F8 8006A758 7745000C */  jal        Task_SetState1
    /* 73FC 8006A75C 05000524 */   addiu     $a1, $zero, 0x5
    /* 7400 8006A760 01AA0108 */  j          .L8006A804
    /* 7404 8006A764 00000000 */   nop
  .L8006A768:
    /* 7408 8006A768 00002492 */  lbu        $a0, 0x0($s1)
    /* 740C 8006A76C EA89000C */  jal        Item_AddToBag
    /* 7410 8006A770 00000000 */   nop
    /* 7414 8006A774 FFFF0324 */  addiu      $v1, $zero, -0x1
    /* 7418 8006A778 11004314 */  bne        $v0, $v1, .L8006A7C0
    /* 741C 8006A77C 00000000 */   nop
    /* 7420 8006A780 00002492 */  lbu        $a0, 0x0($s1)
    /* 7424 8006A784 1278000C */  jal        Item_GetNameText
    /* 7428 8006A788 00000000 */   nop
    /* 742C 8006A78C 01000424 */  addiu      $a0, $zero, 0x1
    /* 7430 8006A790 FD01053C */  lui        $a1, (0x1FD0055 >> 16)
    /* 7434 8006A794 5500A534 */  ori        $a1, $a1, (0x1FD0055 & 0xFFFF)
    /* 7438 8006A798 21304000 */  addu       $a2, $v0, $zero
    /* 743C 8006A79C 849D010C */  jal        func_80067610
    /* 7440 8006A7A0 21380000 */   addu      $a3, $zero, $zero
    /* 7444 8006A7A4 1C000424 */  addiu      $a0, $zero, 0x1C
    /* 7448 8006A7A8 21280000 */  addu       $a1, $zero, $zero
    /* 744C 8006A7AC FF000224 */  addiu      $v0, $zero, 0xFF
    /* 7450 8006A7B0 A369000C */  jal        Snd_PlayById
    /* 7454 8006A7B4 010022A2 */   sb        $v0, 0x1($s1)
    /* 7458 8006A7B8 01AA0108 */  j          .L8006A804
    /* 745C 8006A7BC 00000000 */   nop
  .L8006A7C0:
    /* 7460 8006A7C0 00002492 */  lbu        $a0, 0x0($s1)
    /* 7464 8006A7C4 1278000C */  jal        Item_GetNameText
    /* 7468 8006A7C8 00000000 */   nop
    /* 746C 8006A7CC 01000424 */  addiu      $a0, $zero, 0x1
    /* 7470 8006A7D0 FD01053C */  lui        $a1, (0x1FD004D >> 16)
    /* 7474 8006A7D4 4D00A534 */  ori        $a1, $a1, (0x1FD004D & 0xFFFF)
    /* 7478 8006A7D8 21304000 */  addu       $a2, $v0, $zero
    /* 747C 8006A7DC 849D010C */  jal        func_80067610
    /* 7480 8006A7E0 21380000 */   addu      $a3, $zero, $zero
    /* 7484 8006A7E4 21204002 */  addu       $a0, $s2, $zero
    /* 7488 8006A7E8 7745000C */  jal        Task_SetState1
    /* 748C 8006A7EC 05000524 */   addiu     $a1, $zero, 0x5
    /* 7490 8006A7F0 19000424 */  addiu      $a0, $zero, 0x19
    /* 7494 8006A7F4 A369000C */  jal        Snd_PlayById
    /* 7498 8006A7F8 21280000 */   addu      $a1, $zero, $zero
    /* 749C 8006A7FC AB89000C */  jal        Item_SortList
    /* 74A0 8006A800 00000000 */   nop
  .L8006A804:
    /* 74A4 8006A804 6045000C */  jal        Task_NextState2
    /* 74A8 8006A808 21206002 */   addu      $a0, $s3, $zero
    /* 74AC 8006A80C 0BAA0108 */  j          .L8006A82C
    /* 74B0 8006A810 00000000 */   nop
  .L8006A814:
    /* 74B4 8006A814 C19D010C */  jal        func_80067704
    /* 74B8 8006A818 01000424 */   addiu     $a0, $zero, 0x1
    /* 74BC 8006A81C 03005014 */  bne        $v0, $s0, .L8006A82C
    /* 74C0 8006A820 21206002 */   addu      $a0, $s3, $zero
    /* 74C4 8006A824 7745000C */  jal        Task_SetState1
    /* 74C8 8006A828 06000524 */   addiu     $a1, $zero, 0x6
  .L8006A82C:
    /* 74CC 8006A82C 2000BF8F */  lw         $ra, 0x20($sp)
    /* 74D0 8006A830 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 74D4 8006A834 1800B28F */  lw         $s2, 0x18($sp)
    /* 74D8 8006A838 1400B18F */  lw         $s1, 0x14($sp)
    /* 74DC 8006A83C 1000B08F */  lw         $s0, 0x10($sp)
    /* 74E0 8006A840 0800E003 */  jr         $ra
    /* 74E4 8006A844 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8006A6EC
