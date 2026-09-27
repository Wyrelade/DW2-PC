nonmatching Task_NextState2, 0x18

glabel Task_NextState2
    /* 1D80 80011580 1800828C */  lw         $v0, 0x18($a0)
    /* 1D84 80011584 200080AC */  sw         $zero, 0x20($a0)
    /* 1D88 80011588 1C0080AC */  sw         $zero, 0x1C($a0)
    /* 1D8C 8001158C 01004224 */  addiu      $v0, $v0, 0x1
    /* 1D90 80011590 0800E003 */  jr         $ra
    /* 1D94 80011594 180082AC */   sw        $v0, 0x18($a0)
endlabel Task_NextState2
