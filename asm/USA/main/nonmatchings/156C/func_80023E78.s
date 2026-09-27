nonmatching func_80023E78, 0x40

glabel func_80023E78
    /* 14678 80023E78 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1467C 80023E7C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 14680 80023E80 9E8E000C */  jal        Cd_FindCachedFile
    /* 14684 80023E84 00000000 */   nop
    /* 14688 80023E88 21204000 */  addu       $a0, $v0, $zero
    /* 1468C 80023E8C 06008010 */  beqz       $a0, .L80023EA8
    /* 14690 80023E90 03000224 */   addiu     $v0, $zero, 0x3
    /* 14694 80023E94 00008384 */  lh         $v1, 0x0($a0)
    /* 14698 80023E98 00000000 */  nop
    /* 1469C 80023E9C 02006214 */  bne        $v1, $v0, .L80023EA8
    /* 146A0 80023EA0 01000224 */   addiu     $v0, $zero, 0x1
    /* 146A4 80023EA4 020082A4 */  sh         $v0, 0x2($a0)
  .L80023EA8:
    /* 146A8 80023EA8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 146AC 80023EAC 00000000 */  nop
    /* 146B0 80023EB0 0800E003 */  jr         $ra
    /* 146B4 80023EB4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80023E78
