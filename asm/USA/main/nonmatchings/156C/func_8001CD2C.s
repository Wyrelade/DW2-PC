nonmatching func_8001CD2C, 0x7C

glabel func_8001CD2C
    /* D52C 8001CD2C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* D530 8001CD30 1800B2AF */  sw         $s2, 0x18($sp)
    /* D534 8001CD34 21908000 */  addu       $s2, $a0, $zero
    /* D538 8001CD38 1000B0AF */  sw         $s0, 0x10($sp)
    /* D53C 8001CD3C 21800000 */  addu       $s0, $zero, $zero
    /* D540 8001CD40 1400B1AF */  sw         $s1, 0x14($sp)
    /* D544 8001CD44 FFFF1124 */  addiu      $s1, $zero, -0x1
    /* D548 8001CD48 1C00BFAF */  sw         $ra, 0x1C($sp)
  .L8001CD4C:
    /* D54C 8001CD4C 8A72000C */  jal        Gfx_GetTexSlot
    /* D550 8001CD50 21200002 */   addu      $a0, $s0, $zero
    /* D554 8001CD54 21184000 */  addu       $v1, $v0, $zero
    /* D558 8001CD58 2A101202 */  slt        $v0, $s0, $s2
    /* D55C 8001CD5C 03004014 */  bnez       $v0, .L8001CD6C
    /* D560 8001CD60 00000000 */   nop
    /* D564 8001CD64 60730008 */  j          .L8001CD80
    /* D568 8001CD68 000071AC */   sw        $s1, 0x0($v1)
  .L8001CD6C:
    /* D56C 8001CD6C 0000628C */  lw         $v0, 0x0($v1)
    /* D570 8001CD70 00000000 */  nop
    /* D574 8001CD74 02005114 */  bne        $v0, $s1, .L8001CD80
    /* D578 8001CD78 00000000 */   nop
    /* D57C 8001CD7C 000060AC */  sw         $zero, 0x0($v1)
  .L8001CD80:
    /* D580 8001CD80 01001026 */  addiu      $s0, $s0, 0x1
    /* D584 8001CD84 4000022A */  slti       $v0, $s0, 0x40
    /* D588 8001CD88 F0FF4014 */  bnez       $v0, .L8001CD4C
    /* D58C 8001CD8C 00000000 */   nop
    /* D590 8001CD90 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* D594 8001CD94 1800B28F */  lw         $s2, 0x18($sp)
    /* D598 8001CD98 1400B18F */  lw         $s1, 0x14($sp)
    /* D59C 8001CD9C 1000B08F */  lw         $s0, 0x10($sp)
    /* D5A0 8001CDA0 0800E003 */  jr         $ra
    /* D5A4 8001CDA4 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8001CD2C
