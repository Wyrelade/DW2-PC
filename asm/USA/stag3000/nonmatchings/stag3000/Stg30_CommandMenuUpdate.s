nonmatching Stg30_CommandMenuUpdate, 0x48C

glabel Stg30_CommandMenuUpdate
    /* 17D0 80064B30 98FFBD27 */  addiu      $sp, $sp, -0x68
    /* 17D4 80064B34 4800B0AF */  sw         $s0, 0x48($sp)
    /* 17D8 80064B38 21808000 */  addu       $s0, $a0, $zero
    /* 17DC 80064B3C 01000624 */  addiu      $a2, $zero, 0x1
    /* 17E0 80064B40 6000BFAF */  sw         $ra, 0x60($sp)
    /* 17E4 80064B44 5C00B5AF */  sw         $s5, 0x5C($sp)
    /* 17E8 80064B48 5800B4AF */  sw         $s4, 0x58($sp)
    /* 17EC 80064B4C 5400B3AF */  sw         $s3, 0x54($sp)
    /* 17F0 80064B50 5000B2AF */  sw         $s2, 0x50($sp)
    /* 17F4 80064B54 4C00B1AF */  sw         $s1, 0x4C($sp)
    /* 17F8 80064B58 1000038E */  lw         $v1, 0x10($s0)
    /* 17FC 80064B5C 2C00148E */  lw         $s4, 0x2C($s0)
    /* 1800 80064B60 12006610 */  beq        $v1, $a2, .L80064BAC
    /* 1804 80064B64 02006228 */   slti      $v0, $v1, 0x2
    /* 1808 80064B68 05004010 */  beqz       $v0, .L80064B80
    /* 180C 80064B6C 00000000 */   nop
    /* 1810 80064B70 08006010 */  beqz       $v1, .L80064B94
    /* 1814 80064B74 0780023C */   lui       $v0, %hi(Stg30_CommandMenuCursor)
    /* 1818 80064B78 E6930108 */  j          .L80064F98
    /* 181C 80064B7C 00000000 */   nop
  .L80064B80:
    /* 1820 80064B80 02000224 */  addiu      $v0, $zero, 0x2
    /* 1824 80064B84 E3006210 */  beq        $v1, $v0, .L80064F14
    /* 1828 80064B88 00000000 */   nop
    /* 182C 80064B8C E6930108 */  j          .L80064F98
    /* 1830 80064B90 00000000 */   nop
  .L80064B94:
    /* 1834 80064B94 E03740AC */  sw         $zero, %lo(Stg30_CommandMenuCursor)($v0)
    /* 1838 80064B98 04008426 */  addiu      $a0, $s4, 0x4
    /* 183C 80064B9C 2270000C */  jal        Mem_FillWordsNeg1
    /* 1840 80064BA0 04000524 */   addiu     $a1, $zero, 0x4
    /* 1844 80064BA4 E4930108 */  j          .L80064F90
    /* 1848 80064BA8 00000000 */   nop
  .L80064BAC:
    /* 184C 80064BAC 1800028E */  lw         $v0, 0x18($s0)
    /* 1850 80064BB0 00000000 */  nop
    /* 1854 80064BB4 03004010 */  beqz       $v0, .L80064BC4
    /* 1858 80064BB8 00000000 */   nop
    /* 185C 80064BBC 2C004610 */  beq        $v0, $a2, .L80064C70
    /* 1860 80064BC0 0680023C */   lui       $v0, %hi(Pad_State)
  .L80064BC4:
    /* 1864 80064BC4 1C00028E */  lw         $v0, 0x1C($s0)
    /* 1868 80064BC8 00000000 */  nop
    /* 186C 80064BCC 03004010 */  beqz       $v0, .L80064BDC
    /* 1870 80064BD0 00000000 */   nop
    /* 1874 80064BD4 06004610 */  beq        $v0, $a2, .L80064BF0
    /* 1878 80064BD8 00000000 */   nop
  .L80064BDC:
    /* 187C 80064BDC 280000AE */  sw         $zero, 0x28($s0)
    /* 1880 80064BE0 6645000C */  jal        Task_NextState3
    /* 1884 80064BE4 21200002 */   addu      $a0, $s0, $zero
    /* 1888 80064BE8 E6930108 */  j          .L80064F98
    /* 188C 80064BEC 00000000 */   nop
  .L80064BF0:
    /* 1890 80064BF0 2800028E */  lw         $v0, 0x28($s0)
    /* 1894 80064BF4 00000000 */  nop
    /* 1898 80064BF8 0A004018 */  blez       $v0, .L80064C24
    /* 189C 80064BFC 21180000 */   addu      $v1, $zero, $zero
  .L80064C00:
    /* 18A0 80064C00 00008296 */  lhu        $v0, 0x0($s4)
    /* 18A4 80064C04 00000000 */  nop
    /* 18A8 80064C08 AA024224 */  addiu      $v0, $v0, 0x2AA
    /* 18AC 80064C0C 000082A6 */  sh         $v0, 0x0($s4)
    /* 18B0 80064C10 2800028E */  lw         $v0, 0x28($s0)
    /* 18B4 80064C14 01006324 */  addiu      $v1, $v1, 0x1
    /* 18B8 80064C18 2A106200 */  slt        $v0, $v1, $v0
    /* 18BC 80064C1C F8FF4014 */  bnez       $v0, .L80064C00
    /* 18C0 80064C20 00000000 */   nop
  .L80064C24:
    /* 18C4 80064C24 280000AE */  sw         $zero, 0x28($s0)
    /* 18C8 80064C28 00008286 */  lh         $v0, 0x0($s4)
    /* 18CC 80064C2C 00000000 */  nop
    /* 18D0 80064C30 01104228 */  slti       $v0, $v0, 0x1001
    /* 18D4 80064C34 D8004014 */  bnez       $v0, .L80064F98
    /* 18D8 80064C38 00100224 */   addiu     $v0, $zero, 0x1000
    /* 18DC 80064C3C 000082A6 */  sh         $v0, 0x0($s4)
    /* 18E0 80064C40 6045000C */  jal        Task_NextState2
    /* 18E4 80064C44 21200002 */   addu      $a0, $s0, $zero
    /* 18E8 80064C48 E6930108 */  j          .L80064F98
    /* 18EC 80064C4C 00000000 */   nop
  .L80064C50:
    /* 18F0 80064C50 0A000424 */  addiu      $a0, $zero, 0xA
    /* 18F4 80064C54 21280000 */  addu       $a1, $zero, $zero
    /* 18F8 80064C58 0780033C */  lui        $v1, %hi(Stg30_CommandMenuCursor)
    /* 18FC 80064C5C E037638C */  lw         $v1, %lo(Stg30_CommandMenuCursor)($v1)
    /* 1900 80064C60 C03C4224 */  addiu      $v0, $v0, %lo(Stg30_Battle)
    /* 1904 80064C64 140040AC */  sw         $zero, 0x14($v0)
    /* 1908 80064C68 55930108 */  j          .L80064D54
    /* 190C 80064C6C 100043AC */   sw        $v1, 0x10($v0)
  .L80064C70:
    /* 1910 80064C70 F0F64424 */  addiu      $a0, $v0, %lo(Pad_State)
    /* 1914 80064C74 0800828C */  lw         $v0, 0x8($a0)
    /* 1918 80064C78 00000000 */  nop
    /* 191C 80064C7C 07004018 */  blez       $v0, .L80064C9C
    /* 1920 80064C80 0780033C */   lui       $v1, %hi(Stg30_CommandMenuCursor)
    /* 1924 80064C84 E037628C */  lw         $v0, %lo(Stg30_CommandMenuCursor)($v1)
    /* 1928 80064C88 00000000 */  nop
    /* 192C 80064C8C 35004010 */  beqz       $v0, .L80064D64
    /* 1930 80064C90 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 1934 80064C94 40930108 */  j          .L80064D00
    /* 1938 80064C98 E03762AC */   sw        $v0, %lo(Stg30_CommandMenuCursor)($v1)
  .L80064C9C:
    /* 193C 80064C9C 0C00828C */  lw         $v0, 0xC($a0)
    /* 1940 80064CA0 00000000 */  nop
    /* 1944 80064CA4 1B004018 */  blez       $v0, .L80064D14
    /* 1948 80064CA8 0780053C */   lui       $a1, %hi(Stg30_Battle)
    /* 194C 80064CAC C03CA224 */  addiu      $v0, $a1, %lo(Stg30_Battle)
    /* 1950 80064CB0 0800438C */  lw         $v1, 0x8($v0)
    /* 1954 80064CB4 06000224 */  addiu      $v0, $zero, 0x6
    /* 1958 80064CB8 0C006214 */  bne        $v1, $v0, .L80064CEC
    /* 195C 80064CBC 0780033C */   lui       $v1, %hi(Stg30_CommandMenuCursor)
    /* 1960 80064CC0 0780043C */  lui        $a0, %hi(Stg30_CommandMenuCursor)
    /* 1964 80064CC4 E037838C */  lw         $v1, %lo(Stg30_CommandMenuCursor)($a0)
    /* 1968 80064CC8 02000224 */  addiu      $v0, $zero, 0x2
    /* 196C 80064CCC 26006210 */  beq        $v1, $v0, .L80064D68
    /* 1970 80064CD0 0780023C */   lui       $v0, %hi(Stg30_Battle)
    /* 1974 80064CD4 C03CA28C */  lw         $v0, %lo(Stg30_Battle)($a1)
    /* 1978 80064CD8 00000000 */  nop
    /* 197C 80064CDC 21004014 */  bnez       $v0, .L80064D64
    /* 1980 80064CE0 01006224 */   addiu     $v0, $v1, 0x1
    /* 1984 80064CE4 40930108 */  j          .L80064D00
    /* 1988 80064CE8 E03782AC */   sw        $v0, %lo(Stg30_CommandMenuCursor)($a0)
  .L80064CEC:
    /* 198C 80064CEC E037628C */  lw         $v0, %lo(Stg30_CommandMenuCursor)($v1)
    /* 1990 80064CF0 00000000 */  nop
    /* 1994 80064CF4 1B004610 */  beq        $v0, $a2, .L80064D64
    /* 1998 80064CF8 01004224 */   addiu     $v0, $v0, 0x1
    /* 199C 80064CFC E03762AC */  sw         $v0, %lo(Stg30_CommandMenuCursor)($v1)
  .L80064D00:
    /* 19A0 80064D00 0C000424 */  addiu      $a0, $zero, 0xC
    /* 19A4 80064D04 A369000C */  jal        Snd_PlayById
    /* 19A8 80064D08 21280000 */   addu      $a1, $zero, $zero
    /* 19AC 80064D0C 5A930108 */  j          .L80064D68
    /* 19B0 80064D10 0780023C */   lui       $v0, %hi(Stg30_Battle)
  .L80064D14:
    /* 19B4 80064D14 1400828C */  lw         $v0, 0x14($a0)
    /* 19B8 80064D18 00000000 */  nop
    /* 19BC 80064D1C CCFF401C */  bgtz       $v0, .L80064C50
    /* 19C0 80064D20 0780023C */   lui       $v0, %hi(Stg30_Battle)
    /* 19C4 80064D24 C03C4524 */  addiu      $a1, $v0, %lo(Stg30_Battle)
    /* 19C8 80064D28 0800A38C */  lw         $v1, 0x8($a1)
    /* 19CC 80064D2C 06000224 */  addiu      $v0, $zero, 0x6
    /* 19D0 80064D30 12006210 */  beq        $v1, $v0, .L80064D7C
    /* 19D4 80064D34 00000000 */   nop
    /* 19D8 80064D38 1C00828C */  lw         $v0, 0x1C($a0)
    /* 19DC 80064D3C 00000000 */  nop
    /* 19E0 80064D40 09004018 */  blez       $v0, .L80064D68
    /* 19E4 80064D44 0780023C */   lui       $v0, %hi(Stg30_Battle)
    /* 19E8 80064D48 1400A6AC */  sw         $a2, 0x14($a1)
    /* 19EC 80064D4C 0B000424 */  addiu      $a0, $zero, 0xB
    /* 19F0 80064D50 21280000 */  addu       $a1, $zero, $zero
  .L80064D54:
    /* 19F4 80064D54 A369000C */  jal        Snd_PlayById
    /* 19F8 80064D58 00000000 */   nop
    /* 19FC 80064D5C 5145000C */  jal        Task_NextState0
    /* 1A00 80064D60 21200002 */   addu      $a0, $s0, $zero
  .L80064D64:
    /* 1A04 80064D64 0780023C */  lui        $v0, %hi(Stg30_Battle)
  .L80064D68:
    /* 1A08 80064D68 C03C4724 */  addiu      $a3, $v0, %lo(Stg30_Battle)
    /* 1A0C 80064D6C 0800E68C */  lw         $a2, 0x8($a3)
    /* 1A10 80064D70 06000224 */  addiu      $v0, $zero, 0x6
    /* 1A14 80064D74 3600C214 */  bne        $a2, $v0, .L80064E50
    /* 1A18 80064D78 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L80064D7C:
    /* 1A1C 80064D7C 04008426 */  addiu      $a0, $s4, 0x4
    /* 1A20 80064D80 0680053C */  lui        $a1, %hi(Save_PlayerName)
    /* 1A24 80064D84 34E6A524 */  addiu      $a1, $a1, %lo(Save_PlayerName)
    /* 1A28 80064D88 10000624 */  addiu      $a2, $zero, 0x10
    /* 1A2C 80064D8C 21980000 */  addu       $s3, $zero, $zero
    /* 1A30 80064D90 16001524 */  addiu      $s5, $zero, 0x16
    /* 1A34 80064D94 3C001224 */  addiu      $s2, $zero, 0x3C
    /* 1A38 80064D98 02001124 */  addiu      $s1, $zero, 0x2
    /* 1A3C 80064D9C 08001024 */  addiu      $s0, $zero, 0x8
    /* 1A40 80064DA0 0680033C */  lui        $v1, %hi(Stg30_TamerNameTextPos)
    /* 1A44 80064DA4 E8336224 */  addiu      $v0, $v1, %lo(Stg30_TamerNameTextPos)
    /* 1A48 80064DA8 02004794 */  lhu        $a3, 0x2($v0)
    /* 1A4C 80064DAC E8336294 */  lhu        $v0, %lo(Stg30_TamerNameTextPos)($v1)
    /* 1A50 80064DB0 0438C700 */  sllv       $a3, $a3, $a2
    /* 1A54 80064DB4 3E4D000C */  jal        Text_OpenPacked
    /* 1A58 80064DB8 25384700 */   or        $a3, $v0, $a3
  .L80064DBC:
    /* 1A5C 80064DBC 0780023C */  lui        $v0, %hi(Stg30_Battle)
    /* 1A60 80064DC0 C03C428C */  lw         $v0, %lo(Stg30_Battle)($v0)
    /* 1A64 80064DC4 00000000 */  nop
    /* 1A68 80064DC8 08004010 */  beqz       $v0, .L80064DEC
    /* 1A6C 80064DCC 0780023C */   lui       $v0, %hi(Stg30_CommandMenuCursor)
    /* 1A70 80064DD0 06006012 */  beqz       $s3, .L80064DEC
    /* 1A74 80064DD4 21209002 */   addu      $a0, $s4, $s0
    /* 1A78 80064DD8 21282002 */  addu       $a1, $s1, $zero
    /* 1A7C 80064DDC 1200B2A7 */  sh         $s2, 0x12($sp)
    /* 1A80 80064DE0 FFFF4732 */  andi       $a3, $s2, 0xFFFF
    /* 1A84 80064DE4 88930108 */  j          .L80064E20
    /* 1A88 80064DE8 03000624 */   addiu     $a2, $zero, 0x3
  .L80064DEC:
    /* 1A8C 80064DEC E037428C */  lw         $v0, %lo(Stg30_CommandMenuCursor)($v0)
    /* 1A90 80064DF0 00000000 */  nop
    /* 1A94 80064DF4 06005314 */  bne        $v0, $s3, .L80064E10
    /* 1A98 80064DF8 21209002 */   addu      $a0, $s4, $s0
    /* 1A9C 80064DFC 21282002 */  addu       $a1, $s1, $zero
    /* 1AA0 80064E00 1200B2A7 */  sh         $s2, 0x12($sp)
    /* 1AA4 80064E04 FFFF4732 */  andi       $a3, $s2, 0xFFFF
    /* 1AA8 80064E08 88930108 */  j          .L80064E20
    /* 1AAC 80064E0C 21300000 */   addu      $a2, $zero, $zero
  .L80064E10:
    /* 1AB0 80064E10 21282002 */  addu       $a1, $s1, $zero
    /* 1AB4 80064E14 1200B2A7 */  sh         $s2, 0x12($sp)
    /* 1AB8 80064E18 FFFF4732 */  andi       $a3, $s2, 0xFFFF
    /* 1ABC 80064E1C 01000624 */  addiu      $a2, $zero, 0x1
  .L80064E20:
    /* 1AC0 80064E20 003C0700 */  sll        $a3, $a3, 16
    /* 1AC4 80064E24 1600E734 */  ori        $a3, $a3, 0x16
    /* 1AC8 80064E28 F26F000C */  jal        Text_OpenById
    /* 1ACC 80064E2C 1000B5A7 */   sh        $s5, 0x10($sp)
    /* 1AD0 80064E30 0B005226 */  addiu      $s2, $s2, 0xB
    /* 1AD4 80064E34 01003126 */  addiu      $s1, $s1, 0x1
    /* 1AD8 80064E38 01007326 */  addiu      $s3, $s3, 0x1
    /* 1ADC 80064E3C 0300622A */  slti       $v0, $s3, 0x3
    /* 1AE0 80064E40 DEFF4014 */  bnez       $v0, .L80064DBC
    /* 1AE4 80064E44 04001026 */   addiu     $s0, $s0, 0x4
    /* 1AE8 80064E48 E6930108 */  j          .L80064F98
    /* 1AEC 80064E4C 00000000 */   nop
  .L80064E50:
    /* 1AF0 80064E50 0400838E */  lw         $v1, 0x4($s4)
    /* 1AF4 80064E54 00000000 */  nop
    /* 1AF8 80064E58 17006214 */  bne        $v1, $v0, .L80064EB8
    /* 1AFC 80064E5C 21800000 */   addu      $s0, $zero, $zero
    /* 1B00 80064E60 04008426 */  addiu      $a0, $s4, 0x4
    /* 1B04 80064E64 1800A527 */  addiu      $a1, $sp, 0x18
    /* 1B08 80064E68 40100600 */  sll        $v0, $a2, 1
    /* 1B0C 80064E6C 21104600 */  addu       $v0, $v0, $a2
    /* 1B10 80064E70 C0100200 */  sll        $v0, $v0, 3
    /* 1B14 80064E74 23104600 */  subu       $v0, $v0, $a2
    /* 1B18 80064E78 80100200 */  sll        $v0, $v0, 2
    /* 1B1C 80064E7C 6400E324 */  addiu      $v1, $a3, 0x64
    /* 1B20 80064E80 21104300 */  addu       $v0, $v0, $v1
    /* 1B24 80064E84 2C00A2AF */  sw         $v0, 0x2C($sp)
    /* 1B28 80064E88 04000224 */  addiu      $v0, $zero, 0x4
    /* 1B2C 80064E8C 1C00A2AF */  sw         $v0, 0x1C($sp)
    /* 1B30 80064E90 16000224 */  addiu      $v0, $zero, 0x16
    /* 1B34 80064E94 2000A2A7 */  sh         $v0, 0x20($sp)
    /* 1B38 80064E98 30000224 */  addiu      $v0, $zero, 0x30
    /* 1B3C 80064E9C 1800A0AF */  sw         $zero, 0x18($sp)
    /* 1B40 80064EA0 2200A2A7 */  sh         $v0, 0x22($sp)
    /* 1B44 80064EA4 3000A0AF */  sw         $zero, 0x30($sp)
    /* 1B48 80064EA8 2400A0AF */  sw         $zero, 0x24($sp)
    /* 1B4C 80064EAC 096F000C */  jal        Text_Open
    /* 1B50 80064EB0 2800A0AF */   sw        $zero, 0x28($sp)
    /* 1B54 80064EB4 21800000 */  addu       $s0, $zero, $zero
  .L80064EB8:
    /* 1B58 80064EB8 3C001224 */  addiu      $s2, $zero, 0x3C
    /* 1B5C 80064EBC 08001124 */  addiu      $s1, $zero, 0x8
    /* 1B60 80064EC0 21209102 */  addu       $a0, $s4, $s1
  .L80064EC4:
    /* 1B64 80064EC4 05000526 */  addiu      $a1, $s0, 0x5
    /* 1B68 80064EC8 1200B2A7 */  sh         $s2, 0x12($sp)
    /* 1B6C 80064ECC 0B005226 */  addiu      $s2, $s2, 0xB
    /* 1B70 80064ED0 04003126 */  addiu      $s1, $s1, 0x4
    /* 1B74 80064ED4 0780023C */  lui        $v0, %hi(Stg30_CommandMenuCursor)
    /* 1B78 80064ED8 E037468C */  lw         $a2, %lo(Stg30_CommandMenuCursor)($v0)
    /* 1B7C 80064EDC 1200A797 */  lhu        $a3, 0x12($sp)
    /* 1B80 80064EE0 16000224 */  addiu      $v0, $zero, 0x16
    /* 1B84 80064EE4 1000A2A7 */  sh         $v0, 0x10($sp)
    /* 1B88 80064EE8 2630D000 */  xor        $a2, $a2, $s0
    /* 1B8C 80064EEC 2B300600 */  sltu       $a2, $zero, $a2
    /* 1B90 80064EF0 003C0700 */  sll        $a3, $a3, 16
    /* 1B94 80064EF4 F26F000C */  jal        Text_OpenById
    /* 1B98 80064EF8 1600E734 */   ori       $a3, $a3, 0x16
    /* 1B9C 80064EFC 01001026 */  addiu      $s0, $s0, 0x1
    /* 1BA0 80064F00 0200022A */  slti       $v0, $s0, 0x2
    /* 1BA4 80064F04 EFFF4014 */  bnez       $v0, .L80064EC4
    /* 1BA8 80064F08 21209102 */   addu      $a0, $s4, $s1
    /* 1BAC 80064F0C E6930108 */  j          .L80064F98
    /* 1BB0 80064F10 00000000 */   nop
  .L80064F14:
    /* 1BB4 80064F14 1400028E */  lw         $v0, 0x14($s0)
    /* 1BB8 80064F18 00000000 */  nop
    /* 1BBC 80064F1C 03004010 */  beqz       $v0, .L80064F2C
    /* 1BC0 80064F20 04008426 */   addiu     $a0, $s4, 0x4
    /* 1BC4 80064F24 08004610 */  beq        $v0, $a2, .L80064F48
    /* 1BC8 80064F28 00000000 */   nop
  .L80064F2C:
    /* 1BCC 80064F2C 2C70000C */  jal        Text_CloseArray
    /* 1BD0 80064F30 04000524 */   addiu     $a1, $zero, 0x4
    /* 1BD4 80064F34 280000AE */  sw         $zero, 0x28($s0)
    /* 1BD8 80064F38 5945000C */  jal        Task_NextState1
    /* 1BDC 80064F3C 21200002 */   addu      $a0, $s0, $zero
    /* 1BE0 80064F40 E6930108 */  j          .L80064F98
    /* 1BE4 80064F44 00000000 */   nop
  .L80064F48:
    /* 1BE8 80064F48 2800028E */  lw         $v0, 0x28($s0)
    /* 1BEC 80064F4C 00000000 */  nop
    /* 1BF0 80064F50 0A004018 */  blez       $v0, .L80064F7C
    /* 1BF4 80064F54 21180000 */   addu      $v1, $zero, $zero
  .L80064F58:
    /* 1BF8 80064F58 00008296 */  lhu        $v0, 0x0($s4)
    /* 1BFC 80064F5C 00000000 */  nop
    /* 1C00 80064F60 56FD4224 */  addiu      $v0, $v0, -0x2AA
    /* 1C04 80064F64 000082A6 */  sh         $v0, 0x0($s4)
    /* 1C08 80064F68 2800028E */  lw         $v0, 0x28($s0)
    /* 1C0C 80064F6C 01006324 */  addiu      $v1, $v1, 0x1
    /* 1C10 80064F70 2A106200 */  slt        $v0, $v1, $v0
    /* 1C14 80064F74 F8FF4014 */  bnez       $v0, .L80064F58
    /* 1C18 80064F78 00000000 */   nop
  .L80064F7C:
    /* 1C1C 80064F7C 00008286 */  lh         $v0, 0x0($s4)
    /* 1C20 80064F80 00000000 */  nop
    /* 1C24 80064F84 0400401C */  bgtz       $v0, .L80064F98
    /* 1C28 80064F88 00000000 */   nop
    /* 1C2C 80064F8C 000080A6 */  sh         $zero, 0x0($s4)
  .L80064F90:
    /* 1C30 80064F90 5145000C */  jal        Task_NextState0
    /* 1C34 80064F94 21200002 */   addu      $a0, $s0, $zero
  .L80064F98:
    /* 1C38 80064F98 6000BF8F */  lw         $ra, 0x60($sp)
    /* 1C3C 80064F9C 5C00B58F */  lw         $s5, 0x5C($sp)
    /* 1C40 80064FA0 5800B48F */  lw         $s4, 0x58($sp)
    /* 1C44 80064FA4 5400B38F */  lw         $s3, 0x54($sp)
    /* 1C48 80064FA8 5000B28F */  lw         $s2, 0x50($sp)
    /* 1C4C 80064FAC 4C00B18F */  lw         $s1, 0x4C($sp)
    /* 1C50 80064FB0 4800B08F */  lw         $s0, 0x48($sp)
    /* 1C54 80064FB4 0800E003 */  jr         $ra
    /* 1C58 80064FB8 6800BD27 */   addiu     $sp, $sp, 0x68
endlabel Stg30_CommandMenuUpdate
