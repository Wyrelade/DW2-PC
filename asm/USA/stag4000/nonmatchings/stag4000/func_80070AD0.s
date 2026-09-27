nonmatching func_80070AD0, 0x5C

glabel func_80070AD0
    /* D770 80070AD0 0580023C */  lui        $v0, %hi(D_8005071C)
    /* D774 80070AD4 1C07428C */  lw         $v0, %lo(D_8005071C)($v0)
    /* D778 80070AD8 00000000 */  nop
    /* D77C 80070ADC FC0F4524 */  addiu      $a1, $v0, 0xFFC
    /* D780 80070AE0 FC0F4384 */  lh         $v1, 0xFFC($v0)
    /* D784 80070AE4 FEFF0224 */  addiu      $v0, $zero, -0x2
    /* D788 80070AE8 0C006210 */  beq        $v1, $v0, .L80070B1C
    /* D78C 80070AEC 00140400 */   sll       $v0, $a0, 16
    /* D790 80070AF0 031C0200 */  sra        $v1, $v0, 16
    /* D794 80070AF4 FEFF0424 */  addiu      $a0, $zero, -0x2
  .L80070AF8:
    /* D798 80070AF8 0000A284 */  lh         $v0, 0x0($a1)
    /* D79C 80070AFC 00000000 */  nop
    /* D7A0 80070B00 08004310 */  beq        $v0, $v1, .L80070B24
    /* D7A4 80070B04 2110A000 */   addu      $v0, $a1, $zero
    /* D7A8 80070B08 0200A524 */  addiu      $a1, $a1, 0x2
    /* D7AC 80070B0C 0000A284 */  lh         $v0, 0x0($a1)
    /* D7B0 80070B10 00000000 */  nop
    /* D7B4 80070B14 F8FF4414 */  bne        $v0, $a0, .L80070AF8
    /* D7B8 80070B18 00000000 */   nop
  .L80070B1C:
    /* D7BC 80070B1C 0800E003 */  jr         $ra
    /* D7C0 80070B20 21100000 */   addu      $v0, $zero, $zero
  .L80070B24:
    /* D7C4 80070B24 0800E003 */  jr         $ra
    /* D7C8 80070B28 00000000 */   nop
endlabel func_80070AD0
