nonmatching Digi_GetDataFileId, 0x2C

glabel Digi_GetDataFileId
    /* EE7C 8001E67C 2C018228 */  slti       $v0, $a0, 0x12C
    /* EE80 8001E680 07004014 */  bnez       $v0, .L8001E6A0
    /* EE84 8001E684 B90C0224 */   addiu     $v0, $zero, 0xCB9
    /* EE88 8001E688 70FE8324 */  addiu      $v1, $a0, -0x190
    /* EE8C 8001E68C 6500632C */  sltiu      $v1, $v1, 0x65
    /* EE90 8001E690 03006014 */  bnez       $v1, .L8001E6A0
    /* EE94 8001E694 BB0C0224 */   addiu     $v0, $zero, 0xCBB
    /* EE98 8001E698 0800E003 */  jr         $ra
    /* EE9C 8001E69C BA0C0224 */   addiu     $v0, $zero, 0xCBA
  .L8001E6A0:
    /* EEA0 8001E6A0 0800E003 */  jr         $ra
    /* EEA4 8001E6A4 00000000 */   nop
endlabel Digi_GetDataFileId
