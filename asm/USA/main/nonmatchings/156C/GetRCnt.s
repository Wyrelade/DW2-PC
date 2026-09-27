nonmatching GetRCnt, 0x38

glabel GetRCnt
    /* 25C20 80035420 FFFF8330 */  andi       $v1, $a0, 0xFFFF
    /* 25C24 80035424 03006228 */  slti       $v0, $v1, 0x3
    /* 25C28 80035428 08004010 */  beqz       $v0, .L8003544C
    /* 25C2C 8003542C 00190300 */   sll       $v1, $v1, 4
    /* 25C30 80035430 0580023C */  lui        $v0, %hi(Sys_RCntRegs)
    /* 25C34 80035434 6CFC428C */  lw         $v0, %lo(Sys_RCntRegs)($v0)
    /* 25C38 80035438 00000000 */  nop
    /* 25C3C 8003543C 21186200 */  addu       $v1, $v1, $v0
    /* 25C40 80035440 00006294 */  lhu        $v0, 0x0($v1)
    /* 25C44 80035444 14D50008 */  j          .L80035450
    /* 25C48 80035448 00000000 */   nop
  .L8003544C:
    /* 25C4C 8003544C 21100000 */  addu       $v0, $zero, $zero
  .L80035450:
    /* 25C50 80035450 0800E003 */  jr         $ra
    /* 25C54 80035454 00000000 */   nop
endlabel GetRCnt
