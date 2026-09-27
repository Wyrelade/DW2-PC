nonmatching func_800704FC, 0x34

glabel func_800704FC
    /* D19C 800704FC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* D1A0 80070500 1000B0AF */  sw         $s0, 0x10($sp)
    /* D1A4 80070504 21808000 */  addu       $s0, $a0, $zero
    /* D1A8 80070508 09000424 */  addiu      $a0, $zero, 0x9
    /* D1AC 8007050C 1400BFAF */  sw         $ra, 0x14($sp)
    /* D1B0 80070510 A4C1000C */  jal        CdControlF
    /* D1B4 80070514 21280000 */   addu      $a1, $zero, $zero
    /* D1B8 80070518 5C44000C */  jal        Task_DefaultDestroy
    /* D1BC 8007051C 21200002 */   addu      $a0, $s0, $zero
    /* D1C0 80070520 1400BF8F */  lw         $ra, 0x14($sp)
    /* D1C4 80070524 1000B08F */  lw         $s0, 0x10($sp)
    /* D1C8 80070528 0800E003 */  jr         $ra
    /* D1CC 8007052C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800704FC
