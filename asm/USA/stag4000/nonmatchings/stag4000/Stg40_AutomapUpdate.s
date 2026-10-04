nonmatching Stg40_AutomapUpdate, 0xA8

glabel Stg40_AutomapUpdate
    /* CA54 8006FDB4 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* CA58 8006FDB8 1400B1AF */  sw         $s1, 0x14($sp)
    /* CA5C 8006FDBC 21888000 */  addu       $s1, $a0, $zero
    /* CA60 8006FDC0 01000224 */  addiu      $v0, $zero, 0x1
    /* CA64 8006FDC4 1800BFAF */  sw         $ra, 0x18($sp)
    /* CA68 8006FDC8 1000B0AF */  sw         $s0, 0x10($sp)
    /* CA6C 8006FDCC 1000238E */  lw         $v1, 0x10($s1)
    /* CA70 8006FDD0 2C00308E */  lw         $s0, 0x2C($s1)
    /* CA74 8006FDD4 16006210 */  beq        $v1, $v0, .L8006FE30
    /* CA78 8006FDD8 02006228 */   slti      $v0, $v1, 0x2
    /* CA7C 8006FDDC 03004014 */  bnez       $v0, .L8006FDEC
    /* CA80 8006FDE0 02000224 */   addiu     $v0, $zero, 0x2
    /* CA84 8006FDE4 18006210 */  beq        $v1, $v0, .L8006FE48
    /* CA88 8006FDE8 00000000 */   nop
  .L8006FDEC:
    /* CA8C 8006FDEC 21200002 */  addu       $a0, $s0, $zero
    /* CA90 8006FDF0 0780023C */  lui        $v0, %hi(Stg40_AutomapWork)
    /* CA94 8006FDF4 ECBC010C */  jal        Stg40_AutomapInitDims
    /* CA98 8006FDF8 B02B50AC */   sw        $s0, %lo(Stg40_AutomapWork)($v0)
    /* CA9C 8006FDFC A4BC010C */  jal        Stg40_AutomapInitTex
    /* CAA0 8006FE00 21200002 */   addu      $a0, $s0, $zero
    /* CAA4 8006FE04 34BB010C */  jal        Stg40_AutomapRedraw
    /* CAA8 8006FE08 21200002 */   addu      $a0, $s0, $zero
    /* CAAC 8006FE0C 63BC010C */  jal        Stg40_AutomapFlush
    /* CAB0 8006FE10 21200002 */   addu      $a0, $s0, $zero
    /* CAB4 8006FE14 0780023C */  lui        $v0, %hi(Stg40_RootState)
    /* CAB8 8006FE18 602B428C */  lw         $v0, %lo(Stg40_RootState)($v0)
    /* CABC 8006FE1C 21202002 */  addu       $a0, $s1, $zero
    /* CAC0 8006FE20 5145000C */  jal        Task_NextState0
    /* CAC4 8006FE24 7E0040A4 */   sh        $zero, 0x7E($v0)
    /* CAC8 8006FE28 92BF0108 */  j          .L8006FE48
    /* CACC 8006FE2C 00000000 */   nop
  .L8006FE30:
    /* CAD0 8006FE30 AFBD010C */  jal        Stg40_AutomapRevealAround
    /* CAD4 8006FE34 21200002 */   addu      $a0, $s0, $zero
    /* CAD8 8006FE38 63BC010C */  jal        Stg40_AutomapFlush
    /* CADC 8006FE3C 21200002 */   addu      $a0, $s0, $zero
    /* CAE0 8006FE40 72BC010C */  jal        Stg40_AutomapCycleClut
    /* CAE4 8006FE44 21200002 */   addu      $a0, $s0, $zero
  .L8006FE48:
    /* CAE8 8006FE48 1800BF8F */  lw         $ra, 0x18($sp)
    /* CAEC 8006FE4C 1400B18F */  lw         $s1, 0x14($sp)
    /* CAF0 8006FE50 1000B08F */  lw         $s0, 0x10($sp)
    /* CAF4 8006FE54 0800E003 */  jr         $ra
    /* CAF8 8006FE58 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg40_AutomapUpdate
