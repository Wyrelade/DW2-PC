nonmatching Cd_EvictLruFile, 0x44

glabel Cd_EvictLruFile
    /* 143B0 80023BB0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 143B4 80023BB4 1400BFAF */  sw         $ra, 0x14($sp)
    /* 143B8 80023BB8 BA8E000C */  jal        Cd_FindLruCachedFile
    /* 143BC 80023BBC 1000B0AF */   sw        $s0, 0x10($sp)
    /* 143C0 80023BC0 21804000 */  addu       $s0, $v0, $zero
    /* 143C4 80023BC4 0C00048E */  lw         $a0, 0xC($s0)
    /* 143C8 80023BC8 618B000C */  jal        Mem_Free
    /* 143CC 80023BCC 00000000 */   nop
    /* 143D0 80023BD0 040000AE */  sw         $zero, 0x4($s0)
    /* 143D4 80023BD4 0C0000AE */  sw         $zero, 0xC($s0)
    /* 143D8 80023BD8 080000AE */  sw         $zero, 0x8($s0)
    /* 143DC 80023BDC 000000A6 */  sh         $zero, 0x0($s0)
    /* 143E0 80023BE0 020000A6 */  sh         $zero, 0x2($s0)
    /* 143E4 80023BE4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 143E8 80023BE8 1000B08F */  lw         $s0, 0x10($sp)
    /* 143EC 80023BEC 0800E003 */  jr         $ra
    /* 143F0 80023BF0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Cd_EvictLruFile
