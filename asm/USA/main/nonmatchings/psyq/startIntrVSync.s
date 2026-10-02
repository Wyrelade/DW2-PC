nonmatching startIntrVSync, 0x58

glabel startIntrVSync
    /* 21C64 80031464 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 21C68 80031468 0580043C */  lui        $a0, %hi(Sys_VSyncCallbacks)
    /* 21C6C 8003146C A0FB8424 */  addiu      $a0, $a0, %lo(Sys_VSyncCallbacks)
    /* 21C70 80031470 0580033C */  lui        $v1, %hi(D_8004FBC4)
    /* 21C74 80031474 C4FB638C */  lw         $v1, %lo(D_8004FBC4)($v1)
    /* 21C78 80031478 00010224 */  addiu      $v0, $zero, 0x100
    /* 21C7C 8003147C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 21C80 80031480 000062AC */  sw         $v0, 0x0($v1)
    /* 21C84 80031484 0580013C */  lui        $at, %hi(Sys_VSyncCount)
    /* 21C88 80031488 C0FB20AC */  sw         $zero, %lo(Sys_VSyncCount)($at)
    /* 21C8C 8003148C 55C5000C */  jal        memclr_vb
    /* 21C90 80031490 08000524 */   addiu     $a1, $zero, 0x8
    /* 21C94 80031494 0380053C */  lui        $a1, %hi(trapIntrVSync)
    /* 21C98 80031498 BC14A524 */  addiu      $a1, $a1, %lo(trapIntrVSync)
    /* 21C9C 8003149C 41C3000C */  jal        InterruptCallback
    /* 21CA0 800314A0 21200000 */   addu      $a0, $zero, $zero
    /* 21CA4 800314A4 0380023C */  lui        $v0, %hi(setIntrVSync)
    /* 21CA8 800314A8 28154224 */  addiu      $v0, $v0, %lo(setIntrVSync)
    /* 21CAC 800314AC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 21CB0 800314B0 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 21CB4 800314B4 0800E003 */  jr         $ra
    /* 21CB8 800314B8 00000000 */   nop
endlabel startIntrVSync
