nonmatching Stg20_LoadShopBuyList, 0x1DC

glabel Stg20_LoadShopBuyList
    /* 91B4 8006C514 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 91B8 8006C518 CF03023C */  lui        $v0, (0x3CF0000 >> 16)
    /* 91BC 8006C51C 3400BFAF */  sw         $ra, 0x34($sp)
    /* 91C0 8006C520 3000BEAF */  sw         $fp, 0x30($sp)
    /* 91C4 8006C524 2C00B7AF */  sw         $s7, 0x2C($sp)
    /* 91C8 8006C528 2800B6AF */  sw         $s6, 0x28($sp)
    /* 91CC 8006C52C 2400B5AF */  sw         $s5, 0x24($sp)
    /* 91D0 8006C530 2000B4AF */  sw         $s4, 0x20($sp)
    /* 91D4 8006C534 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 91D8 8006C538 1800B2AF */  sw         $s2, 0x18($sp)
    /* 91DC 8006C53C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 91E0 8006C540 1000B0AF */  sw         $s0, 0x10($sp)
    /* 91E4 8006C544 2C00968C */  lw         $s6, 0x2C($a0)
    /* 91E8 8006C548 688E000C */  jal        Cd_GetFileEntry
    /* 91EC 8006C54C 2120A200 */   addu      $a0, $a1, $v0
    /* 91F0 8006C550 21584000 */  addu       $t3, $v0, $zero
    /* 91F4 8006C554 FD000924 */  addiu      $t1, $zero, 0xFD
    /* 91F8 8006C558 0780023C */  lui        $v0, %hi(Stg20_ShopItems)
    /* 91FC 8006C55C 080A4824 */  addiu      $t0, $v0, %lo(Stg20_ShopItems)
    /* 9200 8006C560 21300001 */  addu       $a2, $t0, $zero
    /* 9204 8006C564 21380000 */  addu       $a3, $zero, $zero
    /* 9208 8006C568 2120C000 */  addu       $a0, $a2, $zero
    /* 920C 8006C56C 64008A24 */  addiu      $t2, $a0, 0x64
    /* 9210 8006C570 4800C0AE */  sw         $zero, 0x48($s6)
  .L8006C574:
    /* 9214 8006C574 000080A4 */  sh         $zero, 0x0($a0)
    /* 9218 8006C578 21180000 */  addu       $v1, $zero, $zero
    /* 921C 8006C57C 2128E000 */  addu       $a1, $a3, $zero
    /* 9220 8006C580 21106500 */  addu       $v0, $v1, $a1
  .L8006C584:
    /* 9224 8006C584 21104800 */  addu       $v0, $v0, $t0
    /* 9228 8006C588 640049A0 */  sb         $t1, 0x64($v0)
    /* 922C 8006C58C 01006324 */  addiu      $v1, $v1, 0x1
    /* 9230 8006C590 19006228 */  slti       $v0, $v1, 0x19
    /* 9234 8006C594 FBFF4014 */  bnez       $v0, .L8006C584
    /* 9238 8006C598 21106500 */   addu      $v0, $v1, $a1
    /* 923C 8006C59C FF000224 */  addiu      $v0, $zero, 0xFF
    /* 9240 8006C5A0 7C00C2A0 */  sb         $v0, 0x7C($a2)
    /* 9244 8006C5A4 1900C624 */  addiu      $a2, $a2, 0x19
    /* 9248 8006C5A8 02008424 */  addiu      $a0, $a0, 0x2
    /* 924C 8006C5AC 2A108A00 */  slt        $v0, $a0, $t2
    /* 9250 8006C5B0 F0FF4014 */  bnez       $v0, .L8006C574
    /* 9254 8006C5B4 1900E724 */   addiu     $a3, $a3, 0x19
    /* 9258 8006C5B8 21900000 */  addu       $s2, $zero, $zero
    /* 925C 8006C5BC FF001E24 */  addiu      $fp, $zero, 0xFF
    /* 9260 8006C5C0 0780023C */  lui        $v0, %hi(Stg20_ShopItems)
    /* 9264 8006C5C4 080A5724 */  addiu      $s7, $v0, %lo(Stg20_ShopItems)
    /* 9268 8006C5C8 2180E002 */  addu       $s0, $s7, $zero
    /* 926C 8006C5CC 21886001 */  addu       $s1, $t3, $zero
    /* 9270 8006C5D0 7200F526 */  addiu      $s5, $s7, 0x72
    /* 9274 8006C5D4 21A04002 */  addu       $s4, $s2, $zero
    /* 9278 8006C5D8 21980002 */  addu       $s3, $s0, $zero
  .L8006C5DC:
    /* 927C 8006C5DC 00002292 */  lbu        $v0, 0x0($s1)
    /* 9280 8006C5E0 00000000 */  nop
    /* 9284 8006C5E4 2B004010 */  beqz       $v0, .L8006C694
    /* 9288 8006C5E8 00000000 */   nop
    /* 928C 8006C5EC 00002292 */  lbu        $v0, 0x0($s1)
    /* 9290 8006C5F0 00000000 */  nop
    /* 9294 8006C5F4 000062A6 */  sh         $v0, 0x0($s3)
    /* 9298 8006C5F8 00002492 */  lbu        $a0, 0x0($s1)
    /* 929C 8006C5FC 1278000C */  jal        Item_GetNameText
    /* 92A0 8006C600 00000000 */   nop
    /* 92A4 8006C604 21284000 */  addu       $a1, $v0, $zero
    /* 92A8 8006C608 21180000 */  addu       $v1, $zero, $zero
    /* 92AC 8006C60C 21308002 */  addu       $a2, $s4, $zero
  .L8006C610:
    /* 92B0 8006C610 0000A490 */  lbu        $a0, 0x0($a1)
    /* 92B4 8006C614 00000000 */  nop
    /* 92B8 8006C618 07009E10 */  beq        $a0, $fp, .L8006C638
    /* 92BC 8006C61C 21106600 */   addu      $v0, $v1, $a2
    /* 92C0 8006C620 21105700 */  addu       $v0, $v0, $s7
    /* 92C4 8006C624 640044A0 */  sb         $a0, 0x64($v0)
    /* 92C8 8006C628 01006324 */  addiu      $v1, $v1, 0x1
    /* 92CC 8006C62C 0A006228 */  slti       $v0, $v1, 0xA
    /* 92D0 8006C630 F7FF4014 */  bnez       $v0, .L8006C610
    /* 92D4 8006C634 0100A524 */   addiu     $a1, $a1, 0x1
  .L8006C638:
    /* 92D8 8006C638 2120A002 */  addu       $a0, $s5, $zero
    /* 92DC 8006C63C 00002592 */  lbu        $a1, 0x0($s1)
    /* 92E0 8006C640 01003126 */  addiu      $s1, $s1, 0x1
    /* 92E4 8006C644 1900B526 */  addiu      $s5, $s5, 0x19
    /* 92E8 8006C648 19009426 */  addiu      $s4, $s4, 0x19
    /* 92EC 8006C64C 02007326 */  addiu      $s3, $s3, 0x2
    /* 92F0 8006C650 08B1010C */  jal        Stg20_FormatPrice
    /* 92F4 8006C654 01005226 */   addiu     $s2, $s2, 0x1
    /* 92F8 8006C658 0B000224 */  addiu      $v0, $zero, 0xB
    /* 92FC 8006C65C 770002A2 */  sb         $v0, 0x77($s0)
    /* 9300 8006C660 12000224 */  addiu      $v0, $zero, 0x12
    /* 9304 8006C664 780002A2 */  sb         $v0, 0x78($s0)
    /* 9308 8006C668 1D000224 */  addiu      $v0, $zero, 0x1D
    /* 930C 8006C66C 790002A2 */  sb         $v0, 0x79($s0)
    /* 9310 8006C670 36000224 */  addiu      $v0, $zero, 0x36
    /* 9314 8006C674 7A0002A2 */  sb         $v0, 0x7A($s0)
    /* 9318 8006C678 4800C28E */  lw         $v0, 0x48($s6)
    /* 931C 8006C67C 00000000 */  nop
    /* 9320 8006C680 01004224 */  addiu      $v0, $v0, 0x1
    /* 9324 8006C684 4800C2AE */  sw         $v0, 0x48($s6)
    /* 9328 8006C688 3200422A */  slti       $v0, $s2, 0x32
    /* 932C 8006C68C D3FF4014 */  bnez       $v0, .L8006C5DC
    /* 9330 8006C690 19001026 */   addiu     $s0, $s0, 0x19
  .L8006C694:
    /* 9334 8006C694 4800C38E */  lw         $v1, 0x48($s6)
    /* 9338 8006C698 00000000 */  nop
    /* 933C 8006C69C 06006010 */  beqz       $v1, .L8006C6B8
    /* 9340 8006C6A0 FFFF6224 */   addiu     $v0, $v1, -0x1
    /* 9344 8006C6A4 02004104 */  bgez       $v0, .L8006C6B0
    /* 9348 8006C6A8 00000000 */   nop
    /* 934C 8006C6AC 06006224 */  addiu      $v0, $v1, 0x6
  .L8006C6B0:
    /* 9350 8006C6B0 AFB10108 */  j          .L8006C6BC
    /* 9354 8006C6B4 C3100200 */   sra       $v0, $v0, 3
  .L8006C6B8:
    /* 9358 8006C6B8 21100000 */  addu       $v0, $zero, $zero
  .L8006C6BC:
    /* 935C 8006C6BC 4C00C2AE */  sw         $v0, 0x4C($s6)
    /* 9360 8006C6C0 3400BF8F */  lw         $ra, 0x34($sp)
    /* 9364 8006C6C4 3000BE8F */  lw         $fp, 0x30($sp)
    /* 9368 8006C6C8 2C00B78F */  lw         $s7, 0x2C($sp)
    /* 936C 8006C6CC 2800B68F */  lw         $s6, 0x28($sp)
    /* 9370 8006C6D0 2400B58F */  lw         $s5, 0x24($sp)
    /* 9374 8006C6D4 2000B48F */  lw         $s4, 0x20($sp)
    /* 9378 8006C6D8 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 937C 8006C6DC 1800B28F */  lw         $s2, 0x18($sp)
    /* 9380 8006C6E0 1400B18F */  lw         $s1, 0x14($sp)
    /* 9384 8006C6E4 1000B08F */  lw         $s0, 0x10($sp)
    /* 9388 8006C6E8 0800E003 */  jr         $ra
    /* 938C 8006C6EC 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel Stg20_LoadShopBuyList
