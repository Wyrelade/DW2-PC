nonmatching GsInitCoordinate2, 0x70

glabel GsInitCoordinate2
    /* 1BC24 8002B424 2138A000 */  addu       $a3, $a1, $zero
    /* 1BC28 8002B428 0680063C */  lui        $a2, %hi(D_80061A28)
    /* 1BC2C 8002B42C 281AC624 */  addiu      $a2, $a2, %lo(D_80061A28)
    /* 1BC30 8002B430 0000C28C */  lw         $v0, 0x0($a2)
    /* 1BC34 8002B434 0400C38C */  lw         $v1, 0x4($a2)
    /* 1BC38 8002B438 0800C58C */  lw         $a1, 0x8($a2)
    /* 1BC3C 8002B43C 0400E2AC */  sw         $v0, 0x4($a3)
    /* 1BC40 8002B440 0800E3AC */  sw         $v1, 0x8($a3)
    /* 1BC44 8002B444 0C00E5AC */  sw         $a1, 0xC($a3)
    /* 1BC48 8002B448 0C00C28C */  lw         $v0, 0xC($a2)
    /* 1BC4C 8002B44C 1000C38C */  lw         $v1, 0x10($a2)
    /* 1BC50 8002B450 1400C58C */  lw         $a1, 0x14($a2)
    /* 1BC54 8002B454 1000E2AC */  sw         $v0, 0x10($a3)
    /* 1BC58 8002B458 1400E3AC */  sw         $v1, 0x14($a3)
    /* 1BC5C 8002B45C 1800E5AC */  sw         $a1, 0x18($a3)
    /* 1BC60 8002B460 1800C28C */  lw         $v0, 0x18($a2)
    /* 1BC64 8002B464 1C00C38C */  lw         $v1, 0x1C($a2)
    /* 1BC68 8002B468 1C00E2AC */  sw         $v0, 0x1C($a3)
    /* 1BC6C 8002B46C 2000E3AC */  sw         $v1, 0x20($a3)
    /* 1BC70 8002B470 4800E4AC */  sw         $a0, 0x48($a3)
    /* 1BC74 8002B474 0200842C */  sltiu      $a0, $a0, 0x2
    /* 1BC78 8002B478 04008014 */  bnez       $a0, .L8002B48C
    /* 1BC7C 8002B47C 0000E0AC */   sw        $zero, 0x0($a3)
    /* 1BC80 8002B480 4800E28C */  lw         $v0, 0x48($a3)
    /* 1BC84 8002B484 00000000 */  nop
    /* 1BC88 8002B488 4C0047AC */  sw         $a3, 0x4C($v0)
  .L8002B48C:
    /* 1BC8C 8002B48C 0800E003 */  jr         $ra
    /* 1BC90 8002B490 00000000 */   nop
endlabel GsInitCoordinate2
