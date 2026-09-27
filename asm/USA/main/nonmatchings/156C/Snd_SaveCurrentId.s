nonmatching Snd_SaveCurrentId, 0x14

glabel Snd_SaveCurrentId
    /* B0BC 8001A8BC 2000828F */  lw         $v0, %gp_rel(Snd_CurrentId)($gp)
    /* B0C0 8001A8C0 00000000 */  nop
    /* B0C4 8001A8C4 7C0082AF */  sw         $v0, %gp_rel(Snd_SavedId)($gp)
    /* B0C8 8001A8C8 0800E003 */  jr         $ra
    /* B0CC 8001A8CC 00000000 */   nop
endlabel Snd_SaveCurrentId
