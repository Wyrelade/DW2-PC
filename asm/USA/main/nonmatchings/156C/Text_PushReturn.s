nonmatching Text_PushReturn, 0x2C

glabel Text_PushReturn
    /* B0F4 8001A8F4 0580033C */  lui        $v1, %hi(Text_ReturnStack)
    /* B0F8 8001A8F8 D04C628C */  lw         $v0, %lo(Text_ReturnStack)($v1)
    /* B0FC 8001A8FC D04C6524 */  addiu      $a1, $v1, %lo(Text_ReturnStack)
    /* B100 8001A900 80100200 */  sll        $v0, $v0, 2
    /* B104 8001A904 21104500 */  addu       $v0, $v0, $a1
    /* B108 8001A908 040044AC */  sw         $a0, 0x4($v0)
    /* B10C 8001A90C D04C628C */  lw         $v0, %lo(Text_ReturnStack)($v1)
    /* B110 8001A910 00000000 */  nop
    /* B114 8001A914 01004224 */  addiu      $v0, $v0, 0x1
    /* B118 8001A918 0800E003 */  jr         $ra
    /* B11C 8001A91C D04C62AC */   sw        $v0, %lo(Text_ReturnStack)($v1)
endlabel Text_PushReturn
