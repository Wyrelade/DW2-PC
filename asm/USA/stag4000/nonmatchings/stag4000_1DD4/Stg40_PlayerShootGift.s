nonmatching Stg40_PlayerShootGift, 0x514

glabel Stg40_PlayerShootGift
    /* 6C24 80069F84 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 6C28 80069F88 1800B2AF */  sw         $s2, 0x18($sp)
    /* 6C2C 80069F8C 21908000 */  addu       $s2, $a0, $zero
    /* 6C30 80069F90 0780023C */  lui        $v0, %hi(Stg40_RootState)
    /* 6C34 80069F94 602B448C */  lw         $a0, %lo(Stg40_RootState)($v0)
    /* 6C38 80069F98 2000BFAF */  sw         $ra, 0x20($sp)
    /* 6C3C 80069F9C 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 6C40 80069FA0 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6C44 80069FA4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6C48 80069FA8 1800458E */  lw         $a1, 0x18($s2)
    /* 6C4C 80069FAC 2C00428E */  lw         $v0, 0x2C($s2)
    /* 6C50 80069FB0 0800A32C */  sltiu      $v1, $a1, 0x8
    /* 6C54 80069FB4 2C00518C */  lw         $s1, 0x2C($v0)
    /* 6C58 80069FB8 4000938C */  lw         $s3, 0x40($a0)
    /* 6C5C 80069FBC 09006010 */  beqz       $v1, .L80069FE4
    /* 6C60 80069FC0 08018624 */   addiu     $a2, $a0, 0x108
    /* 6C64 80069FC4 0680023C */  lui        $v0, %hi(jtbl_80063404)
    /* 6C68 80069FC8 04344224 */  addiu      $v0, $v0, %lo(jtbl_80063404)
    /* 6C6C 80069FCC 80180500 */  sll        $v1, $a1, 2
    /* 6C70 80069FD0 21186200 */  addu       $v1, $v1, $v0
    /* 6C74 80069FD4 0000628C */  lw         $v0, 0x0($v1)
    /* 6C78 80069FD8 00000000 */  nop
    /* 6C7C 80069FDC 08004000 */  jr         $v0
    /* 6C80 80069FE0 00000000 */   nop
  jlabel .L80069FE4
    /* 6C84 80069FE4 21204002 */  addu       $a0, $s2, $zero
    /* 6C88 80069FE8 37B9010C */  jal        Stg40_ObjSetAnim
    /* 6C8C 80069FEC 29000524 */   addiu     $a1, $zero, 0x29
    /* 6C90 80069FF0 2400238E */  lw         $v1, 0x24($s1)
    /* 6C94 80069FF4 2400648E */  lw         $a0, 0x24($s3)
    /* 6C98 80069FF8 2800628E */  lw         $v0, 0x28($s3)
    /* 6C9C 80069FFC 2800258E */  lw         $a1, 0x28($s1)
    /* 6CA0 8006A000 23206400 */  subu       $a0, $v1, $a0
    /* 6CA4 8006A004 51B6000C */  jal        ratan2
    /* 6CA8 8006A008 23284500 */   subu      $a1, $v0, $a1
    /* 6CAC 8006A00C 0780103C */  lui        $s0, %hi(Stg40_RootState)
    /* 6CB0 8006A010 FF0F4430 */  andi       $a0, $v0, 0xFFF
    /* 6CB4 8006A014 602B028E */  lw         $v0, %lo(Stg40_RootState)($s0)
    /* 6CB8 8006A018 BDB2000C */  jal        rsin
    /* 6CBC 8006A01C E80044AC */   sw        $a0, 0xE8($v0)
    /* 6CC0 8006A020 602B038E */  lw         $v1, %lo(Stg40_RootState)($s0)
    /* 6CC4 8006A024 00000000 */  nop
    /* 6CC8 8006A028 E800648C */  lw         $a0, 0xE8($v1)
    /* 6CCC 8006A02C 23100200 */  negu       $v0, $v0
    /* 6CD0 8006A030 F1B2000C */  jal        rcos
    /* 6CD4 8006A034 EC0062AC */   sw        $v0, 0xEC($v1)
    /* 6CD8 8006A038 602B038E */  lw         $v1, %lo(Stg40_RootState)($s0)
    /* 6CDC 8006A03C 00000000 */  nop
    /* 6CE0 8006A040 F00062AC */  sw         $v0, 0xF0($v1)
    /* 6CE4 8006A044 18002286 */  lh         $v0, 0x18($s1)
    /* 6CE8 8006A048 00000000 */  nop
    /* 6CEC 8006A04C 80130200 */  sll        $v0, $v0, 14
    /* 6CF0 8006A050 F40062AC */  sw         $v0, 0xF4($v1)
    /* 6CF4 8006A054 1A002286 */  lh         $v0, 0x1A($s1)
    /* 6CF8 8006A058 00000000 */  nop
    /* 6CFC 8006A05C 80130200 */  sll        $v0, $v0, 14
    /* 6D00 8006A060 F80062AC */  sw         $v0, 0xF8($v1)
    /* 6D04 8006A064 18006286 */  lh         $v0, 0x18($s3)
    /* 6D08 8006A068 00000000 */  nop
    /* 6D0C 8006A06C 80130200 */  sll        $v0, $v0, 14
    /* 6D10 8006A070 FC0062AC */  sw         $v0, 0xFC($v1)
    /* 6D14 8006A074 1A006286 */  lh         $v0, 0x1A($s3)
    /* 6D18 8006A078 21204002 */  addu       $a0, $s2, $zero
    /* 6D1C 8006A07C 80130200 */  sll        $v0, $v0, 14
    /* 6D20 8006A080 6045000C */  jal        Task_NextState2
    /* 6D24 8006A084 000162AC */   sw        $v0, 0x100($v1)
    /* 6D28 8006A088 1FA90108 */  j          .L8006A47C
    /* 6D2C 8006A08C 00000000 */   nop
  jlabel .L8006A090
    /* 6D30 8006A090 0780023C */  lui        $v0, %hi(Stg40_RootState)
    /* 6D34 8006A094 602B458C */  lw         $a1, %lo(Stg40_RootState)($v0)
    /* 6D38 8006A098 0E002486 */  lh         $a0, 0xE($s1)
    /* 6D3C 8006A09C E800A28C */  lw         $v0, 0xE8($a1)
    /* 6D40 8006A0A0 0E002396 */  lhu        $v1, 0xE($s1)
    /* 6D44 8006A0A4 29008210 */  beq        $a0, $v0, .L8006A14C
    /* 6D48 8006A0A8 00F06324 */   addiu     $v1, $v1, -0x1000
    /* 6D4C 8006A0AC E800A294 */  lhu        $v0, 0xE8($a1)
    /* 6D50 8006A0B0 00000000 */  nop
    /* 6D54 8006A0B4 23104300 */  subu       $v0, $v0, $v1
    /* 6D58 8006A0B8 00140200 */  sll        $v0, $v0, 16
    /* 6D5C 8006A0BC 03140200 */  sra        $v0, $v0, 16
    /* 6D60 8006A0C0 02004104 */  bgez       $v0, .L8006A0CC
    /* 6D64 8006A0C4 00000000 */   nop
    /* 6D68 8006A0C8 FF074224 */  addiu      $v0, $v0, 0x7FF
  .L8006A0CC:
    /* 6D6C 8006A0CC C3120200 */  sra        $v0, $v0, 11
    /* 6D70 8006A0D0 01004230 */  andi       $v0, $v0, 0x1
    /* 6D74 8006A0D4 02004014 */  bnez       $v0, .L8006A0E0
    /* 6D78 8006A0D8 C0FF8224 */   addiu     $v0, $a0, -0x40
    /* 6D7C 8006A0DC 40008224 */  addiu      $v0, $a0, 0x40
  .L8006A0E0:
    /* 6D80 8006A0E0 0E0022A6 */  sh         $v0, 0xE($s1)
    /* 6D84 8006A0E4 0780023C */  lui        $v0, %hi(Stg40_RootState)
    /* 6D88 8006A0E8 0E002396 */  lhu        $v1, 0xE($s1)
    /* 6D8C 8006A0EC 602B428C */  lw         $v0, %lo(Stg40_RootState)($v0)
    /* 6D90 8006A0F0 FF0F6330 */  andi       $v1, $v1, 0xFFF
    /* 6D94 8006A0F4 0E0023A6 */  sh         $v1, 0xE($s1)
    /* 6D98 8006A0F8 E800448C */  lw         $a0, 0xE8($v0)
    /* 6D9C 8006A0FC 00000000 */  nop
    /* 6DA0 8006A100 23108300 */  subu       $v0, $a0, $v1
    /* 6DA4 8006A104 05004004 */  bltz       $v0, .L8006A11C
    /* 6DA8 8006A108 40004228 */   slti      $v0, $v0, 0x40
    /* 6DAC 8006A10C 07004014 */  bnez       $v0, .L8006A12C
    /* 6DB0 8006A110 0780023C */   lui       $v0, %hi(Stg40_RootState)
    /* 6DB4 8006A114 50A80108 */  j          .L8006A140
    /* 6DB8 8006A118 00000000 */   nop
  .L8006A11C:
    /* 6DBC 8006A11C 23106400 */  subu       $v0, $v1, $a0
    /* 6DC0 8006A120 40004228 */  slti       $v0, $v0, 0x40
    /* 6DC4 8006A124 06004010 */  beqz       $v0, .L8006A140
    /* 6DC8 8006A128 0780023C */   lui       $v0, %hi(Stg40_RootState)
  .L8006A12C:
    /* 6DCC 8006A12C 602B428C */  lw         $v0, %lo(Stg40_RootState)($v0)
    /* 6DD0 8006A130 00000000 */  nop
    /* 6DD4 8006A134 E8004294 */  lhu        $v0, 0xE8($v0)
    /* 6DD8 8006A138 00000000 */  nop
    /* 6DDC 8006A13C 0E0022A6 */  sh         $v0, 0xE($s1)
  .L8006A140:
    /* 6DE0 8006A140 0E002296 */  lhu        $v0, 0xE($s1)
    /* 6DE4 8006A144 1FA90108 */  j          .L8006A47C
    /* 6DE8 8006A148 0C0022A6 */   sh        $v0, 0xC($s1)
  .L8006A14C:
    /* 6DEC 8006A14C 21204002 */  addu       $a0, $s2, $zero
    /* 6DF0 8006A150 37B9010C */  jal        Stg40_ObjSetAnim
    /* 6DF4 8006A154 28000524 */   addiu     $a1, $zero, 0x28
    /* 6DF8 8006A158 0BA90108 */  j          .L8006A42C
    /* 6DFC 8006A15C 00000000 */   nop
  jlabel .L8006A160
    /* 6E00 8006A160 2000428E */  lw         $v0, 0x20($s2)
    /* 6E04 8006A164 00000000 */  nop
    /* 6E08 8006A168 21184000 */  addu       $v1, $v0, $zero
    /* 6E0C 8006A16C 01004224 */  addiu      $v0, $v0, 0x1
    /* 6E10 8006A170 10006328 */  slti       $v1, $v1, 0x10
    /* 6E14 8006A174 C1006014 */  bnez       $v1, .L8006A47C
    /* 6E18 8006A178 200042AE */   sw        $v0, 0x20($s2)
    /* 6E1C 8006A17C 2D000424 */  addiu      $a0, $zero, 0x2D
    /* 6E20 8006A180 A369000C */  jal        Snd_PlayById
    /* 6E24 8006A184 21280000 */   addu      $a1, $zero, $zero
    /* 6E28 8006A188 21204002 */  addu       $a0, $s2, $zero
    /* 6E2C 8006A18C 37B9010C */  jal        Stg40_ObjSetAnim
    /* 6E30 8006A190 2A000524 */   addiu     $a1, $zero, 0x2A
    /* 6E34 8006A194 0BA90108 */  j          .L8006A42C
    /* 6E38 8006A198 00000000 */   nop
  jlabel .L8006A19C
    /* 6E3C 8006A19C 2000428E */  lw         $v0, 0x20($s2)
    /* 6E40 8006A1A0 00000000 */  nop
    /* 6E44 8006A1A4 21184000 */  addu       $v1, $v0, $zero
    /* 6E48 8006A1A8 01004224 */  addiu      $v0, $v0, 0x1
    /* 6E4C 8006A1AC 06006328 */  slti       $v1, $v1, 0x6
    /* 6E50 8006A1B0 B2006014 */  bnez       $v1, .L8006A47C
    /* 6E54 8006A1B4 200042AE */   sw        $v0, 0x20($s2)
    /* 6E58 8006A1B8 0BA90108 */  j          .L8006A42C
    /* 6E5C 8006A1BC 00000000 */   nop
  jlabel .L8006A1C0
    /* 6E60 8006A1C0 0780103C */  lui        $s0, %hi(Stg40_RootState)
    /* 6E64 8006A1C4 602B038E */  lw         $v1, %lo(Stg40_RootState)($s0)
    /* 6E68 8006A1C8 00000000 */  nop
    /* 6E6C 8006A1CC F400628C */  lw         $v0, 0xF4($v1)
    /* 6E70 8006A1D0 EC00648C */  lw         $a0, 0xEC($v1)
    /* 6E74 8006A1D4 F000658C */  lw         $a1, 0xF0($v1)
    /* 6E78 8006A1D8 21104400 */  addu       $v0, $v0, $a0
    /* 6E7C 8006A1DC F40062AC */  sw         $v0, 0xF4($v1)
    /* 6E80 8006A1E0 F800628C */  lw         $v0, 0xF8($v1)
    /* 6E84 8006A1E4 F400648C */  lw         $a0, 0xF4($v1)
    /* 6E88 8006A1E8 21104500 */  addu       $v0, $v0, $a1
    /* 6E8C 8006A1EC 03220400 */  sra        $a0, $a0, 8
    /* 6E90 8006A1F0 F80062AC */  sw         $v0, 0xF8($v1)
    /* 6E94 8006A1F4 0C00C4AC */  sw         $a0, 0xC($a2)
    /* 6E98 8006A1F8 F800628C */  lw         $v0, 0xF8($v1)
    /* 6E9C 8006A1FC 2120C000 */  addu       $a0, $a2, $zero
    /* 6EA0 8006A200 03120200 */  sra        $v0, $v0, 8
    /* 6EA4 8006A204 4D94010C */  jal        Stg40_ScrollFollow
    /* 6EA8 8006A208 100082AC */   sw        $v0, 0x10($a0)
    /* 6EAC 8006A20C 602B028E */  lw         $v0, %lo(Stg40_RootState)($s0)
    /* 6EB0 8006A210 00000000 */  nop
    /* 6EB4 8006A214 EC00438C */  lw         $v1, 0xEC($v0)
    /* 6EB8 8006A218 FC00458C */  lw         $a1, 0xFC($v0)
    /* 6EBC 8006A21C F400428C */  lw         $v0, 0xF4($v0)
    /* 6EC0 8006A220 02006104 */  bgez       $v1, .L8006A22C
    /* 6EC4 8006A224 00000000 */   nop
    /* 6EC8 8006A228 23180300 */  negu       $v1, $v1
  .L8006A22C:
    /* 6ECC 8006A22C 2320A200 */  subu       $a0, $a1, $v0
    /* 6ED0 8006A230 06008004 */  bltz       $a0, .L8006A24C
    /* 6ED4 8006A234 23104500 */   subu      $v0, $v0, $a1
    /* 6ED8 8006A238 2A106400 */  slt        $v0, $v1, $a0
    /* 6EDC 8006A23C 06004010 */  beqz       $v0, .L8006A258
    /* 6EE0 8006A240 0780023C */   lui       $v0, %hi(Stg40_RootState)
    /* 6EE4 8006A244 1FA90108 */  j          .L8006A47C
    /* 6EE8 8006A248 00000000 */   nop
  .L8006A24C:
    /* 6EEC 8006A24C 2A106200 */  slt        $v0, $v1, $v0
    /* 6EF0 8006A250 8A004014 */  bnez       $v0, .L8006A47C
    /* 6EF4 8006A254 0780023C */   lui       $v0, %hi(Stg40_RootState)
  .L8006A258:
    /* 6EF8 8006A258 602B428C */  lw         $v0, %lo(Stg40_RootState)($v0)
    /* 6EFC 8006A25C 00000000 */  nop
    /* 6F00 8006A260 F000438C */  lw         $v1, 0xF0($v0)
    /* 6F04 8006A264 0001458C */  lw         $a1, 0x100($v0)
    /* 6F08 8006A268 F800428C */  lw         $v0, 0xF8($v0)
    /* 6F0C 8006A26C 02006104 */  bgez       $v1, .L8006A278
    /* 6F10 8006A270 00000000 */   nop
    /* 6F14 8006A274 23180300 */  negu       $v1, $v1
  .L8006A278:
    /* 6F18 8006A278 2320A200 */  subu       $a0, $a1, $v0
    /* 6F1C 8006A27C 06008004 */  bltz       $a0, .L8006A298
    /* 6F20 8006A280 23104500 */   subu      $v0, $v0, $a1
    /* 6F24 8006A284 2A106400 */  slt        $v0, $v1, $a0
    /* 6F28 8006A288 06004010 */  beqz       $v0, .L8006A2A4
    /* 6F2C 8006A28C 00000000 */   nop
    /* 6F30 8006A290 1FA90108 */  j          .L8006A47C
    /* 6F34 8006A294 00000000 */   nop
  .L8006A298:
    /* 6F38 8006A298 2A106200 */  slt        $v0, $v1, $v0
    /* 6F3C 8006A29C 77004014 */  bnez       $v0, .L8006A47C
    /* 6F40 8006A2A0 00000000 */   nop
  .L8006A2A4:
    /* 6F44 8006A2A4 4D94010C */  jal        Stg40_ScrollFollow
    /* 6F48 8006A2A8 18006426 */   addiu     $a0, $s3, 0x18
    /* 6F4C 8006A2AC 6045000C */  jal        Task_NextState2
    /* 6F50 8006A2B0 21204002 */   addu      $a0, $s2, $zero
    /* 6F54 8006A2B4 1B000424 */  addiu      $a0, $zero, 0x1B
    /* 6F58 8006A2B8 A369000C */  jal        Snd_PlayById
    /* 6F5C 8006A2BC 21280000 */   addu      $a1, $zero, $zero
    /* 6F60 8006A2C0 1FA90108 */  j          .L8006A47C
    /* 6F64 8006A2C4 00000000 */   nop
  jlabel .L8006A2C8
    /* 6F68 8006A2C8 2000428E */  lw         $v0, 0x20($s2)
    /* 6F6C 8006A2CC 00000000 */  nop
    /* 6F70 8006A2D0 21184000 */  addu       $v1, $v0, $zero
    /* 6F74 8006A2D4 01004224 */  addiu      $v0, $v0, 0x1
    /* 6F78 8006A2D8 1F006328 */  slti       $v1, $v1, 0x1F
    /* 6F7C 8006A2DC 67006014 */  bnez       $v1, .L8006A47C
    /* 6F80 8006A2E0 200042AE */   sw        $v0, 0x20($s2)
    /* 6F84 8006A2E4 1000708E */  lw         $s0, 0x10($s3)
    /* 6F88 8006A2E8 FD01113C */  lui        $s1, (0x1FD0050 >> 16)
    /* 6F8C 8006A2EC 0A000292 */  lbu        $v0, 0xA($s0)
    /* 6F90 8006A2F0 00000000 */  nop
    /* 6F94 8006A2F4 0900422C */  sltiu      $v0, $v0, 0x9
    /* 6F98 8006A2F8 2F004010 */  beqz       $v0, .L8006A3B8
    /* 6F9C 8006A2FC 50003136 */   ori       $s1, $s1, (0x1FD0050 & 0xFFFF)
    /* 6FA0 8006A300 0780023C */  lui        $v0, %hi(Stg40_RootState)
    /* 6FA4 8006A304 602B428C */  lw         $v0, %lo(Stg40_RootState)($v0)
    /* 6FA8 8006A308 00000000 */  nop
    /* 6FAC 8006A30C E0004490 */  lbu        $a0, 0xE0($v0)
    /* 6FB0 8006A310 3078000C */  jal        Item_GetCategory
    /* 6FB4 8006A314 00000000 */   nop
    /* 6FB8 8006A318 21184000 */  addu       $v1, $v0, $zero
    /* 6FBC 8006A31C 25006228 */  slti       $v0, $v1, 0x25
    /* 6FC0 8006A320 03004010 */  beqz       $v0, .L8006A330
    /* 6FC4 8006A324 22006228 */   slti      $v0, $v1, 0x22
    /* 6FC8 8006A328 02004010 */  beqz       $v0, .L8006A334
    /* 6FCC 8006A32C DEFF6324 */   addiu     $v1, $v1, -0x22
  .L8006A330:
    /* 6FD0 8006A330 03000324 */  addiu      $v1, $zero, 0x3
  .L8006A334:
    /* 6FD4 8006A334 03000224 */  addiu      $v0, $zero, 0x3
    /* 6FD8 8006A338 05006210 */  beq        $v1, $v0, .L8006A350
    /* 6FDC 8006A33C 00000000 */   nop
    /* 6FE0 8006A340 03000292 */  lbu        $v0, 0x3($s0)
    /* 6FE4 8006A344 00000000 */  nop
    /* 6FE8 8006A348 1B006214 */  bne        $v1, $v0, .L8006A3B8
    /* 6FEC 8006A34C 00000000 */   nop
  .L8006A350:
    /* 6FF0 8006A350 60C4010C */  jal        Stg40_RandPercent
    /* 6FF4 8006A354 00000000 */   nop
    /* 6FF8 8006A358 0780033C */  lui        $v1, %hi(Stg40_GiftTakeChance)
    /* 6FFC 8006A35C 0A000492 */  lbu        $a0, 0xA($s0)
    /* 7000 8006A360 88286324 */  addiu      $v1, $v1, %lo(Stg40_GiftTakeChance)
    /* 7004 8006A364 21188300 */  addu       $v1, $a0, $v1
    /* 7008 8006A368 00006390 */  lbu        $v1, 0x0($v1)
    /* 700C 8006A36C 00000000 */  nop
    /* 7010 8006A370 2A104300 */  slt        $v0, $v0, $v1
    /* 7014 8006A374 10004010 */  beqz       $v0, .L8006A3B8
    /* 7018 8006A378 01008224 */   addiu     $v0, $a0, 0x1
    /* 701C 8006A37C 0A0002A2 */  sb         $v0, 0xA($s0)
    /* 7020 8006A380 0780023C */  lui        $v0, %hi(Stg40_RootState)
    /* 7024 8006A384 602B428C */  lw         $v0, %lo(Stg40_RootState)($v0)
    /* 7028 8006A388 00000000 */  nop
    /* 702C 8006A38C E0004490 */  lbu        $a0, 0xE0($v0)
    /* 7030 8006A390 3978000C */  jal        Item_GetLevel
    /* 7034 8006A394 FD01113C */   lui       $s1, (0x1FD004F >> 16)
    /* 7038 8006A398 0780033C */  lui        $v1, %hi(Stg40_GiftPointsByLevel)
    /* 703C 8006A39C 94286324 */  addiu      $v1, $v1, %lo(Stg40_GiftPointsByLevel)
    /* 7040 8006A3A0 21104300 */  addu       $v0, $v0, $v1
    /* 7044 8006A3A4 FFFF4390 */  lbu        $v1, -0x1($v0)
    /* 7048 8006A3A8 0C000296 */  lhu        $v0, 0xC($s0)
    /* 704C 8006A3AC 4F003136 */  ori        $s1, $s1, (0x1FD004F & 0xFFFF)
    /* 7050 8006A3B0 21104300 */  addu       $v0, $v0, $v1
    /* 7054 8006A3B4 0C0002A6 */  sh         $v0, 0xC($s0)
  .L8006A3B8:
    /* 7058 8006A3B8 10000486 */  lh         $a0, 0x10($s0)
    /* 705C 8006A3BC D679000C */  jal        Digi_GetDefaultName
    /* 7060 8006A3C0 00000000 */   nop
    /* 7064 8006A3C4 0780033C */  lui        $v1, %hi(Stg40_RootState)
    /* 7068 8006A3C8 602B638C */  lw         $v1, %lo(Stg40_RootState)($v1)
    /* 706C 8006A3CC 00000000 */  nop
    /* 7070 8006A3D0 E0006490 */  lbu        $a0, 0xE0($v1)
    /* 7074 8006A3D4 1278000C */  jal        Item_GetNameText
    /* 7078 8006A3D8 21804000 */   addu      $s0, $v0, $zero
    /* 707C 8006A3DC 01000424 */  addiu      $a0, $zero, 0x1
    /* 7080 8006A3E0 21282002 */  addu       $a1, $s1, $zero
    /* 7084 8006A3E4 21300002 */  addu       $a2, $s0, $zero
    /* 7088 8006A3E8 849D010C */  jal        Stg40_MsgWinOpen
    /* 708C 8006A3EC 21384000 */   addu      $a3, $v0, $zero
    /* 7090 8006A3F0 0BA90108 */  j          .L8006A42C
    /* 7094 8006A3F4 00000000 */   nop
  jlabel .L8006A3F8
    /* 7098 8006A3F8 C19D010C */  jal        Stg40_MsgWinCloseIfDone
    /* 709C 8006A3FC 01000424 */   addiu     $a0, $zero, 0x1
    /* 70A0 8006A400 01000324 */  addiu      $v1, $zero, 0x1
    /* 70A4 8006A404 1D004314 */  bne        $v0, $v1, .L8006A47C
    /* 70A8 8006A408 18002426 */   addiu     $a0, $s1, 0x18
    /* 70AC 8006A40C 7094010C */  jal        Stg40_ScrollToFollow
    /* 70B0 8006A410 08000524 */   addiu     $a1, $zero, 0x8
    /* 70B4 8006A414 0780023C */  lui        $v0, %hi(Stg40_RootChildren)
    /* 70B8 8006A418 A42A428C */  lw         $v0, %lo(Stg40_RootChildren)($v0)
    /* 70BC 8006A41C 00000000 */  nop
    /* 70C0 8006A420 1400448C */  lw         $a0, 0x14($v0)
    /* 70C4 8006A424 7045000C */  jal        Task_SetState0
    /* 70C8 8006A428 02000524 */   addiu     $a1, $zero, 0x2
  .L8006A42C:
    /* 70CC 8006A42C 6045000C */  jal        Task_NextState2
    /* 70D0 8006A430 21204002 */   addu      $a0, $s2, $zero
    /* 70D4 8006A434 1FA90108 */  j          .L8006A47C
    /* 70D8 8006A438 00000000 */   nop
  jlabel .L8006A43C
    /* 70DC 8006A43C 0780023C */  lui        $v0, %hi(Stg40_RootChildren)
    /* 70E0 8006A440 A42A428C */  lw         $v0, %lo(Stg40_RootChildren)($v0)
    /* 70E4 8006A444 00000000 */  nop
    /* 70E8 8006A448 1400428C */  lw         $v0, 0x14($v0)
    /* 70EC 8006A44C 00000000 */  nop
    /* 70F0 8006A450 0A004010 */  beqz       $v0, .L8006A47C
    /* 70F4 8006A454 21204002 */   addu      $a0, $s2, $zero
    /* 70F8 8006A458 7745000C */  jal        Task_SetState1
    /* 70FC 8006A45C 06000524 */   addiu     $a1, $zero, 0x6
    /* 7100 8006A460 0780033C */  lui        $v1, %hi(Stg40_RootState)
    /* 7104 8006A464 0580023C */  lui        $v0, %hi(Save_GameStatePtr)
    /* 7108 8006A468 2007428C */  lw         $v0, %lo(Save_GameStatePtr)($v0)
    /* 710C 8006A46C 602B638C */  lw         $v1, %lo(Stg40_RootState)($v1)
    /* 7110 8006A470 00004290 */  lbu        $v0, 0x0($v0)
    /* 7114 8006A474 00000000 */  nop
    /* 7118 8006A478 7E0062A4 */  sh         $v0, 0x7E($v1)
  .L8006A47C:
    /* 711C 8006A47C 2000BF8F */  lw         $ra, 0x20($sp)
    /* 7120 8006A480 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 7124 8006A484 1800B28F */  lw         $s2, 0x18($sp)
    /* 7128 8006A488 1400B18F */  lw         $s1, 0x14($sp)
    /* 712C 8006A48C 1000B08F */  lw         $s0, 0x10($sp)
    /* 7130 8006A490 0800E003 */  jr         $ra
    /* 7134 8006A494 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel Stg40_PlayerShootGift
