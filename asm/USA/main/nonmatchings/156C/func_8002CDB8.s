nonmatching func_8002CDB8, 0x98

glabel func_8002CDB8
    /* 1D5B8 8002CDB8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1D5BC 8002CDBC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1D5C0 8002CDC0 21888000 */  addu       $s1, $a0, $zero
    /* 1D5C4 8002CDC4 1800BFAF */  sw         $ra, 0x18($sp)
    /* 1D5C8 8002CDC8 03002016 */  bnez       $s1, .L8002CDD8
    /* 1D5CC 8002CDCC 1000B0AF */   sw        $s0, 0x10($sp)
    /* 1D5D0 8002CDD0 8FB30008 */  j          .L8002CE3C
    /* 1D5D4 8002CDD4 21100000 */   addu      $v0, $zero, $zero
  .L8002CDD8:
    /* 1D5D8 8002CDD8 EDB6000C */  jal        Gte_CountLeadingZeros
    /* 1D5DC 8002CDDC 21202002 */   addu      $a0, $s1, $zero
    /* 1D5E0 8002CDE0 08000324 */  addiu      $v1, $zero, 0x8
    /* 1D5E4 8002CDE4 23106200 */  subu       $v0, $v1, $v0
    /* 1D5E8 8002CDE8 04004004 */  bltz       $v0, .L8002CDFC
    /* 1D5EC 8002CDEC 43800200 */   sra       $s0, $v0, 1
    /* 1D5F0 8002CDF0 40101000 */  sll        $v0, $s0, 1
    /* 1D5F4 8002CDF4 84B30008 */  j          .L8002CE10
    /* 1D5F8 8002CDF8 07205100 */   srav      $a0, $s1, $v0
  .L8002CDFC:
    /* 1D5FC 8002CDFC 43100200 */  sra        $v0, $v0, 1
    /* 1D600 8002CE00 01005024 */  addiu      $s0, $v0, 0x1
    /* 1D604 8002CE04 40101000 */  sll        $v0, $s0, 1
    /* 1D608 8002CE08 23100200 */  negu       $v0, $v0
    /* 1D60C 8002CE0C 04205100 */  sllv       $a0, $s1, $v0
  .L8002CE10:
    /* 1D610 8002CE10 FAFF1026 */  addiu      $s0, $s0, -0x6
    /* 1D614 8002CE14 06000106 */  bgez       $s0, .L8002CE30
    /* 1D618 8002CE18 00000000 */   nop
    /* 1D61C 8002CE1C 19B3000C */  jal        func_8002CC64
    /* 1D620 8002CE20 00000000 */   nop
    /* 1D624 8002CE24 23181000 */  negu       $v1, $s0
    /* 1D628 8002CE28 8FB30008 */  j          .L8002CE3C
    /* 1D62C 8002CE2C 07106200 */   srav      $v0, $v0, $v1
  .L8002CE30:
    /* 1D630 8002CE30 19B3000C */  jal        func_8002CC64
    /* 1D634 8002CE34 00000000 */   nop
    /* 1D638 8002CE38 04100202 */  sllv       $v0, $v0, $s0
  .L8002CE3C:
    /* 1D63C 8002CE3C 1800BF8F */  lw         $ra, 0x18($sp)
    /* 1D640 8002CE40 1400B18F */  lw         $s1, 0x14($sp)
    /* 1D644 8002CE44 1000B08F */  lw         $s0, 0x10($sp)
    /* 1D648 8002CE48 0800E003 */  jr         $ra
    /* 1D64C 8002CE4C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8002CDB8
    /* 1D650 8002CE50 00000000 */  nop
