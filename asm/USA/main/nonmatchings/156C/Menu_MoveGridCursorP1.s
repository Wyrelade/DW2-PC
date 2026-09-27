nonmatching Menu_MoveGridCursorP1, 0x20

glabel Menu_MoveGridCursorP1
    /* 4210 80013A10 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4214 80013A14 1000BFAF */  sw         $ra, 0x10($sp)
    /* 4218 80013A18 304E000C */  jal        Menu_MoveGridCursor
    /* 421C 80013A1C 21300000 */   addu      $a2, $zero, $zero
    /* 4220 80013A20 1000BF8F */  lw         $ra, 0x10($sp)
    /* 4224 80013A24 00000000 */  nop
    /* 4228 80013A28 0800E003 */  jr         $ra
    /* 422C 80013A2C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Menu_MoveGridCursorP1
