nonmatching func_8006CB8C, 0x760

glabel func_8006CB8C
    /* 982C 8006CB8C 60FFBD27 */  addiu      $sp, $sp, -0xA0
    /* 9830 8006CB90 9000B4AF */  sw         $s4, 0x90($sp)
    /* 9834 8006CB94 21A08000 */  addu       $s4, $a0, $zero
    /* 9838 8006CB98 9C00BFAF */  sw         $ra, 0x9C($sp)
    /* 983C 8006CB9C 9800B6AF */  sw         $s6, 0x98($sp)
    /* 9840 8006CBA0 9400B5AF */  sw         $s5, 0x94($sp)
    /* 9844 8006CBA4 8C00B3AF */  sw         $s3, 0x8C($sp)
    /* 9848 8006CBA8 8800B2AF */  sw         $s2, 0x88($sp)
    /* 984C 8006CBAC 8400B1AF */  sw         $s1, 0x84($sp)
    /* 9850 8006CBB0 8000B0AF */  sw         $s0, 0x80($sp)
    /* 9854 8006CBB4 2C00918E */  lw         $s1, 0x2C($s4)
    /* 9858 8006CBB8 1000838E */  lw         $v1, 0x10($s4)
    /* 985C 8006CBBC 3400928E */  lw         $s2, 0x34($s4)
    /* 9860 8006CBC0 05006010 */  beqz       $v1, .L8006CBD8
    /* 9864 8006CBC4 01000224 */   addiu     $v0, $zero, 0x1
    /* 9868 8006CBC8 0A006210 */  beq        $v1, $v0, .L8006CBF4
    /* 986C 8006CBCC 01001324 */   addiu     $s3, $zero, 0x1
    /* 9870 8006CBD0 B1B40108 */  j          .L8006D2C4
    /* 9874 8006CBD4 00000000 */   nop
  .L8006CBD8:
    /* 9878 8006CBD8 0780023C */  lui        $v0, %hi(D_80073890)
    /* 987C 8006CBDC 90384224 */  addiu      $v0, $v0, %lo(D_80073890)
    /* 9880 8006CBE0 000022AE */  sw         $v0, 0x0($s1)
    /* 9884 8006CBE4 5145000C */  jal        Task_NextState0
    /* 9888 8006CBE8 21208002 */   addu      $a0, $s4, $zero
    /* 988C 8006CBEC B1B40108 */  j          .L8006D2C4
    /* 9890 8006CBF0 00000000 */   nop
  .L8006CBF4:
    /* 9894 8006CBF4 21B06002 */  addu       $s6, $s3, $zero
    /* 9898 8006CBF8 0780023C */  lui        $v0, %hi(D_80073CC0)
    /* 989C 8006CBFC C03C5524 */  addiu      $s5, $v0, %lo(D_80073CC0)
  .L8006CC00:
    /* 98A0 8006CC00 0000228E */  lw         $v0, 0x0($s1)
    /* 98A4 8006CC04 00000000 */  nop
    /* 98A8 8006CC08 00004384 */  lh         $v1, 0x0($v0)
    /* 98AC 8006CC0C 00000000 */  nop
    /* 98B0 8006CC10 1900622C */  sltiu      $v0, $v1, 0x19
    /* 98B4 8006CC14 A9014010 */  beqz       $v0, .L8006D2BC
    /* 98B8 8006CC18 0680023C */   lui       $v0, %hi(jtbl_8006357C)
    /* 98BC 8006CC1C 7C354224 */  addiu      $v0, $v0, %lo(jtbl_8006357C)
    /* 98C0 8006CC20 80180300 */  sll        $v1, $v1, 2
    /* 98C4 8006CC24 21186200 */  addu       $v1, $v1, $v0
    /* 98C8 8006CC28 0000628C */  lw         $v0, 0x0($v1)
    /* 98CC 8006CC2C 00000000 */  nop
    /* 98D0 8006CC30 08004000 */  jr         $v0
    /* 98D4 8006CC34 00000000 */   nop
  jlabel .L8006CC38
    /* 98D8 8006CC38 1400828E */  lw         $v0, 0x14($s4)
    /* 98DC 8006CC3C 00000000 */  nop
    /* 98E0 8006CC40 03004010 */  beqz       $v0, .L8006CC50
    /* 98E4 8006CC44 00000000 */   nop
    /* 98E8 8006CC48 04005610 */  beq        $v0, $s6, .L8006CC5C
    /* 98EC 8006CC4C 00000000 */   nop
  .L8006CC50:
    /* 98F0 8006CC50 280080AE */  sw         $zero, 0x28($s4)
    /* 98F4 8006CC54 01004224 */  addiu      $v0, $v0, 0x1
    /* 98F8 8006CC58 140082AE */  sw         $v0, 0x14($s4)
  .L8006CC5C:
    /* 98FC 8006CC5C 0000228E */  lw         $v0, 0x0($s1)
    /* 9900 8006CC60 2800838E */  lw         $v1, 0x28($s4)
    /* 9904 8006CC64 02004284 */  lh         $v0, 0x2($v0)
    /* 9908 8006CC68 00000000 */  nop
    /* 990C 8006CC6C 2A104300 */  slt        $v0, $v0, $v1
    /* 9910 8006CC70 91014010 */  beqz       $v0, .L8006D2B8
    /* 9914 8006CC74 00000000 */   nop
    /* 9918 8006CC78 48B40108 */  j          .L8006D120
    /* 991C 8006CC7C 140080AE */   sw        $zero, 0x14($s4)
  jlabel .L8006CC80
    /* 9920 8006CC80 0000228E */  lw         $v0, 0x0($s1)
    /* 9924 8006CC84 09050424 */  addiu      $a0, $zero, 0x509
    /* 9928 8006CC88 02004684 */  lh         $a2, 0x2($v0)
    /* 992C 8006CC8C 4445000C */  jal        Task_FindFirst
    /* 9930 8006CC90 FFFF0524 */   addiu     $a1, $zero, -0x1
    /* 9934 8006CC94 1000438C */  lw         $v1, 0x10($v0)
    /* 9938 8006CC98 02000224 */  addiu      $v0, $zero, 0x2
    /* 993C 8006CC9C 86016210 */  beq        $v1, $v0, .L8006D2B8
    /* 9940 8006CCA0 00000000 */   nop
    /* 9944 8006CCA4 48B40108 */  j          .L8006D120
    /* 9948 8006CCA8 00000000 */   nop
  jlabel .L8006CCAC
    /* 994C 8006CCAC 0000228E */  lw         $v0, 0x0($s1)
    /* 9950 8006CCB0 00000000 */  nop
    /* 9954 8006CCB4 02004484 */  lh         $a0, 0x2($v0)
    /* 9958 8006CCB8 45C3010C */  jal        func_80070D14
    /* 995C 8006CCBC 21980000 */   addu      $s3, $zero, $zero
    /* 9960 8006CCC0 0000228E */  lw         $v0, 0x0($s1)
    /* 9964 8006CCC4 4BB40108 */  j          .L8006D12C
    /* 9968 8006CCC8 04004224 */   addiu     $v0, $v0, 0x4
  jlabel .L8006CCCC
    /* 996C 8006CCCC 09050424 */  addiu      $a0, $zero, 0x509
    /* 9970 8006CCD0 FFFF0524 */  addiu      $a1, $zero, -0x1
    /* 9974 8006CCD4 4445000C */  jal        Task_FindFirst
    /* 9978 8006CCD8 2130A000 */   addu      $a2, $a1, $zero
    /* 997C 8006CCDC 21804000 */  addu       $s0, $v0, $zero
    /* 9980 8006CCE0 0F010012 */  beqz       $s0, .L8006D120
    /* 9984 8006CCE4 00000000 */   nop
  .L8006CCE8:
    /* 9988 8006CCE8 0000228E */  lw         $v0, 0x0($s1)
    /* 998C 8006CCEC 00000000 */  nop
    /* 9990 8006CCF0 02004384 */  lh         $v1, 0x2($v0)
    /* 9994 8006CCF4 0800028E */  lw         $v0, 0x8($s0)
    /* 9998 8006CCF8 00000000 */  nop
    /* 999C 8006CCFC 07004314 */  bne        $v0, $v1, .L8006CD1C
    /* 99A0 8006CD00 21200002 */   addu      $a0, $s0, $zero
    /* 99A4 8006CD04 90BD010C */  jal        func_8006F640
    /* 99A8 8006CD08 01000524 */   addiu     $a1, $zero, 0x1
    /* 99AC 8006CD0C 99BD010C */  jal        func_8006F664
    /* 99B0 8006CD10 21200002 */   addu      $a0, $s0, $zero
    /* 99B4 8006CD14 49B30108 */  j          .L8006CD24
    /* 99B8 8006CD18 00000000 */   nop
  .L8006CD1C:
    /* 99BC 8006CD1C 90BD010C */  jal        func_8006F640
    /* 99C0 8006CD20 21280000 */   addu      $a1, $zero, $zero
  .L8006CD24:
    /* 99C4 8006CD24 1045000C */  jal        Task_FindNext
    /* 99C8 8006CD28 00000000 */   nop
    /* 99CC 8006CD2C 21804000 */  addu       $s0, $v0, $zero
    /* 99D0 8006CD30 FB000012 */  beqz       $s0, .L8006D120
    /* 99D4 8006CD34 00000000 */   nop
    /* 99D8 8006CD38 3AB30108 */  j          .L8006CCE8
    /* 99DC 8006CD3C 00000000 */   nop
  jlabel .L8006CD40
    /* 99E0 8006CD40 09050424 */  addiu      $a0, $zero, 0x509
    /* 99E4 8006CD44 FFFF0524 */  addiu      $a1, $zero, -0x1
    /* 99E8 8006CD48 4445000C */  jal        Task_FindFirst
    /* 99EC 8006CD4C 2130A000 */   addu      $a2, $a1, $zero
    /* 99F0 8006CD50 21804000 */  addu       $s0, $v0, $zero
    /* 99F4 8006CD54 27010012 */  beqz       $s0, .L8006D1F4
    /* 99F8 8006CD58 00000000 */   nop
  .L8006CD5C:
    /* 99FC 8006CD5C 0800028E */  lw         $v0, 0x8($s0)
    /* 9A00 8006CD60 00000000 */  nop
    /* 9A04 8006CD64 03004228 */  slti       $v0, $v0, 0x3
    /* 9A08 8006CD68 05004010 */  beqz       $v0, .L8006CD80
    /* 9A0C 8006CD6C 21200002 */   addu      $a0, $s0, $zero
    /* 9A10 8006CD70 90BD010C */  jal        func_8006F640
    /* 9A14 8006CD74 01000524 */   addiu     $a1, $zero, 0x1
    /* 9A18 8006CD78 99BD010C */  jal        func_8006F664
    /* 9A1C 8006CD7C 21200002 */   addu      $a0, $s0, $zero
  .L8006CD80:
    /* 9A20 8006CD80 1045000C */  jal        Task_FindNext
    /* 9A24 8006CD84 00000000 */   nop
    /* 9A28 8006CD88 21804000 */  addu       $s0, $v0, $zero
    /* 9A2C 8006CD8C 19010012 */  beqz       $s0, .L8006D1F4
    /* 9A30 8006CD90 00000000 */   nop
    /* 9A34 8006CD94 57B30108 */  j          .L8006CD5C
    /* 9A38 8006CD98 00000000 */   nop
  jlabel .L8006CD9C
    /* 9A3C 8006CD9C 09050424 */  addiu      $a0, $zero, 0x509
    /* 9A40 8006CDA0 FFFF0524 */  addiu      $a1, $zero, -0x1
    /* 9A44 8006CDA4 4445000C */  jal        Task_FindFirst
    /* 9A48 8006CDA8 2130A000 */   addu      $a2, $a1, $zero
    /* 9A4C 8006CDAC 21804000 */  addu       $s0, $v0, $zero
    /* 9A50 8006CDB0 10010012 */  beqz       $s0, .L8006D1F4
    /* 9A54 8006CDB4 00000000 */   nop
  .L8006CDB8:
    /* 9A58 8006CDB8 0800028E */  lw         $v0, 0x8($s0)
    /* 9A5C 8006CDBC 00000000 */  nop
    /* 9A60 8006CDC0 03004228 */  slti       $v0, $v0, 0x3
    /* 9A64 8006CDC4 05004014 */  bnez       $v0, .L8006CDDC
    /* 9A68 8006CDC8 21200002 */   addu      $a0, $s0, $zero
    /* 9A6C 8006CDCC 90BD010C */  jal        func_8006F640
    /* 9A70 8006CDD0 01000524 */   addiu     $a1, $zero, 0x1
    /* 9A74 8006CDD4 99BD010C */  jal        func_8006F664
    /* 9A78 8006CDD8 21200002 */   addu      $a0, $s0, $zero
  .L8006CDDC:
    /* 9A7C 8006CDDC 1045000C */  jal        Task_FindNext
    /* 9A80 8006CDE0 00000000 */   nop
    /* 9A84 8006CDE4 21804000 */  addu       $s0, $v0, $zero
    /* 9A88 8006CDE8 02010012 */  beqz       $s0, .L8006D1F4
    /* 9A8C 8006CDEC 00000000 */   nop
    /* 9A90 8006CDF0 6EB30108 */  j          .L8006CDB8
    /* 9A94 8006CDF4 00000000 */   nop
  jlabel .L8006CDF8
    /* 9A98 8006CDF8 09050424 */  addiu      $a0, $zero, 0x509
    /* 9A9C 8006CDFC FFFF0524 */  addiu      $a1, $zero, -0x1
    /* 9AA0 8006CE00 4445000C */  jal        Task_FindFirst
    /* 9AA4 8006CE04 2130A000 */   addu      $a2, $a1, $zero
    /* 9AA8 8006CE08 21804000 */  addu       $s0, $v0, $zero
    /* 9AAC 8006CE0C F9000012 */  beqz       $s0, .L8006D1F4
    /* 9AB0 8006CE10 21200002 */   addu      $a0, $s0, $zero
  .L8006CE14:
    /* 9AB4 8006CE14 90BD010C */  jal        func_8006F640
    /* 9AB8 8006CE18 01000524 */   addiu     $a1, $zero, 0x1
    /* 9ABC 8006CE1C 99BD010C */  jal        func_8006F664
    /* 9AC0 8006CE20 21200002 */   addu      $a0, $s0, $zero
    /* 9AC4 8006CE24 1045000C */  jal        Task_FindNext
    /* 9AC8 8006CE28 00000000 */   nop
    /* 9ACC 8006CE2C 21804000 */  addu       $s0, $v0, $zero
    /* 9AD0 8006CE30 F8FF0016 */  bnez       $s0, .L8006CE14
    /* 9AD4 8006CE34 21200002 */   addu      $a0, $s0, $zero
    /* 9AD8 8006CE38 7DB40108 */  j          .L8006D1F4
    /* 9ADC 8006CE3C 00000000 */   nop
  jlabel .L8006CE40
    /* 9AE0 8006CE40 0000228E */  lw         $v0, 0x0($s1)
    /* 9AE4 8006CE44 09050424 */  addiu      $a0, $zero, 0x509
    /* 9AE8 8006CE48 02004684 */  lh         $a2, 0x2($v0)
    /* 9AEC 8006CE4C 4445000C */  jal        Task_FindFirst
    /* 9AF0 8006CE50 FFFF0524 */   addiu     $a1, $zero, -0x1
    /* 9AF4 8006CE54 21804000 */  addu       $s0, $v0, $zero
    /* 9AF8 8006CE58 21200002 */  addu       $a0, $s0, $zero
    /* 9AFC 8006CE5C 7045000C */  jal        Task_SetState0
    /* 9B00 8006CE60 02000524 */   addiu     $a1, $zero, 0x2
    /* 9B04 8006CE64 21200002 */  addu       $a0, $s0, $zero
    /* 9B08 8006CE68 7745000C */  jal        Task_SetState1
    /* 9B0C 8006CE6C 21280000 */   addu      $a1, $zero, $zero
    /* 9B10 8006CE70 48B40108 */  j          .L8006D120
    /* 9B14 8006CE74 00000000 */   nop
  jlabel .L8006CE78
    /* 9B18 8006CE78 0000228E */  lw         $v0, 0x0($s1)
    /* 9B1C 8006CE7C 00000000 */  nop
    /* 9B20 8006CE80 02004684 */  lh         $a2, 0x2($v0)
    /* 9B24 8006CE84 06000224 */  addiu      $v0, $zero, 0x6
    /* 9B28 8006CE88 8D00C210 */  beq        $a2, $v0, .L8006D0C0
    /* 9B2C 8006CE8C 09050424 */   addiu     $a0, $zero, 0x509
    /* 9B30 8006CE90 4445000C */  jal        Task_FindFirst
    /* 9B34 8006CE94 FFFF0524 */   addiu     $a1, $zero, -0x1
    /* 9B38 8006CE98 21804000 */  addu       $s0, $v0, $zero
    /* 9B3C 8006CE9C 21200002 */  addu       $a0, $s0, $zero
    /* 9B40 8006CEA0 7045000C */  jal        Task_SetState0
    /* 9B44 8006CEA4 02000524 */   addiu     $a1, $zero, 0x2
    /* 9B48 8006CEA8 21200002 */  addu       $a0, $s0, $zero
    /* 9B4C 8006CEAC 7745000C */  jal        Task_SetState1
    /* 9B50 8006CEB0 01000524 */   addiu     $a1, $zero, 0x1
    /* 9B54 8006CEB4 0000228E */  lw         $v0, 0x0($s1)
    /* 9B58 8006CEB8 00000000 */  nop
    /* 9B5C 8006CEBC 04004590 */  lbu        $a1, 0x4($v0)
    /* 9B60 8006CEC0 8E45000C */  jal        Task_SetState4
    /* 9B64 8006CEC4 21200002 */   addu      $a0, $s0, $zero
    /* 9B68 8006CEC8 30B40108 */  j          .L8006D0C0
    /* 9B6C 8006CECC 00000000 */   nop
  jlabel .L8006CED0
    /* 9B70 8006CED0 0000228E */  lw         $v0, 0x0($s1)
    /* 9B74 8006CED4 09050424 */  addiu      $a0, $zero, 0x509
    /* 9B78 8006CED8 02004684 */  lh         $a2, 0x2($v0)
    /* 9B7C 8006CEDC 4445000C */  jal        Task_FindFirst
    /* 9B80 8006CEE0 FFFF0524 */   addiu     $a1, $zero, -0x1
    /* 9B84 8006CEE4 0000238E */  lw         $v1, 0x0($s1)
    /* 9B88 8006CEE8 21204000 */  addu       $a0, $v0, $zero
    /* 9B8C 8006CEEC 04006684 */  lh         $a2, 0x4($v1)
    /* 9B90 8006CEF0 4C9D010C */  jal        func_80067530
    /* 9B94 8006CEF4 03000524 */   addiu     $a1, $zero, 0x3
    /* 9B98 8006CEF8 30B40108 */  j          .L8006D0C0
    /* 9B9C 8006CEFC 00000000 */   nop
  jlabel .L8006CF00
    /* 9BA0 8006CF00 0000228E */  lw         $v0, 0x0($s1)
    /* 9BA4 8006CF04 09050424 */  addiu      $a0, $zero, 0x509
    /* 9BA8 8006CF08 02004684 */  lh         $a2, 0x2($v0)
    /* 9BAC 8006CF0C 4445000C */  jal        Task_FindFirst
    /* 9BB0 8006CF10 FFFF0524 */   addiu     $a1, $zero, -0x1
    /* 9BB4 8006CF14 0000238E */  lw         $v1, 0x0($s1)
    /* 9BB8 8006CF18 21204000 */  addu       $a0, $v0, $zero
    /* 9BBC 8006CF1C 04006684 */  lh         $a2, 0x4($v1)
    /* 9BC0 8006CF20 4C9D010C */  jal        func_80067530
    /* 9BC4 8006CF24 04000524 */   addiu     $a1, $zero, 0x4
    /* 9BC8 8006CF28 30B40108 */  j          .L8006D0C0
    /* 9BCC 8006CF2C 00000000 */   nop
  jlabel .L8006CF30
    /* 9BD0 8006CF30 0000228E */  lw         $v0, 0x0($s1)
    /* 9BD4 8006CF34 09050424 */  addiu      $a0, $zero, 0x509
    /* 9BD8 8006CF38 02004684 */  lh         $a2, 0x2($v0)
    /* 9BDC 8006CF3C 4445000C */  jal        Task_FindFirst
    /* 9BE0 8006CF40 FFFF0524 */   addiu     $a1, $zero, -0x1
    /* 9BE4 8006CF44 0000238E */  lw         $v1, 0x0($s1)
    /* 9BE8 8006CF48 21204000 */  addu       $a0, $v0, $zero
    /* 9BEC 8006CF4C 04006684 */  lh         $a2, 0x4($v1)
    /* 9BF0 8006CF50 4C9D010C */  jal        func_80067530
    /* 9BF4 8006CF54 05000524 */   addiu     $a1, $zero, 0x5
    /* 9BF8 8006CF58 0000228E */  lw         $v0, 0x0($s1)
    /* 9BFC 8006CF5C 00000000 */  nop
    /* 9C00 8006CF60 02004384 */  lh         $v1, 0x2($v0)
    /* 9C04 8006CF64 00000000 */  nop
    /* 9C08 8006CF68 03006228 */  slti       $v0, $v1, 0x3
    /* 9C0C 8006CF6C 54004014 */  bnez       $v0, .L8006D0C0
    /* 9C10 8006CF70 00000000 */   nop
    /* 9C14 8006CF74 30B40108 */  j          .L8006D0C0
    /* 9C18 8006CF78 D803A3AE */   sw        $v1, 0x3D8($s5)
  jlabel .L8006CF7C
    /* 9C1C 8006CF7C 0000228E */  lw         $v0, 0x0($s1)
    /* 9C20 8006CF80 09050424 */  addiu      $a0, $zero, 0x509
    /* 9C24 8006CF84 02004684 */  lh         $a2, 0x2($v0)
    /* 9C28 8006CF88 4445000C */  jal        Task_FindFirst
    /* 9C2C 8006CF8C FFFF0524 */   addiu     $a1, $zero, -0x1
    /* 9C30 8006CF90 0000238E */  lw         $v1, 0x0($s1)
    /* 9C34 8006CF94 21204000 */  addu       $a0, $v0, $zero
    /* 9C38 8006CF98 04006684 */  lh         $a2, 0x4($v1)
    /* 9C3C 8006CF9C 4C9D010C */  jal        func_80067530
    /* 9C40 8006CFA0 06000524 */   addiu     $a1, $zero, 0x6
    /* 9C44 8006CFA4 30B40108 */  j          .L8006D0C0
    /* 9C48 8006CFA8 00000000 */   nop
  jlabel .L8006CFAC
    /* 9C4C 8006CFAC 0000228E */  lw         $v0, 0x0($s1)
    /* 9C50 8006CFB0 09050424 */  addiu      $a0, $zero, 0x509
    /* 9C54 8006CFB4 02004684 */  lh         $a2, 0x2($v0)
    /* 9C58 8006CFB8 4445000C */  jal        Task_FindFirst
    /* 9C5C 8006CFBC FFFF0524 */   addiu     $a1, $zero, -0x1
    /* 9C60 8006CFC0 0000238E */  lw         $v1, 0x0($s1)
    /* 9C64 8006CFC4 21204000 */  addu       $a0, $v0, $zero
    /* 9C68 8006CFC8 04006684 */  lh         $a2, 0x4($v1)
    /* 9C6C 8006CFCC 4C9D010C */  jal        func_80067530
    /* 9C70 8006CFD0 0C000524 */   addiu     $a1, $zero, 0xC
    /* 9C74 8006CFD4 30B40108 */  j          .L8006D0C0
    /* 9C78 8006CFD8 00000000 */   nop
  jlabel .L8006CFDC
    /* 9C7C 8006CFDC 1400828E */  lw         $v0, 0x14($s4)
    /* 9C80 8006CFE0 00000000 */  nop
    /* 9C84 8006CFE4 03004010 */  beqz       $v0, .L8006CFF4
    /* 9C88 8006CFE8 10050424 */   addiu     $a0, $zero, 0x510
    /* 9C8C 8006CFEC 06005610 */  beq        $v0, $s6, .L8006D008
    /* 9C90 8006CFF0 00000000 */   nop
  .L8006CFF4:
    /* 9C94 8006CFF4 0C004526 */  addiu      $a1, $s2, 0xC
    /* 9C98 8006CFF8 1F44000C */  jal        Task_Create
    /* 9C9C 8006CFFC 21300000 */   addu      $a2, $zero, $zero
    /* 9CA0 8006D000 5945000C */  jal        Task_NextState1
    /* 9CA4 8006D004 21208002 */   addu      $a0, $s4, $zero
  .L8006D008:
    /* 9CA8 8006D008 0C00428E */  lw         $v0, 0xC($s2)
    /* 9CAC 8006D00C 00000000 */  nop
    /* 9CB0 8006D010 AA004014 */  bnez       $v0, .L8006D2BC
    /* 9CB4 8006D014 21980000 */   addu      $s3, $zero, $zero
    /* 9CB8 8006D018 21208002 */  addu       $a0, $s4, $zero
    /* 9CBC 8006D01C 0000228E */  lw         $v0, 0x0($s1)
    /* 9CC0 8006D020 21286002 */  addu       $a1, $s3, $zero
    /* 9CC4 8006D024 A7B40108 */  j          .L8006D29C
    /* 9CC8 8006D028 02004224 */   addiu     $v0, $v0, 0x2
  jlabel .L8006D02C
    /* 9CCC 8006D02C DC02A28E */  lw         $v0, 0x2DC($s5)
    /* 9CD0 8006D030 03000324 */  addiu      $v1, $zero, 0x3
    /* 9CD4 8006D034 03004314 */  bne        $v0, $v1, .L8006D044
    /* 9CD8 8006D038 00000000 */   nop
    /* 9CDC 8006D03C 7DB40108 */  j          .L8006D1F4
    /* 9CE0 8006D040 D003A3AE */   sw        $v1, 0x3D0($s5)
  .L8006D044:
    /* 9CE4 8006D044 EC02A28E */  lw         $v0, 0x2EC($s5)
    /* 9CE8 8006D048 00000000 */  nop
    /* 9CEC 8006D04C 05004310 */  beq        $v0, $v1, .L8006D064
    /* 9CF0 8006D050 04000224 */   addiu     $v0, $zero, 0x4
    /* 9CF4 8006D054 FC02A28E */  lw         $v0, 0x2FC($s5)
    /* 9CF8 8006D058 00000000 */  nop
    /* 9CFC 8006D05C 65004314 */  bne        $v0, $v1, .L8006D1F4
    /* 9D00 8006D060 05000224 */   addiu     $v0, $zero, 0x5
  .L8006D064:
    /* 9D04 8006D064 7DB40108 */  j          .L8006D1F4
    /* 9D08 8006D068 D003A2AE */   sw        $v0, 0x3D0($s5)
  jlabel .L8006D06C
    /* 9D0C 8006D06C 0000228E */  lw         $v0, 0x0($s1)
    /* 9D10 8006D070 00000000 */  nop
    /* 9D14 8006D074 02004284 */  lh         $v0, 0x2($v0)
    /* 9D18 8006D078 0C050424 */  addiu      $a0, $zero, 0x50C
    /* 9D1C 8006D07C 1000A2AF */  sw         $v0, 0x10($sp)
    /* 9D20 8006D080 0000228E */  lw         $v0, 0x0($s1)
    /* 9D24 8006D084 21284002 */  addu       $a1, $s2, $zero
    /* 9D28 8006D088 04004284 */  lh         $v0, 0x4($v0)
    /* 9D2C 8006D08C 1000A627 */  addiu      $a2, $sp, 0x10
    /* 9D30 8006D090 1F44000C */  jal        Task_Create
    /* 9D34 8006D094 1400A2AF */   sw        $v0, 0x14($sp)
    /* 9D38 8006D098 B003A386 */  lh         $v1, 0x3B0($s5)
    /* 9D3C 8006D09C 00000000 */  nop
    /* 9D40 8006D0A0 07006010 */  beqz       $v1, .L8006D0C0
    /* 9D44 8006D0A4 0D050424 */   addiu     $a0, $zero, 0x50D
    /* 9D48 8006D0A8 08004526 */  addiu      $a1, $s2, 0x8
    /* 9D4C 8006D0AC 1800A627 */  addiu      $a2, $sp, 0x18
    /* 9D50 8006D0B0 08000224 */  addiu      $v0, $zero, 0x8
    /* 9D54 8006D0B4 1800A2AF */  sw         $v0, 0x18($sp)
    /* 9D58 8006D0B8 1F44000C */  jal        Task_Create
    /* 9D5C 8006D0BC 2000A3AF */   sw        $v1, 0x20($sp)
  .L8006D0C0:
    /* 9D60 8006D0C0 0000228E */  lw         $v0, 0x0($s1)
    /* 9D64 8006D0C4 00000000 */  nop
    /* 9D68 8006D0C8 06004224 */  addiu      $v0, $v0, 0x6
    /* 9D6C 8006D0CC AFB40108 */  j          .L8006D2BC
    /* 9D70 8006D0D0 000022AE */   sw        $v0, 0x0($s1)
  jlabel .L8006D0D4
    /* 9D74 8006D0D4 0D050424 */  addiu      $a0, $zero, 0x50D
    /* 9D78 8006D0D8 2800A0AF */  sw         $zero, 0x28($sp)
    /* 9D7C 8006D0DC 0000228E */  lw         $v0, 0x0($s1)
    /* 9D80 8006D0E0 04004526 */  addiu      $a1, $s2, 0x4
    /* 9D84 8006D0E4 02004284 */  lh         $v0, 0x2($v0)
    /* 9D88 8006D0E8 2800A627 */  addiu      $a2, $sp, 0x28
    /* 9D8C 8006D0EC 3000A0AF */  sw         $zero, 0x30($sp)
    /* 9D90 8006D0F0 46B40108 */  j          .L8006D118
    /* 9D94 8006D0F4 2C00A2AF */   sw        $v0, 0x2C($sp)
  jlabel .L8006D0F8
    /* 9D98 8006D0F8 0D050424 */  addiu      $a0, $zero, 0x50D
    /* 9D9C 8006D0FC 0000228E */  lw         $v0, 0x0($s1)
    /* 9DA0 8006D100 21284002 */  addu       $a1, $s2, $zero
    /* 9DA4 8006D104 02004284 */  lh         $v0, 0x2($v0)
    /* 9DA8 8006D108 3800A627 */  addiu      $a2, $sp, 0x38
    /* 9DAC 8006D10C 4000A0AF */  sw         $zero, 0x40($sp)
    /* 9DB0 8006D110 04004224 */  addiu      $v0, $v0, 0x4
    /* 9DB4 8006D114 3800A2AF */  sw         $v0, 0x38($sp)
  .L8006D118:
    /* 9DB8 8006D118 1F44000C */  jal        Task_Create
    /* 9DBC 8006D11C 00000000 */   nop
  .L8006D120:
    /* 9DC0 8006D120 0000228E */  lw         $v0, 0x0($s1)
    /* 9DC4 8006D124 00000000 */  nop
    /* 9DC8 8006D128 04004224 */  addiu      $v0, $v0, 0x4
  .L8006D12C:
    /* 9DCC 8006D12C AFB40108 */  j          .L8006D2BC
    /* 9DD0 8006D130 000022AE */   sw        $v0, 0x0($s1)
  jlabel .L8006D134
    /* 9DD4 8006D134 0D050424 */  addiu      $a0, $zero, 0x50D
    /* 9DD8 8006D138 08004526 */  addiu      $a1, $s2, 0x8
    /* 9DDC 8006D13C 4800A627 */  addiu      $a2, $sp, 0x48
    /* 9DE0 8006D140 07000224 */  addiu      $v0, $zero, 0x7
    /* 9DE4 8006D144 4800A2AF */  sw         $v0, 0x48($sp)
    /* 9DE8 8006D148 1F44000C */  jal        Task_Create
    /* 9DEC 8006D14C 5000A0AF */   sw        $zero, 0x50($sp)
    /* 9DF0 8006D150 7DB40108 */  j          .L8006D1F4
    /* 9DF4 8006D154 00000000 */   nop
  jlabel .L8006D158
    /* 9DF8 8006D158 0000228E */  lw         $v0, 0x0($s1)
    /* 9DFC 8006D15C 00000000 */  nop
    /* 9E00 8006D160 04004284 */  lh         $v0, 0x4($v0)
    /* 9E04 8006D164 00000000 */  nop
    /* 9E08 8006D168 5800A2AF */  sw         $v0, 0x58($sp)
    /* 9E0C 8006D16C 0000228E */  lw         $v0, 0x0($s1)
    /* 9E10 8006D170 00000000 */  nop
    /* 9E14 8006D174 02004284 */  lh         $v0, 0x2($v0)
    /* 9E18 8006D178 00000000 */  nop
    /* 9E1C 8006D17C 02004104 */  bgez       $v0, .L8006D188
    /* 9E20 8006D180 0D050424 */   addiu     $a0, $zero, 0x50D
    /* 9E24 8006D184 23100200 */  negu       $v0, $v0
  .L8006D188:
    /* 9E28 8006D188 5C00A2AF */  sw         $v0, 0x5C($sp)
    /* 9E2C 8006D18C 0000228E */  lw         $v0, 0x0($s1)
    /* 9E30 8006D190 04004526 */  addiu      $a1, $s2, 0x4
    /* 9E34 8006D194 06004284 */  lh         $v0, 0x6($v0)
    /* 9E38 8006D198 5800A627 */  addiu      $a2, $sp, 0x58
    /* 9E3C 8006D19C 1F44000C */  jal        Task_Create
    /* 9E40 8006D1A0 6000A2AF */   sw        $v0, 0x60($sp)
    /* 9E44 8006D1A4 0000228E */  lw         $v0, 0x0($s1)
    /* 9E48 8006D1A8 00000000 */  nop
    /* 9E4C 8006D1AC 08004224 */  addiu      $v0, $v0, 0x8
    /* 9E50 8006D1B0 AFB40108 */  j          .L8006D2BC
    /* 9E54 8006D1B4 000022AE */   sw        $v0, 0x0($s1)
  jlabel .L8006D1B8
    /* 9E58 8006D1B8 0E050424 */  addiu      $a0, $zero, 0x50E
    /* 9E5C 8006D1BC 10004526 */  addiu      $a1, $s2, 0x10
    /* 9E60 8006D1C0 7800A627 */  addiu      $a2, $sp, 0x78
    /* 9E64 8006D1C4 0780023C */  lui        $v0, %hi(D_80073890)
    /* 9E68 8006D1C8 90384224 */  addiu      $v0, $v0, %lo(D_80073890)
    /* 9E6C 8006D1CC 1F44000C */  jal        Task_Create
    /* 9E70 8006D1D0 7800A2AF */   sw        $v0, 0x78($sp)
    /* 9E74 8006D1D4 7DB40108 */  j          .L8006D1F4
    /* 9E78 8006D1D8 00000000 */   nop
  jlabel .L8006D1DC
    /* 9E7C 8006D1DC 1000428E */  lw         $v0, 0x10($s2)
    /* 9E80 8006D1E0 00000000 */  nop
    /* 9E84 8006D1E4 1000428C */  lw         $v0, 0x10($v0)
    /* 9E88 8006D1E8 00000000 */  nop
    /* 9E8C 8006D1EC 32005614 */  bne        $v0, $s6, .L8006D2B8
    /* 9E90 8006D1F0 00000000 */   nop
  .L8006D1F4:
    /* 9E94 8006D1F4 0000228E */  lw         $v0, 0x0($s1)
    /* 9E98 8006D1F8 00000000 */  nop
    /* 9E9C 8006D1FC 02004224 */  addiu      $v0, $v0, 0x2
    /* 9EA0 8006D200 AFB40108 */  j          .L8006D2BC
    /* 9EA4 8006D204 000022AE */   sw        $v0, 0x0($s1)
  jlabel .L8006D208
    /* 9EA8 8006D208 1400828E */  lw         $v0, 0x14($s4)
    /* 9EAC 8006D20C 00000000 */  nop
    /* 9EB0 8006D210 03004010 */  beqz       $v0, .L8006D220
    /* 9EB4 8006D214 00000000 */   nop
    /* 9EB8 8006D218 14005610 */  beq        $v0, $s6, .L8006D26C
    /* 9EBC 8006D21C 00000000 */   nop
  .L8006D220:
    /* 9EC0 8006D220 0000228E */  lw         $v0, 0x0($s1)
    /* 9EC4 8006D224 00000000 */  nop
    /* 9EC8 8006D228 02004484 */  lh         $a0, 0x2($v0)
    /* 9ECC 8006D22C FC7B000C */  jal        Skill_GetShotXa
    /* 9ED0 8006D230 00000000 */   nop
    /* 9ED4 8006D234 0000438C */  lw         $v1, 0x0($v0)
    /* 9ED8 8006D238 00000000 */  nop
    /* 9EDC 8006D23C 6800A3AF */  sw         $v1, 0x68($sp)
    /* 9EE0 8006D240 0400428C */  lw         $v0, 0x4($v0)
    /* 9EE4 8006D244 11050424 */  addiu      $a0, $zero, 0x511
    /* 9EE8 8006D248 6C00A2AF */  sw         $v0, 0x6C($sp)
    /* 9EEC 8006D24C 0000228E */  lw         $v0, 0x0($s1)
    /* 9EF0 8006D250 14004526 */  addiu      $a1, $s2, 0x14
    /* 9EF4 8006D254 04004284 */  lh         $v0, 0x4($v0)
    /* 9EF8 8006D258 6800A627 */  addiu      $a2, $sp, 0x68
    /* 9EFC 8006D25C 1F44000C */  jal        Task_Create
    /* 9F00 8006D260 7000A2AF */   sw        $v0, 0x70($sp)
    /* 9F04 8006D264 5945000C */  jal        Task_NextState1
    /* 9F08 8006D268 21208002 */   addu      $a0, $s4, $zero
  .L8006D26C:
    /* 9F0C 8006D26C 1400448E */  lw         $a0, 0x14($s2)
    /* 9F10 8006D270 00000000 */  nop
    /* 9F14 8006D274 1000828C */  lw         $v0, 0x10($a0)
    /* 9F18 8006D278 00000000 */  nop
    /* 9F1C 8006D27C 0E005614 */  bne        $v0, $s6, .L8006D2B8
    /* 9F20 8006D280 00000000 */   nop
    /* 9F24 8006D284 7045000C */  jal        Task_SetState0
    /* 9F28 8006D288 02000524 */   addiu     $a1, $zero, 0x2
    /* 9F2C 8006D28C 21208002 */  addu       $a0, $s4, $zero
    /* 9F30 8006D290 0000228E */  lw         $v0, 0x0($s1)
    /* 9F34 8006D294 21280000 */  addu       $a1, $zero, $zero
    /* 9F38 8006D298 06004224 */  addiu      $v0, $v0, 0x6
  .L8006D29C:
    /* 9F3C 8006D29C 7745000C */  jal        Task_SetState1
    /* 9F40 8006D2A0 000022AE */   sw        $v0, 0x0($s1)
    /* 9F44 8006D2A4 AFB40108 */  j          .L8006D2BC
    /* 9F48 8006D2A8 00000000 */   nop
  jlabel .L8006D2AC
    /* 9F4C 8006D2AC 21208002 */  addu       $a0, $s4, $zero
    /* 9F50 8006D2B0 7045000C */  jal        Task_SetState0
    /* 9F54 8006D2B4 03000524 */   addiu     $a1, $zero, 0x3
  .L8006D2B8:
    /* 9F58 8006D2B8 21980000 */  addu       $s3, $zero, $zero
  .L8006D2BC:
    /* 9F5C 8006D2BC 50FE6016 */  bnez       $s3, .L8006CC00
    /* 9F60 8006D2C0 00000000 */   nop
  .L8006D2C4:
    /* 9F64 8006D2C4 9C00BF8F */  lw         $ra, 0x9C($sp)
    /* 9F68 8006D2C8 9800B68F */  lw         $s6, 0x98($sp)
    /* 9F6C 8006D2CC 9400B58F */  lw         $s5, 0x94($sp)
    /* 9F70 8006D2D0 9000B48F */  lw         $s4, 0x90($sp)
    /* 9F74 8006D2D4 8C00B38F */  lw         $s3, 0x8C($sp)
    /* 9F78 8006D2D8 8800B28F */  lw         $s2, 0x88($sp)
    /* 9F7C 8006D2DC 8400B18F */  lw         $s1, 0x84($sp)
    /* 9F80 8006D2E0 8000B08F */  lw         $s0, 0x80($sp)
    /* 9F84 8006D2E4 0800E003 */  jr         $ra
    /* 9F88 8006D2E8 A000BD27 */   addiu     $sp, $sp, 0xA0
endlabel func_8006CB8C
