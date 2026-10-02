nonmatching Math_MakeAxisRotMatrix, 0xC8

glabel Math_MakeAxisRotMatrix
    /* 1C4C4 8002BCC4 21488000 */  addu       $t1, $a0, $zero
    /* 1C4C8 8002BCC8 0680083C */  lui        $t0, %hi(D_80061A28)
    /* 1C4CC 8002BCCC 281A0825 */  addiu      $t0, $t0, %lo(D_80061A28)
    /* 1C4D0 8002BCD0 0000028D */  lw         $v0, 0x0($t0)
    /* 1C4D4 8002BCD4 0400038D */  lw         $v1, 0x4($t0)
    /* 1C4D8 8002BCD8 0800048D */  lw         $a0, 0x8($t0)
    /* 1C4DC 8002BCDC 000022AD */  sw         $v0, 0x0($t1)
    /* 1C4E0 8002BCE0 040023AD */  sw         $v1, 0x4($t1)
    /* 1C4E4 8002BCE4 080024AD */  sw         $a0, 0x8($t1)
    /* 1C4E8 8002BCE8 0C00028D */  lw         $v0, 0xC($t0)
    /* 1C4EC 8002BCEC 1000038D */  lw         $v1, 0x10($t0)
    /* 1C4F0 8002BCF0 1400048D */  lw         $a0, 0x14($t0)
    /* 1C4F4 8002BCF4 0C0022AD */  sw         $v0, 0xC($t1)
    /* 1C4F8 8002BCF8 100023AD */  sw         $v1, 0x10($t1)
    /* 1C4FC 8002BCFC 140024AD */  sw         $a0, 0x14($t1)
    /* 1C500 8002BD00 1800028D */  lw         $v0, 0x18($t0)
    /* 1C504 8002BD04 1C00038D */  lw         $v1, 0x1C($t0)
    /* 1C508 8002BD08 180022AD */  sw         $v0, 0x18($t1)
    /* 1C50C 8002BD0C 1C0023AD */  sw         $v1, 0x1C($t1)
    /* 1C510 8002BD10 A8FFE724 */  addiu      $a3, $a3, -0x58
    /* 1C514 8002BD14 003E0700 */  sll        $a3, $a3, 24
    /* 1C518 8002BD18 033E0700 */  sra        $a3, $a3, 24
    /* 1C51C 8002BD1C 2300E22C */  sltiu      $v0, $a3, 0x23
    /* 1C520 8002BD20 18004010 */  beqz       $v0, .L8002BD84
    /* 1C524 8002BD24 80100700 */   sll       $v0, $a3, 2
    /* 1C528 8002BD28 0180013C */  lui        $at, %hi(jtbl_80010644)
    /* 1C52C 8002BD2C 21082200 */  addu       $at, $at, $v0
    /* 1C530 8002BD30 4406228C */  lw         $v0, %lo(jtbl_80010644)($at)
    /* 1C534 8002BD34 00000000 */  nop
    /* 1C538 8002BD38 08004000 */  jr         $v0
    /* 1C53C 8002BD3C 00000000 */   nop
  jlabel .L8002BD40
    /* 1C540 8002BD40 23100500 */  negu       $v0, $a1
    /* 1C544 8002BD44 080026A5 */  sh         $a2, 0x8($t1)
    /* 1C548 8002BD48 100026A5 */  sh         $a2, 0x10($t1)
    /* 1C54C 8002BD4C 0A0022A5 */  sh         $v0, 0xA($t1)
    /* 1C550 8002BD50 61AF0008 */  j          .L8002BD84
    /* 1C554 8002BD54 0E0025A5 */   sh        $a1, 0xE($t1)
  jlabel .L8002BD58
    /* 1C558 8002BD58 23100500 */  negu       $v0, $a1
    /* 1C55C 8002BD5C 000026A5 */  sh         $a2, 0x0($t1)
    /* 1C560 8002BD60 100026A5 */  sh         $a2, 0x10($t1)
    /* 1C564 8002BD64 040025A5 */  sh         $a1, 0x4($t1)
    /* 1C568 8002BD68 61AF0008 */  j          .L8002BD84
    /* 1C56C 8002BD6C 0C0022A5 */   sh        $v0, 0xC($t1)
  jlabel .L8002BD70
    /* 1C570 8002BD70 23100500 */  negu       $v0, $a1
    /* 1C574 8002BD74 000026A5 */  sh         $a2, 0x0($t1)
    /* 1C578 8002BD78 080026A5 */  sh         $a2, 0x8($t1)
    /* 1C57C 8002BD7C 020022A5 */  sh         $v0, 0x2($t1)
    /* 1C580 8002BD80 060025A5 */  sh         $a1, 0x6($t1)
  jlabel .L8002BD84
    /* 1C584 8002BD84 0800E003 */  jr         $ra
    /* 1C588 8002BD88 00000000 */   nop
endlabel Math_MakeAxisRotMatrix
    /* 1C58C 8002BD8C 00000000 */  nop
    /* 1C590 8002BD90 00000000 */  nop
