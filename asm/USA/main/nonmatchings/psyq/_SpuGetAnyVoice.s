nonmatching _SpuGetAnyVoice, 0x30

glabel _SpuGetAnyVoice
    /* 2BF14 8003B714 40280500 */  sll        $a1, $a1, 1
    /* 2BF18 8003B718 0580033C */  lui        $v1, %hi(D_8004FE28)
    /* 2BF1C 8003B71C 28FE638C */  lw         $v1, %lo(D_8004FE28)($v1)
    /* 2BF20 8003B720 40200400 */  sll        $a0, $a0, 1
    /* 2BF24 8003B724 2128A300 */  addu       $a1, $a1, $v1
    /* 2BF28 8003B728 21208300 */  addu       $a0, $a0, $v1
    /* 2BF2C 8003B72C 0000A294 */  lhu        $v0, 0x0($a1)
    /* 2BF30 8003B730 00008394 */  lhu        $v1, 0x0($a0)
    /* 2BF34 8003B734 FF004230 */  andi       $v0, $v0, 0xFF
    /* 2BF38 8003B738 00140200 */  sll        $v0, $v0, 16
    /* 2BF3C 8003B73C 0800E003 */  jr         $ra
    /* 2BF40 8003B740 25106200 */   or        $v0, $v1, $v0
endlabel _SpuGetAnyVoice
