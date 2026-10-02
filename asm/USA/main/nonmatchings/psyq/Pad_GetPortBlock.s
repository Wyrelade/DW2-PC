nonmatching Pad_GetPortBlock, 0x20

glabel Pad_GetPortBlock
    /* 15498 80024C98 0680023C */  lui        $v0, %hi(D_8005FDD8)
    /* 1549C 80024C9C D8FD4224 */  addiu      $v0, $v0, %lo(D_8005FDD8)
    /* 154A0 80024CA0 F0008430 */  andi       $a0, $a0, 0xF0
    /* 154A4 80024CA4 02008010 */  beqz       $a0, .L80024CB0
    /* 154A8 80024CA8 00000000 */   nop
    /* 154AC 80024CAC F0004224 */  addiu      $v0, $v0, 0xF0
  .L80024CB0:
    /* 154B0 80024CB0 0800E003 */  jr         $ra
    /* 154B4 80024CB4 00000000 */   nop
endlabel Pad_GetPortBlock
