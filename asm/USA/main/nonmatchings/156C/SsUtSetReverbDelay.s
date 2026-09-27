nonmatching SsUtSetReverbDelay, 0x3C

glabel SsUtSetReverbDelay
    /* 26BA4 800363A4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 26BA8 800363A8 0680033C */  lui        $v1, %hi(D_80062C18)
    /* 26BAC 800363AC 182C6324 */  addiu      $v1, $v1, %lo(D_80062C18)
    /* 26BB0 800363B0 08000224 */  addiu      $v0, $zero, 0x8
    /* 26BB4 800363B4 00240400 */  sll        $a0, $a0, 16
    /* 26BB8 800363B8 03240400 */  sra        $a0, $a0, 16
    /* 26BBC 800363BC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 26BC0 800363C0 0C0064AC */  sw         $a0, 0xC($v1)
    /* 26BC4 800363C4 21206000 */  addu       $a0, $v1, $zero
    /* 26BC8 800363C8 65EE000C */  jal        func_8003B994
    /* 26BCC 800363CC 000062AC */   sw        $v0, 0x0($v1)
    /* 26BD0 800363D0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 26BD4 800363D4 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 26BD8 800363D8 0800E003 */  jr         $ra
    /* 26BDC 800363DC 00000000 */   nop
endlabel SsUtSetReverbDelay
    /* 26BE0 800363E0 00000000 */  nop
