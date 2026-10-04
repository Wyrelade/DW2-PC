nonmatching Stg30_ShowPartyFighters, 0x80

glabel Stg30_ShowPartyFighters
    /* 41EC 8006754C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 41F0 80067550 1400B1AF */  sw         $s1, 0x14($sp)
    /* 41F4 80067554 21880000 */  addu       $s1, $zero, $zero
    /* 41F8 80067558 1800BFAF */  sw         $ra, 0x18($sp)
    /* 41FC 8006755C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 4200 80067560 3400908C */  lw         $s0, 0x34($a0)
  .L80067564:
    /* 4204 80067564 00000000 */  nop
    /* 4208 80067568 2C00048E */  lw         $a0, 0x2C($s0)
    /* 420C 8006756C 00000000 */  nop
    /* 4210 80067570 0C008010 */  beqz       $a0, .L800675A4
    /* 4214 80067574 0300222A */   slti      $v0, $s1, 0x3
    /* 4218 80067578 08004010 */  beqz       $v0, .L8006759C
    /* 421C 8006757C 00000000 */   nop
    /* 4220 80067580 90BD010C */  jal        Stg30_FighterSetVisible
    /* 4224 80067584 01000524 */   addiu     $a1, $zero, 0x1
    /* 4228 80067588 2C00048E */  lw         $a0, 0x2C($s0)
    /* 422C 8006758C 99BD010C */  jal        Stg30_FighterQueueHomeReset
    /* 4230 80067590 04001026 */   addiu     $s0, $s0, 0x4
    /* 4234 80067594 6B9D0108 */  j          .L800675AC
    /* 4238 80067598 01003126 */   addiu     $s1, $s1, 0x1
  .L8006759C:
    /* 423C 8006759C 90BD010C */  jal        Stg30_FighterSetVisible
    /* 4240 800675A0 21280000 */   addu      $a1, $zero, $zero
  .L800675A4:
    /* 4244 800675A4 04001026 */  addiu      $s0, $s0, 0x4
    /* 4248 800675A8 01003126 */  addiu      $s1, $s1, 0x1
  .L800675AC:
    /* 424C 800675AC 0600222A */  slti       $v0, $s1, 0x6
    /* 4250 800675B0 ECFF4014 */  bnez       $v0, .L80067564
    /* 4254 800675B4 00000000 */   nop
    /* 4258 800675B8 1800BF8F */  lw         $ra, 0x18($sp)
    /* 425C 800675BC 1400B18F */  lw         $s1, 0x14($sp)
    /* 4260 800675C0 1000B08F */  lw         $s0, 0x10($sp)
    /* 4264 800675C4 0800E003 */  jr         $ra
    /* 4268 800675C8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg30_ShowPartyFighters
