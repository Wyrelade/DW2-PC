nonmatching Digi_GetRank, 0x28

glabel Digi_GetRank
    /* E158 8001D958 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* E15C 8001D95C 1000BFAF */  sw         $ra, 0x10($sp)
    /* E160 8001D960 3176000C */  jal        Digi_FindBaseData
    /* E164 8001D964 00000000 */   nop
    /* E168 8001D968 04004294 */  lhu        $v0, 0x4($v0)
    /* E16C 8001D96C 1000BF8F */  lw         $ra, 0x10($sp)
    /* E170 8001D970 02110200 */  srl        $v0, $v0, 4
    /* E174 8001D974 0F004230 */  andi       $v0, $v0, 0xF
    /* E178 8001D978 0800E003 */  jr         $ra
    /* E17C 8001D97C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Digi_GetRank
