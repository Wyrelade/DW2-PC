nonmatching Gfx_FadeOutToBlack, 0x1C

glabel Gfx_FadeOutToBlack
    /* CCF0 8001C4F0 0480023C */  lui        $v0, %hi(Gfx_FadeState)
    /* CCF4 8001C4F4 64154524 */  addiu      $a1, $v0, %lo(Gfx_FadeState)
    /* CCF8 8001C4F8 03000324 */  addiu      $v1, $zero, 0x3
    /* CCFC 8001C4FC 0800A0AC */  sw         $zero, 0x8($a1)
    /* CD00 8001C500 641543AC */  sw         $v1, %lo(Gfx_FadeState)($v0)
    /* CD04 8001C504 0800E003 */  jr         $ra
    /* CD08 8001C508 0400A4AC */   sw        $a0, 0x4($a1)
endlabel Gfx_FadeOutToBlack
