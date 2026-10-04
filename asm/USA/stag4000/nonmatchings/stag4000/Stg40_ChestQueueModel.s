nonmatching Stg40_ChestQueueModel, 0x80

glabel Stg40_ChestQueueModel
    /* 946C 8006C7CC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 9470 8006C7D0 0500A22C */  sltiu      $v0, $a1, 0x5
    /* 9474 8006C7D4 09004010 */  beqz       $v0, .L8006C7FC
    /* 9478 8006C7D8 1000BFAF */   sw        $ra, 0x10($sp)
    /* 947C 8006C7DC 0680023C */  lui        $v0, %hi(jtbl_8006351C)
    /* 9480 8006C7E0 1C354224 */  addiu      $v0, $v0, %lo(jtbl_8006351C)
    /* 9484 8006C7E4 80180500 */  sll        $v1, $a1, 2
    /* 9488 8006C7E8 21186200 */  addu       $v1, $v1, $v0
    /* 948C 8006C7EC 0000628C */  lw         $v0, 0x0($v1)
    /* 9490 8006C7F0 00000000 */  nop
    /* 9494 8006C7F4 08004000 */  jr         $v0
    /* 9498 8006C7F8 00000000 */   nop
  jlabel .L8006C7FC
    /* 949C 8006C7FC E30D0524 */  addiu      $a1, $zero, 0xDE3
    /* 94A0 8006C800 0DB20108 */  j          .L8006C834
    /* 94A4 8006C804 E20D0624 */   addiu     $a2, $zero, 0xDE2
  jlabel .L8006C808
    /* 94A8 8006C808 E10D0524 */  addiu      $a1, $zero, 0xDE1
    /* 94AC 8006C80C 0DB20108 */  j          .L8006C834
    /* 94B0 8006C810 DE0D0624 */   addiu     $a2, $zero, 0xDDE
  jlabel .L8006C814
    /* 94B4 8006C814 DF0D0524 */  addiu      $a1, $zero, 0xDDF
    /* 94B8 8006C818 0DB20108 */  j          .L8006C834
    /* 94BC 8006C81C E00D0624 */   addiu     $a2, $zero, 0xDE0
  jlabel .L8006C820
    /* 94C0 8006C820 E40D0524 */  addiu      $a1, $zero, 0xDE4
    /* 94C4 8006C824 0DB20108 */  j          .L8006C834
    /* 94C8 8006C828 E50D0624 */   addiu     $a2, $zero, 0xDE5
  jlabel .L8006C82C
    /* 94CC 8006C82C DC0D0524 */  addiu      $a1, $zero, 0xDDC
    /* 94D0 8006C830 DD0D0624 */  addiu      $a2, $zero, 0xDDD
  .L8006C834:
    /* 94D4 8006C834 D9B9010C */  jal        Stg40_ObjQueueFiles
    /* 94D8 8006C838 00000000 */   nop
    /* 94DC 8006C83C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 94E0 8006C840 00000000 */  nop
    /* 94E4 8006C844 0800E003 */  jr         $ra
    /* 94E8 8006C848 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg40_ChestQueueModel
