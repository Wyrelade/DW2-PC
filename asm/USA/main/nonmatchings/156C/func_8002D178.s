/* Handwritten function */
nonmatching func_8002D178, 0xA4

glabel func_8002D178
    /* 1D978 8002D178 05800E3C */  lui        $t6, %hi(D_80049ABC)
    /* 1D97C 8002D17C BC9ACE8D */  lw         $t6, %lo(D_80049ABC)($t6)
    /* 1D980 8002D180 00000000 */  nop
    /* 1D984 8002D184 0B00C01D */  bgtz       $t6, .L8002D1B4
    /* 1D988 8002D188 00000000 */   nop
    /* 1D98C 8002D18C 0580013C */  lui        $at, %hi(D_80049AB0)
    /* 1D990 8002D190 B09A3FAC */  sw         $ra, %lo(D_80049AB0)($at)
    /* 1D994 8002D194 0580043C */  lui        $a0, %hi(D_80049D71)
    /* 1D998 8002D198 05A8000C */  jal        printf
    /* 1D99C 8002D19C 719D8424 */   addiu     $a0, $a0, %lo(D_80049D71)
    /* 1D9A0 8002D1A0 05801F3C */  lui        $ra, %hi(D_80049AB0)
    /* 1D9A4 8002D1A4 B09AFF8F */  lw         $ra, %lo(D_80049AB0)($ra)
    /* 1D9A8 8002D1A8 00000000 */  nop
    /* 1D9AC 8002D1AC 0800E003 */  jr         $ra
    /* 1D9B0 8002D1B0 00000000 */   nop
  .L8002D1B4:
    /* 1D9B4 8002D1B4 E0FFCE21 */  addi       $t6, $t6, -0x20 /* handwritten instruction */
    /* 1D9B8 8002D1B8 0580013C */  lui        $at, %hi(D_80049ABC)
    /* 1D9BC 8002D1BC BC9A2EAC */  sw         $t6, %lo(D_80049ABC)($at)
    /* 1D9C0 8002D1C0 05800F3C */  lui        $t7, %hi(D_80049AC0)
    /* 1D9C4 8002D1C4 C09AEF25 */  addiu      $t7, $t7, %lo(D_80049AC0)
    /* 1D9C8 8002D1C8 2178EE01 */  addu       $t7, $t7, $t6
    /* 1D9CC 8002D1CC 0000E88D */  lw         $t0, 0x0($t7)
    /* 1D9D0 8002D1D0 0400E98D */  lw         $t1, 0x4($t7)
    /* 1D9D4 8002D1D4 0000C848 */  ctc2       $t0, $0 /* handwritten instruction */
    /* 1D9D8 8002D1D8 0008C948 */  ctc2       $t1, $1 /* handwritten instruction */
    /* 1D9DC 8002D1DC 0800E88D */  lw         $t0, 0x8($t7)
    /* 1D9E0 8002D1E0 0C00E98D */  lw         $t1, 0xC($t7)
    /* 1D9E4 8002D1E4 0010C848 */  ctc2       $t0, $2 /* handwritten instruction */
    /* 1D9E8 8002D1E8 0018C948 */  ctc2       $t1, $3 /* handwritten instruction */
    /* 1D9EC 8002D1EC 1000E88D */  lw         $t0, 0x10($t7)
    /* 1D9F0 8002D1F0 00000000 */  nop
    /* 1D9F4 8002D1F4 0020C848 */  ctc2       $t0, $4 /* handwritten instruction */
    /* 1D9F8 8002D1F8 00000000 */  nop
    /* 1D9FC 8002D1FC 1400E88D */  lw         $t0, 0x14($t7)
    /* 1DA00 8002D200 1800E98D */  lw         $t1, 0x18($t7)
    /* 1DA04 8002D204 1C00EA8D */  lw         $t2, 0x1C($t7)
    /* 1DA08 8002D208 0028C848 */  ctc2       $t0, $5 /* handwritten instruction */
    /* 1DA0C 8002D20C 0030C948 */  ctc2       $t1, $6 /* handwritten instruction */
    /* 1DA10 8002D210 0038CA48 */  ctc2       $t2, $7 /* handwritten instruction */
    /* 1DA14 8002D214 0800E003 */  jr         $ra
    /* 1DA18 8002D218 00000000 */   nop
endlabel func_8002D178
    /* 1DA1C 8002D21C 00000000 */  nop
    /* 1DA20 8002D220 00000000 */  nop
