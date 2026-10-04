nonmatching Stg40_ScrollFollow, 0x34

glabel Stg40_ScrollFollow
    /* 1DD4 80065134 0580023C */  lui        $v0, %hi(D_8005071C)
    /* 1DD8 80065138 1C07428C */  lw         $v0, %lo(D_8005071C)($v0)
    /* 1DDC 8006513C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1DE0 80065140 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1DE4 80065144 641044AC */  sw         $a0, 0x1064($v0)
    /* 1DE8 80065148 0780023C */  lui        $v0, %hi(Stg40_FloorTask)
    /* 1DEC 8006514C 682B448C */  lw         $a0, %lo(Stg40_FloorTask)($v0)
    /* 1DF0 80065150 7745000C */  jal        Task_SetState1
    /* 1DF4 80065154 21280000 */   addu      $a1, $zero, $zero
    /* 1DF8 80065158 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1DFC 8006515C 00000000 */  nop
    /* 1E00 80065160 0800E003 */  jr         $ra
    /* 1E04 80065164 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg40_ScrollFollow
