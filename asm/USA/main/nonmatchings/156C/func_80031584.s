nonmatching func_80031584, 0x4C

glabel func_80031584
    /* 21D84 80031584 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 21D88 80031588 0580043C */  lui        $a0, %hi(D_8004FBD4)
    /* 21D8C 8003158C D4FB8424 */  addiu      $a0, $a0, %lo(D_8004FBD4)
    /* 21D90 80031590 1000BFAF */  sw         $ra, 0x10($sp)
    /* 21D94 80031594 FFC5000C */  jal        memclr_dma
    /* 21D98 80031598 08000524 */   addiu     $a1, $zero, 0x8
    /* 21D9C 8003159C 03000424 */  addiu      $a0, $zero, 0x3
    /* 21DA0 800315A0 0580023C */  lui        $v0, %hi(D_8004FBD0)
    /* 21DA4 800315A4 D0FB428C */  lw         $v0, %lo(D_8004FBD0)($v0)
    /* 21DA8 800315A8 0380053C */  lui        $a1, %hi(func_800315D0)
    /* 21DAC 800315AC D015A524 */  addiu      $a1, $a1, %lo(func_800315D0)
    /* 21DB0 800315B0 41C3000C */  jal        InterruptCallback
    /* 21DB4 800315B4 000040AC */   sw        $zero, 0x0($v0)
    /* 21DB8 800315B8 0380023C */  lui        $v0, %hi(setIntrDMA)
    /* 21DBC 800315BC 50174224 */  addiu      $v0, $v0, %lo(setIntrDMA)
    /* 21DC0 800315C0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 21DC4 800315C4 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 21DC8 800315C8 0800E003 */  jr         $ra
    /* 21DCC 800315CC 00000000 */   nop
endlabel func_80031584
