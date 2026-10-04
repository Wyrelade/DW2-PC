nonmatching Stg40_RollTrapDisarm, 0x3C

glabel Stg40_RollTrapDisarm
    /* DEF8 80071258 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* DEFC 8007125C 1000B0AF */  sw         $s0, 0x10($sp)
    /* DF00 80071260 1400BFAF */  sw         $ra, 0x14($sp)
    /* DF04 80071264 60C4010C */  jal        Stg40_RandPercent
    /* DF08 80071268 21808000 */   addu      $s0, $a0, $zero
    /* DF0C 8007126C 0780033C */  lui        $v1, %hi(Stg40_TrapDisarmChance)
    /* DF10 80071270 1C2A6324 */  addiu      $v1, $v1, %lo(Stg40_TrapDisarmChance)
    /* DF14 80071274 80801000 */  sll        $s0, $s0, 2
    /* DF18 80071278 21800302 */  addu       $s0, $s0, $v1
    /* DF1C 8007127C 0000038E */  lw         $v1, 0x0($s0)
    /* DF20 80071280 1400BF8F */  lw         $ra, 0x14($sp)
    /* DF24 80071284 1000B08F */  lw         $s0, 0x10($sp)
    /* DF28 80071288 2A104300 */  slt        $v0, $v0, $v1
    /* DF2C 8007128C 0800E003 */  jr         $ra
    /* DF30 80071290 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg40_RollTrapDisarm
