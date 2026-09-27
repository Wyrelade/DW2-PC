nonmatching func_80070C94, 0x2C

glabel func_80070C94
    /* D934 80070C94 0580023C */  lui        $v0, %hi(D_8005071C)
    /* D938 80070C98 1C07438C */  lw         $v1, %lo(D_8005071C)($v0)
    /* D93C 80070C9C 00000000 */  nop
    /* D940 80070CA0 FC0F6324 */  addiu      $v1, $v1, 0xFFC
    /* D944 80070CA4 1A006284 */  lh         $v0, 0x1A($v1)
    /* D948 80070CA8 00000000 */  nop
    /* D94C 80070CAC 40100200 */  sll        $v0, $v0, 1
    /* D950 80070CB0 21186200 */  addu       $v1, $v1, $v0
    /* D954 80070CB4 00006284 */  lh         $v0, 0x0($v1)
    /* D958 80070CB8 0800E003 */  jr         $ra
    /* D95C 80070CBC 00000000 */   nop
endlabel func_80070C94
