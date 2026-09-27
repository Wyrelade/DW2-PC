nonmatching func_8001C0B0, 0x54

glabel func_8001C0B0
    /* C8B0 8001C0B0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* C8B4 8001C0B4 1400B1AF */  sw         $s1, 0x14($sp)
    /* C8B8 8001C0B8 21888000 */  addu       $s1, $a0, $zero
    /* C8BC 8001C0BC 1800B2AF */  sw         $s2, 0x18($sp)
    /* C8C0 8001C0C0 2190A000 */  addu       $s2, $a1, $zero
    /* C8C4 8001C0C4 1000B0AF */  sw         $s0, 0x10($sp)
    /* C8C8 8001C0C8 21800000 */  addu       $s0, $zero, $zero
    /* C8CC 8001C0CC 0700401A */  blez       $s2, .L8001C0EC
    /* C8D0 8001C0D0 1C00BFAF */   sw        $ra, 0x1C($sp)
  .L8001C0D4:
    /* C8D4 8001C0D4 E26E000C */  jal        Text_Close
    /* C8D8 8001C0D8 21202002 */   addu      $a0, $s1, $zero
    /* C8DC 8001C0DC 01001026 */  addiu      $s0, $s0, 0x1
    /* C8E0 8001C0E0 2A101202 */  slt        $v0, $s0, $s2
    /* C8E4 8001C0E4 FBFF4014 */  bnez       $v0, .L8001C0D4
    /* C8E8 8001C0E8 04003126 */   addiu     $s1, $s1, 0x4
  .L8001C0EC:
    /* C8EC 8001C0EC 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* C8F0 8001C0F0 1800B28F */  lw         $s2, 0x18($sp)
    /* C8F4 8001C0F4 1400B18F */  lw         $s1, 0x14($sp)
    /* C8F8 8001C0F8 1000B08F */  lw         $s0, 0x10($sp)
    /* C8FC 8001C0FC 0800E003 */  jr         $ra
    /* C900 8001C100 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8001C0B0
