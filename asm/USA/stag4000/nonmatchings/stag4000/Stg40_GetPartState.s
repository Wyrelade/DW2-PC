nonmatching Stg40_GetPartState, 0x2C

glabel Stg40_GetPartState
    /* E27C 800715DC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* E280 800715E0 1000BFAF */  sw         $ra, 0x10($sp)
    /* E284 800715E4 08BA010C */  jal        Stg40_GetBeetlePart
    /* E288 800715E8 00000000 */   nop
    /* E28C 800715EC 02004018 */  blez       $v0, .L800715F8
    /* E290 800715F0 00000000 */   nop
    /* E294 800715F4 01000224 */  addiu      $v0, $zero, 0x1
  .L800715F8:
    /* E298 800715F8 1000BF8F */  lw         $ra, 0x10($sp)
    /* E29C 800715FC 00000000 */  nop
    /* E2A0 80071600 0800E003 */  jr         $ra
    /* E2A4 80071604 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg40_GetPartState
