nonmatching func_800651C0, 0x70

glabel func_800651C0
    /* 1E60 800651C0 0780023C */  lui        $v0, %hi(D_80072B68)
    /* 1E64 800651C4 682B488C */  lw         $t0, %lo(D_80072B68)($v0)
    /* 1E68 800651C8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1E6C 800651CC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1E70 800651D0 0C00828C */  lw         $v0, 0xC($a0)
    /* 1E74 800651D4 2C00068D */  lw         $a2, 0x2C($t0)
    /* 1E78 800651D8 00000000 */  nop
    /* 1E7C 800651DC 901EC2AC */  sw         $v0, 0x1E90($a2)
    /* 1E80 800651E0 0780023C */  lui        $v0, %hi(D_80072B60)
    /* 1E84 800651E4 1000838C */  lw         $v1, 0x10($a0)
    /* 1E88 800651E8 602B478C */  lw         $a3, %lo(D_80072B60)($v0)
    /* 1E8C 800651EC 941EC3AC */  sw         $v1, 0x1E94($a2)
    /* 1E90 800651F0 2C00E28C */  lw         $v0, 0x2C($a3)
    /* 1E94 800651F4 00000000 */  nop
    /* 1E98 800651F8 981EC2AC */  sw         $v0, 0x1E98($a2)
    /* 1E9C 800651FC 0580023C */  lui        $v0, %hi(D_8005071C)
    /* 1EA0 80065200 3000E38C */  lw         $v1, 0x30($a3)
    /* 1EA4 80065204 1C07428C */  lw         $v0, %lo(D_8005071C)($v0)
    /* 1EA8 80065208 A01EC5AC */  sw         $a1, 0x1EA0($a2)
    /* 1EAC 8006520C 02000524 */  addiu      $a1, $zero, 0x2
    /* 1EB0 80065210 9C1EC3AC */  sw         $v1, 0x1E9C($a2)
    /* 1EB4 80065214 641044AC */  sw         $a0, 0x1064($v0)
    /* 1EB8 80065218 7745000C */  jal        Task_SetState1
    /* 1EBC 8006521C 21200001 */   addu      $a0, $t0, $zero
    /* 1EC0 80065220 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1EC4 80065224 00000000 */  nop
    /* 1EC8 80065228 0800E003 */  jr         $ra
    /* 1ECC 8006522C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800651C0
