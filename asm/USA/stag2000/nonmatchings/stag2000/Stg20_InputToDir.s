nonmatching Stg20_InputToDir, 0x58

glabel Stg20_InputToDir
    /* 79B4 8006AD14 00100324 */  addiu      $v1, $zero, 0x1000
    /* 79B8 8006AD18 2C00828C */  lw         $v0, 0x2C($a0)
    /* 79BC 8006AD1C 21200000 */  addu       $a0, $zero, $zero
    /* 79C0 8006AD20 2400458C */  lw         $a1, 0x24($v0)
  .L8006AD24:
    /* 79C4 8006AD24 FFFF6230 */  andi       $v0, $v1, 0xFFFF
    /* 79C8 8006AD28 2410A200 */  and        $v0, $a1, $v0
    /* 79CC 8006AD2C 09004010 */  beqz       $v0, .L8006AD54
    /* 79D0 8006AD30 00000000 */   nop
    /* 79D4 8006AD34 02008324 */  addiu      $v1, $a0, 0x2
    /* 79D8 8006AD38 02006104 */  bgez       $v1, .L8006AD44
    /* 79DC 8006AD3C 21106000 */   addu      $v0, $v1, $zero
    /* 79E0 8006AD40 05008224 */  addiu      $v0, $a0, 0x5
  .L8006AD44:
    /* 79E4 8006AD44 83100200 */  sra        $v0, $v0, 2
    /* 79E8 8006AD48 80100200 */  sll        $v0, $v0, 2
    /* 79EC 8006AD4C 0800E003 */  jr         $ra
    /* 79F0 8006AD50 23106200 */   subu      $v0, $v1, $v0
  .L8006AD54:
    /* 79F4 8006AD54 01008424 */  addiu      $a0, $a0, 0x1
    /* 79F8 8006AD58 04008228 */  slti       $v0, $a0, 0x4
    /* 79FC 8006AD5C F1FF4014 */  bnez       $v0, .L8006AD24
    /* 7A00 8006AD60 40180300 */   sll       $v1, $v1, 1
    /* 7A04 8006AD64 0800E003 */  jr         $ra
    /* 7A08 8006AD68 FFFF0224 */   addiu     $v0, $zero, -0x1
endlabel Stg20_InputToDir
