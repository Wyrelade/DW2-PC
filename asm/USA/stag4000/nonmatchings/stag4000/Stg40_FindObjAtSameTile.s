nonmatching Stg40_FindObjAtSameTile, 0x74

glabel Stg40_FindObjAtSameTile
    /* 5680 800689E0 21300000 */  addu       $a2, $zero, $zero
    /* 5684 800689E4 0580023C */  lui        $v0, %hi(Dung_StatePtr)
    /* 5688 800689E8 1C07428C */  lw         $v0, %lo(Dung_StatePtr)($v0)
    /* 568C 800689EC 2138C000 */  addu       $a3, $a2, $zero
    /* 5690 800689F0 0C004384 */  lh         $v1, 0xC($v0)
    /* 5694 800689F4 00000000 */  nop
    /* 5698 800689F8 14006018 */  blez       $v1, .L80068A4C
    /* 569C 800689FC 18004524 */   addiu     $a1, $v0, 0x18
    /* 56A0 80068A00 21406000 */  addu       $t0, $v1, $zero
  .L80068A04:
    /* 56A4 80068A04 0000A28C */  lw         $v0, 0x0($a1)
    /* 56A8 80068A08 00000000 */  nop
    /* 56AC 80068A0C 00804230 */  andi       $v0, $v0, 0x8000
    /* 56B0 80068A10 0A004010 */  beqz       $v0, .L80068A3C
    /* 56B4 80068A14 00000000 */   nop
    /* 56B8 80068A18 0800A410 */  beq        $a1, $a0, .L80068A3C
    /* 56BC 80068A1C 00000000 */   nop
    /* 56C0 80068A20 1800A38C */  lw         $v1, 0x18($a1)
    /* 56C4 80068A24 1800828C */  lw         $v0, 0x18($a0)
    /* 56C8 80068A28 00000000 */  nop
    /* 56CC 80068A2C 04006214 */  bne        $v1, $v0, .L80068A40
    /* 56D0 80068A30 0100C624 */   addiu     $a2, $a2, 0x1
    /* 56D4 80068A34 93A20108 */  j          .L80068A4C
    /* 56D8 80068A38 2138A000 */   addu      $a3, $a1, $zero
  .L80068A3C:
    /* 56DC 80068A3C 0100C624 */  addiu      $a2, $a2, 0x1
  .L80068A40:
    /* 56E0 80068A40 2A10C800 */  slt        $v0, $a2, $t0
    /* 56E4 80068A44 EFFF4014 */  bnez       $v0, .L80068A04
    /* 56E8 80068A48 4800A524 */   addiu     $a1, $a1, 0x48
  .L80068A4C:
    /* 56EC 80068A4C 0800E003 */  jr         $ra
    /* 56F0 80068A50 2110E000 */   addu      $v0, $a3, $zero
endlabel Stg40_FindObjAtSameTile
