nonmatching Stg35_PartsFree, 0x3C

glabel Stg35_PartsFree
    /* 2E08 80066168 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2E0C 8006616C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2E10 80066170 21808000 */  addu       $s0, $a0, $zero
    /* 2E14 80066174 1400BFAF */  sw         $ra, 0x14($sp)
    /* 2E18 80066178 0000048E */  lw         $a0, 0x0($s0)
    /* 2E1C 8006617C 00000000 */  nop
    /* 2E20 80066180 04008010 */  beqz       $a0, .L80066194
    /* 2E24 80066184 00000000 */   nop
    /* 2E28 80066188 618B000C */  jal        Mem_Free
    /* 2E2C 8006618C 00000000 */   nop
    /* 2E30 80066190 000000AE */  sw         $zero, 0x0($s0)
  .L80066194:
    /* 2E34 80066194 1400BF8F */  lw         $ra, 0x14($sp)
    /* 2E38 80066198 1000B08F */  lw         $s0, 0x10($sp)
    /* 2E3C 8006619C 0800E003 */  jr         $ra
    /* 2E40 800661A0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg35_PartsFree
