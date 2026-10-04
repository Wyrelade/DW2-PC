nonmatching func_8006C18C, 0x38

glabel func_8006C18C
    /* 8E2C 8006C18C 21280000 */  addu       $a1, $zero, $zero
    /* 8E30 8006C190 0680023C */  lui        $v0, %hi(Save_GameState)
    /* 8E34 8006C194 20E64324 */  addiu      $v1, $v0, %lo(Save_GameState)
  .L8006C198:
    /* 8E38 8006C198 2C006294 */  lhu        $v0, 0x2C($v1)
    /* 8E3C 8006C19C 00000000 */  nop
    /* 8E40 8006C1A0 03004414 */  bne        $v0, $a0, .L8006C1B0
    /* 8E44 8006C1A4 0100A524 */   addiu     $a1, $a1, 0x1
    /* 8E48 8006C1A8 0800E003 */  jr         $ra
    /* 8E4C 8006C1AC 01000224 */   addiu     $v0, $zero, 0x1
  .L8006C1B0:
    /* 8E50 8006C1B0 1300A228 */  slti       $v0, $a1, 0x13
    /* 8E54 8006C1B4 F8FF4014 */  bnez       $v0, .L8006C198
    /* 8E58 8006C1B8 02006324 */   addiu     $v1, $v1, 0x2
    /* 8E5C 8006C1BC 0800E003 */  jr         $ra
    /* 8E60 8006C1C0 21100000 */   addu      $v0, $zero, $zero
endlabel func_8006C18C
