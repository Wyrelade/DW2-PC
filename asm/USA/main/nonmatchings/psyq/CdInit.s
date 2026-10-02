nonmatching CdInit, 0x90

glabel CdInit
    /* 1E404 8002DC04 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1E408 8002DC08 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1E40C 8002DC0C 04001024 */  addiu      $s0, $zero, 0x4
    /* 1E410 8002DC10 1400BFAF */  sw         $ra, 0x14($sp)
  .L8002DC14:
    /* 1E414 8002DC14 25B7000C */  jal        func_8002DC94
    /* 1E418 8002DC18 00000000 */   nop
    /* 1E41C 8002DC1C 01000324 */  addiu      $v1, $zero, 0x1
    /* 1E420 8002DC20 10004314 */  bne        $v0, $v1, .L8002DC64
    /* 1E424 8002DC24 01000224 */   addiu     $v0, $zero, 0x1
    /* 1E428 8002DC28 0380033C */  lui        $v1, %hi(def_cbsync)
    /* 1E42C 8002DC2C D0DC6324 */  addiu      $v1, $v1, %lo(def_cbsync)
    /* 1E430 8002DC30 0580013C */  lui        $at, %hi(D_8004E6C8)
    /* 1E434 8002DC34 C8E623AC */  sw         $v1, %lo(D_8004E6C8)($at)
    /* 1E438 8002DC38 0380033C */  lui        $v1, %hi(def_cbready)
    /* 1E43C 8002DC3C F8DC6324 */  addiu      $v1, $v1, %lo(def_cbready)
    /* 1E440 8002DC40 0580013C */  lui        $at, %hi(D_8004E6CC)
    /* 1E444 8002DC44 CCE623AC */  sw         $v1, %lo(D_8004E6CC)($at)
    /* 1E448 8002DC48 0380033C */  lui        $v1, %hi(def_cbread)
    /* 1E44C 8002DC4C 20DD6324 */  addiu      $v1, $v1, %lo(def_cbread)
    /* 1E450 8002DC50 0580013C */  lui        $at, %hi(D_8004E5E0)
    /* 1E454 8002DC54 E0E523AC */  sw         $v1, %lo(D_8004E5E0)($at)
    /* 1E458 8002DC58 0580013C */  lui        $at, %hi(D_8004E5E4)
    /* 1E45C 8002DC5C 21B70008 */  j          .L8002DC84
    /* 1E460 8002DC60 E4E520AC */   sw        $zero, %lo(D_8004E5E4)($at)
  .L8002DC64:
    /* 1E464 8002DC64 FFFF1026 */  addiu      $s0, $s0, -0x1
    /* 1E468 8002DC68 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 1E46C 8002DC6C E9FF0216 */  bne        $s0, $v0, .L8002DC14
    /* 1E470 8002DC70 00000000 */   nop
    /* 1E474 8002DC74 0180043C */  lui        $a0, %hi(D_800106D4)
    /* 1E478 8002DC78 05A8000C */  jal        printf
    /* 1E47C 8002DC7C D4068424 */   addiu     $a0, $a0, %lo(D_800106D4)
    /* 1E480 8002DC80 21100000 */  addu       $v0, $zero, $zero
  .L8002DC84:
    /* 1E484 8002DC84 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1E488 8002DC88 1000B08F */  lw         $s0, 0x10($sp)
    /* 1E48C 8002DC8C 0800E003 */  jr         $ra
    /* 1E490 8002DC90 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel CdInit
