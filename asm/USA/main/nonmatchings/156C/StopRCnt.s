nonmatching StopRCnt, 0x34

glabel StopRCnt
    /* 25C88 80035488 FFFF8430 */  andi       $a0, $a0, 0xFFFF
    /* 25C8C 8003548C 80200400 */  sll        $a0, $a0, 2
    /* 25C90 80035490 0580053C */  lui        $a1, %hi(D_8004FC68)
    /* 25C94 80035494 68FCA58C */  lw         $a1, %lo(D_8004FC68)($a1)
    /* 25C98 80035498 0580023C */  lui        $v0, %hi(D_8004FC70)
    /* 25C9C 8003549C 21104400 */  addu       $v0, $v0, $a0
    /* 25CA0 800354A0 70FC428C */  lw         $v0, %lo(D_8004FC70)($v0)
    /* 25CA4 800354A4 0400A38C */  lw         $v1, 0x4($a1)
    /* 25CA8 800354A8 27100200 */  nor        $v0, $zero, $v0
    /* 25CAC 800354AC 24186200 */  and        $v1, $v1, $v0
    /* 25CB0 800354B0 01000224 */  addiu      $v0, $zero, 0x1
    /* 25CB4 800354B4 0800E003 */  jr         $ra
    /* 25CB8 800354B8 0400A3AC */   sw        $v1, 0x4($a1)
endlabel StopRCnt
