nonmatching Flag_GetEntryCondBlock, 0x48

glabel Flag_GetEntryCondBlock
    /* EA98 8001E298 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* EA9C 8001E29C 1000B0AF */  sw         $s0, 0x10($sp)
    /* EAA0 8001E2A0 21808000 */  addu       $s0, $a0, $zero
    /* EAA4 8001E2A4 0680023C */  lui        $v0, %hi(Flag_EntryIter)
    /* EAA8 8001E2A8 60D5448C */  lw         $a0, %lo(Flag_EntryIter)($v0)
    /* EAAC 8001E2AC 1400BFAF */  sw         $ra, 0x14($sp)
    /* EAB0 8001E2B0 00240400 */  sll        $a0, $a0, 16
    /* EAB4 8001E2B4 688E000C */  jal        Cd_GetFileEntry
    /* EAB8 8001E2B8 02008434 */   ori       $a0, $a0, 0x2
    /* EABC 8001E2BC 05000492 */  lbu        $a0, 0x5($s0)
    /* EAC0 8001E2C0 1400BF8F */  lw         $ra, 0x14($sp)
    /* EAC4 8001E2C4 1000B08F */  lw         $s0, 0x10($sp)
    /* EAC8 8001E2C8 40180400 */  sll        $v1, $a0, 1
    /* EACC 8001E2CC 21186400 */  addu       $v1, $v1, $a0
    /* EAD0 8001E2D0 C0180300 */  sll        $v1, $v1, 3
    /* EAD4 8001E2D4 21104300 */  addu       $v0, $v0, $v1
    /* EAD8 8001E2D8 0800E003 */  jr         $ra
    /* EADC 8001E2DC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Flag_GetEntryCondBlock
