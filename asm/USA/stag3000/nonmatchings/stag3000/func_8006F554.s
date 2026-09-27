nonmatching func_8006F554, 0xEC

glabel func_8006F554
    /* C1F4 8006F554 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* C1F8 8006F558 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* C1FC 8006F55C 21888000 */  addu       $s1, $a0, $zero
    /* C200 8006F560 2000BFAF */  sw         $ra, 0x20($sp)
    /* C204 8006F564 1800B0AF */  sw         $s0, 0x18($sp)
    /* C208 8006F568 2C00308E */  lw         $s0, 0x2C($s1)
    /* C20C 8006F56C 00000000 */  nop
    /* C210 8006F570 2800028E */  lw         $v0, 0x28($s0)
    /* C214 8006F574 00000000 */  nop
    /* C218 8006F578 2C004010 */  beqz       $v0, .L8006F62C
    /* C21C 8006F57C 00000000 */   nop
    /* C220 8006F580 1400058E */  lw         $a1, 0x14($s0)
    /* C224 8006F584 6F7F000C */  jal        Gfx_AttachModel
    /* C228 8006F588 00000000 */   nop
    /* C22C 8006F58C C87C000C */  jal        Anim_StepModelAnim
    /* C230 8006F590 21202002 */   addu      $a0, $s1, $zero
    /* C234 8006F594 4882000C */  jal        Actor_UpdateTransform
    /* C238 8006F598 21202002 */   addu      $a0, $s1, $zero
    /* C23C 8006F59C 3480000C */  jal        Gfx_CalcModelBoneMatrices
    /* C240 8006F5A0 21202002 */   addu      $a0, $s1, $zero
    /* C244 8006F5A4 1800028E */  lw         $v0, 0x18($s0)
    /* C248 8006F5A8 00000000 */  nop
    /* C24C 8006F5AC 03004010 */  beqz       $v0, .L8006F5BC
    /* C250 8006F5B0 21202002 */   addu      $a0, $s1, $zero
    /* C254 8006F5B4 4481000C */  jal        Gfx_DrawTexModel
    /* C258 8006F5B8 21280000 */   addu      $a1, $zero, $zero
  .L8006F5BC:
    /* C25C 8006F5BC 1C00028E */  lw         $v0, 0x1C($s0)
    /* C260 8006F5C0 00000000 */  nop
    /* C264 8006F5C4 19004010 */  beqz       $v0, .L8006F62C
    /* C268 8006F5C8 00000000 */   nop
    /* C26C 8006F5CC 0800228E */  lw         $v0, 0x8($s1)
    /* C270 8006F5D0 00000000 */  nop
    /* C274 8006F5D4 03004228 */  slti       $v0, $v0, 0x3
    /* C278 8006F5D8 08004010 */  beqz       $v0, .L8006F5FC
    /* C27C 8006F5DC 21202002 */   addu      $a0, $s1, $zero
    /* C280 8006F5E0 2300038A */  lwl        $v1, 0x23($s0)
    /* C284 8006F5E4 2000039A */  lwr        $v1, 0x20($s0)
    /* C288 8006F5E8 00000000 */  nop
    /* C28C 8006F5EC 1300A3AB */  swl        $v1, 0x13($sp)
    /* C290 8006F5F0 1000A3BB */  swr        $v1, 0x10($sp)
    /* C294 8006F5F4 89BD0108 */  j          .L8006F624
    /* C298 8006F5F8 21280000 */   addu      $a1, $zero, $zero
  .L8006F5FC:
    /* C29C 8006F5FC 21000292 */  lbu        $v0, 0x21($s0)
    /* C2A0 8006F600 00000000 */  nop
    /* C2A4 8006F604 1000A2A3 */  sb         $v0, 0x10($sp)
    /* C2A8 8006F608 20000292 */  lbu        $v0, 0x20($s0)
    /* C2AC 8006F60C 00000000 */  nop
    /* C2B0 8006F610 1100A2A3 */  sb         $v0, 0x11($sp)
    /* C2B4 8006F614 22000292 */  lbu        $v0, 0x22($s0)
    /* C2B8 8006F618 00000000 */  nop
    /* C2BC 8006F61C 1200A2A3 */  sb         $v0, 0x12($sp)
    /* C2C0 8006F620 21280000 */  addu       $a1, $zero, $zero
  .L8006F624:
    /* C2C4 8006F624 DA81000C */  jal        Gfx_DrawWireModel
    /* C2C8 8006F628 1000A627 */   addiu     $a2, $sp, 0x10
  .L8006F62C:
    /* C2CC 8006F62C 2000BF8F */  lw         $ra, 0x20($sp)
    /* C2D0 8006F630 1C00B18F */  lw         $s1, 0x1C($sp)
    /* C2D4 8006F634 1800B08F */  lw         $s0, 0x18($sp)
    /* C2D8 8006F638 0800E003 */  jr         $ra
    /* C2DC 8006F63C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8006F554
