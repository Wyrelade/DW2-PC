/* Handwritten function */
nonmatching MulMatrix, 0x10C

glabel MulMatrix
    /* 1DA24 8002D224 0000888C */  lw         $t0, 0x0($a0)
    /* 1DA28 8002D228 0400898C */  lw         $t1, 0x4($a0)
    /* 1DA2C 8002D22C 08008A8C */  lw         $t2, 0x8($a0)
    /* 1DA30 8002D230 0C008B8C */  lw         $t3, 0xC($a0)
    /* 1DA34 8002D234 10008C8C */  lw         $t4, 0x10($a0)
    /* 1DA38 8002D238 0000C848 */  ctc2       $t0, $0 /* handwritten instruction */
    /* 1DA3C 8002D23C 0008C948 */  ctc2       $t1, $1 /* handwritten instruction */
    /* 1DA40 8002D240 0010CA48 */  ctc2       $t2, $2 /* handwritten instruction */
    /* 1DA44 8002D244 0018CB48 */  ctc2       $t3, $3 /* handwritten instruction */
    /* 1DA48 8002D248 0020CC48 */  ctc2       $t4, $4 /* handwritten instruction */
    /* 1DA4C 8002D24C 0000A894 */  lhu        $t0, 0x0($a1)
    /* 1DA50 8002D250 0400A98C */  lw         $t1, 0x4($a1)
    /* 1DA54 8002D254 0C00AA8C */  lw         $t2, 0xC($a1)
    /* 1DA58 8002D258 FFFF013C */  lui        $at, (0xFFFF0000 >> 16)
    /* 1DA5C 8002D25C 24482101 */  and        $t1, $t1, $at
    /* 1DA60 8002D260 25400901 */  or         $t0, $t0, $t1
    /* 1DA64 8002D264 00008848 */  mtc2       $t0, $0 /* handwritten instruction */
    /* 1DA68 8002D268 00088A48 */  mtc2       $t2, $1 /* handwritten instruction */
    /* 1DA6C 8002D26C 00000000 */  nop
    /* 1DA70 8002D270 1260484A */  mvmva      1, 0, 0, 3, 0
    /* 1DA74 8002D274 0200A894 */  lhu        $t0, 0x2($a1)
    /* 1DA78 8002D278 0800A98C */  lw         $t1, 0x8($a1)
    /* 1DA7C 8002D27C 0E00AA84 */  lh         $t2, 0xE($a1)
    /* 1DA80 8002D280 004C0900 */  sll        $t1, $t1, 16
    /* 1DA84 8002D284 25400901 */  or         $t0, $t0, $t1
    /* 1DA88 8002D288 00480B48 */  mfc2       $t3, $9 /* handwritten instruction */
    /* 1DA8C 8002D28C 00500C48 */  mfc2       $t4, $10 /* handwritten instruction */
    /* 1DA90 8002D290 00580D48 */  mfc2       $t5, $11 /* handwritten instruction */
    /* 1DA94 8002D294 00008848 */  mtc2       $t0, $0 /* handwritten instruction */
    /* 1DA98 8002D298 00088A48 */  mtc2       $t2, $1 /* handwritten instruction */
    /* 1DA9C 8002D29C 00000000 */  nop
    /* 1DAA0 8002D2A0 1260484A */  mvmva      1, 0, 0, 3, 0
    /* 1DAA4 8002D2A4 0400A894 */  lhu        $t0, 0x4($a1)
    /* 1DAA8 8002D2A8 0800A98C */  lw         $t1, 0x8($a1)
    /* 1DAAC 8002D2AC 1000AA8C */  lw         $t2, 0x10($a1)
    /* 1DAB0 8002D2B0 FFFF013C */  lui        $at, (0xFFFF0000 >> 16)
    /* 1DAB4 8002D2B4 24482101 */  and        $t1, $t1, $at
    /* 1DAB8 8002D2B8 25400901 */  or         $t0, $t0, $t1
    /* 1DABC 8002D2BC 00480E48 */  mfc2       $t6, $9 /* handwritten instruction */
    /* 1DAC0 8002D2C0 00500F48 */  mfc2       $t7, $10 /* handwritten instruction */
    /* 1DAC4 8002D2C4 00581848 */  mfc2       $t8, $11 /* handwritten instruction */
    /* 1DAC8 8002D2C8 00008848 */  mtc2       $t0, $0 /* handwritten instruction */
    /* 1DACC 8002D2CC 00088A48 */  mtc2       $t2, $1 /* handwritten instruction */
    /* 1DAD0 8002D2D0 00000000 */  nop
    /* 1DAD4 8002D2D4 1260484A */  mvmva      1, 0, 0, 3, 0
    /* 1DAD8 8002D2D8 FFFF6B31 */  andi       $t3, $t3, 0xFFFF
    /* 1DADC 8002D2DC 00740E00 */  sll        $t6, $t6, 16
    /* 1DAE0 8002D2E0 2570CB01 */  or         $t6, $t6, $t3
    /* 1DAE4 8002D2E4 00008EAC */  sw         $t6, 0x0($a0)
    /* 1DAE8 8002D2E8 FFFFAD31 */  andi       $t5, $t5, 0xFFFF
    /* 1DAEC 8002D2EC 00C41800 */  sll        $t8, $t8, 16
    /* 1DAF0 8002D2F0 25C00D03 */  or         $t8, $t8, $t5
    /* 1DAF4 8002D2F4 0C0098AC */  sw         $t8, 0xC($a0)
    /* 1DAF8 8002D2F8 00480848 */  mfc2       $t0, $9 /* handwritten instruction */
    /* 1DAFC 8002D2FC 00500948 */  mfc2       $t1, $10 /* handwritten instruction */
    /* 1DB00 8002D300 FFFF0831 */  andi       $t0, $t0, 0xFFFF
    /* 1DB04 8002D304 00640C00 */  sll        $t4, $t4, 16
    /* 1DB08 8002D308 25400C01 */  or         $t0, $t0, $t4
    /* 1DB0C 8002D30C 040088AC */  sw         $t0, 0x4($a0)
    /* 1DB10 8002D310 FFFFEF31 */  andi       $t7, $t7, 0xFFFF
    /* 1DB14 8002D314 004C0900 */  sll        $t1, $t1, 16
    /* 1DB18 8002D318 25482F01 */  or         $t1, $t1, $t7
    /* 1DB1C 8002D31C 080089AC */  sw         $t1, 0x8($a0)
    /* 1DB20 8002D320 10008BE8 */  swc2       $11, 0x10($a0)
    /* 1DB24 8002D324 21108000 */  addu       $v0, $a0, $zero
    /* 1DB28 8002D328 0800E003 */  jr         $ra
    /* 1DB2C 8002D32C 00000000 */   nop
endlabel MulMatrix
    /* 1DB30 8002D330 00000000 */  nop
