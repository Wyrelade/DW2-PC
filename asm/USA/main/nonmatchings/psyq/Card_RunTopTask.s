nonmatching Card_RunTopTask, 0x6C

glabel Card_RunTopTask
    /* 302A0 8003FAA0 0580033C */  lui        $v1, %hi(Card_TaskTop)
    /* 302A4 8003FAA4 E806638C */  lw         $v1, %lo(Card_TaskTop)($v1)
    /* 302A8 8003FAA8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 302AC 8003FAAC 13006004 */  bltz       $v1, .L8003FAFC
    /* 302B0 8003FAB0 1000BFAF */   sw        $ra, 0x10($sp)
    /* 302B4 8003FAB4 80100300 */  sll        $v0, $v1, 2
    /* 302B8 8003FAB8 00190300 */  sll        $v1, $v1, 4
    /* 302BC 8003FABC 0680043C */  lui        $a0, %hi(Card_TaskWork)
    /* 302C0 8003FAC0 10308424 */  addiu      $a0, $a0, %lo(Card_TaskWork)
    /* 302C4 8003FAC4 0680013C */  lui        $at, %hi(Card_TaskFuncs)
    /* 302C8 8003FAC8 21082200 */  addu       $at, $at, $v0
    /* 302CC 8003FACC 5030228C */  lw         $v0, %lo(Card_TaskFuncs)($at)
    /* 302D0 8003FAD0 00000000 */  nop
    /* 302D4 8003FAD4 09F84000 */  jalr       $v0
    /* 302D8 8003FAD8 21206400 */   addu      $a0, $v1, $a0
    /* 302DC 8003FADC 07004010 */  beqz       $v0, .L8003FAFC
    /* 302E0 8003FAE0 00000000 */   nop
    /* 302E4 8003FAE4 0580023C */  lui        $v0, %hi(Card_TaskTop)
    /* 302E8 8003FAE8 E806428C */  lw         $v0, %lo(Card_TaskTop)($v0)
    /* 302EC 8003FAEC 00000000 */  nop
    /* 302F0 8003FAF0 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 302F4 8003FAF4 0580013C */  lui        $at, %hi(Card_TaskTop)
    /* 302F8 8003FAF8 E80622AC */  sw         $v0, %lo(Card_TaskTop)($at)
  .L8003FAFC:
    /* 302FC 8003FAFC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 30300 8003FB00 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 30304 8003FB04 0800E003 */  jr         $ra
    /* 30308 8003FB08 00000000 */   nop
endlabel Card_RunTopTask
