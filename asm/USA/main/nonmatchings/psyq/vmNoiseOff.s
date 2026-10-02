nonmatching vmNoiseOff, 0x38

glabel vmNoiseOff
    /* 28AD4 800382D4 FF008430 */  andi       $a0, $a0, 0xFF
    /* 28AD8 800382D8 C0100400 */  sll        $v0, $a0, 3
    /* 28ADC 800382DC 23104400 */  subu       $v0, $v0, $a0
    /* 28AE0 800382E0 C0100200 */  sll        $v0, $v0, 3
    /* 28AE4 800382E4 0680013C */  lui        $at, %hi(D_80062505)
    /* 28AE8 800382E8 21082200 */  addu       $at, $at, $v0
    /* 28AEC 800382EC 052520A0 */  sb         $zero, %lo(D_80062505)($at)
    /* 28AF0 800382F0 0680013C */  lui        $at, %hi(D_800624E8)
    /* 28AF4 800382F4 21082200 */  addu       $at, $at, $v0
    /* 28AF8 800382F8 E82420A4 */  sh         $zero, %lo(D_800624E8)($at)
    /* 28AFC 800382FC 0680013C */  lui        $at, %hi(D_800624EC)
    /* 28B00 80038300 21082200 */  addu       $at, $at, $v0
    /* 28B04 80038304 0800E003 */  jr         $ra
    /* 28B08 80038308 EC2420A4 */   sh        $zero, %lo(D_800624EC)($at)
endlabel vmNoiseOff
    /* 28B0C 8003830C 00000000 */  nop
    /* 28B10 80038310 00000000 */  nop
