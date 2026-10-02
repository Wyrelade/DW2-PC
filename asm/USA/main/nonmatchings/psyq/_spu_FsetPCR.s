nonmatching _spu_FsetPCR, 0x58

glabel _spu_FsetPCR
    /* 2B404 8003AC04 0580053C */  lui        $a1, %hi(D_8004FE38)
    /* 2B408 8003AC08 38FEA58C */  lw         $a1, %lo(D_8004FE38)($a1)
    /* 2B40C 8003AC0C F8FF033C */  lui        $v1, (0xFFF8FFFF >> 16)
    /* 2B410 8003AC10 0000A28C */  lw         $v0, 0x0($a1)
    /* 2B414 8003AC14 FFFF6334 */  ori        $v1, $v1, (0xFFF8FFFF & 0xFFFF)
    /* 2B418 8003AC18 24104300 */  and        $v0, $v0, $v1
    /* 2B41C 8003AC1C 07008010 */  beqz       $a0, .L8003AC3C
    /* 2B420 8003AC20 0000A2AC */   sw        $v0, 0x0($a1)
    /* 2B424 8003AC24 0580023C */  lui        $v0, %hi(D_8004FE38)
    /* 2B428 8003AC28 38FE428C */  lw         $v0, %lo(D_8004FE38)($v0)
    /* 2B42C 8003AC2C 00000000 */  nop
    /* 2B430 8003AC30 0000438C */  lw         $v1, 0x0($v0)
    /* 2B434 8003AC34 14EB0008 */  j          .L8003AC50
    /* 2B438 8003AC38 0300043C */   lui       $a0, (0x30000 >> 16)
  .L8003AC3C:
    /* 2B43C 8003AC3C 0580023C */  lui        $v0, %hi(D_8004FE38)
    /* 2B440 8003AC40 38FE428C */  lw         $v0, %lo(D_8004FE38)($v0)
    /* 2B444 8003AC44 00000000 */  nop
    /* 2B448 8003AC48 0000438C */  lw         $v1, 0x0($v0)
    /* 2B44C 8003AC4C 0500043C */  lui        $a0, (0x50000 >> 16)
  .L8003AC50:
    /* 2B450 8003AC50 25186400 */  or         $v1, $v1, $a0
    /* 2B454 8003AC54 0800E003 */  jr         $ra
    /* 2B458 8003AC58 000043AC */   sw        $v1, 0x0($v0)
endlabel _spu_FsetPCR
