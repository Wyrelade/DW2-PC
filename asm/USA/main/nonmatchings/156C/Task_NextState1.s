nonmatching Task_NextState1, 0x1C

glabel Task_NextState1
    /* 1D64 80011564 1400828C */  lw         $v0, 0x14($a0)
    /* 1D68 80011568 200080AC */  sw         $zero, 0x20($a0)
    /* 1D6C 8001156C 1C0080AC */  sw         $zero, 0x1C($a0)
    /* 1D70 80011570 180080AC */  sw         $zero, 0x18($a0)
    /* 1D74 80011574 01004224 */  addiu      $v0, $v0, 0x1
    /* 1D78 80011578 0800E003 */  jr         $ra
    /* 1D7C 8001157C 140082AC */   sw        $v0, 0x14($a0)
endlabel Task_NextState1
