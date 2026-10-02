nonmatching func_800266D0, 0x48

glabel func_800266D0
    /* 16ED0 800266D0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 16ED4 800266D4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 16ED8 800266D8 0580023C */  lui        $v0, %hi(D_80048E30)
    /* 16EDC 800266DC 308E428C */  lw         $v0, %lo(D_80048E30)($v0)
    /* 16EE0 800266E0 1400BFAF */  sw         $ra, 0x14($sp)
    /* 16EE4 800266E4 09F84000 */  jalr       $v0
    /* 16EE8 800266E8 21808000 */   addu      $s0, $a0, $zero
    /* 16EEC 800266EC 21200002 */  addu       $a0, $s0, $zero
    /* 16EF0 800266F0 3C00038E */  lw         $v1, 0x3C($s0)
    /* 16EF4 800266F4 FEFF0524 */  addiu      $a1, $zero, -0x2
    /* 16EF8 800266F8 0580013C */  lui        $at, %hi(D_80048E98)
    /* 16EFC 800266FC 988E22AC */  sw         $v0, %lo(D_80048E98)($at)
    /* 16F00 80026700 D895000C */  jal        Pad_SioXferDataByte
    /* 16F04 80026704 000060A0 */   sb        $zero, 0x0($v1)
    /* 16F08 80026708 1400BF8F */  lw         $ra, 0x14($sp)
    /* 16F0C 8002670C 1000B08F */  lw         $s0, 0x10($sp)
    /* 16F10 80026710 0800E003 */  jr         $ra
    /* 16F14 80026714 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800266D0
