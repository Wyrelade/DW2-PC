nonmatching Gfx_FadeSetBlack, 0x18

glabel Gfx_FadeSetBlack
    /* CD6C 8001C56C 0480023C */  lui        $v0, %hi(Gfx_FadeState)
    /* CD70 8001C570 64154324 */  addiu      $v1, $v0, %lo(Gfx_FadeState)
    /* CD74 8001C574 080060AC */  sw         $zero, 0x8($v1)
    /* CD78 8001C578 01000324 */  addiu      $v1, $zero, 0x1
    /* CD7C 8001C57C 0800E003 */  jr         $ra
    /* CD80 8001C580 641543AC */   sw        $v1, %lo(Gfx_FadeState)($v0)
endlabel Gfx_FadeSetBlack
