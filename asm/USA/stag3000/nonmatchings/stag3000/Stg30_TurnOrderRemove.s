nonmatching Stg30_TurnOrderRemove, 0x44

glabel Stg30_TurnOrderRemove
    /* B254 8006E5B4 0B008228 */  slti       $v0, $a0, 0xB
    /* B258 8006E5B8 0D004010 */  beqz       $v0, .L8006E5F0
    /* B25C 8006E5BC 0780023C */   lui       $v0, %hi(Stg30_TurnOrder)
    /* B260 8006E5C0 203A4524 */  addiu      $a1, $v0, %lo(Stg30_TurnOrder)
    /* B264 8006E5C4 80180400 */  sll        $v1, $a0, 2
  .L8006E5C8:
    /* B268 8006E5C8 01008224 */  addiu      $v0, $a0, 0x1
    /* B26C 8006E5CC 21204000 */  addu       $a0, $v0, $zero
    /* B270 8006E5D0 80100400 */  sll        $v0, $a0, 2
    /* B274 8006E5D4 21104500 */  addu       $v0, $v0, $a1
    /* B278 8006E5D8 0000428C */  lw         $v0, 0x0($v0)
    /* B27C 8006E5DC 21186500 */  addu       $v1, $v1, $a1
    /* B280 8006E5E0 000062AC */  sw         $v0, 0x0($v1)
    /* B284 8006E5E4 0B008228 */  slti       $v0, $a0, 0xB
    /* B288 8006E5E8 F7FF4014 */  bnez       $v0, .L8006E5C8
    /* B28C 8006E5EC 80180400 */   sll       $v1, $a0, 2
  .L8006E5F0:
    /* B290 8006E5F0 0800E003 */  jr         $ra
    /* B294 8006E5F4 00000000 */   nop
endlabel Stg30_TurnOrderRemove
