nonmatching func_8006E588, 0x84

glabel func_8006E588
    /* B228 8006E588 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* B22C 8006E58C 1000B0AF */  sw         $s0, 0x10($sp)
    /* B230 8006E590 21808000 */  addu       $s0, $a0, $zero
    /* B234 8006E594 1400B1AF */  sw         $s1, 0x14($sp)
    /* B238 8006E598 21880000 */  addu       $s1, $zero, $zero
    /* B23C 8006E59C 1800BFAF */  sw         $ra, 0x18($sp)
    /* B240 8006E5A0 2000028E */  lw         $v0, 0x20($s0)
    /* B244 8006E5A4 00000000 */  nop
    /* B248 8006E5A8 01004224 */  addiu      $v0, $v0, 0x1
    /* B24C 8006E5AC 319E010C */  jal        func_800678C4
    /* B250 8006E5B0 200002AE */   sw        $v0, 0x20($s0)
    /* B254 8006E5B4 01000324 */  addiu      $v1, $zero, 0x1
    /* B258 8006E5B8 0D004310 */  beq        $v0, $v1, .L8006E5F0
    /* B25C 8006E5BC 00000000 */   nop
    /* B260 8006E5C0 2000048E */  lw         $a0, 0x20($s0)
    /* B264 8006E5C4 00000000 */  nop
    /* B268 8006E5C8 1F008228 */  slti       $v0, $a0, 0x1F
    /* B26C 8006E5CC 08004010 */  beqz       $v0, .L8006E5F0
    /* B270 8006E5D0 0B008228 */   slti      $v0, $a0, 0xB
    /* B274 8006E5D4 08004014 */  bnez       $v0, .L8006E5F8
    /* B278 8006E5D8 21102002 */   addu      $v0, $s1, $zero
    /* B27C 8006E5DC 0680023C */  lui        $v0, %hi(D_8005F704)
    /* B280 8006E5E0 04F7428C */  lw         $v0, %lo(D_8005F704)($v0)
    /* B284 8006E5E4 00000000 */  nop
    /* B288 8006E5E8 03004010 */  beqz       $v0, .L8006E5F8
    /* B28C 8006E5EC 21102002 */   addu      $v0, $s1, $zero
  .L8006E5F0:
    /* B290 8006E5F0 01001124 */  addiu      $s1, $zero, 0x1
    /* B294 8006E5F4 21102002 */  addu       $v0, $s1, $zero
  .L8006E5F8:
    /* B298 8006E5F8 1800BF8F */  lw         $ra, 0x18($sp)
    /* B29C 8006E5FC 1400B18F */  lw         $s1, 0x14($sp)
    /* B2A0 8006E600 1000B08F */  lw         $s0, 0x10($sp)
    /* B2A4 8006E604 0800E003 */  jr         $ra
    /* B2A8 8006E608 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8006E588
