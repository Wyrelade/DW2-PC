nonmatching func_8006E520, 0x68

glabel func_8006E520
    /* B1C0 8006E520 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* B1C4 8006E524 1000B0AF */  sw         $s0, 0x10($sp)
    /* B1C8 8006E528 21808000 */  addu       $s0, $a0, $zero
    /* B1CC 8006E52C 1400B1AF */  sw         $s1, 0x14($sp)
    /* B1D0 8006E530 21880000 */  addu       $s1, $zero, $zero
    /* B1D4 8006E534 1800BFAF */  sw         $ra, 0x18($sp)
    /* B1D8 8006E538 2000028E */  lw         $v0, 0x20($s0)
    /* B1DC 8006E53C 00000000 */  nop
    /* B1E0 8006E540 01004224 */  addiu      $v0, $v0, 0x1
    /* B1E4 8006E544 319E010C */  jal        func_800678C4
    /* B1E8 8006E548 200002AE */   sw        $v0, 0x20($s0)
    /* B1EC 8006E54C 01000324 */  addiu      $v1, $zero, 0x1
    /* B1F0 8006E550 06004310 */  beq        $v0, $v1, .L8006E56C
    /* B1F4 8006E554 00000000 */   nop
    /* B1F8 8006E558 2000028E */  lw         $v0, 0x20($s0)
    /* B1FC 8006E55C 00000000 */  nop
    /* B200 8006E560 1F004228 */  slti       $v0, $v0, 0x1F
    /* B204 8006E564 03004014 */  bnez       $v0, .L8006E574
    /* B208 8006E568 21102002 */   addu      $v0, $s1, $zero
  .L8006E56C:
    /* B20C 8006E56C 01001124 */  addiu      $s1, $zero, 0x1
    /* B210 8006E570 21102002 */  addu       $v0, $s1, $zero
  .L8006E574:
    /* B214 8006E574 1800BF8F */  lw         $ra, 0x18($sp)
    /* B218 8006E578 1400B18F */  lw         $s1, 0x14($sp)
    /* B21C 8006E57C 1000B08F */  lw         $s0, 0x10($sp)
    /* B220 8006E580 0800E003 */  jr         $ra
    /* B224 8006E584 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8006E520
