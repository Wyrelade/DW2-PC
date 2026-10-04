nonmatching Stg20_CanUpgradePart, 0xA8

glabel Stg20_CanUpgradePart
    /* B688 8006E9E8 2F008228 */  slti       $v0, $a0, 0x2F
    /* B68C 8006E9EC 0F004010 */  beqz       $v0, .L8006EA2C
    /* B690 8006E9F0 2E000224 */   addiu     $v0, $zero, 0x2E
    /* B694 8006E9F4 0B008210 */  beq        $a0, $v0, .L8006EA24
    /* B698 8006E9F8 6666023C */   lui       $v0, (0x66666667 >> 16)
    /* B69C 8006E9FC 67664234 */  ori        $v0, $v0, (0x66666667 & 0xFFFF)
  .L8006EA00:
    /* B6A0 8006EA00 18008200 */  mult       $a0, $v0
    /* B6A4 8006EA04 C3170400 */  sra        $v0, $a0, 31
    /* B6A8 8006EA08 10280000 */  mfhi       $a1
    /* B6AC 8006EA0C 43180500 */  sra        $v1, $a1, 1
    /* B6B0 8006EA10 23186200 */  subu       $v1, $v1, $v0
    /* B6B4 8006EA14 80100300 */  sll        $v0, $v1, 2
    /* B6B8 8006EA18 21104300 */  addu       $v0, $v0, $v1
  .L8006EA1C:
    /* B6BC 8006EA1C 1A008214 */  bne        $a0, $v0, .L8006EA88
    /* B6C0 8006EA20 01000224 */   addiu     $v0, $zero, 0x1
  .L8006EA24:
    /* B6C4 8006EA24 0800E003 */  jr         $ra
    /* B6C8 8006EA28 21100000 */   addu      $v0, $zero, $zero
  .L8006EA2C:
    /* B6CC 8006EA2C 4A008228 */  slti       $v0, $a0, 0x4A
    /* B6D0 8006EA30 06004010 */  beqz       $v0, .L8006EA4C
    /* B6D4 8006EA34 49000224 */   addiu     $v0, $zero, 0x49
    /* B6D8 8006EA38 FAFF8210 */  beq        $a0, $v0, .L8006EA24
    /* B6DC 8006EA3C 6666023C */   lui       $v0, (0x66666667 >> 16)
    /* B6E0 8006EA40 67664234 */  ori        $v0, $v0, (0x66666667 & 0xFFFF)
    /* B6E4 8006EA44 80BA0108 */  j          .L8006EA00
    /* B6E8 8006EA48 CCFF8424 */   addiu     $a0, $a0, -0x34
  .L8006EA4C:
    /* B6EC 8006EA4C 63008228 */  slti       $v0, $a0, 0x63
    /* B6F0 8006EA50 F2FF4014 */  bnez       $v0, .L8006EA1C
    /* B6F4 8006EA54 62000224 */   addiu     $v0, $zero, 0x62
    /* B6F8 8006EA58 66008228 */  slti       $v0, $a0, 0x66
    /* B6FC 8006EA5C EFFF4014 */  bnez       $v0, .L8006EA1C
    /* B700 8006EA60 65000224 */   addiu     $v0, $zero, 0x65
    /* B704 8006EA64 6D008228 */  slti       $v0, $a0, 0x6D
    /* B708 8006EA68 ECFF4014 */  bnez       $v0, .L8006EA1C
    /* B70C 8006EA6C 6C000224 */   addiu     $v0, $zero, 0x6C
    /* B710 8006EA70 72008228 */  slti       $v0, $a0, 0x72
    /* B714 8006EA74 03004010 */  beqz       $v0, .L8006EA84
    /* B718 8006EA78 6F000324 */   addiu     $v1, $zero, 0x6F
    /* B71C 8006EA7C 02008310 */  beq        $a0, $v1, .L8006EA88
    /* B720 8006EA80 21100000 */   addu      $v0, $zero, $zero
  .L8006EA84:
    /* B724 8006EA84 01000224 */  addiu      $v0, $zero, 0x1
  .L8006EA88:
    /* B728 8006EA88 0800E003 */  jr         $ra
    /* B72C 8006EA8C 00000000 */   nop
endlabel Stg20_CanUpgradePart
