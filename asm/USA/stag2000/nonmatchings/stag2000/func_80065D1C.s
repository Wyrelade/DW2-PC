nonmatching func_80065D1C, 0x58

glabel func_80065D1C
    /* 29BC 80065D1C 0680043C */  lui        $a0, %hi(Save_GameState)
    /* 29C0 80065D20 20E68424 */  addiu      $a0, $a0, %lo(Save_GameState)
    /* 29C4 80065D24 0780033C */  lui        $v1, %hi(D_8006FCCC)
    /* 29C8 80065D28 2E008294 */  lhu        $v0, 0x2E($a0)
    /* 29CC 80065D2C CCFC6324 */  addiu      $v1, $v1, %lo(D_8006FCCC)
    /* 29D0 80065D30 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 29D4 80065D34 40100200 */  sll        $v0, $v0, 1
    /* 29D8 80065D38 21104300 */  addu       $v0, $v0, $v1
    /* 29DC 80065D3C 00004294 */  lhu        $v0, 0x0($v0)
    /* 29E0 80065D40 0780033C */  lui        $v1, %hi(D_8006FD28)
    /* 29E4 80065D44 240082A4 */  sh         $v0, 0x24($a0)
    /* 29E8 80065D48 260082A4 */  sh         $v0, 0x26($a0)
    /* 29EC 80065D4C 32008294 */  lhu        $v0, 0x32($a0)
    /* 29F0 80065D50 28FD6324 */  addiu      $v1, $v1, %lo(D_8006FD28)
    /* 29F4 80065D54 CBFF4224 */  addiu      $v0, $v0, -0x35
    /* 29F8 80065D58 40100200 */  sll        $v0, $v0, 1
    /* 29FC 80065D5C 21104300 */  addu       $v0, $v0, $v1
    /* 2A00 80065D60 00004294 */  lhu        $v0, 0x0($v0)
    /* 2A04 80065D64 00000000 */  nop
    /* 2A08 80065D68 280082A4 */  sh         $v0, 0x28($a0)
    /* 2A0C 80065D6C 0800E003 */  jr         $ra
    /* 2A10 80065D70 2A0082A4 */   sh        $v0, 0x2A($a0)
endlabel func_80065D1C
