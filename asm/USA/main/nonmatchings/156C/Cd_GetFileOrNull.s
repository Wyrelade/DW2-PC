nonmatching Cd_GetFileOrNull, 0x30

glabel Cd_GetFileOrNull
    /* 14208 80023A08 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1420C 80023A0C 05008010 */  beqz       $a0, .L80023A24
    /* 14210 80023A10 1000BFAF */   sw        $ra, 0x10($sp)
    /* 14214 80023A14 6C8F000C */  jal        Cd_GetFileSync
    /* 14218 80023A18 00000000 */   nop
    /* 1421C 80023A1C 8A8E0008 */  j          .L80023A28
    /* 14220 80023A20 00000000 */   nop
  .L80023A24:
    /* 14224 80023A24 21100000 */  addu       $v0, $zero, $zero
  .L80023A28:
    /* 14228 80023A28 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1422C 80023A2C 00000000 */  nop
    /* 14230 80023A30 0800E003 */  jr         $ra
    /* 14234 80023A34 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Cd_GetFileOrNull
