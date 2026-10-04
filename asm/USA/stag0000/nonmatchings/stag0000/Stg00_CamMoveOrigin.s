nonmatching Stg00_CamMoveOrigin, 0x44

glabel Stg00_CamMoveOrigin
    /* 56A0 80068A00 0E008010 */  beqz       $a0, .L80068A3C
    /* 56A4 80068A04 00000000 */   nop
    /* 56A8 80068A08 2C00838C */  lw         $v1, 0x2C($a0)
    /* 56AC 80068A0C 00000000 */  nop
    /* 56B0 80068A10 6C00628C */  lw         $v0, 0x6C($v1)
    /* 56B4 80068A14 01000424 */  addiu      $a0, $zero, 0x1
    /* 56B8 80068A18 840064AC */  sw         $a0, 0x84($v1)
    /* 56BC 80068A1C 7400648C */  lw         $a0, 0x74($v1)
    /* 56C0 80068A20 21104500 */  addu       $v0, $v0, $a1
    /* 56C4 80068A24 6C0062AC */  sw         $v0, 0x6C($v1)
    /* 56C8 80068A28 7000628C */  lw         $v0, 0x70($v1)
    /* 56CC 80068A2C 21208700 */  addu       $a0, $a0, $a3
    /* 56D0 80068A30 740064AC */  sw         $a0, 0x74($v1)
    /* 56D4 80068A34 21104600 */  addu       $v0, $v0, $a2
    /* 56D8 80068A38 700062AC */  sw         $v0, 0x70($v1)
  .L80068A3C:
    /* 56DC 80068A3C 0800E003 */  jr         $ra
    /* 56E0 80068A40 00000000 */   nop
endlabel Stg00_CamMoveOrigin
