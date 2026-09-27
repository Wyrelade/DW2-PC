nonmatching func_80066C00, 0x2BC

glabel func_80066C00
    /* 38A0 80066C00 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 38A4 80066C04 1000B0AF */  sw         $s0, 0x10($sp)
    /* 38A8 80066C08 21808000 */  addu       $s0, $a0, $zero
    /* 38AC 80066C0C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 38B0 80066C10 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 38B4 80066C14 1400B1AF */  sw         $s1, 0x14($sp)
    /* 38B8 80066C18 1C00028E */  lw         $v0, 0x1C($s0)
    /* 38BC 80066C1C 3800118E */  lw         $s1, 0x38($s0)
    /* 38C0 80066C20 09004014 */  bnez       $v0, .L80066C48
    /* 38C4 80066C24 2190A000 */   addu      $s2, $a1, $zero
    /* 38C8 80066C28 2000028E */  lw         $v0, 0x20($s0)
    /* 38CC 80066C2C 00000000 */  nop
    /* 38D0 80066C30 05004014 */  bnez       $v0, .L80066C48
    /* 38D4 80066C34 00000000 */   nop
    /* 38D8 80066C38 BA83000C */  jal        Actor_StopAxisMotion
    /* 38DC 80066C3C 01000524 */   addiu     $a1, $zero, 0x1
    /* 38E0 80066C40 189B0108 */  j          .L80066C60
    /* 38E4 80066C44 00000000 */   nop
  .L80066C48:
    /* 38E8 80066C48 21200002 */  addu       $a0, $s0, $zero
    /* 38EC 80066C4C 5583000C */  jal        func_80020D54
    /* 38F0 80066C50 01000524 */   addiu     $a1, $zero, 0x1
    /* 38F4 80066C54 21200002 */  addu       $a0, $s0, $zero
    /* 38F8 80066C58 8083000C */  jal        func_80020E00
    /* 38FC 80066C5C 02000524 */   addiu     $a1, $zero, 0x2
  .L80066C60:
    /* 3900 80066C60 1C00038E */  lw         $v1, 0x1C($s0)
    /* 3904 80066C64 00000000 */  nop
    /* 3908 80066C68 0500622C */  sltiu      $v0, $v1, 0x5
    /* 390C 80066C6C 08004010 */  beqz       $v0, .L80066C90
    /* 3910 80066C70 0680023C */   lui       $v0, %hi(jtbl_800633CC)
    /* 3914 80066C74 CC334224 */  addiu      $v0, $v0, %lo(jtbl_800633CC)
    /* 3918 80066C78 80180300 */  sll        $v1, $v1, 2
    /* 391C 80066C7C 21186200 */  addu       $v1, $v1, $v0
    /* 3920 80066C80 0000628C */  lw         $v0, 0x0($v1)
    /* 3924 80066C84 00000000 */  nop
    /* 3928 80066C88 08004000 */  jr         $v0
    /* 392C 80066C8C 00000000 */   nop
  jlabel .L80066C90
    /* 3930 80066C90 2000038E */  lw         $v1, 0x20($s0)
    /* 3934 80066C94 00000000 */  nop
    /* 3938 80066C98 03006010 */  beqz       $v1, .L80066CA8
    /* 393C 80066C9C 01000224 */   addiu     $v0, $zero, 0x1
    /* 3940 80066CA0 32006210 */  beq        $v1, $v0, .L80066D6C
    /* 3944 80066CA4 00000000 */   nop
  .L80066CA8:
    /* 3948 80066CA8 21200002 */  addu       $a0, $s0, $zero
    /* 394C 80066CAC 02000524 */  addiu      $a1, $zero, 0x2
    /* 3950 80066CB0 0780063C */  lui        $a2, %hi(D_8006A58C)
    /* 3954 80066CB4 AC83000C */  jal        Actor_SetAxisMotion
    /* 3958 80066CB8 8CA5C624 */   addiu     $a2, $a2, %lo(D_8006A58C)
    /* 395C 80066CBC 21200002 */  addu       $a0, $s0, $zero
    /* 3960 80066CC0 9D7C000C */  jal        Anim_HasModelAnim
    /* 3964 80066CC4 14000524 */   addiu     $a1, $zero, 0x14
    /* 3968 80066CC8 05004014 */  bnez       $v0, .L80066CE0
    /* 396C 80066CCC 21200002 */   addu      $a0, $s0, $zero
    /* 3970 80066CD0 6645000C */  jal        Task_NextState3
    /* 3974 80066CD4 21200002 */   addu      $a0, $s0, $zero
    /* 3978 80066CD8 419B0108 */  j          .L80066D04
    /* 397C 80066CDC 00000000 */   nop
  .L80066CE0:
    /* 3980 80066CE0 F499010C */  jal        func_800667D0
    /* 3984 80066CE4 14000524 */   addiu     $a1, $zero, 0x14
    /* 3988 80066CE8 21200002 */  addu       $a0, $s0, $zero
    /* 398C 80066CEC 01000524 */  addiu      $a1, $zero, 0x1
    /* 3990 80066CF0 0780063C */  lui        $a2, %hi(D_8006A574)
    /* 3994 80066CF4 AC83000C */  jal        Actor_SetAxisMotion
    /* 3998 80066CF8 74A5C624 */   addiu     $a2, $a2, %lo(D_8006A574)
    /* 399C 80066CFC 9D9B0108 */  j          .L80066E74
    /* 39A0 80066D00 00000000 */   nop
  jlabel .L80066D04
    /* 39A4 80066D04 2000038E */  lw         $v1, 0x20($s0)
    /* 39A8 80066D08 00000000 */  nop
    /* 39AC 80066D0C 03006010 */  beqz       $v1, .L80066D1C
    /* 39B0 80066D10 01000224 */   addiu     $v0, $zero, 0x1
    /* 39B4 80066D14 15006210 */  beq        $v1, $v0, .L80066D6C
    /* 39B8 80066D18 00000000 */   nop
  .L80066D1C:
    /* 39BC 80066D1C F29A010C */  jal        func_80066BC8
    /* 39C0 80066D20 21200002 */   addu      $a0, $s0, $zero
    /* 39C4 80066D24 21200002 */  addu       $a0, $s0, $zero
    /* 39C8 80066D28 9D7C000C */  jal        Anim_HasModelAnim
    /* 39CC 80066D2C 15000524 */   addiu     $a1, $zero, 0x15
    /* 39D0 80066D30 05004014 */  bnez       $v0, .L80066D48
    /* 39D4 80066D34 21200002 */   addu      $a0, $s0, $zero
    /* 39D8 80066D38 6645000C */  jal        Task_NextState3
    /* 39DC 80066D3C 21200002 */   addu      $a0, $s0, $zero
    /* 39E0 80066D40 679B0108 */  j          .L80066D9C
    /* 39E4 80066D44 00000000 */   nop
  .L80066D48:
    /* 39E8 80066D48 F499010C */  jal        func_800667D0
    /* 39EC 80066D4C 15000524 */   addiu     $a1, $zero, 0x15
    /* 39F0 80066D50 21200002 */  addu       $a0, $s0, $zero
    /* 39F4 80066D54 01000524 */  addiu      $a1, $zero, 0x1
    /* 39F8 80066D58 0780063C */  lui        $a2, %hi(D_8006A580)
    /* 39FC 80066D5C AC83000C */  jal        Actor_SetAxisMotion
    /* 3A00 80066D60 80A5C624 */   addiu     $a2, $a2, %lo(D_8006A580)
    /* 3A04 80066D64 9D9B0108 */  j          .L80066E74
    /* 3A08 80066D68 00000000 */   nop
  .L80066D6C:
    /* 3A0C 80066D6C 3400228E */  lw         $v0, 0x34($s1)
    /* 3A10 80066D70 00000000 */  nop
    /* 3A14 80066D74 4B004018 */  blez       $v0, .L80066EA4
    /* 3A18 80066D78 21200002 */   addu      $a0, $s0, $zero
    /* 3A1C 80066D7C BA83000C */  jal        Actor_StopAxisMotion
    /* 3A20 80066D80 01000524 */   addiu     $a1, $zero, 0x1
    /* 3A24 80066D84 21200002 */  addu       $a0, $s0, $zero
    /* 3A28 80066D88 340020AE */  sw         $zero, 0x34($s1)
    /* 3A2C 80066D8C 6645000C */  jal        Task_NextState3
    /* 3A30 80066D90 4C0020AE */   sw        $zero, 0x4C($s1)
    /* 3A34 80066D94 A99B0108 */  j          .L80066EA4
    /* 3A38 80066D98 00000000 */   nop
  jlabel .L80066D9C
    /* 3A3C 80066D9C 2000038E */  lw         $v1, 0x20($s0)
    /* 3A40 80066DA0 00000000 */  nop
    /* 3A44 80066DA4 03006010 */  beqz       $v1, .L80066DB4
    /* 3A48 80066DA8 01000224 */   addiu     $v0, $zero, 0x1
    /* 3A4C 80066DAC 06006210 */  beq        $v1, $v0, .L80066DC8
    /* 3A50 80066DB0 00000000 */   nop
  .L80066DB4:
    /* 3A54 80066DB4 F29A010C */  jal        func_80066BC8
    /* 3A58 80066DB8 21200002 */   addu      $a0, $s0, $zero
    /* 3A5C 80066DBC 21200002 */  addu       $a0, $s0, $zero
    /* 3A60 80066DC0 9B9B0108 */  j          .L80066E6C
    /* 3A64 80066DC4 16000524 */   addiu     $a1, $zero, 0x16
  .L80066DC8:
    /* 3A68 80066DC8 3C00028E */  lw         $v0, 0x3C($s0)
    /* 3A6C 80066DCC 00000000 */  nop
    /* 3A70 80066DD0 6000428C */  lw         $v0, 0x60($v0)
    /* 3A74 80066DD4 00000000 */  nop
    /* 3A78 80066DD8 32004104 */  bgez       $v0, .L80066EA4
    /* 3A7C 80066DDC 00000000 */   nop
    /* 3A80 80066DE0 6645000C */  jal        Task_NextState3
    /* 3A84 80066DE4 21200002 */   addu      $a0, $s0, $zero
    /* 3A88 80066DE8 2E004012 */  beqz       $s2, .L80066EA4
    /* 3A8C 80066DEC 00000000 */   nop
    /* 3A90 80066DF0 6645000C */  jal        Task_NextState3
    /* 3A94 80066DF4 21200002 */   addu      $a0, $s0, $zero
    /* 3A98 80066DF8 A99B0108 */  j          .L80066EA4
    /* 3A9C 80066DFC 00000000 */   nop
  jlabel .L80066E00
    /* 3AA0 80066E00 2000038E */  lw         $v1, 0x20($s0)
    /* 3AA4 80066E04 00000000 */  nop
    /* 3AA8 80066E08 03006010 */  beqz       $v1, .L80066E18
    /* 3AAC 80066E0C 01000224 */   addiu     $v0, $zero, 0x1
    /* 3AB0 80066E10 04006210 */  beq        $v1, $v0, .L80066E24
    /* 3AB4 80066E14 00000000 */   nop
  .L80066E18:
    /* 3AB8 80066E18 21200002 */  addu       $a0, $s0, $zero
    /* 3ABC 80066E1C 9B9B0108 */  j          .L80066E6C
    /* 3AC0 80066E20 5A000524 */   addiu     $a1, $zero, 0x5A
  .L80066E24:
    /* 3AC4 80066E24 3C00028E */  lw         $v0, 0x3C($s0)
    /* 3AC8 80066E28 00000000 */  nop
    /* 3ACC 80066E2C 6000428C */  lw         $v0, 0x60($v0)
    /* 3AD0 80066E30 00000000 */  nop
    /* 3AD4 80066E34 1B004104 */  bgez       $v0, .L80066EA4
    /* 3AD8 80066E38 21200002 */   addu      $a0, $s0, $zero
    /* 3ADC 80066E3C 7745000C */  jal        Task_SetState1
    /* 3AE0 80066E40 21280000 */   addu      $a1, $zero, $zero
    /* 3AE4 80066E44 A99B0108 */  j          .L80066EA4
    /* 3AE8 80066E48 00000000 */   nop
  jlabel .L80066E4C
    /* 3AEC 80066E4C 2000038E */  lw         $v1, 0x20($s0)
    /* 3AF0 80066E50 00000000 */  nop
    /* 3AF4 80066E54 03006010 */  beqz       $v1, .L80066E64
    /* 3AF8 80066E58 01000224 */   addiu     $v0, $zero, 0x1
    /* 3AFC 80066E5C 09006210 */  beq        $v1, $v0, .L80066E84
    /* 3B00 80066E60 00000000 */   nop
  .L80066E64:
    /* 3B04 80066E64 21200002 */  addu       $a0, $s0, $zero
    /* 3B08 80066E68 64000524 */  addiu      $a1, $zero, 0x64
  .L80066E6C:
    /* 3B0C 80066E6C F499010C */  jal        func_800667D0
    /* 3B10 80066E70 00000000 */   nop
  .L80066E74:
    /* 3B14 80066E74 6B45000C */  jal        Task_NextState4
    /* 3B18 80066E78 21200002 */   addu      $a0, $s0, $zero
    /* 3B1C 80066E7C A99B0108 */  j          .L80066EA4
    /* 3B20 80066E80 00000000 */   nop
  .L80066E84:
    /* 3B24 80066E84 3C00028E */  lw         $v0, 0x3C($s0)
    /* 3B28 80066E88 00000000 */  nop
    /* 3B2C 80066E8C 6000428C */  lw         $v0, 0x60($v0)
    /* 3B30 80066E90 00000000 */  nop
    /* 3B34 80066E94 03004010 */  beqz       $v0, .L80066EA4
    /* 3B38 80066E98 21200002 */   addu      $a0, $s0, $zero
    /* 3B3C 80066E9C 7045000C */  jal        Task_SetState0
    /* 3B40 80066EA0 01000524 */   addiu     $a1, $zero, 0x1
  .L80066EA4:
    /* 3B44 80066EA4 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 3B48 80066EA8 1800B28F */  lw         $s2, 0x18($sp)
    /* 3B4C 80066EAC 1400B18F */  lw         $s1, 0x14($sp)
    /* 3B50 80066EB0 1000B08F */  lw         $s0, 0x10($sp)
    /* 3B54 80066EB4 0800E003 */  jr         $ra
    /* 3B58 80066EB8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80066C00
