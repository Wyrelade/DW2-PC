nonmatching func_80011140, 0x20

glabel func_80011140
    /* 1940 80011140 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1944 80011144 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1948 80011148 5145000C */  jal        Task_NextState0
    /* 194C 8001114C 00000000 */   nop
    /* 1950 80011150 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1954 80011154 00000000 */  nop
    /* 1958 80011158 0800E003 */  jr         $ra
    /* 195C 8001115C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80011140
