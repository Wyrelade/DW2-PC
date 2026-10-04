nonmatching Stg40_AutomapLoadClut, 0x24

glabel Stg40_AutomapLoadClut
    /* BE08 8006F168 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* BE0C 8006F16C 21288000 */  addu       $a1, $a0, $zero
    /* BE10 8006F170 1000BFAF */  sw         $ra, 0x10($sp)
    /* BE14 8006F174 CB9D000C */  jal        LoadImage
    /* BE18 8006F178 4807A424 */   addiu     $a0, $a1, 0x748
    /* BE1C 8006F17C 1000BF8F */  lw         $ra, 0x10($sp)
    /* BE20 8006F180 00000000 */  nop
    /* BE24 8006F184 0800E003 */  jr         $ra
    /* BE28 8006F188 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg40_AutomapLoadClut
