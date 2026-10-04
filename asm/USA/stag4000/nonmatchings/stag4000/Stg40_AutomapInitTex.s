nonmatching Stg40_AutomapInitTex, 0xFC

glabel Stg40_AutomapInitTex
    /* BF30 8006F290 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* BF34 8006F294 1400B1AF */  sw         $s1, 0x14($sp)
    /* BF38 8006F298 21888000 */  addu       $s1, $a0, $zero
    /* BF3C 8006F29C 1800BFAF */  sw         $ra, 0x18($sp)
    /* BF40 8006F2A0 6A73000C */  jal        Gfx_ReserveTexSlot
    /* BF44 8006F2A4 1000B0AF */   sw        $s0, 0x10($sp)
    /* BF48 8006F2A8 48072626 */  addiu      $a2, $s1, 0x748
    /* BF4C 8006F2AC 21202002 */  addu       $a0, $s1, $zero
    /* BF50 8006F2B0 0780033C */  lui        $v1, %hi(Stg40_AutomapClut)
    /* BF54 8006F2B4 48296724 */  addiu      $a3, $v1, %lo(Stg40_AutomapClut)
    /* BF58 8006F2B8 21804000 */  addu       $s0, $v0, $zero
    /* BF5C 8006F2BC 580722AE */  sw         $v0, 0x758($s1)
    /* BF60 8006F2C0 18000296 */  lhu        $v0, 0x18($s0)
    /* BF64 8006F2C4 21280000 */  addu       $a1, $zero, $zero
    /* BF68 8006F2C8 480722A6 */  sh         $v0, 0x748($s1)
    /* BF6C 8006F2CC 1C000396 */  lhu        $v1, 0x1C($s0)
    /* BF70 8006F2D0 10000224 */  addiu      $v0, $zero, 0x10
    /* BF74 8006F2D4 0400C2A4 */  sh         $v0, 0x4($a2)
    /* BF78 8006F2D8 02000224 */  addiu      $v0, $zero, 0x2
    /* BF7C 8006F2DC 0600C2A4 */  sh         $v0, 0x6($a2)
    /* BF80 8006F2E0 FE006324 */  addiu      $v1, $v1, 0xFE
    /* BF84 8006F2E4 0200C3A4 */  sh         $v1, 0x2($a2)
  .L8006F2E8:
    /* BF88 8006F2E8 0000E294 */  lhu        $v0, 0x0($a3)
    /* BF8C 8006F2EC 0200E724 */  addiu      $a3, $a3, 0x2
    /* BF90 8006F2F0 0100A524 */  addiu      $a1, $a1, 0x1
    /* BF94 8006F2F4 000082A4 */  sh         $v0, 0x0($a0)
    /* BF98 8006F2F8 2000A228 */  slti       $v0, $a1, 0x20
    /* BF9C 8006F2FC FAFF4014 */  bnez       $v0, .L8006F2E8
    /* BFA0 8006F300 02008424 */   addiu     $a0, $a0, 0x2
    /* BFA4 8006F304 5ABC010C */  jal        Stg40_AutomapLoadClut
    /* BFA8 8006F308 21202002 */   addu      $a0, $s1, $zero
    /* BFAC 8006F30C 50072626 */  addiu      $a2, $s1, 0x750
    /* BFB0 8006F310 84030724 */  addiu      $a3, $zero, 0x384
    /* BFB4 8006F314 40002426 */  addiu      $a0, $s1, 0x40
    /* BFB8 8006F318 18000296 */  lhu        $v0, 0x18($s0)
    /* BFBC 8006F31C 21280000 */  addu       $a1, $zero, $zero
    /* BFC0 8006F320 500722A6 */  sh         $v0, 0x750($s1)
    /* BFC4 8006F324 1C000396 */  lhu        $v1, 0x1C($s0)
    /* BFC8 8006F328 12000224 */  addiu      $v0, $zero, 0x12
    /* BFCC 8006F32C 0400C2A4 */  sh         $v0, 0x4($a2)
    /* BFD0 8006F330 32000224 */  addiu      $v0, $zero, 0x32
    /* BFD4 8006F334 0600C2A4 */  sh         $v0, 0x6($a2)
    /* BFD8 8006F338 0200C3A4 */  sh         $v1, 0x2($a2)
  .L8006F33C:
    /* BFDC 8006F33C 000080A4 */  sh         $zero, 0x0($a0)
    /* BFE0 8006F340 0100A524 */  addiu      $a1, $a1, 0x1
    /* BFE4 8006F344 2A10A700 */  slt        $v0, $a1, $a3
    /* BFE8 8006F348 FCFF4014 */  bnez       $v0, .L8006F33C
    /* BFEC 8006F34C 02008424 */   addiu     $a0, $a0, 0x2
    /* BFF0 8006F350 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* BFF4 8006F354 600722A6 */  sh         $v0, 0x760($s1)
    /* BFF8 8006F358 63BC010C */  jal        Stg40_AutomapFlush
    /* BFFC 8006F35C 21202002 */   addu      $a0, $s1, $zero
    /* C000 8006F360 01000224 */  addiu      $v0, $zero, 0x1
    /* C004 8006F364 02002426 */  addiu      $a0, $s1, 0x2
  .L8006F368:
    /* C008 8006F368 620780A4 */  sh         $zero, 0x762($a0)
    /* C00C 8006F36C FFFF4224 */  addiu      $v0, $v0, -0x1
    /* C010 8006F370 FDFF4104 */  bgez       $v0, .L8006F368
    /* C014 8006F374 FEFF8424 */   addiu     $a0, $a0, -0x2
    /* C018 8006F378 1800BF8F */  lw         $ra, 0x18($sp)
    /* C01C 8006F37C 1400B18F */  lw         $s1, 0x14($sp)
    /* C020 8006F380 1000B08F */  lw         $s0, 0x10($sp)
    /* C024 8006F384 0800E003 */  jr         $ra
    /* C028 8006F388 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg40_AutomapInitTex
