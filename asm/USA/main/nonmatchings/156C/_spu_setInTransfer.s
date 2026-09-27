nonmatching _spu_setInTransfer, 0x28

glabel _spu_setInTransfer
    /* 2D0C4 8003C8C4 01000224 */  addiu      $v0, $zero, 0x1
    /* 2D0C8 8003C8C8 04008214 */  bne        $a0, $v0, .L8003C8DC
    /* 2D0CC 8003C8CC 00000000 */   nop
    /* 2D0D0 8003C8D0 0580013C */  lui        $at, %hi(Spu_InTransfer)
    /* 2D0D4 8003C8D4 39F20008 */  j          .L8003C8E4
    /* 2D0D8 8003C8D8 5CFE20AC */   sw        $zero, %lo(Spu_InTransfer)($at)
  .L8003C8DC:
    /* 2D0DC 8003C8DC 0580013C */  lui        $at, %hi(Spu_InTransfer)
    /* 2D0E0 8003C8E0 5CFE22AC */  sw         $v0, %lo(Spu_InTransfer)($at)
  .L8003C8E4:
    /* 2D0E4 8003C8E4 0800E003 */  jr         $ra
    /* 2D0E8 8003C8E8 00000000 */   nop
endlabel _spu_setInTransfer
