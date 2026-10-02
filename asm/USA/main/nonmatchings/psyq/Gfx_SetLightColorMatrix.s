nonmatching Gfx_SetLightColorMatrix, 0x64

glabel Gfx_SetLightColorMatrix
    /* 1C21C 8002BA1C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1C220 8002BA20 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1C224 8002BA24 0680063C */  lui        $a2, %hi(D_800619C8)
    /* 1C228 8002BA28 C819C624 */  addiu      $a2, $a2, %lo(D_800619C8)
    /* 1C22C 8002BA2C 0000828C */  lw         $v0, 0x0($a0)
    /* 1C230 8002BA30 0400838C */  lw         $v1, 0x4($a0)
    /* 1C234 8002BA34 0800858C */  lw         $a1, 0x8($a0)
    /* 1C238 8002BA38 0000C2AC */  sw         $v0, 0x0($a2)
    /* 1C23C 8002BA3C 0400C3AC */  sw         $v1, 0x4($a2)
    /* 1C240 8002BA40 0800C5AC */  sw         $a1, 0x8($a2)
    /* 1C244 8002BA44 0C00828C */  lw         $v0, 0xC($a0)
    /* 1C248 8002BA48 1000838C */  lw         $v1, 0x10($a0)
    /* 1C24C 8002BA4C 1400858C */  lw         $a1, 0x14($a0)
    /* 1C250 8002BA50 0C00C2AC */  sw         $v0, 0xC($a2)
    /* 1C254 8002BA54 1000C3AC */  sw         $v1, 0x10($a2)
    /* 1C258 8002BA58 1400C5AC */  sw         $a1, 0x14($a2)
    /* 1C25C 8002BA5C 1800828C */  lw         $v0, 0x18($a0)
    /* 1C260 8002BA60 1C00838C */  lw         $v1, 0x1C($a0)
    /* 1C264 8002BA64 1800C2AC */  sw         $v0, 0x18($a2)
    /* 1C268 8002BA68 85B5000C */  jal        SetColorMatrix
    /* 1C26C 8002BA6C 1C00C3AC */   sw        $v1, 0x1C($a2)
    /* 1C270 8002BA70 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1C274 8002BA74 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 1C278 8002BA78 0800E003 */  jr         $ra
    /* 1C27C 8002BA7C 00000000 */   nop
endlabel Gfx_SetLightColorMatrix
