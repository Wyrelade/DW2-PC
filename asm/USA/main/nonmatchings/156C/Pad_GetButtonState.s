nonmatching Pad_GetButtonState, 0x2C

glabel Pad_GetButtonState
    /* 13A70 80023270 24208600 */  and        $a0, $a0, $a2
    /* 13A74 80023274 03008010 */  beqz       $a0, .L80023284
    /* 13A78 80023278 21180000 */   addu      $v1, $zero, $zero
    /* 13A7C 8002327C A58C0008 */  j          .L80023294
    /* 13A80 80023280 01000324 */   addiu     $v1, $zero, 0x1
  .L80023284:
    /* 13A84 80023284 2410A600 */  and        $v0, $a1, $a2
    /* 13A88 80023288 02004010 */  beqz       $v0, .L80023294
    /* 13A8C 8002328C 00000000 */   nop
    /* 13A90 80023290 FFFF0324 */  addiu      $v1, $zero, -0x1
  .L80023294:
    /* 13A94 80023294 0800E003 */  jr         $ra
    /* 13A98 80023298 21106000 */   addu      $v0, $v1, $zero
endlabel Pad_GetButtonState
