nonmatching func_8002B334, 0xE8

glabel func_8002B334
    /* 1BB34 8002B334 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1BB38 8002B338 0680023C */  lui        $v0, %hi(D_8006198E)
    /* 1BB3C 8002B33C 8E194284 */  lh         $v0, %lo(D_8006198E)($v0)
    /* 1BB40 8002B340 2130A000 */  addu       $a2, $a1, $zero
    /* 1BB44 8002B344 1800BFAF */  sw         $ra, 0x18($sp)
    /* 1BB48 8002B348 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1BB4C 8002B34C 19004010 */  beqz       $v0, .L8002B3B4
    /* 1BB50 8002B350 1000B0AF */   sw        $s0, 0x10($sp)
    /* 1BB54 8002B354 0680033C */  lui        $v1, %hi(D_8006198C)
    /* 1BB58 8002B358 8C196384 */  lh         $v1, %lo(D_8006198C)($v1)
    /* 1BB5C 8002B35C 00000000 */  nop
    /* 1BB60 8002B360 40180300 */  sll        $v1, $v1, 1
    /* 1BB64 8002B364 0680023C */  lui        $v0, %hi(D_800618F0)
    /* 1BB68 8002B368 21104300 */  addu       $v0, $v0, $v1
    /* 1BB6C 8002B36C F0184294 */  lhu        $v0, %lo(D_800618F0)($v0)
    /* 1BB70 8002B370 0680053C */  lui        $a1, %hi(D_80061910)
    /* 1BB74 8002B374 1019A524 */  addiu      $a1, $a1, %lo(D_80061910)
    /* 1BB78 8002B378 0680013C */  lui        $at, %hi(D_8006197E)
    /* 1BB7C 8002B37C 7E1920A4 */  sh         $zero, %lo(D_8006197E)($at)
    /* 1BB80 8002B380 0680013C */  lui        $at, %hi(D_8006197C)
    /* 1BB84 8002B384 7C1920A4 */  sh         $zero, %lo(D_8006197C)($at)
    /* 1BB88 8002B388 21104400 */  addu       $v0, $v0, $a0
    /* 1BB8C 8002B38C 0000A2A4 */  sh         $v0, 0x0($a1)
    /* 1BB90 8002B390 0680023C */  lui        $v0, %hi(D_800618F4)
    /* 1BB94 8002B394 21104300 */  addu       $v0, $v0, $v1
    /* 1BB98 8002B398 F4184294 */  lhu        $v0, %lo(D_800618F4)($v0)
    /* 1BB9C 8002B39C F8FFA424 */  addiu      $a0, $a1, -0x8
    /* 1BBA0 8002B3A0 21104600 */  addu       $v0, $v0, $a2
    /* 1BBA4 8002B3A4 B99E000C */  jal        func_80027AE4
    /* 1BBA8 8002B3A8 0200A2A4 */   sh        $v0, 0x2($a1)
    /* 1BBAC 8002B3AC 02AD0008 */  j          .L8002B408
    /* 1BBB0 8002B3B0 00000000 */   nop
  .L8002B3B4:
    /* 1BBB4 8002B3B4 0680053C */  lui        $a1, %hi(D_8006198C)
    /* 1BBB8 8002B3B8 8C19A584 */  lh         $a1, %lo(D_8006198C)($a1)
    /* 1BBBC 8002B3BC 0680023C */  lui        $v0, %hi(D_800618F0)
    /* 1BBC0 8002B3C0 0200A014 */  bnez       $a1, .L8002B3CC
    /* 1BBC4 8002B3C4 F0184224 */   addiu     $v0, $v0, %lo(D_800618F0)
    /* 1BBC8 8002B3C8 02004224 */  addiu      $v0, $v0, 0x2
  .L8002B3CC:
    /* 1BBCC 8002B3CC 00004284 */  lh         $v0, 0x0($v0)
    /* 1BBD0 8002B3D0 0680033C */  lui        $v1, %hi(D_800618F4)
    /* 1BBD4 8002B3D4 F4186324 */  addiu      $v1, $v1, %lo(D_800618F4)
    /* 1BBD8 8002B3D8 0200A014 */  bnez       $a1, .L8002B3E4
    /* 1BBDC 8002B3DC 21888200 */   addu      $s1, $a0, $v0
    /* 1BBE0 8002B3E0 02006324 */  addiu      $v1, $v1, 0x2
  .L8002B3E4:
    /* 1BBE4 8002B3E4 00007084 */  lh         $s0, 0x0($v1)
    /* 1BBE8 8002B3E8 21202002 */  addu       $a0, $s1, $zero
    /* 1BBEC 8002B3EC 2180D000 */  addu       $s0, $a2, $s0
    /* 1BBF0 8002B3F0 A9B5000C */  jal        SetGeomOffset
    /* 1BBF4 8002B3F4 21280002 */   addu      $a1, $s0, $zero
    /* 1BBF8 8002B3F8 0680013C */  lui        $at, %hi(D_8006197C)
    /* 1BBFC 8002B3FC 7C1931A4 */  sh         $s1, %lo(D_8006197C)($at)
    /* 1BC00 8002B400 0680013C */  lui        $at, %hi(D_8006197E)
    /* 1BC04 8002B404 7E1930A4 */  sh         $s0, %lo(D_8006197E)($at)
  .L8002B408:
    /* 1BC08 8002B408 1800BF8F */  lw         $ra, 0x18($sp)
    /* 1BC0C 8002B40C 1400B18F */  lw         $s1, 0x14($sp)
    /* 1BC10 8002B410 1000B08F */  lw         $s0, 0x10($sp)
    /* 1BC14 8002B414 0800E003 */  jr         $ra
    /* 1BC18 8002B418 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8002B334
    /* 1BC1C 8002B41C 00000000 */  nop
    /* 1BC20 8002B420 00000000 */  nop
