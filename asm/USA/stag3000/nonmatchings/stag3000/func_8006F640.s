nonmatching func_8006F640, 0x24

glabel func_8006F640
    /* C2E0 8006F640 2C00828C */  lw         $v0, 0x2C($a0)
    /* C2E4 8006F644 0400A010 */  beqz       $a1, .L8006F658
    /* C2E8 8006F648 280045AC */   sw        $a1, 0x28($v0)
    /* C2EC 8006F64C 05000224 */  addiu      $v0, $zero, 0x5
    /* C2F0 8006F650 0800E003 */  jr         $ra
    /* C2F4 8006F654 300082AC */   sw        $v0, 0x30($a0)
  .L8006F658:
    /* C2F8 8006F658 04000224 */  addiu      $v0, $zero, 0x4
    /* C2FC 8006F65C 0800E003 */  jr         $ra
    /* C300 8006F660 300082AC */   sw        $v0, 0x30($a0)
endlabel func_8006F640
