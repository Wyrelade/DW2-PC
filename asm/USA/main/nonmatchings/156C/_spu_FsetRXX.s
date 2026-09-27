nonmatching _spu_FsetRXX, 0x44

glabel _spu_FsetRXX
    /* 2B2E0 8003AAE0 0700C014 */  bnez       $a2, .L8003AB00
    /* 2B2E4 8003AAE4 40100400 */   sll       $v0, $a0, 1
    /* 2B2E8 8003AAE8 0580033C */  lui        $v1, %hi(D_8004FE28)
    /* 2B2EC 8003AAEC 28FE638C */  lw         $v1, %lo(D_8004FE28)($v1)
    /* 2B2F0 8003AAF0 00000000 */  nop
    /* 2B2F4 8003AAF4 21104300 */  addu       $v0, $v0, $v1
    /* 2B2F8 8003AAF8 C7EA0008 */  j          .L8003AB1C
    /* 2B2FC 8003AAFC 000045A4 */   sh        $a1, 0x0($v0)
  .L8003AB00:
    /* 2B300 8003AB00 0580043C */  lui        $a0, %hi(D_8004FE28)
    /* 2B304 8003AB04 28FE848C */  lw         $a0, %lo(D_8004FE28)($a0)
    /* 2B308 8003AB08 0580033C */  lui        $v1, %hi(D_8004FE50)
    /* 2B30C 8003AB0C 50FE638C */  lw         $v1, %lo(D_8004FE50)($v1)
    /* 2B310 8003AB10 21104400 */  addu       $v0, $v0, $a0
    /* 2B314 8003AB14 06186500 */  srlv       $v1, $a1, $v1
    /* 2B318 8003AB18 000043A4 */  sh         $v1, 0x0($v0)
  .L8003AB1C:
    /* 2B31C 8003AB1C 0800E003 */  jr         $ra
    /* 2B320 8003AB20 00000000 */   nop
endlabel _spu_FsetRXX
