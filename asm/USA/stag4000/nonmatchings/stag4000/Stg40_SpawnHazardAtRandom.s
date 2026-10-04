nonmatching Stg40_SpawnHazardAtRandom, 0x80

glabel Stg40_SpawnHazardAtRandom
    /* AC44 8006DFA4 0780023C */  lui        $v0, %hi(D_80072B60)
    /* AC48 8006DFA8 602B428C */  lw         $v0, %lo(D_80072B60)($v0)
    /* AC4C 8006DFAC E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* AC50 8006DFB0 1000B0AF */  sw         $s0, 0x10($sp)
    /* AC54 8006DFB4 21808000 */  addu       $s0, $a0, $zero
    /* AC58 8006DFB8 1400B1AF */  sw         $s1, 0x14($sp)
    /* AC5C 8006DFBC 2188A000 */  addu       $s1, $a1, $zero
    /* AC60 8006DFC0 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* AC64 8006DFC4 1800B2AF */  sw         $s2, 0x18($sp)
    /* AC68 8006DFC8 0000448C */  lw         $a0, 0x0($v0)
    /* AC6C 8006DFCC 71C4010C */  jal        Stg40_RandInt
    /* AC70 8006DFD0 2190C000 */   addu      $s2, $a2, $zero
    /* AC74 8006DFD4 21200002 */  addu       $a0, $s0, $zero
    /* AC78 8006DFD8 BCB7010C */  jal        Stg40_GetRegionCells
    /* AC7C 8006DFDC 21284000 */   addu      $a1, $v0, $zero
    /* AC80 8006DFE0 0A004010 */  beqz       $v0, .L8006E00C
    /* AC84 8006DFE4 00000000 */   nop
    /* AC88 8006DFE8 71C4010C */  jal        Stg40_RandInt
    /* AC8C 8006DFEC 21204000 */   addu      $a0, $v0, $zero
    /* AC90 8006DFF0 21202002 */  addu       $a0, $s1, $zero
    /* AC94 8006DFF4 40100200 */  sll        $v0, $v0, 1
    /* AC98 8006DFF8 21105000 */  addu       $v0, $v0, $s0
    /* AC9C 8006DFFC 00004690 */  lbu        $a2, 0x0($v0)
    /* ACA0 8006E000 01004790 */  lbu        $a3, 0x1($v0)
    /* ACA4 8006E004 DAB6010C */  jal        Stg40_SpawnHazard
    /* ACA8 8006E008 21284002 */   addu      $a1, $s2, $zero
  .L8006E00C:
    /* ACAC 8006E00C 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* ACB0 8006E010 1800B28F */  lw         $s2, 0x18($sp)
    /* ACB4 8006E014 1400B18F */  lw         $s1, 0x14($sp)
    /* ACB8 8006E018 1000B08F */  lw         $s0, 0x10($sp)
    /* ACBC 8006E01C 0800E003 */  jr         $ra
    /* ACC0 8006E020 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg40_SpawnHazardAtRandom
