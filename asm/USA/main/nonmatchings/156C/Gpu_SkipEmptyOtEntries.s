nonmatching Gpu_SkipEmptyOtEntries, 0x94

glabel Gpu_SkipEmptyOtEntries
    /* D098 8001C898 00120400 */  sll        $v0, $a0, 8
    /* D09C 8001C89C 21104400 */  addu       $v0, $v0, $a0
    /* D0A0 8001C8A0 80100200 */  sll        $v0, $v0, 2
    /* D0A4 8001C8A4 23104400 */  subu       $v0, $v0, $a0
    /* D0A8 8001C8A8 00110200 */  sll        $v0, $v0, 4
    /* D0AC 8001C8AC 0680033C */  lui        $v1, %hi(Gpu_OtBufEnds)
    /* D0B0 8001C8B0 288D6324 */  addiu      $v1, $v1, %lo(Gpu_OtBufEnds)
    /* D0B4 8001C8B4 21204300 */  addu       $a0, $v0, $v1
    /* D0B8 8001C8B8 FCFF8424 */  addiu      $a0, $a0, -0x4
    /* D0BC 8001C8BC FF00063C */  lui        $a2, (0xFFFFFF >> 16)
    /* D0C0 8001C8C0 D0BF6324 */  addiu      $v1, $v1, -0x4030
    /* D0C4 8001C8C4 21384300 */  addu       $a3, $v0, $v1
    /* D0C8 8001C8C8 16008710 */  beq        $a0, $a3, .L8001C924
    /* D0CC 8001C8CC FFFFC634 */   ori       $a2, $a2, (0xFFFFFF & 0xFFFF)
  .L8001C8D0:
    /* D0D0 8001C8D0 0000838C */  lw         $v1, 0x0($a0)
    /* D0D4 8001C8D4 FCFF8524 */  addiu      $a1, $a0, -0x4
    /* D0D8 8001C8D8 2410A600 */  and        $v0, $a1, $a2
    /* D0DC 8001C8DC 24186600 */  and        $v1, $v1, $a2
    /* D0E0 8001C8E0 0D006214 */  bne        $v1, $v0, .L8001C918
    /* D0E4 8001C8E4 F8FF8224 */   addiu     $v0, $a0, -0x8
    /* D0E8 8001C8E8 FCFF838C */  lw         $v1, -0x4($a0)
    /* D0EC 8001C8EC 40720008 */  j          .L8001C900
    /* D0F0 8001C8F0 24104600 */   and       $v0, $v0, $a2
  .L8001C8F4:
    /* D0F4 8001C8F4 0000A38C */  lw         $v1, 0x0($a1)
    /* D0F8 8001C8F8 FCFFA224 */  addiu      $v0, $a1, -0x4
    /* D0FC 8001C8FC 24104600 */  and        $v0, $v0, $a2
  .L8001C900:
    /* D100 8001C900 24186600 */  and        $v1, $v1, $a2
    /* D104 8001C904 FBFF6210 */  beq        $v1, $v0, .L8001C8F4
    /* D108 8001C908 FCFFA524 */   addiu     $a1, $a1, -0x4
    /* D10C 8001C90C 0400A524 */  addiu      $a1, $a1, 0x4
    /* D110 8001C910 2410A600 */  and        $v0, $a1, $a2
    /* D114 8001C914 000082AC */  sw         $v0, 0x0($a0)
  .L8001C918:
    /* D118 8001C918 2120A000 */  addu       $a0, $a1, $zero
    /* D11C 8001C91C ECFF8714 */  bne        $a0, $a3, .L8001C8D0
    /* D120 8001C920 00000000 */   nop
  .L8001C924:
    /* D124 8001C924 0800E003 */  jr         $ra
    /* D128 8001C928 00000000 */   nop
endlabel Gpu_SkipEmptyOtEntries
