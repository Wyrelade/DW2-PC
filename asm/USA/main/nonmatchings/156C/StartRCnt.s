nonmatching StartRCnt, 0x30

glabel StartRCnt
    /* 25C58 80035458 FFFF8230 */  andi       $v0, $a0, 0xFFFF
    /* 25C5C 8003545C 80200200 */  sll        $a0, $v0, 2
    /* 25C60 80035460 0580053C */  lui        $a1, %hi(D_8004FC68)
    /* 25C64 80035464 68FCA58C */  lw         $a1, %lo(D_8004FC68)($a1)
    /* 25C68 80035468 0580013C */  lui        $at, %hi(D_8004FC70)
    /* 25C6C 8003546C 21082400 */  addu       $at, $at, $a0
    /* 25C70 80035470 70FC248C */  lw         $a0, %lo(D_8004FC70)($at)
    /* 25C74 80035474 0400A38C */  lw         $v1, 0x4($a1)
    /* 25C78 80035478 03004228 */  slti       $v0, $v0, 0x3
    /* 25C7C 8003547C 25186400 */  or         $v1, $v1, $a0
    /* 25C80 80035480 0800E003 */  jr         $ra
    /* 25C84 80035484 0400A3AC */   sw        $v1, 0x4($a1)
endlabel StartRCnt
