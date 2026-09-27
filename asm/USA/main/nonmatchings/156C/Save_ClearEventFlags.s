nonmatching Save_ClearEventFlags, 0x8C

glabel Save_ClearEventFlags
    /* 125C8 80021DC8 1F000324 */  addiu      $v1, $zero, 0x1F
    /* 125CC 80021DCC 0680023C */  lui        $v0, %hi(D_8005E620)
    /* 125D0 80021DD0 20E64224 */  addiu      $v0, $v0, %lo(D_8005E620)
    /* 125D4 80021DD4 21104300 */  addu       $v0, $v0, $v1
  .L80021DD8:
    /* 125D8 80021DD8 041040A0 */  sb         $zero, 0x1004($v0)
    /* 125DC 80021DDC FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 125E0 80021DE0 FDFF6104 */  bgez       $v1, .L80021DD8
    /* 125E4 80021DE4 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 125E8 80021DE8 07000324 */  addiu      $v1, $zero, 0x7
    /* 125EC 80021DEC 0680023C */  lui        $v0, %hi(D_8005E620)
    /* 125F0 80021DF0 20E64224 */  addiu      $v0, $v0, %lo(D_8005E620)
    /* 125F4 80021DF4 21104300 */  addu       $v0, $v0, $v1
  .L80021DF8:
    /* 125F8 80021DF8 241040A0 */  sb         $zero, 0x1024($v0)
    /* 125FC 80021DFC FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 12600 80021E00 FDFF6104 */  bgez       $v1, .L80021DF8
    /* 12604 80021E04 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 12608 80021E08 07000324 */  addiu      $v1, $zero, 0x7
    /* 1260C 80021E0C 0680023C */  lui        $v0, %hi(D_8005E620)
    /* 12610 80021E10 20E64224 */  addiu      $v0, $v0, %lo(D_8005E620)
    /* 12614 80021E14 21104300 */  addu       $v0, $v0, $v1
  .L80021E18:
    /* 12618 80021E18 2C1040A0 */  sb         $zero, 0x102C($v0)
    /* 1261C 80021E1C FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 12620 80021E20 FDFF6104 */  bgez       $v1, .L80021E18
    /* 12624 80021E24 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 12628 80021E28 0F000324 */  addiu      $v1, $zero, 0xF
    /* 1262C 80021E2C 0680023C */  lui        $v0, %hi(D_8005E620)
    /* 12630 80021E30 20E64224 */  addiu      $v0, $v0, %lo(D_8005E620)
    /* 12634 80021E34 21104300 */  addu       $v0, $v0, $v1
  .L80021E38:
    /* 12638 80021E38 341040A0 */  sb         $zero, 0x1034($v0)
    /* 1263C 80021E3C FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 12640 80021E40 FDFF6104 */  bgez       $v1, .L80021E38
    /* 12644 80021E44 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 12648 80021E48 0680023C */  lui        $v0, %hi(D_8005F664)
    /* 1264C 80021E4C 0800E003 */  jr         $ra
    /* 12650 80021E50 64F640AC */   sw        $zero, %lo(D_8005F664)($v0)
endlabel Save_ClearEventFlags
