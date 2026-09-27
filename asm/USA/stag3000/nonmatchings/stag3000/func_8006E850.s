nonmatching func_8006E850, 0x38

glabel func_8006E850
    /* B4F0 8006E850 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* B4F4 8006E854 1000BFAF */  sw         $ra, 0x10($sp)
    /* B4F8 8006E858 2C00838C */  lw         $v1, 0x2C($a0)
    /* B4FC 8006E85C 00000000 */  nop
    /* B500 8006E860 3400628C */  lw         $v0, 0x34($v1)
    /* B504 8006E864 00000000 */  nop
    /* B508 8006E868 03004510 */  beq        $v0, $a1, .L8006E878
    /* B50C 8006E86C 00000000 */   nop
    /* B510 8006E870 6A7C000C */  jal        Anim_SetModelAnim
    /* B514 8006E874 340065AC */   sw        $a1, 0x34($v1)
  .L8006E878:
    /* B518 8006E878 1000BF8F */  lw         $ra, 0x10($sp)
    /* B51C 8006E87C 00000000 */  nop
    /* B520 8006E880 0800E003 */  jr         $ra
    /* B524 8006E884 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006E850
