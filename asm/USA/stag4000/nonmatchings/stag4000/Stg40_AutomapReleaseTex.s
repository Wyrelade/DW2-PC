nonmatching Stg40_AutomapReleaseTex, 0x24

glabel Stg40_AutomapReleaseTex
    /* C02C 8006F38C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* C030 8006F390 1000BFAF */  sw         $ra, 0x10($sp)
    /* C034 8006F394 5807848C */  lw         $a0, 0x758($a0)
    /* C038 8006F398 A073000C */  jal        Gfx_ReleaseTexSlot
    /* C03C 8006F39C 00000000 */   nop
    /* C040 8006F3A0 1000BF8F */  lw         $ra, 0x10($sp)
    /* C044 8006F3A4 00000000 */  nop
    /* C048 8006F3A8 0800E003 */  jr         $ra
    /* C04C 8006F3AC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg40_AutomapReleaseTex
