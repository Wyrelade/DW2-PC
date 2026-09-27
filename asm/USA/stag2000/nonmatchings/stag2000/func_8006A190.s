nonmatching func_8006A190, 0xB8

glabel func_8006A190
    /* 6E30 8006A190 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 6E34 8006A194 1800B2AF */  sw         $s2, 0x18($sp)
    /* 6E38 8006A198 21908000 */  addu       $s2, $a0, $zero
    /* 6E3C 8006A19C 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 6E40 8006A1A0 2198A000 */  addu       $s3, $a1, $zero
    /* 6E44 8006A1A4 2400BFAF */  sw         $ra, 0x24($sp)
    /* 6E48 8006A1A8 2000B4AF */  sw         $s4, 0x20($sp)
    /* 6E4C 8006A1AC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6E50 8006A1B0 51A8010C */  jal        func_8006A144
    /* 6E54 8006A1B4 1000B0AF */   sw        $s0, 0x10($sp)
    /* 6E58 8006A1B8 21204002 */  addu       $a0, $s2, $zero
    /* 6E5C 8006A1BC 5676000C */  jal        func_8001D958
    /* 6E60 8006A1C0 21A04000 */   addu      $s4, $v0, $zero
    /* 6E64 8006A1C4 21206002 */  addu       $a0, $s3, $zero
    /* 6E68 8006A1C8 5676000C */  jal        func_8001D958
    /* 6E6C 8006A1CC 21804000 */   addu      $s0, $v0, $zero
    /* 6E70 8006A1D0 21884000 */  addu       $s1, $v0, $zero
    /* 6E74 8006A1D4 2A101102 */  slt        $v0, $s0, $s1
    /* 6E78 8006A1D8 02004010 */  beqz       $v0, .L8006A1E4
    /* 6E7C 8006A1DC 21204002 */   addu      $a0, $s2, $zero
    /* 6E80 8006A1E0 21880002 */  addu       $s1, $s0, $zero
  .L8006A1E4:
    /* 6E84 8006A1E4 4476000C */  jal        func_8001D910
    /* 6E88 8006A1E8 FFFF3126 */   addiu     $s1, $s1, -0x1
    /* 6E8C 8006A1EC 21206002 */  addu       $a0, $s3, $zero
    /* 6E90 8006A1F0 4476000C */  jal        func_8001D910
    /* 6E94 8006A1F4 21804000 */   addu      $s0, $v0, $zero
    /* 6E98 8006A1F8 0780043C */  lui        $a0, %hi(D_80070138)
    /* 6E9C 8006A1FC 38018424 */  addiu      $a0, $a0, %lo(D_80070138)
    /* 6EA0 8006A200 C0801000 */  sll        $s0, $s0, 3
    /* 6EA4 8006A204 21105000 */  addu       $v0, $v0, $s0
    /* 6EA8 8006A208 80891100 */  sll        $s1, $s1, 6
    /* 6EAC 8006A20C 21105100 */  addu       $v0, $v0, $s1
    /* 6EB0 8006A210 40181400 */  sll        $v1, $s4, 1
    /* 6EB4 8006A214 21187400 */  addu       $v1, $v1, $s4
    /* 6EB8 8006A218 80190300 */  sll        $v1, $v1, 6
    /* 6EBC 8006A21C 21104300 */  addu       $v0, $v0, $v1
    /* 6EC0 8006A220 21104400 */  addu       $v0, $v0, $a0
    /* 6EC4 8006A224 00004290 */  lbu        $v0, 0x0($v0)
    /* 6EC8 8006A228 2400BF8F */  lw         $ra, 0x24($sp)
    /* 6ECC 8006A22C 2000B48F */  lw         $s4, 0x20($sp)
    /* 6ED0 8006A230 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 6ED4 8006A234 1800B28F */  lw         $s2, 0x18($sp)
    /* 6ED8 8006A238 1400B18F */  lw         $s1, 0x14($sp)
    /* 6EDC 8006A23C 1000B08F */  lw         $s0, 0x10($sp)
    /* 6EE0 8006A240 0800E003 */  jr         $ra
    /* 6EE4 8006A244 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8006A190
