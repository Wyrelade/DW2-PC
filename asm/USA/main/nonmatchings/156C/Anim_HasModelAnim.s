nonmatching Anim_HasModelAnim, 0xAC

glabel Anim_HasModelAnim
    /* FA74 8001F274 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* FA78 8001F278 1000B0AF */  sw         $s0, 0x10($sp)
    /* FA7C 8001F27C 2180A000 */  addu       $s0, $a1, $zero
    /* FA80 8001F280 0A00022A */  slti       $v0, $s0, 0xA
    /* FA84 8001F284 1800BFAF */  sw         $ra, 0x18($sp)
    /* FA88 8001F288 1400B1AF */  sw         $s1, 0x14($sp)
    /* FA8C 8001F28C 3C00918C */  lw         $s1, 0x3C($a0)
    /* FA90 8001F290 06004010 */  beqz       $v0, .L8001F2AC
    /* FA94 8001F294 21280000 */   addu      $a1, $zero, $zero
    /* FA98 8001F298 0C00848C */  lw         $a0, 0xC($a0)
    /* FA9C 8001F29C CA79000C */  jal        Anim_GetModelAnimFile
    /* FAA0 8001F2A0 2180A000 */   addu      $s0, $a1, $zero
    /* FAA4 8001F2A4 B77C0008 */  j          .L8001F2DC
    /* FAA8 8001F2A8 00000000 */   nop
  .L8001F2AC:
    /* FAAC 8001F2AC 1400022A */  slti       $v0, $s0, 0x14
    /* FAB0 8001F2B0 06004010 */  beqz       $v0, .L8001F2CC
    /* FAB4 8001F2B4 00000000 */   nop
    /* FAB8 8001F2B8 0C00848C */  lw         $a0, 0xC($a0)
    /* FABC 8001F2BC CA79000C */  jal        Anim_GetModelAnimFile
    /* FAC0 8001F2C0 01000524 */   addiu     $a1, $zero, 0x1
    /* FAC4 8001F2C4 B77C0008 */  j          .L8001F2DC
    /* FAC8 8001F2C8 F6FF1026 */   addiu     $s0, $s0, -0xA
  .L8001F2CC:
    /* FACC 8001F2CC 0C00848C */  lw         $a0, 0xC($a0)
    /* FAD0 8001F2D0 CA79000C */  jal        Anim_GetModelAnimFile
    /* FAD4 8001F2D4 02000524 */   addiu     $a1, $zero, 0x2
    /* FAD8 8001F2D8 ECFF1026 */  addiu      $s0, $s0, -0x14
  .L8001F2DC:
    /* FADC 8001F2DC 828E000C */  jal        Cd_GetFileOrNull
    /* FAE0 8001F2E0 21204000 */   addu      $a0, $v0, $zero
    /* FAE4 8001F2E4 0800238E */  lw         $v1, 0x8($s1)
    /* FAE8 8001F2E8 00000000 */  nop
    /* FAEC 8001F2EC 01006324 */  addiu      $v1, $v1, 0x1
    /* FAF0 8001F2F0 80180300 */  sll        $v1, $v1, 2
    /* FAF4 8001F2F4 21104300 */  addu       $v0, $v0, $v1
    /* FAF8 8001F2F8 80181000 */  sll        $v1, $s0, 2
    /* FAFC 8001F2FC 21186200 */  addu       $v1, $v1, $v0
    /* FB00 8001F300 640022AE */  sw         $v0, 0x64($s1)
    /* FB04 8001F304 0000628C */  lw         $v0, 0x0($v1)
    /* FB08 8001F308 1800BF8F */  lw         $ra, 0x18($sp)
    /* FB0C 8001F30C 1400B18F */  lw         $s1, 0x14($sp)
    /* FB10 8001F310 1000B08F */  lw         $s0, 0x10($sp)
    /* FB14 8001F314 2B100200 */  sltu       $v0, $zero, $v0
    /* FB18 8001F318 0800E003 */  jr         $ra
    /* FB1C 8001F31C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Anim_HasModelAnim
