nonmatching SpuSetTransferMode, 0x30

glabel SpuSetTransferMode
    /* 2CFD4 8003C7D4 05008010 */  beqz       $a0, .L8003C7EC
    /* 2CFD8 8003C7D8 01000224 */   addiu     $v0, $zero, 0x1
    /* 2CFDC 8003C7DC 04008214 */  bne        $a0, $v0, .L8003C7F0
    /* 2CFE0 8003C7E0 21100000 */   addu      $v0, $zero, $zero
    /* 2CFE4 8003C7E4 FCF10008 */  j          .L8003C7F0
    /* 2CFE8 8003C7E8 01000224 */   addiu     $v0, $zero, 0x1
  .L8003C7EC:
    /* 2CFEC 8003C7EC 21100000 */  addu       $v0, $zero, $zero
  .L8003C7F0:
    /* 2CFF0 8003C7F0 0580013C */  lui        $at, %hi(D_8004FDB8)
    /* 2CFF4 8003C7F4 B8FD24AC */  sw         $a0, %lo(D_8004FDB8)($at)
    /* 2CFF8 8003C7F8 0580013C */  lui        $at, %hi(D_8004FE44)
    /* 2CFFC 8003C7FC 0800E003 */  jr         $ra
    /* 2D000 8003C800 44FE22AC */   sw        $v0, %lo(D_8004FE44)($at)
endlabel SpuSetTransferMode
