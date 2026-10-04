nonmatching Stg35_PrepareAction, 0x20

glabel Stg35_PrepareAction
    /* 64F0 80069850 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 64F4 80069854 1000BFAF */  sw         $ra, 0x10($sp)
    /* 64F8 80069858 9BA4010C */  jal        Stg35_BuildSkillScript
    /* 64FC 8006985C 00000000 */   nop
    /* 6500 80069860 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6504 80069864 01000224 */  addiu      $v0, $zero, 0x1
    /* 6508 80069868 0800E003 */  jr         $ra
    /* 650C 8006986C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg35_PrepareAction
