nonmatching func_80064480, 0x54

glabel func_80064480
    /* 1120 80064480 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1124 80064484 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1128 80064488 21800000 */  addu       $s0, $zero, $zero
    /* 112C 8006448C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1130 80064490 09050424 */  addiu      $a0, $zero, 0x509
  .L80064494:
    /* 1134 80064494 FFFF0524 */  addiu      $a1, $zero, -0x1
    /* 1138 80064498 4445000C */  jal        Task_FindFirst
    /* 113C 8006449C 21300002 */   addu      $a2, $s0, $zero
    /* 1140 800644A0 04004010 */  beqz       $v0, .L800644B4
    /* 1144 800644A4 21204000 */   addu      $a0, $v0, $zero
    /* 1148 800644A8 02000524 */  addiu      $a1, $zero, 0x2
    /* 114C 800644AC 7D45000C */  jal        Task_SetState01
    /* 1150 800644B0 08000624 */   addiu     $a2, $zero, 0x8
  .L800644B4:
    /* 1154 800644B4 01001026 */  addiu      $s0, $s0, 0x1
    /* 1158 800644B8 0300022A */  slti       $v0, $s0, 0x3
    /* 115C 800644BC F5FF4014 */  bnez       $v0, .L80064494
    /* 1160 800644C0 09050424 */   addiu     $a0, $zero, 0x509
    /* 1164 800644C4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1168 800644C8 1000B08F */  lw         $s0, 0x10($sp)
    /* 116C 800644CC 0800E003 */  jr         $ra
    /* 1170 800644D0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80064480
