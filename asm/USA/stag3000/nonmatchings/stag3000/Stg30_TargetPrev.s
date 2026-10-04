nonmatching Stg30_TargetPrev, 0xAC

glabel Stg30_TargetPrev
    /* B070 8006E3D0 FFFFA824 */  addiu      $t0, $a1, -0x1
    /* B074 8006E3D4 40100400 */  sll        $v0, $a0, 1
    /* B078 8006E3D8 21484400 */  addu       $t1, $v0, $a0
    /* B07C 8006E3DC 2A100901 */  slt        $v0, $t0, $t1
    /* B080 8006E3E0 24004014 */  bnez       $v0, .L8006E474
    /* B084 8006E3E4 03000B24 */   addiu     $t3, $zero, 0x3
    /* B088 8006E3E8 01000A3C */  lui        $t2, (0x10000 >> 16)
    /* B08C 8006E3EC 0780033C */  lui        $v1, %hi(Stg30_Battle)
    /* B090 8006E3F0 C03C6324 */  addiu      $v1, $v1, %lo(Stg30_Battle)
    /* B094 8006E3F4 80100800 */  sll        $v0, $t0, 2
    /* B098 8006E3F8 21204300 */  addu       $a0, $v0, $v1
    /* B09C 8006E3FC 40100800 */  sll        $v0, $t0, 1
    /* B0A0 8006E400 21104800 */  addu       $v0, $v0, $t0
    /* B0A4 8006E404 04106201 */  sllv       $v0, $v0, $t3
    /* B0A8 8006E408 23104800 */  subu       $v0, $v0, $t0
    /* B0AC 8006E40C 80100200 */  sll        $v0, $v0, 2
    /* B0B0 8006E410 21184300 */  addu       $v1, $v0, $v1
  .L8006E414:
    /* B0B4 8006E414 19006290 */  lbu        $v0, 0x19($v1)
    /* B0B8 8006E418 00000000 */  nop
    /* B0BC 8006E41C 10004010 */  beqz       $v0, .L8006E460
    /* B0C0 8006E420 00000000 */   nop
    /* B0C4 8006E424 0500EB10 */  beq        $a3, $t3, .L8006E43C
    /* B0C8 8006E428 00000000 */   nop
    /* B0CC 8006E42C 2E006284 */  lh         $v0, 0x2E($v1)
    /* B0D0 8006E430 00000000 */  nop
    /* B0D4 8006E434 0A004010 */  beqz       $v0, .L8006E460
    /* B0D8 8006E438 00000000 */   nop
  .L8006E43C:
    /* B0DC 8006E43C 0600C010 */  beqz       $a2, .L8006E458
    /* B0E0 8006E440 00000000 */   nop
    /* B0E4 8006E444 1C03828C */  lw         $v0, 0x31C($a0)
    /* B0E8 8006E448 00000000 */  nop
    /* B0EC 8006E44C 24104A00 */  and        $v0, $v0, $t2
    /* B0F0 8006E450 04004014 */  bnez       $v0, .L8006E464
    /* B0F4 8006E454 FCFF8424 */   addiu     $a0, $a0, -0x4
  .L8006E458:
    /* B0F8 8006E458 0800E003 */  jr         $ra
    /* B0FC 8006E45C 21100001 */   addu      $v0, $t0, $zero
  .L8006E460:
    /* B100 8006E460 FCFF8424 */  addiu      $a0, $a0, -0x4
  .L8006E464:
    /* B104 8006E464 FFFF0825 */  addiu      $t0, $t0, -0x1
    /* B108 8006E468 2A100901 */  slt        $v0, $t0, $t1
    /* B10C 8006E46C E9FF4010 */  beqz       $v0, .L8006E414
    /* B110 8006E470 A4FF6324 */   addiu     $v1, $v1, -0x5C
  .L8006E474:
    /* B114 8006E474 0800E003 */  jr         $ra
    /* B118 8006E478 2110A000 */   addu      $v0, $a1, $zero
endlabel Stg30_TargetPrev
