nonmatching Stg40_PlayerSporeDamage, 0x14C

glabel Stg40_PlayerSporeDamage
    /* 64D0 80069830 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 64D4 80069834 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 64D8 80069838 0780133C */  lui        $s3, %hi(Stg40_RootState)
    /* 64DC 8006983C 602B628E */  lw         $v0, %lo(Stg40_RootState)($s3)
    /* 64E0 80069840 1400B1AF */  sw         $s1, 0x14($sp)
    /* 64E4 80069844 21888000 */  addu       $s1, $a0, $zero
    /* 64E8 80069848 1000B0AF */  sw         $s0, 0x10($sp)
    /* 64EC 8006984C 01001024 */  addiu      $s0, $zero, 0x1
    /* 64F0 80069850 2400BFAF */  sw         $ra, 0x24($sp)
    /* 64F4 80069854 2000B4AF */  sw         $s4, 0x20($sp)
    /* 64F8 80069858 1800B2AF */  sw         $s2, 0x18($sp)
    /* 64FC 8006985C 1800238E */  lw         $v1, 0x18($s1)
    /* 6500 80069860 4000548C */  lw         $s4, 0x40($v0)
    /* 6504 80069864 3C00528C */  lw         $s2, 0x3C($v0)
    /* 6508 80069868 1F007010 */  beq        $v1, $s0, .L800698E8
    /* 650C 8006986C 02006228 */   slti      $v0, $v1, 0x2
    /* 6510 80069870 03004014 */  bnez       $v0, .L80069880
    /* 6514 80069874 02000224 */   addiu     $v0, $zero, 0x2
    /* 6518 80069878 32006210 */  beq        $v1, $v0, .L80069944
    /* 651C 8006987C 00000000 */   nop
  .L80069880:
    /* 6520 80069880 21202002 */  addu       $a0, $s1, $zero
    /* 6524 80069884 37B9010C */  jal        Stg40_ObjSetAnim
    /* 6528 80069888 2C000524 */   addiu     $a1, $zero, 0x2C
    /* 652C 8006988C 21202002 */  addu       $a0, $s1, $zero
    /* 6530 80069890 209E010C */  jal        Stg40_ObjStartFlash
    /* 6534 80069894 02000524 */   addiu     $a1, $zero, 0x2
    /* 6538 80069898 21204002 */  addu       $a0, $s2, $zero
    /* 653C 8006989C 7745000C */  jal        Task_SetState1
    /* 6540 800698A0 04000524 */   addiu     $a1, $zero, 0x4
    /* 6544 800698A4 1000828E */  lw         $v0, 0x10($s4)
    /* 6548 800698A8 00000000 */  nop
    /* 654C 800698AC 01004290 */  lbu        $v0, 0x1($v0)
    /* 6550 800698B0 00000000 */  nop
    /* 6554 800698B4 40200200 */  sll        $a0, $v0, 1
    /* 6558 800698B8 21208200 */  addu       $a0, $a0, $v0
    /* 655C 800698BC C0200400 */  sll        $a0, $a0, 3
    /* 6560 800698C0 21208200 */  addu       $a0, $a0, $v0
    /* 6564 800698C4 602B628E */  lw         $v0, %lo(Stg40_RootState)($s3)
    /* 6568 800698C8 C0200400 */  sll        $a0, $a0, 3
    /* 656C 800698CC 3DBA010C */  jal        Stg40_DamageBeetle
    /* 6570 800698D0 580044AC */   sw        $a0, 0x58($v0)
    /* 6574 800698D4 33000424 */  addiu      $a0, $zero, 0x33
    /* 6578 800698D8 A369000C */  jal        Snd_PlayById
    /* 657C 800698DC 21280000 */   addu      $a1, $zero, $zero
    /* 6580 800698E0 4DA60108 */  j          .L80069934
    /* 6584 800698E4 00000000 */   nop
  .L800698E8:
    /* 6588 800698E8 62B9010C */  jal        Stg40_ObjWaitAnimOrSkip
    /* 658C 800698EC 21202002 */   addu      $a0, $s1, $zero
    /* 6590 800698F0 1A005014 */  bne        $v0, $s0, .L8006995C
    /* 6594 800698F4 21202002 */   addu      $a0, $s1, $zero
    /* 6598 800698F8 37B9010C */  jal        Stg40_ObjSetAnim
    /* 659C 800698FC 28000524 */   addiu     $a1, $zero, 0x28
    /* 65A0 80069900 602B628E */  lw         $v0, %lo(Stg40_RootState)($s3)
    /* 65A4 80069904 00000000 */  nop
    /* 65A8 80069908 5800458C */  lw         $a1, 0x58($v0)
    /* 65AC 8006990C 579D010C */  jal        Stg40_NumToDigits
    /* 65B0 80069910 21200000 */   addu      $a0, $zero, $zero
    /* 65B4 80069914 01000424 */  addiu      $a0, $zero, 0x1
    /* 65B8 80069918 FD01053C */  lui        $a1, (0x1FD001F >> 16)
    /* 65BC 8006991C 0580033C */  lui        $v1, %hi(Save_GameStatePtr)
    /* 65C0 80069920 1F00A534 */  ori        $a1, $a1, (0x1FD001F & 0xFFFF)
    /* 65C4 80069924 2007668C */  lw         $a2, %lo(Save_GameStatePtr)($v1)
    /* 65C8 80069928 21384000 */  addu       $a3, $v0, $zero
    /* 65CC 8006992C 849D010C */  jal        Stg40_MsgWinOpen
    /* 65D0 80069930 D100C624 */   addiu     $a2, $a2, 0xD1
  .L80069934:
    /* 65D4 80069934 6045000C */  jal        Task_NextState2
    /* 65D8 80069938 21202002 */   addu      $a0, $s1, $zero
    /* 65DC 8006993C 57A60108 */  j          .L8006995C
    /* 65E0 80069940 00000000 */   nop
  .L80069944:
    /* 65E4 80069944 C19D010C */  jal        Stg40_MsgWinCloseIfDone
    /* 65E8 80069948 01000424 */   addiu     $a0, $zero, 0x1
    /* 65EC 8006994C 03005014 */  bne        $v0, $s0, .L8006995C
    /* 65F0 80069950 21202002 */   addu      $a0, $s1, $zero
    /* 65F4 80069954 7745000C */  jal        Task_SetState1
    /* 65F8 80069958 06000524 */   addiu     $a1, $zero, 0x6
  .L8006995C:
    /* 65FC 8006995C 2400BF8F */  lw         $ra, 0x24($sp)
    /* 6600 80069960 2000B48F */  lw         $s4, 0x20($sp)
    /* 6604 80069964 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 6608 80069968 1800B28F */  lw         $s2, 0x18($sp)
    /* 660C 8006996C 1400B18F */  lw         $s1, 0x14($sp)
    /* 6610 80069970 1000B08F */  lw         $s0, 0x10($sp)
    /* 6614 80069974 0800E003 */  jr         $ra
    /* 6618 80069978 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel Stg40_PlayerSporeDamage
