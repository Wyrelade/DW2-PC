nonmatching _spu_getInTransfer, 0x18

glabel _spu_getInTransfer
    /* 2D0EC 8003C8EC 0580023C */  lui        $v0, %hi(Spu_InTransfer)
    /* 2D0F0 8003C8F0 5CFE428C */  lw         $v0, %lo(Spu_InTransfer)($v0)
    /* 2D0F4 8003C8F4 00000000 */  nop
    /* 2D0F8 8003C8F8 01004238 */  xori       $v0, $v0, 0x1
    /* 2D0FC 8003C8FC 0800E003 */  jr         $ra
    /* 2D100 8003C900 2B100200 */   sltu      $v0, $zero, $v0
endlabel _spu_getInTransfer
