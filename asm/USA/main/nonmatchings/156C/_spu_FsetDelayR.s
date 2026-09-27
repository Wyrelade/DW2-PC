nonmatching _spu_FsetDelayR, 0x28

glabel _spu_FsetDelayR
    /* 2B484 8003AC84 0580043C */  lui        $a0, %hi(D_8004FE3C)
    /* 2B488 8003AC88 3CFE848C */  lw         $a0, %lo(D_8004FE3C)($a0)
    /* 2B48C 8003AC8C FFF0033C */  lui        $v1, (0xF0FFFFFF >> 16)
    /* 2B490 8003AC90 0000828C */  lw         $v0, 0x0($a0)
    /* 2B494 8003AC94 FFFF6334 */  ori        $v1, $v1, (0xF0FFFFFF & 0xFFFF)
    /* 2B498 8003AC98 24104300 */  and        $v0, $v0, $v1
    /* 2B49C 8003AC9C 0022033C */  lui        $v1, (0x22000000 >> 16)
    /* 2B4A0 8003ACA0 25104300 */  or         $v0, $v0, $v1
    /* 2B4A4 8003ACA4 0800E003 */  jr         $ra
    /* 2B4A8 8003ACA8 000082AC */   sw        $v0, 0x0($a0)
endlabel _spu_FsetDelayR
