nonmatching func_8006E7F0, 0x30

glabel func_8006E7F0
    /* B490 8006E7F0 0580023C */  lui        $v0, %hi(D_80050720)
    /* B494 8006E7F4 2007438C */  lw         $v1, %lo(D_80050720)($v0)
    /* B498 8006E7F8 40100400 */  sll        $v0, $a0, 1
    /* B49C 8006E7FC 21106200 */  addu       $v0, $v1, $v0
    /* B4A0 8006E800 21186400 */  addu       $v1, $v1, $a0
    /* B4A4 8006E804 0300A010 */  beqz       $a1, .L8006E814
    /* B4A8 8006E808 2C0045A4 */   sh        $a1, 0x2C($v0)
    /* B4AC 8006E80C 0800E003 */  jr         $ra
    /* B4B0 8006E810 520066A0 */   sb        $a2, 0x52($v1)
  .L8006E814:
    /* B4B4 8006E814 01000224 */  addiu      $v0, $zero, 0x1
    /* B4B8 8006E818 0800E003 */  jr         $ra
    /* B4BC 8006E81C 520062A0 */   sb        $v0, 0x52($v1)
endlabel func_8006E7F0
