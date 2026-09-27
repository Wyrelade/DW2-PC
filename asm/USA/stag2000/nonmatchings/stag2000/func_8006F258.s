nonmatching func_8006F258, 0x34

glabel func_8006F258
    /* BEF8 8006F258 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* BEFC 8006F25C 1000B0AF */  sw         $s0, 0x10($sp)
    /* BF00 8006F260 21808000 */  addu       $s0, $a0, $zero
    /* BF04 8006F264 1400BFAF */  sw         $ra, 0x14($sp)
    /* BF08 8006F268 2C00048E */  lw         $a0, 0x2C($s0)
    /* BF0C 8006F26C 2C70000C */  jal        Text_CloseArray
    /* BF10 8006F270 0C000524 */   addiu     $a1, $zero, 0xC
    /* BF14 8006F274 5C44000C */  jal        Task_DefaultDestroy
    /* BF18 8006F278 21200002 */   addu      $a0, $s0, $zero
    /* BF1C 8006F27C 1400BF8F */  lw         $ra, 0x14($sp)
    /* BF20 8006F280 1000B08F */  lw         $s0, 0x10($sp)
    /* BF24 8006F284 0800E003 */  jr         $ra
    /* BF28 8006F288 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006F258
