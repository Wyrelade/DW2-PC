nonmatching Task_NextState0, 0x20

glabel Task_NextState0
    /* 1D44 80011544 1000828C */  lw         $v0, 0x10($a0)
    /* 1D48 80011548 200080AC */  sw         $zero, 0x20($a0)
    /* 1D4C 8001154C 1C0080AC */  sw         $zero, 0x1C($a0)
    /* 1D50 80011550 180080AC */  sw         $zero, 0x18($a0)
    /* 1D54 80011554 140080AC */  sw         $zero, 0x14($a0)
    /* 1D58 80011558 01004224 */  addiu      $v0, $v0, 0x1
    /* 1D5C 8001155C 0800E003 */  jr         $ra
    /* 1D60 80011560 100082AC */   sw        $v0, 0x10($a0)
endlabel Task_NextState0
