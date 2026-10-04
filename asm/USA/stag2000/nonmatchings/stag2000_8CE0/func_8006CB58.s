nonmatching func_8006CB58, 0x598

glabel func_8006CB58
    /* 97F8 8006CB58 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 97FC 8006CB5C 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 9800 8006CB60 21988000 */  addu       $s3, $a0, $zero
    /* 9804 8006CB64 01000224 */  addiu      $v0, $zero, 0x1
    /* 9808 8006CB68 2400BFAF */  sw         $ra, 0x24($sp)
    /* 980C 8006CB6C 2000B4AF */  sw         $s4, 0x20($sp)
    /* 9810 8006CB70 1800B2AF */  sw         $s2, 0x18($sp)
    /* 9814 8006CB74 1400B1AF */  sw         $s1, 0x14($sp)
    /* 9818 8006CB78 1000B0AF */  sw         $s0, 0x10($sp)
    /* 981C 8006CB7C 2C00708E */  lw         $s0, 0x2C($s3)
    /* 9820 8006CB80 1000718E */  lw         $s1, 0x10($s3)
    /* 9824 8006CB84 3400728E */  lw         $s2, 0x34($s3)
    /* 9828 8006CB88 43002212 */  beq        $s1, $v0, .L8006CC98
    /* 982C 8006CB8C 0200222A */   slti      $v0, $s1, 0x2
    /* 9830 8006CB90 4F014010 */  beqz       $v0, .L8006D0D0
    /* 9834 8006CB94 00000000 */   nop
    /* 9838 8006CB98 4D012016 */  bnez       $s1, .L8006D0D0
    /* 983C 8006CB9C 00000000 */   nop
    /* 9840 8006CBA0 21200002 */  addu       $a0, $s0, $zero
    /* 9844 8006CBA4 2270000C */  jal        Mem_FillWordsNeg1
    /* 9848 8006CBA8 0F000524 */   addiu     $a1, $zero, 0xF
    /* 984C 8006CBAC 0D030424 */  addiu      $a0, $zero, 0x30D
    /* 9850 8006CBB0 21284002 */  addu       $a1, $s2, $zero
    /* 9854 8006CBB4 1F44000C */  jal        Task_Create
    /* 9858 8006CBB8 21300000 */   addu      $a2, $zero, $zero
    /* 985C 8006CBBC 21200002 */  addu       $a0, $s0, $zero
    /* 9860 8006CBC0 2D010524 */  addiu      $a1, $zero, 0x12D
    /* 9864 8006CBC4 04000624 */  addiu      $a2, $zero, 0x4
    /* 9868 8006CBC8 0780023C */  lui        $v0, %hi(D_800704E4)
    /* 986C 8006CBCC E4045124 */  addiu      $s1, $v0, %lo(D_800704E4)
    /* 9870 8006CBD0 02002796 */  lhu        $a3, 0x2($s1)
    /* 9874 8006CBD4 E4044294 */  lhu        $v0, %lo(D_800704E4)($v0)
    /* 9878 8006CBD8 003C0700 */  sll        $a3, $a3, 16
    /* 987C 8006CBDC F26F000C */  jal        Text_OpenById
    /* 9880 8006CBE0 25384700 */   or        $a3, $v0, $a3
    /* 9884 8006CBE4 04000426 */  addiu      $a0, $s0, 0x4
    /* 9888 8006CBE8 0780023C */  lui        $v0, %hi(D_800709B0)
    /* 988C 8006CBEC B0095224 */  addiu      $s2, $v0, %lo(D_800709B0)
    /* 9890 8006CBF0 04000624 */  addiu      $a2, $zero, 0x4
    /* 9894 8006CBF4 5400458E */  lw         $a1, 0x54($s2)
    /* 9898 8006CBF8 06002796 */  lhu        $a3, 0x6($s1)
    /* 989C 8006CBFC 04002296 */  lhu        $v0, 0x4($s1)
    /* 98A0 8006CC00 2B01A524 */  addiu      $a1, $a1, 0x12B
    /* 98A4 8006CC04 003C0700 */  sll        $a3, $a3, 16
    /* 98A8 8006CC08 F26F000C */  jal        Text_OpenById
    /* 98AC 8006CC0C 25384700 */   or        $a3, $v0, $a3
    /* 98B0 8006CC10 08000426 */  addiu      $a0, $s0, 0x8
    /* 98B4 8006CC14 FA000524 */  addiu      $a1, $zero, 0xFA
    /* 98B8 8006CC18 21300000 */  addu       $a2, $zero, $zero
    /* 98BC 8006CC1C 0A002796 */  lhu        $a3, 0xA($s1)
    /* 98C0 8006CC20 08002296 */  lhu        $v0, 0x8($s1)
    /* 98C4 8006CC24 003C0700 */  sll        $a3, $a3, 16
    /* 98C8 8006CC28 F26F000C */  jal        Text_OpenById
    /* 98CC 8006CC2C 25384700 */   or        $a3, $v0, $a3
    /* 98D0 8006CC30 5400428E */  lw         $v0, 0x54($s2)
    /* 98D4 8006CC34 00000000 */  nop
    /* 98D8 8006CC38 11004014 */  bnez       $v0, .L8006CC80
    /* 98DC 8006CC3C 0C000426 */   addiu     $a0, $s0, 0xC
    /* 98E0 8006CC40 2E010524 */  addiu      $a1, $zero, 0x12E
    /* 98E4 8006CC44 21300000 */  addu       $a2, $zero, $zero
    /* 98E8 8006CC48 0E002796 */  lhu        $a3, 0xE($s1)
    /* 98EC 8006CC4C 0C002296 */  lhu        $v0, 0xC($s1)
    /* 98F0 8006CC50 003C0700 */  sll        $a3, $a3, 16
    /* 98F4 8006CC54 F26F000C */  jal        Text_OpenById
    /* 98F8 8006CC58 25384700 */   or        $a3, $v0, $a3
    /* 98FC 8006CC5C 5400428E */  lw         $v0, 0x54($s2)
    /* 9900 8006CC60 00000000 */  nop
    /* 9904 8006CC64 06004014 */  bnez       $v0, .L8006CC80
    /* 9908 8006CC68 0680023C */   lui       $v0, %hi(D_8005F794)
    /* 990C 8006CC6C 94F7458C */  lw         $a1, %lo(D_8005F794)($v0)
    /* 9910 8006CC70 45B1010C */  jal        func_8006C514
    /* 9914 8006CC74 21206002 */   addu      $a0, $s3, $zero
    /* 9918 8006CC78 22B30108 */  j          .L8006CC88
    /* 991C 8006CC7C 00000000 */   nop
  .L8006CC80:
    /* 9920 8006CC80 BCB1010C */  jal        func_8006C6F0
    /* 9924 8006CC84 21206002 */   addu      $a0, $s3, $zero
  .L8006CC88:
    /* 9928 8006CC88 5145000C */  jal        Task_NextState0
    /* 992C 8006CC8C 21206002 */   addu      $a0, $s3, $zero
    /* 9930 8006CC90 34B40108 */  j          .L8006D0D0
    /* 9934 8006CC94 00000000 */   nop
  .L8006CC98:
    /* 9938 8006CC98 1400638E */  lw         $v1, 0x14($s3)
    /* 993C 8006CC9C 00000000 */  nop
    /* 9940 8006CCA0 71007110 */  beq        $v1, $s1, .L8006CE68
    /* 9944 8006CCA4 02006228 */   slti      $v0, $v1, 0x2
    /* 9948 8006CCA8 03004014 */  bnez       $v0, .L8006CCB8
    /* 994C 8006CCAC 02000224 */   addiu     $v0, $zero, 0x2
    /* 9950 8006CCB0 CC006210 */  beq        $v1, $v0, .L8006CFE4
    /* 9954 8006CCB4 00000000 */   nop
  .L8006CCB8:
    /* 9958 8006CCB8 1800628E */  lw         $v0, 0x18($s3)
    /* 995C 8006CCBC 00000000 */  nop
    /* 9960 8006CCC0 03004010 */  beqz       $v0, .L8006CCD0
    /* 9964 8006CCC4 00000000 */   nop
    /* 9968 8006CCC8 05005110 */  beq        $v0, $s1, .L8006CCE0
    /* 996C 8006CCCC 38010224 */   addiu     $v0, $zero, 0x138
  .L8006CCD0:
    /* 9970 8006CCD0 3C0011AE */  sw         $s1, 0x3C($s0)
    /* 9974 8006CCD4 6045000C */  jal        Task_NextState2
    /* 9978 8006CCD8 21206002 */   addu      $a0, $s3, $zero
    /* 997C 8006CCDC 38010224 */  addiu      $v0, $zero, 0x138
  .L8006CCE0:
    /* 9980 8006CCE0 5C0002AE */  sw         $v0, 0x5C($s0)
    /* 9984 8006CCE4 600000AE */  sw         $zero, 0x60($s0)
    /* 9988 8006CCE8 0780063C */  lui        $a2, %hi(D_800709B8)
    /* 998C 8006CCEC 0680053C */  lui        $a1, %hi(Pad_State)
    /* 9990 8006CCF0 F0F6A424 */  addiu      $a0, $a1, %lo(Pad_State)
    /* 9994 8006CCF4 3C008394 */  lhu        $v1, 0x3C($a0)
    /* 9998 8006CCF8 00000000 */  nop
    /* 999C 8006CCFC 00106230 */  andi       $v0, $v1, 0x1000
    /* 99A0 8006CD00 05004010 */  beqz       $v0, .L8006CD18
    /* 99A4 8006CD04 B809C724 */   addiu     $a3, $a2, %lo(D_800709B8)
    /* 99A8 8006CD08 4000028E */  lw         $v0, 0x40($s0)
    /* 99AC 8006CD0C 00000000 */  nop
    /* 99B0 8006CD10 99004014 */  bnez       $v0, .L8006CF78
    /* 99B4 8006CD14 00000000 */   nop
  .L8006CD18:
    /* 99B8 8006CD18 00406230 */  andi       $v0, $v1, 0x4000
    /* 99BC 8006CD1C 05004010 */  beqz       $v0, .L8006CD34
    /* 99C0 8006CD20 07000224 */   addiu     $v0, $zero, 0x7
    /* 99C4 8006CD24 4000038E */  lw         $v1, 0x40($s0)
    /* 99C8 8006CD28 00000000 */  nop
    /* 99CC 8006CD2C 96006214 */  bne        $v1, $v0, .L8006CF88
    /* 99D0 8006CD30 01006224 */   addiu     $v0, $v1, 0x1
  .L8006CD34:
    /* 99D4 8006CD34 F0F6A28C */  lw         $v0, %lo(Pad_State)($a1)
    /* 99D8 8006CD38 00000000 */  nop
    /* 99DC 8006CD3C 0A004018 */  blez       $v0, .L8006CD68
    /* 99E0 8006CD40 21188000 */   addu      $v1, $a0, $zero
    /* 99E4 8006CD44 4400038E */  lw         $v1, 0x44($s0)
    /* 99E8 8006CD48 4C00028E */  lw         $v0, 0x4C($s0)
    /* 99EC 8006CD4C 00000000 */  nop
    /* 99F0 8006CD50 DD006210 */  beq        $v1, $v0, .L8006D0C8
    /* 99F4 8006CD54 0D000424 */   addiu     $a0, $zero, 0xD
    /* 99F8 8006CD58 21280000 */  addu       $a1, $zero, $zero
    /* 99FC 8006CD5C 01006224 */  addiu      $v0, $v1, 0x1
    /* 9A00 8006CD60 E5B30108 */  j          .L8006CF94
    /* 9A04 8006CD64 440002AE */   sw        $v0, 0x44($s0)
  .L8006CD68:
    /* 9A08 8006CD68 0400628C */  lw         $v0, 0x4($v1)
    /* 9A0C 8006CD6C 00000000 */  nop
    /* 9A10 8006CD70 09004018 */  blez       $v0, .L8006CD98
    /* 9A14 8006CD74 00000000 */   nop
    /* 9A18 8006CD78 4400028E */  lw         $v0, 0x44($s0)
    /* 9A1C 8006CD7C 00000000 */  nop
    /* 9A20 8006CD80 D1004010 */  beqz       $v0, .L8006D0C8
    /* 9A24 8006CD84 0D000424 */   addiu     $a0, $zero, 0xD
    /* 9A28 8006CD88 21280000 */  addu       $a1, $zero, $zero
    /* 9A2C 8006CD8C FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 9A30 8006CD90 E5B30108 */  j          .L8006CF94
    /* 9A34 8006CD94 440002AE */   sw        $v0, 0x44($s0)
  .L8006CD98:
    /* 9A38 8006CD98 1C00828C */  lw         $v0, 0x1C($a0)
    /* 9A3C 8006CD9C 00000000 */  nop
    /* 9A40 8006CDA0 8100401C */  bgtz       $v0, .L8006CFA8
    /* 9A44 8006CDA4 01000224 */   addiu     $v0, $zero, 0x1
    /* 9A48 8006CDA8 1400828C */  lw         $v0, 0x14($a0)
    /* 9A4C 8006CDAC 00000000 */  nop
    /* 9A50 8006CDB0 C5004018 */  blez       $v0, .L8006D0C8
    /* 9A54 8006CDB4 00000000 */   nop
    /* 9A58 8006CDB8 4C00E28C */  lw         $v0, 0x4C($a3)
    /* 9A5C 8006CDBC 00000000 */  nop
    /* 9A60 8006CDC0 18004014 */  bnez       $v0, .L8006CE24
    /* 9A64 8006CDC4 0780043C */   lui       $a0, %hi(D_80070A08)
    /* 9A68 8006CDC8 080A8424 */  addiu      $a0, $a0, %lo(D_80070A08)
    /* 9A6C 8006CDCC 4400038E */  lw         $v1, 0x44($s0)
    /* 9A70 8006CDD0 4000028E */  lw         $v0, 0x40($s0)
    /* 9A74 8006CDD4 C0180300 */  sll        $v1, $v1, 3
    /* 9A78 8006CDD8 21104300 */  addu       $v0, $v0, $v1
    /* 9A7C 8006CDDC 40100200 */  sll        $v0, $v0, 1
    /* 9A80 8006CDE0 21104400 */  addu       $v0, $v0, $a0
    /* 9A84 8006CDE4 00004484 */  lh         $a0, 0x0($v0)
    /* 9A88 8006CDE8 00000000 */  nop
    /* 9A8C 8006CDEC B6008010 */  beqz       $a0, .L8006D0C8
    /* 9A90 8006CDF0 00000000 */   nop
    /* 9A94 8006CDF4 6078000C */  jal        Item_GetPrice
    /* 9A98 8006CDF8 00000000 */   nop
    /* 9A9C 8006CDFC 0680033C */  lui        $v1, %hi(D_8005E628)
    /* 9AA0 8006CE00 28E6638C */  lw         $v1, %lo(D_8005E628)($v1)
    /* 9AA4 8006CE04 00000000 */  nop
    /* 9AA8 8006CE08 2A186200 */  slt        $v1, $v1, $v0
    /* 9AAC 8006CE0C 71006010 */  beqz       $v1, .L8006CFD4
    /* 9AB0 8006CE10 10000424 */   addiu     $a0, $zero, 0x10
    /* 9AB4 8006CE14 21280000 */  addu       $a1, $zero, $zero
    /* 9AB8 8006CE18 39010224 */  addiu      $v0, $zero, 0x139
    /* 9ABC 8006CE1C E5B30108 */  j          .L8006CF94
    /* 9AC0 8006CE20 5C0002AE */   sw        $v0, 0x5C($s0)
  .L8006CE24:
    /* 9AC4 8006CE24 080A8424 */  addiu      $a0, $a0, %lo(D_80070A08)
    /* 9AC8 8006CE28 4400038E */  lw         $v1, 0x44($s0)
    /* 9ACC 8006CE2C 4000028E */  lw         $v0, 0x40($s0)
    /* 9AD0 8006CE30 C0180300 */  sll        $v1, $v1, 3
    /* 9AD4 8006CE34 21104300 */  addu       $v0, $v0, $v1
    /* 9AD8 8006CE38 40100200 */  sll        $v0, $v0, 1
    /* 9ADC 8006CE3C 21104400 */  addu       $v0, $v0, $a0
    /* 9AE0 8006CE40 00004484 */  lh         $a0, 0x0($v0)
    /* 9AE4 8006CE44 00000000 */  nop
    /* 9AE8 8006CE48 9F008010 */  beqz       $a0, .L8006D0C8
    /* 9AEC 8006CE4C 00000000 */   nop
    /* 9AF0 8006CE50 6078000C */  jal        Item_GetPrice
    /* 9AF4 8006CE54 00000000 */   nop
    /* 9AF8 8006CE58 5C004014 */  bnez       $v0, .L8006CFCC
    /* 9AFC 8006CE5C 10000424 */   addiu     $a0, $zero, 0x10
    /* 9B00 8006CE60 EFB30108 */  j          .L8006CFBC
    /* 9B04 8006CE64 00000000 */   nop
  .L8006CE68:
    /* 9B08 8006CE68 0780043C */  lui        $a0, %hi(D_80070A08)
    /* 9B0C 8006CE6C 080A8424 */  addiu      $a0, $a0, %lo(D_80070A08)
    /* 9B10 8006CE70 4400038E */  lw         $v1, 0x44($s0)
    /* 9B14 8006CE74 4000028E */  lw         $v0, 0x40($s0)
    /* 9B18 8006CE78 C0180300 */  sll        $v1, $v1, 3
    /* 9B1C 8006CE7C 21104300 */  addu       $v0, $v0, $v1
    /* 9B20 8006CE80 40100200 */  sll        $v0, $v0, 1
    /* 9B24 8006CE84 21104400 */  addu       $v0, $v0, $a0
    /* 9B28 8006CE88 1800638E */  lw         $v1, 0x18($s3)
    /* 9B2C 8006CE8C 00005284 */  lh         $s2, 0x0($v0)
    /* 9B30 8006CE90 03006010 */  beqz       $v1, .L8006CEA0
    /* 9B34 8006CE94 00000000 */   nop
    /* 9B38 8006CE98 0C007110 */  beq        $v1, $s1, .L8006CECC
    /* 9B3C 8006CE9C 00000000 */   nop
  .L8006CEA0:
    /* 9B40 8006CEA0 71B0010C */  jal        func_8006C1C4
    /* 9B44 8006CEA4 21204002 */   addu      $a0, $s2, $zero
    /* 9B48 8006CEA8 10000424 */  addiu      $a0, $zero, 0x10
    /* 9B4C 8006CEAC 21280000 */  addu       $a1, $zero, $zero
    /* 9B50 8006CEB0 5C0002AE */  sw         $v0, 0x5C($s0)
    /* 9B54 8006CEB4 37010224 */  addiu      $v0, $zero, 0x137
    /* 9B58 8006CEB8 600002AE */  sw         $v0, 0x60($s0)
    /* 9B5C 8006CEBC 7188000C */  jal        Flag_Set
    /* 9B60 8006CEC0 3C0011AE */   sw        $s1, 0x3C($s0)
    /* 9B64 8006CEC4 6045000C */  jal        Task_NextState2
    /* 9B68 8006CEC8 21206002 */   addu      $a0, $s3, $zero
  .L8006CECC:
    /* 9B6C 8006CECC 9E87000C */  jal        Flag_Test
    /* 9B70 8006CED0 10000424 */   addiu     $a0, $zero, 0x10
    /* 9B74 8006CED4 1C004010 */  beqz       $v0, .L8006CF48
    /* 9B78 8006CED8 0680023C */   lui       $v0, %hi(D_8005F70C)
    /* 9B7C 8006CEDC 9E87000C */  jal        Flag_Test
    /* 9B80 8006CEE0 11000424 */   addiu     $a0, $zero, 0x11
    /* 9B84 8006CEE4 18004014 */  bnez       $v0, .L8006CF48
    /* 9B88 8006CEE8 0680023C */   lui       $v0, %hi(D_8005F70C)
    /* 9B8C 8006CEEC 0F000424 */  addiu      $a0, $zero, 0xF
    /* 9B90 8006CEF0 A369000C */  jal        Snd_PlayById
    /* 9B94 8006CEF4 21280000 */   addu      $a1, $zero, $zero
    /* 9B98 8006CEF8 0680023C */  lui        $v0, %hi(Save_GameState)
    /* 9B9C 8006CEFC 20E64224 */  addiu      $v0, $v0, %lo(Save_GameState)
    /* 9BA0 8006CF00 40181200 */  sll        $v1, $s2, 1
    /* 9BA4 8006CF04 21186200 */  addu       $v1, $v1, $v0
    /* 9BA8 8006CF08 D40D6494 */  lhu        $a0, 0xDD4($v1)
    /* 9BAC 8006CF0C 63000224 */  addiu      $v0, $zero, 0x63
    /* 9BB0 8006CF10 02008214 */  bne        $a0, $v0, .L8006CF1C
    /* 9BB4 8006CF14 01008224 */   addiu     $v0, $a0, 0x1
    /* 9BB8 8006CF18 63000224 */  addiu      $v0, $zero, 0x63
  .L8006CF1C:
    /* 9BBC 8006CF1C 21204002 */  addu       $a0, $s2, $zero
    /* 9BC0 8006CF20 6078000C */  jal        Item_GetPrice
    /* 9BC4 8006CF24 D40D62A4 */   sh        $v0, 0xDD4($v1)
    /* 9BC8 8006CF28 21206002 */  addu       $a0, $s3, $zero
    /* 9BCC 8006CF2C 0680063C */  lui        $a2, %hi(Save_GameState)
    /* 9BD0 8006CF30 20E6C624 */  addiu      $a2, $a2, %lo(Save_GameState)
    /* 9BD4 8006CF34 0800C38C */  lw         $v1, 0x8($a2)
    /* 9BD8 8006CF38 21280000 */  addu       $a1, $zero, $zero
    /* 9BDC 8006CF3C 23186200 */  subu       $v1, $v1, $v0
    /* 9BE0 8006CF40 30B40108 */  j          .L8006D0C0
    /* 9BE4 8006CF44 0800C3AC */   sw        $v1, 0x8($a2)
  .L8006CF48:
    /* 9BE8 8006CF48 0CF7428C */  lw         $v0, %lo(D_8005F70C)($v0)
    /* 9BEC 8006CF4C 00000000 */  nop
    /* 9BF0 8006CF50 0500401C */  bgtz       $v0, .L8006CF68
    /* 9BF4 8006CF54 0B000424 */   addiu     $a0, $zero, 0xB
    /* 9BF8 8006CF58 9E87000C */  jal        Flag_Test
    /* 9BFC 8006CF5C 10000424 */   addiu     $a0, $zero, 0x10
    /* 9C00 8006CF60 59004010 */  beqz       $v0, .L8006D0C8
    /* 9C04 8006CF64 0B000424 */   addiu     $a0, $zero, 0xB
  .L8006CF68:
    /* 9C08 8006CF68 A369000C */  jal        Snd_PlayById
    /* 9C0C 8006CF6C 21280000 */   addu      $a1, $zero, $zero
    /* 9C10 8006CF70 2FB40108 */  j          .L8006D0BC
    /* 9C14 8006CF74 21206002 */   addu      $a0, $s3, $zero
  .L8006CF78:
    /* 9C18 8006CF78 0D000424 */  addiu      $a0, $zero, 0xD
    /* 9C1C 8006CF7C 21280000 */  addu       $a1, $zero, $zero
    /* 9C20 8006CF80 E4B30108 */  j          .L8006CF90
    /* 9C24 8006CF84 FFFF4224 */   addiu     $v0, $v0, -0x1
  .L8006CF88:
    /* 9C28 8006CF88 0D000424 */  addiu      $a0, $zero, 0xD
    /* 9C2C 8006CF8C 21280000 */  addu       $a1, $zero, $zero
  .L8006CF90:
    /* 9C30 8006CF90 400002AE */  sw         $v0, 0x40($s0)
  .L8006CF94:
    /* 9C34 8006CF94 01000224 */  addiu      $v0, $zero, 0x1
    /* 9C38 8006CF98 A369000C */  jal        Snd_PlayById
    /* 9C3C 8006CF9C 3C0002AE */   sw        $v0, 0x3C($s0)
    /* 9C40 8006CFA0 32B40108 */  j          .L8006D0C8
    /* 9C44 8006CFA4 00000000 */   nop
  .L8006CFA8:
    /* 9C48 8006CFA8 B809C2AC */  sw         $v0, %lo(D_800709B8)($a2)
    /* 9C4C 8006CFAC 21206002 */  addu       $a0, $s3, $zero
    /* 9C50 8006CFB0 7045000C */  jal        Task_SetState0
    /* 9C54 8006CFB4 03000524 */   addiu     $a1, $zero, 0x3
    /* 9C58 8006CFB8 0B000424 */  addiu      $a0, $zero, 0xB
  .L8006CFBC:
    /* 9C5C 8006CFBC A369000C */  jal        Snd_PlayById
    /* 9C60 8006CFC0 21280000 */   addu      $a1, $zero, $zero
    /* 9C64 8006CFC4 32B40108 */  j          .L8006D0C8
    /* 9C68 8006CFC8 00000000 */   nop
  .L8006CFCC:
    /* 9C6C 8006CFCC 5945000C */  jal        Task_NextState1
    /* 9C70 8006CFD0 21206002 */   addu      $a0, $s3, $zero
  .L8006CFD4:
    /* 9C74 8006CFD4 5945000C */  jal        Task_NextState1
    /* 9C78 8006CFD8 21206002 */   addu      $a0, $s3, $zero
    /* 9C7C 8006CFDC 32B40108 */  j          .L8006D0C8
    /* 9C80 8006CFE0 00000000 */   nop
  .L8006CFE4:
    /* 9C84 8006CFE4 4400028E */  lw         $v0, 0x44($s0)
    /* 9C88 8006CFE8 4000038E */  lw         $v1, 0x40($s0)
    /* 9C8C 8006CFEC C0100200 */  sll        $v0, $v0, 3
    /* 9C90 8006CFF0 21A06200 */  addu       $s4, $v1, $v0
    /* 9C94 8006CFF4 0780023C */  lui        $v0, %hi(D_80070A08)
    /* 9C98 8006CFF8 080A4224 */  addiu      $v0, $v0, %lo(D_80070A08)
    /* 9C9C 8006CFFC 40181400 */  sll        $v1, $s4, 1
    /* 9CA0 8006D000 21186200 */  addu       $v1, $v1, $v0
    /* 9CA4 8006D004 1800628E */  lw         $v0, 0x18($s3)
    /* 9CA8 8006D008 00007284 */  lh         $s2, 0x0($v1)
    /* 9CAC 8006D00C 03004010 */  beqz       $v0, .L8006D01C
    /* 9CB0 8006D010 10000424 */   addiu     $a0, $zero, 0x10
    /* 9CB4 8006D014 09005110 */  beq        $v0, $s1, .L8006D03C
    /* 9CB8 8006D018 00000000 */   nop
  .L8006D01C:
    /* 9CBC 8006D01C 21280000 */  addu       $a1, $zero, $zero
    /* 9CC0 8006D020 3A010224 */  addiu      $v0, $zero, 0x13A
    /* 9CC4 8006D024 5C0002AE */  sw         $v0, 0x5C($s0)
    /* 9CC8 8006D028 600000AE */  sw         $zero, 0x60($s0)
    /* 9CCC 8006D02C 7188000C */  jal        Flag_Set
    /* 9CD0 8006D030 3C0011AE */   sw        $s1, 0x3C($s0)
    /* 9CD4 8006D034 6045000C */  jal        Task_NextState2
    /* 9CD8 8006D038 21206002 */   addu      $a0, $s3, $zero
  .L8006D03C:
    /* 9CDC 8006D03C 9E87000C */  jal        Flag_Test
    /* 9CE0 8006D040 10000424 */   addiu     $a0, $zero, 0x10
    /* 9CE4 8006D044 20004010 */  beqz       $v0, .L8006D0C8
    /* 9CE8 8006D048 00000000 */   nop
    /* 9CEC 8006D04C 9E87000C */  jal        Flag_Test
    /* 9CF0 8006D050 11000424 */   addiu     $a0, $zero, 0x11
    /* 9CF4 8006D054 18004014 */  bnez       $v0, .L8006D0B8
    /* 9CF8 8006D058 00000000 */   nop
    /* 9CFC 8006D05C 0F000424 */  addiu      $a0, $zero, 0xF
    /* 9D00 8006D060 A369000C */  jal        Snd_PlayById
    /* 9D04 8006D064 21280000 */   addu      $a1, $zero, $zero
    /* 9D08 8006D068 6078000C */  jal        Item_GetPrice
    /* 9D0C 8006D06C 21204002 */   addu      $a0, $s2, $zero
    /* 9D10 8006D070 F505053C */  lui        $a1, (0x5F5E0FF >> 16)
    /* 9D14 8006D074 FFE0A534 */  ori        $a1, $a1, (0x5F5E0FF & 0xFFFF)
    /* 9D18 8006D078 0680033C */  lui        $v1, %hi(Save_GameState)
    /* 9D1C 8006D07C 20E66424 */  addiu      $a0, $v1, %lo(Save_GameState)
    /* 9D20 8006D080 C21F0200 */  srl        $v1, $v0, 31
    /* 9D24 8006D084 21186200 */  addu       $v1, $v1, $v0
    /* 9D28 8006D088 0800828C */  lw         $v0, 0x8($a0)
    /* 9D2C 8006D08C 43180300 */  sra        $v1, $v1, 1
    /* 9D30 8006D090 21104300 */  addu       $v0, $v0, $v1
    /* 9D34 8006D094 080082AC */  sw         $v0, 0x8($a0)
    /* 9D38 8006D098 2A10A200 */  slt        $v0, $a1, $v0
    /* 9D3C 8006D09C 02004010 */  beqz       $v0, .L8006D0A8
    /* 9D40 8006D0A0 00000000 */   nop
    /* 9D44 8006D0A4 080085AC */  sw         $a1, 0x8($a0)
  .L8006D0A8:
    /* 9D48 8006D0A8 FC89000C */  jal        Item_RemoveFromBag
    /* 9D4C 8006D0AC 21208002 */   addu      $a0, $s4, $zero
    /* 9D50 8006D0B0 BCB1010C */  jal        func_8006C6F0
    /* 9D54 8006D0B4 21206002 */   addu      $a0, $s3, $zero
  .L8006D0B8:
    /* 9D58 8006D0B8 21206002 */  addu       $a0, $s3, $zero
  .L8006D0BC:
    /* 9D5C 8006D0BC 21280000 */  addu       $a1, $zero, $zero
  .L8006D0C0:
    /* 9D60 8006D0C0 7745000C */  jal        Task_SetState1
    /* 9D64 8006D0C4 00000000 */   nop
  .L8006D0C8:
    /* 9D68 8006D0C8 2FB2010C */  jal        func_8006C8BC
    /* 9D6C 8006D0CC 21206002 */   addu      $a0, $s3, $zero
  .L8006D0D0:
    /* 9D70 8006D0D0 2400BF8F */  lw         $ra, 0x24($sp)
    /* 9D74 8006D0D4 2000B48F */  lw         $s4, 0x20($sp)
    /* 9D78 8006D0D8 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 9D7C 8006D0DC 1800B28F */  lw         $s2, 0x18($sp)
    /* 9D80 8006D0E0 1400B18F */  lw         $s1, 0x14($sp)
    /* 9D84 8006D0E4 1000B08F */  lw         $s0, 0x10($sp)
    /* 9D88 8006D0E8 0800E003 */  jr         $ra
    /* 9D8C 8006D0EC 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8006CB58
