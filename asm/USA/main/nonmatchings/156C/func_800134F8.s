nonmatching func_800134F8, 0x60

glabel func_800134F8
    /* 3CF8 800134F8 B8FFBD27 */  addiu      $sp, $sp, -0x48
    /* 3CFC 800134FC C2110600 */  srl        $v0, $a2, 7
    /* 3D00 80013500 01004230 */  andi       $v0, $v0, 0x1
    /* 3D04 80013504 1000A2AF */  sw         $v0, 0x10($sp)
    /* 3D08 80013508 82100600 */  srl        $v0, $a2, 2
    /* 3D0C 8001350C 0F004230 */  andi       $v0, $v0, 0xF
    /* 3D10 80013510 5400A7AF */  sw         $a3, 0x54($sp)
    /* 3D14 80013514 2400A5AF */  sw         $a1, 0x24($sp)
    /* 3D18 80013518 1400A2AF */  sw         $v0, 0x14($sp)
    /* 3D1C 8001351C 5400A297 */  lhu        $v0, 0x54($sp)
    /* 3D20 80013520 0300C630 */  andi       $a2, $a2, 0x3
    /* 3D24 80013524 1800A2A7 */  sh         $v0, 0x18($sp)
    /* 3D28 80013528 5600A297 */  lhu        $v0, 0x56($sp)
    /* 3D2C 8001352C 1000A527 */  addiu      $a1, $sp, 0x10
    /* 3D30 80013530 4000BFAF */  sw         $ra, 0x40($sp)
    /* 3D34 80013534 1C00A0AF */  sw         $zero, 0x1C($sp)
    /* 3D38 80013538 2000A0AF */  sw         $zero, 0x20($sp)
    /* 3D3C 8001353C 2800A6AF */  sw         $a2, 0x28($sp)
    /* 3D40 80013540 096F000C */  jal        Text_Open
    /* 3D44 80013544 1A00A2A7 */   sh        $v0, 0x1A($sp)
    /* 3D48 80013548 4000BF8F */  lw         $ra, 0x40($sp)
    /* 3D4C 8001354C 00000000 */  nop
    /* 3D50 80013550 0800E003 */  jr         $ra
    /* 3D54 80013554 4800BD27 */   addiu     $sp, $sp, 0x48
endlabel func_800134F8
