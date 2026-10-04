nonmatching Stg40_ObjSetAnimIfNew, 0x38

glabel Stg40_ObjSetAnimIfNew
    /* B188 8006E4E8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* B18C 8006E4EC 1000BFAF */  sw         $ra, 0x10($sp)
    /* B190 8006E4F0 2C00828C */  lw         $v0, 0x2C($a0)
    /* B194 8006E4F4 00000000 */  nop
    /* B198 8006E4F8 32004284 */  lh         $v0, 0x32($v0)
    /* B19C 8006E4FC 00000000 */  nop
    /* B1A0 8006E500 03004510 */  beq        $v0, $a1, .L8006E510
    /* B1A4 8006E504 00000000 */   nop
    /* B1A8 8006E508 37B9010C */  jal        Stg40_ObjSetAnim
    /* B1AC 8006E50C 00000000 */   nop
  .L8006E510:
    /* B1B0 8006E510 1000BF8F */  lw         $ra, 0x10($sp)
    /* B1B4 8006E514 00000000 */  nop
    /* B1B8 8006E518 0800E003 */  jr         $ra
    /* B1BC 8006E51C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg40_ObjSetAnimIfNew
