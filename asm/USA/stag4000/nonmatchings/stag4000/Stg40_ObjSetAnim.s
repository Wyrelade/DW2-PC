nonmatching Stg40_ObjSetAnim, 0xC

glabel Stg40_ObjSetAnim
    /* B17C 8006E4DC 2C00828C */  lw         $v0, 0x2C($a0)
    /* B180 8006E4E0 0800E003 */  jr         $ra
    /* B184 8006E4E4 300045A4 */   sh        $a1, 0x30($v0)
endlabel Stg40_ObjSetAnim
