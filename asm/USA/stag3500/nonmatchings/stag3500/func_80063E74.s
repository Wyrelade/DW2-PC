nonmatching func_80063E74, 0xC4

glabel func_80063E74
    /* B14 80063E74 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* B18 80063E78 1000B0AF */  sw         $s0, 0x10($sp)
    /* B1C 80063E7C 21808000 */  addu       $s0, $a0, $zero
    /* B20 80063E80 1400BFAF */  sw         $ra, 0x14($sp)
    /* B24 80063E84 1000028E */  lw         $v0, 0x10($s0)
    /* B28 80063E88 3400058E */  lw         $a1, 0x34($s0)
    /* B2C 80063E8C 26004014 */  bnez       $v0, .L80063F28
    /* B30 80063E90 0680023C */   lui       $v0, %hi(Sys_State)
    /* B34 80063E94 70F74624 */  addiu      $a2, $v0, %lo(Sys_State)
    /* B38 80063E98 1800C38C */  lw         $v1, 0x18($a2)
    /* B3C 80063E9C 02070224 */  addiu      $v0, $zero, 0x702
    /* B40 80063EA0 1C006210 */  beq        $v1, $v0, .L80063F14
    /* B44 80063EA4 03076228 */   slti      $v0, $v1, 0x703
    /* B48 80063EA8 03004014 */  bnez       $v0, .L80063EB8
    /* B4C 80063EAC 03070224 */   addiu     $v0, $zero, 0x703
    /* B50 80063EB0 19006210 */  beq        $v1, $v0, .L80063F18
    /* B54 80063EB4 05070424 */   addiu     $a0, $zero, 0x705
  .L80063EB8:
    /* B58 80063EB8 2120C000 */  addu       $a0, $a2, $zero
    /* B5C 80063EBC 2000C38C */  lw         $v1, 0x20($a2)
    /* B60 80063EC0 03060224 */  addiu      $v0, $zero, 0x603
    /* B64 80063EC4 05006210 */  beq        $v1, $v0, .L80063EDC
    /* B68 80063EC8 04060224 */   addiu     $v0, $zero, 0x604
    /* B6C 80063ECC 09006210 */  beq        $v1, $v0, .L80063EF4
    /* B70 80063ED0 0580023C */   lui       $v0, %hi(D_80050780)
    /* B74 80063ED4 C38F0108 */  j          .L80063F0C
    /* B78 80063ED8 240080AC */   sw        $zero, 0x24($a0)
  .L80063EDC:
    /* B7C 80063EDC 0580023C */  lui        $v0, %hi(D_80050780)
    /* B80 80063EE0 80074284 */  lh         $v0, %lo(D_80050780)($v0)
    /* B84 80063EE4 00000000 */  nop
    /* B88 80063EE8 2B100200 */  sltu       $v0, $zero, $v0
    /* B8C 80063EEC C38F0108 */  j          .L80063F0C
    /* B90 80063EF0 240082AC */   sw        $v0, 0x24($a0)
  .L80063EF4:
    /* B94 80063EF4 80074284 */  lh         $v0, %lo(D_80050780)($v0)
    /* B98 80063EF8 00000000 */  nop
    /* B9C 80063EFC 02004010 */  beqz       $v0, .L80063F08
    /* BA0 80063F00 01000324 */   addiu     $v1, $zero, 0x1
    /* BA4 80063F04 02000324 */  addiu      $v1, $zero, 0x2
  .L80063F08:
    /* BA8 80063F08 2400C3AC */  sw         $v1, 0x24($a2)
  .L80063F0C:
    /* BAC 80063F0C C68F0108 */  j          .L80063F18
    /* BB0 80063F10 01070424 */   addiu     $a0, $zero, 0x701
  .L80063F14:
    /* BB4 80063F14 03070424 */  addiu      $a0, $zero, 0x703
  .L80063F18:
    /* BB8 80063F18 1F44000C */  jal        Task_Create
    /* BBC 80063F1C 21300000 */   addu      $a2, $zero, $zero
    /* BC0 80063F20 5145000C */  jal        Task_NextState0
    /* BC4 80063F24 21200002 */   addu      $a0, $s0, $zero
  .L80063F28:
    /* BC8 80063F28 1400BF8F */  lw         $ra, 0x14($sp)
    /* BCC 80063F2C 1000B08F */  lw         $s0, 0x10($sp)
    /* BD0 80063F30 0800E003 */  jr         $ra
    /* BD4 80063F34 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80063E74
