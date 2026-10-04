nonmatching Menu_SkillListInit, 0xC

glabel Menu_SkillListInit
    /* 9FFC 800197FC 2C00828C */  lw         $v0, 0x2C($a0)
    /* A000 80019800 0800E003 */  jr         $ra
    /* A004 80019804 A40045A4 */   sh        $a1, 0xA4($v0)
endlabel Menu_SkillListInit
