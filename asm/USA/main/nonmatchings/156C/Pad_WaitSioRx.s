nonmatching Pad_WaitSioRx, 0x28

glabel Pad_WaitSioRx
    /* 16490 80025C90 0580033C */  lui        $v1, %hi(Pad_SioRegs)
    /* 16494 80025C94 908E638C */  lw         $v1, %lo(Pad_SioRegs)($v1)
    /* 16498 80025C98 00000000 */  nop
  .L80025C9C:
    /* 1649C 80025C9C 04006294 */  lhu        $v0, 0x4($v1)
    /* 164A0 80025CA0 00000000 */  nop
    /* 164A4 80025CA4 02004230 */  andi       $v0, $v0, 0x2
    /* 164A8 80025CA8 FCFF4010 */  beqz       $v0, .L80025C9C
    /* 164AC 80025CAC 00000000 */   nop
    /* 164B0 80025CB0 0800E003 */  jr         $ra
    /* 164B4 80025CB4 00000000 */   nop
endlabel Pad_WaitSioRx
