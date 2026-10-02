nonmatching Gfx_GetLightColorMatrix, 0x4C

glabel Gfx_GetLightColorMatrix
    /* 1C280 8002BA80 0680063C */  lui        $a2, %hi(D_800619C8)
    /* 1C284 8002BA84 C819C624 */  addiu      $a2, $a2, %lo(D_800619C8)
    /* 1C288 8002BA88 0000C28C */  lw         $v0, 0x0($a2)
    /* 1C28C 8002BA8C 0400C38C */  lw         $v1, 0x4($a2)
    /* 1C290 8002BA90 0800C58C */  lw         $a1, 0x8($a2)
    /* 1C294 8002BA94 000082AC */  sw         $v0, 0x0($a0)
    /* 1C298 8002BA98 040083AC */  sw         $v1, 0x4($a0)
    /* 1C29C 8002BA9C 080085AC */  sw         $a1, 0x8($a0)
    /* 1C2A0 8002BAA0 0C00C28C */  lw         $v0, 0xC($a2)
    /* 1C2A4 8002BAA4 1000C38C */  lw         $v1, 0x10($a2)
    /* 1C2A8 8002BAA8 1400C58C */  lw         $a1, 0x14($a2)
    /* 1C2AC 8002BAAC 0C0082AC */  sw         $v0, 0xC($a0)
    /* 1C2B0 8002BAB0 100083AC */  sw         $v1, 0x10($a0)
    /* 1C2B4 8002BAB4 140085AC */  sw         $a1, 0x14($a0)
    /* 1C2B8 8002BAB8 1800C28C */  lw         $v0, 0x18($a2)
    /* 1C2BC 8002BABC 1C00C38C */  lw         $v1, 0x1C($a2)
    /* 1C2C0 8002BAC0 180082AC */  sw         $v0, 0x18($a0)
    /* 1C2C4 8002BAC4 0800E003 */  jr         $ra
    /* 1C2C8 8002BAC8 1C0083AC */   sw        $v1, 0x1C($a0)
endlabel Gfx_GetLightColorMatrix
    /* 1C2CC 8002BACC 00000000 */  nop
    /* 1C2D0 8002BAD0 00000000 */  nop
