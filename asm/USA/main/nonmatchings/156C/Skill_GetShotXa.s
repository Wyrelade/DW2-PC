nonmatching Skill_GetShotXa, 0x30

glabel Skill_GetShotXa
    /* F7F0 8001EFF0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* F7F4 8001EFF4 1000BFAF */  sw         $ra, 0x10($sp)
    /* F7F8 8001EFF8 507B000C */  jal        Skill_FindById
    /* F7FC 8001EFFC 00000000 */   nop
    /* F800 8001F000 06004384 */  lh         $v1, 0x6($v0)
    /* F804 8001F004 1000BF8F */  lw         $ra, 0x10($sp)
    /* F808 8001F008 800083AF */  sw         $v1, %gp_rel(Skill_ShotXaFile)($gp)
    /* F80C 8001F00C 05004390 */  lbu        $v1, 0x5($v0)
    /* F810 8001F010 80008227 */  addiu      $v0, $gp, %gp_rel(Skill_ShotXaFile)
    /* F814 8001F014 840083AF */  sw         $v1, %gp_rel(D_8005077C)($gp)
    /* F818 8001F018 0800E003 */  jr         $ra
    /* F81C 8001F01C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Skill_GetShotXa
