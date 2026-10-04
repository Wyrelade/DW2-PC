nonmatching Stg30_TurnOrderFreeIndex, 0x40

glabel Stg30_TurnOrderFreeIndex
    /* B2D4 8006E634 21180000 */  addu       $v1, $zero, $zero
    /* B2D8 8006E638 FFFF0524 */  addiu      $a1, $zero, -0x1
    /* B2DC 8006E63C 0780023C */  lui        $v0, %hi(Stg30_TurnOrder)
    /* B2E0 8006E640 203A4424 */  addiu      $a0, $v0, %lo(Stg30_TurnOrder)
  .L8006E644:
    /* B2E4 8006E644 0000828C */  lw         $v0, 0x0($a0)
    /* B2E8 8006E648 00000000 */  nop
    /* B2EC 8006E64C 07004510 */  beq        $v0, $a1, .L8006E66C
    /* B2F0 8006E650 21106000 */   addu      $v0, $v1, $zero
    /* B2F4 8006E654 01006324 */  addiu      $v1, $v1, 0x1
    /* B2F8 8006E658 0C006228 */  slti       $v0, $v1, 0xC
    /* B2FC 8006E65C F9FF4014 */  bnez       $v0, .L8006E644
    /* B300 8006E660 04008424 */   addiu     $a0, $a0, 0x4
    /* B304 8006E664 0800E003 */  jr         $ra
    /* B308 8006E668 FFFF6224 */   addiu     $v0, $v1, -0x1
  .L8006E66C:
    /* B30C 8006E66C 0800E003 */  jr         $ra
    /* B310 8006E670 00000000 */   nop
endlabel Stg30_TurnOrderFreeIndex
