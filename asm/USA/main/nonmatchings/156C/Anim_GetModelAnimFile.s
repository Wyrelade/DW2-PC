nonmatching Anim_GetModelAnimFile, 0x30

glabel Anim_GetModelAnimFile
    /* EF28 8001E728 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* EF2C 8001E72C 1000B0AF */  sw         $s0, 0x10($sp)
    /* EF30 8001E730 1400BFAF */  sw         $ra, 0x14($sp)
    /* EF34 8001E734 AA79000C */  jal        func_8001E6A8
    /* EF38 8001E738 2180A000 */   addu      $s0, $a1, $zero
    /* EF3C 8001E73C 40801000 */  sll        $s0, $s0, 1
    /* EF40 8001E740 21105000 */  addu       $v0, $v0, $s0
    /* EF44 8001E744 08004284 */  lh         $v0, 0x8($v0)
    /* EF48 8001E748 1400BF8F */  lw         $ra, 0x14($sp)
    /* EF4C 8001E74C 1000B08F */  lw         $s0, 0x10($sp)
    /* EF50 8001E750 0800E003 */  jr         $ra
    /* EF54 8001E754 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Anim_GetModelAnimFile
