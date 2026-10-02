nonmatching memclr_dma, 0x24

glabel memclr_dma
    /* 21FFC 800317FC 0600A010 */  beqz       $a1, .L80031818
    /* 22000 80031800 FFFFA224 */   addiu     $v0, $a1, -0x1
    /* 22004 80031804 FFFF0324 */  addiu      $v1, $zero, -0x1
  .L80031808:
    /* 22008 80031808 000080AC */  sw         $zero, 0x0($a0)
    /* 2200C 8003180C FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 22010 80031810 FDFF4314 */  bne        $v0, $v1, .L80031808
    /* 22014 80031814 04008424 */   addiu     $a0, $a0, 0x4
  .L80031818:
    /* 22018 80031818 0800E003 */  jr         $ra
    /* 2201C 8003181C 00000000 */   nop
endlabel memclr_dma
    /* 22020 80031820 00000000 */  nop
