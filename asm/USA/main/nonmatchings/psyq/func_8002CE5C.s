/* Handwritten function */
nonmatching func_8002CE5C, 0x80

glabel func_8002CE5C
    /* 1D65C 8002CE5C 0580013C */  lui        $at, %hi(D_80049920)
    /* 1D660 8002CE60 20993FAC */  sw         $ra, %lo(D_80049920)($at)
    /* 1D664 8002CE64 B1B6000C */  jal        func_8002DAC4
    /* 1D668 8002CE68 00000000 */   nop
    /* 1D66C 8002CE6C 05801F3C */  lui        $ra, %hi(D_80049920)
    /* 1D670 8002CE70 2099FF8F */  lw         $ra, %lo(D_80049920)($ra)
    /* 1D674 8002CE74 00000000 */  nop
    /* 1D678 8002CE78 00600240 */  mfc0       $v0, $12 /* handwritten instruction */
    /* 1D67C 8002CE7C 0040033C */  lui        $v1, (0x40000000 >> 16)
    /* 1D680 8002CE80 25104300 */  or         $v0, $v0, $v1
    /* 1D684 8002CE84 00608240 */  mtc0       $v0, $12 /* handwritten instruction */
    /* 1D688 8002CE88 00000000 */  nop
    /* 1D68C 8002CE8C 55010824 */  addiu      $t0, $zero, 0x155
    /* 1D690 8002CE90 00E8C848 */  ctc2       $t0, $29 /* handwritten instruction */
    /* 1D694 8002CE94 00000000 */  nop
    /* 1D698 8002CE98 00010824 */  addiu      $t0, $zero, 0x100
    /* 1D69C 8002CE9C 00F0C848 */  ctc2       $t0, $30 /* handwritten instruction */
    /* 1D6A0 8002CEA0 00000000 */  nop
    /* 1D6A4 8002CEA4 E8030824 */  addiu      $t0, $zero, 0x3E8
    /* 1D6A8 8002CEA8 00D0C848 */  ctc2       $t0, $26 /* handwritten instruction */
    /* 1D6AC 8002CEAC 00000000 */  nop
    /* 1D6B0 8002CEB0 9EEF0824 */  addiu      $t0, $zero, -0x1062
    /* 1D6B4 8002CEB4 00D8C848 */  ctc2       $t0, $27 /* handwritten instruction */
    /* 1D6B8 8002CEB8 00000000 */  nop
    /* 1D6BC 8002CEBC 4001083C */  lui        $t0, (0x1400000 >> 16)
    /* 1D6C0 8002CEC0 00E0C848 */  ctc2       $t0, $28 /* handwritten instruction */
    /* 1D6C4 8002CEC4 00000000 */  nop
    /* 1D6C8 8002CEC8 00C0C048 */  ctc2       $zero, $24 /* handwritten instruction */
    /* 1D6CC 8002CECC 00C8C048 */  ctc2       $zero, $25 /* handwritten instruction */
    /* 1D6D0 8002CED0 00000000 */  nop
    /* 1D6D4 8002CED4 0800E003 */  jr         $ra
    /* 1D6D8 8002CED8 00000000 */   nop
endlabel func_8002CE5C
    /* 1D6DC 8002CEDC 00000000 */  nop
    /* 1D6E0 8002CEE0 00000000 */  nop
