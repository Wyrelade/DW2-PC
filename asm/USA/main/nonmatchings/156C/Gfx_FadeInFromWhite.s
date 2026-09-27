nonmatching Gfx_FadeInFromWhite, 0x2C

glabel Gfx_FadeInFromWhite
    /* CD0C 8001C50C 0480033C */  lui        $v1, %hi(Gfx_FadeState)
    /* CD10 8001C510 64156524 */  addiu      $a1, $v1, %lo(Gfx_FadeState)
    /* CD14 8001C514 01000224 */  addiu      $v0, $zero, 0x1
    /* CD18 8001C518 0800A2AC */  sw         $v0, 0x8($a1)
    /* CD1C 8001C51C 02000224 */  addiu      $v0, $zero, 0x2
    /* CD20 8001C520 641562AC */  sw         $v0, %lo(Gfx_FadeState)($v1)
    /* CD24 8001C524 0680023C */  lui        $v0, %hi(D_8005F780)
    /* CD28 8001C528 0400A4AC */  sw         $a0, 0x4($a1)
    /* CD2C 8001C52C FF008424 */  addiu      $a0, $a0, 0xFF
    /* CD30 8001C530 0800E003 */  jr         $ra
    /* CD34 8001C534 80F744AC */   sw        $a0, %lo(D_8005F780)($v0)
endlabel Gfx_FadeInFromWhite
