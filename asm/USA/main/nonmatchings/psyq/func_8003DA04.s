/* Handwritten function */
nonmatching func_8003DA04, 0x44

glabel func_8003DA04
    /* 2E204 8003DA04 0680013C */  lui        $at, %hi(D_80062F30)
    /* 2E208 8003DA08 302F3FAC */  sw         $ra, %lo(D_80062F30)($at)
    /* 2E20C 8003DA0C 57000924 */  addiu      $t1, $zero, 0x57
    /* 2E210 8003DA10 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 2E214 8003DA14 09F84001 */  jalr       $t2
    /* 2E218 8003DA18 00000000 */   nop
    /* 2E21C 8003DA1C 09000A24 */  addiu      $t2, $zero, 0x9
    /* 2E220 8003DA20 6C01428C */  lw         $v0, 0x16C($v0)
    /* 2E224 8003DA24 00000000 */  nop
    /* 2E228 8003DA28 88194320 */  addi       $v1, $v0, 0x1988 /* handwritten instruction */
    /* 2E22C 8003DA2C E9B6000C */  jal        FlushCache
    /* 2E230 8003DA30 000060AC */   sw        $zero, 0x0($v1)
    /* 2E234 8003DA34 06801F3C */  lui        $ra, %hi(D_80062F30)
    /* 2E238 8003DA38 302FFF8F */  lw         $ra, %lo(D_80062F30)($ra)
    /* 2E23C 8003DA3C 00000000 */  nop
    /* 2E240 8003DA40 0800E003 */  jr         $ra
    /* 2E244 8003DA44 00000000 */   nop
endlabel func_8003DA04
