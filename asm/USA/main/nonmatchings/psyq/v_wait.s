nonmatching v_wait, 0x98

glabel v_wait
    /* 2142C 80030C2C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 21430 80030C30 C02B0500 */  sll        $a1, $a1, 15
    /* 21434 80030C34 1000A5AF */  sw         $a1, 0x10($sp)
    /* 21438 80030C38 0580023C */  lui        $v0, %hi(Sys_VSyncCount)
    /* 2143C 80030C3C C0FB428C */  lw         $v0, %lo(Sys_VSyncCount)($v0)
    /* 21440 80030C40 00000000 */  nop
    /* 21444 80030C44 2A104400 */  slt        $v0, $v0, $a0
    /* 21448 80030C48 1A004010 */  beqz       $v0, .L80030CB4
    /* 2144C 80030C4C 1800BFAF */   sw        $ra, 0x18($sp)
    /* 21450 80030C50 FFFF0324 */  addiu      $v1, $zero, -0x1
  .L80030C54:
    /* 21454 80030C54 1000A28F */  lw         $v0, 0x10($sp)
    /* 21458 80030C58 00000000 */  nop
    /* 2145C 80030C5C FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 21460 80030C60 1000A2AF */  sw         $v0, 0x10($sp)
    /* 21464 80030C64 1000A28F */  lw         $v0, 0x10($sp)
    /* 21468 80030C68 00000000 */  nop
    /* 2146C 80030C6C 0B004314 */  bne        $v0, $v1, .L80030C9C
    /* 21470 80030C70 00000000 */   nop
    /* 21474 80030C74 0180043C */  lui        $a0, %hi(D_80010984)
    /* 21478 80030C78 CDC0000C */  jal        Debug_PutString
    /* 2147C 80030C7C 84098424 */   addiu     $a0, $a0, %lo(D_80010984)
    /* 21480 80030C80 31C3000C */  jal        ChangeClearPAD
    /* 21484 80030C84 21200000 */   addu      $a0, $zero, $zero
    /* 21488 80030C88 03000424 */  addiu      $a0, $zero, 0x3
    /* 2148C 80030C8C 019C000C */  jal        ChangeClearRCnt
    /* 21490 80030C90 21280000 */   addu      $a1, $zero, $zero
    /* 21494 80030C94 2DC30008 */  j          .L80030CB4
    /* 21498 80030C98 00000000 */   nop
  .L80030C9C:
    /* 2149C 80030C9C 0580023C */  lui        $v0, %hi(Sys_VSyncCount)
    /* 214A0 80030CA0 C0FB428C */  lw         $v0, %lo(Sys_VSyncCount)($v0)
    /* 214A4 80030CA4 00000000 */  nop
    /* 214A8 80030CA8 2A104400 */  slt        $v0, $v0, $a0
    /* 214AC 80030CAC E9FF4014 */  bnez       $v0, .L80030C54
    /* 214B0 80030CB0 00000000 */   nop
  .L80030CB4:
    /* 214B4 80030CB4 1800BF8F */  lw         $ra, 0x18($sp)
    /* 214B8 80030CB8 2000BD27 */  addiu      $sp, $sp, 0x20
    /* 214BC 80030CBC 0800E003 */  jr         $ra
    /* 214C0 80030CC0 00000000 */   nop
endlabel v_wait
