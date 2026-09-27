nonmatching Cd_FindFreeCacheSlot, 0x38

glabel Cd_FindFreeCacheSlot
    /* 142B0 80023AB0 0680023C */  lui        $v0, %hi(D_8005F8C8)
    /* 142B4 80023AB4 C8F84324 */  addiu      $v1, $v0, %lo(D_8005F8C8)
    /* 142B8 80023AB8 21200000 */  addu       $a0, $zero, $zero
  .L80023ABC:
    /* 142BC 80023ABC 0400628C */  lw         $v0, 0x4($v1)
    /* 142C0 80023AC0 00000000 */  nop
    /* 142C4 80023AC4 03004014 */  bnez       $v0, .L80023AD4
    /* 142C8 80023AC8 01008424 */   addiu     $a0, $a0, 0x1
    /* 142CC 80023ACC 0800E003 */  jr         $ra
    /* 142D0 80023AD0 21106000 */   addu      $v0, $v1, $zero
  .L80023AD4:
    /* 142D4 80023AD4 50008228 */  slti       $v0, $a0, 0x50
    /* 142D8 80023AD8 F8FF4014 */  bnez       $v0, .L80023ABC
    /* 142DC 80023ADC 10006324 */   addiu     $v1, $v1, 0x10
    /* 142E0 80023AE0 0800E003 */  jr         $ra
    /* 142E4 80023AE4 21100000 */   addu      $v0, $zero, $zero
endlabel Cd_FindFreeCacheSlot
