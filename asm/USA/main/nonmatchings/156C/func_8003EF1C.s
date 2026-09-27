nonmatching func_8003EF1C, 0x25C

glabel func_8003EF1C
    /* 2F71C 8003EF1C 70FFBD27 */  addiu      $sp, $sp, -0x90
    /* 2F720 8003EF20 8000B6AF */  sw         $s6, 0x80($sp)
    /* 2F724 8003EF24 21B08000 */  addu       $s6, $a0, $zero
    /* 2F728 8003EF28 6C00B1AF */  sw         $s1, 0x6C($sp)
    /* 2F72C 8003EF2C 2188A000 */  addu       $s1, $a1, $zero
    /* 2F730 8003EF30 8400B7AF */  sw         $s7, 0x84($sp)
    /* 2F734 8003EF34 21B8C000 */  addu       $s7, $a2, $zero
    /* 2F738 8003EF38 6800B0AF */  sw         $s0, 0x68($sp)
    /* 2F73C 8003EF3C 0680103C */  lui        $s0, %hi(D_80062F80)
    /* 2F740 8003EF40 802F1026 */  addiu      $s0, $s0, %lo(D_80062F80)
    /* 2F744 8003EF44 8C00BFAF */  sw         $ra, 0x8C($sp)
    /* 2F748 8003EF48 8800BEAF */  sw         $fp, 0x88($sp)
    /* 2F74C 8003EF4C 7C00B5AF */  sw         $s5, 0x7C($sp)
    /* 2F750 8003EF50 7800B4AF */  sw         $s4, 0x78($sp)
    /* 2F754 8003EF54 7400B3AF */  sw         $s3, 0x74($sp)
    /* 2F758 8003EF58 7000B2AF */  sw         $s2, 0x70($sp)
    /* 2F75C 8003EF5C 5C00A7AF */  sw         $a3, 0x5C($sp)
    /* 2F760 8003EF60 0000028E */  lw         $v0, 0x0($s0)
    /* 2F764 8003EF64 A000BE8F */  lw         $fp, 0xA0($sp)
    /* 2F768 8003EF68 06004010 */  beqz       $v0, .L8003EF84
    /* 2F76C 8003EF6C 2120C002 */   addu      $a0, $s6, $zero
    /* 2F770 8003EF70 0180043C */  lui        $a0, %hi(D_80010D18)
    /* 2F774 8003EF74 05A8000C */  jal        printf
    /* 2F778 8003EF78 180D8424 */   addiu     $a0, $a0, %lo(D_80010D18)
    /* 2F77C 8003EF7C 52FC0008 */  j          .L8003F148
    /* 2F780 8003EF80 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L8003EF84:
    /* 2F784 8003EF84 46FD000C */  jal        Card_MakeDevName
    /* 2F788 8003EF88 1000A527 */   addiu     $a1, $sp, 0x10
    /* 2F78C 8003EF8C 1000A427 */  addiu      $a0, $sp, 0x10
    /* 2F790 8003EF90 1DFE000C */  jal        strcat
    /* 2F794 8003EF94 21282002 */   addu      $a1, $s1, $zero
    /* 2F798 8003EF98 21900000 */  addu       $s2, $zero, $zero
    /* 2F79C 8003EF9C 21880000 */  addu       $s1, $zero, $zero
    /* 2F7A0 8003EFA0 01000224 */  addiu      $v0, $zero, 0x1
    /* 2F7A4 8003EFA4 5800A0AF */  sw         $zero, 0x58($sp)
    /* 2F7A8 8003EFA8 0C00038E */  lw         $v1, 0xC($s0)
    /* 2F7AC 8003EFAC 0410C202 */  sllv       $v0, $v0, $s6
    /* 2F7B0 8003EFB0 25186200 */  or         $v1, $v1, $v0
    /* 2F7B4 8003EFB4 0C0003AE */  sw         $v1, 0xC($s0)
    /* 2F7B8 8003EFB8 A400A88F */  lw         $t0, 0xA4($sp)
    /* 2F7BC 8003EFBC 00000000 */  nop
    /* 2F7C0 8003EFC0 2110C803 */  addu       $v0, $fp, $t0
    /* 2F7C4 8003EFC4 5B004018 */  blez       $v0, .L8003F134
    /* 2F7C8 8003EFC8 21A80000 */   addu      $s5, $zero, $zero
    /* 2F7CC 8003EFCC 21980002 */  addu       $s3, $s0, $zero
    /* 2F7D0 8003EFD0 5000A827 */  addiu      $t0, $sp, 0x50
    /* 2F7D4 8003EFD4 6000A8AF */  sw         $t0, 0x60($sp)
    /* 2F7D8 8003EFD8 21A00000 */  addu       $s4, $zero, $zero
  .L8003EFDC:
    /* 2F7DC 8003EFDC 32002016 */  bnez       $s1, .L8003F0A8
    /* 2F7E0 8003EFE0 00000000 */   nop
  .L8003EFE4:
    /* 2F7E4 8003EFE4 A9FF000C */  jal        func_8003FEA4
    /* 2F7E8 8003EFE8 00000000 */   nop
    /* 2F7EC 8003EFEC 1000A427 */  addiu      $a0, $sp, 0x10
    /* 2F7F0 8003EFF0 71FD000C */  jal        func_8003F5C4
    /* 2F7F4 8003EFF4 3000A527 */   addiu     $a1, $sp, 0x30
    /* 2F7F8 8003EFF8 21804000 */  addu       $s0, $v0, $zero
    /* 2F7FC 8003EFFC 2F000016 */  bnez       $s0, .L8003F0BC
    /* 2F800 8003F000 2A103E02 */   slt       $v0, $s1, $fp
    /* 2F804 8003F004 2100010C */  jal        func_80040084
    /* 2F808 8003F008 00000000 */   nop
    /* 2F80C 8003F00C 06FD000C */  jal        func_8003F418
    /* 2F810 8003F010 21204000 */   addu      $a0, $v0, $zero
    /* 2F814 8003F014 27004010 */  beqz       $v0, .L8003F0B4
    /* 2F818 8003F018 5800A2AF */   sw        $v0, 0x58($sp)
    /* 2F81C 8003F01C 01005226 */  addiu      $s2, $s2, 0x1
    /* 2F820 8003F020 0400422A */  slti       $v0, $s2, 0x4
    /* 2F824 8003F024 EFFF4014 */  bnez       $v0, .L8003EFE4
    /* 2F828 8003F028 00000000 */   nop
    /* 2F82C 8003F02C 5EFC000C */  jal        MemCardCallback
    /* 2F830 8003F030 21200000 */   addu      $a0, $zero, $zero
    /* 2F834 8003F034 0000638E */  lw         $v1, 0x0($s3)
    /* 2F838 8003F038 0680013C */  lui        $at, %hi(D_80062FD8)
    /* 2F83C 8003F03C D82F22AC */  sw         $v0, %lo(D_80062FD8)($at)
    /* 2F840 8003F040 06006018 */  blez       $v1, .L8003F05C
    /* 2F844 8003F044 02000824 */   addiu     $t0, $zero, 0x2
    /* 2F848 8003F048 0180043C */  lui        $a0, %hi(D_80010B74)
    /* 2F84C 8003F04C 05A8000C */  jal        printf
    /* 2F850 8003F050 740B8424 */   addiu     $a0, $a0, %lo(D_80010B74)
    /* 2F854 8003F054 20FC0008 */  j          .L8003F080
    /* 2F858 8003F058 21200000 */   addu      $a0, $zero, $zero
  .L8003F05C:
    /* 2F85C 8003F05C 0480043C */  lui        $a0, %hi(func_8003E19C)
    /* 2F860 8003F060 9CE18424 */  addiu      $a0, $a0, %lo(func_8003E19C)
    /* 2F864 8003F064 000068AE */  sw         $t0, 0x0($s3)
    /* 2F868 8003F068 040060AE */  sw         $zero, 0x4($s3)
    /* 2F86C 8003F06C 080060AE */  sw         $zero, 0x8($s3)
    /* 2F870 8003F070 0680013C */  lui        $at, %hi(D_80062F90)
    /* 2F874 8003F074 89FE000C */  jal        Card_PushTask
    /* 2F878 8003F078 902F36AC */   sw        $s6, %lo(D_80062F90)($at)
    /* 2F87C 8003F07C 21200000 */  addu       $a0, $zero, $zero
  .L8003F080:
    /* 2F880 8003F080 21280000 */  addu       $a1, $zero, $zero
    /* 2F884 8003F084 63FC000C */  jal        MemCardSync
    /* 2F888 8003F088 5800A627 */   addiu     $a2, $sp, 0x58
    /* 2F88C 8003F08C 0680043C */  lui        $a0, %hi(D_80062FD8)
    /* 2F890 8003F090 D82F848C */  lw         $a0, %lo(D_80062FD8)($a0)
    /* 2F894 8003F094 5EFC000C */  jal        MemCardCallback
    /* 2F898 8003F098 00000000 */   nop
    /* 2F89C 8003F09C 5800A28F */  lw         $v0, 0x58($sp)
    /* 2F8A0 8003F0A0 52FC0008 */  j          .L8003F148
    /* 2F8A4 8003F0A4 00000000 */   nop
  .L8003F0A8:
    /* 2F8A8 8003F0A8 6DFD000C */  jal        nextfile
    /* 2F8AC 8003F0AC 3000A427 */   addiu     $a0, $sp, 0x30
    /* 2F8B0 8003F0B0 21804000 */  addu       $s0, $v0, $zero
  .L8003F0B4:
    /* 2F8B4 8003F0B4 1F000012 */  beqz       $s0, .L8003F134
    /* 2F8B8 8003F0B8 2A103E02 */   slt       $v0, $s1, $fp
  .L8003F0BC:
    /* 2F8BC 8003F0BC 17004014 */  bnez       $v0, .L8003F11C
    /* 2F8C0 8003F0C0 00000000 */   nop
    /* 2F8C4 8003F0C4 1500E012 */  beqz       $s7, .L8003F11C
    /* 2F8C8 8003F0C8 21389702 */   addu      $a3, $s4, $s7
    /* 2F8CC 8003F0CC 3000A627 */  addiu      $a2, $sp, 0x30
  .L8003F0D0:
    /* 2F8D0 8003F0D0 0000C28C */  lw         $v0, 0x0($a2)
    /* 2F8D4 8003F0D4 0400C38C */  lw         $v1, 0x4($a2)
    /* 2F8D8 8003F0D8 0800C48C */  lw         $a0, 0x8($a2)
    /* 2F8DC 8003F0DC 0C00C58C */  lw         $a1, 0xC($a2)
    /* 2F8E0 8003F0E0 0000E2AC */  sw         $v0, 0x0($a3)
    /* 2F8E4 8003F0E4 0400E3AC */  sw         $v1, 0x4($a3)
    /* 2F8E8 8003F0E8 0800E4AC */  sw         $a0, 0x8($a3)
    /* 2F8EC 8003F0EC 0C00E5AC */  sw         $a1, 0xC($a3)
    /* 2F8F0 8003F0F0 1000C624 */  addiu      $a2, $a2, 0x10
    /* 2F8F4 8003F0F4 6000A88F */  lw         $t0, 0x60($sp)
    /* 2F8F8 8003F0F8 00000000 */  nop
    /* 2F8FC 8003F0FC F4FFC814 */  bne        $a2, $t0, .L8003F0D0
    /* 2F900 8003F100 1000E724 */   addiu     $a3, $a3, 0x10
    /* 2F904 8003F104 0000C28C */  lw         $v0, 0x0($a2)
    /* 2F908 8003F108 0400C38C */  lw         $v1, 0x4($a2)
    /* 2F90C 8003F10C 0000E2AC */  sw         $v0, 0x0($a3)
    /* 2F910 8003F110 0400E3AC */  sw         $v1, 0x4($a3)
    /* 2F914 8003F114 28009426 */  addiu      $s4, $s4, 0x28
    /* 2F918 8003F118 0100B526 */  addiu      $s5, $s5, 0x1
  .L8003F11C:
    /* 2F91C 8003F11C A400A88F */  lw         $t0, 0xA4($sp)
    /* 2F920 8003F120 01003126 */  addiu      $s1, $s1, 0x1
    /* 2F924 8003F124 2110C803 */  addu       $v0, $fp, $t0
    /* 2F928 8003F128 2A102202 */  slt        $v0, $s1, $v0
    /* 2F92C 8003F12C ABFF4014 */  bnez       $v0, .L8003EFDC
    /* 2F930 8003F130 00000000 */   nop
  .L8003F134:
    /* 2F934 8003F134 5C00A88F */  lw         $t0, 0x5C($sp)
    /* 2F938 8003F138 00000000 */  nop
    /* 2F93C 8003F13C 02000011 */  beqz       $t0, .L8003F148
    /* 2F940 8003F140 21100000 */   addu      $v0, $zero, $zero
    /* 2F944 8003F144 000015AD */  sw         $s5, 0x0($t0)
  .L8003F148:
    /* 2F948 8003F148 8C00BF8F */  lw         $ra, 0x8C($sp)
    /* 2F94C 8003F14C 8800BE8F */  lw         $fp, 0x88($sp)
    /* 2F950 8003F150 8400B78F */  lw         $s7, 0x84($sp)
    /* 2F954 8003F154 8000B68F */  lw         $s6, 0x80($sp)
    /* 2F958 8003F158 7C00B58F */  lw         $s5, 0x7C($sp)
    /* 2F95C 8003F15C 7800B48F */  lw         $s4, 0x78($sp)
    /* 2F960 8003F160 7400B38F */  lw         $s3, 0x74($sp)
    /* 2F964 8003F164 7000B28F */  lw         $s2, 0x70($sp)
    /* 2F968 8003F168 6C00B18F */  lw         $s1, 0x6C($sp)
    /* 2F96C 8003F16C 6800B08F */  lw         $s0, 0x68($sp)
    /* 2F970 8003F170 0800E003 */  jr         $ra
    /* 2F974 8003F174 9000BD27 */   addiu     $sp, $sp, 0x90
endlabel func_8003EF1C
