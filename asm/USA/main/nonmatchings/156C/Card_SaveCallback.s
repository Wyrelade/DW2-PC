nonmatching Card_SaveCallback, 0x28

glabel Card_SaveCallback
    /* 2E4A4 8003DCA4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2E4A8 8003DCA8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2E4AC 8003DCAC 5EFC000C */  jal        MemCardCallback
    /* 2E4B0 8003DCB0 21200000 */   addu      $a0, $zero, $zero
    /* 2E4B4 8003DCB4 0680013C */  lui        $at, %hi(D_80062FD8)
    /* 2E4B8 8003DCB8 D82F22AC */  sw         $v0, %lo(D_80062FD8)($at)
    /* 2E4BC 8003DCBC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2E4C0 8003DCC0 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 2E4C4 8003DCC4 0800E003 */  jr         $ra
    /* 2E4C8 8003DCC8 00000000 */   nop
endlabel Card_SaveCallback
