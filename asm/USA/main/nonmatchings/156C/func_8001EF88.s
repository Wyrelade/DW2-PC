nonmatching func_8001EF88, 0x68

glabel func_8001EF88
    /* F788 8001EF88 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* F78C 8001EF8C 1000BFAF */  sw         $ra, 0x10($sp)
    /* F790 8001EF90 507B000C */  jal        func_8001ED40
    /* F794 8001EF94 00000000 */   nop
    /* F798 8001EF98 03004290 */  lbu        $v0, 0x3($v0)
    /* F79C 8001EF9C 00000000 */  nop
    /* F7A0 8001EFA0 0F004330 */  andi       $v1, $v0, 0xF
    /* F7A4 8001EFA4 06000224 */  addiu      $v0, $zero, 0x6
    /* F7A8 8001EFA8 0D006214 */  bne        $v1, $v0, .L8001EFE0
    /* F7AC 8001EFAC 21106000 */   addu      $v0, $v1, $zero
    /* F7B0 8001EFB0 448E000C */  jal        Rand_Next
    /* F7B4 8001EFB4 00000000 */   nop
    /* F7B8 8001EFB8 FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* F7BC 8001EFBC CCCC033C */  lui        $v1, (0xCCCCCCCD >> 16)
    /* F7C0 8001EFC0 CDCC6334 */  ori        $v1, $v1, (0xCCCCCCCD & 0xFFFF)
    /* F7C4 8001EFC4 19004300 */  multu      $v0, $v1
    /* F7C8 8001EFC8 10280000 */  mfhi       $a1
    /* F7CC 8001EFCC 82200500 */  srl        $a0, $a1, 2
    /* F7D0 8001EFD0 80180400 */  sll        $v1, $a0, 2
    /* F7D4 8001EFD4 21186400 */  addu       $v1, $v1, $a0
    /* F7D8 8001EFD8 23104300 */  subu       $v0, $v0, $v1
    /* F7DC 8001EFDC FFFF4230 */  andi       $v0, $v0, 0xFFFF
  .L8001EFE0:
    /* F7E0 8001EFE0 1000BF8F */  lw         $ra, 0x10($sp)
    /* F7E4 8001EFE4 00000000 */  nop
    /* F7E8 8001EFE8 0800E003 */  jr         $ra
    /* F7EC 8001EFEC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001EF88
