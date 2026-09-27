nonmatching func_8006FF28, 0x2C

glabel func_8006FF28
    /* CBC8 8006FF28 0580023C */  lui        $v0, %hi(D_8005071C)
    /* CBCC 8006FF2C 1C07428C */  lw         $v0, %lo(D_8005071C)($v0)
    /* CBD0 8006FF30 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* CBD4 8006FF34 1000BFAF */  sw         $ra, 0x10($sp)
    /* CBD8 8006FF38 580E448C */  lw         $a0, 0xE58($v0)
    /* CBDC 8006FF3C 618B000C */  jal        Mem_Free
    /* CBE0 8006FF40 00000000 */   nop
    /* CBE4 8006FF44 1000BF8F */  lw         $ra, 0x10($sp)
    /* CBE8 8006FF48 00000000 */  nop
    /* CBEC 8006FF4C 0800E003 */  jr         $ra
    /* CBF0 8006FF50 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006FF28
