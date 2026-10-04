nonmatching func_8006E920, 0x164

glabel func_8006E920
    /* B5C0 8006E920 0780023C */  lui        $v0, %hi(D_80072B60)
    /* B5C4 8006E924 602B428C */  lw         $v0, %lo(D_80072B60)($v0)
    /* B5C8 8006E928 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* B5CC 8006E92C 2800B6AF */  sw         $s6, 0x28($sp)
    /* B5D0 8006E930 21B08000 */  addu       $s6, $a0, $zero
    /* B5D4 8006E934 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* B5D8 8006E938 2400B5AF */  sw         $s5, 0x24($sp)
    /* B5DC 8006E93C 2000B4AF */  sw         $s4, 0x20($sp)
    /* B5E0 8006E940 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* B5E4 8006E944 1800B2AF */  sw         $s2, 0x18($sp)
    /* B5E8 8006E948 1400B1AF */  sw         $s1, 0x14($sp)
    /* B5EC 8006E94C 1000B0AF */  sw         $s0, 0x10($sp)
    /* B5F0 8006E950 E10040A0 */  sb         $zero, 0xE1($v0)
    /* B5F4 8006E954 0000C486 */  lh         $a0, 0x0($s6)
    /* B5F8 8006E958 08BA010C */  jal        func_8006E820
    /* B5FC 8006E95C 00000000 */   nop
    /* B600 8006E960 21184000 */  addu       $v1, $v0, $zero
    /* B604 8006E964 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* B608 8006E968 05006210 */  beq        $v1, $v0, .L8006E980
    /* B60C 8006E96C 00000000 */   nop
    /* B610 8006E970 06006010 */  beqz       $v1, .L8006E98C
    /* B614 8006E974 21A00000 */   addu      $s4, $zero, $zero
    /* B618 8006E978 66BA0108 */  j          .L8006E998
    /* B61C 8006E97C 0780153C */   lui       $s5, %hi(D_80072B60)
  .L8006E980:
    /* B620 8006E980 0C00C28E */  lw         $v0, 0xC($s6)
    /* B624 8006E984 97BA0108 */  j          .L8006EA5C
    /* B628 8006E988 00000000 */   nop
  .L8006E98C:
    /* B62C 8006E98C 0C00C28E */  lw         $v0, 0xC($s6)
    /* B630 8006E990 97BA0108 */  j          .L8006EA5C
    /* B634 8006E994 01004224 */   addiu     $v0, $v0, 0x1
  .L8006E998:
    /* B638 8006E998 2198C002 */  addu       $s3, $s6, $zero
  .L8006E99C:
    /* B63C 8006E99C 0580023C */  lui        $v0, %hi(D_80050720)
    /* B640 8006E9A0 2007428C */  lw         $v0, %lo(D_80050720)($v0)
    /* B644 8006E9A4 02007286 */  lh         $s2, 0x2($s3)
    /* B648 8006E9A8 66004424 */  addiu      $a0, $v0, 0x66
    /* B64C 8006E9AC FFFF0224 */  addiu      $v0, $zero, -0x1
    /* B650 8006E9B0 1B004212 */  beq        $s2, $v0, .L8006EA20
    /* B654 8006E9B4 00000000 */   nop
    /* B658 8006E9B8 21880000 */  addu       $s1, $zero, $zero
    /* B65C 8006E9BC 21808000 */  addu       $s0, $a0, $zero
  .L8006E9C0:
    /* B660 8006E9C0 00000296 */  lhu        $v0, 0x0($s0)
    /* B664 8006E9C4 00000000 */  nop
    /* B668 8006E9C8 11004010 */  beqz       $v0, .L8006EA10
    /* B66C 8006E9CC 00000000 */   nop
    /* B670 8006E9D0 3078000C */  jal        Item_GetCategory
    /* B674 8006E9D4 21204000 */   addu      $a0, $v0, $zero
    /* B678 8006E9D8 0D004216 */  bne        $s2, $v0, .L8006EA10
    /* B67C 8006E9DC 00000000 */   nop
    /* B680 8006E9E0 602BA28E */  lw         $v0, %lo(D_80072B60)($s5)
    /* B684 8006E9E4 00000000 */  nop
    /* B688 8006E9E8 E1004390 */  lbu        $v1, 0xE1($v0)
    /* B68C 8006E9EC 00000492 */  lbu        $a0, 0x0($s0)
    /* B690 8006E9F0 21104300 */  addu       $v0, $v0, $v1
    /* B694 8006E9F4 B00044A0 */  sb         $a0, 0xB0($v0)
    /* B698 8006E9F8 602BA38E */  lw         $v1, %lo(D_80072B60)($s5)
    /* B69C 8006E9FC 00000000 */  nop
    /* B6A0 8006EA00 E1006290 */  lbu        $v0, 0xE1($v1)
    /* B6A4 8006EA04 00000000 */  nop
    /* B6A8 8006EA08 01004224 */  addiu      $v0, $v0, 0x1
    /* B6AC 8006EA0C E10062A0 */  sb         $v0, 0xE1($v1)
  .L8006EA10:
    /* B6B0 8006EA10 01003126 */  addiu      $s1, $s1, 0x1
    /* B6B4 8006EA14 3000222A */  slti       $v0, $s1, 0x30
    /* B6B8 8006EA18 E9FF4014 */  bnez       $v0, .L8006E9C0
    /* B6BC 8006EA1C 02001026 */   addiu     $s0, $s0, 0x2
  .L8006EA20:
    /* B6C0 8006EA20 01009426 */  addiu      $s4, $s4, 0x1
    /* B6C4 8006EA24 0400822A */  slti       $v0, $s4, 0x4
    /* B6C8 8006EA28 DCFF4014 */  bnez       $v0, .L8006E99C
    /* B6CC 8006EA2C 02007326 */   addiu     $s3, $s3, 0x2
    /* B6D0 8006EA30 0780023C */  lui        $v0, %hi(D_80072B60)
    /* B6D4 8006EA34 602B428C */  lw         $v0, %lo(D_80072B60)($v0)
    /* B6D8 8006EA38 00000000 */  nop
    /* B6DC 8006EA3C E1004290 */  lbu        $v0, 0xE1($v0)
    /* B6E0 8006EA40 00000000 */  nop
    /* B6E4 8006EA44 04004014 */  bnez       $v0, .L8006EA58
    /* B6E8 8006EA48 00000000 */   nop
    /* B6EC 8006EA4C 0C00C28E */  lw         $v0, 0xC($s6)
    /* B6F0 8006EA50 97BA0108 */  j          .L8006EA5C
    /* B6F4 8006EA54 02004224 */   addiu     $v0, $v0, 0x2
  .L8006EA58:
    /* B6F8 8006EA58 21100000 */  addu       $v0, $zero, $zero
  .L8006EA5C:
    /* B6FC 8006EA5C 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* B700 8006EA60 2800B68F */  lw         $s6, 0x28($sp)
    /* B704 8006EA64 2400B58F */  lw         $s5, 0x24($sp)
    /* B708 8006EA68 2000B48F */  lw         $s4, 0x20($sp)
    /* B70C 8006EA6C 1C00B38F */  lw         $s3, 0x1C($sp)
    /* B710 8006EA70 1800B28F */  lw         $s2, 0x18($sp)
    /* B714 8006EA74 1400B18F */  lw         $s1, 0x14($sp)
    /* B718 8006EA78 1000B08F */  lw         $s0, 0x10($sp)
    /* B71C 8006EA7C 0800E003 */  jr         $ra
    /* B720 8006EA80 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_8006E920
