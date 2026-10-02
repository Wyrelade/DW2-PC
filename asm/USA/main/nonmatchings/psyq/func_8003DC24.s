nonmatching func_8003DC24, 0x70

glabel func_8003DC24
    /* 2E424 8003DC24 0680013C */  lui        $at, %hi(D_80062F40)
    /* 2E428 8003DC28 402F3FAC */  sw         $ra, %lo(D_80062F40)($at)
    /* 2E42C 8003DC2C F19B000C */  jal        EnterCriticalSection
    /* 2E430 8003DC30 00000000 */   nop
    /* 2E434 8003DC34 56000924 */  addiu      $t1, $zero, 0x56
    /* 2E438 8003DC38 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 2E43C 8003DC3C 09F84001 */  jalr       $t2
    /* 2E440 8003DC40 00000000 */   nop
    /* 2E444 8003DC44 1800428C */  lw         $v0, 0x18($v0)
    /* 2E448 8003DC48 04800A3C */  lui        $t2, %hi(D_8003DC94)
    /* 2E44C 8003DC4C 94DC4A25 */  addiu      $t2, $t2, %lo(D_8003DC94)
    /* 2E450 8003DC50 0480093C */  lui        $t1, %hi(D_8003DCA0)
    /* 2E454 8003DC54 A0DC2925 */  addiu      $t1, $t1, %lo(D_8003DCA0)
  .L8003DC58:
    /* 2E458 8003DC58 0000438D */  lw         $v1, 0x0($t2)
    /* 2E45C 8003DC5C 00000000 */  nop
    /* 2E460 8003DC60 700043AC */  sw         $v1, 0x70($v0)
    /* 2E464 8003DC64 04004A25 */  addiu      $t2, $t2, 0x4
    /* 2E468 8003DC68 FBFF4915 */  bne        $t2, $t1, .L8003DC58
    /* 2E46C 8003DC6C 04004224 */   addiu     $v0, $v0, 0x4
    /* 2E470 8003DC70 E9B6000C */  jal        FlushCache
    /* 2E474 8003DC74 00000000 */   nop
    /* 2E478 8003DC78 F59B000C */  jal        ExitCriticalSection
    /* 2E47C 8003DC7C 00000000 */   nop
    /* 2E480 8003DC80 06801F3C */  lui        $ra, %hi(D_80062F40)
    /* 2E484 8003DC84 402FFF8F */  lw         $ra, %lo(D_80062F40)($ra)
    /* 2E488 8003DC88 00000000 */  nop
    /* 2E48C 8003DC8C 0800E003 */  jr         $ra
    /* 2E490 8003DC90 00000000 */   nop
endlabel func_8003DC24
  alabel D_8003DC94
    /* 2E494 8003DC94 00000000 */  nop
    /* 2E498 8003DC98 00000000 */  nop
    /* 2E49C 8003DC9C 00000000 */  nop
  alabel D_8003DCA0
    /* 2E4A0 8003DCA0 00000000 */  nop
