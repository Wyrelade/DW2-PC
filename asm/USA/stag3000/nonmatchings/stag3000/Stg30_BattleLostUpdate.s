nonmatching Stg30_BattleLostUpdate, 0x110

glabel Stg30_BattleLostUpdate
    /* 4A54 80067DB4 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 4A58 80067DB8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 4A5C 80067DBC 21808000 */  addu       $s0, $a0, $zero
    /* 4A60 80067DC0 01000224 */  addiu      $v0, $zero, 0x1
    /* 4A64 80067DC4 1800BFAF */  sw         $ra, 0x18($sp)
    /* 4A68 80067DC8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 4A6C 80067DCC 1800038E */  lw         $v1, 0x18($s0)
    /* 4A70 80067DD0 3400118E */  lw         $s1, 0x34($s0)
    /* 4A74 80067DD4 12006210 */  beq        $v1, $v0, .L80067E20
    /* 4A78 80067DD8 02006228 */   slti      $v0, $v1, 0x2
    /* 4A7C 80067DDC 03004014 */  bnez       $v0, .L80067DEC
    /* 4A80 80067DE0 02000224 */   addiu     $v0, $zero, 0x2
    /* 4A84 80067DE4 14006210 */  beq        $v1, $v0, .L80067E38
    /* 4A88 80067DE8 00000000 */   nop
  .L80067DEC:
    /* 4A8C 80067DEC 03020424 */  addiu      $a0, $zero, 0x203
    /* 4A90 80067DF0 A369000C */  jal        Snd_PlayById
    /* 4A94 80067DF4 01000524 */   addiu     $a1, $zero, 0x1
    /* 4A98 80067DF8 539D010C */  jal        Stg30_ShowPartyFighters
    /* 4A9C 80067DFC 21200002 */   addu      $a0, $s0, $zero
    /* 4AA0 80067E00 05050424 */  addiu      $a0, $zero, 0x505
    /* 4AA4 80067E04 24002526 */  addiu      $a1, $s1, 0x24
    /* 4AA8 80067E08 1F44000C */  jal        Task_Create
    /* 4AAC 80067E0C 03000624 */   addiu     $a2, $zero, 0x3
    /* 4AB0 80067E10 45C3010C */  jal        Stg30_SetCameraShot
    /* 4AB4 80067E14 19000424 */   addiu     $a0, $zero, 0x19
    /* 4AB8 80067E18 6045000C */  jal        Task_NextState2
    /* 4ABC 80067E1C 21200002 */   addu      $a0, $s0, $zero
  .L80067E20:
    /* 4AC0 80067E20 2400228E */  lw         $v0, 0x24($s1)
    /* 4AC4 80067E24 00000000 */  nop
    /* 4AC8 80067E28 21004014 */  bnez       $v0, .L80067EB0
    /* 4ACC 80067E2C 00000000 */   nop
    /* 4AD0 80067E30 6045000C */  jal        Task_NextState2
    /* 4AD4 80067E34 21200002 */   addu      $a0, $s0, $zero
  .L80067E38:
    /* 4AD8 80067E38 1C00038E */  lw         $v1, 0x1C($s0)
    /* 4ADC 80067E3C 01000224 */  addiu      $v0, $zero, 0x1
    /* 4AE0 80067E40 09006210 */  beq        $v1, $v0, .L80067E68
    /* 4AE4 80067E44 02006228 */   slti      $v0, $v1, 0x2
    /* 4AE8 80067E48 03004014 */  bnez       $v0, .L80067E58
    /* 4AEC 80067E4C 02000224 */   addiu     $v0, $zero, 0x2
    /* 4AF0 80067E50 17006210 */  beq        $v1, $v0, .L80067EB0
    /* 4AF4 80067E54 00000000 */   nop
  .L80067E58:
    /* 4AF8 80067E58 3C71000C */  jal        Gfx_FadeOutToBlack
    /* 4AFC 80067E5C 0F000424 */   addiu     $a0, $zero, 0xF
    /* 4B00 80067E60 6645000C */  jal        Task_NextState3
    /* 4B04 80067E64 21200002 */   addu      $a0, $s0, $zero
  .L80067E68:
    /* 4B08 80067E68 0680023C */  lui        $v0, %hi(Sys_State)
    /* 4B0C 80067E6C 70F74424 */  addiu      $a0, $v0, %lo(Sys_State)
    /* 4B10 80067E70 1000838C */  lw         $v1, 0x10($a0)
    /* 4B14 80067E74 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 4B18 80067E78 0D006214 */  bne        $v1, $v0, .L80067EB0
    /* 4B1C 80067E7C 0780023C */   lui       $v0, %hi(Stg30_Battle)
    /* 4B20 80067E80 C03C428C */  lw         $v0, %lo(Stg30_Battle)($v0)
    /* 4B24 80067E84 00000000 */  nop
    /* 4B28 80067E88 05004010 */  beqz       $v0, .L80067EA0
    /* 4B2C 80067E8C 02000224 */   addiu     $v0, $zero, 0x2
    /* 4B30 80067E90 2000838C */  lw         $v1, 0x20($a0)
    /* 4B34 80067E94 240082AC */  sw         $v0, 0x24($a0)
    /* 4B38 80067E98 AA9F0108 */  j          .L80067EA8
    /* 4B3C 80067E9C 1C0083AC */   sw        $v1, 0x1C($a0)
  .L80067EA0:
    /* 4B40 80067EA0 01040224 */  addiu      $v0, $zero, 0x401
    /* 4B44 80067EA4 1C0082AC */  sw         $v0, 0x1C($a0)
  .L80067EA8:
    /* 4B48 80067EA8 6645000C */  jal        Task_NextState3
    /* 4B4C 80067EAC 21200002 */   addu      $a0, $s0, $zero
  .L80067EB0:
    /* 4B50 80067EB0 1800BF8F */  lw         $ra, 0x18($sp)
    /* 4B54 80067EB4 1400B18F */  lw         $s1, 0x14($sp)
    /* 4B58 80067EB8 1000B08F */  lw         $s0, 0x10($sp)
    /* 4B5C 80067EBC 0800E003 */  jr         $ra
    /* 4B60 80067EC0 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg30_BattleLostUpdate
