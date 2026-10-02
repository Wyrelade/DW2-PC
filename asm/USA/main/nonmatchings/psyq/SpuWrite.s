nonmatching SpuWrite, 0x5C

glabel SpuWrite
    /* 2CF14 8003C714 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2CF18 8003C718 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2CF1C 8003C71C 2180A000 */  addu       $s0, $a1, $zero
    /* 2CF20 8003C720 0700023C */  lui        $v0, (0x7EFF0 >> 16)
    /* 2CF24 8003C724 F0EF4234 */  ori        $v0, $v0, (0x7EFF0 & 0xFFFF)
    /* 2CF28 8003C728 2B105000 */  sltu       $v0, $v0, $s0
    /* 2CF2C 8003C72C 03004010 */  beqz       $v0, .L8003C73C
    /* 2CF30 8003C730 1400BFAF */   sw        $ra, 0x14($sp)
    /* 2CF34 8003C734 0700103C */  lui        $s0, (0x7EFF0 >> 16)
    /* 2CF38 8003C738 F0EF1036 */  ori        $s0, $s0, (0x7EFF0 & 0xFFFF)
  .L8003C73C:
    /* 2CF3C 8003C73C 7EEA000C */  jal        _spu_Fw
    /* 2CF40 8003C740 21280002 */   addu      $a1, $s0, $zero
    /* 2CF44 8003C744 0580023C */  lui        $v0, %hi(D_8004FE60)
    /* 2CF48 8003C748 60FE428C */  lw         $v0, %lo(D_8004FE60)($v0)
    /* 2CF4C 8003C74C 00000000 */  nop
    /* 2CF50 8003C750 03004014 */  bnez       $v0, .L8003C760
    /* 2CF54 8003C754 21100002 */   addu      $v0, $s0, $zero
    /* 2CF58 8003C758 0580013C */  lui        $at, %hi(Spu_InTransfer)
    /* 2CF5C 8003C75C 5CFE20AC */  sw         $zero, %lo(Spu_InTransfer)($at)
  .L8003C760:
    /* 2CF60 8003C760 1400BF8F */  lw         $ra, 0x14($sp)
    /* 2CF64 8003C764 1000B08F */  lw         $s0, 0x10($sp)
    /* 2CF68 8003C768 0800E003 */  jr         $ra
    /* 2CF6C 8003C76C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel SpuWrite
    /* 2CF70 8003C770 00000000 */  nop
