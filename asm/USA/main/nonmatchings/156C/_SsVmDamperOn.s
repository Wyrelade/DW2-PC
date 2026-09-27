nonmatching _SsVmDamperOn, 0x10

glabel _SsVmDamperOn
    /* 26F74 80036774 02000224 */  addiu      $v0, $zero, 0x2
    /* 26F78 80036778 0680013C */  lui        $at, %hi(D_80062CB0)
    /* 26F7C 8003677C 0800E003 */  jr         $ra
    /* 26F80 80036780 B02C22A4 */   sh        $v0, %lo(D_80062CB0)($at)
endlabel _SsVmDamperOn
