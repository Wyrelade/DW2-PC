nonmatching func_8006F674, 0x28

glabel func_8006F674
    /* C314 8006F674 0000A28C */  lw         $v0, 0x0($a1)
    /* C318 8006F678 00000000 */  nop
    /* C31C 8006F67C 080082AC */  sw         $v0, 0x8($a0)
    /* C320 8006F680 0400A28C */  lw         $v0, 0x4($a1)
    /* C324 8006F684 00000000 */  nop
    /* C328 8006F688 02004010 */  beqz       $v0, .L8006F694
    /* C32C 8006F68C 04000324 */   addiu     $v1, $zero, 0x4
    /* C330 8006F690 02000324 */  addiu      $v1, $zero, 0x2
  .L8006F694:
    /* C334 8006F694 0800E003 */  jr         $ra
    /* C338 8006F698 040083AC */   sw        $v1, 0x4($a0)
endlabel func_8006F674
