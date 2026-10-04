nonmatching Stg40_PlayerAfterAction, 0x40

glabel Stg40_PlayerAfterAction
    /* 5C5C 80068FBC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 5C60 80068FC0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 5C64 80068FC4 1400BFAF */  sw         $ra, 0x14($sp)
    /* 5C68 80068FC8 BBC5010C */  jal        Stg40_TickStatusEffects
    /* 5C6C 80068FCC 21808000 */   addu      $s0, $a0, $zero
    /* 5C70 80068FD0 03004010 */  beqz       $v0, .L80068FE0
    /* 5C74 80068FD4 21200002 */   addu      $a0, $s0, $zero
    /* 5C78 80068FD8 F9A30108 */  j          .L80068FE4
    /* 5C7C 80068FDC 08000524 */   addiu     $a1, $zero, 0x8
  .L80068FE0:
    /* 5C80 80068FE0 07000524 */  addiu      $a1, $zero, 0x7
  .L80068FE4:
    /* 5C84 80068FE4 7745000C */  jal        Task_SetState1
    /* 5C88 80068FE8 00000000 */   nop
    /* 5C8C 80068FEC 1400BF8F */  lw         $ra, 0x14($sp)
    /* 5C90 80068FF0 1000B08F */  lw         $s0, 0x10($sp)
    /* 5C94 80068FF4 0800E003 */  jr         $ra
    /* 5C98 80068FF8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg40_PlayerAfterAction
