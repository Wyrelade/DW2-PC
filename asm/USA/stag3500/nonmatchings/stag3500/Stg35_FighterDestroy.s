nonmatching Stg35_FighterDestroy, 0x24

glabel Stg35_FighterDestroy
    /* 4064 800673C4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4068 800673C8 04000224 */  addiu      $v0, $zero, 0x4
    /* 406C 800673CC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 4070 800673D0 5C44000C */  jal        Task_DefaultDestroy
    /* 4074 800673D4 300082AC */   sw        $v0, 0x30($a0)
    /* 4078 800673D8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 407C 800673DC 00000000 */  nop
    /* 4080 800673E0 0800E003 */  jr         $ra
    /* 4084 800673E4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg35_FighterDestroy
