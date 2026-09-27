nonmatching func_80031258, 0xA0

glabel func_80031258
    /* 21A58 80031258 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 21A5C 8003125C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 21A60 80031260 0580103C */  lui        $s0, %hi(D_8004EAF8)
    /* 21A64 80031264 F8EA1026 */  addiu      $s0, $s0, %lo(D_8004EAF8)
    /* 21A68 80031268 1400BFAF */  sw         $ra, 0x14($sp)
    /* 21A6C 8003126C 00000296 */  lhu        $v0, 0x0($s0)
    /* 21A70 80031270 00000000 */  nop
    /* 21A74 80031274 1C004010 */  beqz       $v0, .L800312E8
    /* 21A78 80031278 21100000 */   addu      $v0, $zero, $zero
    /* 21A7C 8003127C F19B000C */  jal        EnterCriticalSection
    /* 21A80 80031280 00000000 */   nop
    /* 21A84 80031284 0580023C */  lui        $v0, %hi(Sys_IntrMaskPtr)
    /* 21A88 80031288 88FB428C */  lw         $v0, %lo(Sys_IntrMaskPtr)($v0)
    /* 21A8C 8003128C 0580043C */  lui        $a0, %hi(D_8004FB8C)
    /* 21A90 80031290 8CFB848C */  lw         $a0, %lo(D_8004FB8C)($a0)
    /* 21A94 80031294 00004394 */  lhu        $v1, 0x0($v0)
    /* 21A98 80031298 00000000 */  nop
    /* 21A9C 8003129C 320003A6 */  sh         $v1, 0x32($s0)
    /* 21AA0 800312A0 0000838C */  lw         $v1, 0x0($a0)
    /* 21AA4 800312A4 0580043C */  lui        $a0, %hi(D_8004FB84)
    /* 21AA8 800312A8 84FB848C */  lw         $a0, %lo(D_8004FB84)($a0)
    /* 21AAC 800312AC 340003AE */  sw         $v1, 0x34($s0)
    /* 21AB0 800312B0 000040A4 */  sh         $zero, 0x0($v0)
    /* 21AB4 800312B4 00004294 */  lhu        $v0, 0x0($v0)
    /* 21AB8 800312B8 00000000 */  nop
    /* 21ABC 800312BC 000082A4 */  sh         $v0, 0x0($a0)
    /* 21AC0 800312C0 0580043C */  lui        $a0, %hi(D_8004FB8C)
    /* 21AC4 800312C4 8CFB848C */  lw         $a0, %lo(D_8004FB8C)($a0)
    /* 21AC8 800312C8 7777033C */  lui        $v1, (0x77777777 >> 16)
    /* 21ACC 800312CC 0000828C */  lw         $v0, 0x0($a0)
    /* 21AD0 800312D0 77776334 */  ori        $v1, $v1, (0x77777777 & 0xFFFF)
    /* 21AD4 800312D4 24104300 */  and        $v0, $v0, $v1
    /* 21AD8 800312D8 F1C4000C */  jal        ResetEntryInt
    /* 21ADC 800312DC 000082AC */   sw        $v0, 0x0($a0)
    /* 21AE0 800312E0 21100002 */  addu       $v0, $s0, $zero
    /* 21AE4 800312E4 000040A4 */  sh         $zero, 0x0($v0)
  .L800312E8:
    /* 21AE8 800312E8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 21AEC 800312EC 1000B08F */  lw         $s0, 0x10($sp)
    /* 21AF0 800312F0 0800E003 */  jr         $ra
    /* 21AF4 800312F4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80031258
