nonmatching CdSetDebug, 0x14

glabel CdSetDebug
    /* 20CB4 800304B4 0580023C */  lui        $v0, %hi(D_8004E6D0)
    /* 20CB8 800304B8 D0E6428C */  lw         $v0, %lo(D_8004E6D0)($v0)
    /* 20CBC 800304BC 0580013C */  lui        $at, %hi(D_8004E6D0)
    /* 20CC0 800304C0 0800E003 */  jr         $ra
    /* 20CC4 800304C4 D0E624AC */   sw        $a0, %lo(D_8004E6D0)($at)
endlabel CdSetDebug
    /* 20CC8 800304C8 00000000 */  nop
    /* 20CCC 800304CC 00000000 */  nop
    /* 20CD0 800304D0 00000000 */  nop
