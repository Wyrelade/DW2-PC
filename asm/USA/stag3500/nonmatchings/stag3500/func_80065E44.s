nonmatching func_80065E44, 0x1C

glabel func_80065E44
    /* 2AE4 80065E44 0780023C */  lui        $v0, %hi(D_8006AA58)
    /* 2AE8 80065E48 58AA4224 */  addiu      $v0, $v0, %lo(D_8006AA58)
    /* 2AEC 80065E4C 80200400 */  sll        $a0, $a0, 2
    /* 2AF0 80065E50 21208200 */  addu       $a0, $a0, $v0
    /* 2AF4 80065E54 0000828C */  lw         $v0, 0x0($a0)
    /* 2AF8 80065E58 0800E003 */  jr         $ra
    /* 2AFC 80065E5C 00000000 */   nop
endlabel func_80065E44
