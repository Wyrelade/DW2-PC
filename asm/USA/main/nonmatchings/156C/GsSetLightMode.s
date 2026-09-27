nonmatching GsSetLightMode, 0x7C

glabel GsSetLightMode
    /* 1C2D4 8002BAD4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1C2D8 8002BAD8 21288000 */  addu       $a1, $a0, $zero
    /* 1C2DC 8002BADC 01000224 */  addiu      $v0, $zero, 0x1
    /* 1C2E0 8002BAE0 1100A210 */  beq        $a1, $v0, .L8002BB28
    /* 1C2E4 8002BAE4 1000BFAF */   sw        $ra, 0x10($sp)
    /* 1C2E8 8002BAE8 0200A228 */  slti       $v0, $a1, 0x2
    /* 1C2EC 8002BAEC 05004010 */  beqz       $v0, .L8002BB04
    /* 1C2F0 8002BAF0 02000224 */   addiu     $v0, $zero, 0x2
    /* 1C2F4 8002BAF4 0900A010 */  beqz       $a1, .L8002BB1C
    /* 1C2F8 8002BAF8 00000000 */   nop
    /* 1C2FC 8002BAFC CDAE0008 */  j          .L8002BB34
    /* 1C300 8002BB00 00000000 */   nop
  .L8002BB04:
    /* 1C304 8002BB04 0800A210 */  beq        $a1, $v0, .L8002BB28
    /* 1C308 8002BB08 03000224 */   addiu     $v0, $zero, 0x3
    /* 1C30C 8002BB0C 0600A210 */  beq        $a1, $v0, .L8002BB28
    /* 1C310 8002BB10 00000000 */   nop
    /* 1C314 8002BB14 CDAE0008 */  j          .L8002BB34
    /* 1C318 8002BB18 00000000 */   nop
  .L8002BB1C:
    /* 1C31C 8002BB1C 0680013C */  lui        $at, %hi(D_8006199C)
    /* 1C320 8002BB20 D0AE0008 */  j          .L8002BB40
    /* 1C324 8002BB24 9C1920AC */   sw        $zero, %lo(D_8006199C)($at)
  .L8002BB28:
    /* 1C328 8002BB28 0680013C */  lui        $at, %hi(D_8006199C)
    /* 1C32C 8002BB2C D0AE0008 */  j          .L8002BB40
    /* 1C330 8002BB30 9C1925AC */   sw        $a1, %lo(D_8006199C)($at)
  .L8002BB34:
    /* 1C334 8002BB34 0180043C */  lui        $a0, %hi(D_80010624)
    /* 1C338 8002BB38 05A8000C */  jal        printf
    /* 1C33C 8002BB3C 24068424 */   addiu     $a0, $a0, %lo(D_80010624)
  .L8002BB40:
    /* 1C340 8002BB40 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1C344 8002BB44 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 1C348 8002BB48 0800E003 */  jr         $ra
    /* 1C34C 8002BB4C 00000000 */   nop
endlabel GsSetLightMode
    /* 1C350 8002BB50 00000000 */  nop
