nonmatching Stg35_TextAlloc, 0x48

glabel Stg35_TextAlloc
    /* 2370 800656D0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2374 800656D4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2378 800656D8 21808000 */  addu       $s0, $a0, $zero
    /* 237C 800656DC 1C000424 */  addiu      $a0, $zero, 0x1C
    /* 2380 800656E0 1400BFAF */  sw         $ra, 0x14($sp)
    /* 2384 800656E4 CF8B000C */  jal        Mem_Alloc
    /* 2388 800656E8 02000524 */   addiu     $a1, $zero, 0x2
    /* 238C 800656EC 21204000 */  addu       $a0, $v0, $zero
    /* 2390 800656F0 1C000524 */  addiu      $a1, $zero, 0x1C
    /* 2394 800656F4 E38B000C */  jal        Mem_Zero
    /* 2398 800656F8 000004AE */   sw        $a0, 0x0($s0)
    /* 239C 800656FC 0000038E */  lw         $v1, 0x0($s0)
    /* 23A0 80065700 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 23A4 80065704 000062AC */  sw         $v0, 0x0($v1)
    /* 23A8 80065708 1400BF8F */  lw         $ra, 0x14($sp)
    /* 23AC 8006570C 1000B08F */  lw         $s0, 0x10($sp)
    /* 23B0 80065710 0800E003 */  jr         $ra
    /* 23B4 80065714 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg35_TextAlloc
