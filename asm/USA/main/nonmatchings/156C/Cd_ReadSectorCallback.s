nonmatching Cd_ReadSectorCallback, 0x8C

glabel Cd_ReadSectorCallback
    /* 1485C 8002405C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 14860 80024060 01000224 */  addiu      $v0, $zero, 0x1
    /* 14864 80024064 1400BFAF */  sw         $ra, 0x14($sp)
    /* 14868 80024068 13008214 */  bne        $a0, $v0, .L800240B8
    /* 1486C 8002406C 1000B0AF */   sw        $s0, 0x10($sp)
    /* 14870 80024070 FF8F000C */  jal        Cd_CheckNextSector
    /* 14874 80024074 00000000 */   nop
    /* 14878 80024078 10004014 */  bnez       $v0, .L800240BC
    /* 1487C 8002407C 0580033C */   lui       $v1, %hi(D_80048DBC)
    /* 14880 80024080 0580103C */  lui        $s0, %hi(D_80048DB8)
    /* 14884 80024084 B88D1026 */  addiu      $s0, $s0, %lo(D_80048DB8)
    /* 14888 80024088 0800048E */  lw         $a0, 0x8($s0)
    /* 1488C 8002408C 45C2000C */  jal        CdGetSector
    /* 14890 80024090 00020524 */   addiu     $a1, $zero, 0x200
    /* 14894 80024094 0800028E */  lw         $v0, 0x8($s0)
    /* 14898 80024098 0400038E */  lw         $v1, 0x4($s0)
    /* 1489C 8002409C 00084224 */  addiu      $v0, $v0, 0x800
    /* 148A0 800240A0 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 148A4 800240A4 080002AE */  sw         $v0, 0x8($s0)
    /* 148A8 800240A8 0B006014 */  bnez       $v1, .L800240D8
    /* 148AC 800240AC 040003AE */   sw        $v1, 0x4($s0)
    /* 148B0 800240B0 31900008 */  j          .L800240C4
    /* 148B4 800240B4 00000000 */   nop
  .L800240B8:
    /* 148B8 800240B8 0580033C */  lui        $v1, %hi(D_80048DBC)
  .L800240BC:
    /* 148BC 800240BC FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 148C0 800240C0 BC8D62AC */  sw         $v0, %lo(D_80048DBC)($v1)
  .L800240C4:
    /* 148C4 800240C4 4DC1000C */  jal        CdReadyCallback
    /* 148C8 800240C8 21200000 */   addu      $a0, $zero, $zero
    /* 148CC 800240CC 09000424 */  addiu      $a0, $zero, 0x9
    /* 148D0 800240D0 A4C1000C */  jal        func_80030690
    /* 148D4 800240D4 21280000 */   addu      $a1, $zero, $zero
  .L800240D8:
    /* 148D8 800240D8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 148DC 800240DC 1000B08F */  lw         $s0, 0x10($sp)
    /* 148E0 800240E0 0800E003 */  jr         $ra
    /* 148E4 800240E4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Cd_ReadSectorCallback
