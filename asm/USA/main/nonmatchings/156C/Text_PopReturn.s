nonmatching Text_PopReturn, 0x38

glabel Text_PopReturn
    /* B120 8001A920 0580033C */  lui        $v1, %hi(Text_ReturnStack)
    /* B124 8001A924 D04C628C */  lw         $v0, %lo(Text_ReturnStack)($v1)
    /* B128 8001A928 00000000 */  nop
    /* B12C 8001A92C 08004010 */  beqz       $v0, .L8001A950
    /* B130 8001A930 D04C6424 */   addiu     $a0, $v1, %lo(Text_ReturnStack)
    /* B134 8001A934 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* B138 8001A938 D04C62AC */  sw         $v0, %lo(Text_ReturnStack)($v1)
    /* B13C 8001A93C 80100200 */  sll        $v0, $v0, 2
    /* B140 8001A940 21104400 */  addu       $v0, $v0, $a0
    /* B144 8001A944 0400428C */  lw         $v0, 0x4($v0)
    /* B148 8001A948 0800E003 */  jr         $ra
    /* B14C 8001A94C 00000000 */   nop
  .L8001A950:
    /* B150 8001A950 0800E003 */  jr         $ra
    /* B154 8001A954 21100000 */   addu      $v0, $zero, $zero
endlabel Text_PopReturn
