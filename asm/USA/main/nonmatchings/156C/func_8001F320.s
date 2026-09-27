nonmatching func_8001F320, 0x2C8

glabel func_8001F320
    /* FB20 8001F320 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* FB24 8001F324 1400BFAF */  sw         $ra, 0x14($sp)
    /* FB28 8001F328 1000B0AF */  sw         $s0, 0x10($sp)
    /* FB2C 8001F32C 3C00908C */  lw         $s0, 0x3C($a0)
    /* FB30 8001F330 00000000 */  nop
    /* FB34 8001F334 4800048E */  lw         $a0, 0x48($s0)
    /* FB38 8001F338 828E000C */  jal        Cd_GetFileOrNull
    /* FB3C 8001F33C 00000000 */   nop
    /* FB40 8001F340 5000038E */  lw         $v1, 0x50($s0)
    /* FB44 8001F344 21284000 */  addu       $a1, $v0, $zero
    /* FB48 8001F348 0800A310 */  beq        $a1, $v1, .L8001F36C
    /* FB4C 8001F34C 0400A324 */   addiu     $v1, $a1, 0x4
    /* FB50 8001F350 0800028E */  lw         $v0, 0x8($s0)
    /* FB54 8001F354 500005AE */  sw         $a1, 0x50($s0)
    /* FB58 8001F358 680003AE */  sw         $v1, 0x68($s0)
    /* FB5C 8001F35C 01004224 */  addiu      $v0, $v0, 0x1
    /* FB60 8001F360 80100200 */  sll        $v0, $v0, 2
    /* FB64 8001F364 2110A200 */  addu       $v0, $a1, $v0
    /* FB68 8001F368 640002AE */  sw         $v0, 0x64($s0)
  .L8001F36C:
    /* FB6C 8001F36C 0000A28C */  lw         $v0, 0x0($a1)
    /* FB70 8001F370 00000000 */  nop
    /* FB74 8001F374 29004014 */  bnez       $v0, .L8001F41C
    /* FB78 8001F378 0680023C */   lui       $v0, %hi(D_8005F778)
    /* FB7C 8001F37C 01000324 */  addiu      $v1, $zero, 0x1
    /* FB80 8001F380 0000A3AC */  sw         $v1, 0x0($a1)
    /* FB84 8001F384 6400048E */  lw         $a0, 0x64($s0)
    /* FB88 8001F388 00000000 */  nop
    /* FB8C 8001F38C 0000828C */  lw         $v0, 0x0($a0)
    /* FB90 8001F390 00000000 */  nop
    /* FB94 8001F394 10004310 */  beq        $v0, $v1, .L8001F3D8
    /* FB98 8001F398 00000000 */   nop
    /* FB9C 8001F39C 21306000 */  addu       $a2, $v1, $zero
    /* FBA0 8001F3A0 21180000 */  addu       $v1, $zero, $zero
    /* FBA4 8001F3A4 21206400 */  addu       $a0, $v1, $a0
  .L8001F3A8:
    /* FBA8 8001F3A8 0000828C */  lw         $v0, 0x0($a0)
    /* FBAC 8001F3AC 00000000 */  nop
    /* FBB0 8001F3B0 02004010 */  beqz       $v0, .L8001F3BC
    /* FBB4 8001F3B4 21104500 */   addu      $v0, $v0, $a1
    /* FBB8 8001F3B8 000082AC */  sw         $v0, 0x0($a0)
  .L8001F3BC:
    /* FBBC 8001F3BC 6400048E */  lw         $a0, 0x64($s0)
    /* FBC0 8001F3C0 04006324 */  addiu      $v1, $v1, 0x4
    /* FBC4 8001F3C4 21106400 */  addu       $v0, $v1, $a0
    /* FBC8 8001F3C8 0000428C */  lw         $v0, 0x0($v0)
    /* FBCC 8001F3CC 00000000 */  nop
    /* FBD0 8001F3D0 F5FF4614 */  bne        $v0, $a2, .L8001F3A8
    /* FBD4 8001F3D4 21206400 */   addu      $a0, $v1, $a0
  .L8001F3D8:
    /* FBD8 8001F3D8 0800028E */  lw         $v0, 0x8($s0)
    /* FBDC 8001F3DC 00000000 */  nop
    /* FBE0 8001F3E0 0D004018 */  blez       $v0, .L8001F418
    /* FBE4 8001F3E4 21200000 */   addu      $a0, $zero, $zero
  .L8001F3E8:
    /* FBE8 8001F3E8 6800028E */  lw         $v0, 0x68($s0)
    /* FBEC 8001F3EC 80180400 */  sll        $v1, $a0, 2
    /* FBF0 8001F3F0 21186200 */  addu       $v1, $v1, $v0
    /* FBF4 8001F3F4 0000628C */  lw         $v0, 0x0($v1)
    /* FBF8 8001F3F8 00000000 */  nop
    /* FBFC 8001F3FC 21104500 */  addu       $v0, $v0, $a1
    /* FC00 8001F400 000062AC */  sw         $v0, 0x0($v1)
    /* FC04 8001F404 0800028E */  lw         $v0, 0x8($s0)
    /* FC08 8001F408 01008424 */  addiu      $a0, $a0, 0x1
    /* FC0C 8001F40C 2A108200 */  slt        $v0, $a0, $v0
    /* FC10 8001F410 F5FF4014 */  bnez       $v0, .L8001F3E8
    /* FC14 8001F414 00000000 */   nop
  .L8001F418:
    /* FC18 8001F418 0680023C */  lui        $v0, %hi(D_8005F778)
  .L8001F41C:
    /* FC1C 8001F41C 5C00038E */  lw         $v1, 0x5C($s0)
    /* FC20 8001F420 78F7428C */  lw         $v0, %lo(D_8005F778)($v0)
    /* FC24 8001F424 00000000 */  nop
    /* FC28 8001F428 21186200 */  addu       $v1, $v1, $v0
    /* FC2C 8001F42C 5C0003AE */  sw         $v1, 0x5C($s0)
    /* FC30 8001F430 02006328 */  slti       $v1, $v1, 0x2
    /* FC34 8001F434 37006014 */  bnez       $v1, .L8001F514
    /* FC38 8001F438 FF000924 */   addiu     $t1, $zero, 0xFF
    /* FC3C 8001F43C FE000A24 */  addiu      $t2, $zero, 0xFE
    /* FC40 8001F440 FFFF0824 */  addiu      $t0, $zero, -0x1
  .L8001F444:
    /* FC44 8001F444 5C00028E */  lw         $v0, 0x5C($s0)
    /* FC48 8001F448 7800058E */  lw         $a1, 0x78($s0)
    /* FC4C 8001F44C FEFF4224 */  addiu      $v0, $v0, -0x2
    /* FC50 8001F450 5C0002AE */  sw         $v0, 0x5C($s0)
    /* FC54 8001F454 4C00028E */  lw         $v0, 0x4C($s0)
    /* FC58 8001F458 6400038E */  lw         $v1, 0x64($s0)
    /* FC5C 8001F45C 80100200 */  sll        $v0, $v0, 2
    /* FC60 8001F460 21104300 */  addu       $v0, $v0, $v1
    /* FC64 8001F464 0000468C */  lw         $a2, 0x0($v0)
    /* FC68 8001F468 0800028E */  lw         $v0, 0x8($s0)
    /* FC6C 8001F46C 5800078E */  lw         $a3, 0x58($s0)
    /* FC70 8001F470 0C004018 */  blez       $v0, .L8001F4A4
    /* FC74 8001F474 21200000 */   addu      $a0, $zero, $zero
  .L8001F478:
    /* FC78 8001F478 5800038E */  lw         $v1, 0x58($s0)
    /* FC7C 8001F47C 01008424 */  addiu      $a0, $a0, 0x1
    /* FC80 8001F480 2110C300 */  addu       $v0, $a2, $v1
    /* FC84 8001F484 00004290 */  lbu        $v0, 0x0($v0)
    /* FC88 8001F488 01006324 */  addiu      $v1, $v1, 0x1
    /* FC8C 8001F48C 8000A2AC */  sw         $v0, 0x80($a1)
    /* FC90 8001F490 0800028E */  lw         $v0, 0x8($s0)
    /* FC94 8001F494 8400A524 */  addiu      $a1, $a1, 0x84
    /* FC98 8001F498 2A108200 */  slt        $v0, $a0, $v0
    /* FC9C 8001F49C F6FF4014 */  bnez       $v0, .L8001F478
    /* FCA0 8001F4A0 580003AE */   sw        $v1, 0x58($s0)
  .L8001F4A4:
    /* FCA4 8001F4A4 5800028E */  lw         $v0, 0x58($s0)
    /* FCA8 8001F4A8 00000000 */  nop
    /* FCAC 8001F4AC 2118C200 */  addu       $v1, $a2, $v0
    /* FCB0 8001F4B0 00006290 */  lbu        $v0, 0x0($v1)
    /* FCB4 8001F4B4 00000000 */  nop
    /* FCB8 8001F4B8 80004230 */  andi       $v0, $v0, 0x80
    /* FCBC 8001F4BC 10004010 */  beqz       $v0, .L8001F500
    /* FCC0 8001F4C0 00000000 */   nop
    /* FCC4 8001F4C4 00006290 */  lbu        $v0, 0x0($v1)
    /* FCC8 8001F4C8 00000000 */  nop
    /* FCCC 8001F4CC 06004A10 */  beq        $v0, $t2, .L8001F4E8
    /* FCD0 8001F4D0 00000000 */   nop
    /* FCD4 8001F4D4 0A004914 */  bne        $v0, $t1, .L8001F500
    /* FCD8 8001F4D8 00000000 */   nop
    /* FCDC 8001F4DC 600008AE */  sw         $t0, 0x60($s0)
    /* FCE0 8001F4E0 457D0008 */  j          .L8001F514
    /* FCE4 8001F4E4 580007AE */   sw        $a3, 0x58($s0)
  .L8001F4E8:
    /* FCE8 8001F4E8 02006290 */  lbu        $v0, 0x2($v1)
    /* FCEC 8001F4EC 01006390 */  lbu        $v1, 0x1($v1)
    /* FCF0 8001F4F0 600008AE */  sw         $t0, 0x60($s0)
    /* FCF4 8001F4F4 00120200 */  sll        $v0, $v0, 8
    /* FCF8 8001F4F8 25104300 */  or         $v0, $v0, $v1
    /* FCFC 8001F4FC 580002AE */  sw         $v0, 0x58($s0)
  .L8001F500:
    /* FD00 8001F500 5C00028E */  lw         $v0, 0x5C($s0)
    /* FD04 8001F504 00000000 */  nop
    /* FD08 8001F508 02004228 */  slti       $v0, $v0, 0x2
    /* FD0C 8001F50C CDFF4010 */  beqz       $v0, .L8001F444
    /* FD10 8001F510 00000000 */   nop
  .L8001F514:
    /* FD14 8001F514 0800028E */  lw         $v0, 0x8($s0)
    /* FD18 8001F518 7800098E */  lw         $t1, 0x78($s0)
    /* FD1C 8001F51C 2E004018 */  blez       $v0, .L8001F5D8
    /* FD20 8001F520 21400000 */   addu      $t0, $zero, $zero
    /* FD24 8001F524 60002725 */  addiu      $a3, $t1, 0x60
  .L8001F528:
    /* FD28 8001F528 21300000 */  addu       $a2, $zero, $zero
    /* FD2C 8001F52C 21282001 */  addu       $a1, $t1, $zero
    /* FD30 8001F530 80180800 */  sll        $v1, $t0, 2
    /* FD34 8001F534 6800028E */  lw         $v0, 0x68($s0)
    /* FD38 8001F538 2000E48C */  lw         $a0, 0x20($a3)
    /* FD3C 8001F53C 21186200 */  addu       $v1, $v1, $v0
    /* FD40 8001F540 40100400 */  sll        $v0, $a0, 1
    /* FD44 8001F544 21104400 */  addu       $v0, $v0, $a0
    /* FD48 8001F548 0000638C */  lw         $v1, 0x0($v1)
    /* FD4C 8001F54C C0100200 */  sll        $v0, $v0, 3
    /* FD50 8001F550 21186200 */  addu       $v1, $v1, $v0
    /* FD54 8001F554 03006B88 */  lwl        $t3, 0x3($v1)
    /* FD58 8001F558 00006B98 */  lwr        $t3, 0x0($v1)
    /* FD5C 8001F55C 07006C88 */  lwl        $t4, 0x7($v1)
    /* FD60 8001F560 04006C98 */  lwr        $t4, 0x4($v1)
    /* FD64 8001F564 0B006D88 */  lwl        $t5, 0xB($v1)
    /* FD68 8001F568 08006D98 */  lwr        $t5, 0x8($v1)
    /* FD6C 8001F56C 0F006E88 */  lwl        $t6, 0xF($v1)
    /* FD70 8001F570 0C006E98 */  lwr        $t6, 0xC($v1)
    /* FD74 8001F574 0300EBA8 */  swl        $t3, 0x3($a3)
    /* FD78 8001F578 0000EBB8 */  swr        $t3, 0x0($a3)
    /* FD7C 8001F57C 0700ECA8 */  swl        $t4, 0x7($a3)
    /* FD80 8001F580 0400ECB8 */  swr        $t4, 0x4($a3)
    /* FD84 8001F584 0B00EDA8 */  swl        $t5, 0xB($a3)
    /* FD88 8001F588 0800EDB8 */  swr        $t5, 0x8($a3)
    /* FD8C 8001F58C 0F00EEA8 */  swl        $t6, 0xF($a3)
    /* FD90 8001F590 0C00EEB8 */  swr        $t6, 0xC($a3)
    /* FD94 8001F594 10006B84 */  lh         $t3, 0x10($v1)
    /* FD98 8001F598 00000000 */  nop
    /* FD9C 8001F59C 1000EBA4 */  sh         $t3, 0x10($a3)
  .L8001F5A0:
    /* FDA0 8001F5A0 12006284 */  lh         $v0, 0x12($v1)
    /* FDA4 8001F5A4 02006324 */  addiu      $v1, $v1, 0x2
    /* FDA8 8001F5A8 0100C624 */  addiu      $a2, $a2, 0x1
    /* FDAC 8001F5AC 7400A2AC */  sw         $v0, 0x74($a1)
    /* FDB0 8001F5B0 0300C228 */  slti       $v0, $a2, 0x3
    /* FDB4 8001F5B4 FAFF4014 */  bnez       $v0, .L8001F5A0
    /* FDB8 8001F5B8 0400A524 */   addiu     $a1, $a1, 0x4
    /* FDBC 8001F5BC 01000825 */  addiu      $t0, $t0, 0x1
    /* FDC0 8001F5C0 8400E724 */  addiu      $a3, $a3, 0x84
    /* FDC4 8001F5C4 0800028E */  lw         $v0, 0x8($s0)
    /* FDC8 8001F5C8 00000000 */  nop
    /* FDCC 8001F5CC 2A100201 */  slt        $v0, $t0, $v0
    /* FDD0 8001F5D0 D5FF4014 */  bnez       $v0, .L8001F528
    /* FDD4 8001F5D4 84002925 */   addiu     $t1, $t1, 0x84
  .L8001F5D8:
    /* FDD8 8001F5D8 1400BF8F */  lw         $ra, 0x14($sp)
    /* FDDC 8001F5DC 1000B08F */  lw         $s0, 0x10($sp)
    /* FDE0 8001F5E0 0800E003 */  jr         $ra
    /* FDE4 8001F5E4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001F320
