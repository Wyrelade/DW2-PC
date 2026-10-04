nonmatching Stg40_SetPartBroken, 0x30

glabel Stg40_SetPartBroken
    /* B564 8006E8C4 21300000 */  addu       $a2, $zero, $zero
    /* B568 8006E8C8 0580023C */  lui        $v0, %hi(Save_GameStatePtr)
    /* B56C 8006E8CC 2007438C */  lw         $v1, %lo(Save_GameStatePtr)($v0)
    /* B570 8006E8D0 40100400 */  sll        $v0, $a0, 1
    /* B574 8006E8D4 21106200 */  addu       $v0, $v1, $v0
    /* B578 8006E8D8 2C004294 */  lhu        $v0, 0x2C($v0)
    /* B57C 8006E8DC 00000000 */  nop
    /* B580 8006E8E0 02004010 */  beqz       $v0, .L8006E8EC
    /* B584 8006E8E4 21186400 */   addu      $v1, $v1, $a0
    /* B588 8006E8E8 2130A000 */  addu       $a2, $a1, $zero
  .L8006E8EC:
    /* B58C 8006E8EC 0800E003 */  jr         $ra
    /* B590 8006E8F0 520066A0 */   sb        $a2, 0x52($v1)
endlabel Stg40_SetPartBroken
