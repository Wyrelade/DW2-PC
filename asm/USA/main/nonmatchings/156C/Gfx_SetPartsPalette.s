nonmatching Gfx_SetPartsPalette, 0x44

glabel Gfx_SetPartsPalette
    /* 3FB8 800137B8 0000828C */  lw         $v0, 0x0($a0)
    /* 3FBC 800137BC 00000000 */  nop
    /* 3FC0 800137C0 0C004010 */  beqz       $v0, .L800137F4
    /* 3FC4 800137C4 0C008324 */   addiu     $v1, $a0, 0xC
  .L800137C8:
    /* 3FC8 800137C8 1000628C */  lw         $v0, 0x10($v1)
    /* 3FCC 800137CC 00000000 */  nop
    /* 3FD0 800137D0 24104500 */  and        $v0, $v0, $a1
    /* 3FD4 800137D4 02004010 */  beqz       $v0, .L800137E0
    /* 3FD8 800137D8 00000000 */   nop
    /* 3FDC 800137DC 000066A0 */  sb         $a2, 0x0($v1)
  .L800137E0:
    /* 3FE0 800137E0 28008424 */  addiu      $a0, $a0, 0x28
    /* 3FE4 800137E4 0000828C */  lw         $v0, 0x0($a0)
    /* 3FE8 800137E8 00000000 */  nop
    /* 3FEC 800137EC F6FF4014 */  bnez       $v0, .L800137C8
    /* 3FF0 800137F0 28006324 */   addiu     $v1, $v1, 0x28
  .L800137F4:
    /* 3FF4 800137F4 0800E003 */  jr         $ra
    /* 3FF8 800137F8 00000000 */   nop
endlabel Gfx_SetPartsPalette
