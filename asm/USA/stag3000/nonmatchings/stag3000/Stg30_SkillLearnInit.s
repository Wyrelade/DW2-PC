nonmatching Stg30_SkillLearnInit, 0x54

glabel Stg30_SkillLearnInit
    /* EA10 80071D70 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* EA14 80071D74 21300000 */  addu       $a2, $zero, $zero
    /* EA18 80071D78 1000BFAF */  sw         $ra, 0x10($sp)
    /* EA1C 80071D7C 2C00828C */  lw         $v0, 0x2C($a0)
    /* EA20 80071D80 0000A38C */  lw         $v1, 0x0($a1)
    /* EA24 80071D84 21204000 */  addu       $a0, $v0, $zero
    /* EA28 80071D88 000083AC */  sw         $v1, 0x0($a0)
  .L80071D8C:
    /* EA2C 80071D8C 0400A294 */  lhu        $v0, 0x4($a1)
    /* EA30 80071D90 0200A524 */  addiu      $a1, $a1, 0x2
    /* EA34 80071D94 0100C624 */  addiu      $a2, $a2, 0x1
    /* EA38 80071D98 740082A4 */  sh         $v0, 0x74($a0)
    /* EA3C 80071D9C 0C00C228 */  slti       $v0, $a2, 0xC
    /* EA40 80071DA0 FAFF4014 */  bnez       $v0, .L80071D8C
    /* EA44 80071DA4 02008424 */   addiu     $a0, $a0, 0x2
    /* EA48 80071DA8 2B000424 */  addiu      $a0, $zero, 0x2B
    /* EA4C 80071DAC A369000C */  jal        Snd_PlayById
    /* EA50 80071DB0 21280000 */   addu      $a1, $zero, $zero
    /* EA54 80071DB4 1000BF8F */  lw         $ra, 0x10($sp)
    /* EA58 80071DB8 00000000 */  nop
    /* EA5C 80071DBC 0800E003 */  jr         $ra
    /* EA60 80071DC0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg30_SkillLearnInit
