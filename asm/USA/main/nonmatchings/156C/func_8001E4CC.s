nonmatching func_8001E4CC, 0x48

glabel func_8001E4CC
    /* ECCC 8001E4CC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* ECD0 8001E4D0 1000B0AF */  sw         $s0, 0x10($sp)
    /* ECD4 8001E4D4 21808000 */  addu       $s0, $a0, $zero
    /* ECD8 8001E4D8 0680023C */  lui        $v0, %hi(D_8005D560)
    /* ECDC 8001E4DC 60D5448C */  lw         $a0, %lo(D_8005D560)($v0)
    /* ECE0 8001E4E0 1400BFAF */  sw         $ra, 0x14($sp)
    /* ECE4 8001E4E4 688E000C */  jal        Cd_GetFileEntry
    /* ECE8 8001E4E8 00240400 */   sll       $a0, $a0, 16
    /* ECEC 8001E4EC 40181000 */  sll        $v1, $s0, 1
    /* ECF0 8001E4F0 21187000 */  addu       $v1, $v1, $s0
    /* ECF4 8001E4F4 80180300 */  sll        $v1, $v1, 2
    /* ECF8 8001E4F8 23187000 */  subu       $v1, $v1, $s0
    /* ECFC 8001E4FC 80180300 */  sll        $v1, $v1, 2
    /* ED00 8001E500 1400BF8F */  lw         $ra, 0x14($sp)
    /* ED04 8001E504 1000B08F */  lw         $s0, 0x10($sp)
    /* ED08 8001E508 21104300 */  addu       $v0, $v0, $v1
    /* ED0C 8001E50C 0800E003 */  jr         $ra
    /* ED10 8001E510 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001E4CC
