nonmatching Mem_FillWordsNeg1, 0x28

glabel Mem_FillWordsNeg1
    /* C888 8001C088 0700A018 */  blez       $a1, .L8001C0A8
    /* C88C 8001C08C 21180000 */   addu      $v1, $zero, $zero
    /* C890 8001C090 FFFF0624 */  addiu      $a2, $zero, -0x1
  .L8001C094:
    /* C894 8001C094 000086AC */  sw         $a2, 0x0($a0)
    /* C898 8001C098 01006324 */  addiu      $v1, $v1, 0x1
    /* C89C 8001C09C 2A106500 */  slt        $v0, $v1, $a1
    /* C8A0 8001C0A0 FCFF4014 */  bnez       $v0, .L8001C094
    /* C8A4 8001C0A4 04008424 */   addiu     $a0, $a0, 0x4
  .L8001C0A8:
    /* C8A8 8001C0A8 0800E003 */  jr         $ra
    /* C8AC 8001C0AC 00000000 */   nop
endlabel Mem_FillWordsNeg1
