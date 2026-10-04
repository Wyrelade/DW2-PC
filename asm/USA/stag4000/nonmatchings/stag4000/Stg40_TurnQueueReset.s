nonmatching Stg40_TurnQueueReset, 0x54

glabel Stg40_TurnQueueReset
    /* D71C 80070A7C 0580023C */  lui        $v0, %hi(D_8005071C)
    /* D720 80070A80 1C07428C */  lw         $v0, %lo(D_8005071C)($v0)
    /* D724 80070A84 21200000 */  addu       $a0, $zero, $zero
    /* D728 80070A88 FC0F4324 */  addiu      $v1, $v0, 0xFFC
    /* D72C 80070A8C 0A000224 */  addiu      $v0, $zero, 0xA
    /* D730 80070A90 180062A4 */  sh         $v0, 0x18($v1)
    /* D734 80070A94 18006284 */  lh         $v0, 0x18($v1)
    /* D738 80070A98 21286000 */  addu       $a1, $v1, $zero
    /* D73C 80070A9C 160060A4 */  sh         $zero, 0x16($v1)
    /* D740 80070AA0 08004018 */  blez       $v0, .L80070AC4
    /* D744 80070AA4 1A0060A4 */   sh        $zero, 0x1A($v1)
    /* D748 80070AA8 FFFF0624 */  addiu      $a2, $zero, -0x1
  .L80070AAC:
    /* D74C 80070AAC 000066A4 */  sh         $a2, 0x0($v1)
    /* D750 80070AB0 1800A284 */  lh         $v0, 0x18($a1)
    /* D754 80070AB4 01008424 */  addiu      $a0, $a0, 0x1
    /* D758 80070AB8 2A108200 */  slt        $v0, $a0, $v0
    /* D75C 80070ABC FBFF4014 */  bnez       $v0, .L80070AAC
    /* D760 80070AC0 02006324 */   addiu     $v1, $v1, 0x2
  .L80070AC4:
    /* D764 80070AC4 FEFF0224 */  addiu      $v0, $zero, -0x2
    /* D768 80070AC8 0800E003 */  jr         $ra
    /* D76C 80070ACC 000062A4 */   sh        $v0, 0x0($v1)
endlabel Stg40_TurnQueueReset
