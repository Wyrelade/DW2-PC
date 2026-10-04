nonmatching Stg20_FormatPrice, 0xF4

glabel Stg20_FormatPrice
    /* 90C0 8006C420 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 90C4 8006C424 1800B0AF */  sw         $s0, 0x18($sp)
    /* 90C8 8006C428 21808000 */  addu       $s0, $a0, $zero
    /* 90CC 8006C42C 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 90D0 8006C430 6078000C */  jal        Item_GetPrice
    /* 90D4 8006C434 2120A000 */   addu      $a0, $a1, $zero
    /* 90D8 8006C438 0780033C */  lui        $v1, %hi(Stg20_ShopSellMode)
    /* 90DC 8006C43C 040A638C */  lw         $v1, %lo(Stg20_ShopSellMode)($v1)
    /* 90E0 8006C440 00000000 */  nop
    /* 90E4 8006C444 04006010 */  beqz       $v1, .L8006C458
    /* 90E8 8006C448 21304000 */   addu      $a2, $v0, $zero
    /* 90EC 8006C44C C2170600 */  srl        $v0, $a2, 31
    /* 90F0 8006C450 2110C200 */  addu       $v0, $a2, $v0
    /* 90F4 8006C454 43300200 */  sra        $a2, $v0, 1
  .L8006C458:
    /* 90F8 8006C458 0200C104 */  bgez       $a2, .L8006C464
    /* 90FC 8006C45C 2110C000 */   addu      $v0, $a2, $zero
    /* 9100 8006C460 21100000 */  addu       $v0, $zero, $zero
  .L8006C464:
    /* 9104 8006C464 21304000 */  addu       $a2, $v0, $zero
    /* 9108 8006C468 04000524 */  addiu      $a1, $zero, 0x4
    /* 910C 8006C46C 1000A827 */  addiu      $t0, $sp, 0x10
    /* 9110 8006C470 6666073C */  lui        $a3, (0x66666667 >> 16)
    /* 9114 8006C474 6766E734 */  ori        $a3, $a3, (0x66666667 & 0xFFFF)
    /* 9118 8006C478 FFFF0924 */  addiu      $t1, $zero, -0x1
  .L8006C47C:
    /* 911C 8006C47C 1800C700 */  mult       $a2, $a3
    /* 9120 8006C480 21200501 */  addu       $a0, $t0, $a1
    /* 9124 8006C484 FFFFA524 */  addiu      $a1, $a1, -0x1
    /* 9128 8006C488 C3170600 */  sra        $v0, $a2, 31
    /* 912C 8006C48C 10500000 */  mfhi       $t2
    /* 9130 8006C490 83180A00 */  sra        $v1, $t2, 2
    /* 9134 8006C494 23186200 */  subu       $v1, $v1, $v0
    /* 9138 8006C498 80100300 */  sll        $v0, $v1, 2
    /* 913C 8006C49C 21104300 */  addu       $v0, $v0, $v1
    /* 9140 8006C4A0 40100200 */  sll        $v0, $v0, 1
    /* 9144 8006C4A4 2310C200 */  subu       $v0, $a2, $v0
    /* 9148 8006C4A8 000082A0 */  sb         $v0, 0x0($a0)
    /* 914C 8006C4AC F3FFA914 */  bne        $a1, $t1, .L8006C47C
    /* 9150 8006C4B0 21306000 */   addu      $a2, $v1, $zero
    /* 9154 8006C4B4 01000624 */  addiu      $a2, $zero, 0x1
    /* 9158 8006C4B8 21280000 */  addu       $a1, $zero, $zero
    /* 915C 8006C4BC 04000724 */  addiu      $a3, $zero, 0x4
    /* 9160 8006C4C0 1000A427 */  addiu      $a0, $sp, 0x10
  .L8006C4C4:
    /* 9164 8006C4C4 0700A710 */  beq        $a1, $a3, .L8006C4E4
    /* 9168 8006C4C8 00000000 */   nop
    /* 916C 8006C4CC 0500C010 */  beqz       $a2, .L8006C4E4
    /* 9170 8006C4D0 00000000 */   nop
    /* 9174 8006C4D4 00008290 */  lbu        $v0, 0x0($a0)
    /* 9178 8006C4D8 00000000 */  nop
    /* 917C 8006C4DC 05004010 */  beqz       $v0, .L8006C4F4
    /* 9180 8006C4E0 00000000 */   nop
  .L8006C4E4:
    /* 9184 8006C4E4 21300000 */  addu       $a2, $zero, $zero
    /* 9188 8006C4E8 00008390 */  lbu        $v1, 0x0($a0)
    /* 918C 8006C4EC 21100502 */  addu       $v0, $s0, $a1
    /* 9190 8006C4F0 000043A0 */  sb         $v1, 0x0($v0)
  .L8006C4F4:
    /* 9194 8006C4F4 0100A524 */  addiu      $a1, $a1, 0x1
    /* 9198 8006C4F8 0500A228 */  slti       $v0, $a1, 0x5
    /* 919C 8006C4FC F1FF4014 */  bnez       $v0, .L8006C4C4
    /* 91A0 8006C500 01008424 */   addiu     $a0, $a0, 0x1
    /* 91A4 8006C504 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 91A8 8006C508 1800B08F */  lw         $s0, 0x18($sp)
    /* 91AC 8006C50C 0800E003 */  jr         $ra
    /* 91B0 8006C510 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg20_FormatPrice
