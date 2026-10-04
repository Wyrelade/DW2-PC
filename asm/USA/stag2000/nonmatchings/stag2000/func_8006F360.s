nonmatching func_8006F360, 0x78

glabel func_8006F360
    /* C000 8006F360 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* C004 8006F364 1000B0AF */  sw         $s0, 0x10($sp)
    /* C008 8006F368 21808000 */  addu       $s0, $a0, $zero
    /* C00C 8006F36C 280D033C */  lui        $v1, (0xD28FCD6 >> 16)
    /* C010 8006F370 0680023C */  lui        $v0, %hi(Sys_GameMode)
    /* C014 8006F374 88F7448C */  lw         $a0, %lo(Sys_GameMode)($v0)
    /* C018 8006F378 D6FC6334 */  ori        $v1, $v1, (0xD28FCD6 & 0xFFFF)
    /* C01C 8006F37C 1400BFAF */  sw         $ra, 0x14($sp)
    /* C020 8006F380 688E000C */  jal        Cd_GetFileEntry
    /* C024 8006F384 21208300 */   addu      $a0, $a0, $v1
    /* C028 8006F388 40181000 */  sll        $v1, $s0, 1
    /* C02C 8006F38C 21187000 */  addu       $v1, $v1, $s0
    /* C030 8006F390 C0180300 */  sll        $v1, $v1, 3
    /* C034 8006F394 21806200 */  addu       $s0, $v1, $v0
    /* C038 8006F398 13000292 */  lbu        $v0, 0x13($s0)
    /* C03C 8006F39C 00000000 */  nop
    /* C040 8006F3A0 09004014 */  bnez       $v0, .L8006F3C8
    /* C044 8006F3A4 21100002 */   addu      $v0, $s0, $zero
    /* C048 8006F3A8 828E000C */  jal        Cd_GetFileOrNull
    /* C04C 8006F3AC 290D0424 */   addiu     $a0, $zero, 0xD29
    /* C050 8006F3B0 0400038E */  lw         $v1, 0x4($s0)
    /* C054 8006F3B4 01000424 */  addiu      $a0, $zero, 0x1
    /* C058 8006F3B8 130004A2 */  sb         $a0, 0x13($s0)
    /* C05C 8006F3BC 21186200 */  addu       $v1, $v1, $v0
    /* C060 8006F3C0 040003AE */  sw         $v1, 0x4($s0)
    /* C064 8006F3C4 21100002 */  addu       $v0, $s0, $zero
  .L8006F3C8:
    /* C068 8006F3C8 1400BF8F */  lw         $ra, 0x14($sp)
    /* C06C 8006F3CC 1000B08F */  lw         $s0, 0x10($sp)
    /* C070 8006F3D0 0800E003 */  jr         $ra
    /* C074 8006F3D4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006F360
