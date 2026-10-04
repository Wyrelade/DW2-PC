nonmatching Stg20_PartsListRemove, 0x38

glabel Stg20_PartsListRemove
    /* A15C 8006D4BC 21300000 */  addu       $a2, $zero, $zero
    /* A160 8006D4C0 2C00838C */  lw         $v1, 0x2C($a0)
  .L8006D4C4:
    /* A164 8006D4C4 00000000 */  nop
    /* A168 8006D4C8 60006284 */  lh         $v0, 0x60($v1)
    /* A16C 8006D4CC 00000000 */  nop
    /* A170 8006D4D0 03004514 */  bne        $v0, $a1, .L8006D4E0
    /* A174 8006D4D4 0100C624 */   addiu     $a2, $a2, 0x1
    /* A178 8006D4D8 0800E003 */  jr         $ra
    /* A17C 8006D4DC 600060A4 */   sh        $zero, 0x60($v1)
  .L8006D4E0:
    /* A180 8006D4E0 4300C228 */  slti       $v0, $a2, 0x43
    /* A184 8006D4E4 F7FF4014 */  bnez       $v0, .L8006D4C4
    /* A188 8006D4E8 02006324 */   addiu     $v1, $v1, 0x2
    /* A18C 8006D4EC 0800E003 */  jr         $ra
    /* A190 8006D4F0 00000000 */   nop
endlabel Stg20_PartsListRemove
