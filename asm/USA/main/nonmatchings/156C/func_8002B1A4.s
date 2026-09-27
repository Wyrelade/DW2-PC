nonmatching func_8002B1A4, 0x108

glabel func_8002B1A4
    /* 1B9A4 8002B1A4 0680023C */  lui        $v0, %hi(D_8006198E)
    /* 1B9A8 8002B1A8 8E194284 */  lh         $v0, %lo(D_8006198E)($v0)
    /* 1B9AC 8002B1AC E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1B9B0 8002B1B0 1800BFAF */  sw         $ra, 0x18($sp)
    /* 1B9B4 8002B1B4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1B9B8 8002B1B8 1C004010 */  beqz       $v0, .L8002B22C
    /* 1B9BC 8002B1BC 1000B0AF */   sw        $s0, 0x10($sp)
    /* 1B9C0 8002B1C0 0680063C */  lui        $a2, %hi(D_80061900)
    /* 1B9C4 8002B1C4 0019C624 */  addiu      $a2, $a2, %lo(D_80061900)
    /* 1B9C8 8002B1C8 0680033C */  lui        $v1, %hi(D_8006198C)
    /* 1B9CC 8002B1CC 8C196384 */  lh         $v1, %lo(D_8006198C)($v1)
    /* 1B9D0 8002B1D0 0000C294 */  lhu        $v0, 0x0($a2)
    /* 1B9D4 8002B1D4 40180300 */  sll        $v1, $v1, 1
    /* 1B9D8 8002B1D8 0680043C */  lui        $a0, %hi(D_800618F0)
    /* 1B9DC 8002B1DC 21208300 */  addu       $a0, $a0, $v1
    /* 1B9E0 8002B1E0 F0188494 */  lhu        $a0, %lo(D_800618F0)($a0)
    /* 1B9E4 8002B1E4 0680053C */  lui        $a1, %hi(D_80061910)
    /* 1B9E8 8002B1E8 1019A524 */  addiu      $a1, $a1, %lo(D_80061910)
    /* 1B9EC 8002B1EC 0680013C */  lui        $at, %hi(D_8006197E)
    /* 1B9F0 8002B1F0 7E1920A4 */  sh         $zero, %lo(D_8006197E)($at)
    /* 1B9F4 8002B1F4 0680013C */  lui        $at, %hi(D_8006197C)
    /* 1B9F8 8002B1F8 7C1920A4 */  sh         $zero, %lo(D_8006197C)($at)
    /* 1B9FC 8002B1FC 21104400 */  addu       $v0, $v0, $a0
    /* 1BA00 8002B200 0000A2A4 */  sh         $v0, 0x0($a1)
    /* 1BA04 8002B204 0200C294 */  lhu        $v0, 0x2($a2)
    /* 1BA08 8002B208 0680013C */  lui        $at, %hi(D_800618F4)
    /* 1BA0C 8002B20C 21082300 */  addu       $at, $at, $v1
    /* 1BA10 8002B210 F4182394 */  lhu        $v1, %lo(D_800618F4)($at)
    /* 1BA14 8002B214 F8FFA424 */  addiu      $a0, $a1, -0x8
    /* 1BA18 8002B218 21104300 */  addu       $v0, $v0, $v1
    /* 1BA1C 8002B21C B99E000C */  jal        func_80027AE4
    /* 1BA20 8002B220 0200A2A4 */   sh        $v0, 0x2($a1)
    /* 1BA24 8002B224 A6AC0008 */  j          .L8002B298
    /* 1BA28 8002B228 00000000 */   nop
  .L8002B22C:
    /* 1BA2C 8002B22C 0680023C */  lui        $v0, %hi(D_800618F0)
    /* 1BA30 8002B230 F0184224 */  addiu      $v0, $v0, %lo(D_800618F0)
    /* 1BA34 8002B234 0680103C */  lui        $s0, %hi(D_80061900)
    /* 1BA38 8002B238 00191026 */  addiu      $s0, $s0, %lo(D_80061900)
    /* 1BA3C 8002B23C 0680053C */  lui        $a1, %hi(D_8006198C)
    /* 1BA40 8002B240 8C19A584 */  lh         $a1, %lo(D_8006198C)($a1)
    /* 1BA44 8002B244 00000486 */  lh         $a0, 0x0($s0)
    /* 1BA48 8002B248 0200A014 */  bnez       $a1, .L8002B254
    /* 1BA4C 8002B24C 00000000 */   nop
    /* 1BA50 8002B250 02004224 */  addiu      $v0, $v0, 0x2
  .L8002B254:
    /* 1BA54 8002B254 00004284 */  lh         $v0, 0x0($v0)
    /* 1BA58 8002B258 0680033C */  lui        $v1, %hi(D_800618F4)
    /* 1BA5C 8002B25C F4186324 */  addiu      $v1, $v1, %lo(D_800618F4)
    /* 1BA60 8002B260 21888200 */  addu       $s1, $a0, $v0
    /* 1BA64 8002B264 02000286 */  lh         $v0, 0x2($s0)
    /* 1BA68 8002B268 0200A014 */  bnez       $a1, .L8002B274
    /* 1BA6C 8002B26C 00000000 */   nop
    /* 1BA70 8002B270 02006324 */  addiu      $v1, $v1, 0x2
  .L8002B274:
    /* 1BA74 8002B274 00007084 */  lh         $s0, 0x0($v1)
    /* 1BA78 8002B278 21202002 */  addu       $a0, $s1, $zero
    /* 1BA7C 8002B27C 21805000 */  addu       $s0, $v0, $s0
    /* 1BA80 8002B280 A9B5000C */  jal        SetGeomOffset
    /* 1BA84 8002B284 21280002 */   addu      $a1, $s0, $zero
    /* 1BA88 8002B288 0680013C */  lui        $at, %hi(D_8006197C)
    /* 1BA8C 8002B28C 7C1931A4 */  sh         $s1, %lo(D_8006197C)($at)
    /* 1BA90 8002B290 0680013C */  lui        $at, %hi(D_8006197E)
    /* 1BA94 8002B294 7E1930A4 */  sh         $s0, %lo(D_8006197E)($at)
  .L8002B298:
    /* 1BA98 8002B298 1800BF8F */  lw         $ra, 0x18($sp)
    /* 1BA9C 8002B29C 1400B18F */  lw         $s1, 0x14($sp)
    /* 1BAA0 8002B2A0 1000B08F */  lw         $s0, 0x10($sp)
    /* 1BAA4 8002B2A4 0800E003 */  jr         $ra
    /* 1BAA8 8002B2A8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8002B1A4
    /* 1BAAC 8002B2AC 00000000 */  nop
    /* 1BAB0 8002B2B0 00000000 */  nop
