nonmatching func_8001EDD4, 0x3C

glabel func_8001EDD4
    /* F5D4 8001EDD4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* F5D8 8001EDD8 1000B0AF */  sw         $s0, 0x10($sp)
    /* F5DC 8001EDDC 21808000 */  addu       $s0, $a0, $zero
    /* F5E0 8001EDE0 1400BFAF */  sw         $ra, 0x14($sp)
    /* F5E4 8001EDE4 828E000C */  jal        Cd_GetFileOrNull
    /* F5E8 8001EDE8 5B020424 */   addiu     $a0, $zero, 0x25B
    /* F5EC 8001EDEC 21200002 */  addu       $a0, $s0, $zero
    /* F5F0 8001EDF0 507B000C */  jal        func_8001ED40
    /* F5F4 8001EDF4 21804000 */   addu      $s0, $v0, $zero
    /* F5F8 8001EDF8 2800428C */  lw         $v0, 0x28($v0)
    /* F5FC 8001EDFC 1400BF8F */  lw         $ra, 0x14($sp)
    /* F600 8001EE00 21105000 */  addu       $v0, $v0, $s0
    /* F604 8001EE04 1000B08F */  lw         $s0, 0x10($sp)
    /* F608 8001EE08 0800E003 */  jr         $ra
    /* F60C 8001EE0C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001EDD4
