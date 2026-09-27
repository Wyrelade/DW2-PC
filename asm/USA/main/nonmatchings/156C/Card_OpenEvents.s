nonmatching Card_OpenEvents, 0x1DC

glabel Card_OpenEvents
    /* 303F4 8003FBF4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 303F8 8003FBF8 1400BFAF */  sw         $ra, 0x14($sp)
    /* 303FC 8003FBFC F19B000C */  jal        EnterCriticalSection
    /* 30400 8003FC00 1000B0AF */   sw        $s0, 0x10($sp)
    /* 30404 8003FC04 00F4043C */  lui        $a0, (0xF4000001 >> 16)
    /* 30408 8003FC08 01008434 */  ori        $a0, $a0, (0xF4000001 & 0xFFFF)
    /* 3040C 8003FC0C 04000524 */  addiu      $a1, $zero, 0x4
    /* 30410 8003FC10 00100624 */  addiu      $a2, $zero, 0x1000
    /* 30414 8003FC14 0480073C */  lui        $a3, %hi(Card_OnSwIoe)
    /* 30418 8003FC18 24FBE724 */  addiu      $a3, $a3, %lo(Card_OnSwIoe)
    /* 3041C 8003FC1C 6DE8000C */  jal        OpenEvent
    /* 30420 8003FC20 21804000 */   addu      $s0, $v0, $zero
    /* 30424 8003FC24 00F4043C */  lui        $a0, (0xF4000001 >> 16)
    /* 30428 8003FC28 01008434 */  ori        $a0, $a0, (0xF4000001 & 0xFFFF)
    /* 3042C 8003FC2C 00800534 */  ori        $a1, $zero, 0x8000
    /* 30430 8003FC30 0480073C */  lui        $a3, %hi(Card_OnSwError)
    /* 30434 8003FC34 38FBE724 */  addiu      $a3, $a3, %lo(Card_OnSwError)
    /* 30438 8003FC38 0680013C */  lui        $at, %hi(D_80063060)
    /* 3043C 8003FC3C 603022AC */  sw         $v0, %lo(D_80063060)($at)
    /* 30440 8003FC40 6DE8000C */  jal        OpenEvent
    /* 30444 8003FC44 00100624 */   addiu     $a2, $zero, 0x1000
    /* 30448 8003FC48 00F4043C */  lui        $a0, (0xF4000001 >> 16)
    /* 3044C 8003FC4C 01008434 */  ori        $a0, $a0, (0xF4000001 & 0xFFFF)
    /* 30450 8003FC50 00010524 */  addiu      $a1, $zero, 0x100
    /* 30454 8003FC54 0480073C */  lui        $a3, %hi(Card_OnSwTimeout)
    /* 30458 8003FC58 4CFBE724 */  addiu      $a3, $a3, %lo(Card_OnSwTimeout)
    /* 3045C 8003FC5C 0680013C */  lui        $at, %hi(D_80063064)
    /* 30460 8003FC60 643022AC */  sw         $v0, %lo(D_80063064)($at)
    /* 30464 8003FC64 6DE8000C */  jal        OpenEvent
    /* 30468 8003FC68 00100624 */   addiu     $a2, $zero, 0x1000
    /* 3046C 8003FC6C 00F4043C */  lui        $a0, (0xF4000001 >> 16)
    /* 30470 8003FC70 01008434 */  ori        $a0, $a0, (0xF4000001 & 0xFFFF)
    /* 30474 8003FC74 00200524 */  addiu      $a1, $zero, 0x2000
    /* 30478 8003FC78 0480073C */  lui        $a3, %hi(Card_OnSwNewCard)
    /* 3047C 8003FC7C 60FBE724 */  addiu      $a3, $a3, %lo(Card_OnSwNewCard)
    /* 30480 8003FC80 0680013C */  lui        $at, %hi(D_80063068)
    /* 30484 8003FC84 683022AC */  sw         $v0, %lo(D_80063068)($at)
    /* 30488 8003FC88 6DE8000C */  jal        OpenEvent
    /* 3048C 8003FC8C 00100624 */   addiu     $a2, $zero, 0x1000
    /* 30490 8003FC90 00F0043C */  lui        $a0, (0xF0000011 >> 16)
    /* 30494 8003FC94 11008434 */  ori        $a0, $a0, (0xF0000011 & 0xFFFF)
    /* 30498 8003FC98 04000524 */  addiu      $a1, $zero, 0x4
    /* 3049C 8003FC9C 0480073C */  lui        $a3, %hi(Card_OnHwIoe)
    /* 304A0 8003FCA0 74FBE724 */  addiu      $a3, $a3, %lo(Card_OnHwIoe)
    /* 304A4 8003FCA4 0680013C */  lui        $at, %hi(D_8006306C)
    /* 304A8 8003FCA8 6C3022AC */  sw         $v0, %lo(D_8006306C)($at)
    /* 304AC 8003FCAC 6DE8000C */  jal        OpenEvent
    /* 304B0 8003FCB0 00100624 */   addiu     $a2, $zero, 0x1000
    /* 304B4 8003FCB4 00F0043C */  lui        $a0, (0xF0000011 >> 16)
    /* 304B8 8003FCB8 11008434 */  ori        $a0, $a0, (0xF0000011 & 0xFFFF)
    /* 304BC 8003FCBC 00800534 */  ori        $a1, $zero, 0x8000
    /* 304C0 8003FCC0 0480073C */  lui        $a3, %hi(Card_OnHwError)
    /* 304C4 8003FCC4 88FBE724 */  addiu      $a3, $a3, %lo(Card_OnHwError)
    /* 304C8 8003FCC8 0680013C */  lui        $at, %hi(D_80063070)
    /* 304CC 8003FCCC 703022AC */  sw         $v0, %lo(D_80063070)($at)
    /* 304D0 8003FCD0 6DE8000C */  jal        OpenEvent
    /* 304D4 8003FCD4 00100624 */   addiu     $a2, $zero, 0x1000
    /* 304D8 8003FCD8 00F0043C */  lui        $a0, (0xF0000011 >> 16)
    /* 304DC 8003FCDC 11008434 */  ori        $a0, $a0, (0xF0000011 & 0xFFFF)
    /* 304E0 8003FCE0 00010524 */  addiu      $a1, $zero, 0x100
    /* 304E4 8003FCE4 0480073C */  lui        $a3, %hi(Card_OnHwTimeout)
    /* 304E8 8003FCE8 9CFBE724 */  addiu      $a3, $a3, %lo(Card_OnHwTimeout)
    /* 304EC 8003FCEC 0680013C */  lui        $at, %hi(D_80063074)
    /* 304F0 8003FCF0 743022AC */  sw         $v0, %lo(D_80063074)($at)
    /* 304F4 8003FCF4 6DE8000C */  jal        OpenEvent
    /* 304F8 8003FCF8 00100624 */   addiu     $a2, $zero, 0x1000
    /* 304FC 8003FCFC 00F0043C */  lui        $a0, (0xF0000011 >> 16)
    /* 30500 8003FD00 11008434 */  ori        $a0, $a0, (0xF0000011 & 0xFFFF)
    /* 30504 8003FD04 00200524 */  addiu      $a1, $zero, 0x2000
    /* 30508 8003FD08 0480073C */  lui        $a3, %hi(Card_OnHwNewCard)
    /* 3050C 8003FD0C B0FBE724 */  addiu      $a3, $a3, %lo(Card_OnHwNewCard)
    /* 30510 8003FD10 0680013C */  lui        $at, %hi(D_80063078)
    /* 30514 8003FD14 783022AC */  sw         $v0, %lo(D_80063078)($at)
    /* 30518 8003FD18 6DE8000C */  jal        OpenEvent
    /* 3051C 8003FD1C 00100624 */   addiu     $a2, $zero, 0x1000
    /* 30520 8003FD20 0680043C */  lui        $a0, %hi(D_80063060)
    /* 30524 8003FD24 6030848C */  lw         $a0, %lo(D_80063060)($a0)
    /* 30528 8003FD28 0680013C */  lui        $at, %hi(D_8006307C)
    /* 3052C 8003FD2C 71E8000C */  jal        EnableEvent
    /* 30530 8003FD30 7C3022AC */   sw        $v0, %lo(D_8006307C)($at)
    /* 30534 8003FD34 0680043C */  lui        $a0, %hi(D_80063064)
    /* 30538 8003FD38 6430848C */  lw         $a0, %lo(D_80063064)($a0)
    /* 3053C 8003FD3C 71E8000C */  jal        EnableEvent
    /* 30540 8003FD40 00000000 */   nop
    /* 30544 8003FD44 0680043C */  lui        $a0, %hi(D_80063068)
    /* 30548 8003FD48 6830848C */  lw         $a0, %lo(D_80063068)($a0)
    /* 3054C 8003FD4C 71E8000C */  jal        EnableEvent
    /* 30550 8003FD50 00000000 */   nop
    /* 30554 8003FD54 0680043C */  lui        $a0, %hi(D_8006306C)
    /* 30558 8003FD58 6C30848C */  lw         $a0, %lo(D_8006306C)($a0)
    /* 3055C 8003FD5C 71E8000C */  jal        EnableEvent
    /* 30560 8003FD60 00000000 */   nop
    /* 30564 8003FD64 0680043C */  lui        $a0, %hi(D_80063070)
    /* 30568 8003FD68 7030848C */  lw         $a0, %lo(D_80063070)($a0)
    /* 3056C 8003FD6C 71E8000C */  jal        EnableEvent
    /* 30570 8003FD70 00000000 */   nop
    /* 30574 8003FD74 0680043C */  lui        $a0, %hi(D_80063074)
    /* 30578 8003FD78 7430848C */  lw         $a0, %lo(D_80063074)($a0)
    /* 3057C 8003FD7C 71E8000C */  jal        EnableEvent
    /* 30580 8003FD80 00000000 */   nop
    /* 30584 8003FD84 0680043C */  lui        $a0, %hi(D_80063078)
    /* 30588 8003FD88 7830848C */  lw         $a0, %lo(D_80063078)($a0)
    /* 3058C 8003FD8C 71E8000C */  jal        EnableEvent
    /* 30590 8003FD90 00000000 */   nop
    /* 30594 8003FD94 0680043C */  lui        $a0, %hi(D_8006307C)
    /* 30598 8003FD98 7C30848C */  lw         $a0, %lo(D_8006307C)($a0)
    /* 3059C 8003FD9C 71E8000C */  jal        EnableEvent
    /* 305A0 8003FDA0 00000000 */   nop
    /* 305A4 8003FDA4 A9FF000C */  jal        Card_ClearEvents
    /* 305A8 8003FDA8 00000000 */   nop
    /* 305AC 8003FDAC 01000224 */  addiu      $v0, $zero, 0x1
    /* 305B0 8003FDB0 03000216 */  bne        $s0, $v0, .L8003FDC0
    /* 305B4 8003FDB4 00000000 */   nop
    /* 305B8 8003FDB8 F59B000C */  jal        ExitCriticalSection
    /* 305BC 8003FDBC 00000000 */   nop
  .L8003FDC0:
    /* 305C0 8003FDC0 1400BF8F */  lw         $ra, 0x14($sp)
    /* 305C4 8003FDC4 1000B08F */  lw         $s0, 0x10($sp)
    /* 305C8 8003FDC8 0800E003 */  jr         $ra
    /* 305CC 8003FDCC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Card_OpenEvents
