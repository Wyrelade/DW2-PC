nonmatching Stg20_ByteListHas, 0x40

glabel Stg20_ByteListHas
    /* 8DEC 8006C14C 00008290 */  lbu        $v0, 0x0($a0)
    /* 8DF0 8006C150 00000000 */  nop
    /* 8DF4 8006C154 0B004010 */  beqz       $v0, .L8006C184
    /* 8DF8 8006C158 00000000 */   nop
  .L8006C15C:
    /* 8DFC 8006C15C 00008290 */  lbu        $v0, 0x0($a0)
    /* 8E00 8006C160 00000000 */  nop
    /* 8E04 8006C164 03004514 */  bne        $v0, $a1, .L8006C174
    /* 8E08 8006C168 01008424 */   addiu     $a0, $a0, 0x1
    /* 8E0C 8006C16C 0800E003 */  jr         $ra
    /* 8E10 8006C170 01000224 */   addiu     $v0, $zero, 0x1
  .L8006C174:
    /* 8E14 8006C174 00008290 */  lbu        $v0, 0x0($a0)
    /* 8E18 8006C178 00000000 */  nop
    /* 8E1C 8006C17C F7FF4014 */  bnez       $v0, .L8006C15C
    /* 8E20 8006C180 00000000 */   nop
  .L8006C184:
    /* 8E24 8006C184 0800E003 */  jr         $ra
    /* 8E28 8006C188 21100000 */   addu      $v0, $zero, $zero
endlabel Stg20_ByteListHas
