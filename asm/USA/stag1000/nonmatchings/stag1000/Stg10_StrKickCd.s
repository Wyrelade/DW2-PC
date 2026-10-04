nonmatching Stg10_StrKickCd, 0x68

glabel Stg10_StrKickCd
    /* BD8 80063F38 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* BDC 80063F3C 1800B0AF */  sw         $s0, 0x18($sp)
    /* BE0 80063F40 21808000 */  addu       $s0, $a0, $zero
    /* BE4 80063F44 80000224 */  addiu      $v0, $zero, 0x80
    /* BE8 80063F48 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* BEC 80063F4C 1000A2A3 */  sb         $v0, 0x10($sp)
  .L80063F50:
    /* BF0 80063F50 02000424 */  addiu      $a0, $zero, 0x2
  .L80063F54:
    /* BF4 80063F54 21280002 */  addu       $a1, $s0, $zero
    /* BF8 80063F58 55C1000C */  jal        CdControl
    /* BFC 80063F5C 21300000 */   addu      $a2, $zero, $zero
    /* C00 80063F60 FCFF4010 */  beqz       $v0, .L80063F54
    /* C04 80063F64 02000424 */   addiu     $a0, $zero, 0x2
    /* C08 80063F68 0E000424 */  addiu      $a0, $zero, 0xE
  .L80063F6C:
    /* C0C 80063F6C 1000A527 */  addiu      $a1, $sp, 0x10
    /* C10 80063F70 55C1000C */  jal        CdControl
    /* C14 80063F74 21300000 */   addu      $a2, $zero, $zero
    /* C18 80063F78 FCFF4010 */  beqz       $v0, .L80063F6C
    /* C1C 80063F7C 0E000424 */   addiu     $a0, $zero, 0xE
    /* C20 80063F80 79B7000C */  jal        CdRead2
    /* C24 80063F84 E0010424 */   addiu     $a0, $zero, 0x1E0
    /* C28 80063F88 F1FF4010 */  beqz       $v0, .L80063F50
    /* C2C 80063F8C 00000000 */   nop
    /* C30 80063F90 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* C34 80063F94 1800B08F */  lw         $s0, 0x18($sp)
    /* C38 80063F98 0800E003 */  jr         $ra
    /* C3C 80063F9C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg10_StrKickCd
