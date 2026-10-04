nonmatching func_80066A9C, 0x44

glabel func_80066A9C
    /* 373C 80066A9C 0680023C */  lui        $v0, %hi(Save_GameState)
    /* 3740 80066AA0 20E64324 */  addiu      $v1, $v0, %lo(Save_GameState)
    /* 3744 80066AA4 0800628C */  lw         $v0, 0x8($v1)
    /* 3748 80066AA8 00000000 */  nop
    /* 374C 80066AAC 21104400 */  addu       $v0, $v0, $a0
    /* 3750 80066AB0 02004104 */  bgez       $v0, .L80066ABC
    /* 3754 80066AB4 080062AC */   sw        $v0, 0x8($v1)
    /* 3758 80066AB8 080060AC */  sw         $zero, 0x8($v1)
  .L80066ABC:
    /* 375C 80066ABC F505043C */  lui        $a0, (0x5F5E0FF >> 16)
    /* 3760 80066AC0 0800628C */  lw         $v0, 0x8($v1)
    /* 3764 80066AC4 FFE08434 */  ori        $a0, $a0, (0x5F5E0FF & 0xFFFF)
    /* 3768 80066AC8 2A108200 */  slt        $v0, $a0, $v0
    /* 376C 80066ACC 02004010 */  beqz       $v0, .L80066AD8
    /* 3770 80066AD0 00000000 */   nop
    /* 3774 80066AD4 080064AC */  sw         $a0, 0x8($v1)
  .L80066AD8:
    /* 3778 80066AD8 0800E003 */  jr         $ra
    /* 377C 80066ADC 00000000 */   nop
endlabel func_80066A9C
