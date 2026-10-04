nonmatching Stg11_CardGetResult, 0x20

glabel Stg11_CardGetResult
    /* 44B8 80067818 0780023C */  lui        $v0, %hi(Stg11_CardTask)
    /* 44BC 8006781C D085428C */  lw         $v0, %lo(Stg11_CardTask)($v0)
    /* 44C0 80067820 00000000 */  nop
    /* 44C4 80067824 2C00428C */  lw         $v0, 0x2C($v0)
    /* 44C8 80067828 00000000 */  nop
    /* 44CC 8006782C 0400428C */  lw         $v0, 0x4($v0)
    /* 44D0 80067830 0800E003 */  jr         $ra
    /* 44D4 80067834 00000000 */   nop
endlabel Stg11_CardGetResult
