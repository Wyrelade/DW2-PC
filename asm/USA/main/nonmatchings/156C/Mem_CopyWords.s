nonmatching Mem_CopyWords, 0x2C

glabel Mem_CopyWords
    /* 1F3E0 8002EBE0 0800C010 */  beqz       $a2, .L8002EC04
    /* 1F3E4 8002EBE4 21180000 */   addu      $v1, $zero, $zero
  .L8002EBE8:
    /* 1F3E8 8002EBE8 0000A28C */  lw         $v0, 0x0($a1)
    /* 1F3EC 8002EBEC 0400A524 */  addiu      $a1, $a1, 0x4
    /* 1F3F0 8002EBF0 01006324 */  addiu      $v1, $v1, 0x1
    /* 1F3F4 8002EBF4 000082AC */  sw         $v0, 0x0($a0)
    /* 1F3F8 8002EBF8 2B106600 */  sltu       $v0, $v1, $a2
    /* 1F3FC 8002EBFC FAFF4014 */  bnez       $v0, .L8002EBE8
    /* 1F400 8002EC00 04008424 */   addiu     $a0, $a0, 0x4
  .L8002EC04:
    /* 1F404 8002EC04 0800E003 */  jr         $ra
    /* 1F408 8002EC08 00000000 */   nop
endlabel Mem_CopyWords
