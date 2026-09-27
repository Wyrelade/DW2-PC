nonmatching _spu_Fw, 0x84

glabel _spu_Fw
    /* 2B1F8 8003A9F8 0580023C */  lui        $v0, %hi(D_8004FE44)
    /* 2B1FC 8003A9FC 44FE428C */  lw         $v0, %lo(D_8004FE44)($v0)
    /* 2B200 8003AA00 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2B204 8003AA04 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2B208 8003AA08 21888000 */  addu       $s1, $a0, $zero
    /* 2B20C 8003AA0C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2B210 8003AA10 2180A000 */  addu       $s0, $a1, $zero
    /* 2B214 8003AA14 10004014 */  bnez       $v0, .L8003AA58
    /* 2B218 8003AA18 1800BFAF */   sw        $ra, 0x18($sp)
    /* 2B21C 8003AA1C 0580023C */  lui        $v0, %hi(D_8004FE40)
    /* 2B220 8003AA20 40FE4294 */  lhu        $v0, %lo(D_8004FE40)($v0)
    /* 2B224 8003AA24 0580053C */  lui        $a1, %hi(D_8004FE50)
    /* 2B228 8003AA28 50FEA58C */  lw         $a1, %lo(D_8004FE50)($a1)
    /* 2B22C 8003AA2C 02000424 */  addiu      $a0, $zero, 0x2
    /* 2B230 8003AA30 DEE9000C */  jal        _spu_t
    /* 2B234 8003AA34 0428A200 */   sllv      $a1, $v0, $a1
    /* 2B238 8003AA38 DEE9000C */  jal        _spu_t
    /* 2B23C 8003AA3C 01000424 */   addiu     $a0, $zero, 0x1
    /* 2B240 8003AA40 03000424 */  addiu      $a0, $zero, 0x3
    /* 2B244 8003AA44 21282002 */  addu       $a1, $s1, $zero
    /* 2B248 8003AA48 DEE9000C */  jal        _spu_t
    /* 2B24C 8003AA4C 21300002 */   addu      $a2, $s0, $zero
    /* 2B250 8003AA50 9AEA0008 */  j          .L8003AA68
    /* 2B254 8003AA54 21100002 */   addu      $v0, $s0, $zero
  .L8003AA58:
    /* 2B258 8003AA58 21202002 */  addu       $a0, $s1, $zero
    /* 2B25C 8003AA5C 15E9000C */  jal        func_8003A454
    /* 2B260 8003AA60 21280002 */   addu      $a1, $s0, $zero
    /* 2B264 8003AA64 21100002 */  addu       $v0, $s0, $zero
  .L8003AA68:
    /* 2B268 8003AA68 1800BF8F */  lw         $ra, 0x18($sp)
    /* 2B26C 8003AA6C 1400B18F */  lw         $s1, 0x14($sp)
    /* 2B270 8003AA70 1000B08F */  lw         $s0, 0x10($sp)
    /* 2B274 8003AA74 0800E003 */  jr         $ra
    /* 2B278 8003AA78 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _spu_Fw
