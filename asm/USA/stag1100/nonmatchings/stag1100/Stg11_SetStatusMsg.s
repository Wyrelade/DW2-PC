nonmatching Stg11_SetStatusMsg, 0x78

glabel Stg11_SetStatusMsg
    /* 1584 800648E4 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 1588 800648E8 2800B0AF */  sw         $s0, 0x28($sp)
    /* 158C 800648EC 21808000 */  addu       $s0, $a0, $zero
    /* 1590 800648F0 0500A014 */  bnez       $a1, .L80064908
    /* 1594 800648F4 2C00BFAF */   sw        $ra, 0x2C($sp)
    /* 1598 800648F8 E26E000C */  jal        Text_Close
    /* 159C 800648FC 08000426 */   addiu     $a0, $s0, 0x8
    /* 15A0 80064900 53920108 */  j          .L8006494C
    /* 15A4 80064904 00000000 */   nop
  .L80064908:
    /* 15A8 80064908 FD01043C */  lui        $a0, (0x1FD0000 >> 16)
    /* 15AC 8006490C 2120A400 */  addu       $a0, $a1, $a0
    /* 15B0 80064910 0780023C */  lui        $v0, %hi(Stg11_StatusPos)
    /* 15B4 80064914 D8814824 */  addiu      $t0, $v0, %lo(Stg11_StatusPos)
    /* 15B8 80064918 03000389 */  lwl        $v1, 0x3($t0)
    /* 15BC 8006491C 00000399 */  lwr        $v1, 0x0($t0)
    /* 15C0 80064920 00000000 */  nop
    /* 15C4 80064924 1F00A3AB */  swl        $v1, 0x1F($sp)
    /* 15C8 80064928 1C00A3BB */  swr        $v1, 0x1C($sp)
    /* 15CC 8006492C 80000224 */  addiu      $v0, $zero, 0x80
    /* 15D0 80064930 2000A2A3 */  sb         $v0, 0x20($sp)
    /* 15D4 80064934 688E000C */  jal        Cd_GetFileEntry
    /* 15D8 80064938 2100A0A3 */   sb        $zero, 0x21($sp)
    /* 15DC 8006493C 08000426 */  addiu      $a0, $s0, 0x8
    /* 15E0 80064940 1000A527 */  addiu      $a1, $sp, 0x10
    /* 15E4 80064944 1C4D000C */  jal        Text_OpenDesc
    /* 15E8 80064948 1000A2AF */   sw        $v0, 0x10($sp)
  .L8006494C:
    /* 15EC 8006494C 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 15F0 80064950 2800B08F */  lw         $s0, 0x28($sp)
    /* 15F4 80064954 0800E003 */  jr         $ra
    /* 15F8 80064958 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel Stg11_SetStatusMsg
