nonmatching Gfx_ReleaseTexSlot, 0x1C

glabel Gfx_ReleaseTexSlot
    /* D680 8001CE80 0000838C */  lw         $v1, 0x0($a0)
    /* D684 8001CE84 FEFF0224 */  addiu      $v0, $zero, -0x2
    /* D688 8001CE88 02006214 */  bne        $v1, $v0, .L8001CE94
    /* D68C 8001CE8C 00000000 */   nop
    /* D690 8001CE90 000080AC */  sw         $zero, 0x0($a0)
  .L8001CE94:
    /* D694 8001CE94 0800E003 */  jr         $ra
    /* D698 8001CE98 00000000 */   nop
endlabel Gfx_ReleaseTexSlot
