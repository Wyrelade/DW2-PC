nonmatching Stg40_TurnQueueAdd, 0x78

glabel Stg40_TurnQueueAdd
    /* D7CC 80070B2C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* D7D0 80070B30 1400B1AF */  sw         $s1, 0x14($sp)
    /* D7D4 80070B34 21888000 */  addu       $s1, $a0, $zero
    /* D7D8 80070B38 0580023C */  lui        $v0, %hi(Dung_StatePtr)
    /* D7DC 80070B3C 00241100 */  sll        $a0, $s1, 16
    /* D7E0 80070B40 1C07428C */  lw         $v0, %lo(Dung_StatePtr)($v0)
    /* D7E4 80070B44 03240400 */  sra        $a0, $a0, 16
    /* D7E8 80070B48 1800BFAF */  sw         $ra, 0x18($sp)
    /* D7EC 80070B4C 1000B0AF */  sw         $s0, 0x10($sp)
    /* D7F0 80070B50 B4C2010C */  jal        Stg40_TurnQueueFind
    /* D7F4 80070B54 FC0F5024 */   addiu     $s0, $v0, 0xFFC
    /* D7F8 80070B58 0D004014 */  bnez       $v0, .L80070B90
    /* D7FC 80070B5C 00000000 */   nop
    /* D800 80070B60 16000386 */  lh         $v1, 0x16($s0)
    /* D804 80070B64 18000286 */  lh         $v0, 0x18($s0)
    /* D808 80070B68 00000000 */  nop
    /* D80C 80070B6C 2A106200 */  slt        $v0, $v1, $v0
    /* D810 80070B70 07004010 */  beqz       $v0, .L80070B90
    /* D814 80070B74 40100300 */   sll       $v0, $v1, 1
    /* D818 80070B78 21100202 */  addu       $v0, $s0, $v0
    /* D81C 80070B7C 000051A4 */  sh         $s1, 0x0($v0)
    /* D820 80070B80 16000296 */  lhu        $v0, 0x16($s0)
    /* D824 80070B84 00000000 */  nop
    /* D828 80070B88 01004224 */  addiu      $v0, $v0, 0x1
    /* D82C 80070B8C 160002A6 */  sh         $v0, 0x16($s0)
  .L80070B90:
    /* D830 80070B90 1800BF8F */  lw         $ra, 0x18($sp)
    /* D834 80070B94 1400B18F */  lw         $s1, 0x14($sp)
    /* D838 80070B98 1000B08F */  lw         $s0, 0x10($sp)
    /* D83C 80070B9C 0800E003 */  jr         $ra
    /* D840 80070BA0 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg40_TurnQueueAdd
