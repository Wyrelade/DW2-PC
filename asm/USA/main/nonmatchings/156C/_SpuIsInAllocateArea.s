nonmatching _SpuIsInAllocateArea, 0x80

glabel _SpuIsInAllocateArea
    /* 2C084 8003B884 0580023C */  lui        $v0, %hi(Spu_MemList)
    /* 2C088 8003B888 90FE428C */  lw         $v0, %lo(Spu_MemList)($v0)
    /* 2C08C 8003B88C 00000000 */  nop
    /* 2C090 8003B890 03004014 */  bnez       $v0, .L8003B8A0
    /* 2C094 8003B894 0080083C */   lui       $t0, (0x80000000 >> 16)
    /* 2C098 8003B898 3FEE0008 */  j          .L8003B8FC
    /* 2C09C 8003B89C 21100000 */   addu      $v0, $zero, $zero
  .L8003B8A0:
    /* 2C0A0 8003B8A0 0040073C */  lui        $a3, (0x40000000 >> 16)
    /* 2C0A4 8003B8A4 FF0F063C */  lui        $a2, (0xFFFFFFF >> 16)
    /* 2C0A8 8003B8A8 FFFFC634 */  ori        $a2, $a2, (0xFFFFFFF & 0xFFFF)
    /* 2C0AC 8003B8AC 21284000 */  addu       $a1, $v0, $zero
  .L8003B8B0:
    /* 2C0B0 8003B8B0 0000A38C */  lw         $v1, 0x0($a1)
    /* 2C0B4 8003B8B4 00000000 */  nop
    /* 2C0B8 8003B8B8 24106800 */  and        $v0, $v1, $t0
    /* 2C0BC 8003B8BC 0C004014 */  bnez       $v0, .L8003B8F0
    /* 2C0C0 8003B8C0 24106700 */   and       $v0, $v1, $a3
    /* 2C0C4 8003B8C4 0C004014 */  bnez       $v0, .L8003B8F8
    /* 2C0C8 8003B8C8 24186600 */   and       $v1, $v1, $a2
    /* 2C0CC 8003B8CC 2B106400 */  sltu       $v0, $v1, $a0
    /* 2C0D0 8003B8D0 0A004010 */  beqz       $v0, .L8003B8FC
    /* 2C0D4 8003B8D4 01000224 */   addiu     $v0, $zero, 0x1
    /* 2C0D8 8003B8D8 0400A28C */  lw         $v0, 0x4($a1)
    /* 2C0DC 8003B8DC 00000000 */  nop
    /* 2C0E0 8003B8E0 21106200 */  addu       $v0, $v1, $v0
    /* 2C0E4 8003B8E4 2B108200 */  sltu       $v0, $a0, $v0
    /* 2C0E8 8003B8E8 04004014 */  bnez       $v0, .L8003B8FC
    /* 2C0EC 8003B8EC 01000224 */   addiu     $v0, $zero, 0x1
  .L8003B8F0:
    /* 2C0F0 8003B8F0 2CEE0008 */  j          .L8003B8B0
    /* 2C0F4 8003B8F4 0800A524 */   addiu     $a1, $a1, 0x8
  .L8003B8F8:
    /* 2C0F8 8003B8F8 21100000 */  addu       $v0, $zero, $zero
  .L8003B8FC:
    /* 2C0FC 8003B8FC 0800E003 */  jr         $ra
    /* 2C100 8003B900 00000000 */   nop
endlabel _SpuIsInAllocateArea
