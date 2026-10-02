nonmatching memclr_vb, 0x24

glabel memclr_vb
    /* 21D54 80031554 0600A010 */  beqz       $a1, .L80031570
    /* 21D58 80031558 FFFFA224 */   addiu     $v0, $a1, -0x1
    /* 21D5C 8003155C FFFF0324 */  addiu      $v1, $zero, -0x1
  .L80031560:
    /* 21D60 80031560 000080AC */  sw         $zero, 0x0($a0)
    /* 21D64 80031564 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 21D68 80031568 FDFF4314 */  bne        $v0, $v1, .L80031560
    /* 21D6C 8003156C 04008424 */   addiu     $a0, $a0, 0x4
  .L80031570:
    /* 21D70 80031570 0800E003 */  jr         $ra
    /* 21D74 80031574 00000000 */   nop
endlabel memclr_vb
    /* 21D78 80031578 00000000 */  nop
    /* 21D7C 8003157C 00000000 */  nop
    /* 21D80 80031580 00000000 */  nop
