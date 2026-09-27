nonmatching func_8006A144, 0x4C

glabel func_8006A144
    /* 6DE4 8006A144 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6DE8 8006A148 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6DEC 8006A14C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 6DF0 8006A150 4D76000C */  jal        func_8001D934
    /* 6DF4 8006A154 2180A000 */   addu      $s0, $a1, $zero
    /* 6DF8 8006A158 21200002 */  addu       $a0, $s0, $zero
    /* 6DFC 8006A15C 4D76000C */  jal        func_8001D934
    /* 6E00 8006A160 21804000 */   addu      $s0, $v0, $zero
    /* 6E04 8006A164 0780043C */  lui        $a0, %hi(D_8007012C)
    /* 6E08 8006A168 2C018424 */  addiu      $a0, $a0, %lo(D_8007012C)
    /* 6E0C 8006A16C 40181000 */  sll        $v1, $s0, 1
    /* 6E10 8006A170 21187000 */  addu       $v1, $v1, $s0
    /* 6E14 8006A174 21104300 */  addu       $v0, $v0, $v1
    /* 6E18 8006A178 21104400 */  addu       $v0, $v0, $a0
    /* 6E1C 8006A17C 00004290 */  lbu        $v0, 0x0($v0)
    /* 6E20 8006A180 1400BF8F */  lw         $ra, 0x14($sp)
    /* 6E24 8006A184 1000B08F */  lw         $s0, 0x10($sp)
    /* 6E28 8006A188 0800E003 */  jr         $ra
    /* 6E2C 8006A18C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006A144
