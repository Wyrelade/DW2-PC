nonmatching StUnSetRing, 0x80

glabel StUnSetRing
    /* 1E6F4 8002DEF4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1E6F8 8002DEF8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1E6FC 8002DEFC F19B000C */  jal        EnterCriticalSection
    /* 1E700 8002DF00 00000000 */   nop
    /* 1E704 8002DF04 0580033C */  lui        $v1, %hi(D_8004E6E8)
    /* 1E708 8002DF08 E8E6638C */  lw         $v1, %lo(D_8004E6E8)($v1)
    /* 1E70C 8002DF0C 01000224 */  addiu      $v0, $zero, 0x1
    /* 1E710 8002DF10 07006214 */  bne        $v1, $v0, .L8002DF30
    /* 1E714 8002DF14 00000000 */   nop
    /* 1E718 8002DF18 A1C2000C */  jal        func_80030A84
    /* 1E71C 8002DF1C 21200000 */   addu      $a0, $zero, $zero
    /* 1E720 8002DF20 99C2000C */  jal        func_80030A64
    /* 1E724 8002DF24 21200000 */   addu      $a0, $zero, $zero
    /* 1E728 8002DF28 D0B70008 */  j          .L8002DF40
    /* 1E72C 8002DF2C 00000000 */   nop
  .L8002DF30:
    /* 1E730 8002DF30 8DC2000C */  jal        CdDataCallback
    /* 1E734 8002DF34 21200000 */   addu      $a0, $zero, $zero
    /* 1E738 8002DF38 4DC1000C */  jal        CdReadyCallback
    /* 1E73C 8002DF3C 21200000 */   addu      $a0, $zero, $zero
  .L8002DF40:
    /* 1E740 8002DF40 0580023C */  lui        $v0, %hi(D_8004E600)
    /* 1E744 8002DF44 00E6428C */  lw         $v0, %lo(D_8004E600)($v0)
    /* 1E748 8002DF48 00000000 */  nop
    /* 1E74C 8002DF4C 000040A0 */  sb         $zero, 0x0($v0)
    /* 1E750 8002DF50 0580023C */  lui        $v0, %hi(D_8004E60C)
    /* 1E754 8002DF54 0CE6428C */  lw         $v0, %lo(D_8004E60C)($v0)
    /* 1E758 8002DF58 00000000 */  nop
    /* 1E75C 8002DF5C F59B000C */  jal        ExitCriticalSection
    /* 1E760 8002DF60 000040A0 */   sb        $zero, 0x0($v0)
    /* 1E764 8002DF64 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1E768 8002DF68 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 1E76C 8002DF6C 0800E003 */  jr         $ra
    /* 1E770 8002DF70 00000000 */   nop
endlabel StUnSetRing
