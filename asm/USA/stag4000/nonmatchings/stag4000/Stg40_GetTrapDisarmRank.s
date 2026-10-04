nonmatching Stg40_GetTrapDisarmRank, 0x54

glabel Stg40_GetTrapDisarmRank
    /* DEA4 80071204 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* DEA8 80071208 1000B0AF */  sw         $s0, 0x10($sp)
    /* DEAC 8007120C 21808000 */  addu       $s0, $a0, $zero
    /* DEB0 80071210 1400BFAF */  sw         $ra, 0x14($sp)
    /* DEB4 80071214 16BA010C */  jal        Stg40_GetPartLevel
    /* DEB8 80071218 07000424 */   addiu     $a0, $zero, 0x7
    /* DEBC 8007121C 02004104 */  bgez       $v0, .L80071228
    /* DEC0 80071220 21204000 */   addu      $a0, $v0, $zero
    /* DEC4 80071224 21200000 */  addu       $a0, $zero, $zero
  .L80071228:
    /* DEC8 80071228 0780033C */  lui        $v1, %hi(Stg40_TrapDisarmRanks)
    /* DECC 8007122C F8296324 */  addiu      $v1, $v1, %lo(Stg40_TrapDisarmRanks)
    /* DED0 80071230 40100400 */  sll        $v0, $a0, 1
    /* DED4 80071234 21104400 */  addu       $v0, $v0, $a0
    /* DED8 80071238 40100200 */  sll        $v0, $v0, 1
    /* DEDC 8007123C 21100202 */  addu       $v0, $s0, $v0
    /* DEE0 80071240 21104300 */  addu       $v0, $v0, $v1
    /* DEE4 80071244 00004290 */  lbu        $v0, 0x0($v0)
    /* DEE8 80071248 1400BF8F */  lw         $ra, 0x14($sp)
    /* DEEC 8007124C 1000B08F */  lw         $s0, 0x10($sp)
    /* DEF0 80071250 0800E003 */  jr         $ra
    /* DEF4 80071254 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg40_GetTrapDisarmRank
