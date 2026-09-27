nonmatching HookEntryInt, 0xC

glabel HookEntryInt
    /* 21BD4 800313D4 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 21BD8 800313D8 08004001 */  jr         $t2
    /* 21BDC 800313DC 19000924 */   addiu     $t1, $zero, 0x19
endlabel HookEntryInt
    /* 21BE0 800313E0 00000000 */  nop
