nonmatching Math_CycleRange, 0x44

glabel Math_CycleRange
    /* 12BEC 800223EC 2A10C700 */  slt        $v0, $a2, $a3
    /* 12BF0 800223F0 1A008500 */  div        $zero, $a0, $a1
    /* 12BF4 800223F4 12200000 */  mflo       $a0
    /* 12BF8 800223F8 07004014 */  bnez       $v0, .L80022418
    /* 12BFC 800223FC 00000000 */   nop
    /* 12C00 80022400 2310C700 */  subu       $v0, $a2, $a3
    /* 12C04 80022404 01004224 */  addiu      $v0, $v0, 0x1
    /* 12C08 80022408 1A008200 */  div        $zero, $a0, $v0
    /* 12C0C 8002240C 10200000 */  mfhi       $a0
    /* 12C10 80022410 0800E003 */  jr         $ra
    /* 12C14 80022414 2310C400 */   subu      $v0, $a2, $a0
  .L80022418:
    /* 12C18 80022418 2310E600 */  subu       $v0, $a3, $a2
    /* 12C1C 8002241C 01004224 */  addiu      $v0, $v0, 0x1
    /* 12C20 80022420 1A008200 */  div        $zero, $a0, $v0
    /* 12C24 80022424 10200000 */  mfhi       $a0
    /* 12C28 80022428 0800E003 */  jr         $ra
    /* 12C2C 8002242C 21108600 */   addu      $v0, $a0, $a2
endlabel Math_CycleRange
