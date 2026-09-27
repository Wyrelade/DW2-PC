nonmatching GsMulCoord2, 0x80

glabel GsMulCoord2
    /* 1C864 8002C064 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 1C868 8002C068 2000B0AF */  sw         $s0, 0x20($sp)
    /* 1C86C 8002C06C 21808000 */  addu       $s0, $a0, $zero
    /* 1C870 8002C070 2400B1AF */  sw         $s1, 0x24($sp)
    /* 1C874 8002C074 2188A000 */  addu       $s1, $a1, $zero
    /* 1C878 8002C078 14002526 */  addiu      $a1, $s1, 0x14
    /* 1C87C 8002C07C 2800BFAF */  sw         $ra, 0x28($sp)
    /* 1C880 8002C080 DDB3000C */  jal        ApplyMatrixLV
    /* 1C884 8002C084 1000A627 */   addiu     $a2, $sp, 0x10
    /* 1C888 8002C088 21200002 */  addu       $a0, $s0, $zero
    /* 1C88C 8002C08C CDB4000C */  jal        MulMatrix2
    /* 1C890 8002C090 21282002 */   addu      $a1, $s1, $zero
    /* 1C894 8002C094 1000A28F */  lw         $v0, 0x10($sp)
    /* 1C898 8002C098 1400038E */  lw         $v1, 0x14($s0)
    /* 1C89C 8002C09C 00000000 */  nop
    /* 1C8A0 8002C0A0 21104300 */  addu       $v0, $v0, $v1
    /* 1C8A4 8002C0A4 140022AE */  sw         $v0, 0x14($s1)
    /* 1C8A8 8002C0A8 1400A28F */  lw         $v0, 0x14($sp)
    /* 1C8AC 8002C0AC 1800038E */  lw         $v1, 0x18($s0)
    /* 1C8B0 8002C0B0 00000000 */  nop
    /* 1C8B4 8002C0B4 21104300 */  addu       $v0, $v0, $v1
    /* 1C8B8 8002C0B8 180022AE */  sw         $v0, 0x18($s1)
    /* 1C8BC 8002C0BC 1800A28F */  lw         $v0, 0x18($sp)
    /* 1C8C0 8002C0C0 1C00038E */  lw         $v1, 0x1C($s0)
    /* 1C8C4 8002C0C4 00000000 */  nop
    /* 1C8C8 8002C0C8 21104300 */  addu       $v0, $v0, $v1
    /* 1C8CC 8002C0CC 1C0022AE */  sw         $v0, 0x1C($s1)
    /* 1C8D0 8002C0D0 2800BF8F */  lw         $ra, 0x28($sp)
    /* 1C8D4 8002C0D4 2400B18F */  lw         $s1, 0x24($sp)
    /* 1C8D8 8002C0D8 2000B08F */  lw         $s0, 0x20($sp)
    /* 1C8DC 8002C0DC 0800E003 */  jr         $ra
    /* 1C8E0 8002C0E0 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel GsMulCoord2
