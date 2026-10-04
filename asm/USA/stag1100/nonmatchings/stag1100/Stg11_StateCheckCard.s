nonmatching Stg11_StateCheckCard, 0x28C

glabel Stg11_StateCheckCard
    /* 1904 80064C64 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1908 80064C68 1400B1AF */  sw         $s1, 0x14($sp)
    /* 190C 80064C6C 21888000 */  addu       $s1, $a0, $zero
    /* 1910 80064C70 1800BFAF */  sw         $ra, 0x18($sp)
    /* 1914 80064C74 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1918 80064C78 1800238E */  lw         $v1, 0x18($s1)
    /* 191C 80064C7C 00000000 */  nop
    /* 1920 80064C80 2000622C */  sltiu      $v0, $v1, 0x20
    /* 1924 80064C84 87004010 */  beqz       $v0, .L80064EA4
    /* 1928 80064C88 2180A000 */   addu      $s0, $a1, $zero
    /* 192C 80064C8C 0680023C */  lui        $v0, %hi(jtbl_80063390)
    /* 1930 80064C90 90334224 */  addiu      $v0, $v0, %lo(jtbl_80063390)
    /* 1934 80064C94 80180300 */  sll        $v1, $v1, 2
    /* 1938 80064C98 21186200 */  addu       $v1, $v1, $v0
    /* 193C 80064C9C 0000628C */  lw         $v0, 0x0($v1)
    /* 1940 80064CA0 00000000 */  nop
    /* 1944 80064CA4 08004000 */  jr         $v0
    /* 1948 80064CA8 00000000 */   nop
  jlabel .L80064CAC
    /* 194C 80064CAC 21200002 */  addu       $a0, $s0, $zero
    /* 1950 80064CB0 88000586 */  lh         $a1, 0x88($s0)
    /* 1954 80064CB4 5792010C */  jal        Stg11_SetPromptMsg
    /* 1958 80064CB8 01000624 */   addiu     $a2, $zero, 0x1
    /* 195C 80064CBC 21202002 */  addu       $a0, $s1, $zero
    /* 1960 80064CC0 21280002 */  addu       $a1, $s0, $zero
    /* 1964 80064CC4 880000A6 */  sh         $zero, 0x88($s0)
    /* 1968 80064CC8 2D92010C */  jal        Stg11_CloseSlotText
    /* 196C 80064CCC 860000A6 */   sh        $zero, 0x86($s0)
    /* 1970 80064CD0 21202002 */  addu       $a0, $s1, $zero
    /* 1974 80064CD4 8545000C */  jal        Task_SetState2
    /* 1978 80064CD8 0A000524 */   addiu     $a1, $zero, 0xA
  jlabel .L80064CDC
    /* 197C 80064CDC 84000586 */  lh         $a1, 0x84($s0)
    /* 1980 80064CE0 7F930108 */  j          .L80064DFC
    /* 1984 80064CE4 02000424 */   addiu     $a0, $zero, 0x2
  jlabel .L80064CE8
    /* 1988 80064CE8 069E010C */  jal        Stg11_CardGetResult
    /* 198C 80064CEC 00000000 */   nop
    /* 1990 80064CF0 21184000 */  addu       $v1, $v0, $zero
    /* 1994 80064CF4 11006010 */  beqz       $v1, .L80064D3C
    /* 1998 80064CF8 00000000 */   nop
    /* 199C 80064CFC 69006018 */  blez       $v1, .L80064EA4
    /* 19A0 80064D00 02000224 */   addiu     $v0, $zero, 0x2
    /* 19A4 80064D04 68006214 */  bne        $v1, $v0, .L80064EA8
    /* 19A8 80064D08 0680023C */   lui       $v0, %hi(Pad_State)
    /* 19AC 80064D0C 80000286 */  lh         $v0, 0x80($s0)
    /* 19B0 80064D10 00000000 */  nop
    /* 19B4 80064D14 02004010 */  beqz       $v0, .L80064D20
    /* 19B8 80064D18 6B010524 */   addiu     $a1, $zero, 0x16B
    /* 19BC 80064D1C AD010524 */  addiu      $a1, $zero, 0x1AD
  .L80064D20:
    /* 19C0 80064D20 3992010C */  jal        Stg11_SetStatusMsg
    /* 19C4 80064D24 21200002 */   addu      $a0, $s0, $zero
    /* 19C8 80064D28 21202002 */  addu       $a0, $s1, $zero
    /* 19CC 80064D2C 8545000C */  jal        Task_SetState2
    /* 19D0 80064D30 14000524 */   addiu     $a1, $zero, 0x14
    /* 19D4 80064D34 AA930108 */  j          .L80064EA8
    /* 19D8 80064D38 0680023C */   lui       $v0, %hi(Pad_State)
  .L80064D3C:
    /* 19DC 80064D3C 80000286 */  lh         $v0, 0x80($s0)
    /* 19E0 80064D40 84000586 */  lh         $a1, 0x84($s0)
    /* 19E4 80064D44 03004010 */  beqz       $v0, .L80064D54
    /* 19E8 80064D48 00000000 */   nop
  .L80064D4C:
    /* 19EC 80064D4C 56930108 */  j          .L80064D58
    /* 19F0 80064D50 AE01A524 */   addiu     $a1, $a1, 0x1AE
  .L80064D54:
    /* 19F4 80064D54 8001A524 */  addiu      $a1, $a1, 0x180
  .L80064D58:
    /* 19F8 80064D58 3992010C */  jal        Stg11_SetStatusMsg
    /* 19FC 80064D5C 21200002 */   addu      $a0, $s0, $zero
    /* 1A00 80064D60 A2930108 */  j          .L80064E88
    /* 1A04 80064D64 21202002 */   addu      $a0, $s1, $zero
  jlabel .L80064D68
    /* 1A08 80064D68 84000586 */  lh         $a1, 0x84($s0)
    /* 1A0C 80064D6C 7F930108 */  j          .L80064DFC
    /* 1A10 80064D70 04000424 */   addiu     $a0, $zero, 0x4
  jlabel .L80064D74
    /* 1A14 80064D74 069E010C */  jal        Stg11_CardGetResult
    /* 1A18 80064D78 00000000 */   nop
    /* 1A1C 80064D7C 21184000 */  addu       $v1, $v0, $zero
    /* 1A20 80064D80 10006010 */  beqz       $v1, .L80064DC4
    /* 1A24 80064D84 00000000 */   nop
    /* 1A28 80064D88 0600601C */  bgtz       $v1, .L80064DA4
    /* 1A2C 80064D8C 01000224 */   addiu     $v0, $zero, 0x1
    /* 1A30 80064D90 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 1A34 80064D94 43006210 */  beq        $v1, $v0, .L80064EA4
    /* 1A38 80064D98 21202002 */   addu      $a0, $s1, $zero
    /* 1A3C 80064D9C A7930108 */  j          .L80064E9C
    /* 1A40 80064DA0 02000524 */   addiu     $a1, $zero, 0x2
  .L80064DA4:
    /* 1A44 80064DA4 0D006210 */  beq        $v1, $v0, .L80064DDC
    /* 1A48 80064DA8 02000224 */   addiu     $v0, $zero, 0x2
    /* 1A4C 80064DAC 3A006214 */  bne        $v1, $v0, .L80064E98
    /* 1A50 80064DB0 21202002 */   addu      $a0, $s1, $zero
    /* 1A54 80064DB4 8545000C */  jal        Task_SetState2
    /* 1A58 80064DB8 1E000524 */   addiu     $a1, $zero, 0x1E
    /* 1A5C 80064DBC AA930108 */  j          .L80064EA8
    /* 1A60 80064DC0 0680023C */   lui       $v0, %hi(Pad_State)
  .L80064DC4:
    /* 1A64 80064DC4 80000286 */  lh         $v0, 0x80($s0)
    /* 1A68 80064DC8 84000586 */  lh         $a1, 0x84($s0)
    /* 1A6C 80064DCC DFFF4014 */  bnez       $v0, .L80064D4C
    /* 1A70 80064DD0 00000000 */   nop
    /* 1A74 80064DD4 56930108 */  j          .L80064D58
    /* 1A78 80064DD8 8001A524 */   addiu     $a1, $a1, 0x180
  .L80064DDC:
    /* 1A7C 80064DDC 7A000286 */  lh         $v0, 0x7A($s0)
    /* 1A80 80064DE0 00000000 */  nop
    /* 1A84 80064DE4 2C004014 */  bnez       $v0, .L80064E98
    /* 1A88 80064DE8 21202002 */   addu      $a0, $s1, $zero
    /* 1A8C 80064DEC A7930108 */  j          .L80064E9C
    /* 1A90 80064DF0 09000524 */   addiu     $a1, $zero, 0x9
  jlabel .L80064DF4
    /* 1A94 80064DF4 84000586 */  lh         $a1, 0x84($s0)
    /* 1A98 80064DF8 05000424 */  addiu      $a0, $zero, 0x5
  .L80064DFC:
    /* 1A9C 80064DFC EB9D010C */  jal        Stg11_CardStartOp
    /* 1AA0 80064E00 00000000 */   nop
    /* 1AA4 80064E04 6045000C */  jal        Task_NextState2
    /* 1AA8 80064E08 21202002 */   addu      $a0, $s1, $zero
    /* 1AAC 80064E0C AA930108 */  j          .L80064EA8
    /* 1AB0 80064E10 0680023C */   lui       $v0, %hi(Pad_State)
  jlabel .L80064E14
    /* 1AB4 80064E14 069E010C */  jal        Stg11_CardGetResult
    /* 1AB8 80064E18 00000000 */   nop
    /* 1ABC 80064E1C 21184000 */  addu       $v1, $v0, $zero
    /* 1AC0 80064E20 09000224 */  addiu      $v0, $zero, 0x9
    /* 1AC4 80064E24 0E006210 */  beq        $v1, $v0, .L80064E60
    /* 1AC8 80064E28 0A006228 */   slti      $v0, $v1, 0xA
    /* 1ACC 80064E2C 07004010 */  beqz       $v0, .L80064E4C
    /* 1AD0 80064E30 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 1AD4 80064E34 1C006210 */  beq        $v1, $v0, .L80064EA8
    /* 1AD8 80064E38 0680023C */   lui       $v0, %hi(Pad_State)
    /* 1ADC 80064E3C 12006010 */  beqz       $v1, .L80064E88
    /* 1AE0 80064E40 21202002 */   addu      $a0, $s1, $zero
    /* 1AE4 80064E44 A7930108 */  j          .L80064E9C
    /* 1AE8 80064E48 02000524 */   addiu     $a1, $zero, 0x2
  .L80064E4C:
    /* 1AEC 80064E4C 0A000224 */  addiu      $v0, $zero, 0xA
    /* 1AF0 80064E50 06006210 */  beq        $v1, $v0, .L80064E6C
    /* 1AF4 80064E54 21202002 */   addu      $a0, $s1, $zero
    /* 1AF8 80064E58 A7930108 */  j          .L80064E9C
    /* 1AFC 80064E5C 02000524 */   addiu     $a1, $zero, 0x2
  .L80064E60:
    /* 1B00 80064E60 21202002 */  addu       $a0, $s1, $zero
    /* 1B04 80064E64 A7930108 */  j          .L80064E9C
    /* 1B08 80064E68 06000524 */   addiu     $a1, $zero, 0x6
  .L80064E6C:
    /* 1B0C 80064E6C 7A000286 */  lh         $v0, 0x7A($s0)
    /* 1B10 80064E70 00000000 */  nop
    /* 1B14 80064E74 09004014 */  bnez       $v0, .L80064E9C
    /* 1B18 80064E78 02000524 */   addiu     $a1, $zero, 0x2
    /* 1B1C 80064E7C 21202002 */  addu       $a0, $s1, $zero
    /* 1B20 80064E80 A7930108 */  j          .L80064E9C
    /* 1B24 80064E84 04000524 */   addiu     $a1, $zero, 0x4
  .L80064E88:
    /* 1B28 80064E88 8545000C */  jal        Task_SetState2
    /* 1B2C 80064E8C 0A000524 */   addiu     $a1, $zero, 0xA
    /* 1B30 80064E90 AA930108 */  j          .L80064EA8
    /* 1B34 80064E94 0680023C */   lui       $v0, %hi(Pad_State)
  .L80064E98:
    /* 1B38 80064E98 02000524 */  addiu      $a1, $zero, 0x2
  .L80064E9C:
    /* 1B3C 80064E9C 7745000C */  jal        Task_SetState1
    /* 1B40 80064EA0 00000000 */   nop
  jlabel .L80064EA4
    /* 1B44 80064EA4 0680023C */  lui        $v0, %hi(Pad_State)
  .L80064EA8:
    /* 1B48 80064EA8 7E000386 */  lh         $v1, 0x7E($s0)
    /* 1B4C 80064EAC F0F64224 */  addiu      $v0, $v0, %lo(Pad_State)
    /* 1B50 80064EB0 80190300 */  sll        $v1, $v1, 6
    /* 1B54 80064EB4 21186200 */  addu       $v1, $v1, $v0
    /* 1B58 80064EB8 1C00628C */  lw         $v0, 0x1C($v1)
    /* 1B5C 80064EBC 00000000 */  nop
    /* 1B60 80064EC0 06004018 */  blez       $v0, .L80064EDC
    /* 1B64 80064EC4 0B000424 */   addiu     $a0, $zero, 0xB
    /* 1B68 80064EC8 A369000C */  jal        Snd_PlayById
    /* 1B6C 80064ECC 21280000 */   addu      $a1, $zero, $zero
    /* 1B70 80064ED0 21202002 */  addu       $a0, $s1, $zero
    /* 1B74 80064ED4 7045000C */  jal        Task_SetState0
    /* 1B78 80064ED8 02000524 */   addiu     $a1, $zero, 0x2
  .L80064EDC:
    /* 1B7C 80064EDC 1800BF8F */  lw         $ra, 0x18($sp)
    /* 1B80 80064EE0 1400B18F */  lw         $s1, 0x14($sp)
    /* 1B84 80064EE4 1000B08F */  lw         $s0, 0x10($sp)
    /* 1B88 80064EE8 0800E003 */  jr         $ra
    /* 1B8C 80064EEC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg11_StateCheckCard
