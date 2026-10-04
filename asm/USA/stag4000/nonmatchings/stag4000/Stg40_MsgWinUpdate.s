nonmatching Stg40_MsgWinUpdate, 0x68

glabel Stg40_MsgWinUpdate
    /* 442C 8006778C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4430 80067790 1000BFAF */  sw         $ra, 0x10($sp)
    /* 4434 80067794 1000828C */  lw         $v0, 0x10($a0)
    /* 4438 80067798 2C00868C */  lw         $a2, 0x2C($a0)
    /* 443C 8006779C 05004010 */  beqz       $v0, .L800677B4
    /* 4440 800677A0 FFFF0724 */   addiu     $a3, $zero, -0x1
    /* 4444 800677A4 03004004 */  bltz       $v0, .L800677B4
    /* 4448 800677A8 03004228 */   slti      $v0, $v0, 0x3
    /* 444C 800677AC 0D004014 */  bnez       $v0, .L800677E4
    /* 4450 800677B0 00000000 */   nop
  .L800677B4:
    /* 4454 800677B4 04000524 */  addiu      $a1, $zero, 0x4
    /* 4458 800677B8 1000C324 */  addiu      $v1, $a2, 0x10
    /* 445C 800677BC 0780023C */  lui        $v0, %hi(Stg40_MsgWinTask)
    /* 4460 800677C0 802B44AC */  sw         $a0, %lo(Stg40_MsgWinTask)($v0)
    /* 4464 800677C4 0780023C */  lui        $v0, %hi(Stg40_MsgWinTexts)
    /* 4468 800677C8 842B46AC */  sw         $a2, %lo(Stg40_MsgWinTexts)($v0)
  .L800677CC:
    /* 446C 800677CC 000067AC */  sw         $a3, 0x0($v1)
    /* 4470 800677D0 FFFFA524 */  addiu      $a1, $a1, -0x1
    /* 4474 800677D4 FDFFA104 */  bgez       $a1, .L800677CC
    /* 4478 800677D8 FCFF6324 */   addiu     $v1, $v1, -0x4
    /* 447C 800677DC 5145000C */  jal        Task_NextState0
    /* 4480 800677E0 00000000 */   nop
  .L800677E4:
    /* 4484 800677E4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 4488 800677E8 00000000 */  nop
    /* 448C 800677EC 0800E003 */  jr         $ra
    /* 4490 800677F0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg40_MsgWinUpdate
