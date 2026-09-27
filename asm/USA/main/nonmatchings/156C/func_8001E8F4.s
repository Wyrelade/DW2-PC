nonmatching func_8001E8F4, 0x44

glabel func_8001E8F4
    /* F0F4 8001E8F4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* F0F8 8001E8F8 1000B0AF */  sw         $s0, 0x10($sp)
    /* F0FC 8001E8FC 21808000 */  addu       $s0, $a0, $zero
    /* F100 8001E900 1400BFAF */  sw         $ra, 0x14($sp)
    /* F104 8001E904 688E000C */  jal        Cd_GetFileEntry
    /* F108 8001E908 F801043C */   lui       $a0, (0x1F80000 >> 16)
    /* F10C 8001E90C 80181000 */  sll        $v1, $s0, 2
    /* F110 8001E910 21187000 */  addu       $v1, $v1, $s0
    /* F114 8001E914 C0180300 */  sll        $v1, $v1, 3
    /* F118 8001E918 21104300 */  addu       $v0, $v0, $v1
    /* F11C 8001E91C 0400428C */  lw         $v0, 0x4($v0)
    /* F120 8001E920 1400BF8F */  lw         $ra, 0x14($sp)
    /* F124 8001E924 1000B08F */  lw         $s0, 0x10($sp)
    /* F128 8001E928 42100200 */  srl        $v0, $v0, 1
    /* F12C 8001E92C FF7F4230 */  andi       $v0, $v0, 0x7FFF
    /* F130 8001E930 0800E003 */  jr         $ra
    /* F134 8001E934 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001E8F4
