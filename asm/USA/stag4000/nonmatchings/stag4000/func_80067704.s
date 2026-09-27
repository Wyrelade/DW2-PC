nonmatching func_80067704, 0x4C

glabel func_80067704
    /* 43A4 80067704 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 43A8 80067708 1400B1AF */  sw         $s1, 0x14($sp)
    /* 43AC 8006770C 21888000 */  addu       $s1, $a0, $zero
    /* 43B0 80067710 1000B0AF */  sw         $s0, 0x10($sp)
    /* 43B4 80067714 1800BFAF */  sw         $ra, 0x18($sp)
    /* 43B8 80067718 B49D010C */  jal        func_800676D0
    /* 43BC 8006771C 21800000 */   addu      $s0, $zero, $zero
    /* 43C0 80067720 01000324 */  addiu      $v1, $zero, 0x1
    /* 43C4 80067724 05004314 */  bne        $v0, $v1, .L8006773C
    /* 43C8 80067728 21100002 */   addu      $v0, $s0, $zero
    /* 43CC 8006772C A99D010C */  jal        func_800676A4
    /* 43D0 80067730 21202002 */   addu      $a0, $s1, $zero
    /* 43D4 80067734 01001024 */  addiu      $s0, $zero, 0x1
    /* 43D8 80067738 21100002 */  addu       $v0, $s0, $zero
  .L8006773C:
    /* 43DC 8006773C 1800BF8F */  lw         $ra, 0x18($sp)
    /* 43E0 80067740 1400B18F */  lw         $s1, 0x14($sp)
    /* 43E4 80067744 1000B08F */  lw         $s0, 0x10($sp)
    /* 43E8 80067748 0800E003 */  jr         $ra
    /* 43EC 8006774C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80067704
