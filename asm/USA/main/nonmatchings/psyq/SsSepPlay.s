nonmatching SsSepPlay, 0x3C

glabel SsSepPlay
    /* 25604 80034E04 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 25608 80034E08 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2560C 80034E0C 00240400 */  sll        $a0, $a0, 16
    /* 25610 80034E10 002C0500 */  sll        $a1, $a1, 16
    /* 25614 80034E14 00360600 */  sll        $a2, $a2, 24
    /* 25618 80034E18 003C0700 */  sll        $a3, $a3, 16
    /* 2561C 80034E1C 03240400 */  sra        $a0, $a0, 16
    /* 25620 80034E20 032C0500 */  sra        $a1, $a1, 16
    /* 25624 80034E24 03360600 */  sra        $a2, $a2, 24
    /* 25628 80034E28 91D3000C */  jal        Snd_SetPlayMode
    /* 2562C 80034E2C 033C0700 */   sra       $a3, $a3, 16
    /* 25630 80034E30 1000BF8F */  lw         $ra, 0x10($sp)
    /* 25634 80034E34 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 25638 80034E38 0800E003 */  jr         $ra
    /* 2563C 80034E3C 00000000 */   nop
endlabel SsSepPlay
    /* 25640 80034E40 00000000 */  nop
