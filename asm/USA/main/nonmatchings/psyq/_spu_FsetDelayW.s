nonmatching _spu_FsetDelayW, 0x28

glabel _spu_FsetDelayW
    /* 2B45C 8003AC5C 0580043C */  lui        $a0, %hi(D_8004FE3C)
    /* 2B460 8003AC60 3CFE848C */  lw         $a0, %lo(D_8004FE3C)($a0)
    /* 2B464 8003AC64 FFF0033C */  lui        $v1, (0xF0FFFFFF >> 16)
    /* 2B468 8003AC68 0000828C */  lw         $v0, 0x0($a0)
    /* 2B46C 8003AC6C FFFF6334 */  ori        $v1, $v1, (0xF0FFFFFF & 0xFFFF)
    /* 2B470 8003AC70 24104300 */  and        $v0, $v0, $v1
    /* 2B474 8003AC74 0020033C */  lui        $v1, (0x20000000 >> 16)
    /* 2B478 8003AC78 25104300 */  or         $v0, $v0, $v1
    /* 2B47C 8003AC7C 0800E003 */  jr         $ra
    /* 2B480 8003AC80 000082AC */   sw        $v0, 0x0($a0)
endlabel _spu_FsetDelayW
