nonmatching Digi_GetEvolutionTarget, 0x98

glabel Digi_GetEvolutionTarget
    /* E280 8001DA80 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* E284 8001DA84 1000B0AF */  sw         $s0, 0x10($sp)
    /* E288 8001DA88 1400BFAF */  sw         $ra, 0x14($sp)
    /* E28C 8001DA8C 3176000C */  jal        Digi_FindBaseData
    /* E290 8001DA90 2180A000 */   addu      $s0, $a1, $zero
    /* E294 8001DA94 21304000 */  addu       $a2, $v0, $zero
    /* E298 8001DA98 0D00C290 */  lbu        $v0, 0xD($a2)
    /* E29C 8001DA9C 00000000 */  nop
    /* E2A0 8001DAA0 03004014 */  bnez       $v0, .L8001DAB0
    /* E2A4 8001DAA4 21180000 */   addu      $v1, $zero, $zero
    /* E2A8 8001DAA8 C2760008 */  j          .L8001DB08
    /* E2AC 8001DAAC 21100000 */   addu      $v0, $zero, $zero
  .L8001DAB0:
    /* E2B0 8001DAB0 01006524 */  addiu      $a1, $v1, 0x1
  .L8001DAB4:
    /* E2B4 8001DAB4 2120C500 */  addu       $a0, $a2, $a1
    /* E2B8 8001DAB8 08008290 */  lbu        $v0, 0x8($a0)
    /* E2BC 8001DABC 00000000 */  nop
    /* E2C0 8001DAC0 0F004010 */  beqz       $v0, .L8001DB00
    /* E2C4 8001DAC4 2110C300 */   addu      $v0, $a2, $v1
    /* E2C8 8001DAC8 08004290 */  lbu        $v0, 0x8($v0)
    /* E2CC 8001DACC 00000000 */  nop
    /* E2D0 8001DAD0 2A100202 */  slt        $v0, $s0, $v0
    /* E2D4 8001DAD4 06004014 */  bnez       $v0, .L8001DAF0
    /* E2D8 8001DAD8 00000000 */   nop
    /* E2DC 8001DADC 08008290 */  lbu        $v0, 0x8($a0)
    /* E2E0 8001DAE0 00000000 */  nop
    /* E2E4 8001DAE4 2A100202 */  slt        $v0, $s0, $v0
    /* E2E8 8001DAE8 06004014 */  bnez       $v0, .L8001DB04
    /* E2EC 8001DAEC 2110C300 */   addu      $v0, $a2, $v1
  .L8001DAF0:
    /* E2F0 8001DAF0 2118A000 */  addu       $v1, $a1, $zero
    /* E2F4 8001DAF4 0400A228 */  slti       $v0, $a1, 0x4
    /* E2F8 8001DAF8 EEFF4014 */  bnez       $v0, .L8001DAB4
    /* E2FC 8001DAFC 01006524 */   addiu     $a1, $v1, 0x1
  .L8001DB00:
    /* E300 8001DB00 2110C300 */  addu       $v0, $a2, $v1
  .L8001DB04:
    /* E304 8001DB04 0D004290 */  lbu        $v0, 0xD($v0)
  .L8001DB08:
    /* E308 8001DB08 1400BF8F */  lw         $ra, 0x14($sp)
    /* E30C 8001DB0C 1000B08F */  lw         $s0, 0x10($sp)
    /* E310 8001DB10 0800E003 */  jr         $ra
    /* E314 8001DB14 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Digi_GetEvolutionTarget
