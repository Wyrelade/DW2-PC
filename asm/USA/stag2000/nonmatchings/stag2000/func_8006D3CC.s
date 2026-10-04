nonmatching func_8006D3CC, 0xB8

glabel func_8006D3CC
    /* A06C 8006D3CC 21300000 */  addu       $a2, $zero, $zero
    /* A070 8006D3D0 2118C000 */  addu       $v1, $a2, $zero
    /* A074 8006D3D4 2C00878C */  lw         $a3, 0x2C($a0)
    /* A078 8006D3D8 0680023C */  lui        $v0, %hi(Save_GameState)
    /* A07C 8006D3DC 20E64524 */  addiu      $a1, $v0, %lo(Save_GameState)
    /* A080 8006D3E0 2120E000 */  addu       $a0, $a3, $zero
  .L8006D3E4:
    /* A084 8006D3E4 6600A294 */  lhu        $v0, 0x66($a1)
    /* A088 8006D3E8 00000000 */  nop
    /* A08C 8006D3EC 04004010 */  beqz       $v0, .L8006D400
    /* A090 8006D3F0 00000000 */   nop
    /* A094 8006D3F4 600082A4 */  sh         $v0, 0x60($a0)
    /* A098 8006D3F8 02008424 */  addiu      $a0, $a0, 0x2
    /* A09C 8006D3FC 0100C624 */  addiu      $a2, $a2, 0x1
  .L8006D400:
    /* A0A0 8006D400 01006324 */  addiu      $v1, $v1, 0x1
    /* A0A4 8006D404 30006228 */  slti       $v0, $v1, 0x30
    /* A0A8 8006D408 F6FF4014 */  bnez       $v0, .L8006D3E4
    /* A0AC 8006D40C 0200A524 */   addiu     $a1, $a1, 0x2
    /* A0B0 8006D410 01000324 */  addiu      $v1, $zero, 0x1
    /* A0B4 8006D414 0680023C */  lui        $v0, %hi(Save_GameState)
    /* A0B8 8006D418 20E64224 */  addiu      $v0, $v0, %lo(Save_GameState)
    /* A0BC 8006D41C 02004524 */  addiu      $a1, $v0, 0x2
    /* A0C0 8006D420 04106600 */  sllv       $v0, $a2, $v1
    /* A0C4 8006D424 21204700 */  addu       $a0, $v0, $a3
  .L8006D428:
    /* A0C8 8006D428 2C00A294 */  lhu        $v0, 0x2C($a1)
    /* A0CC 8006D42C 00000000 */  nop
    /* A0D0 8006D430 03004010 */  beqz       $v0, .L8006D440
    /* A0D4 8006D434 00000000 */   nop
    /* A0D8 8006D438 600082A4 */  sh         $v0, 0x60($a0)
    /* A0DC 8006D43C 02008424 */  addiu      $a0, $a0, 0x2
  .L8006D440:
    /* A0E0 8006D440 01006324 */  addiu      $v1, $v1, 0x1
    /* A0E4 8006D444 13006228 */  slti       $v0, $v1, 0x13
    /* A0E8 8006D448 F7FF4014 */  bnez       $v0, .L8006D428
    /* A0EC 8006D44C 0200A524 */   addiu     $a1, $a1, 0x2
    /* A0F0 8006D450 01000324 */  addiu      $v1, $zero, 0x1
    /* A0F4 8006D454 0680023C */  lui        $v0, %hi(Save_GameState)
    /* A0F8 8006D458 20E64524 */  addiu      $a1, $v0, %lo(Save_GameState)
    /* A0FC 8006D45C 0200A424 */  addiu      $a0, $a1, 0x2
  .L8006D460:
    /* A100 8006D460 2C0080A4 */  sh         $zero, 0x2C($a0)
    /* A104 8006D464 21106500 */  addu       $v0, $v1, $a1
    /* A108 8006D468 01006324 */  addiu      $v1, $v1, 0x1
    /* A10C 8006D46C 520040A0 */  sb         $zero, 0x52($v0)
    /* A110 8006D470 13006228 */  slti       $v0, $v1, 0x13
    /* A114 8006D474 FAFF4014 */  bnez       $v0, .L8006D460
    /* A118 8006D478 02008424 */   addiu     $a0, $a0, 0x2
    /* A11C 8006D47C 0800E003 */  jr         $ra
    /* A120 8006D480 00000000 */   nop
endlabel func_8006D3CC
