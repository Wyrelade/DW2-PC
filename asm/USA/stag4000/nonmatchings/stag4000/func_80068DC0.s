nonmatching func_80068DC0, 0x160

glabel func_80068DC0
    /* 5A60 80068DC0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 5A64 80068DC4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 5A68 80068DC8 21888000 */  addu       $s1, $a0, $zero
    /* 5A6C 80068DCC 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 5A70 80068DD0 1800B2AF */  sw         $s2, 0x18($sp)
    /* 5A74 80068DD4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 5A78 80068DD8 2C00328E */  lw         $s2, 0x2C($s1)
    /* 5A7C 80068DDC 00000000 */  nop
    /* 5A80 80068DE0 2C00508E */  lw         $s0, 0x2C($s2)
    /* 5A84 80068DE4 3AB9010C */  jal        func_8006E4E8
    /* 5A88 80068DE8 29000524 */   addiu     $a1, $zero, 0x29
    /* 5A8C 80068DEC 20000386 */  lh         $v1, 0x20($s0)
    /* 5A90 80068DF0 0B000224 */  addiu      $v0, $zero, 0xB
    /* 5A94 80068DF4 03006214 */  bne        $v1, $v0, .L80068E04
    /* 5A98 80068DF8 2C000424 */   addiu     $a0, $zero, 0x2C
    /* 5A9C 80068DFC A369000C */  jal        Snd_PlayById
    /* 5AA0 80068E00 21280000 */   addu      $a1, $zero, $zero
  .L80068E04:
    /* 5AA4 80068E04 18A3010C */  jal        func_80068C60
    /* 5AA8 80068E08 21202002 */   addu      $a0, $s1, $zero
    /* 5AAC 80068E0C 3E004014 */  bnez       $v0, .L80068F08
    /* 5AB0 80068E10 00000000 */   nop
    /* 5AB4 80068E14 2C00428E */  lw         $v0, 0x2C($s2)
    /* 5AB8 80068E18 00000000 */  nop
    /* 5ABC 80068E1C 20004284 */  lh         $v0, 0x20($v0)
    /* 5AC0 80068E20 00000000 */  nop
    /* 5AC4 80068E24 02004228 */  slti       $v0, $v0, 0x2
    /* 5AC8 80068E28 37004010 */  beqz       $v0, .L80068F08
    /* 5ACC 80068E2C 0580023C */   lui       $v0, %hi(Save_GameStatePtr)
    /* 5AD0 80068E30 2007448C */  lw         $a0, %lo(Save_GameStatePtr)($v0)
    /* 5AD4 80068E34 00000000 */  nop
    /* 5AD8 80068E38 28008284 */  lh         $v0, 0x28($a0)
    /* 5ADC 80068E3C 28008394 */  lhu        $v1, 0x28($a0)
    /* 5AE0 80068E40 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 5AE4 80068E44 02004104 */  bgez       $v0, .L80068E50
    /* 5AE8 80068E48 FFFF6224 */   addiu     $v0, $v1, -0x1
    /* 5AEC 80068E4C 21100000 */  addu       $v0, $zero, $zero
  .L80068E50:
    /* 5AF0 80068E50 280082A4 */  sh         $v0, 0x28($a0)
    /* 5AF4 80068E54 95A2010C */  jal        func_80068A54
    /* 5AF8 80068E58 21202002 */   addu      $a0, $s1, $zero
    /* 5AFC 80068E5C 2A004014 */  bnez       $v0, .L80068F08
    /* 5B00 80068E60 00000000 */   nop
    /* 5B04 80068E64 BBC5010C */  jal        func_800716EC
    /* 5B08 80068E68 21202002 */   addu      $a0, $s1, $zero
    /* 5B0C 80068E6C 03004010 */  beqz       $v0, .L80068E7C
    /* 5B10 80068E70 21202002 */   addu      $a0, $s1, $zero
    /* 5B14 80068E74 C0A30108 */  j          .L80068F00
    /* 5B18 80068E78 08000524 */   addiu     $a1, $zero, 0x8
  .L80068E7C:
    /* 5B1C 80068E7C 9E87000C */  jal        Flag_Test
    /* 5B20 80068E80 68000424 */   addiu     $a0, $zero, 0x68
    /* 5B24 80068E84 09004010 */  beqz       $v0, .L80068EAC
    /* 5B28 80068E88 0580023C */   lui       $v0, %hi(Save_GameStatePtr)
    /* 5B2C 80068E8C 2007438C */  lw         $v1, %lo(Save_GameStatePtr)($v0)
    /* 5B30 80068E90 00000000 */  nop
    /* 5B34 80068E94 28006284 */  lh         $v0, 0x28($v1)
    /* 5B38 80068E98 00000000 */  nop
    /* 5B3C 80068E9C 0A004014 */  bnez       $v0, .L80068EC8
    /* 5B40 80068EA0 0580023C */   lui       $v0, %hi(Save_GameStatePtr)
    /* 5B44 80068EA4 01000224 */  addiu      $v0, $zero, 0x1
    /* 5B48 80068EA8 280062A4 */  sh         $v0, 0x28($v1)
  .L80068EAC:
    /* 5B4C 80068EAC 0580023C */  lui        $v0, %hi(Save_GameStatePtr)
    /* 5B50 80068EB0 2007428C */  lw         $v0, %lo(Save_GameStatePtr)($v0)
    /* 5B54 80068EB4 00000000 */  nop
    /* 5B58 80068EB8 28004284 */  lh         $v0, 0x28($v0)
    /* 5B5C 80068EBC 00000000 */  nop
    /* 5B60 80068EC0 07004010 */  beqz       $v0, .L80068EE0
    /* 5B64 80068EC4 0580023C */   lui       $v0, %hi(Save_GameStatePtr)
  .L80068EC8:
    /* 5B68 80068EC8 2007428C */  lw         $v0, %lo(Save_GameStatePtr)($v0)
    /* 5B6C 80068ECC 00000000 */  nop
    /* 5B70 80068ED0 24004284 */  lh         $v0, 0x24($v0)
    /* 5B74 80068ED4 00000000 */  nop
    /* 5B78 80068ED8 04004014 */  bnez       $v0, .L80068EEC
    /* 5B7C 80068EDC 00000000 */   nop
  .L80068EE0:
    /* 5B80 80068EE0 21202002 */  addu       $a0, $s1, $zero
    /* 5B84 80068EE4 C0A30108 */  j          .L80068F00
    /* 5B88 80068EE8 1C000524 */   addiu     $a1, $zero, 0x1C
  .L80068EEC:
    /* 5B8C 80068EEC E3A2010C */  jal        func_80068B8C
    /* 5B90 80068EF0 21202002 */   addu      $a0, $s1, $zero
    /* 5B94 80068EF4 04004014 */  bnez       $v0, .L80068F08
    /* 5B98 80068EF8 21202002 */   addu      $a0, $s1, $zero
    /* 5B9C 80068EFC 03000524 */  addiu      $a1, $zero, 0x3
  .L80068F00:
    /* 5BA0 80068F00 7745000C */  jal        Task_SetState1
    /* 5BA4 80068F04 00000000 */   nop
  .L80068F08:
    /* 5BA8 80068F08 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 5BAC 80068F0C 1800B28F */  lw         $s2, 0x18($sp)
    /* 5BB0 80068F10 1400B18F */  lw         $s1, 0x14($sp)
    /* 5BB4 80068F14 1000B08F */  lw         $s0, 0x10($sp)
    /* 5BB8 80068F18 0800E003 */  jr         $ra
    /* 5BBC 80068F1C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80068DC0
