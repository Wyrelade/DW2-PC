nonmatching strncpy, 0x70

glabel strncpy
    /* 31474 80040C74 19008010 */  beqz       $a0, .L80040CDC
    /* 31478 80040C78 21100000 */   addu      $v0, $zero, $zero
    /* 3147C 80040C7C 1700A010 */  beqz       $a1, .L80040CDC
    /* 31480 80040C80 21180000 */   addu      $v1, $zero, $zero
    /* 31484 80040C84 1400C018 */  blez       $a2, .L80040CD8
    /* 31488 80040C88 21388000 */   addu      $a3, $a0, $zero
  .L80040C8C:
    /* 3148C 80040C8C 0000A290 */  lbu        $v0, 0x0($a1)
    /* 31490 80040C90 0100A524 */  addiu      $a1, $a1, 0x1
    /* 31494 80040C94 000082A0 */  sb         $v0, 0x0($a0)
    /* 31498 80040C98 0B004014 */  bnez       $v0, .L80040CC8
    /* 3149C 80040C9C 01008424 */   addiu     $a0, $a0, 0x1
    /* 314A0 80040CA0 2D030108 */  j          .L80040CB4
    /* 314A4 80040CA4 01006324 */   addiu     $v1, $v1, 0x1
  .L80040CA8:
    /* 314A8 80040CA8 000080A0 */  sb         $zero, 0x0($a0)
    /* 314AC 80040CAC 01008424 */  addiu      $a0, $a0, 0x1
    /* 314B0 80040CB0 01006324 */  addiu      $v1, $v1, 0x1
  .L80040CB4:
    /* 314B4 80040CB4 2A106600 */  slt        $v0, $v1, $a2
    /* 314B8 80040CB8 FBFF4014 */  bnez       $v0, .L80040CA8
    /* 314BC 80040CBC 2110E000 */   addu      $v0, $a3, $zero
    /* 314C0 80040CC0 37030108 */  j          .L80040CDC
    /* 314C4 80040CC4 00000000 */   nop
  .L80040CC8:
    /* 314C8 80040CC8 01006324 */  addiu      $v1, $v1, 0x1
    /* 314CC 80040CCC 2A106600 */  slt        $v0, $v1, $a2
    /* 314D0 80040CD0 EEFF4014 */  bnez       $v0, .L80040C8C
    /* 314D4 80040CD4 00000000 */   nop
  .L80040CD8:
    /* 314D8 80040CD8 2110E000 */  addu       $v0, $a3, $zero
  .L80040CDC:
    /* 314DC 80040CDC 0800E003 */  jr         $ra
    /* 314E0 80040CE0 00000000 */   nop
endlabel strncpy
