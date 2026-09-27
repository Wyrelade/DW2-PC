nonmatching FlushCache, 0xC

glabel FlushCache
    /* 1E3A4 8002DBA4 A0000A24 */  addiu      $t2, $zero, 0xA0
    /* 1E3A8 8002DBA8 08004001 */  jr         $t2
    /* 1E3AC 8002DBAC 44000924 */   addiu     $t1, $zero, 0x44
endlabel FlushCache
    /* 1E3B0 8002DBB0 00000000 */  nop
