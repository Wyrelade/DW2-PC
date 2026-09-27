nonmatching Gfx_FadeInFromBlack, 0x28

glabel Gfx_FadeInFromBlack
    /* CCC8 8001C4C8 0480033C */  lui        $v1, %hi(Gfx_FadeState)
    /* CCCC 8001C4CC 64156524 */  addiu      $a1, $v1, %lo(Gfx_FadeState)
    /* CCD0 8001C4D0 02000224 */  addiu      $v0, $zero, 0x2
    /* CCD4 8001C4D4 0800A0AC */  sw         $zero, 0x8($a1)
    /* CCD8 8001C4D8 641562AC */  sw         $v0, %lo(Gfx_FadeState)($v1)
    /* CCDC 8001C4DC 0680023C */  lui        $v0, %hi(D_8005F780)
    /* CCE0 8001C4E0 0400A4AC */  sw         $a0, 0x4($a1)
    /* CCE4 8001C4E4 FF008424 */  addiu      $a0, $a0, 0xFF
    /* CCE8 8001C4E8 0800E003 */  jr         $ra
    /* CCEC 8001C4EC 80F744AC */   sw        $a0, %lo(D_8005F780)($v0)
endlabel Gfx_FadeInFromBlack
