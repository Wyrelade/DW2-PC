nonmatching Stg30_JoinPromptDraw, 0x44

glabel Stg30_JoinPromptDraw
    /* FC24 80072F84 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* FC28 80072F88 1000BFAF */  sw         $ra, 0x10($sp)
    /* FC2C 80072F8C 2C00828C */  lw         $v0, 0x2C($a0)
    /* FC30 80072F90 00000000 */  nop
    /* FC34 80072F94 1000428C */  lw         $v0, 0x10($v0)
    /* FC38 80072F98 00000000 */  nop
    /* FC3C 80072F9C 06004010 */  beqz       $v0, .L80072FB8
    /* FC40 80072FA0 00000000 */   nop
    /* FC44 80072FA4 A101043C */  lui        $a0, (0x1A10017 >> 16)
    /* FC48 80072FA8 688E000C */  jal        Cd_GetFileEntry
    /* FC4C 80072FAC 17008434 */   ori       $a0, $a0, (0x1A10017 & 0xFFFF)
    /* FC50 80072FB0 2176000C */  jal        Gfx_DrawParts
    /* FC54 80072FB4 21204000 */   addu      $a0, $v0, $zero
  .L80072FB8:
    /* FC58 80072FB8 1000BF8F */  lw         $ra, 0x10($sp)
    /* FC5C 80072FBC 00000000 */  nop
    /* FC60 80072FC0 0800E003 */  jr         $ra
    /* FC64 80072FC4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg30_JoinPromptDraw
