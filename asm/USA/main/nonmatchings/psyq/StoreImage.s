nonmatching StoreImage, 0x60

glabel StoreImage
    /* 17F8C 8002778C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 17F90 80027790 1000B0AF */  sw         $s0, 0x10($sp)
    /* 17F94 80027794 21808000 */  addu       $s0, $a0, $zero
    /* 17F98 80027798 1400B1AF */  sw         $s1, 0x14($sp)
    /* 17F9C 8002779C 2188A000 */  addu       $s1, $a1, $zero
    /* 17FA0 800277A0 0180043C */  lui        $a0, %hi(D_8001031C)
    /* 17FA4 800277A4 1C038424 */  addiu      $a0, $a0, %lo(D_8001031C)
    /* 17FA8 800277A8 1800BFAF */  sw         $ra, 0x18($sp)
    /* 17FAC 800277AC 3A9D000C */  jal        checkRECT
    /* 17FB0 800277B0 21280002 */   addu      $a1, $s0, $zero
    /* 17FB4 800277B4 21280002 */  addu       $a1, $s0, $zero
    /* 17FB8 800277B8 0580023C */  lui        $v0, %hi(D_80048F08)
    /* 17FBC 800277BC 088F428C */  lw         $v0, %lo(D_80048F08)($v0)
    /* 17FC0 800277C0 08000624 */  addiu      $a2, $zero, 0x8
    /* 17FC4 800277C4 1C00448C */  lw         $a0, 0x1C($v0)
    /* 17FC8 800277C8 0800428C */  lw         $v0, 0x8($v0)
    /* 17FCC 800277CC 00000000 */  nop
    /* 17FD0 800277D0 09F84000 */  jalr       $v0
    /* 17FD4 800277D4 21382002 */   addu      $a3, $s1, $zero
    /* 17FD8 800277D8 1800BF8F */  lw         $ra, 0x18($sp)
    /* 17FDC 800277DC 1400B18F */  lw         $s1, 0x14($sp)
    /* 17FE0 800277E0 1000B08F */  lw         $s0, 0x10($sp)
    /* 17FE4 800277E4 0800E003 */  jr         $ra
    /* 17FE8 800277E8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel StoreImage
