nonmatching SsVabClose, 0xA4

glabel SsVabClose
    /* 2A194 80039994 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2A198 80039998 FFFF8230 */  andi       $v0, $a0, 0xFFFF
    /* 2A19C 8003999C 1000422C */  sltiu      $v0, $v0, 0x10
    /* 2A1A0 800399A0 1400BFAF */  sw         $ra, 0x14($sp)
    /* 2A1A4 800399A4 20004010 */  beqz       $v0, .L80039A28
    /* 2A1A8 800399A8 1000B0AF */   sw        $s0, 0x10($sp)
    /* 2A1AC 800399AC 00140400 */  sll        $v0, $a0, 16
    /* 2A1B0 800399B0 03840200 */  sra        $s0, $v0, 16
    /* 2A1B4 800399B4 0680033C */  lui        $v1, %hi(D_80062D38)
    /* 2A1B8 800399B8 21187000 */  addu       $v1, $v1, $s0
    /* 2A1BC 800399BC 382D6390 */  lbu        $v1, %lo(D_80062D38)($v1)
    /* 2A1C0 800399C0 00000000 */  nop
    /* 2A1C4 800399C4 03006228 */  slti       $v0, $v1, 0x3
    /* 2A1C8 800399C8 17004010 */  beqz       $v0, .L80039A28
    /* 2A1CC 800399CC 00000000 */   nop
    /* 2A1D0 800399D0 15006010 */  beqz       $v1, .L80039A28
    /* 2A1D4 800399D4 80101000 */   sll       $v0, $s0, 2
    /* 2A1D8 800399D8 0680043C */  lui        $a0, %hi(D_80062D98)
    /* 2A1DC 800399DC 21208200 */  addu       $a0, $a0, $v0
    /* 2A1E0 800399E0 982D848C */  lw         $a0, %lo(D_80062D98)($a0)
    /* 2A1E4 800399E4 DDEC000C */  jal        SpuFree
    /* 2A1E8 800399E8 00000000 */   nop
    /* 2A1EC 800399EC 0680013C */  lui        $at, %hi(D_80062D38)
    /* 2A1F0 800399F0 21083000 */  addu       $at, $at, $s0
    /* 2A1F4 800399F4 382D20A0 */  sb         $zero, %lo(D_80062D38)($at)
    /* 2A1F8 800399F8 0680023C */  lui        $v0, %hi(D_80062D90)
    /* 2A1FC 800399FC 902D4294 */  lhu        $v0, %lo(D_80062D90)($v0)
    /* 2A200 80039A00 00000000 */  nop
    /* 2A204 80039A04 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 2A208 80039A08 0680013C */  lui        $at, %hi(D_80062D90)
    /* 2A20C 80039A0C 3BF2000C */  jal        _spu_getInTransfer
    /* 2A210 80039A10 902D22A4 */   sh        $v0, %lo(D_80062D90)($at)
    /* 2A214 80039A14 01000324 */  addiu      $v1, $zero, 0x1
    /* 2A218 80039A18 03004314 */  bne        $v0, $v1, .L80039A28
    /* 2A21C 80039A1C 00000000 */   nop
    /* 2A220 80039A20 31F2000C */  jal        _spu_setInTransfer
    /* 2A224 80039A24 21200000 */   addu      $a0, $zero, $zero
  .L80039A28:
    /* 2A228 80039A28 1400BF8F */  lw         $ra, 0x14($sp)
    /* 2A22C 80039A2C 1000B08F */  lw         $s0, 0x10($sp)
    /* 2A230 80039A30 0800E003 */  jr         $ra
    /* 2A234 80039A34 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel SsVabClose
    /* 2A238 80039A38 00000000 */  nop
    /* 2A23C 80039A3C 00000000 */  nop
    /* 2A240 80039A40 00000000 */  nop
