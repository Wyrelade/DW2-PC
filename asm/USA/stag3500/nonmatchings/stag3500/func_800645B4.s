nonmatching func_800645B4, 0x84

glabel func_800645B4
    /* 1254 800645B4 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 1258 800645B8 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 125C 800645BC 21988000 */  addu       $s3, $a0, $zero
    /* 1260 800645C0 2000BFAF */  sw         $ra, 0x20($sp)
    /* 1264 800645C4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 1268 800645C8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 126C 800645CC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1270 800645D0 2C00728E */  lw         $s2, 0x2C($s3)
    /* 1274 800645D4 21800000 */  addu       $s0, $zero, $zero
    /* 1278 800645D8 21884002 */  addu       $s1, $s2, $zero
  .L800645DC:
    /* 127C 800645DC 5A98010C */  jal        func_80066168
    /* 1280 800645E0 21202002 */   addu      $a0, $s1, $zero
    /* 1284 800645E4 01001026 */  addiu      $s0, $s0, 0x1
    /* 1288 800645E8 0400022A */  slti       $v0, $s0, 0x4
    /* 128C 800645EC FBFF4014 */  bnez       $v0, .L800645DC
    /* 1290 800645F0 04003126 */   addiu     $s1, $s1, 0x4
    /* 1294 800645F4 21800000 */  addu       $s0, $zero, $zero
    /* 1298 800645F8 10001124 */  addiu      $s1, $zero, 0x10
  .L800645FC:
    /* 129C 800645FC C695010C */  jal        func_80065718
    /* 12A0 80064600 21205102 */   addu      $a0, $s2, $s1
    /* 12A4 80064604 01001026 */  addiu      $s0, $s0, 0x1
    /* 12A8 80064608 0700022A */  slti       $v0, $s0, 0x7
    /* 12AC 8006460C FBFF4014 */  bnez       $v0, .L800645FC
    /* 12B0 80064610 04003126 */   addiu     $s1, $s1, 0x4
    /* 12B4 80064614 5C44000C */  jal        Task_DefaultDestroy
    /* 12B8 80064618 21206002 */   addu      $a0, $s3, $zero
    /* 12BC 8006461C 2000BF8F */  lw         $ra, 0x20($sp)
    /* 12C0 80064620 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 12C4 80064624 1800B28F */  lw         $s2, 0x18($sp)
    /* 12C8 80064628 1400B18F */  lw         $s1, 0x14($sp)
    /* 12CC 8006462C 1000B08F */  lw         $s0, 0x10($sp)
    /* 12D0 80064630 0800E003 */  jr         $ra
    /* 12D4 80064634 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_800645B4
