nonmatching Flag_FirstPassingEntry, 0x4C

glabel Flag_FirstPassingEntry
    /* EC80 8001E480 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* EC84 8001E484 1000B0AF */  sw         $s0, 0x10($sp)
    /* EC88 8001E488 0680103C */  lui        $s0, %hi(Flag_EntryIter)
    /* EC8C 8001E48C 60D5048E */  lw         $a0, %lo(Flag_EntryIter)($s0)
    /* EC90 8001E490 1400BFAF */  sw         $ra, 0x14($sp)
    /* EC94 8001E494 828E000C */  jal        Cd_GetFileOrNull
    /* EC98 8001E498 00000000 */   nop
    /* EC9C 8001E49C 60D5048E */  lw         $a0, %lo(Flag_EntryIter)($s0)
    /* ECA0 8001E4A0 60D51026 */  addiu      $s0, $s0, %lo(Flag_EntryIter)
    /* ECA4 8001E4A4 040002AE */  sw         $v0, 0x4($s0)
    /* ECA8 8001E4A8 688E000C */  jal        Cd_GetFileEntry
    /* ECAC 8001E4AC 00240400 */   sll       $a0, $a0, 16
    /* ECB0 8001E4B0 0C0002AE */  sw         $v0, 0xC($s0)
    /* ECB4 8001E4B4 E478000C */  jal        Flag_NextPassingEntry
    /* ECB8 8001E4B8 080000AE */   sw        $zero, 0x8($s0)
    /* ECBC 8001E4BC 1400BF8F */  lw         $ra, 0x14($sp)
    /* ECC0 8001E4C0 1000B08F */  lw         $s0, 0x10($sp)
    /* ECC4 8001E4C4 0800E003 */  jr         $ra
    /* ECC8 8001E4C8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Flag_FirstPassingEntry
