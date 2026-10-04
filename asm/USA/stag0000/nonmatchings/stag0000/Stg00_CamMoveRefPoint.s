nonmatching Stg00_CamMoveRefPoint, 0x44

glabel Stg00_CamMoveRefPoint
    /* 563C 8006899C 0E008010 */  beqz       $a0, .L800689D8
    /* 5640 800689A0 00000000 */   nop
    /* 5644 800689A4 2C00838C */  lw         $v1, 0x2C($a0)
    /* 5648 800689A8 00000000 */  nop
    /* 564C 800689AC 0C00628C */  lw         $v0, 0xC($v1)
    /* 5650 800689B0 01000424 */  addiu      $a0, $zero, 0x1
    /* 5654 800689B4 840064AC */  sw         $a0, 0x84($v1)
    /* 5658 800689B8 1400648C */  lw         $a0, 0x14($v1)
    /* 565C 800689BC 21104500 */  addu       $v0, $v0, $a1
    /* 5660 800689C0 0C0062AC */  sw         $v0, 0xC($v1)
    /* 5664 800689C4 1000628C */  lw         $v0, 0x10($v1)
    /* 5668 800689C8 21208700 */  addu       $a0, $a0, $a3
    /* 566C 800689CC 140064AC */  sw         $a0, 0x14($v1)
    /* 5670 800689D0 21104600 */  addu       $v0, $v0, $a2
    /* 5674 800689D4 100062AC */  sw         $v0, 0x10($v1)
  .L800689D8:
    /* 5678 800689D8 0800E003 */  jr         $ra
    /* 567C 800689DC 00000000 */   nop
endlabel Stg00_CamMoveRefPoint
