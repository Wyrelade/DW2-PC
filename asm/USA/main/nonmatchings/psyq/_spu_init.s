nonmatching _spu_init, 0x280

glabel _spu_init
    /* 2A9D4 8003A1D4 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2A9D8 8003A1D8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2A9DC 8003A1DC 21808000 */  addu       $s0, $a0, $zero
    /* 2A9E0 8003A1E0 0580043C */  lui        $a0, %hi(D_8004FE38)
    /* 2A9E4 8003A1E4 38FE848C */  lw         $a0, %lo(D_8004FE38)($a0)
    /* 2A9E8 8003A1E8 1800BFAF */  sw         $ra, 0x18($sp)
    /* 2A9EC 8003A1EC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2A9F0 8003A1F0 0000828C */  lw         $v0, 0x0($a0)
    /* 2A9F4 8003A1F4 0B00033C */  lui        $v1, (0xB0000 >> 16)
    /* 2A9F8 8003A1F8 25104300 */  or         $v0, $v0, $v1
    /* 2A9FC 8003A1FC 000082AC */  sw         $v0, 0x0($a0)
    /* 2AA00 8003A200 0580023C */  lui        $v0, %hi(D_8004FE28)
    /* 2AA04 8003A204 28FE428C */  lw         $v0, %lo(D_8004FE28)($v0)
    /* 2AA08 8003A208 0580013C */  lui        $at, %hi(D_8004FE44)
    /* 2AA0C 8003A20C 44FE20AC */  sw         $zero, %lo(D_8004FE44)($at)
    /* 2AA10 8003A210 0580013C */  lui        $at, %hi(D_8004FE48)
    /* 2AA14 8003A214 48FE20AC */  sw         $zero, %lo(D_8004FE48)($at)
    /* 2AA18 8003A218 0580013C */  lui        $at, %hi(D_8004FE40)
    /* 2AA1C 8003A21C 40FE20A4 */  sh         $zero, %lo(D_8004FE40)($at)
    /* 2AA20 8003A220 800140A4 */  sh         $zero, 0x180($v0)
    /* 2AA24 8003A224 820140A4 */  sh         $zero, 0x182($v0)
    /* 2AA28 8003A228 2BEB000C */  jal        _spu_Fw1ts
    /* 2AA2C 8003A22C AA0140A4 */   sh        $zero, 0x1AA($v0)
    /* 2AA30 8003A230 0580023C */  lui        $v0, %hi(D_8004FE28)
    /* 2AA34 8003A234 28FE428C */  lw         $v0, %lo(D_8004FE28)($v0)
    /* 2AA38 8003A238 00000000 */  nop
    /* 2AA3C 8003A23C 800140A4 */  sh         $zero, 0x180($v0)
    /* 2AA40 8003A240 820140A4 */  sh         $zero, 0x182($v0)
    /* 2AA44 8003A244 AE014294 */  lhu        $v0, 0x1AE($v0)
    /* 2AA48 8003A248 00000000 */  nop
    /* 2AA4C 8003A24C FF074230 */  andi       $v0, $v0, 0x7FF
    /* 2AA50 8003A250 14004010 */  beqz       $v0, .L8003A2A4
    /* 2AA54 8003A254 21180000 */   addu      $v1, $zero, $zero
    /* 2AA58 8003A258 01006324 */  addiu      $v1, $v1, 0x1
  .L8003A25C:
    /* 2AA5C 8003A25C 010F622C */  sltiu      $v0, $v1, 0xF01
    /* 2AA60 8003A260 08004014 */  bnez       $v0, .L8003A284
    /* 2AA64 8003A264 00000000 */   nop
    /* 2AA68 8003A268 0180043C */  lui        $a0, %hi(D_80010AA4)
    /* 2AA6C 8003A26C A40A8424 */  addiu      $a0, $a0, %lo(D_80010AA4)
    /* 2AA70 8003A270 0180053C */  lui        $a1, %hi(D_80010AB4)
    /* 2AA74 8003A274 05A8000C */  jal        printf
    /* 2AA78 8003A278 B40AA524 */   addiu     $a1, $a1, %lo(D_80010AB4)
    /* 2AA7C 8003A27C AAE80008 */  j          .L8003A2A8
    /* 2AA80 8003A280 21200000 */   addu      $a0, $zero, $zero
  .L8003A284:
    /* 2AA84 8003A284 0580023C */  lui        $v0, %hi(D_8004FE28)
    /* 2AA88 8003A288 28FE428C */  lw         $v0, %lo(D_8004FE28)($v0)
    /* 2AA8C 8003A28C 00000000 */  nop
    /* 2AA90 8003A290 AE014294 */  lhu        $v0, 0x1AE($v0)
    /* 2AA94 8003A294 00000000 */  nop
    /* 2AA98 8003A298 FF074230 */  andi       $v0, $v0, 0x7FF
    /* 2AA9C 8003A29C EFFF4014 */  bnez       $v0, .L8003A25C
    /* 2AAA0 8003A2A0 01006324 */   addiu     $v1, $v1, 0x1
  .L8003A2A4:
    /* 2AAA4 8003A2A4 21200000 */  addu       $a0, $zero, $zero
  .L8003A2A8:
    /* 2AAA8 8003A2A8 0680053C */  lui        $a1, %hi(D_80062EE8)
    /* 2AAAC 8003A2AC E82EA524 */  addiu      $a1, $a1, %lo(D_80062EE8)
    /* 2AAB0 8003A2B0 02000224 */  addiu      $v0, $zero, 0x2
    /* 2AAB4 8003A2B4 0580013C */  lui        $at, %hi(D_8004FE4C)
    /* 2AAB8 8003A2B8 4CFE22AC */  sw         $v0, %lo(D_8004FE4C)($at)
    /* 2AABC 8003A2BC 03000224 */  addiu      $v0, $zero, 0x3
    /* 2AAC0 8003A2C0 0580013C */  lui        $at, %hi(D_8004FE50)
    /* 2AAC4 8003A2C4 50FE22AC */  sw         $v0, %lo(D_8004FE50)($at)
    /* 2AAC8 8003A2C8 08000224 */  addiu      $v0, $zero, 0x8
    /* 2AACC 8003A2CC 0580013C */  lui        $at, %hi(D_8004FE54)
    /* 2AAD0 8003A2D0 54FE22AC */  sw         $v0, %lo(D_8004FE54)($at)
    /* 2AAD4 8003A2D4 07000224 */  addiu      $v0, $zero, 0x7
    /* 2AAD8 8003A2D8 0580013C */  lui        $at, %hi(D_8004FE58)
    /* 2AADC 8003A2DC 58FE22AC */  sw         $v0, %lo(D_8004FE58)($at)
    /* 2AAE0 8003A2E0 0580023C */  lui        $v0, %hi(D_8004FE28)
    /* 2AAE4 8003A2E4 28FE428C */  lw         $v0, %lo(D_8004FE28)($v0)
    /* 2AAE8 8003A2E8 04000324 */  addiu      $v1, $zero, 0x4
    /* 2AAEC 8003A2EC AC0143A4 */  sh         $v1, 0x1AC($v0)
    /* 2AAF0 8003A2F0 FFFF0334 */  ori        $v1, $zero, 0xFFFF
    /* 2AAF4 8003A2F4 840140A4 */  sh         $zero, 0x184($v0)
    /* 2AAF8 8003A2F8 860140A4 */  sh         $zero, 0x186($v0)
    /* 2AAFC 8003A2FC 8C0143A4 */  sh         $v1, 0x18C($v0)
    /* 2AB00 8003A300 8E0143A4 */  sh         $v1, 0x18E($v0)
    /* 2AB04 8003A304 980140A4 */  sh         $zero, 0x198($v0)
    /* 2AB08 8003A308 9A0140A4 */  sh         $zero, 0x19A($v0)
  .L8003A30C:
    /* 2AB0C 8003A30C 0000A0A4 */  sh         $zero, 0x0($a1)
    /* 2AB10 8003A310 01008424 */  addiu      $a0, $a0, 0x1
    /* 2AB14 8003A314 0A008228 */  slti       $v0, $a0, 0xA
    /* 2AB18 8003A318 FCFF4014 */  bnez       $v0, .L8003A30C
    /* 2AB1C 8003A31C 0200A524 */   addiu     $a1, $a1, 0x2
    /* 2AB20 8003A320 3C000016 */  bnez       $s0, .L8003A414
    /* 2AB24 8003A324 21100000 */   addu      $v0, $zero, $zero
    /* 2AB28 8003A328 0580043C */  lui        $a0, %hi(D_8004FE68)
    /* 2AB2C 8003A32C 68FE8424 */  addiu      $a0, $a0, %lo(D_8004FE68)
    /* 2AB30 8003A330 0580023C */  lui        $v0, %hi(D_8004FE28)
    /* 2AB34 8003A334 28FE428C */  lw         $v0, %lo(D_8004FE28)($v0)
    /* 2AB38 8003A338 00020324 */  addiu      $v1, $zero, 0x200
    /* 2AB3C 8003A33C 0580013C */  lui        $at, %hi(D_8004FE40)
    /* 2AB40 8003A340 40FE23A4 */  sh         $v1, %lo(D_8004FE40)($at)
    /* 2AB44 8003A344 900140A4 */  sh         $zero, 0x190($v0)
    /* 2AB48 8003A348 920140A4 */  sh         $zero, 0x192($v0)
    /* 2AB4C 8003A34C 940140A4 */  sh         $zero, 0x194($v0)
    /* 2AB50 8003A350 960140A4 */  sh         $zero, 0x196($v0)
    /* 2AB54 8003A354 B00140A4 */  sh         $zero, 0x1B0($v0)
    /* 2AB58 8003A358 B20140A4 */  sh         $zero, 0x1B2($v0)
    /* 2AB5C 8003A35C B40140A4 */  sh         $zero, 0x1B4($v0)
    /* 2AB60 8003A360 B60140A4 */  sh         $zero, 0x1B6($v0)
    /* 2AB64 8003A364 15E9000C */  jal        _spu_FwriteByIO
    /* 2AB68 8003A368 10000524 */   addiu     $a1, $zero, 0x10
    /* 2AB6C 8003A36C 21200000 */  addu       $a0, $zero, $zero
    /* 2AB70 8003A370 FF3F0624 */  addiu      $a2, $zero, 0x3FFF
    /* 2AB74 8003A374 00020524 */  addiu      $a1, $zero, 0x200
    /* 2AB78 8003A378 0580033C */  lui        $v1, %hi(D_8004FE28)
    /* 2AB7C 8003A37C 28FE638C */  lw         $v1, %lo(D_8004FE28)($v1)
    /* 2AB80 8003A380 00000000 */  nop
  .L8003A384:
    /* 2AB84 8003A384 000060A4 */  sh         $zero, 0x0($v1)
    /* 2AB88 8003A388 020060A4 */  sh         $zero, 0x2($v1)
    /* 2AB8C 8003A38C 040066A4 */  sh         $a2, 0x4($v1)
    /* 2AB90 8003A390 060065A4 */  sh         $a1, 0x6($v1)
    /* 2AB94 8003A394 080060A4 */  sh         $zero, 0x8($v1)
    /* 2AB98 8003A398 0A0060A4 */  sh         $zero, 0xA($v1)
    /* 2AB9C 8003A39C 01008424 */  addiu      $a0, $a0, 0x1
    /* 2ABA0 8003A3A0 18008228 */  slti       $v0, $a0, 0x18
    /* 2ABA4 8003A3A4 F7FF4014 */  bnez       $v0, .L8003A384
    /* 2ABA8 8003A3A8 10006324 */   addiu     $v1, $v1, 0x10
    /* 2ABAC 8003A3AC FFFF1134 */  ori        $s1, $zero, 0xFFFF
    /* 2ABB0 8003A3B0 0580023C */  lui        $v0, %hi(D_8004FE28)
    /* 2ABB4 8003A3B4 28FE428C */  lw         $v0, %lo(D_8004FE28)($v0)
    /* 2ABB8 8003A3B8 FF001024 */  addiu      $s0, $zero, 0xFF
    /* 2ABBC 8003A3BC 880151A4 */  sh         $s1, 0x188($v0)
    /* 2ABC0 8003A3C0 2BEB000C */  jal        _spu_Fw1ts
    /* 2ABC4 8003A3C4 8A0150A4 */   sh        $s0, 0x18A($v0)
    /* 2ABC8 8003A3C8 2BEB000C */  jal        _spu_Fw1ts
    /* 2ABCC 8003A3CC 00000000 */   nop
    /* 2ABD0 8003A3D0 2BEB000C */  jal        _spu_Fw1ts
    /* 2ABD4 8003A3D4 00000000 */   nop
    /* 2ABD8 8003A3D8 2BEB000C */  jal        _spu_Fw1ts
    /* 2ABDC 8003A3DC 00000000 */   nop
    /* 2ABE0 8003A3E0 0580023C */  lui        $v0, %hi(D_8004FE28)
    /* 2ABE4 8003A3E4 28FE428C */  lw         $v0, %lo(D_8004FE28)($v0)
    /* 2ABE8 8003A3E8 00000000 */  nop
    /* 2ABEC 8003A3EC 8C0151A4 */  sh         $s1, 0x18C($v0)
    /* 2ABF0 8003A3F0 2BEB000C */  jal        _spu_Fw1ts
    /* 2ABF4 8003A3F4 8E0150A4 */   sh        $s0, 0x18E($v0)
    /* 2ABF8 8003A3F8 2BEB000C */  jal        _spu_Fw1ts
    /* 2ABFC 8003A3FC 00000000 */   nop
    /* 2AC00 8003A400 2BEB000C */  jal        _spu_Fw1ts
    /* 2AC04 8003A404 00000000 */   nop
    /* 2AC08 8003A408 2BEB000C */  jal        _spu_Fw1ts
    /* 2AC0C 8003A40C 00000000 */   nop
    /* 2AC10 8003A410 21100000 */  addu       $v0, $zero, $zero
  .L8003A414:
    /* 2AC14 8003A414 0580043C */  lui        $a0, %hi(D_8004FE28)
    /* 2AC18 8003A418 28FE848C */  lw         $a0, %lo(D_8004FE28)($a0)
    /* 2AC1C 8003A41C 01000324 */  addiu      $v1, $zero, 0x1
    /* 2AC20 8003A420 0580013C */  lui        $at, %hi(Spu_InTransfer)
    /* 2AC24 8003A424 5CFE23AC */  sw         $v1, %lo(Spu_InTransfer)($at)
    /* 2AC28 8003A428 00C00334 */  ori        $v1, $zero, 0xC000
    /* 2AC2C 8003A42C AA0183A4 */  sh         $v1, 0x1AA($a0)
    /* 2AC30 8003A430 0580013C */  lui        $at, %hi(D_8004FE60)
    /* 2AC34 8003A434 60FE20AC */  sw         $zero, %lo(D_8004FE60)($at)
    /* 2AC38 8003A438 0580013C */  lui        $at, %hi(D_8004FE64)
    /* 2AC3C 8003A43C 64FE20AC */  sw         $zero, %lo(D_8004FE64)($at)
    /* 2AC40 8003A440 1800BF8F */  lw         $ra, 0x18($sp)
    /* 2AC44 8003A444 1400B18F */  lw         $s1, 0x14($sp)
    /* 2AC48 8003A448 1000B08F */  lw         $s0, 0x10($sp)
    /* 2AC4C 8003A44C 0800E003 */  jr         $ra
    /* 2AC50 8003A450 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _spu_init
