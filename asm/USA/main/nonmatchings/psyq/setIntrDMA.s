nonmatching setIntrDMA, 0xAC

glabel setIntrDMA
    /* 21F50 80031750 21308000 */  addu       $a2, $a0, $zero
    /* 21F54 80031754 0580033C */  lui        $v1, %hi(Sys_DmaCallbacks)
    /* 21F58 80031758 D4FB6324 */  addiu      $v1, $v1, %lo(Sys_DmaCallbacks)
    /* 21F5C 8003175C 80100600 */  sll        $v0, $a2, 2
    /* 21F60 80031760 21184300 */  addu       $v1, $v0, $v1
    /* 21F64 80031764 0000678C */  lw         $a3, 0x0($v1)
    /* 21F68 80031768 2120A000 */  addu       $a0, $a1, $zero
    /* 21F6C 8003176C 21008710 */  beq        $a0, $a3, .L800317F4
    /* 21F70 80031770 2110E000 */   addu      $v0, $a3, $zero
    /* 21F74 80031774 10008010 */  beqz       $a0, .L800317B8
    /* 21F78 80031778 FF00023C */   lui       $v0, (0xFFFFFF >> 16)
    /* 21F7C 8003177C 0580053C */  lui        $a1, %hi(Sys_DicrPtr)
    /* 21F80 80031780 D0FBA58C */  lw         $a1, %lo(Sys_DicrPtr)($a1)
    /* 21F84 80031784 FFFF4234 */  ori        $v0, $v0, (0xFFFFFF & 0xFFFF)
    /* 21F88 80031788 000064AC */  sw         $a0, 0x0($v1)
    /* 21F8C 8003178C 0000A48C */  lw         $a0, 0x0($a1)
    /* 21F90 80031790 1000C324 */  addiu      $v1, $a2, 0x10
    /* 21F94 80031794 24208200 */  and        $a0, $a0, $v0
    /* 21F98 80031798 01000224 */  addiu      $v0, $zero, 0x1
    /* 21F9C 8003179C 04106200 */  sllv       $v0, $v0, $v1
    /* 21FA0 800317A0 8000033C */  lui        $v1, (0x800000 >> 16)
    /* 21FA4 800317A4 25104300 */  or         $v0, $v0, $v1
    /* 21FA8 800317A8 25208200 */  or         $a0, $a0, $v0
    /* 21FAC 800317AC 0000A4AC */  sw         $a0, 0x0($a1)
    /* 21FB0 800317B0 FDC50008 */  j          .L800317F4
    /* 21FB4 800317B4 2110E000 */   addu      $v0, $a3, $zero
  .L800317B8:
    /* 21FB8 800317B8 0580053C */  lui        $a1, %hi(Sys_DicrPtr)
    /* 21FBC 800317BC D0FBA58C */  lw         $a1, %lo(Sys_DicrPtr)($a1)
    /* 21FC0 800317C0 FFFF4234 */  ori        $v0, $v0, (0xFFFFFF & 0xFFFF)
    /* 21FC4 800317C4 000060AC */  sw         $zero, 0x0($v1)
    /* 21FC8 800317C8 0000A38C */  lw         $v1, 0x0($a1)
    /* 21FCC 800317CC 1000C424 */  addiu      $a0, $a2, 0x10
    /* 21FD0 800317D0 24186200 */  and        $v1, $v1, $v0
    /* 21FD4 800317D4 8000023C */  lui        $v0, (0x800000 >> 16)
    /* 21FD8 800317D8 25186200 */  or         $v1, $v1, $v0
    /* 21FDC 800317DC 01000224 */  addiu      $v0, $zero, 0x1
    /* 21FE0 800317E0 04108200 */  sllv       $v0, $v0, $a0
    /* 21FE4 800317E4 27100200 */  nor        $v0, $zero, $v0
    /* 21FE8 800317E8 24186200 */  and        $v1, $v1, $v0
    /* 21FEC 800317EC 0000A3AC */  sw         $v1, 0x0($a1)
    /* 21FF0 800317F0 2110E000 */  addu       $v0, $a3, $zero
  .L800317F4:
    /* 21FF4 800317F4 0800E003 */  jr         $ra
    /* 21FF8 800317F8 00000000 */   nop
endlabel setIntrDMA
