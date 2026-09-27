nonmatching func_800658B8, 0x3C

glabel func_800658B8
    /* 2558 800658B8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 255C 800658BC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2560 800658C0 21808000 */  addu       $s0, $a0, $zero
    /* 2564 800658C4 20000424 */  addiu      $a0, $zero, 0x20
    /* 2568 800658C8 1400BFAF */  sw         $ra, 0x14($sp)
    /* 256C 800658CC CF8B000C */  jal        Mem_Alloc
    /* 2570 800658D0 02000524 */   addiu     $a1, $zero, 0x2
    /* 2574 800658D4 21204000 */  addu       $a0, $v0, $zero
    /* 2578 800658D8 20000524 */  addiu      $a1, $zero, 0x20
    /* 257C 800658DC E38B000C */  jal        Mem_Zero
    /* 2580 800658E0 000002AE */   sw        $v0, 0x0($s0)
    /* 2584 800658E4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 2588 800658E8 1000B08F */  lw         $s0, 0x10($sp)
    /* 258C 800658EC 0800E003 */  jr         $ra
    /* 2590 800658F0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800658B8
