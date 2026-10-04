nonmatching Stg20_StartBgShake, 0x4C

glabel Stg20_StartBgShake
    /* 924 80063C84 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 928 80063C88 1000BFAF */  sw         $ra, 0x10($sp)
    /* 92C 80063C8C 01030424 */  addiu      $a0, $zero, 0x301
    /* 930 80063C90 FFFF0524 */  addiu      $a1, $zero, -0x1
    /* 934 80063C94 4445000C */  jal        Task_FindFirst
    /* 938 80063C98 2130A000 */   addu      $a2, $a1, $zero
    /* 93C 80063C9C 21204000 */  addu       $a0, $v0, $zero
    /* 940 80063CA0 07008010 */  beqz       $a0, .L80063CC0
    /* 944 80063CA4 01000224 */   addiu     $v0, $zero, 0x1
    /* 948 80063CA8 1000838C */  lw         $v1, 0x10($a0)
    /* 94C 80063CAC 00000000 */  nop
    /* 950 80063CB0 03006214 */  bne        $v1, $v0, .L80063CC0
    /* 954 80063CB4 00000000 */   nop
    /* 958 80063CB8 7745000C */  jal        Task_SetState1
    /* 95C 80063CBC 21284000 */   addu      $a1, $v0, $zero
  .L80063CC0:
    /* 960 80063CC0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 964 80063CC4 00000000 */  nop
    /* 968 80063CC8 0800E003 */  jr         $ra
    /* 96C 80063CCC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg20_StartBgShake
