/* Handwritten function */
nonmatching EnterCriticalSection, 0x10

glabel EnterCriticalSection
    /* 177C4 80026FC4 01000424 */  addiu      $a0, $zero, 0x1
    /* 177C8 80026FC8 0C000000 */  syscall    0 /* handwritten instruction */
    /* 177CC 80026FCC 0800E003 */  jr         $ra
    /* 177D0 80026FD0 00000000 */   nop
endlabel EnterCriticalSection
