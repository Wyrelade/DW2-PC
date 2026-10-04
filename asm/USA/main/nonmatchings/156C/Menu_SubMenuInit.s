nonmatching Menu_SubMenuInit, 0x34

glabel Menu_SubMenuInit
    /* 4BCC 800143CC 2C00838C */  lw         $v1, 0x2C($a0)
    /* 4BD0 800143D0 03000224 */  addiu      $v0, $zero, 0x3
    /* 4BD4 800143D4 380065A4 */  sh         $a1, 0x38($v1)
    /* 4BD8 800143D8 002C0500 */  sll        $a1, $a1, 16
    /* 4BDC 800143DC 032C0500 */  sra        $a1, $a1, 16
    /* 4BE0 800143E0 0500A214 */  bne        $a1, $v0, .L800143F8
    /* 4BE4 800143E4 00000000 */   nop
    /* 4BE8 800143E8 0580023C */  lui        $v0, %hi(Menu_Ctx)
    /* 4BEC 800143EC 6807428C */  lw         $v0, %lo(Menu_Ctx)($v0)
    /* 4BF0 800143F0 00000000 */  nop
    /* 4BF4 800143F4 5C0340A4 */  sh         $zero, 0x35C($v0)
  .L800143F8:
    /* 4BF8 800143F8 0800E003 */  jr         $ra
    /* 4BFC 800143FC 3C0060A4 */   sh        $zero, 0x3C($v1)
endlabel Menu_SubMenuInit
