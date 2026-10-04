nonmatching DecDCTPutEnv, 0x98

glabel DecDCTPutEnv
    /* 1420 80064780 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1424 80064784 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1428 80064788 21808000 */  addu       $s0, $a0, $zero
    /* 142C 8006478C 0680053C */  lui        $a1, %hi(D_8006525C)
    /* 1430 80064790 5C52A524 */  addiu      $a1, $a1, %lo(D_8006525C)
    /* 1434 80064794 0F000324 */  addiu      $v1, $zero, 0xF
    /* 1438 80064798 FFFF0624 */  addiu      $a2, $zero, -0x1
    /* 143C 8006479C 1400BFAF */  sw         $ra, 0x14($sp)
  .L800647A0:
    /* 1440 800647A0 0000828C */  lw         $v0, 0x0($a0)
    /* 1444 800647A4 04008424 */  addiu      $a0, $a0, 0x4
    /* 1448 800647A8 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 144C 800647AC 0000A2AC */  sw         $v0, 0x0($a1)
    /* 1450 800647B0 FBFF6614 */  bne        $v1, $a2, .L800647A0
    /* 1454 800647B4 0400A524 */   addiu     $a1, $a1, 0x4
    /* 1458 800647B8 0680053C */  lui        $a1, %hi(D_8006529C)
    /* 145C 800647BC 9C52A524 */  addiu      $a1, $a1, %lo(D_8006529C)
    /* 1460 800647C0 40000426 */  addiu      $a0, $s0, 0x40
    /* 1464 800647C4 0F000324 */  addiu      $v1, $zero, 0xF
    /* 1468 800647C8 FFFF0624 */  addiu      $a2, $zero, -0x1
  .L800647CC:
    /* 146C 800647CC 0000828C */  lw         $v0, 0x0($a0)
    /* 1470 800647D0 04008424 */  addiu      $a0, $a0, 0x4
    /* 1474 800647D4 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 1478 800647D8 0000A2AC */  sw         $v0, 0x0($a1)
    /* 147C 800647DC FBFF6614 */  bne        $v1, $a2, .L800647CC
    /* 1480 800647E0 0400A524 */   addiu     $a1, $a1, 0x4
    /* 1484 800647E4 0680043C */  lui        $a0, %hi(D_80065258)
    /* 1488 800647E8 58528424 */  addiu      $a0, $a0, %lo(D_80065258)
    /* 148C 800647EC 9C92010C */  jal        MDEC_in
    /* 1490 800647F0 20000524 */   addiu     $a1, $zero, 0x20
    /* 1494 800647F4 0680043C */  lui        $a0, %hi(D_800652DC)
    /* 1498 800647F8 DC528424 */  addiu      $a0, $a0, %lo(D_800652DC)
    /* 149C 800647FC 9C92010C */  jal        MDEC_in
    /* 14A0 80064800 20000524 */   addiu     $a1, $zero, 0x20
    /* 14A4 80064804 21100002 */  addu       $v0, $s0, $zero
    /* 14A8 80064808 1400BF8F */  lw         $ra, 0x14($sp)
    /* 14AC 8006480C 1000B08F */  lw         $s0, 0x10($sp)
    /* 14B0 80064810 0800E003 */  jr         $ra
    /* 14B4 80064814 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel DecDCTPutEnv
