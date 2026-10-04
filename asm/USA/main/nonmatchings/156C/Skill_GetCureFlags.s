nonmatching Skill_GetCureFlags, 0x2C

glabel Skill_GetCureFlags
    /* F894 8001F094 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* F898 8001F098 1000BFAF */  sw         $ra, 0x10($sp)
    /* F89C 8001F09C 507B000C */  jal        Skill_FindById
    /* F8A0 8001F0A0 00000000 */   nop
    /* F8A4 8001F0A4 0300033C */  lui        $v1, (0x3FFFF >> 16)
    /* F8A8 8001F0A8 FFFF6334 */  ori        $v1, $v1, (0x3FFFF & 0xFFFF)
    /* F8AC 8001F0AC 1C00428C */  lw         $v0, 0x1C($v0)
    /* F8B0 8001F0B0 1000BF8F */  lw         $ra, 0x10($sp)
    /* F8B4 8001F0B4 24104300 */  and        $v0, $v0, $v1
    /* F8B8 8001F0B8 0800E003 */  jr         $ra
    /* F8BC 8001F0BC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Skill_GetCureFlags
