nonmatching func_8003DAB8, 0x24

glabel func_8003DAB8
    /* 2E2B8 8003DAB8 01A0023C */  lui        $v0, %hi(D_A000DFAC)
    /* 2E2BC 8003DABC ACDF4224 */  addiu      $v0, $v0, %lo(D_A000DFAC)
    /* 2E2C0 8003DAC0 08004000 */  jr         $v0
    /* 2E2C4 8003DAC4 00000000 */   nop
    /* 2E2C8 8003DAC8 00000000 */  nop
    /* 2E2CC 8003DACC 01A0083C */  lui        $t0, %hi(D_A000DF80)
    /* 2E2D0 8003DAD0 80DF0825 */  addiu      $t0, $t0, %lo(D_A000DF80)
    /* 2E2D4 8003DAD4 09F80001 */  jalr       $t0
    /* 2E2D8 8003DAD8 00000000 */   nop
endlabel func_8003DAB8
    /* 2E2DC 8003DADC 00000000 */  nop
