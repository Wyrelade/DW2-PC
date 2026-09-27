nonmatching func_8003DD00, 0x70

glabel func_8003DD00
    /* 2E500 8003DD00 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2E504 8003DD04 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2E508 8003DD08 0680103C */  lui        $s0, %hi(D_80062F80)
    /* 2E50C 8003DD0C 802F1026 */  addiu      $s0, $s0, %lo(D_80062F80)
    /* 2E510 8003DD10 1400BFAF */  sw         $ra, 0x14($sp)
    /* 2E514 8003DD14 0C0000AE */  sw         $zero, 0xC($s0)
    /* 2E518 8003DD18 85FE000C */  jal        Card_ClearTaskStack
    /* 2E51C 8003DD1C 440000AE */   sw        $zero, 0x44($s0)
    /* 2E520 8003DD20 000000AE */  sw         $zero, 0x0($s0)
    /* 2E524 8003DD24 040000AE */  sw         $zero, 0x4($s0)
    /* 2E528 8003DD28 080000AE */  sw         $zero, 0x8($s0)
    /* 2E52C 8003DD2C 540000AE */  sw         $zero, 0x54($s0)
    /* 2E530 8003DD30 5400038E */  lw         $v1, 0x54($s0)
    /* 2E534 8003DD34 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 2E538 8003DD38 140002AE */  sw         $v0, 0x14($s0)
    /* 2E53C 8003DD3C 01000224 */  addiu      $v0, $zero, 0x1
    /* 2E540 8003DD40 4C0002AE */  sw         $v0, 0x4C($s0)
    /* 2E544 8003DD44 480002AE */  sw         $v0, 0x48($s0)
    /* 2E548 8003DD48 FDFE000C */  jal        func_8003FBF4
    /* 2E54C 8003DD4C 500003AE */   sw        $v1, 0x50($s0)
    /* 2E550 8003DD50 0480053C */  lui        $a1, %hi(Card_OnVSync)
    /* 2E554 8003DD54 6CF4A524 */  addiu      $a1, $a1, %lo(Card_OnVSync)
    /* 2E558 8003DD58 66C3000C */  jal        VSyncCallbacks
    /* 2E55C 8003DD5C 07000424 */   addiu     $a0, $zero, 0x7
    /* 2E560 8003DD60 1400BF8F */  lw         $ra, 0x14($sp)
    /* 2E564 8003DD64 1000B08F */  lw         $s0, 0x10($sp)
    /* 2E568 8003DD68 0800E003 */  jr         $ra
    /* 2E56C 8003DD6C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8003DD00
