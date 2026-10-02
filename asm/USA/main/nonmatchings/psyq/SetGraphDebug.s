nonmatching SetGraphDebug, 0x5C

glabel SetGraphDebug
    /* 17A78 80027278 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 17A7C 8002727C 0580033C */  lui        $v1, %hi(D_80048F12)
    /* 17A80 80027280 128F6324 */  addiu      $v1, $v1, %lo(D_80048F12)
    /* 17A84 80027284 1400BFAF */  sw         $ra, 0x14($sp)
    /* 17A88 80027288 1000B0AF */  sw         $s0, 0x10($sp)
    /* 17A8C 8002728C 00007090 */  lbu        $s0, 0x0($v1)
    /* 17A90 80027290 000064A0 */  sb         $a0, 0x0($v1)
    /* 17A94 80027294 FF008430 */  andi       $a0, $a0, 0xFF
    /* 17A98 80027298 0A008010 */  beqz       $a0, .L800272C4
    /* 17A9C 8002729C 21100002 */   addu      $v0, $s0, $zero
    /* 17AA0 800272A0 0580023C */  lui        $v0, %hi(D_80048F0C)
    /* 17AA4 800272A4 0C8F428C */  lw         $v0, %lo(D_80048F0C)($v0)
    /* 17AA8 800272A8 00006590 */  lbu        $a1, 0x0($v1)
    /* 17AAC 800272AC FEFF6690 */  lbu        $a2, -0x2($v1)
    /* 17AB0 800272B0 01006790 */  lbu        $a3, 0x1($v1)
    /* 17AB4 800272B4 0180043C */  lui        $a0, %hi(D_80010250)
    /* 17AB8 800272B8 09F84000 */  jalr       $v0
    /* 17ABC 800272BC 50028424 */   addiu     $a0, $a0, %lo(D_80010250)
    /* 17AC0 800272C0 21100002 */  addu       $v0, $s0, $zero
  .L800272C4:
    /* 17AC4 800272C4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 17AC8 800272C8 1000B08F */  lw         $s0, 0x10($sp)
    /* 17ACC 800272CC 0800E003 */  jr         $ra
    /* 17AD0 800272D0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel SetGraphDebug
