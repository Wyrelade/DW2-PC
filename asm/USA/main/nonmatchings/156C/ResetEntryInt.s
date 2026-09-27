nonmatching ResetEntryInt, 0xC

glabel ResetEntryInt
    /* 21BC4 800313C4 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 21BC8 800313C8 08004001 */  jr         $t2
    /* 21BCC 800313CC 18000924 */   addiu     $t1, $zero, 0x18
endlabel ResetEntryInt
    /* 21BD0 800313D0 00000000 */  nop
