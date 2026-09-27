nonmatching Task_NextState4, 0x14

glabel Task_NextState4
    /* 1DAC 800115AC 2000828C */  lw         $v0, 0x20($a0)
    /* 1DB0 800115B0 00000000 */  nop
    /* 1DB4 800115B4 01004224 */  addiu      $v0, $v0, 0x1
    /* 1DB8 800115B8 0800E003 */  jr         $ra
    /* 1DBC 800115BC 200082AC */   sw        $v0, 0x20($a0)
endlabel Task_NextState4
