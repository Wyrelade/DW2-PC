nonmatching _SsVmDamperOff, 0xC

glabel _SsVmDamperOff
    /* 26F64 80036764 0680013C */  lui        $at, %hi(D_80062CB0)
    /* 26F68 80036768 0800E003 */  jr         $ra
    /* 26F6C 8003676C B02C20A4 */   sh        $zero, %lo(D_80062CB0)($at)
endlabel _SsVmDamperOff
    /* 26F70 80036770 00000000 */  nop
