nonmatching Stg40_RelocPtr, 0x20

glabel Stg40_RelocPtr
    /* DB60 80070EC0 0000838C */  lw         $v1, 0x0($a0)
    /* DB64 80070EC4 00000000 */  nop
    /* DB68 80070EC8 2B106500 */  sltu       $v0, $v1, $a1
    /* DB6C 80070ECC 02004010 */  beqz       $v0, .L80070ED8
    /* DB70 80070ED0 21106500 */   addu      $v0, $v1, $a1
    /* DB74 80070ED4 000082AC */  sw         $v0, 0x0($a0)
  .L80070ED8:
    /* DB78 80070ED8 0800E003 */  jr         $ra
    /* DB7C 80070EDC 00000000 */   nop
endlabel Stg40_RelocPtr
