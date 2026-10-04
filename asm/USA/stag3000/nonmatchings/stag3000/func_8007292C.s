nonmatching func_8007292C, 0x658

glabel func_8007292C
    /* F5CC 8007292C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* F5D0 80072930 2000B2AF */  sw         $s2, 0x20($sp)
    /* F5D4 80072934 21908000 */  addu       $s2, $a0, $zero
    /* F5D8 80072938 01000224 */  addiu      $v0, $zero, 0x1
    /* F5DC 8007293C 2400BFAF */  sw         $ra, 0x24($sp)
    /* F5E0 80072940 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* F5E4 80072944 1800B0AF */  sw         $s0, 0x18($sp)
    /* F5E8 80072948 2C00518E */  lw         $s1, 0x2C($s2)
    /* F5EC 8007294C 1000438E */  lw         $v1, 0x10($s2)
    /* F5F0 80072950 3400508E */  lw         $s0, 0x34($s2)
    /* F5F4 80072954 15006210 */  beq        $v1, $v0, .L800729AC
    /* F5F8 80072958 02006228 */   slti      $v0, $v1, 0x2
    /* F5FC 8007295C 05004010 */  beqz       $v0, .L80072974
    /* F600 80072960 00000000 */   nop
    /* F604 80072964 08006010 */  beqz       $v1, .L80072988
    /* F608 80072968 04002426 */   addiu     $a0, $s1, 0x4
    /* F60C 8007296C DBCB0108 */  j          .L80072F6C
    /* F610 80072970 00000000 */   nop
  .L80072974:
    /* F614 80072974 02000224 */  addiu      $v0, $zero, 0x2
    /* F618 80072978 77016210 */  beq        $v1, $v0, .L80072F58
    /* F61C 8007297C 04002426 */   addiu     $a0, $s1, 0x4
    /* F620 80072980 DBCB0108 */  j          .L80072F6C
    /* F624 80072984 00000000 */   nop
  .L80072988:
    /* F628 80072988 2270000C */  jal        Mem_FillWordsNeg1
    /* F62C 8007298C 02000524 */   addiu     $a1, $zero, 0x2
    /* F630 80072990 09050424 */  addiu      $a0, $zero, 0x509
    /* F634 80072994 0000268E */  lw         $a2, 0x0($s1)
    /* F638 80072998 4445000C */  jal        Task_FindFirst
    /* F63C 8007299C FFFF0524 */   addiu     $a1, $zero, -0x1
    /* F640 800729A0 21204002 */  addu       $a0, $s2, $zero
    /* F644 800729A4 D9CB0108 */  j          .L80072F64
    /* F648 800729A8 0C0022AE */   sw        $v0, 0xC($s1)
  .L800729AC:
    /* F64C 800729AC 1400438E */  lw         $v1, 0x14($s2)
    /* F650 800729B0 00000000 */  nop
    /* F654 800729B4 0900622C */  sltiu      $v0, $v1, 0x9
    /* F658 800729B8 08004010 */  beqz       $v0, .L800729DC
    /* F65C 800729BC 0680023C */   lui       $v0, %hi(jtbl_80063874)
    /* F660 800729C0 74384224 */  addiu      $v0, $v0, %lo(jtbl_80063874)
    /* F664 800729C4 80180300 */  sll        $v1, $v1, 2
    /* F668 800729C8 21186200 */  addu       $v1, $v1, $v0
    /* F66C 800729CC 0000628C */  lw         $v0, 0x0($v1)
    /* F670 800729D0 00000000 */  nop
    /* F674 800729D4 08004000 */  jr         $v0
    /* F678 800729D8 00000000 */   nop
  jlabel .L800729DC
    /* F67C 800729DC 0000248E */  lw         $a0, 0x0($s1)
    /* F680 800729E0 45C3010C */  jal        func_80070D14
    /* F684 800729E4 02008424 */   addiu     $a0, $a0, 0x2
    /* F688 800729E8 0C00248E */  lw         $a0, 0xC($s1)
    /* F68C 800729EC 90BD010C */  jal        func_8006F640
    /* F690 800729F0 01000524 */   addiu     $a1, $zero, 0x1
    /* F694 800729F4 21204002 */  addu       $a0, $s2, $zero
    /* F698 800729F8 5945000C */  jal        Task_NextState1
    /* F69C 800729FC 280040AE */   sw        $zero, 0x28($s2)
  jlabel .L80072A00
    /* F6A0 80072A00 1800438E */  lw         $v1, 0x18($s2)
    /* F6A4 80072A04 00000000 */  nop
    /* F6A8 80072A08 03006010 */  beqz       $v1, .L80072A18
    /* F6AC 80072A0C 01000224 */   addiu     $v0, $zero, 0x1
    /* F6B0 80072A10 1C006210 */  beq        $v1, $v0, .L80072A84
    /* F6B4 80072A14 00000000 */   nop
  .L80072A18:
    /* F6B8 80072A18 2800428E */  lw         $v0, 0x28($s2)
    /* F6BC 80072A1C 00000000 */  nop
    /* F6C0 80072A20 15004228 */  slti       $v0, $v0, 0x15
    /* F6C4 80072A24 51014014 */  bnez       $v0, .L80072F6C
    /* F6C8 80072A28 09050424 */   addiu     $a0, $zero, 0x509
    /* F6CC 80072A2C FFFF0524 */  addiu      $a1, $zero, -0x1
    /* F6D0 80072A30 4445000C */  jal        Task_FindFirst
    /* F6D4 80072A34 2130A000 */   addu      $a2, $a1, $zero
    /* F6D8 80072A38 21804000 */  addu       $s0, $v0, $zero
    /* F6DC 80072A3C 1B010012 */  beqz       $s0, .L80072EAC
    /* F6E0 80072A40 00000000 */   nop
  .L80072A44:
    /* F6E4 80072A44 0800028E */  lw         $v0, 0x8($s0)
    /* F6E8 80072A48 00000000 */  nop
    /* F6EC 80072A4C 03004228 */  slti       $v0, $v0, 0x3
    /* F6F0 80072A50 05004010 */  beqz       $v0, .L80072A68
    /* F6F4 80072A54 21200002 */   addu      $a0, $s0, $zero
    /* F6F8 80072A58 90BD010C */  jal        func_8006F640
    /* F6FC 80072A5C 21280000 */   addu      $a1, $zero, $zero
    /* F700 80072A60 99BD010C */  jal        func_8006F664
    /* F704 80072A64 21200002 */   addu      $a0, $s0, $zero
  .L80072A68:
    /* F708 80072A68 1045000C */  jal        Task_FindNext
    /* F70C 80072A6C 00000000 */   nop
    /* F710 80072A70 21804000 */  addu       $s0, $v0, $zero
    /* F714 80072A74 0D010012 */  beqz       $s0, .L80072EAC
    /* F718 80072A78 00000000 */   nop
    /* F71C 80072A7C 91CA0108 */  j          .L80072A44
    /* F720 80072A80 00000000 */   nop
  .L80072A84:
    /* F724 80072A84 2800428E */  lw         $v0, 0x28($s2)
    /* F728 80072A88 00000000 */  nop
    /* F72C 80072A8C 78004228 */  slti       $v0, $v0, 0x78
    /* F730 80072A90 36014014 */  bnez       $v0, .L80072F6C
    /* F734 80072A94 00000000 */   nop
    /* F738 80072A98 0C00248E */  lw         $a0, 0xC($s1)
    /* F73C 80072A9C 7045000C */  jal        Task_SetState0
    /* F740 80072AA0 02000524 */   addiu     $a1, $zero, 0x2
    /* F744 80072AA4 0C00248E */  lw         $a0, 0xC($s1)
    /* F748 80072AA8 7745000C */  jal        Task_SetState1
    /* F74C 80072AAC 0B000524 */   addiu     $a1, $zero, 0xB
    /* F750 80072AB0 5945000C */  jal        Task_NextState1
    /* F754 80072AB4 21204002 */   addu      $a0, $s2, $zero
    /* F758 80072AB8 DBCB0108 */  j          .L80072F6C
    /* F75C 80072ABC 00000000 */   nop
  jlabel .L80072AC0
    /* F760 80072AC0 1800438E */  lw         $v1, 0x18($s2)
    /* F764 80072AC4 00000000 */  nop
    /* F768 80072AC8 03006010 */  beqz       $v1, .L80072AD8
    /* F76C 80072ACC 01000224 */   addiu     $v0, $zero, 0x1
    /* F770 80072AD0 20006210 */  beq        $v1, $v0, .L80072B54
    /* F774 80072AD4 00000000 */   nop
  .L80072AD8:
    /* F778 80072AD8 01000224 */  addiu      $v0, $zero, 0x1
    /* F77C 80072ADC 100022AE */  sw         $v0, 0x10($s1)
    /* F780 80072AE0 0C00448E */  lw         $a0, 0xC($s2)
    /* F784 80072AE4 D679000C */  jal        Digi_GetDefaultName
    /* F788 80072AE8 00000000 */   nop
    /* F78C 80072AEC 04002426 */  addiu      $a0, $s1, 0x4
    /* F790 80072AF0 21284000 */  addu       $a1, $v0, $zero
    /* F794 80072AF4 21300000 */  addu       $a2, $zero, $zero
    /* F798 80072AF8 0780023C */  lui        $v0, %hi(D_800737B8)
    /* F79C 80072AFC B8375024 */  addiu      $s0, $v0, %lo(D_800737B8)
    /* F7A0 80072B00 02000796 */  lhu        $a3, 0x2($s0)
    /* F7A4 80072B04 B8374294 */  lhu        $v0, %lo(D_800737B8)($v0)
    /* F7A8 80072B08 003C0700 */  sll        $a3, $a3, 16
    /* F7AC 80072B0C 3E4D000C */  jal        Text_OpenPacked
    /* F7B0 80072B10 25384700 */   or        $a3, $v0, $a3
    /* F7B4 80072B14 FD01043C */  lui        $a0, (0x1FD018D >> 16)
    /* F7B8 80072B18 688E000C */  jal        Cd_GetFileEntry
    /* F7BC 80072B1C 8D018434 */   ori       $a0, $a0, (0x1FD018D & 0xFFFF)
    /* F7C0 80072B20 08002426 */  addiu      $a0, $s1, 0x8
    /* F7C4 80072B24 21284000 */  addu       $a1, $v0, $zero
    /* F7C8 80072B28 81000624 */  addiu      $a2, $zero, 0x81
    /* F7CC 80072B2C 06000796 */  lhu        $a3, 0x6($s0)
    /* F7D0 80072B30 04000296 */  lhu        $v0, 0x4($s0)
    /* F7D4 80072B34 003C0700 */  sll        $a3, $a3, 16
    /* F7D8 80072B38 3E4D000C */  jal        Text_OpenPacked
    /* F7DC 80072B3C 25384700 */   or        $a3, $v0, $a3
    /* F7E0 80072B40 10000424 */  addiu      $a0, $zero, 0x10
    /* F7E4 80072B44 7188000C */  jal        Flag_Set
    /* F7E8 80072B48 21280000 */   addu      $a1, $zero, $zero
    /* F7EC 80072B4C ABCB0108 */  j          .L80072EAC
    /* F7F0 80072B50 00000000 */   nop
  .L80072B54:
    /* F7F4 80072B54 9E87000C */  jal        Flag_Test
    /* F7F8 80072B58 10000424 */   addiu     $a0, $zero, 0x10
    /* F7FC 80072B5C 03014010 */  beqz       $v0, .L80072F6C
    /* F800 80072B60 00000000 */   nop
    /* F804 80072B64 9E87000C */  jal        Flag_Test
    /* F808 80072B68 11000424 */   addiu     $a0, $zero, 0x11
    /* F80C 80072B6C D7004014 */  bnez       $v0, .L80072ECC
    /* F810 80072B70 21204002 */   addu      $a0, $s2, $zero
    /* F814 80072B74 7745000C */  jal        Task_SetState1
    /* F818 80072B78 03000524 */   addiu     $a1, $zero, 0x3
    /* F81C 80072B7C DBCB0108 */  j          .L80072F6C
    /* F820 80072B80 00000000 */   nop
  jlabel .L80072B84
    /* F824 80072B84 1800438E */  lw         $v1, 0x18($s2)
    /* F828 80072B88 01000224 */  addiu      $v0, $zero, 0x1
    /* F82C 80072B8C 2A006210 */  beq        $v1, $v0, .L80072C38
    /* F830 80072B90 02006228 */   slti      $v0, $v1, 0x2
    /* F834 80072B94 04004014 */  bnez       $v0, .L80072BA8
    /* F838 80072B98 21280000 */   addu      $a1, $zero, $zero
    /* F83C 80072B9C 02000224 */  addiu      $v0, $zero, 0x2
    /* F840 80072BA0 C6006210 */  beq        $v1, $v0, .L80072EBC
    /* F844 80072BA4 0680023C */   lui       $v0, %hi(D_8005F704)
  .L80072BA8:
    /* F848 80072BA8 2120A000 */  addu       $a0, $a1, $zero
    /* F84C 80072BAC 0680023C */  lui        $v0, %hi(Save_GameState)
    /* F850 80072BB0 20E64324 */  addiu      $v1, $v0, %lo(Save_GameState)
  .L80072BB4:
    /* F854 80072BB4 E4006290 */  lbu        $v0, 0xE4($v1)
    /* F858 80072BB8 00000000 */  nop
    /* F85C 80072BBC 0200422C */  sltiu      $v0, $v0, 0x2
    /* F860 80072BC0 02004014 */  bnez       $v0, .L80072BCC
    /* F864 80072BC4 00000000 */   nop
    /* F868 80072BC8 0100A524 */  addiu      $a1, $a1, 0x1
  .L80072BCC:
    /* F86C 80072BCC 01008424 */  addiu      $a0, $a0, 0x1
    /* F870 80072BD0 24008228 */  slti       $v0, $a0, 0x24
    /* F874 80072BD4 F7FF4014 */  bnez       $v0, .L80072BB4
    /* F878 80072BD8 5C006324 */   addiu     $v1, $v1, 0x5C
    /* F87C 80072BDC 0780023C */  lui        $v0, %hi(D_800737C0)
    /* F880 80072BE0 0680033C */  lui        $v1, %hi(D_8005E650)
    /* F884 80072BE4 50E66394 */  lhu        $v1, %lo(D_8005E650)($v1)
    /* F888 80072BE8 C0374224 */  addiu      $v0, $v0, %lo(D_800737C0)
    /* F88C 80072BEC 21186200 */  addu       $v1, $v1, $v0
    /* F890 80072BF0 0580023C */  lui        $v0, %hi(D_8005071C)
    /* F894 80072BF4 1C07428C */  lw         $v0, %lo(D_8005071C)($v0)
    /* F898 80072BF8 D1FF6390 */  lbu        $v1, -0x2F($v1)
    /* F89C 80072BFC A80B4290 */  lbu        $v0, 0xBA8($v0)
    /* F8A0 80072C00 00000000 */  nop
    /* F8A4 80072C04 23186200 */  subu       $v1, $v1, $v0
    /* F8A8 80072C08 08006018 */  blez       $v1, .L80072C2C
    /* F8AC 80072C0C 2A10A300 */   slt       $v0, $a1, $v1
    /* F8B0 80072C10 07004010 */  beqz       $v0, .L80072C30
    /* F8B4 80072C14 FD01043C */   lui       $a0, (0x1FD018E >> 16)
    /* F8B8 80072C18 21204002 */  addu       $a0, $s2, $zero
    /* F8BC 80072C1C 7745000C */  jal        Task_SetState1
    /* F8C0 80072C20 04000524 */   addiu     $a1, $zero, 0x4
    /* F8C4 80072C24 DBCB0108 */  j          .L80072F6C
    /* F8C8 80072C28 00000000 */   nop
  .L80072C2C:
    /* F8CC 80072C2C FD01043C */  lui        $a0, (0x1FD018E >> 16)
  .L80072C30:
    /* F8D0 80072C30 9FCB0108 */  j          .L80072E7C
    /* F8D4 80072C34 8E018434 */   ori       $a0, $a0, (0x1FD018E & 0xFFFF)
  .L80072C38:
    /* F8D8 80072C38 0680023C */  lui        $v0, %hi(D_8005F704)
    /* F8DC 80072C3C 04F7428C */  lw         $v0, %lo(D_8005F704)($v0)
    /* F8E0 80072C40 00000000 */  nop
    /* F8E4 80072C44 C9004018 */  blez       $v0, .L80072F6C
    /* F8E8 80072C48 0680023C */   lui       $v0, %hi(Save_GameState)
    /* F8EC 80072C4C 20E64324 */  addiu      $v1, $v0, %lo(Save_GameState)
    /* F8F0 80072C50 4A006294 */  lhu        $v0, 0x4A($v1)
    /* F8F4 80072C54 00000000 */  nop
    /* F8F8 80072C58 05004014 */  bnez       $v0, .L80072C70
    /* F8FC 80072C5C 21204002 */   addu      $a0, $s2, $zero
    /* F900 80072C60 7745000C */  jal        Task_SetState1
    /* F904 80072C64 06000524 */   addiu     $a1, $zero, 0x6
    /* F908 80072C68 DBCB0108 */  j          .L80072F6C
    /* F90C 80072C6C 00000000 */   nop
  .L80072C70:
    /* F910 80072C70 61006290 */  lbu        $v0, 0x61($v1)
    /* F914 80072C74 00000000 */  nop
    /* F918 80072C78 05004010 */  beqz       $v0, .L80072C90
    /* F91C 80072C7C 21280000 */   addu      $a1, $zero, $zero
    /* F920 80072C80 7745000C */  jal        Task_SetState1
    /* F924 80072C84 07000524 */   addiu     $a1, $zero, 0x7
    /* F928 80072C88 DBCB0108 */  j          .L80072F6C
    /* F92C 80072C8C 00000000 */   nop
  .L80072C90:
    /* F930 80072C90 2120A000 */  addu       $a0, $a1, $zero
    /* F934 80072C94 01000624 */  addiu      $a2, $zero, 0x1
  .L80072C98:
    /* F938 80072C98 E4006290 */  lbu        $v0, 0xE4($v1)
    /* F93C 80072C9C 00000000 */  nop
    /* F940 80072CA0 02004614 */  bne        $v0, $a2, .L80072CAC
    /* F944 80072CA4 00000000 */   nop
    /* F948 80072CA8 0100A524 */  addiu      $a1, $a1, 0x1
  .L80072CAC:
    /* F94C 80072CAC 01008424 */  addiu      $a0, $a0, 0x1
    /* F950 80072CB0 24008228 */  slti       $v0, $a0, 0x24
    /* F954 80072CB4 F8FF4014 */  bnez       $v0, .L80072C98
    /* F958 80072CB8 5C006324 */   addiu     $v1, $v1, 0x5C
    /* F95C 80072CBC 1800A228 */  slti       $v0, $a1, 0x18
    /* F960 80072CC0 06004010 */  beqz       $v0, .L80072CDC
    /* F964 80072CC4 FD01043C */   lui       $a0, (0x1FD0190 >> 16)
    /* F968 80072CC8 21204002 */  addu       $a0, $s2, $zero
    /* F96C 80072CCC 7745000C */  jal        Task_SetState1
    /* F970 80072CD0 05000524 */   addiu     $a1, $zero, 0x5
    /* F974 80072CD4 DBCB0108 */  j          .L80072F6C
    /* F978 80072CD8 00000000 */   nop
  .L80072CDC:
    /* F97C 80072CDC 9FCB0108 */  j          .L80072E7C
    /* F980 80072CE0 90018434 */   ori       $a0, $a0, (0x1FD0190 & 0xFFFF)
  jlabel .L80072CE4
    /* F984 80072CE4 1800438E */  lw         $v1, 0x18($s2)
    /* F988 80072CE8 3400508E */  lw         $s0, 0x34($s2)
    /* F98C 80072CEC 03006010 */  beqz       $v1, .L80072CFC
    /* F990 80072CF0 01000224 */   addiu     $v0, $zero, 0x1
    /* F994 80072CF4 12006210 */  beq        $v1, $v0, .L80072D40
    /* F998 80072CF8 00000000 */   nop
  .L80072CFC:
    /* F99C 80072CFC 04002426 */  addiu      $a0, $s1, 0x4
    /* F9A0 80072D00 E26E000C */  jal        Text_Close
    /* F9A4 80072D04 100020AE */   sw        $zero, 0x10($s1)
    /* F9A8 80072D08 E26E000C */  jal        Text_Close
    /* F9AC 80072D0C 08002426 */   addiu     $a0, $s1, 0x8
    /* F9B0 80072D10 21204002 */  addu       $a0, $s2, $zero
    /* F9B4 80072D14 36CA010C */  jal        func_800728D8
    /* F9B8 80072D18 21280000 */   addu      $a1, $zero, $zero
    /* F9BC 80072D1C 16000424 */  addiu      $a0, $zero, 0x16
    /* F9C0 80072D20 21280002 */  addu       $a1, $s0, $zero
    /* F9C4 80072D24 1000A627 */  addiu      $a2, $sp, 0x10
    /* F9C8 80072D28 23000224 */  addiu      $v0, $zero, 0x23
    /* F9CC 80072D2C 1000A0AF */  sw         $zero, 0x10($sp)
    /* F9D0 80072D30 1F44000C */  jal        Task_Create
    /* F9D4 80072D34 1400A2AF */   sw        $v0, 0x14($sp)
    /* F9D8 80072D38 ABCB0108 */  j          .L80072EAC
    /* F9DC 80072D3C 00000000 */   nop
  .L80072D40:
    /* F9E0 80072D40 0000028E */  lw         $v0, 0x0($s0)
    /* F9E4 80072D44 00000000 */  nop
    /* F9E8 80072D48 88004014 */  bnez       $v0, .L80072F6C
    /* F9EC 80072D4C 00000000 */   nop
    /* F9F0 80072D50 B98A000C */  jal        Digi_SortRoster
    /* F9F4 80072D54 00000000 */   nop
    /* F9F8 80072D58 D9CB0108 */  j          .L80072F64
    /* F9FC 80072D5C 21204002 */   addu      $a0, $s2, $zero
  jlabel .L80072D60
    /* FA00 80072D60 1800438E */  lw         $v1, 0x18($s2)
    /* FA04 80072D64 01000224 */  addiu      $v0, $zero, 0x1
    /* FA08 80072D68 19006210 */  beq        $v1, $v0, .L80072DD0
    /* FA0C 80072D6C 02006228 */   slti      $v0, $v1, 0x2
    /* FA10 80072D70 06004014 */  bnez       $v0, .L80072D8C
    /* FA14 80072D74 FD01043C */   lui       $a0, (0x1FD018F >> 16)
    /* FA18 80072D78 02000224 */  addiu      $v0, $zero, 0x2
    /* FA1C 80072D7C 1E006210 */  beq        $v1, $v0, .L80072DF8
    /* FA20 80072D80 03000224 */   addiu     $v0, $zero, 0x3
    /* FA24 80072D84 2D006210 */  beq        $v1, $v0, .L80072E3C
    /* FA28 80072D88 00000000 */   nop
  .L80072D8C:
    /* FA2C 80072D8C 688E000C */  jal        Cd_GetFileEntry
    /* FA30 80072D90 8F018434 */   ori       $a0, $a0, (0x1FD018F & 0xFFFF)
    /* FA34 80072D94 08002426 */  addiu      $a0, $s1, 0x8
    /* FA38 80072D98 21284000 */  addu       $a1, $v0, $zero
    /* FA3C 80072D9C 81000624 */  addiu      $a2, $zero, 0x81
    /* FA40 80072DA0 0780023C */  lui        $v0, %hi(D_800737B8)
    /* FA44 80072DA4 B8374224 */  addiu      $v0, $v0, %lo(D_800737B8)
    /* FA48 80072DA8 06004794 */  lhu        $a3, 0x6($v0)
    /* FA4C 80072DAC 04004294 */  lhu        $v0, 0x4($v0)
    /* FA50 80072DB0 003C0700 */  sll        $a3, $a3, 16
    /* FA54 80072DB4 3E4D000C */  jal        Text_OpenPacked
    /* FA58 80072DB8 25384700 */   or        $a3, $v0, $a3
    /* FA5C 80072DBC 10000424 */  addiu      $a0, $zero, 0x10
    /* FA60 80072DC0 7188000C */  jal        Flag_Set
    /* FA64 80072DC4 21280000 */   addu      $a1, $zero, $zero
    /* FA68 80072DC8 ABCB0108 */  j          .L80072EAC
    /* FA6C 80072DCC 00000000 */   nop
  .L80072DD0:
    /* FA70 80072DD0 9E87000C */  jal        Flag_Test
    /* FA74 80072DD4 10000424 */   addiu     $a0, $zero, 0x10
    /* FA78 80072DD8 64004010 */  beqz       $v0, .L80072F6C
    /* FA7C 80072DDC 00000000 */   nop
    /* FA80 80072DE0 9E87000C */  jal        Flag_Test
    /* FA84 80072DE4 11000424 */   addiu     $a0, $zero, 0x11
    /* FA88 80072DE8 30004010 */  beqz       $v0, .L80072EAC
    /* FA8C 80072DEC 21204002 */   addu      $a0, $s2, $zero
    /* FA90 80072DF0 B3CB0108 */  j          .L80072ECC
    /* FA94 80072DF4 00000000 */   nop
  .L80072DF8:
    /* FA98 80072DF8 04002426 */  addiu      $a0, $s1, 0x4
    /* FA9C 80072DFC E26E000C */  jal        Text_Close
    /* FAA0 80072E00 100020AE */   sw        $zero, 0x10($s1)
    /* FAA4 80072E04 E26E000C */  jal        Text_Close
    /* FAA8 80072E08 08002426 */   addiu     $a0, $s1, 0x8
    /* FAAC 80072E0C 21204002 */  addu       $a0, $s2, $zero
    /* FAB0 80072E10 36CA010C */  jal        func_800728D8
    /* FAB4 80072E14 01000524 */   addiu     $a1, $zero, 0x1
    /* FAB8 80072E18 16000424 */  addiu      $a0, $zero, 0x16
    /* FABC 80072E1C 21280002 */  addu       $a1, $s0, $zero
    /* FAC0 80072E20 1000A627 */  addiu      $a2, $sp, 0x10
    /* FAC4 80072E24 23000224 */  addiu      $v0, $zero, 0x23
    /* FAC8 80072E28 1000A0AF */  sw         $zero, 0x10($sp)
    /* FACC 80072E2C 1F44000C */  jal        Task_Create
    /* FAD0 80072E30 1400A2AF */   sw        $v0, 0x14($sp)
    /* FAD4 80072E34 ABCB0108 */  j          .L80072EAC
    /* FAD8 80072E38 00000000 */   nop
  .L80072E3C:
    /* FADC 80072E3C 0000028E */  lw         $v0, 0x0($s0)
    /* FAE0 80072E40 00000000 */  nop
    /* FAE4 80072E44 49004014 */  bnez       $v0, .L80072F6C
    /* FAE8 80072E48 00000000 */   nop
    /* FAEC 80072E4C B98A000C */  jal        Digi_SortRoster
    /* FAF0 80072E50 00000000 */   nop
    /* FAF4 80072E54 D9CB0108 */  j          .L80072F64
    /* FAF8 80072E58 21204002 */   addu      $a0, $s2, $zero
  jlabel .L80072E5C
    /* FAFC 80072E5C 1800438E */  lw         $v1, 0x18($s2)
    /* FB00 80072E60 00000000 */  nop
    /* FB04 80072E64 03006010 */  beqz       $v1, .L80072E74
    /* FB08 80072E68 01000224 */   addiu     $v0, $zero, 0x1
    /* FB0C 80072E6C 13006210 */  beq        $v1, $v0, .L80072EBC
    /* FB10 80072E70 0680023C */   lui       $v0, %hi(D_8005F704)
  .L80072E74:
    /* FB14 80072E74 FD01043C */  lui        $a0, (0x1FD0191 >> 16)
    /* FB18 80072E78 91018434 */  ori        $a0, $a0, (0x1FD0191 & 0xFFFF)
  .L80072E7C:
    /* FB1C 80072E7C 688E000C */  jal        Cd_GetFileEntry
    /* FB20 80072E80 00000000 */   nop
    /* FB24 80072E84 08002426 */  addiu      $a0, $s1, 0x8
    /* FB28 80072E88 21284000 */  addu       $a1, $v0, $zero
    /* FB2C 80072E8C 81000624 */  addiu      $a2, $zero, 0x81
    /* FB30 80072E90 0780023C */  lui        $v0, %hi(D_800737B8)
    /* FB34 80072E94 B8374224 */  addiu      $v0, $v0, %lo(D_800737B8)
    /* FB38 80072E98 06004794 */  lhu        $a3, 0x6($v0)
    /* FB3C 80072E9C 04004294 */  lhu        $v0, 0x4($v0)
    /* FB40 80072EA0 003C0700 */  sll        $a3, $a3, 16
    /* FB44 80072EA4 3E4D000C */  jal        Text_OpenPacked
    /* FB48 80072EA8 25384700 */   or        $a3, $v0, $a3
  .L80072EAC:
    /* FB4C 80072EAC 6045000C */  jal        Task_NextState2
    /* FB50 80072EB0 21204002 */   addu      $a0, $s2, $zero
    /* FB54 80072EB4 DBCB0108 */  j          .L80072F6C
    /* FB58 80072EB8 00000000 */   nop
  .L80072EBC:
    /* FB5C 80072EBC 04F7428C */  lw         $v0, %lo(D_8005F704)($v0)
    /* FB60 80072EC0 00000000 */  nop
    /* FB64 80072EC4 29004018 */  blez       $v0, .L80072F6C
    /* FB68 80072EC8 21204002 */   addu      $a0, $s2, $zero
  .L80072ECC:
    /* FB6C 80072ECC 7745000C */  jal        Task_SetState1
    /* FB70 80072ED0 08000524 */   addiu     $a1, $zero, 0x8
    /* FB74 80072ED4 DBCB0108 */  j          .L80072F6C
    /* FB78 80072ED8 00000000 */   nop
  jlabel .L80072EDC
    /* FB7C 80072EDC 1800438E */  lw         $v1, 0x18($s2)
    /* FB80 80072EE0 00000000 */  nop
    /* FB84 80072EE4 03006010 */  beqz       $v1, .L80072EF4
    /* FB88 80072EE8 01000224 */   addiu     $v0, $zero, 0x1
    /* FB8C 80072EEC 14006210 */  beq        $v1, $v0, .L80072F40
    /* FB90 80072EF0 0680023C */   lui       $v0, %hi(D_8005F704)
  .L80072EF4:
    /* FB94 80072EF4 1C000424 */  addiu      $a0, $zero, 0x1C
    /* FB98 80072EF8 A369000C */  jal        Snd_PlayById
    /* FB9C 80072EFC 21280000 */   addu      $a1, $zero, $zero
    /* FBA0 80072F00 FD01043C */  lui        $a0, (0x1FD0192 >> 16)
    /* FBA4 80072F04 688E000C */  jal        Cd_GetFileEntry
    /* FBA8 80072F08 92018434 */   ori       $a0, $a0, (0x1FD0192 & 0xFFFF)
    /* FBAC 80072F0C 08002426 */  addiu      $a0, $s1, 0x8
    /* FBB0 80072F10 21284000 */  addu       $a1, $v0, $zero
    /* FBB4 80072F14 81000624 */  addiu      $a2, $zero, 0x81
    /* FBB8 80072F18 0780023C */  lui        $v0, %hi(D_800737B8)
    /* FBBC 80072F1C B8374224 */  addiu      $v0, $v0, %lo(D_800737B8)
    /* FBC0 80072F20 06004794 */  lhu        $a3, 0x6($v0)
    /* FBC4 80072F24 04004294 */  lhu        $v0, 0x4($v0)
    /* FBC8 80072F28 003C0700 */  sll        $a3, $a3, 16
    /* FBCC 80072F2C 3E4D000C */  jal        Text_OpenPacked
    /* FBD0 80072F30 25384700 */   or        $a3, $v0, $a3
    /* FBD4 80072F34 6045000C */  jal        Task_NextState2
    /* FBD8 80072F38 21204002 */   addu      $a0, $s2, $zero
    /* FBDC 80072F3C 0680023C */  lui        $v0, %hi(D_8005F704)
  .L80072F40:
    /* FBE0 80072F40 04F7428C */  lw         $v0, %lo(D_8005F704)($v0)
    /* FBE4 80072F44 00000000 */  nop
    /* FBE8 80072F48 08004018 */  blez       $v0, .L80072F6C
    /* FBEC 80072F4C 21204002 */   addu      $a0, $s2, $zero
    /* FBF0 80072F50 D9CB0108 */  j          .L80072F64
    /* FBF4 80072F54 00000000 */   nop
  .L80072F58:
    /* FBF8 80072F58 2C70000C */  jal        Text_CloseArray
    /* FBFC 80072F5C 02000524 */   addiu     $a1, $zero, 0x2
    /* FC00 80072F60 21204002 */  addu       $a0, $s2, $zero
  .L80072F64:
    /* FC04 80072F64 5145000C */  jal        Task_NextState0
    /* FC08 80072F68 00000000 */   nop
  .L80072F6C:
    /* FC0C 80072F6C 2400BF8F */  lw         $ra, 0x24($sp)
    /* FC10 80072F70 2000B28F */  lw         $s2, 0x20($sp)
    /* FC14 80072F74 1C00B18F */  lw         $s1, 0x1C($sp)
    /* FC18 80072F78 1800B08F */  lw         $s0, 0x18($sp)
    /* FC1C 80072F7C 0800E003 */  jr         $ra
    /* FC20 80072F80 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8007292C
