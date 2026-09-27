nonmatching Flag_NextPassingEntry, 0xF0

glabel Flag_NextPassingEntry
    /* EB90 8001E390 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* EB94 8001E394 0680023C */  lui        $v0, %hi(D_8005D560)
    /* EB98 8001E398 60D54324 */  addiu      $v1, $v0, %lo(D_8005D560)
    /* EB9C 8001E39C 1400BFAF */  sw         $ra, 0x14($sp)
    /* EBA0 8001E3A0 1000B0AF */  sw         $s0, 0x10($sp)
    /* EBA4 8001E3A4 0C00628C */  lw         $v0, 0xC($v1)
    /* EBA8 8001E3A8 00000000 */  nop
    /* EBAC 8001E3AC 00004284 */  lh         $v0, 0x0($v0)
    /* EBB0 8001E3B0 00000000 */  nop
    /* EBB4 8001E3B4 2D004010 */  beqz       $v0, .L8001E46C
    /* EBB8 8001E3B8 21806000 */   addu      $s0, $v1, $zero
  .L8001E3BC:
    /* EBBC 8001E3BC 0C00048E */  lw         $a0, 0xC($s0)
    /* EBC0 8001E3C0 A678000C */  jal        func_8001E298
    /* EBC4 8001E3C4 00000000 */   nop
    /* EBC8 8001E3C8 0E88000C */  jal        Flag_TestConds
    /* EBCC 8001E3CC 21204000 */   addu      $a0, $v0, $zero
    /* EBD0 8001E3D0 1C004010 */  beqz       $v0, .L8001E444
    /* EBD4 8001E3D4 10000326 */   addiu     $v1, $s0, 0x10
    /* EBD8 8001E3D8 0C00028E */  lw         $v0, 0xC($s0)
    /* EBDC 8001E3DC 00000000 */  nop
    /* EBE0 8001E3E0 20004424 */  addiu      $a0, $v0, 0x20
  .L8001E3E4:
    /* EBE4 8001E3E4 0000458C */  lw         $a1, 0x0($v0)
    /* EBE8 8001E3E8 0400468C */  lw         $a2, 0x4($v0)
    /* EBEC 8001E3EC 0800478C */  lw         $a3, 0x8($v0)
    /* EBF0 8001E3F0 0C00488C */  lw         $t0, 0xC($v0)
    /* EBF4 8001E3F4 000065AC */  sw         $a1, 0x0($v1)
    /* EBF8 8001E3F8 040066AC */  sw         $a2, 0x4($v1)
    /* EBFC 8001E3FC 080067AC */  sw         $a3, 0x8($v1)
    /* EC00 8001E400 0C0068AC */  sw         $t0, 0xC($v1)
    /* EC04 8001E404 10004224 */  addiu      $v0, $v0, 0x10
    /* EC08 8001E408 F6FF4414 */  bne        $v0, $a0, .L8001E3E4
    /* EC0C 8001E40C 10006324 */   addiu     $v1, $v1, 0x10
    /* EC10 8001E410 0000458C */  lw         $a1, 0x0($v0)
    /* EC14 8001E414 0400468C */  lw         $a2, 0x4($v0)
    /* EC18 8001E418 0800478C */  lw         $a3, 0x8($v0)
    /* EC1C 8001E41C 000065AC */  sw         $a1, 0x0($v1)
    /* EC20 8001E420 040066AC */  sw         $a2, 0x4($v1)
    /* EC24 8001E424 080067AC */  sw         $a3, 0x8($v1)
    /* EC28 8001E428 0C00038E */  lw         $v1, 0xC($s0)
    /* EC2C 8001E42C 0800028E */  lw         $v0, 0x8($s0)
    /* EC30 8001E430 2C006324 */  addiu      $v1, $v1, 0x2C
    /* EC34 8001E434 0C0003AE */  sw         $v1, 0xC($s0)
    /* EC38 8001E438 01004324 */  addiu      $v1, $v0, 0x1
    /* EC3C 8001E43C 1C790008 */  j          .L8001E470
    /* EC40 8001E440 080003AE */   sw        $v1, 0x8($s0)
  .L8001E444:
    /* EC44 8001E444 0C00048E */  lw         $a0, 0xC($s0)
    /* EC48 8001E448 0800038E */  lw         $v1, 0x8($s0)
    /* EC4C 8001E44C 2C008224 */  addiu      $v0, $a0, 0x2C
    /* EC50 8001E450 01006324 */  addiu      $v1, $v1, 0x1
    /* EC54 8001E454 0C0002AE */  sw         $v0, 0xC($s0)
    /* EC58 8001E458 080003AE */  sw         $v1, 0x8($s0)
    /* EC5C 8001E45C 2C008284 */  lh         $v0, 0x2C($a0)
    /* EC60 8001E460 00000000 */  nop
    /* EC64 8001E464 D5FF4014 */  bnez       $v0, .L8001E3BC
    /* EC68 8001E468 00000000 */   nop
  .L8001E46C:
    /* EC6C 8001E46C FFFF0224 */  addiu      $v0, $zero, -0x1
  .L8001E470:
    /* EC70 8001E470 1400BF8F */  lw         $ra, 0x14($sp)
    /* EC74 8001E474 1000B08F */  lw         $s0, 0x10($sp)
    /* EC78 8001E478 0800E003 */  jr         $ra
    /* EC7C 8001E47C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Flag_NextPassingEntry
