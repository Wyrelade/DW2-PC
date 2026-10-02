nonmatching memclr, 0x24

glabel memclr
    /* 21B70 80031370 0600A010 */  beqz       $a1, .L8003138C
    /* 21B74 80031374 FFFFA224 */   addiu     $v0, $a1, -0x1
    /* 21B78 80031378 FFFF0324 */  addiu      $v1, $zero, -0x1
  .L8003137C:
    /* 21B7C 8003137C 000080AC */  sw         $zero, 0x0($a0)
    /* 21B80 80031380 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 21B84 80031384 FDFF4314 */  bne        $v0, $v1, .L8003137C
    /* 21B88 80031388 04008424 */   addiu     $a0, $a0, 0x4
  .L8003138C:
    /* 21B8C 8003138C 0800E003 */  jr         $ra
    /* 21B90 80031390 00000000 */   nop
endlabel memclr
