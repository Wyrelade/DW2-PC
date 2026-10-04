nonmatching Stg40_SetModelTint, 0x30

glabel Stg40_SetModelTint
    /* 4534 80067894 FF00A530 */  andi       $a1, $a1, 0xFF
    /* 4538 80067898 1000A88F */  lw         $t0, 0x10($sp)
    /* 453C 8006789C 3C00838C */  lw         $v1, 0x3C($a0)
    /* 4540 800678A0 0300A014 */  bnez       $a1, .L800678B0
    /* 4544 800678A4 02000224 */   addiu     $v0, $zero, 0x2
    /* 4548 800678A8 0800E003 */  jr         $ra
    /* 454C 800678AC 340060A4 */   sh        $zero, 0x34($v1)
  .L800678B0:
    /* 4550 800678B0 340062A4 */  sh         $v0, 0x34($v1)
    /* 4554 800678B4 380066A0 */  sb         $a2, 0x38($v1)
    /* 4558 800678B8 390067A0 */  sb         $a3, 0x39($v1)
    /* 455C 800678BC 0800E003 */  jr         $ra
    /* 4560 800678C0 3A0068A0 */   sb        $t0, 0x3A($v1)
endlabel Stg40_SetModelTint
