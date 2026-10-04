nonmatching Stg30_CalcCannonDamage, 0x1EC

glabel Stg30_CalcCannonDamage
    /* 9F8C 8006D2EC D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 9F90 8006D2F0 2400B5AF */  sw         $s5, 0x24($sp)
    /* 9F94 8006D2F4 21A88000 */  addu       $s5, $a0, $zero
    /* 9F98 8006D2F8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 9F9C 8006D2FC 2180A000 */  addu       $s0, $a1, $zero
    /* 9FA0 8006D300 21200002 */  addu       $a0, $s0, $zero
    /* 9FA4 8006D304 0100C624 */  addiu      $a2, $a2, 0x1
    /* 9FA8 8006D308 80100600 */  sll        $v0, $a2, 2
    /* 9FAC 8006D30C 21104600 */  addu       $v0, $v0, $a2
    /* 9FB0 8006D310 2800B6AF */  sw         $s6, 0x28($sp)
    /* 9FB4 8006D314 80B00200 */  sll        $s6, $v0, 2
    /* 9FB8 8006D318 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 9FBC 8006D31C 2000B4AF */  sw         $s4, 0x20($sp)
    /* 9FC0 8006D320 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 9FC4 8006D324 1800B2AF */  sw         $s2, 0x18($sp)
    /* 9FC8 8006D328 D97B000C */  jal        Skill_GetPower
    /* 9FCC 8006D32C 1400B1AF */   sw        $s1, 0x14($sp)
    /* 9FD0 8006D330 21884000 */  addu       $s1, $v0, $zero
    /* 9FD4 8006D334 E27B000C */  jal        Skill_GetSpecialty
    /* 9FD8 8006D338 21200002 */   addu      $a0, $s0, $zero
    /* 9FDC 8006D33C 0780103C */  lui        $s0, %hi(Stg30_Battle)
    /* 9FE0 8006D340 C03C1026 */  addiu      $s0, $s0, %lo(Stg30_Battle)
    /* 9FE4 8006D344 40181500 */  sll        $v1, $s5, 1
    /* 9FE8 8006D348 21187500 */  addu       $v1, $v1, $s5
    /* 9FEC 8006D34C C0180300 */  sll        $v1, $v1, 3
    /* 9FF0 8006D350 23187500 */  subu       $v1, $v1, $s5
    /* 9FF4 8006D354 80180300 */  sll        $v1, $v1, 2
    /* 9FF8 8006D358 21187000 */  addu       $v1, $v1, $s0
    /* 9FFC 8006D35C 19006490 */  lbu        $a0, 0x19($v1)
    /* A000 8006D360 36007284 */  lh         $s2, 0x36($v1)
    /* A004 8006D364 6076000C */  jal        Digi_GetSpecialty
    /* A008 8006D368 21A04000 */   addu      $s4, $v0, $zero
    /* A00C 8006D36C 21984000 */  addu       $s3, $v0, $zero
    /* A010 8006D370 00111500 */  sll        $v0, $s5, 4
    /* A014 8006D374 21105000 */  addu       $v0, $v0, $s0
    /* A018 8006D378 AC02438C */  lw         $v1, 0x2AC($v0)
    /* A01C 8006D37C 05000224 */  addiu      $v0, $zero, 0x5
    /* A020 8006D380 09006214 */  bne        $v1, $v0, .L8006D3A8
    /* A024 8006D384 21208002 */   addu      $a0, $s4, $zero
    /* A028 8006D388 40101200 */  sll        $v0, $s2, 1
    /* A02C 8006D38C 21105200 */  addu       $v0, $v0, $s2
    /* A030 8006D390 80110200 */  sll        $v0, $v0, 6
    /* A034 8006D394 04004104 */  bgez       $v0, .L8006D3A8
    /* A038 8006D398 C3910200 */   sra       $s2, $v0, 7
    /* A03C 8006D39C 7F004224 */  addiu      $v0, $v0, 0x7F
    /* A040 8006D3A0 C3910200 */  sra        $s2, $v0, 7
    /* A044 8006D3A4 21208002 */  addu       $a0, $s4, $zero
  .L8006D3A8:
    /* A048 8006D3A8 0CA8010C */  jal        Stg30_CompareSpecialty
    /* A04C 8006D3AC 21286002 */   addu      $a1, $s3, $zero
    /* A050 8006D3B0 21184000 */  addu       $v1, $v0, $zero
    /* A054 8006D3B4 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* A058 8006D3B8 08006210 */  beq        $v1, $v0, .L8006D3DC
    /* A05C 8006D3BC 01000224 */   addiu     $v0, $zero, 0x1
    /* A060 8006D3C0 0F006214 */  bne        $v1, $v0, .L8006D400
    /* A064 8006D3C4 C0101100 */   sll       $v0, $s1, 3
    /* A068 8006D3C8 21105100 */  addu       $v0, $v0, $s1
    /* A06C 8006D3CC 00190200 */  sll        $v1, $v0, 4
    /* A070 8006D3D0 21104300 */  addu       $v0, $v0, $v1
    /* A074 8006D3D4 FCB40108 */  j          .L8006D3F0
    /* A078 8006D3D8 21105100 */   addu      $v0, $v0, $s1
  .L8006D3DC:
    /* A07C 8006D3DC 40101100 */  sll        $v0, $s1, 1
    /* A080 8006D3E0 21105100 */  addu       $v0, $v0, $s1
    /* A084 8006D3E4 00190200 */  sll        $v1, $v0, 4
    /* A088 8006D3E8 21104300 */  addu       $v0, $v0, $v1
    /* A08C 8006D3EC 40100200 */  sll        $v0, $v0, 1
  .L8006D3F0:
    /* A090 8006D3F0 03004104 */  bgez       $v0, .L8006D400
    /* A094 8006D3F4 C3890200 */   sra       $s1, $v0, 7
    /* A098 8006D3F8 7F004224 */  addiu      $v0, $v0, 0x7F
    /* A09C 8006D3FC C3890200 */  sra        $s1, $v0, 7
  .L8006D400:
    /* A0A0 8006D400 46A8010C */  jal        Stg30_GetFloorSpecialty
    /* A0A4 8006D404 00000000 */   nop
    /* A0A8 8006D408 0B008216 */  bne        $s4, $v0, .L8006D438
    /* A0AC 8006D40C 05000224 */   addiu     $v0, $zero, 0x5
    /* A0B0 8006D410 C0101100 */  sll        $v0, $s1, 3
    /* A0B4 8006D414 21105100 */  addu       $v0, $v0, $s1
    /* A0B8 8006D418 00190200 */  sll        $v1, $v0, 4
    /* A0BC 8006D41C 21104300 */  addu       $v0, $v0, $v1
    /* A0C0 8006D420 21105100 */  addu       $v0, $v0, $s1
    /* A0C4 8006D424 03004104 */  bgez       $v0, .L8006D434
    /* A0C8 8006D428 C3890200 */   sra       $s1, $v0, 7
    /* A0CC 8006D42C 7F004224 */  addiu      $v0, $v0, 0x7F
    /* A0D0 8006D430 C3890200 */  sra        $s1, $v0, 7
  .L8006D434:
    /* A0D4 8006D434 05000224 */  addiu      $v0, $zero, 0x5
  .L8006D438:
    /* A0D8 8006D438 0F006212 */  beq        $s3, $v0, .L8006D478
    /* A0DC 8006D43C 1800D102 */   mult      $s6, $s1
    /* A0E0 8006D440 46A8010C */  jal        Stg30_GetFloorSpecialty
    /* A0E4 8006D444 00000000 */   nop
    /* A0E8 8006D448 0B006216 */  bne        $s3, $v0, .L8006D478
    /* A0EC 8006D44C 1800D102 */   mult      $s6, $s1
    /* A0F0 8006D450 C0101200 */  sll        $v0, $s2, 3
    /* A0F4 8006D454 21105200 */  addu       $v0, $v0, $s2
    /* A0F8 8006D458 00190200 */  sll        $v1, $v0, 4
    /* A0FC 8006D45C 21104300 */  addu       $v0, $v0, $v1
    /* A100 8006D460 21105200 */  addu       $v0, $v0, $s2
    /* A104 8006D464 03004104 */  bgez       $v0, .L8006D474
    /* A108 8006D468 C3910200 */   sra       $s2, $v0, 7
    /* A10C 8006D46C 7F004224 */  addiu      $v0, $v0, 0x7F
    /* A110 8006D470 C3910200 */  sra        $s2, $v0, 7
  .L8006D474:
    /* A114 8006D474 1800D102 */  mult       $s6, $s1
  .L8006D478:
    /* A118 8006D478 0780033C */  lui        $v1, %hi(Stg30_Battle)
    /* A11C 8006D47C C03C6324 */  addiu      $v1, $v1, %lo(Stg30_Battle)
    /* A120 8006D480 80101500 */  sll        $v0, $s5, 2
    /* A124 8006D484 21104300 */  addu       $v0, $v0, $v1
    /* A128 8006D488 1C03428C */  lw         $v0, 0x31C($v0)
    /* A12C 8006D48C 12400000 */  mflo       $t0
    /* A130 8006D490 40201200 */  sll        $a0, $s2, 1
    /* A134 8006D494 01004230 */  andi       $v0, $v0, 0x1
    /* A138 8006D498 1A000401 */  div        $zero, $t0, $a0
    /* A13C 8006D49C 12200000 */  mflo       $a0
    /* A140 8006D4A0 02004010 */  beqz       $v0, .L8006D4AC
    /* A144 8006D4A4 00000000 */   nop
    /* A148 8006D4A8 0A008424 */  addiu      $a0, $a0, 0xA
  .L8006D4AC:
    /* A14C 8006D4AC 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* A150 8006D4B0 2800B68F */  lw         $s6, 0x28($sp)
    /* A154 8006D4B4 2400B58F */  lw         $s5, 0x24($sp)
    /* A158 8006D4B8 2000B48F */  lw         $s4, 0x20($sp)
    /* A15C 8006D4BC 1C00B38F */  lw         $s3, 0x1C($sp)
    /* A160 8006D4C0 1800B28F */  lw         $s2, 0x18($sp)
    /* A164 8006D4C4 1400B18F */  lw         $s1, 0x14($sp)
    /* A168 8006D4C8 1000B08F */  lw         $s0, 0x10($sp)
    /* A16C 8006D4CC 21108000 */  addu       $v0, $a0, $zero
    /* A170 8006D4D0 0800E003 */  jr         $ra
    /* A174 8006D4D4 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel Stg30_CalcCannonDamage
