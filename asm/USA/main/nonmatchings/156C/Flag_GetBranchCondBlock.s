nonmatching Flag_GetBranchCondBlock, 0x58

glabel Flag_GetBranchCondBlock
    /* EAE0 8001E2E0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* EAE4 8001E2E4 1000B0AF */  sw         $s0, 0x10($sp)
    /* EAE8 8001E2E8 21808000 */  addu       $s0, $a0, $zero
    /* EAEC 8001E2EC 0680023C */  lui        $v0, %hi(Flag_EntryIter)
    /* EAF0 8001E2F0 60D5448C */  lw         $a0, %lo(Flag_EntryIter)($v0)
    /* EAF4 8001E2F4 1400B1AF */  sw         $s1, 0x14($sp)
    /* EAF8 8001E2F8 2188A000 */  addu       $s1, $a1, $zero
    /* EAFC 8001E2FC 1800BFAF */  sw         $ra, 0x18($sp)
    /* EB00 8001E300 00240400 */  sll        $a0, $a0, 16
    /* EB04 8001E304 688E000C */  jal        Cd_GetFileEntry
    /* EB08 8001E308 02008434 */   ori       $a0, $a0, 0x2
    /* EB0C 8001E30C 21801102 */  addu       $s0, $s0, $s1
    /* EB10 8001E310 06000492 */  lbu        $a0, 0x6($s0)
    /* EB14 8001E314 1800BF8F */  lw         $ra, 0x18($sp)
    /* EB18 8001E318 1400B18F */  lw         $s1, 0x14($sp)
    /* EB1C 8001E31C 1000B08F */  lw         $s0, 0x10($sp)
    /* EB20 8001E320 40180400 */  sll        $v1, $a0, 1
    /* EB24 8001E324 21186400 */  addu       $v1, $v1, $a0
    /* EB28 8001E328 C0180300 */  sll        $v1, $v1, 3
    /* EB2C 8001E32C 21104300 */  addu       $v0, $v0, $v1
    /* EB30 8001E330 0800E003 */  jr         $ra
    /* EB34 8001E334 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Flag_GetBranchCondBlock
