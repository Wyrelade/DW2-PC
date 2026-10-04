nonmatching Stg30_TargetNext, 0xB4

glabel Stg30_TargetNext
    /* B11C 8006E47C 0100A824 */  addiu      $t0, $a1, 0x1
    /* B120 8006E480 40100400 */  sll        $v0, $a0, 1
    /* B124 8006E484 21104400 */  addu       $v0, $v0, $a0
    /* B128 8006E488 03004324 */  addiu      $v1, $v0, 0x3
    /* B12C 8006E48C 2A100301 */  slt        $v0, $t0, $v1
    /* B130 8006E490 25004010 */  beqz       $v0, .L8006E528
    /* B134 8006E494 03000B24 */   addiu     $t3, $zero, 0x3
    /* B138 8006E498 01000A3C */  lui        $t2, (0x10000 >> 16)
    /* B13C 8006E49C 21486000 */  addu       $t1, $v1, $zero
    /* B140 8006E4A0 0780033C */  lui        $v1, %hi(Stg30_Battle)
    /* B144 8006E4A4 C03C6324 */  addiu      $v1, $v1, %lo(Stg30_Battle)
    /* B148 8006E4A8 80100800 */  sll        $v0, $t0, 2
    /* B14C 8006E4AC 21204300 */  addu       $a0, $v0, $v1
    /* B150 8006E4B0 40100800 */  sll        $v0, $t0, 1
    /* B154 8006E4B4 21104800 */  addu       $v0, $v0, $t0
    /* B158 8006E4B8 04106201 */  sllv       $v0, $v0, $t3
    /* B15C 8006E4BC 23104800 */  subu       $v0, $v0, $t0
    /* B160 8006E4C0 80100200 */  sll        $v0, $v0, 2
    /* B164 8006E4C4 21184300 */  addu       $v1, $v0, $v1
  .L8006E4C8:
    /* B168 8006E4C8 19006290 */  lbu        $v0, 0x19($v1)
    /* B16C 8006E4CC 00000000 */  nop
    /* B170 8006E4D0 10004010 */  beqz       $v0, .L8006E514
    /* B174 8006E4D4 00000000 */   nop
    /* B178 8006E4D8 0500EB10 */  beq        $a3, $t3, .L8006E4F0
    /* B17C 8006E4DC 00000000 */   nop
    /* B180 8006E4E0 2E006284 */  lh         $v0, 0x2E($v1)
    /* B184 8006E4E4 00000000 */  nop
    /* B188 8006E4E8 0A004010 */  beqz       $v0, .L8006E514
    /* B18C 8006E4EC 00000000 */   nop
  .L8006E4F0:
    /* B190 8006E4F0 0600C010 */  beqz       $a2, .L8006E50C
    /* B194 8006E4F4 00000000 */   nop
    /* B198 8006E4F8 1C03828C */  lw         $v0, 0x31C($a0)
    /* B19C 8006E4FC 00000000 */  nop
    /* B1A0 8006E500 24104A00 */  and        $v0, $v0, $t2
    /* B1A4 8006E504 04004014 */  bnez       $v0, .L8006E518
    /* B1A8 8006E508 04008424 */   addiu     $a0, $a0, 0x4
  .L8006E50C:
    /* B1AC 8006E50C 0800E003 */  jr         $ra
    /* B1B0 8006E510 21100001 */   addu      $v0, $t0, $zero
  .L8006E514:
    /* B1B4 8006E514 04008424 */  addiu      $a0, $a0, 0x4
  .L8006E518:
    /* B1B8 8006E518 01000825 */  addiu      $t0, $t0, 0x1
    /* B1BC 8006E51C 2A100901 */  slt        $v0, $t0, $t1
    /* B1C0 8006E520 E9FF4014 */  bnez       $v0, .L8006E4C8
    /* B1C4 8006E524 5C006324 */   addiu     $v1, $v1, 0x5C
  .L8006E528:
    /* B1C8 8006E528 0800E003 */  jr         $ra
    /* B1CC 8006E52C 2110A000 */   addu      $v0, $a1, $zero
endlabel Stg30_TargetNext
