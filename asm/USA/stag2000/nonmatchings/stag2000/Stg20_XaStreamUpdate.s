nonmatching Stg20_XaStreamUpdate, 0x1FC

glabel Stg20_XaStreamUpdate
    /* 8500 8006B860 B0FFBD27 */  addiu      $sp, $sp, -0x50
    /* 8504 8006B864 4000B2AF */  sw         $s2, 0x40($sp)
    /* 8508 8006B868 21908000 */  addu       $s2, $a0, $zero
    /* 850C 8006B86C 4400B3AF */  sw         $s3, 0x44($sp)
    /* 8510 8006B870 01001324 */  addiu      $s3, $zero, 0x1
    /* 8514 8006B874 4800BFAF */  sw         $ra, 0x48($sp)
    /* 8518 8006B878 3C00B1AF */  sw         $s1, 0x3C($sp)
    /* 851C 8006B87C 3800B0AF */  sw         $s0, 0x38($sp)
    /* 8520 8006B880 1000518E */  lw         $s1, 0x10($s2)
    /* 8524 8006B884 2C00508E */  lw         $s0, 0x2C($s2)
    /* 8528 8006B888 6D003312 */  beq        $s1, $s3, .L8006BA40
    /* 852C 8006B88C 0200222A */   slti      $v0, $s1, 0x2
    /* 8530 8006B890 03004014 */  bnez       $v0, .L8006B8A0
    /* 8534 8006B894 02000224 */   addiu     $v0, $zero, 0x2
    /* 8538 8006B898 34002212 */  beq        $s1, $v0, .L8006B96C
    /* 853C 8006B89C 00000000 */   nop
  .L8006B8A0:
    /* 8540 8006B8A0 1400428E */  lw         $v0, 0x14($s2)
    /* 8544 8006B8A4 00000000 */  nop
    /* 8548 8006B8A8 03004010 */  beqz       $v0, .L8006B8B8
    /* 854C 8006B8AC 00000000 */   nop
    /* 8550 8006B8B0 1E005310 */  beq        $v0, $s3, .L8006B92C
    /* 8554 8006B8B4 01000424 */   addiu     $a0, $zero, 0x1
  .L8006B8B8:
    /* 8558 8006B8B8 0000048E */  lw         $a0, 0x0($s0)
    /* 855C 8006B8BC EB8F000C */  jal        Cd_GetFileLba
    /* 8560 8006B8C0 00000000 */   nop
    /* 8564 8006B8C4 0D000424 */  addiu      $a0, $zero, 0xD
    /* 8568 8006B8C8 0800038E */  lw         $v1, 0x8($s0)
    /* 856C 8006B8CC 1000A527 */  addiu      $a1, $sp, 0x10
    /* 8570 8006B8D0 0C0002AE */  sw         $v0, 0xC($s0)
    /* 8574 8006B8D4 21104300 */  addu       $v0, $v0, $v1
    /* 8578 8006B8D8 100002AE */  sw         $v0, 0x10($s0)
    /* 857C 8006B8DC 1000B3A3 */  sb         $s3, 0x10($sp)
    /* 8580 8006B8E0 04000292 */  lbu        $v0, 0x4($s0)
    /* 8584 8006B8E4 21300000 */  addu       $a2, $zero, $zero
    /* 8588 8006B8E8 55C1000C */  jal        CdControl
    /* 858C 8006B8EC 1100A2A3 */   sb        $v0, 0x11($sp)
    /* 8590 8006B8F0 0E000424 */  addiu      $a0, $zero, 0xE
    /* 8594 8006B8F4 1800A527 */  addiu      $a1, $sp, 0x18
    /* 8598 8006B8F8 21300000 */  addu       $a2, $zero, $zero
    /* 859C 8006B8FC C8000224 */  addiu      $v0, $zero, 0xC8
    /* 85A0 8006B900 F1C1000C */  jal        CdControlB
    /* 85A4 8006B904 1800A2A3 */   sb        $v0, 0x18($sp)
    /* 85A8 8006B908 0C00048E */  lw         $a0, 0xC($s0)
    /* 85AC 8006B90C 2000B027 */  addiu      $s0, $sp, 0x20
    /* 85B0 8006B910 E5C0000C */  jal        CdIntToPos
    /* 85B4 8006B914 21280002 */   addu      $a1, $s0, $zero
    /* 85B8 8006B918 15000424 */  addiu      $a0, $zero, 0x15
    /* 85BC 8006B91C A4C1000C */  jal        CdControlF
    /* 85C0 8006B920 21280002 */   addu      $a1, $s0, $zero
    /* 85C4 8006B924 6BAE0108 */  j          .L8006B9AC
    /* 85C8 8006B928 00000000 */   nop
  .L8006B92C:
    /* 85CC 8006B92C 35C1000C */  jal        CdSync
    /* 85D0 8006B930 2800A527 */   addiu     $a1, $sp, 0x28
    /* 85D4 8006B934 21184000 */  addu       $v1, $v0, $zero
    /* 85D8 8006B938 02000224 */  addiu      $v0, $zero, 0x2
    /* 85DC 8006B93C 07006210 */  beq        $v1, $v0, .L8006B95C
    /* 85E0 8006B940 05000224 */   addiu     $v0, $zero, 0x5
    /* 85E4 8006B944 3E006214 */  bne        $v1, $v0, .L8006BA40
    /* 85E8 8006B948 21204002 */   addu      $a0, $s2, $zero
    /* 85EC 8006B94C 7045000C */  jal        Task_SetState0
    /* 85F0 8006B950 21280000 */   addu      $a1, $zero, $zero
    /* 85F4 8006B954 90AE0108 */  j          .L8006BA40
    /* 85F8 8006B958 00000000 */   nop
  .L8006B95C:
    /* 85FC 8006B95C 5145000C */  jal        Task_NextState0
    /* 8600 8006B960 21204002 */   addu      $a0, $s2, $zero
    /* 8604 8006B964 90AE0108 */  j          .L8006BA40
    /* 8608 8006B968 00000000 */   nop
  .L8006B96C:
    /* 860C 8006B96C 1400428E */  lw         $v0, 0x14($s2)
    /* 8610 8006B970 00000000 */  nop
    /* 8614 8006B974 03004010 */  beqz       $v0, .L8006B984
    /* 8618 8006B978 00000000 */   nop
    /* 861C 8006B97C 0F005310 */  beq        $v0, $s3, .L8006B9BC
    /* 8620 8006B980 00000000 */   nop
  .L8006B984:
    /* 8624 8006B984 0C00048E */  lw         $a0, 0xC($s0)
    /* 8628 8006B988 2800B027 */  addiu      $s0, $sp, 0x28
    /* 862C 8006B98C E5C0000C */  jal        CdIntToPos
    /* 8630 8006B990 21280002 */   addu      $a1, $s0, $zero
    /* 8634 8006B994 1B000424 */  addiu      $a0, $zero, 0x1B
    /* 8638 8006B998 21280002 */  addu       $a1, $s0, $zero
    /* 863C 8006B99C 55C1000C */  jal        CdControl
    /* 8640 8006B9A0 21300000 */   addu      $a2, $zero, $zero
    /* 8644 8006B9A4 26005314 */  bne        $v0, $s3, .L8006BA40
    /* 8648 8006B9A8 00000000 */   nop
  .L8006B9AC:
    /* 864C 8006B9AC 5945000C */  jal        Task_NextState1
    /* 8650 8006B9B0 21204002 */   addu      $a0, $s2, $zero
    /* 8654 8006B9B4 90AE0108 */  j          .L8006BA40
    /* 8658 8006B9B8 00000000 */   nop
  .L8006B9BC:
    /* 865C 8006B9BC 2400428E */  lw         $v0, 0x24($s2)
    /* 8660 8006B9C0 00000000 */  nop
    /* 8664 8006B9C4 1F004230 */  andi       $v0, $v0, 0x1F
    /* 8668 8006B9C8 1D004014 */  bnez       $v0, .L8006BA40
    /* 866C 8006B9CC 01000424 */   addiu     $a0, $zero, 0x1
    /* 8670 8006B9D0 35C1000C */  jal        CdSync
    /* 8674 8006B9D4 3000A527 */   addiu     $a1, $sp, 0x30
    /* 8678 8006B9D8 21184000 */  addu       $v1, $v0, $zero
    /* 867C 8006B9DC 05007110 */  beq        $v1, $s1, .L8006B9F4
    /* 8680 8006B9E0 05000224 */   addiu     $v0, $zero, 0x5
    /* 8684 8006B9E4 16006214 */  bne        $v1, $v0, .L8006BA40
    /* 8688 8006B9E8 21204002 */   addu      $a0, $s2, $zero
    /* 868C 8006B9EC 8AAE0108 */  j          .L8006BA28
    /* 8690 8006B9F0 00000000 */   nop
  .L8006B9F4:
    /* 8694 8006B9F4 29C1000C */  jal        CdLastCom
    /* 8698 8006B9F8 00000000 */   nop
    /* 869C 8006B9FC 11000324 */  addiu      $v1, $zero, 0x11
    /* 86A0 8006BA00 0D004314 */  bne        $v0, $v1, .L8006BA38
    /* 86A4 8006BA04 11000424 */   addiu     $a0, $zero, 0x11
    /* 86A8 8006BA08 59B7000C */  jal        CdPosToInt
    /* 86AC 8006BA0C 3500A427 */   addiu     $a0, $sp, 0x35
    /* 86B0 8006BA10 1000038E */  lw         $v1, 0x10($s0)
    /* 86B4 8006BA14 00000000 */  nop
    /* 86B8 8006BA18 2A104300 */  slt        $v0, $v0, $v1
    /* 86BC 8006BA1C 06004014 */  bnez       $v0, .L8006BA38
    /* 86C0 8006BA20 11000424 */   addiu     $a0, $zero, 0x11
    /* 86C4 8006BA24 21204002 */  addu       $a0, $s2, $zero
  .L8006BA28:
    /* 86C8 8006BA28 7045000C */  jal        Task_SetState0
    /* 86CC 8006BA2C 03000524 */   addiu     $a1, $zero, 0x3
    /* 86D0 8006BA30 90AE0108 */  j          .L8006BA40
    /* 86D4 8006BA34 00000000 */   nop
  .L8006BA38:
    /* 86D8 8006BA38 A4C1000C */  jal        CdControlF
    /* 86DC 8006BA3C 21280000 */   addu      $a1, $zero, $zero
  .L8006BA40:
    /* 86E0 8006BA40 4800BF8F */  lw         $ra, 0x48($sp)
    /* 86E4 8006BA44 4400B38F */  lw         $s3, 0x44($sp)
    /* 86E8 8006BA48 4000B28F */  lw         $s2, 0x40($sp)
    /* 86EC 8006BA4C 3C00B18F */  lw         $s1, 0x3C($sp)
    /* 86F0 8006BA50 3800B08F */  lw         $s0, 0x38($sp)
    /* 86F4 8006BA54 0800E003 */  jr         $ra
    /* 86F8 8006BA58 5000BD27 */   addiu     $sp, $sp, 0x50
endlabel Stg20_XaStreamUpdate
