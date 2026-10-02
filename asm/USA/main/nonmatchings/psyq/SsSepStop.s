nonmatching SsSepStop, 0x2C

glabel SsSepStop
    /* 25E9C 8003569C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 25EA0 800356A0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 25EA4 800356A4 00240400 */  sll        $a0, $a0, 16
    /* 25EA8 800356A8 002C0500 */  sll        $a1, $a1, 16
    /* 25EAC 800356AC 03240400 */  sra        $a0, $a0, 16
    /* 25EB0 800356B0 3DD5000C */  jal        _SsSndStop
    /* 25EB4 800356B4 032C0500 */   sra       $a1, $a1, 16
    /* 25EB8 800356B8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 25EBC 800356BC 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 25EC0 800356C0 0800E003 */  jr         $ra
    /* 25EC4 800356C4 00000000 */   nop
endlabel SsSepStop
    /* 25EC8 800356C8 00000000 */  nop
    /* 25ECC 800356CC 00000000 */  nop
    /* 25ED0 800356D0 00000000 */  nop
