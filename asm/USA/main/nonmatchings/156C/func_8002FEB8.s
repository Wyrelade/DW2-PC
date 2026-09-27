nonmatching func_8002FEB8, 0x4C

glabel func_8002FEB8
    /* 206B8 8002FEB8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 206BC 8002FEBC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 206C0 8002FEC0 0580013C */  lui        $at, %hi(D_8004E6CC)
    /* 206C4 8002FEC4 CCE620AC */  sw         $zero, %lo(D_8004E6CC)($at)
    /* 206C8 8002FEC8 0580013C */  lui        $at, %hi(D_8004E6C8)
    /* 206CC 8002FECC C8E620AC */  sw         $zero, %lo(D_8004E6C8)($at)
    /* 206D0 8002FED0 0580013C */  lui        $at, %hi(D_8004E6D8)
    /* 206D4 8002FED4 D8E620AC */  sw         $zero, %lo(D_8004E6D8)($at)
    /* 206D8 8002FED8 0580013C */  lui        $at, %hi(D_8004E6D4)
    /* 206DC 8002FEDC 35C3000C */  jal        ResetCallback
    /* 206E0 8002FEE0 D4E620AC */   sw        $zero, %lo(D_8004E6D4)($at)
    /* 206E4 8002FEE4 0380053C */  lui        $a1, %hi(func_80030258)
    /* 206E8 8002FEE8 5802A524 */  addiu      $a1, $a1, %lo(func_80030258)
    /* 206EC 8002FEEC 41C3000C */  jal        InterruptCallback
    /* 206F0 8002FEF0 02000424 */   addiu     $a0, $zero, 0x2
    /* 206F4 8002FEF4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 206F8 8002FEF8 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 206FC 8002FEFC 0800E003 */  jr         $ra
    /* 20700 8002FF00 00000000 */   nop
endlabel func_8002FEB8
