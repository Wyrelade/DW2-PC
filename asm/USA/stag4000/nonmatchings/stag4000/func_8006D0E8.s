nonmatching func_8006D0E8, 0x330

glabel func_8006D0E8
    /* 9D88 8006D0E8 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 9D8C 8006D0EC 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 9D90 8006D0F0 21888000 */  addu       $s1, $a0, $zero
    /* 9D94 8006D0F4 2400BFAF */  sw         $ra, 0x24($sp)
    /* 9D98 8006D0F8 2000B2AF */  sw         $s2, 0x20($sp)
    /* 9D9C 8006D0FC 1800B0AF */  sw         $s0, 0x18($sp)
    /* 9DA0 8006D100 2C00228E */  lw         $v0, 0x2C($s1)
    /* 9DA4 8006D104 00000000 */  nop
    /* 9DA8 8006D108 2C00508C */  lw         $s0, 0x2C($v0)
    /* 9DAC 8006D10C 00000000 */  nop
    /* 9DB0 8006D110 18000486 */  lh         $a0, 0x18($s0)
    /* 9DB4 8006D114 1A000586 */  lh         $a1, 0x1A($s0)
    /* 9DB8 8006D118 3FC2010C */  jal        func_800708FC
    /* 9DBC 8006D11C 21300000 */   addu      $a2, $zero, $zero
    /* 9DC0 8006D120 0000028E */  lw         $v0, 0x0($s0)
    /* 9DC4 8006D124 00000000 */  nop
    /* 9DC8 8006D128 00104230 */  andi       $v0, $v0, 0x1000
    /* 9DCC 8006D12C 07004010 */  beqz       $v0, .L8006D14C
    /* 9DD0 8006D130 FFFF0624 */   addiu     $a2, $zero, -0x1
    /* 9DD4 8006D134 18000486 */  lh         $a0, 0x18($s0)
    /* 9DD8 8006D138 1A000586 */  lh         $a1, 0x1A($s0)
    /* 9DDC 8006D13C 08000292 */  lbu        $v0, 0x8($s0)
    /* 9DE0 8006D140 2138C000 */  addu       $a3, $a2, $zero
    /* 9DE4 8006D144 FDBA010C */  jal        func_8006EBF4
    /* 9DE8 8006D148 1000A2AF */   sw        $v0, 0x10($sp)
  .L8006D14C:
    /* 9DEC 8006D14C 1400238E */  lw         $v1, 0x14($s1)
    /* 9DF0 8006D150 00000000 */  nop
    /* 9DF4 8006D154 0700622C */  sltiu      $v0, $v1, 0x7
    /* 9DF8 8006D158 08004010 */  beqz       $v0, .L8006D17C
    /* 9DFC 8006D15C 0680023C */   lui       $v0, %hi(jtbl_800635AC)
    /* 9E00 8006D160 AC354224 */  addiu      $v0, $v0, %lo(jtbl_800635AC)
    /* 9E04 8006D164 80180300 */  sll        $v1, $v1, 2
    /* 9E08 8006D168 21186200 */  addu       $v1, $v1, $v0
    /* 9E0C 8006D16C 0000628C */  lw         $v0, 0x0($v1)
    /* 9E10 8006D170 00000000 */  nop
    /* 9E14 8006D174 08004000 */  jr         $v0
    /* 9E18 8006D178 00000000 */   nop
  jlabel .L8006D17C
    /* 9E1C 8006D17C 0000038E */  lw         $v1, 0x0($s0)
    /* 9E20 8006D180 00280224 */  addiu      $v0, $zero, 0x2800
    /* 9E24 8006D184 2C0002AE */  sw         $v0, 0x2C($s0)
    /* 9E28 8006D188 00106230 */  andi       $v0, $v1, 0x1000
    /* 9E2C 8006D18C 03004014 */  bnez       $v0, .L8006D19C
    /* 9E30 8006D190 00446234 */   ori       $v0, $v1, 0x4400
    /* 9E34 8006D194 FFBF0224 */  addiu      $v0, $zero, -0x4001
    /* 9E38 8006D198 24106200 */  and        $v0, $v1, $v0
  .L8006D19C:
    /* 9E3C 8006D19C 000002AE */  sw         $v0, 0x0($s0)
    /* 9E40 8006D1A0 21202002 */  addu       $a0, $s1, $zero
    /* 9E44 8006D1A4 FEB40108 */  j          .L8006D3F8
    /* 9E48 8006D1A8 01000524 */   addiu     $a1, $zero, 0x1
  jlabel .L8006D1AC
    /* 9E4C 8006D1AC 18000486 */  lh         $a0, 0x18($s0)
    /* 9E50 8006D1B0 1A000586 */  lh         $a1, 0x1A($s0)
    /* 9E54 8006D1B4 5DC2010C */  jal        func_80070974
    /* 9E58 8006D1B8 00000000 */   nop
    /* 9E5C 8006D1BC FFFF0424 */  addiu      $a0, $zero, -0x1
    /* 9E60 8006D1C0 18000686 */  lh         $a2, 0x18($s0)
    /* 9E64 8006D1C4 1A000786 */  lh         $a3, 0x1A($s0)
    /* 9E68 8006D1C8 08000292 */  lbu        $v0, 0x8($s0)
    /* 9E6C 8006D1CC 21288000 */  addu       $a1, $a0, $zero
    /* 9E70 8006D1D0 FDBA010C */  jal        func_8006EBF4
    /* 9E74 8006D1D4 1000A2AF */   sw        $v0, 0x10($sp)
    /* 9E78 8006D1D8 21202002 */  addu       $a0, $s1, $zero
    /* 9E7C 8006D1DC 03000524 */  addiu      $a1, $zero, 0x3
    /* 9E80 8006D1E0 7045000C */  jal        Task_SetState0
    /* 9E84 8006D1E4 000000AE */   sw        $zero, 0x0($s0)
    /* 9E88 8006D1E8 00B50108 */  j          .L8006D400
    /* 9E8C 8006D1EC 00000000 */   nop
  jlabel .L8006D1F0
    /* 9E90 8006D1F0 1800238E */  lw         $v1, 0x18($s1)
    /* 9E94 8006D1F4 01001224 */  addiu      $s2, $zero, 0x1
    /* 9E98 8006D1F8 17007210 */  beq        $v1, $s2, .L8006D258
    /* 9E9C 8006D1FC 02006228 */   slti      $v0, $v1, 0x2
    /* 9EA0 8006D200 06004014 */  bnez       $v0, .L8006D21C
    /* 9EA4 8006D204 21202002 */   addu      $a0, $s1, $zero
    /* 9EA8 8006D208 02000224 */  addiu      $v0, $zero, 0x2
    /* 9EAC 8006D20C 22006210 */  beq        $v1, $v0, .L8006D298
    /* 9EB0 8006D210 03000224 */   addiu     $v0, $zero, 0x3
    /* 9EB4 8006D214 2A006210 */  beq        $v1, $v0, .L8006D2C0
    /* 9EB8 8006D218 00000000 */   nop
  .L8006D21C:
    /* 9EBC 8006D21C 28000524 */  addiu      $a1, $zero, 0x28
    /* 9EC0 8006D220 0000028E */  lw         $v0, 0x0($s0)
    /* 9EC4 8006D224 FFFB0324 */  addiu      $v1, $zero, -0x401
    /* 9EC8 8006D228 00504234 */  ori        $v0, $v0, 0x5000
    /* 9ECC 8006D22C 24104300 */  and        $v0, $v0, $v1
    /* 9ED0 8006D230 37B9010C */  jal        func_8006E4DC
    /* 9ED4 8006D234 000002AE */   sw        $v0, 0x0($s0)
    /* 9ED8 8006D238 04000424 */  addiu      $a0, $zero, 0x4
    /* 9EDC 8006D23C 21280000 */  addu       $a1, $zero, $zero
    /* 9EE0 8006D240 00280224 */  addiu      $v0, $zero, 0x2800
    /* 9EE4 8006D244 300000AE */  sw         $zero, 0x30($s0)
    /* 9EE8 8006D248 A369000C */  jal        Snd_PlayById
    /* 9EEC 8006D24C 2C0002AE */   sw        $v0, 0x2C($s0)
    /* 9EF0 8006D250 F5B40108 */  j          .L8006D3D4
    /* 9EF4 8006D254 00000000 */   nop
  .L8006D258:
    /* 9EF8 8006D258 3000028E */  lw         $v0, 0x30($s0)
    /* 9EFC 8006D25C 2C00038E */  lw         $v1, 0x2C($s0)
    /* 9F00 8006D260 26004224 */  addiu      $v0, $v0, 0x26
    /* 9F04 8006D264 23186200 */  subu       $v1, $v1, $v0
    /* 9F08 8006D268 2C0003AE */  sw         $v1, 0x2C($s0)
    /* 9F0C 8006D26C 00056328 */  slti       $v1, $v1, 0x500
    /* 9F10 8006D270 63006010 */  beqz       $v1, .L8006D400
    /* 9F14 8006D274 300002AE */   sw        $v0, 0x30($s0)
    /* 9F18 8006D278 21202002 */  addu       $a0, $s1, $zero
    /* 9F1C 8006D27C 00050324 */  addiu      $v1, $zero, 0x500
    /* 9F20 8006D280 2C0003AE */  sw         $v1, 0x2C($s0)
    /* 9F24 8006D284 C21F0200 */  srl        $v1, $v0, 31
    /* 9F28 8006D288 21104300 */  addu       $v0, $v0, $v1
    /* 9F2C 8006D28C 43100200 */  sra        $v0, $v0, 1
    /* 9F30 8006D290 E6B40108 */  j          .L8006D398
    /* 9F34 8006D294 23100200 */   negu      $v0, $v0
  .L8006D298:
    /* 9F38 8006D298 3000028E */  lw         $v0, 0x30($s0)
    /* 9F3C 8006D29C 2C00038E */  lw         $v1, 0x2C($s0)
    /* 9F40 8006D2A0 26004224 */  addiu      $v0, $v0, 0x26
    /* 9F44 8006D2A4 300002AE */  sw         $v0, 0x30($s0)
    /* 9F48 8006D2A8 21204000 */  addu       $a0, $v0, $zero
    /* 9F4C 8006D2AC 23186200 */  subu       $v1, $v1, $v0
    /* 9F50 8006D2B0 53008018 */  blez       $a0, .L8006D400
    /* 9F54 8006D2B4 2C0003AE */   sw        $v1, 0x2C($s0)
    /* 9F58 8006D2B8 F3B40108 */  j          .L8006D3CC
    /* 9F5C 8006D2BC 21202002 */   addu      $a0, $s1, $zero
  .L8006D2C0:
    /* 9F60 8006D2C0 62B9010C */  jal        func_8006E588
    /* 9F64 8006D2C4 21202002 */   addu      $a0, $s1, $zero
    /* 9F68 8006D2C8 4D005214 */  bne        $v0, $s2, .L8006D400
    /* 9F6C 8006D2CC 21202002 */   addu      $a0, $s1, $zero
    /* 9F70 8006D2D0 0000028E */  lw         $v0, 0x0($s0)
    /* 9F74 8006D2D4 01000524 */  addiu      $a1, $zero, 0x1
    /* 9F78 8006D2D8 00044234 */  ori        $v0, $v0, 0x400
    /* 9F7C 8006D2DC FEB40108 */  j          .L8006D3F8
    /* 9F80 8006D2E0 000002AE */   sw        $v0, 0x0($s0)
  jlabel .L8006D2E4
    /* 9F84 8006D2E4 21202002 */  addu       $a0, $s1, $zero
    /* 9F88 8006D2E8 0000028E */  lw         $v0, 0x0($s0)
    /* 9F8C 8006D2EC 01000524 */  addiu      $a1, $zero, 0x1
    /* 9F90 8006D2F0 00544234 */  ori        $v0, $v0, 0x5400
    /* 9F94 8006D2F4 FEB40108 */  j          .L8006D3F8
    /* 9F98 8006D2F8 000002AE */   sw        $v0, 0x0($s0)
  jlabel .L8006D2FC
    /* 9F9C 8006D2FC 1800238E */  lw         $v1, 0x18($s1)
    /* 9FA0 8006D300 01001224 */  addiu      $s2, $zero, 0x1
    /* 9FA4 8006D304 17007210 */  beq        $v1, $s2, .L8006D364
    /* 9FA8 8006D308 02006228 */   slti      $v0, $v1, 0x2
    /* 9FAC 8006D30C 06004014 */  bnez       $v0, .L8006D328
    /* 9FB0 8006D310 21202002 */   addu      $a0, $s1, $zero
    /* 9FB4 8006D314 02000224 */  addiu      $v0, $zero, 0x2
    /* 9FB8 8006D318 23006210 */  beq        $v1, $v0, .L8006D3A8
    /* 9FBC 8006D31C 03000224 */   addiu     $v0, $zero, 0x3
    /* 9FC0 8006D320 30006210 */  beq        $v1, $v0, .L8006D3E4
    /* 9FC4 8006D324 00000000 */   nop
  .L8006D328:
    /* 9FC8 8006D328 28000524 */  addiu      $a1, $zero, 0x28
    /* 9FCC 8006D32C 0000028E */  lw         $v0, 0x0($s0)
    /* 9FD0 8006D330 FFFB0324 */  addiu      $v1, $zero, -0x401
    /* 9FD4 8006D334 00504234 */  ori        $v0, $v0, 0x5000
    /* 9FD8 8006D338 24104300 */  and        $v0, $v0, $v1
    /* 9FDC 8006D33C 37B9010C */  jal        func_8006E4DC
    /* 9FE0 8006D340 000002AE */   sw        $v0, 0x0($s0)
    /* 9FE4 8006D344 05000424 */  addiu      $a0, $zero, 0x5
    /* 9FE8 8006D348 21280000 */  addu       $a1, $zero, $zero
    /* 9FEC 8006D34C 00280224 */  addiu      $v0, $zero, 0x2800
    /* 9FF0 8006D350 300000AE */  sw         $zero, 0x30($s0)
    /* 9FF4 8006D354 A369000C */  jal        Snd_PlayById
    /* 9FF8 8006D358 2C0002AE */   sw        $v0, 0x2C($s0)
    /* 9FFC 8006D35C F5B40108 */  j          .L8006D3D4
    /* A000 8006D360 00000000 */   nop
  .L8006D364:
    /* A004 8006D364 3000028E */  lw         $v0, 0x30($s0)
    /* A008 8006D368 2C00038E */  lw         $v1, 0x2C($s0)
    /* A00C 8006D36C 26004224 */  addiu      $v0, $v0, 0x26
    /* A010 8006D370 23186200 */  subu       $v1, $v1, $v0
    /* A014 8006D374 300002AE */  sw         $v0, 0x30($s0)
    /* A018 8006D378 21006104 */  bgez       $v1, .L8006D400
    /* A01C 8006D37C 2C0003AE */   sw        $v1, 0x2C($s0)
    /* A020 8006D380 21202002 */  addu       $a0, $s1, $zero
    /* A024 8006D384 C21F0200 */  srl        $v1, $v0, 31
    /* A028 8006D388 21104300 */  addu       $v0, $v0, $v1
    /* A02C 8006D38C 43100200 */  sra        $v0, $v0, 1
    /* A030 8006D390 23100200 */  negu       $v0, $v0
    /* A034 8006D394 2C0000AE */  sw         $zero, 0x2C($s0)
  .L8006D398:
    /* A038 8006D398 6045000C */  jal        Task_NextState2
    /* A03C 8006D39C 300002AE */   sw        $v0, 0x30($s0)
    /* A040 8006D3A0 00B50108 */  j          .L8006D400
    /* A044 8006D3A4 00000000 */   nop
  .L8006D3A8:
    /* A048 8006D3A8 3000028E */  lw         $v0, 0x30($s0)
    /* A04C 8006D3AC 2C00038E */  lw         $v1, 0x2C($s0)
    /* A050 8006D3B0 26004224 */  addiu      $v0, $v0, 0x26
    /* A054 8006D3B4 23186200 */  subu       $v1, $v1, $v0
    /* A058 8006D3B8 300002AE */  sw         $v0, 0x30($s0)
    /* A05C 8006D3BC 10006104 */  bgez       $v1, .L8006D400
    /* A060 8006D3C0 2C0003AE */   sw        $v1, 0x2C($s0)
    /* A064 8006D3C4 2C0000AE */  sw         $zero, 0x2C($s0)
    /* A068 8006D3C8 21202002 */  addu       $a0, $s1, $zero
  .L8006D3CC:
    /* A06C 8006D3CC 37B9010C */  jal        func_8006E4DC
    /* A070 8006D3D0 2B000524 */   addiu     $a1, $zero, 0x2B
  .L8006D3D4:
    /* A074 8006D3D4 6045000C */  jal        Task_NextState2
    /* A078 8006D3D8 21202002 */   addu      $a0, $s1, $zero
    /* A07C 8006D3DC 00B50108 */  j          .L8006D400
    /* A080 8006D3E0 00000000 */   nop
  .L8006D3E4:
    /* A084 8006D3E4 62B9010C */  jal        func_8006E588
    /* A088 8006D3E8 21202002 */   addu      $a0, $s1, $zero
    /* A08C 8006D3EC 04005214 */  bne        $v0, $s2, .L8006D400
    /* A090 8006D3F0 21202002 */   addu      $a0, $s1, $zero
    /* A094 8006D3F4 02000524 */  addiu      $a1, $zero, 0x2
  .L8006D3F8:
    /* A098 8006D3F8 7745000C */  jal        Task_SetState1
    /* A09C 8006D3FC 00000000 */   nop
  jlabel .L8006D400
    /* A0A0 8006D400 2400BF8F */  lw         $ra, 0x24($sp)
    /* A0A4 8006D404 2000B28F */  lw         $s2, 0x20($sp)
    /* A0A8 8006D408 1C00B18F */  lw         $s1, 0x1C($sp)
    /* A0AC 8006D40C 1800B08F */  lw         $s0, 0x18($sp)
    /* A0B0 8006D410 0800E003 */  jr         $ra
    /* A0B4 8006D414 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8006D0E8
