nonmatching func_800648AC, 0x84

glabel func_800648AC
    /* 154C 800648AC 21280000 */  addu       $a1, $zero, $zero
    /* 1550 800648B0 2138A000 */  addu       $a3, $a1, $zero
    /* 1554 800648B4 0580033C */  lui        $v1, %hi(Cd_PreloadIds)
    /* 1558 800648B8 0580023C */  lui        $v0, %hi(Cd_PreloadCount)
    /* 155C 800648BC 5C07468C */  lw         $a2, %lo(Cd_PreloadCount)($v0)
    /* 1560 800648C0 00000000 */  nop
    /* 1564 800648C4 0B00C018 */  blez       $a2, .L800648F4
    /* 1568 800648C8 48096224 */   addiu     $v0, $v1, %lo(Cd_PreloadIds)
    /* 156C 800648CC 21184000 */  addu       $v1, $v0, $zero
  .L800648D0:
    /* 1570 800648D0 0000628C */  lw         $v0, 0x0($v1)
    /* 1574 800648D4 00000000 */  nop
    /* 1578 800648D8 03004414 */  bne        $v0, $a0, .L800648E8
    /* 157C 800648DC 0100A524 */   addiu     $a1, $a1, 0x1
    /* 1580 800648E0 0800E003 */  jr         $ra
    /* 1584 800648E4 01000224 */   addiu     $v0, $zero, 0x1
  .L800648E8:
    /* 1588 800648E8 2A10A600 */  slt        $v0, $a1, $a2
    /* 158C 800648EC F8FF4014 */  bnez       $v0, .L800648D0
    /* 1590 800648F0 04006324 */   addiu     $v1, $v1, 0x4
  .L800648F4:
    /* 1594 800648F4 0580063C */  lui        $a2, %hi(Cd_PreloadCount)
    /* 1598 800648F8 5C07C58C */  lw         $a1, %lo(Cd_PreloadCount)($a2)
    /* 159C 800648FC 00000000 */  nop
    /* 15A0 80064900 4000A228 */  slti       $v0, $a1, 0x40
    /* 15A4 80064904 08004010 */  beqz       $v0, .L80064928
    /* 15A8 80064908 0580023C */   lui       $v0, %hi(Cd_PreloadIds)
    /* 15AC 8006490C 01000724 */  addiu      $a3, $zero, 0x1
    /* 15B0 80064910 48094224 */  addiu      $v0, $v0, %lo(Cd_PreloadIds)
    /* 15B4 80064914 80180500 */  sll        $v1, $a1, 2
    /* 15B8 80064918 21186200 */  addu       $v1, $v1, $v0
    /* 15BC 8006491C 2110A700 */  addu       $v0, $a1, $a3
    /* 15C0 80064920 000064AC */  sw         $a0, 0x0($v1)
    /* 15C4 80064924 5C07C2AC */  sw         $v0, %lo(Cd_PreloadCount)($a2)
  .L80064928:
    /* 15C8 80064928 0800E003 */  jr         $ra
    /* 15CC 8006492C 2110E000 */   addu      $v0, $a3, $zero
endlabel func_800648AC
