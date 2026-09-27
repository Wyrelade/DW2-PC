nonmatching func_8001E180, 0x2C

glabel func_8001E180
    /* E980 8001E180 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* E984 8001E184 1000BFAF */  sw         $ra, 0x10($sp)
    /* E988 8001E188 FD77000C */  jal        Item_FindById
    /* E98C 8001E18C 00000000 */   nop
    /* E990 8001E190 FF00033C */  lui        $v1, (0xFFFFFF >> 16)
    /* E994 8001E194 FFFF6334 */  ori        $v1, $v1, (0xFFFFFF & 0xFFFF)
    /* E998 8001E198 0400428C */  lw         $v0, 0x4($v0)
    /* E99C 8001E19C 1000BF8F */  lw         $ra, 0x10($sp)
    /* E9A0 8001E1A0 24104300 */  and        $v0, $v0, $v1
    /* E9A4 8001E1A4 0800E003 */  jr         $ra
    /* E9A8 8001E1A8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001E180
