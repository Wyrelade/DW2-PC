nonmatching GsSetDrawBuffClip, 0x78

glabel GsSetDrawBuffClip
    /* 1BAB4 8002B2B4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1BAB8 8002B2B8 0680023C */  lui        $v0, %hi(D_8006198C)
    /* 1BABC 8002B2BC 8C194284 */  lh         $v0, %lo(D_8006198C)($v0)
    /* 1BAC0 8002B2C0 0680033C */  lui        $v1, %hi(D_80061980)
    /* 1BAC4 8002B2C4 80196324 */  addiu      $v1, $v1, %lo(D_80061980)
    /* 1BAC8 8002B2C8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1BACC 8002B2CC 06006594 */  lhu        $a1, 0x6($v1)
    /* 1BAD0 8002B2D0 40100200 */  sll        $v0, $v0, 1
    /* 1BAD4 8002B2D4 0680063C */  lui        $a2, %hi(D_800618F0)
    /* 1BAD8 8002B2D8 2130C200 */  addu       $a2, $a2, $v0
    /* 1BADC 8002B2DC F018C684 */  lh         $a2, %lo(D_800618F0)($a2)
    /* 1BAE0 8002B2E0 0680073C */  lui        $a3, %hi(D_800618F4)
    /* 1BAE4 8002B2E4 2138E200 */  addu       $a3, $a3, $v0
    /* 1BAE8 8002B2E8 F418E784 */  lh         $a3, %lo(D_800618F4)($a3)
    /* 1BAEC 8002B2EC 04006294 */  lhu        $v0, 0x4($v1)
    /* 1BAF0 8002B2F0 0680043C */  lui        $a0, %hi(D_80061908)
    /* 1BAF4 8002B2F4 08198424 */  addiu      $a0, $a0, %lo(D_80061908)
    /* 1BAF8 8002B2F8 060085A4 */  sh         $a1, 0x6($a0)
    /* 1BAFC 8002B2FC 040082A4 */  sh         $v0, 0x4($a0)
    /* 1BB00 8002B300 00006284 */  lh         $v0, 0x0($v1)
    /* 1BB04 8002B304 02006384 */  lh         $v1, 0x2($v1)
    /* 1BB08 8002B308 21104600 */  addu       $v0, $v0, $a2
    /* 1BB0C 8002B30C 21186700 */  addu       $v1, $v1, $a3
    /* 1BB10 8002B310 000082A4 */  sh         $v0, 0x0($a0)
    /* 1BB14 8002B314 B99E000C */  jal        PutDrawEnv
    /* 1BB18 8002B318 020083A4 */   sh        $v1, 0x2($a0)
    /* 1BB1C 8002B31C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1BB20 8002B320 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 1BB24 8002B324 0800E003 */  jr         $ra
    /* 1BB28 8002B328 00000000 */   nop
endlabel GsSetDrawBuffClip
    /* 1BB2C 8002B32C 00000000 */  nop
    /* 1BB30 8002B330 00000000 */  nop
