nonmatching ResetRCnt, 0x34

glabel ResetRCnt
    /* 25CBC 800354BC FFFF8330 */  andi       $v1, $a0, 0xFFFF
    /* 25CC0 800354C0 03006228 */  slti       $v0, $v1, 0x3
    /* 25CC4 800354C4 07004010 */  beqz       $v0, .L800354E4
    /* 25CC8 800354C8 01000224 */   addiu     $v0, $zero, 0x1
    /* 25CCC 800354CC 0580043C */  lui        $a0, %hi(Sys_RCntRegs)
    /* 25CD0 800354D0 6CFC848C */  lw         $a0, %lo(Sys_RCntRegs)($a0)
    /* 25CD4 800354D4 00190300 */  sll        $v1, $v1, 4
    /* 25CD8 800354D8 21186400 */  addu       $v1, $v1, $a0
    /* 25CDC 800354DC 3AD50008 */  j          .L800354E8
    /* 25CE0 800354E0 000060A4 */   sh        $zero, 0x0($v1)
  .L800354E4:
    /* 25CE4 800354E4 21100000 */  addu       $v0, $zero, $zero
  .L800354E8:
    /* 25CE8 800354E8 0800E003 */  jr         $ra
    /* 25CEC 800354EC 00000000 */   nop
endlabel ResetRCnt
    /* 25CF0 800354F0 00000000 */  nop
