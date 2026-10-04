nonmatching _card_read, 0x8C

glabel _card_read
    /* 314E4 80040CE4 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 314E8 80040CE8 08004001 */  jr         $t2
    /* 314EC 80040CEC 4F000924 */   addiu     $t1, $zero, 0x4F
    /* 314F0 80040CF0 00000000 */  nop
    /* 314F4 80040CF4 00000000 */  nop
    /* 314F8 80040CF8 840E0480 */  lb         $a0, 0xE84($zero)
    /* 314FC 80040CFC 00000000 */  nop
    /* 31500 80040D00 B80F0480 */  lb         $a0, 0xFB8($zero)
    /* 31504 80040D04 E00F0480 */  lb         $a0, 0xFE0($zero)
    /* 31508 80040D08 940D0480 */  lb         $a0, 0xD94($zero)
    /* 3150C 80040D0C B4160480 */  lb         $a0, 0x16B4($zero)
    /* 31510 80040D10 D88D0480 */  lb         $a0, -0x7228($zero)
    /* 31514 80040D14 00000000 */  nop
    /* 31518 80040D18 4C150480 */  lb         $a0, 0x154C($zero)
    /* 3151C 80040D1C 200E0480 */  lb         $a0, 0xE20($zero)
    /* 31520 80040D20 9C0E0480 */  lb         $a0, 0xE9C($zero)
    /* 31524 80040D24 B40E0480 */  lb         $a0, 0xEB4($zero)
    /* 31528 80040D28 CC0E0480 */  lb         $a0, 0xECC($zero)
    /* 3152C 80040D2C E40E0480 */  lb         $a0, 0xEE4($zero)
    /* 31530 80040D30 040F0480 */  lb         $a0, 0xF04($zero)
    /* 31534 80040D34 4C0F0480 */  lb         $a0, 0xF4C($zero)
    /* 31538 80040D38 800F0480 */  lb         $a0, 0xF80($zero)
    /* 3153C 80040D3C A00F0480 */  lb         $a0, 0xFA0($zero)
    /* 31540 80040D40 800F0480 */  lb         $a0, 0xF80($zero)
    /* 31544 80040D44 800F0480 */  lb         $a0, 0xF80($zero)
    /* 31548 80040D48 800F0480 */  lb         $a0, 0xF80($zero)
    /* 3154C 80040D4C 500E0480 */  lb         $a0, 0xE50($zero)
  alabel Task_DescTable
    /* 31550 80040D50 F40C0480 */  lb         $a0, 0xCF4($zero)
    /* 31554 80040D54 688F0680 */  lb         $a2, -0x7098($zero)
    /* 31558 80040D58 0C290780 */  lb         $a3, 0x290C($zero)
    /* 3155C 80040D5C F8030780 */  lb         $a3, 0x3F8($zero)
    /* 31560 80040D60 48520680 */  lb         $a2, 0x5248($zero)
    /* 31564 80040D64 70330780 */  lb         $a3, 0x3370($zero)
    /* 31568 80040D68 88840680 */  lb         $a2, -0x7B78($zero)
    /* 3156C 80040D6C C8A50680 */  lb         $a2, -0x5A38($zero)
endlabel _card_read
