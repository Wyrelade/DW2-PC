nonmatching func_8003DBE4, 0x34

glabel func_8003DBE4
    /* 2E3E4 8003DBE4 80DF0234 */  ori        $v0, $zero, 0xDF80
    /* 2E3E8 8003DBE8 04800A3C */  lui        $t2, %hi(func_8003DA48)
    /* 2E3EC 8003DBEC 48DA4A25 */  addiu      $t2, $t2, %lo(func_8003DA48)
    /* 2E3F0 8003DBF0 0480093C */  lui        $t1, %hi(func_8003DAB8)
    /* 2E3F4 8003DBF4 B8DA2925 */  addiu      $t1, $t1, %lo(func_8003DAB8)
  .L8003DBF8:
    /* 2E3F8 8003DBF8 0000438D */  lw         $v1, 0x0($t2)
    /* 2E3FC 8003DBFC 00000000 */  nop
    /* 2E400 8003DC00 000043AC */  sw         $v1, 0x0($v0)
    /* 2E404 8003DC04 04004A25 */  addiu      $t2, $t2, 0x4
    /* 2E408 8003DC08 FBFF4915 */  bne        $t2, $t1, .L8003DBF8
    /* 2E40C 8003DC0C 04004224 */   addiu     $v0, $v0, 0x4
    /* 2E410 8003DC10 0800E003 */  jr         $ra
    /* 2E414 8003DC14 00000000 */   nop
endlabel func_8003DBE4
    /* 2E418 8003DC18 00000000 */  nop
    /* 2E41C 8003DC1C 00000000 */  nop
    /* 2E420 8003DC20 00000000 */  nop
