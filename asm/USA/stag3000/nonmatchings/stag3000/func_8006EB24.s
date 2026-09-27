nonmatching func_8006EB24, 0x138

glabel func_8006EB24
    /* B7C4 8006EB24 A8FFBD27 */  addiu      $sp, $sp, -0x58
    /* B7C8 8006EB28 4C00B3AF */  sw         $s3, 0x4C($sp)
    /* B7CC 8006EB2C 21988000 */  addu       $s3, $a0, $zero
    /* B7D0 8006EB30 01000524 */  addiu      $a1, $zero, 0x1
    /* B7D4 8006EB34 3000A627 */  addiu      $a2, $sp, 0x30
    /* B7D8 8006EB38 4000B0AF */  sw         $s0, 0x40($sp)
    /* B7DC 8006EB3C 21800000 */  addu       $s0, $zero, $zero
    /* B7E0 8006EB40 4800B2AF */  sw         $s2, 0x48($sp)
    /* B7E4 8006EB44 04001224 */  addiu      $s2, $zero, 0x4
    /* B7E8 8006EB48 5400BFAF */  sw         $ra, 0x54($sp)
    /* B7EC 8006EB4C 5000B4AF */  sw         $s4, 0x50($sp)
    /* B7F0 8006EB50 4400B1AF */  sw         $s1, 0x44($sp)
    /* B7F4 8006EB54 2C00718E */  lw         $s1, 0x2C($s3)
    /* B7F8 8006EB58 00000000 */  nop
    /* B7FC 8006EB5C 2C00248E */  lw         $a0, 0x2C($s1)
    /* B800 8006EB60 3400748E */  lw         $s4, 0x34($s3)
    /* B804 8006EB64 A97B000C */  jal        func_8001EEA4
    /* B808 8006EB68 3800A727 */   addiu     $a3, $sp, 0x38
  .L8006EB6C:
    /* B80C 8006EB6C 40181000 */  sll        $v1, $s0, 1
    /* B810 8006EB70 2110A303 */  addu       $v0, $sp, $v1
    /* B814 8006EB74 30004284 */  lh         $v0, 0x30($v0)
    /* B818 8006EB78 00000000 */  nop
    /* B81C 8006EB7C 2B004010 */  beqz       $v0, .L8006EC2C
    /* B820 8006EB80 00000000 */   nop
    /* B824 8006EB84 1000A2AF */  sw         $v0, 0x10($sp)
    /* B828 8006EB88 2110A303 */  addu       $v0, $sp, $v1
    /* B82C 8006EB8C 38004284 */  lh         $v0, 0x38($v0)
    /* B830 8006EB90 00000000 */  nop
    /* B834 8006EB94 1400A2AF */  sw         $v0, 0x14($sp)
    /* B838 8006EB98 1000228E */  lw         $v0, 0x10($s1)
    /* B83C 8006EB9C 00000000 */  nop
    /* B840 8006EBA0 2400A2AF */  sw         $v0, 0x24($sp)
    /* B844 8006EBA4 0400228E */  lw         $v0, 0x4($s1)
    /* B848 8006EBA8 00000000 */  nop
    /* B84C 8006EBAC 1800A2AF */  sw         $v0, 0x18($sp)
    /* B850 8006EBB0 0800228E */  lw         $v0, 0x8($s1)
    /* B854 8006EBB4 00000000 */  nop
    /* B858 8006EBB8 1C00A2AF */  sw         $v0, 0x1C($sp)
    /* B85C 8006EBBC 0C00238E */  lw         $v1, 0xC($s1)
    /* B860 8006EBC0 3C000224 */  addiu      $v0, $zero, 0x3C
    /* B864 8006EBC4 2800A2AF */  sw         $v0, 0x28($sp)
    /* B868 8006EBC8 01000224 */  addiu      $v0, $zero, 0x1
    /* B86C 8006EBCC 0C000212 */  beq        $s0, $v0, .L8006EC00
    /* B870 8006EBD0 2000A3AF */   sw        $v1, 0x20($sp)
    /* B874 8006EBD4 0200022A */  slti       $v0, $s0, 0x2
    /* B878 8006EBD8 11004010 */  beqz       $v0, .L8006EC20
    /* B87C 8006EBDC 07000424 */   addiu     $a0, $zero, 0x7
    /* B880 8006EBE0 10000016 */  bnez       $s0, .L8006EC24
    /* B884 8006EBE4 21289202 */   addu      $a1, $s4, $s2
    /* B888 8006EBE8 0C00648E */  lw         $a0, 0xC($s3)
    /* B88C 8006EBEC E779000C */  jal        func_8001E79C
    /* B890 8006EBF0 00000000 */   nop
    /* B894 8006EBF4 1C00A38F */  lw         $v1, 0x1C($sp)
    /* B898 8006EBF8 04BB0108 */  j          .L8006EC10
    /* B89C 8006EBFC 80FD6324 */   addiu     $v1, $v1, -0x280
  .L8006EC00:
    /* B8A0 8006EC00 0C00648E */  lw         $a0, 0xC($s3)
    /* B8A4 8006EC04 F079000C */  jal        func_8001E7C0
    /* B8A8 8006EC08 00000000 */   nop
    /* B8AC 8006EC0C 1C00A38F */  lw         $v1, 0x1C($sp)
  .L8006EC10:
    /* B8B0 8006EC10 00000000 */  nop
    /* B8B4 8006EC14 23186200 */  subu       $v1, $v1, $v0
    /* B8B8 8006EC18 1C00A3AF */  sw         $v1, 0x1C($sp)
    /* B8BC 8006EC1C 07000424 */  addiu      $a0, $zero, 0x7
  .L8006EC20:
    /* B8C0 8006EC20 21289202 */  addu       $a1, $s4, $s2
  .L8006EC24:
    /* B8C4 8006EC24 1F44000C */  jal        Task_Create
    /* B8C8 8006EC28 1000A627 */   addiu     $a2, $sp, 0x10
  .L8006EC2C:
    /* B8CC 8006EC2C 01001026 */  addiu      $s0, $s0, 0x1
    /* B8D0 8006EC30 0300022A */  slti       $v0, $s0, 0x3
    /* B8D4 8006EC34 CDFF4014 */  bnez       $v0, .L8006EB6C
    /* B8D8 8006EC38 04005226 */   addiu     $s2, $s2, 0x4
    /* B8DC 8006EC3C 5400BF8F */  lw         $ra, 0x54($sp)
    /* B8E0 8006EC40 5000B48F */  lw         $s4, 0x50($sp)
    /* B8E4 8006EC44 4C00B38F */  lw         $s3, 0x4C($sp)
    /* B8E8 8006EC48 4800B28F */  lw         $s2, 0x48($sp)
    /* B8EC 8006EC4C 4400B18F */  lw         $s1, 0x44($sp)
    /* B8F0 8006EC50 4000B08F */  lw         $s0, 0x40($sp)
    /* B8F4 8006EC54 0800E003 */  jr         $ra
    /* B8F8 8006EC58 5800BD27 */   addiu     $sp, $sp, 0x58
endlabel func_8006EB24
