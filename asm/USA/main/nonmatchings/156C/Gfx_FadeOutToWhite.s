nonmatching Gfx_FadeOutToWhite, 0x20

glabel Gfx_FadeOutToWhite
    /* CD38 8001C538 0480033C */  lui        $v1, %hi(Gfx_FadeState)
    /* CD3C 8001C53C 64156524 */  addiu      $a1, $v1, %lo(Gfx_FadeState)
    /* CD40 8001C540 01000224 */  addiu      $v0, $zero, 0x1
    /* CD44 8001C544 0800A2AC */  sw         $v0, 0x8($a1)
    /* CD48 8001C548 03000224 */  addiu      $v0, $zero, 0x3
    /* CD4C 8001C54C 641562AC */  sw         $v0, %lo(Gfx_FadeState)($v1)
    /* CD50 8001C550 0800E003 */  jr         $ra
    /* CD54 8001C554 0400A4AC */   sw        $a0, 0x4($a1)
endlabel Gfx_FadeOutToWhite
