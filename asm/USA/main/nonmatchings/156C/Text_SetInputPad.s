nonmatching Text_SetInputPad, 0x70

glabel Text_SetInputPad
    /* C6E8 8001BEE8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* C6EC 8001BEEC 1000B0AF */  sw         $s0, 0x10($sp)
    /* C6F0 8001BEF0 21808000 */  addu       $s0, $a0, $zero
    /* C6F4 8001BEF4 1400B1AF */  sw         $s1, 0x14($sp)
    /* C6F8 8001BEF8 2188A000 */  addu       $s1, $a1, $zero
    /* C6FC 8001BEFC 09000424 */  addiu      $a0, $zero, 0x9
    /* C700 8001BF00 FFFF0524 */  addiu      $a1, $zero, -0x1
    /* C704 8001BF04 1800BFAF */  sw         $ra, 0x18($sp)
    /* C708 8001BF08 4445000C */  jal        Task_FindFirst
    /* C70C 8001BF0C 2130A000 */   addu      $a2, $a1, $zero
    /* C710 8001BF10 21184000 */  addu       $v1, $v0, $zero
    /* C714 8001BF14 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* C718 8001BF18 0A000212 */  beq        $s0, $v0, .L8001BF44
    /* C71C 8001BF1C 00000000 */   nop
    /* C720 8001BF20 08006010 */  beqz       $v1, .L8001BF44
    /* C724 8001BF24 40101000 */   sll       $v0, $s0, 1
    /* C728 8001BF28 21105000 */  addu       $v0, $v0, $s0
    /* C72C 8001BF2C 80100200 */  sll        $v0, $v0, 2
    /* C730 8001BF30 21105000 */  addu       $v0, $v0, $s0
    /* C734 8001BF34 2C00638C */  lw         $v1, 0x2C($v1)
    /* C738 8001BF38 80100200 */  sll        $v0, $v0, 2
    /* C73C 8001BF3C 21186200 */  addu       $v1, $v1, $v0
    /* C740 8001BF40 300071A0 */  sb         $s1, 0x30($v1)
  .L8001BF44:
    /* C744 8001BF44 1800BF8F */  lw         $ra, 0x18($sp)
    /* C748 8001BF48 1400B18F */  lw         $s1, 0x14($sp)
    /* C74C 8001BF4C 1000B08F */  lw         $s0, 0x10($sp)
    /* C750 8001BF50 0800E003 */  jr         $ra
    /* C754 8001BF54 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Text_SetInputPad
