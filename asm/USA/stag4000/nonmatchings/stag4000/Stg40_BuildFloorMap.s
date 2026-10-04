nonmatching Stg40_BuildFloorMap, 0x38

glabel Stg40_BuildFloorMap
    /* 69C 800639FC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6A0 80063A00 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6A4 80063A04 70C3010C */  jal        Stg40_ApplyFloorLayout
    /* 6A8 80063A08 00000000 */   nop
    /* 6AC 80063A0C B5BF010C */  jal        Stg40_AllocCellGrid
    /* 6B0 80063A10 00000000 */   nop
    /* 6B4 80063A14 F3BF010C */  jal        Stg40_FillCellGrid
    /* 6B8 80063A18 00000000 */   nop
    /* 6BC 80063A1C F4C1010C */  jal        Stg40_LabelRooms
    /* 6C0 80063A20 00000000 */   nop
    /* 6C4 80063A24 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6C8 80063A28 00000000 */  nop
    /* 6CC 80063A2C 0800E003 */  jr         $ra
    /* 6D0 80063A30 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg40_BuildFloorMap
