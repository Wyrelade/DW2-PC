nonmatching ScaleMatrix, 0x138

glabel ScaleMatrix
    /* 1DCA4 8002D4A4 0000AB8C */  lw         $t3, 0x0($a1)
    /* 1DCA8 8002D4A8 0400AC8C */  lw         $t4, 0x4($a1)
    /* 1DCAC 8002D4AC 0800AD8C */  lw         $t5, 0x8($a1)
    /* 1DCB0 8002D4B0 0000888C */  lw         $t0, 0x0($a0)
    /* 1DCB4 8002D4B4 00000000 */  nop
    /* 1DCB8 8002D4B8 FFFF0931 */  andi       $t1, $t0, 0xFFFF
    /* 1DCBC 8002D4BC 004C0900 */  sll        $t1, $t1, 16
    /* 1DCC0 8002D4C0 034C0900 */  sra        $t1, $t1, 16
    /* 1DCC4 8002D4C4 19002B01 */  multu      $t1, $t3
    /* 1DCC8 8002D4C8 12480000 */  mflo       $t1
    /* 1DCCC 8002D4CC 034B0900 */  sra        $t1, $t1, 12
    /* 1DCD0 8002D4D0 FFFF2931 */  andi       $t1, $t1, 0xFFFF
    /* 1DCD4 8002D4D4 03540800 */  sra        $t2, $t0, 16
    /* 1DCD8 8002D4D8 19004C01 */  multu      $t2, $t4
    /* 1DCDC 8002D4DC 12500000 */  mflo       $t2
    /* 1DCE0 8002D4E0 03530A00 */  sra        $t2, $t2, 12
    /* 1DCE4 8002D4E4 00540A00 */  sll        $t2, $t2, 16
    /* 1DCE8 8002D4E8 25482A01 */  or         $t1, $t1, $t2
    /* 1DCEC 8002D4EC 000089AC */  sw         $t1, 0x0($a0)
    /* 1DCF0 8002D4F0 0400888C */  lw         $t0, 0x4($a0)
    /* 1DCF4 8002D4F4 00000000 */  nop
    /* 1DCF8 8002D4F8 FFFF0931 */  andi       $t1, $t0, 0xFFFF
    /* 1DCFC 8002D4FC 004C0900 */  sll        $t1, $t1, 16
    /* 1DD00 8002D500 034C0900 */  sra        $t1, $t1, 16
    /* 1DD04 8002D504 19002D01 */  multu      $t1, $t5
    /* 1DD08 8002D508 12480000 */  mflo       $t1
    /* 1DD0C 8002D50C 034B0900 */  sra        $t1, $t1, 12
    /* 1DD10 8002D510 FFFF2931 */  andi       $t1, $t1, 0xFFFF
    /* 1DD14 8002D514 03540800 */  sra        $t2, $t0, 16
    /* 1DD18 8002D518 19004B01 */  multu      $t2, $t3
    /* 1DD1C 8002D51C 12500000 */  mflo       $t2
    /* 1DD20 8002D520 03530A00 */  sra        $t2, $t2, 12
    /* 1DD24 8002D524 00540A00 */  sll        $t2, $t2, 16
    /* 1DD28 8002D528 25482A01 */  or         $t1, $t1, $t2
    /* 1DD2C 8002D52C 040089AC */  sw         $t1, 0x4($a0)
    /* 1DD30 8002D530 0800888C */  lw         $t0, 0x8($a0)
    /* 1DD34 8002D534 00000000 */  nop
    /* 1DD38 8002D538 FFFF0931 */  andi       $t1, $t0, 0xFFFF
    /* 1DD3C 8002D53C 004C0900 */  sll        $t1, $t1, 16
    /* 1DD40 8002D540 034C0900 */  sra        $t1, $t1, 16
    /* 1DD44 8002D544 19002C01 */  multu      $t1, $t4
    /* 1DD48 8002D548 12480000 */  mflo       $t1
    /* 1DD4C 8002D54C 034B0900 */  sra        $t1, $t1, 12
    /* 1DD50 8002D550 FFFF2931 */  andi       $t1, $t1, 0xFFFF
    /* 1DD54 8002D554 03540800 */  sra        $t2, $t0, 16
    /* 1DD58 8002D558 19004D01 */  multu      $t2, $t5
    /* 1DD5C 8002D55C 12500000 */  mflo       $t2
    /* 1DD60 8002D560 03530A00 */  sra        $t2, $t2, 12
    /* 1DD64 8002D564 00540A00 */  sll        $t2, $t2, 16
    /* 1DD68 8002D568 25482A01 */  or         $t1, $t1, $t2
    /* 1DD6C 8002D56C 080089AC */  sw         $t1, 0x8($a0)
    /* 1DD70 8002D570 0C00888C */  lw         $t0, 0xC($a0)
    /* 1DD74 8002D574 00000000 */  nop
    /* 1DD78 8002D578 FFFF0931 */  andi       $t1, $t0, 0xFFFF
    /* 1DD7C 8002D57C 004C0900 */  sll        $t1, $t1, 16
    /* 1DD80 8002D580 034C0900 */  sra        $t1, $t1, 16
    /* 1DD84 8002D584 19002B01 */  multu      $t1, $t3
    /* 1DD88 8002D588 12480000 */  mflo       $t1
    /* 1DD8C 8002D58C 034B0900 */  sra        $t1, $t1, 12
    /* 1DD90 8002D590 FFFF2931 */  andi       $t1, $t1, 0xFFFF
    /* 1DD94 8002D594 03540800 */  sra        $t2, $t0, 16
    /* 1DD98 8002D598 19004C01 */  multu      $t2, $t4
    /* 1DD9C 8002D59C 12500000 */  mflo       $t2
    /* 1DDA0 8002D5A0 03530A00 */  sra        $t2, $t2, 12
    /* 1DDA4 8002D5A4 00540A00 */  sll        $t2, $t2, 16
    /* 1DDA8 8002D5A8 25482A01 */  or         $t1, $t1, $t2
    /* 1DDAC 8002D5AC 0C0089AC */  sw         $t1, 0xC($a0)
    /* 1DDB0 8002D5B0 1000888C */  lw         $t0, 0x10($a0)
    /* 1DDB4 8002D5B4 00000000 */  nop
    /* 1DDB8 8002D5B8 FFFF0931 */  andi       $t1, $t0, 0xFFFF
    /* 1DDBC 8002D5BC 004C0900 */  sll        $t1, $t1, 16
    /* 1DDC0 8002D5C0 034C0900 */  sra        $t1, $t1, 16
    /* 1DDC4 8002D5C4 19002D01 */  multu      $t1, $t5
    /* 1DDC8 8002D5C8 12480000 */  mflo       $t1
    /* 1DDCC 8002D5CC 034B0900 */  sra        $t1, $t1, 12
    /* 1DDD0 8002D5D0 100089AC */  sw         $t1, 0x10($a0)
    /* 1DDD4 8002D5D4 0800E003 */  jr         $ra
    /* 1DDD8 8002D5D8 21108000 */   addu      $v0, $a0, $zero
endlabel ScaleMatrix
    /* 1DDDC 8002D5DC 00000000 */  nop
    /* 1DDE0 8002D5E0 00000000 */  nop
