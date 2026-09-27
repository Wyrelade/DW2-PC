nonmatching func_8006E674, 0x1C

glabel func_8006E674
    /* B314 8006E674 0780023C */  lui        $v0, %hi(D_80073A20)
    /* B318 8006E678 203A4224 */  addiu      $v0, $v0, %lo(D_80073A20)
    /* B31C 8006E67C 80200400 */  sll        $a0, $a0, 2
    /* B320 8006E680 21208200 */  addu       $a0, $a0, $v0
    /* B324 8006E684 0000828C */  lw         $v0, 0x0($a0)
    /* B328 8006E688 0800E003 */  jr         $ra
    /* B32C 8006E68C 00000000 */   nop
endlabel func_8006E674
