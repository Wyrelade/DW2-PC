nonmatching Stg30_TargetFirst, 0xB4

glabel Stg30_TargetFirst
    /* AFBC 8006E31C 40100400 */  sll        $v0, $a0, 1
    /* AFC0 8006E320 21384400 */  addu       $a3, $v0, $a0
    /* AFC4 8006E324 0300E324 */  addiu      $v1, $a3, 0x3
    /* AFC8 8006E328 2A10E300 */  slt        $v0, $a3, $v1
    /* AFCC 8006E32C 26004010 */  beqz       $v0, .L8006E3C8
    /* AFD0 8006E330 2120E000 */   addu      $a0, $a3, $zero
    /* AFD4 8006E334 03000B24 */  addiu      $t3, $zero, 0x3
    /* AFD8 8006E338 01000A3C */  lui        $t2, (0x10000 >> 16)
    /* AFDC 8006E33C 21486000 */  addu       $t1, $v1, $zero
    /* AFE0 8006E340 0780033C */  lui        $v1, %hi(Stg30_Battle)
    /* AFE4 8006E344 C03C6324 */  addiu      $v1, $v1, %lo(Stg30_Battle)
    /* AFE8 8006E348 80100700 */  sll        $v0, $a3, 2
    /* AFEC 8006E34C 21404300 */  addu       $t0, $v0, $v1
    /* AFF0 8006E350 40100700 */  sll        $v0, $a3, 1
    /* AFF4 8006E354 21104700 */  addu       $v0, $v0, $a3
    /* AFF8 8006E358 04106201 */  sllv       $v0, $v0, $t3
    /* AFFC 8006E35C 23104700 */  subu       $v0, $v0, $a3
    /* B000 8006E360 80100200 */  sll        $v0, $v0, 2
    /* B004 8006E364 21184300 */  addu       $v1, $v0, $v1
  .L8006E368:
    /* B008 8006E368 19006290 */  lbu        $v0, 0x19($v1)
    /* B00C 8006E36C 00000000 */  nop
    /* B010 8006E370 10004010 */  beqz       $v0, .L8006E3B4
    /* B014 8006E374 00000000 */   nop
    /* B018 8006E378 0500CB10 */  beq        $a2, $t3, .L8006E390
    /* B01C 8006E37C 00000000 */   nop
    /* B020 8006E380 2E006284 */  lh         $v0, 0x2E($v1)
    /* B024 8006E384 00000000 */  nop
    /* B028 8006E388 0A004010 */  beqz       $v0, .L8006E3B4
    /* B02C 8006E38C 00000000 */   nop
  .L8006E390:
    /* B030 8006E390 0600A010 */  beqz       $a1, .L8006E3AC
    /* B034 8006E394 00000000 */   nop
    /* B038 8006E398 1C03028D */  lw         $v0, 0x31C($t0)
    /* B03C 8006E39C 00000000 */  nop
    /* B040 8006E3A0 24104A00 */  and        $v0, $v0, $t2
    /* B044 8006E3A4 04004014 */  bnez       $v0, .L8006E3B8
    /* B048 8006E3A8 04000825 */   addiu     $t0, $t0, 0x4
  .L8006E3AC:
    /* B04C 8006E3AC 0800E003 */  jr         $ra
    /* B050 8006E3B0 21108000 */   addu      $v0, $a0, $zero
  .L8006E3B4:
    /* B054 8006E3B4 04000825 */  addiu      $t0, $t0, 0x4
  .L8006E3B8:
    /* B058 8006E3B8 01008424 */  addiu      $a0, $a0, 0x1
    /* B05C 8006E3BC 2A108900 */  slt        $v0, $a0, $t1
    /* B060 8006E3C0 E9FF4014 */  bnez       $v0, .L8006E368
    /* B064 8006E3C4 5C006324 */   addiu     $v1, $v1, 0x5C
  .L8006E3C8:
    /* B068 8006E3C8 0800E003 */  jr         $ra
    /* B06C 8006E3CC 2110E000 */   addu      $v0, $a3, $zero
endlabel Stg30_TargetFirst
