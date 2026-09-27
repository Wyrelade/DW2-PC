nonmatching func_8001C038, 0x50

glabel func_8001C038
    /* C838 8001C038 B8FFBD27 */  addiu      $sp, $sp, -0x48
    /* C83C 8001C03C 2400A5AF */  sw         $a1, 0x24($sp)
    /* C840 8001C040 1000A527 */  addiu      $a1, $sp, 0x10
    /* C844 8001C044 01000224 */  addiu      $v0, $zero, 0x1
    /* C848 8001C048 4000BFAF */  sw         $ra, 0x40($sp)
    /* C84C 8001C04C 1000A2AF */  sw         $v0, 0x10($sp)
    /* C850 8001C050 1400A0AF */  sw         $zero, 0x14($sp)
    /* C854 8001C054 1800A0A7 */  sh         $zero, 0x18($sp)
    /* C858 8001C058 1A00A0A7 */  sh         $zero, 0x1A($sp)
    /* C85C 8001C05C 1C00A0AF */  sw         $zero, 0x1C($sp)
    /* C860 8001C060 2000A0AF */  sw         $zero, 0x20($sp)
    /* C864 8001C064 096F000C */  jal        Text_Open
    /* C868 8001C068 2800A2AF */   sw        $v0, 0x28($sp)
    /* C86C 8001C06C 10000424 */  addiu      $a0, $zero, 0x10
    /* C870 8001C070 7188000C */  jal        func_800221C4
    /* C874 8001C074 21280000 */   addu      $a1, $zero, $zero
    /* C878 8001C078 4000BF8F */  lw         $ra, 0x40($sp)
    /* C87C 8001C07C 00000000 */  nop
    /* C880 8001C080 0800E003 */  jr         $ra
    /* C884 8001C084 4800BD27 */   addiu     $sp, $sp, 0x48
endlabel func_8001C038
