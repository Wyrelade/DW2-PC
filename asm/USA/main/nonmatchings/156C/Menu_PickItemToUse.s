nonmatching Menu_PickItemToUse, 0x138

glabel Menu_PickItemToUse
    /* 6EFC 800166FC C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 6F00 80016700 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* 6F04 80016704 21A88000 */  addu       $s5, $a0, $zero
    /* 6F08 80016708 2800B4AF */  sw         $s4, 0x28($sp)
    /* 6F0C 8001670C 21A0A000 */  addu       $s4, $a1, $zero
    /* 6F10 80016710 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 6F14 80016714 54009126 */  addiu      $s1, $s4, 0x54
    /* 6F18 80016718 21202002 */  addu       $a0, $s1, $zero
    /* 6F1C 8001671C 2000B2AF */  sw         $s2, 0x20($sp)
    /* 6F20 80016720 58009226 */  addiu      $s2, $s4, 0x58
    /* 6F24 80016724 21284002 */  addu       $a1, $s2, $zero
    /* 6F28 80016728 3000BFAF */  sw         $ra, 0x30($sp)
    /* 6F2C 8001672C 2400B3AF */  sw         $s3, 0x24($sp)
    /* 6F30 80016730 9C4E000C */  jal        Menu_GridIndexColMajor
    /* 6F34 80016734 1800B0AF */   sw        $s0, 0x18($sp)
    /* 6F38 80016738 40180200 */  sll        $v1, $v0, 1
    /* 6F3C 8001673C 21186200 */  addu       $v1, $v1, $v0
    /* 6F40 80016740 40180300 */  sll        $v1, $v1, 1
    /* 6F44 80016744 21188302 */  addu       $v1, $s4, $v1
    /* 6F48 80016748 72007094 */  lhu        $s0, 0x72($v1)
    /* 6F4C 8001674C 00000000 */  nop
    /* 6F50 80016750 16000012 */  beqz       $s0, .L800167AC
    /* 6F54 80016754 10000424 */   addiu     $a0, $zero, 0x10
    /* 6F58 80016758 F947000C */  jal        Item_GetUseKind
    /* 6F5C 8001675C 21200002 */   addu      $a0, $s0, $zero
    /* 6F60 80016760 21984000 */  addu       $s3, $v0, $zero
    /* 6F64 80016764 15006016 */  bnez       $s3, .L800167BC
    /* 6F68 80016768 21202002 */   addu      $a0, $s1, $zero
    /* 6F6C 8001676C FD01043C */  lui        $a0, (0x1FD00A1 >> 16)
    /* 6F70 80016770 A1008434 */  ori        $a0, $a0, (0x1FD00A1 & 0xFFFF)
    /* 6F74 80016774 10000224 */  addiu      $v0, $zero, 0x10
    /* 6F78 80016778 1000A2A7 */  sh         $v0, 0x10($sp)
    /* 6F7C 8001677C BA000224 */  addiu      $v0, $zero, 0xBA
    /* 6F80 80016780 688E000C */  jal        Cd_GetFileEntry
    /* 6F84 80016784 1200A2A7 */   sh        $v0, 0x12($sp)
    /* 6F88 80016788 44008426 */  addiu      $a0, $s4, 0x44
    /* 6F8C 8001678C 21284000 */  addu       $a1, $v0, $zero
    /* 6F90 80016790 81000624 */  addiu      $a2, $zero, 0x81
    /* 6F94 80016794 1200A797 */  lhu        $a3, 0x12($sp)
    /* 6F98 80016798 1000A297 */  lhu        $v0, 0x10($sp)
    /* 6F9C 8001679C 003C0700 */  sll        $a3, $a3, 16
    /* 6FA0 800167A0 3E4D000C */  jal        Text_OpenPacked
    /* 6FA4 800167A4 25384700 */   or        $a3, $v0, $a3
    /* 6FA8 800167A8 10000424 */  addiu      $a0, $zero, 0x10
  .L800167AC:
    /* 6FAC 800167AC A369000C */  jal        Snd_PlayById
    /* 6FB0 800167B0 21280000 */   addu      $a1, $zero, $zero
    /* 6FB4 800167B4 045A0008 */  j          .L80016810
    /* 6FB8 800167B8 00000000 */   nop
  .L800167BC:
    /* 6FBC 800167BC 0580023C */  lui        $v0, %hi(Menu_Ctx)
    /* 6FC0 800167C0 6807428C */  lw         $v0, %lo(Menu_Ctx)($v0)
    /* 6FC4 800167C4 21284002 */  addu       $a1, $s2, $zero
    /* 6FC8 800167C8 9C4E000C */  jal        Menu_GridIndexColMajor
    /* 6FCC 800167CC 080150A4 */   sh        $s0, 0x108($v0)
    /* 6FD0 800167D0 0E000424 */  addiu      $a0, $zero, 0xE
    /* 6FD4 800167D4 40180200 */  sll        $v1, $v0, 1
    /* 6FD8 800167D8 21186200 */  addu       $v1, $v1, $v0
    /* 6FDC 800167DC 40180300 */  sll        $v1, $v1, 1
    /* 6FE0 800167E0 21188302 */  addu       $v1, $s4, $v1
    /* 6FE4 800167E4 0580063C */  lui        $a2, %hi(Menu_Ctx)
    /* 6FE8 800167E8 6807C68C */  lw         $a2, %lo(Menu_Ctx)($a2)
    /* 6FEC 800167EC 76006294 */  lhu        $v0, 0x76($v1)
    /* 6FF0 800167F0 21280000 */  addu       $a1, $zero, $zero
    /* 6FF4 800167F4 0A01C2A4 */  sh         $v0, 0x10A($a2)
    /* 6FF8 800167F8 0100623A */  xori       $v0, $s3, 0x1
    /* 6FFC 800167FC 0100422C */  sltiu      $v0, $v0, 0x1
    /* 7000 80016800 A369000C */  jal        Snd_PlayById
    /* 7004 80016804 660082A6 */   sh        $v0, 0x66($s4)
    /* 7008 80016808 5945000C */  jal        Task_NextState1
    /* 700C 8001680C 2120A002 */   addu      $a0, $s5, $zero
  .L80016810:
    /* 7010 80016810 3000BF8F */  lw         $ra, 0x30($sp)
    /* 7014 80016814 2C00B58F */  lw         $s5, 0x2C($sp)
    /* 7018 80016818 2800B48F */  lw         $s4, 0x28($sp)
    /* 701C 8001681C 2400B38F */  lw         $s3, 0x24($sp)
    /* 7020 80016820 2000B28F */  lw         $s2, 0x20($sp)
    /* 7024 80016824 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 7028 80016828 1800B08F */  lw         $s0, 0x18($sp)
    /* 702C 8001682C 0800E003 */  jr         $ra
    /* 7030 80016830 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel Menu_PickItemToUse
