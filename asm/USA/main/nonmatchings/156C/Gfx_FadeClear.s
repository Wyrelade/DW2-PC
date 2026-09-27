nonmatching Gfx_FadeClear, 0x14

glabel Gfx_FadeClear
    /* CD58 8001C558 0480033C */  lui        $v1, %hi(Gfx_FadeState)
    /* CD5C 8001C55C 64156224 */  addiu      $v0, $v1, %lo(Gfx_FadeState)
    /* CD60 8001C560 080040AC */  sw         $zero, 0x8($v0)
    /* CD64 8001C564 0800E003 */  jr         $ra
    /* CD68 8001C568 641560AC */   sw        $zero, %lo(Gfx_FadeState)($v1)
endlabel Gfx_FadeClear
