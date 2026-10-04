nonmatching Stg00_StageSetup, 0x290

glabel Stg00_StageSetup
    /* 714 80063A74 80FFBD27 */  addiu      $sp, $sp, -0x80
    /* 718 80063A78 7400B1AF */  sw         $s1, 0x74($sp)
    /* 71C 80063A7C 21888000 */  addu       $s1, $a0, $zero
    /* 720 80063A80 7800BFAF */  sw         $ra, 0x78($sp)
    /* 724 80063A84 7000B0AF */  sw         $s0, 0x70($sp)
    /* 728 80063A88 1000228E */  lw         $v0, 0x10($s1)
    /* 72C 80063A8C 3400308E */  lw         $s0, 0x34($s1)
    /* 730 80063A90 97004014 */  bnez       $v0, .L80063CF0
    /* 734 80063A94 14000526 */   addiu     $a1, $s0, 0x14
    /* 738 80063A98 09000424 */  addiu      $a0, $zero, 0x9
    /* 73C 80063A9C 1F44000C */  jal        Task_Create
    /* 740 80063AA0 21300000 */   addu      $a2, $zero, $zero
    /* 744 80063AA4 0680023C */  lui        $v0, %hi(Sys_GameMode)
    /* 748 80063AA8 88F7428C */  lw         $v0, %lo(Sys_GameMode)($v0)
    /* 74C 80063AAC 00000000 */  nop
    /* 750 80063AB0 FFFE4324 */  addiu      $v1, $v0, -0x101
    /* 754 80063AB4 0600622C */  sltiu      $v0, $v1, 0x6
    /* 758 80063AB8 08004010 */  beqz       $v0, .L80063ADC
    /* 75C 80063ABC 0680023C */   lui       $v0, %hi(jtbl_80063360)
    /* 760 80063AC0 60334224 */  addiu      $v0, $v0, %lo(jtbl_80063360)
    /* 764 80063AC4 80180300 */  sll        $v1, $v1, 2
    /* 768 80063AC8 21186200 */  addu       $v1, $v1, $v0
    /* 76C 80063ACC 0000628C */  lw         $v0, 0x0($v1)
    /* 770 80063AD0 00000000 */  nop
    /* 774 80063AD4 08004000 */  jr         $v0
    /* 778 80063AD8 00000000 */   nop
  jlabel .L80063ADC
    /* 77C 80063ADC 09010424 */  addiu      $a0, $zero, 0x109
    /* 780 80063AE0 21280002 */  addu       $a1, $s0, $zero
    /* 784 80063AE4 1000A627 */  addiu      $a2, $sp, 0x10
    /* 788 80063AE8 00F10224 */  addiu      $v0, $zero, -0xF00
    /* 78C 80063AEC 1400A2AF */  sw         $v0, 0x14($sp)
    /* 790 80063AF0 00E70224 */  addiu      $v0, $zero, -0x1900
    /* 794 80063AF4 1800A2AF */  sw         $v0, 0x18($sp)
    /* 798 80063AF8 30020224 */  addiu      $v0, $zero, 0x230
    /* 79C 80063AFC 1000A0AF */  sw         $zero, 0x10($sp)
    /* 7A0 80063B00 1C00A0AF */  sw         $zero, 0x1C($sp)
    /* 7A4 80063B04 2000A0AF */  sw         $zero, 0x20($sp)
    /* 7A8 80063B08 2400A0AF */  sw         $zero, 0x24($sp)
    /* 7AC 80063B0C 1F44000C */  jal        Task_Create
    /* 7B0 80063B10 2800A2AF */   sw        $v0, 0x28($sp)
    /* 7B4 80063B14 06010424 */  addiu      $a0, $zero, 0x106
    /* 7B8 80063B18 04000526 */  addiu      $a1, $s0, 0x4
    /* 7BC 80063B1C 1F44000C */  jal        Task_Create
    /* 7C0 80063B20 21300000 */   addu      $a2, $zero, $zero
    /* 7C4 80063B24 08010424 */  addiu      $a0, $zero, 0x108
    /* 7C8 80063B28 388F0108 */  j          .L80063CE0
    /* 7CC 80063B2C 08000526 */   addiu     $a1, $s0, 0x8
  jlabel .L80063B30
    /* 7D0 80063B30 09010424 */  addiu      $a0, $zero, 0x109
    /* 7D4 80063B34 21280002 */  addu       $a1, $s0, $zero
    /* 7D8 80063B38 3000A627 */  addiu      $a2, $sp, 0x30
    /* 7DC 80063B3C 00F10224 */  addiu      $v0, $zero, -0xF00
    /* 7E0 80063B40 3400A2AF */  sw         $v0, 0x34($sp)
    /* 7E4 80063B44 00E70224 */  addiu      $v0, $zero, -0x1900
    /* 7E8 80063B48 3800A2AF */  sw         $v0, 0x38($sp)
    /* 7EC 80063B4C 30020224 */  addiu      $v0, $zero, 0x230
    /* 7F0 80063B50 3000A0AF */  sw         $zero, 0x30($sp)
    /* 7F4 80063B54 3C00A0AF */  sw         $zero, 0x3C($sp)
    /* 7F8 80063B58 4000A0AF */  sw         $zero, 0x40($sp)
    /* 7FC 80063B5C 4400A0AF */  sw         $zero, 0x44($sp)
    /* 800 80063B60 1F44000C */  jal        Task_Create
    /* 804 80063B64 4800A2AF */   sw        $v0, 0x48($sp)
    /* 808 80063B68 03010424 */  addiu      $a0, $zero, 0x103
    /* 80C 80063B6C 04000526 */  addiu      $a1, $s0, 0x4
    /* 810 80063B70 1F44000C */  jal        Task_Create
    /* 814 80063B74 21300000 */   addu      $a2, $zero, $zero
    /* 818 80063B78 06010424 */  addiu      $a0, $zero, 0x106
    /* 81C 80063B7C 08000526 */  addiu      $a1, $s0, 0x8
    /* 820 80063B80 1F44000C */  jal        Task_Create
    /* 824 80063B84 21300000 */   addu      $a2, $zero, $zero
    /* 828 80063B88 02010424 */  addiu      $a0, $zero, 0x102
    /* 82C 80063B8C 388F0108 */  j          .L80063CE0
    /* 830 80063B90 0C000526 */   addiu     $a1, $s0, 0xC
  jlabel .L80063B94
    /* 834 80063B94 09010424 */  addiu      $a0, $zero, 0x109
    /* 838 80063B98 21280002 */  addu       $a1, $s0, $zero
    /* 83C 80063B9C 5000A627 */  addiu      $a2, $sp, 0x50
    /* 840 80063BA0 90E80224 */  addiu      $v0, $zero, -0x1770
    /* 844 80063BA4 5400A2AF */  sw         $v0, 0x54($sp)
    /* 848 80063BA8 08520224 */  addiu      $v0, $zero, 0x5208
    /* 84C 80063BAC 5800A2AF */  sw         $v0, 0x58($sp)
    /* 850 80063BB0 44FD0224 */  addiu      $v0, $zero, -0x2BC
    /* 854 80063BB4 6000A2AF */  sw         $v0, 0x60($sp)
    /* 858 80063BB8 DC050224 */  addiu      $v0, $zero, 0x5DC
    /* 85C 80063BBC 5000A0AF */  sw         $zero, 0x50($sp)
    /* 860 80063BC0 5C00A0AF */  sw         $zero, 0x5C($sp)
    /* 864 80063BC4 6400A0AF */  sw         $zero, 0x64($sp)
    /* 868 80063BC8 1F44000C */  jal        Task_Create
    /* 86C 80063BCC 6800A2AF */   sw        $v0, 0x68($sp)
    /* 870 80063BD0 06010424 */  addiu      $a0, $zero, 0x106
    /* 874 80063BD4 04000526 */  addiu      $a1, $s0, 0x4
    /* 878 80063BD8 1F44000C */  jal        Task_Create
    /* 87C 80063BDC 21300000 */   addu      $a2, $zero, $zero
    /* 880 80063BE0 04010424 */  addiu      $a0, $zero, 0x104
    /* 884 80063BE4 388F0108 */  j          .L80063CE0
    /* 888 80063BE8 08000526 */   addiu     $a1, $s0, 0x8
  jlabel .L80063BEC
    /* 88C 80063BEC 598E000C */  jal        Sys_SetFrameRate60
    /* 890 80063BF0 00000000 */   nop
    /* 894 80063BF4 0200043C */  lui        $a0, (0x25800 >> 16)
    /* 898 80063BF8 6C72000C */  jal        Gpu_AllocPacketBufs
    /* 89C 80063BFC 00588434 */   ori       $a0, $a0, (0x25800 & 0xFFFF)
    /* 8A0 80063C00 40010424 */  addiu      $a0, $zero, 0x140
    /* 8A4 80063C04 F0000524 */  addiu      $a1, $zero, 0xF0
    /* 8A8 80063C08 21300000 */  addu       $a2, $zero, $zero
    /* 8AC 80063C0C 7870000C */  jal        Gpu_InitDoubleBuffer
    /* 8B0 80063C10 2138C000 */   addu      $a3, $a2, $zero
    /* 8B4 80063C14 21200000 */  addu       $a0, $zero, $zero
    /* 8B8 80063C18 21288000 */  addu       $a1, $a0, $zero
    /* 8BC 80063C1C 6570000C */  jal        Gpu_SetBgClearColor
    /* 8C0 80063C20 21308000 */   addu      $a2, $a0, $zero
    /* 8C4 80063C24 4170000C */  jal        Gpu_ClearScreens
    /* 8C8 80063C28 00000000 */   nop
    /* 8CC 80063C2C 3271000C */  jal        Gfx_FadeInFromBlack
    /* 8D0 80063C30 1E000424 */   addiu     $a0, $zero, 0x1E
    /* 8D4 80063C34 07010424 */  addiu      $a0, $zero, 0x107
    /* 8D8 80063C38 388F0108 */  j          .L80063CE0
    /* 8DC 80063C3C 18000526 */   addiu     $a1, $s0, 0x18
  jlabel .L80063C40
    /* 8E0 80063C40 598E000C */  jal        Sys_SetFrameRate60
    /* 8E4 80063C44 00000000 */   nop
    /* 8E8 80063C48 0200043C */  lui        $a0, (0x25800 >> 16)
    /* 8EC 80063C4C 6C72000C */  jal        Gpu_AllocPacketBufs
    /* 8F0 80063C50 00588434 */   ori       $a0, $a0, (0x25800 & 0xFFFF)
    /* 8F4 80063C54 40010424 */  addiu      $a0, $zero, 0x140
    /* 8F8 80063C58 F0000524 */  addiu      $a1, $zero, 0xF0
    /* 8FC 80063C5C 21300000 */  addu       $a2, $zero, $zero
    /* 900 80063C60 7870000C */  jal        Gpu_InitDoubleBuffer
    /* 904 80063C64 2138C000 */   addu      $a3, $a2, $zero
    /* 908 80063C68 21200000 */  addu       $a0, $zero, $zero
    /* 90C 80063C6C 21288000 */  addu       $a1, $a0, $zero
    /* 910 80063C70 6570000C */  jal        Gpu_SetBgClearColor
    /* 914 80063C74 21308000 */   addu      $a2, $a0, $zero
    /* 918 80063C78 4170000C */  jal        Gpu_ClearScreens
    /* 91C 80063C7C 00000000 */   nop
    /* 920 80063C80 3271000C */  jal        Gfx_FadeInFromBlack
    /* 924 80063C84 1E000424 */   addiu     $a0, $zero, 0x1E
    /* 928 80063C88 378F0108 */  j          .L80063CDC
    /* 92C 80063C8C 0A010424 */   addiu     $a0, $zero, 0x10A
  jlabel .L80063C90
    /* 930 80063C90 598E000C */  jal        Sys_SetFrameRate60
    /* 934 80063C94 00000000 */   nop
    /* 938 80063C98 0200043C */  lui        $a0, (0x25800 >> 16)
    /* 93C 80063C9C 6C72000C */  jal        Gpu_AllocPacketBufs
    /* 940 80063CA0 00588434 */   ori       $a0, $a0, (0x25800 & 0xFFFF)
    /* 944 80063CA4 40010424 */  addiu      $a0, $zero, 0x140
    /* 948 80063CA8 F0000524 */  addiu      $a1, $zero, 0xF0
    /* 94C 80063CAC 21300000 */  addu       $a2, $zero, $zero
    /* 950 80063CB0 7870000C */  jal        Gpu_InitDoubleBuffer
    /* 954 80063CB4 2138C000 */   addu      $a3, $a2, $zero
    /* 958 80063CB8 21200000 */  addu       $a0, $zero, $zero
    /* 95C 80063CBC 21288000 */  addu       $a1, $a0, $zero
    /* 960 80063CC0 6570000C */  jal        Gpu_SetBgClearColor
    /* 964 80063CC4 21308000 */   addu      $a2, $a0, $zero
    /* 968 80063CC8 4170000C */  jal        Gpu_ClearScreens
    /* 96C 80063CCC 00000000 */   nop
    /* 970 80063CD0 3271000C */  jal        Gfx_FadeInFromBlack
    /* 974 80063CD4 1E000424 */   addiu     $a0, $zero, 0x1E
    /* 978 80063CD8 0D010424 */  addiu      $a0, $zero, 0x10D
  .L80063CDC:
    /* 97C 80063CDC 1C000526 */  addiu      $a1, $s0, 0x1C
  .L80063CE0:
    /* 980 80063CE0 1F44000C */  jal        Task_Create
    /* 984 80063CE4 21300000 */   addu      $a2, $zero, $zero
    /* 988 80063CE8 5145000C */  jal        Task_NextState0
    /* 98C 80063CEC 21202002 */   addu      $a0, $s1, $zero
  .L80063CF0:
    /* 990 80063CF0 7800BF8F */  lw         $ra, 0x78($sp)
    /* 994 80063CF4 7400B18F */  lw         $s1, 0x74($sp)
    /* 998 80063CF8 7000B08F */  lw         $s0, 0x70($sp)
    /* 99C 80063CFC 0800E003 */  jr         $ra
    /* 9A0 80063D00 8000BD27 */   addiu     $sp, $sp, 0x80
endlabel Stg00_StageSetup
