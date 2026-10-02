nonmatching Card_CloseEvents, 0xB4

glabel Card_CloseEvents
    /* 305F0 8003FDF0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 305F4 8003FDF4 1400BFAF */  sw         $ra, 0x14($sp)
    /* 305F8 8003FDF8 F19B000C */  jal        EnterCriticalSection
    /* 305FC 8003FDFC 1000B0AF */   sw        $s0, 0x10($sp)
    /* 30600 8003FE00 0680043C */  lui        $a0, %hi(D_80063060)
    /* 30604 8003FE04 6030848C */  lw         $a0, %lo(D_80063060)($a0)
    /* 30608 8003FE08 7500010C */  jal        CloseEvent
    /* 3060C 8003FE0C 21804000 */   addu      $s0, $v0, $zero
    /* 30610 8003FE10 0680043C */  lui        $a0, %hi(D_80063064)
    /* 30614 8003FE14 6430848C */  lw         $a0, %lo(D_80063064)($a0)
    /* 30618 8003FE18 7500010C */  jal        CloseEvent
    /* 3061C 8003FE1C 00000000 */   nop
    /* 30620 8003FE20 0680043C */  lui        $a0, %hi(D_80063068)
    /* 30624 8003FE24 6830848C */  lw         $a0, %lo(D_80063068)($a0)
    /* 30628 8003FE28 7500010C */  jal        CloseEvent
    /* 3062C 8003FE2C 00000000 */   nop
    /* 30630 8003FE30 0680043C */  lui        $a0, %hi(D_8006306C)
    /* 30634 8003FE34 6C30848C */  lw         $a0, %lo(D_8006306C)($a0)
    /* 30638 8003FE38 7500010C */  jal        CloseEvent
    /* 3063C 8003FE3C 00000000 */   nop
    /* 30640 8003FE40 0680043C */  lui        $a0, %hi(D_80063070)
    /* 30644 8003FE44 7030848C */  lw         $a0, %lo(D_80063070)($a0)
    /* 30648 8003FE48 7500010C */  jal        CloseEvent
    /* 3064C 8003FE4C 00000000 */   nop
    /* 30650 8003FE50 0680043C */  lui        $a0, %hi(D_80063074)
    /* 30654 8003FE54 7430848C */  lw         $a0, %lo(D_80063074)($a0)
    /* 30658 8003FE58 7500010C */  jal        CloseEvent
    /* 3065C 8003FE5C 00000000 */   nop
    /* 30660 8003FE60 0680043C */  lui        $a0, %hi(D_80063078)
    /* 30664 8003FE64 7830848C */  lw         $a0, %lo(D_80063078)($a0)
    /* 30668 8003FE68 7500010C */  jal        CloseEvent
    /* 3066C 8003FE6C 00000000 */   nop
    /* 30670 8003FE70 0680043C */  lui        $a0, %hi(D_8006307C)
    /* 30674 8003FE74 7C30848C */  lw         $a0, %lo(D_8006307C)($a0)
    /* 30678 8003FE78 7500010C */  jal        CloseEvent
    /* 3067C 8003FE7C 00000000 */   nop
    /* 30680 8003FE80 01000224 */  addiu      $v0, $zero, 0x1
    /* 30684 8003FE84 03000216 */  bne        $s0, $v0, .L8003FE94
    /* 30688 8003FE88 00000000 */   nop
    /* 3068C 8003FE8C F59B000C */  jal        ExitCriticalSection
    /* 30690 8003FE90 00000000 */   nop
  .L8003FE94:
    /* 30694 8003FE94 1400BF8F */  lw         $ra, 0x14($sp)
    /* 30698 8003FE98 1000B08F */  lw         $s0, 0x10($sp)
    /* 3069C 8003FE9C 0800E003 */  jr         $ra
    /* 306A0 8003FEA0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Card_CloseEvents
