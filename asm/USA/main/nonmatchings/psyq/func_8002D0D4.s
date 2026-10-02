/* Handwritten function */
nonmatching func_8002D0D4, 0xA4

glabel func_8002D0D4
    /* 1D8D4 8002D0D4 05800E3C */  lui        $t6, %hi(D_80049ABC)
    /* 1D8D8 8002D0D8 BC9ACE8D */  lw         $t6, %lo(D_80049ABC)($t6)
    /* 1D8DC 8002D0DC 00000000 */  nop
    /* 1D8E0 8002D0E0 8002C129 */  slti       $at, $t6, 0x280
    /* 1D8E4 8002D0E4 0B002014 */  bnez       $at, .L8002D114
    /* 1D8E8 8002D0E8 00000000 */   nop
    /* 1D8EC 8002D0EC 0580013C */  lui        $at, %hi(D_80049AB0)
    /* 1D8F0 8002D0F0 B09A3FAC */  sw         $ra, %lo(D_80049AB0)($at)
    /* 1D8F4 8002D0F4 0580043C */  lui        $a0, %hi(D_80049D40)
    /* 1D8F8 8002D0F8 05A8000C */  jal        printf
    /* 1D8FC 8002D0FC 409D8424 */   addiu     $a0, $a0, %lo(D_80049D40)
    /* 1D900 8002D100 05801F3C */  lui        $ra, %hi(D_80049AB0)
    /* 1D904 8002D104 B09AFF8F */  lw         $ra, %lo(D_80049AB0)($ra)
    /* 1D908 8002D108 00000000 */  nop
    /* 1D90C 8002D10C 0800E003 */  jr         $ra
    /* 1D910 8002D110 00000000 */   nop
  .L8002D114:
    /* 1D914 8002D114 05800F3C */  lui        $t7, %hi(D_80049AC0)
    /* 1D918 8002D118 C09AEF25 */  addiu      $t7, $t7, %lo(D_80049AC0)
    /* 1D91C 8002D11C 2178EE01 */  addu       $t7, $t7, $t6
    /* 1D920 8002D120 00004848 */  cfc2       $t0, $0 /* handwritten instruction */
    /* 1D924 8002D124 00084948 */  cfc2       $t1, $1 /* handwritten instruction */
    /* 1D928 8002D128 0000E8AD */  sw         $t0, 0x0($t7)
    /* 1D92C 8002D12C 0400E9AD */  sw         $t1, 0x4($t7)
    /* 1D930 8002D130 00104848 */  cfc2       $t0, $2 /* handwritten instruction */
    /* 1D934 8002D134 00184948 */  cfc2       $t1, $3 /* handwritten instruction */
    /* 1D938 8002D138 0800E8AD */  sw         $t0, 0x8($t7)
    /* 1D93C 8002D13C 0C00E9AD */  sw         $t1, 0xC($t7)
    /* 1D940 8002D140 00204848 */  cfc2       $t0, $4 /* handwritten instruction */
    /* 1D944 8002D144 00000000 */  nop
    /* 1D948 8002D148 1000E8AD */  sw         $t0, 0x10($t7)
    /* 1D94C 8002D14C 00284848 */  cfc2       $t0, $5 /* handwritten instruction */
    /* 1D950 8002D150 00304948 */  cfc2       $t1, $6 /* handwritten instruction */
    /* 1D954 8002D154 00384A48 */  cfc2       $t2, $7 /* handwritten instruction */
    /* 1D958 8002D158 1400E8AD */  sw         $t0, 0x14($t7)
    /* 1D95C 8002D15C 1800E9AD */  sw         $t1, 0x18($t7)
    /* 1D960 8002D160 1C00EAAD */  sw         $t2, 0x1C($t7)
    /* 1D964 8002D164 2000CE21 */  addi       $t6, $t6, 0x20 /* handwritten instruction */
    /* 1D968 8002D168 0580013C */  lui        $at, %hi(D_80049ABC)
    /* 1D96C 8002D16C BC9A2EAC */  sw         $t6, %lo(D_80049ABC)($at)
    /* 1D970 8002D170 0800E003 */  jr         $ra
    /* 1D974 8002D174 00000000 */   nop
endlabel func_8002D0D4
