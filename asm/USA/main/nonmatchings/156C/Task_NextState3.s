nonmatching Task_NextState3, 0x14

glabel Task_NextState3
    /* 1D98 80011598 1C00828C */  lw         $v0, 0x1C($a0)
    /* 1D9C 8001159C 200080AC */  sw         $zero, 0x20($a0)
    /* 1DA0 800115A0 01004224 */  addiu      $v0, $v0, 0x1
    /* 1DA4 800115A4 0800E003 */  jr         $ra
    /* 1DA8 800115A8 1C0082AC */   sw        $v0, 0x1C($a0)
endlabel Task_NextState3
