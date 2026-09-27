nonmatching _spu_Fr, 0x64

glabel _spu_Fr
    /* 2B27C 8003AA7C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2B280 8003AA80 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2B284 8003AA84 21888000 */  addu       $s1, $a0, $zero
    /* 2B288 8003AA88 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2B28C 8003AA8C 2180A000 */  addu       $s0, $a1, $zero
    /* 2B290 8003AA90 0580023C */  lui        $v0, %hi(D_8004FE40)
    /* 2B294 8003AA94 40FE4294 */  lhu        $v0, %lo(D_8004FE40)($v0)
    /* 2B298 8003AA98 0580053C */  lui        $a1, %hi(D_8004FE50)
    /* 2B29C 8003AA9C 50FEA58C */  lw         $a1, %lo(D_8004FE50)($a1)
    /* 2B2A0 8003AAA0 02000424 */  addiu      $a0, $zero, 0x2
    /* 2B2A4 8003AAA4 1800BFAF */  sw         $ra, 0x18($sp)
    /* 2B2A8 8003AAA8 DEE9000C */  jal        _spu_t
    /* 2B2AC 8003AAAC 0428A200 */   sllv      $a1, $v0, $a1
    /* 2B2B0 8003AAB0 DEE9000C */  jal        _spu_t
    /* 2B2B4 8003AAB4 21200000 */   addu      $a0, $zero, $zero
    /* 2B2B8 8003AAB8 03000424 */  addiu      $a0, $zero, 0x3
    /* 2B2BC 8003AABC 21282002 */  addu       $a1, $s1, $zero
    /* 2B2C0 8003AAC0 DEE9000C */  jal        _spu_t
    /* 2B2C4 8003AAC4 21300002 */   addu      $a2, $s0, $zero
    /* 2B2C8 8003AAC8 21100002 */  addu       $v0, $s0, $zero
    /* 2B2CC 8003AACC 1800BF8F */  lw         $ra, 0x18($sp)
    /* 2B2D0 8003AAD0 1400B18F */  lw         $s1, 0x14($sp)
    /* 2B2D4 8003AAD4 1000B08F */  lw         $s0, 0x10($sp)
    /* 2B2D8 8003AAD8 0800E003 */  jr         $ra
    /* 2B2DC 8003AADC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _spu_Fr
