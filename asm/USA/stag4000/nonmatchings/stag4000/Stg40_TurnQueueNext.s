nonmatching Stg40_TurnQueueNext, 0x4C

glabel Stg40_TurnQueueNext
    /* D8E8 80070C48 0580023C */  lui        $v0, %hi(D_8005071C)
    /* D8EC 80070C4C 1C07428C */  lw         $v0, %lo(D_8005071C)($v0)
    /* D8F0 80070C50 00000000 */  nop
    /* D8F4 80070C54 FC0F4424 */  addiu      $a0, $v0, 0xFFC
    /* D8F8 80070C58 1A008284 */  lh         $v0, 0x1A($a0)
    /* D8FC 80070C5C 16008384 */  lh         $v1, 0x16($a0)
    /* D900 80070C60 01004224 */  addiu      $v0, $v0, 0x1
    /* D904 80070C64 2A104300 */  slt        $v0, $v0, $v1
    /* D908 80070C68 1A008394 */  lhu        $v1, 0x1A($a0)
    /* D90C 80070C6C 02004014 */  bnez       $v0, .L80070C78
    /* D910 80070C70 01006224 */   addiu     $v0, $v1, 0x1
    /* D914 80070C74 21100000 */  addu       $v0, $zero, $zero
  .L80070C78:
    /* D918 80070C78 1A0082A4 */  sh         $v0, 0x1A($a0)
    /* D91C 80070C7C 00140200 */  sll        $v0, $v0, 16
    /* D920 80070C80 C3130200 */  sra        $v0, $v0, 15
    /* D924 80070C84 21108200 */  addu       $v0, $a0, $v0
    /* D928 80070C88 00004284 */  lh         $v0, 0x0($v0)
    /* D92C 80070C8C 0800E003 */  jr         $ra
    /* D930 80070C90 00000000 */   nop
endlabel Stg40_TurnQueueNext
