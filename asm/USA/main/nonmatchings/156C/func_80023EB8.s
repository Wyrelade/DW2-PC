nonmatching func_80023EB8, 0x40

glabel func_80023EB8
    /* 146B8 80023EB8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 146BC 80023EBC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 146C0 80023EC0 9E8E000C */  jal        Cd_FindCachedFile
    /* 146C4 80023EC4 00000000 */   nop
    /* 146C8 80023EC8 21204000 */  addu       $a0, $v0, $zero
    /* 146CC 80023ECC 06008010 */  beqz       $a0, .L80023EE8
    /* 146D0 80023ED0 03000224 */   addiu     $v0, $zero, 0x3
    /* 146D4 80023ED4 00008384 */  lh         $v1, 0x0($a0)
    /* 146D8 80023ED8 00000000 */  nop
    /* 146DC 80023EDC 02006214 */  bne        $v1, $v0, .L80023EE8
    /* 146E0 80023EE0 00000000 */   nop
    /* 146E4 80023EE4 020080A4 */  sh         $zero, 0x2($a0)
  .L80023EE8:
    /* 146E8 80023EE8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 146EC 80023EEC 00000000 */  nop
    /* 146F0 80023EF0 0800E003 */  jr         $ra
    /* 146F4 80023EF4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80023EB8
