nonmatching Stg40_ScrollTo, 0x58

glabel Stg40_ScrollTo
    /* 1E08 80065168 0780023C */  lui        $v0, %hi(Stg40_FloorTask)
    /* 1E0C 8006516C 682B488C */  lw         $t0, %lo(Stg40_FloorTask)($v0)
    /* 1E10 80065170 0780023C */  lui        $v0, %hi(D_80072B60)
    /* 1E14 80065174 602B478C */  lw         $a3, %lo(D_80072B60)($v0)
    /* 1E18 80065178 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1E1C 8006517C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1E20 80065180 2C00038D */  lw         $v1, 0x2C($t0)
    /* 1E24 80065184 00000000 */  nop
    /* 1E28 80065188 901E64AC */  sw         $a0, 0x1E90($v1)
    /* 1E2C 8006518C 941E65AC */  sw         $a1, 0x1E94($v1)
    /* 1E30 80065190 2C00E28C */  lw         $v0, 0x2C($a3)
    /* 1E34 80065194 21200001 */  addu       $a0, $t0, $zero
    /* 1E38 80065198 981E62AC */  sw         $v0, 0x1E98($v1)
    /* 1E3C 8006519C 3000E28C */  lw         $v0, 0x30($a3)
    /* 1E40 800651A0 01000524 */  addiu      $a1, $zero, 0x1
    /* 1E44 800651A4 A01E66AC */  sw         $a2, 0x1EA0($v1)
    /* 1E48 800651A8 7745000C */  jal        Task_SetState1
    /* 1E4C 800651AC 9C1E62AC */   sw        $v0, 0x1E9C($v1)
    /* 1E50 800651B0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1E54 800651B4 00000000 */  nop
    /* 1E58 800651B8 0800E003 */  jr         $ra
    /* 1E5C 800651BC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg40_ScrollTo
