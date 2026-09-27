nonmatching SpuGetVoiceEnvelope, 0x1C

glabel SpuGetVoiceEnvelope
    /* 2D904 8003D104 0580023C */  lui        $v0, %hi(D_8004FE28)
    /* 2D908 8003D108 28FE428C */  lw         $v0, %lo(D_8004FE28)($v0)
    /* 2D90C 8003D10C 00210400 */  sll        $a0, $a0, 4
    /* 2D910 8003D110 21208200 */  addu       $a0, $a0, $v0
    /* 2D914 8003D114 0C008294 */  lhu        $v0, 0xC($a0)
    /* 2D918 8003D118 0800E003 */  jr         $ra
    /* 2D91C 8003D11C 0000A2A4 */   sh        $v0, 0x0($a1)
endlabel SpuGetVoiceEnvelope
    /* 2D920 8003D120 00000000 */  nop
