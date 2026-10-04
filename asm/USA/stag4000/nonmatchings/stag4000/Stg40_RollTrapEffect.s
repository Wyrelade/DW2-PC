nonmatching Stg40_RollTrapEffect, 0x7C

glabel Stg40_RollTrapEffect
    /* DF34 80071294 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* DF38 80071298 0780023C */  lui        $v0, %hi(Stg40_TrapEffectTable)
    /* DF3C 8007129C 1000B0AF */  sw         $s0, 0x10($sp)
    /* DF40 800712A0 1400BFAF */  sw         $ra, 0x14($sp)
    /* DF44 800712A4 60C4010C */  jal        Stg40_RandPercent
    /* DF48 800712A8 302A5024 */   addiu     $s0, $v0, %lo(Stg40_TrapEffectTable)
    /* DF4C 800712AC 02004104 */  bgez       $v0, .L800712B8
    /* DF50 800712B0 00000000 */   nop
    /* DF54 800712B4 03004224 */  addiu      $v0, $v0, 0x3
  .L800712B8:
    /* DF58 800712B8 83100200 */  sra        $v0, $v0, 2
    /* DF5C 800712BC 21105000 */  addu       $v0, $v0, $s0
    /* DF60 800712C0 00005090 */  lbu        $s0, 0x0($v0)
    /* DF64 800712C4 00000000 */  nop
    /* DF68 800712C8 FCFF0426 */  addiu      $a0, $s0, -0x4
    /* DF6C 800712CC 0C00822C */  sltiu      $v0, $a0, 0xC
    /* DF70 800712D0 0A004010 */  beqz       $v0, .L800712FC
    /* DF74 800712D4 0780033C */   lui       $v1, %hi(Stg40_TrapPartSlots)
    /* DF78 800712D8 E0296324 */  addiu      $v1, $v1, %lo(Stg40_TrapPartSlots)
    /* DF7C 800712DC 40100400 */  sll        $v0, $a0, 1
    /* DF80 800712E0 21104300 */  addu       $v0, $v0, $v1
    /* DF84 800712E4 00004484 */  lh         $a0, 0x0($v0)
    /* DF88 800712E8 08BA010C */  jal        Stg40_GetBeetlePart
    /* DF8C 800712EC 00000000 */   nop
    /* DF90 800712F0 0300401C */  bgtz       $v0, .L80071300
    /* DF94 800712F4 21100002 */   addu      $v0, $s0, $zero
    /* DF98 800712F8 10001024 */  addiu      $s0, $zero, 0x10
  .L800712FC:
    /* DF9C 800712FC 21100002 */  addu       $v0, $s0, $zero
  .L80071300:
    /* DFA0 80071300 1400BF8F */  lw         $ra, 0x14($sp)
    /* DFA4 80071304 1000B08F */  lw         $s0, 0x10($sp)
    /* DFA8 80071308 0800E003 */  jr         $ra
    /* DFAC 8007130C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg40_RollTrapEffect
