nonmatching Stg30_GetSkillEffectKind, 0x60

glabel Stg30_GetSkillEffectKind
    /* AF5C 8006E2BC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* AF60 8006E2C0 1000B0AF */  sw         $s0, 0x10($sp)
    /* AF64 8006E2C4 1400BFAF */  sw         $ra, 0x14($sp)
    /* AF68 8006E2C8 D97B000C */  jal        Skill_GetPower
    /* AF6C 8006E2CC 21808000 */   addu      $s0, $a0, $zero
    /* AF70 8006E2D0 03004018 */  blez       $v0, .L8006E2E0
    /* AF74 8006E2D4 00000000 */   nop
    /* AF78 8006E2D8 C3B80108 */  j          .L8006E30C
    /* AF7C 8006E2DC 21100000 */   addu      $v0, $zero, $zero
  .L8006E2E0:
    /* AF80 8006E2E0 09004004 */  bltz       $v0, .L8006E308
    /* AF84 8006E2E4 00000000 */   nop
    /* AF88 8006E2E8 257C000C */  jal        Skill_GetCureFlags
    /* AF8C 8006E2EC 21200002 */   addu      $a0, $s0, $zero
    /* AF90 8006E2F0 0200033C */  lui        $v1, (0x20000 >> 16)
    /* AF94 8006E2F4 24184300 */  and        $v1, $v0, $v1
    /* AF98 8006E2F8 04006014 */  bnez       $v1, .L8006E30C
    /* AF9C 8006E2FC 03000224 */   addiu     $v0, $zero, 0x3
    /* AFA0 8006E300 C3B80108 */  j          .L8006E30C
    /* AFA4 8006E304 02000224 */   addiu     $v0, $zero, 0x2
  .L8006E308:
    /* AFA8 8006E308 01000224 */  addiu      $v0, $zero, 0x1
  .L8006E30C:
    /* AFAC 8006E30C 1400BF8F */  lw         $ra, 0x14($sp)
    /* AFB0 8006E310 1000B08F */  lw         $s0, 0x10($sp)
    /* AFB4 8006E314 0800E003 */  jr         $ra
    /* AFB8 8006E318 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg30_GetSkillEffectKind
