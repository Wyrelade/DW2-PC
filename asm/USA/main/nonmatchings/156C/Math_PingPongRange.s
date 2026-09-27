nonmatching Math_PingPongRange, 0x38

glabel Math_PingPongRange
    /* 12C30 80022430 1A008500 */  div        $zero, $a0, $a1
    /* 12C34 80022434 12200000 */  mflo       $a0
    /* 12C38 80022438 2328E600 */  subu       $a1, $a3, $a2
    /* 12C3C 8002243C 40100500 */  sll        $v0, $a1, 1
    /* 12C40 80022440 1A008200 */  div        $zero, $a0, $v0
    /* 12C44 80022444 10180000 */  mfhi       $v1
    /* 12C48 80022448 00000000 */  nop
    /* 12C4C 8002244C 2A106500 */  slt        $v0, $v1, $a1
    /* 12C50 80022450 03004014 */  bnez       $v0, .L80022460
    /* 12C54 80022454 23106500 */   subu      $v0, $v1, $a1
    /* 12C58 80022458 0800E003 */  jr         $ra
    /* 12C5C 8002245C 2310E200 */   subu      $v0, $a3, $v0
  .L80022460:
    /* 12C60 80022460 0800E003 */  jr         $ra
    /* 12C64 80022464 21106600 */   addu      $v0, $v1, $a2
endlabel Math_PingPongRange
