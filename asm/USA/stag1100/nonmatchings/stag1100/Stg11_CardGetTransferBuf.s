nonmatching Stg11_CardGetTransferBuf, 0x18

glabel Stg11_CardGetTransferBuf
    /* 43AC 8006770C 0780023C */  lui        $v0, %hi(Stg11_CardTask)
    /* 43B0 80067710 D085428C */  lw         $v0, %lo(Stg11_CardTask)($v0)
    /* 43B4 80067714 00000000 */  nop
    /* 43B8 80067718 2C00428C */  lw         $v0, 0x2C($v0)
    /* 43BC 8006771C 0800E003 */  jr         $ra
    /* 43C0 80067720 34404224 */   addiu     $v0, $v0, 0x4034
endlabel Stg11_CardGetTransferBuf
