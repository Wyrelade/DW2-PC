nonmatching Stg30_FighterDestroy, 0x24

glabel Stg30_FighterDestroy
    /* C1D0 8006F530 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* C1D4 8006F534 05000224 */  addiu      $v0, $zero, 0x5
    /* C1D8 8006F538 1000BFAF */  sw         $ra, 0x10($sp)
    /* C1DC 8006F53C 5C44000C */  jal        Task_DefaultDestroy
    /* C1E0 8006F540 300082AC */   sw        $v0, 0x30($a0)
    /* C1E4 8006F544 1000BF8F */  lw         $ra, 0x10($sp)
    /* C1E8 8006F548 00000000 */  nop
    /* C1EC 8006F54C 0800E003 */  jr         $ra
    /* C1F0 8006F550 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg30_FighterDestroy
