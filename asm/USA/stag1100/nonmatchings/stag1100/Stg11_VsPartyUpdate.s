nonmatching Stg11_VsPartyUpdate, 0x4DC

glabel Stg11_VsPartyUpdate
    /* 38E8 80066C48 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 38EC 80066C4C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 38F0 80066C50 21908000 */  addu       $s2, $a0, $zero
    /* 38F4 80066C54 01000624 */  addiu      $a2, $zero, 0x1
    /* 38F8 80066C58 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 38FC 80066C5C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3900 80066C60 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3904 80066C64 1000458E */  lw         $a1, 0x10($s2)
    /* 3908 80066C68 2C00508E */  lw         $s0, 0x2C($s2)
    /* 390C 80066C6C 1F00A610 */  beq        $a1, $a2, .L80066CEC
    /* 3910 80066C70 0200A228 */   slti      $v0, $a1, 0x2
    /* 3914 80066C74 03004014 */  bnez       $v0, .L80066C84
    /* 3918 80066C78 02000224 */   addiu     $v0, $zero, 0x2
    /* 391C 80066C7C 0001A210 */  beq        $a1, $v0, .L80067080
    /* 3920 80066C80 00000000 */   nop
  .L80066C84:
    /* 3924 80066C84 21200002 */  addu       $a0, $s0, $zero
    /* 3928 80066C88 0780023C */  lui        $v0, %hi(Stg11_VsPartyLayout)
    /* 392C 80066C8C F8814B24 */  addiu      $t3, $v0, %lo(Stg11_VsPartyLayout)
    /* 3930 80066C90 03006889 */  lwl        $t0, 0x3($t3)
    /* 3934 80066C94 00006899 */  lwr        $t0, 0x0($t3)
    /* 3938 80066C98 07006989 */  lwl        $t1, 0x7($t3)
    /* 393C 80066C9C 04006999 */  lwr        $t1, 0x4($t3)
    /* 3940 80066CA0 0B006A89 */  lwl        $t2, 0xB($t3)
    /* 3944 80066CA4 08006A99 */  lwr        $t2, 0x8($t3)
    /* 3948 80066CA8 570008AA */  swl        $t0, 0x57($s0)
    /* 394C 80066CAC 540008BA */  swr        $t0, 0x54($s0)
    /* 3950 80066CB0 5B0009AA */  swl        $t1, 0x5B($s0)
    /* 3954 80066CB4 580009BA */  swr        $t1, 0x58($s0)
    /* 3958 80066CB8 5F000AAA */  swl        $t2, 0x5F($s0)
    /* 395C 80066CBC 5C000ABA */  swr        $t2, 0x5C($s0)
    /* 3960 80066CC0 660000A6 */  sh         $zero, 0x66($s0)
    /* 3964 80066CC4 520000A6 */  sh         $zero, 0x52($s0)
    /* 3968 80066CC8 D299010C */  jal        Stg11_VsPartyBuildList
    /* 396C 80066CCC 500000A6 */   sh        $zero, 0x50($s0)
    /* 3970 80066CD0 21200002 */  addu       $a0, $s0, $zero
    /* 3974 80066CD4 2270000C */  jal        Mem_FillWordsNeg1
    /* 3978 80066CD8 14000524 */   addiu     $a1, $zero, 0x14
    /* 397C 80066CDC 5145000C */  jal        Task_NextState0
    /* 3980 80066CE0 21204002 */   addu      $a0, $s2, $zero
    /* 3984 80066CE4 439C0108 */  j          .L8006710C
    /* 3988 80066CE8 00000000 */   nop
  .L80066CEC:
    /* 398C 80066CEC 1400438E */  lw         $v1, 0x14($s2)
    /* 3990 80066CF0 00000000 */  nop
    /* 3994 80066CF4 0600622C */  sltiu      $v0, $v1, 0x6
    /* 3998 80066CF8 08004010 */  beqz       $v0, .L80066D1C
    /* 399C 80066CFC 0680023C */   lui       $v0, %hi(jtbl_800634AC)
    /* 39A0 80066D00 AC344224 */  addiu      $v0, $v0, %lo(jtbl_800634AC)
    /* 39A4 80066D04 80180300 */  sll        $v1, $v1, 2
    /* 39A8 80066D08 21186200 */  addu       $v1, $v1, $v0
    /* 39AC 80066D0C 0000628C */  lw         $v0, 0x0($v1)
    /* 39B0 80066D10 00000000 */  nop
    /* 39B4 80066D14 08004000 */  jr         $v0
    /* 39B8 80066D18 00000000 */   nop
  jlabel .L80066D1C
    /* 39BC 80066D1C 21204002 */  addu       $a0, $s2, $zero
    /* 39C0 80066D20 B94D000C */  jal        Math_RampToOne
    /* 39C4 80066D24 9C010526 */   addiu     $a1, $s0, 0x19C
    /* 39C8 80066D28 F8004014 */  bnez       $v0, .L8006710C
    /* 39CC 80066D2C 21200002 */   addu      $a0, $s0, $zero
    /* 39D0 80066D30 189A010C */  jal        Stg11_VsPartyOpenRowText
    /* 39D4 80066D34 01000524 */   addiu     $a1, $zero, 0x1
    /* 39D8 80066D38 379C0108 */  j          .L800670DC
    /* 39DC 80066D3C 00000000 */   nop
  jlabel .L80066D40
    /* 39E0 80066D40 60000386 */  lh         $v1, 0x60($s0)
    /* 39E4 80066D44 00000000 */  nop
    /* 39E8 80066D48 05006018 */  blez       $v1, .L80066D60
    /* 39EC 80066D4C 03006228 */   slti      $v0, $v1, 0x3
    /* 39F0 80066D50 03004014 */  bnez       $v0, .L80066D60
    /* 39F4 80066D54 05006228 */   slti      $v0, $v1, 0x5
    /* 39F8 80066D58 0A004014 */  bnez       $v0, .L80066D84
    /* 39FC 80066D5C FD01023C */   lui       $v0, (0x1FD0109 >> 16)
  .L80066D60:
    /* 3A00 80066D60 6A000286 */  lh         $v0, 0x6A($s0)
    /* 3A04 80066D64 00000000 */  nop
    /* 3A08 80066D68 04004228 */  slti       $v0, $v0, 0x4
    /* 3A0C 80066D6C 78004014 */  bnez       $v0, .L80066F50
    /* 3A10 80066D70 21204002 */   addu      $a0, $s2, $zero
    /* 3A14 80066D74 7745000C */  jal        Task_SetState1
    /* 3A18 80066D78 03000524 */   addiu     $a1, $zero, 0x3
    /* 3A1C 80066D7C 439C0108 */  j          .L8006710C
    /* 3A20 80066D80 00000000 */   nop
  .L80066D84:
    /* 3A24 80066D84 A0010486 */  lh         $a0, 0x1A0($s0)
    /* 3A28 80066D88 09014234 */  ori        $v0, $v0, (0x1FD0109 & 0xFFFF)
    /* 3A2C 80066D8C 688E000C */  jal        Cd_GetFileEntry
    /* 3A30 80066D90 21208200 */   addu      $a0, $a0, $v0
    /* 3A34 80066D94 40000426 */  addiu      $a0, $s0, 0x40
    /* 3A38 80066D98 21284000 */  addu       $a1, $v0, $zero
    /* 3A3C 80066D9C 80000624 */  addiu      $a2, $zero, 0x80
    /* 3A40 80066DA0 0780033C */  lui        $v1, %hi(Stg11_VsPromptPos)
    /* 3A44 80066DA4 04826224 */  addiu      $v0, $v1, %lo(Stg11_VsPromptPos)
    /* 3A48 80066DA8 02004794 */  lhu        $a3, 0x2($v0)
    /* 3A4C 80066DAC 04826294 */  lhu        $v0, %lo(Stg11_VsPromptPos)($v1)
    /* 3A50 80066DB0 003C0700 */  sll        $a3, $a3, 16
    /* 3A54 80066DB4 3E4D000C */  jal        Text_OpenPacked
    /* 3A58 80066DB8 25384700 */   or        $a3, $v0, $a3
    /* 3A5C 80066DBC FD01043C */  lui        $a0, (0x1FD00FA >> 16)
    /* 3A60 80066DC0 688E000C */  jal        Cd_GetFileEntry
    /* 3A64 80066DC4 FA008434 */   ori       $a0, $a0, (0x1FD00FA & 0xFFFF)
    /* 3A68 80066DC8 48000426 */  addiu      $a0, $s0, 0x48
    /* 3A6C 80066DCC 21284000 */  addu       $a1, $v0, $zero
    /* 3A70 80066DD0 21300000 */  addu       $a2, $zero, $zero
    /* 3A74 80066DD4 0780033C */  lui        $v1, %hi(D_80068208)
    /* 3A78 80066DD8 08826224 */  addiu      $v0, $v1, %lo(D_80068208)
    /* 3A7C 80066DDC 02004794 */  lhu        $a3, 0x2($v0)
    /* 3A80 80066DE0 08826294 */  lhu        $v0, %lo(D_80068208)($v1)
    /* 3A84 80066DE4 003C0700 */  sll        $a3, $a3, 16
    /* 3A88 80066DE8 3E4D000C */  jal        Text_OpenPacked
    /* 3A8C 80066DEC 25384700 */   or        $a3, $v0, $a3
    /* 3A90 80066DF0 379C0108 */  j          .L800670DC
    /* 3A94 80066DF4 00000000 */   nop
  jlabel .L80066DF8
    /* 3A98 80066DF8 50000426 */  addiu      $a0, $s0, 0x50
    /* 3A9C 80066DFC 64000686 */  lh         $a2, 0x64($s0)
    /* 3AA0 80066E00 304E000C */  jal        Menu_MoveGridCursor
    /* 3AA4 80066E04 54000526 */   addiu     $a1, $s0, 0x54
    /* 3AA8 80066E08 16004014 */  bnez       $v0, .L80066E64
    /* 3AAC 80066E0C 0D000424 */   addiu     $a0, $zero, 0xD
    /* 3AB0 80066E10 0680023C */  lui        $v0, %hi(D_8005F6F0)
    /* 3AB4 80066E14 64000386 */  lh         $v1, 0x64($s0)
    /* 3AB8 80066E18 F0F64224 */  addiu      $v0, $v0, %lo(D_8005F6F0)
    /* 3ABC 80066E1C 80190300 */  sll        $v1, $v1, 6
    /* 3AC0 80066E20 21186200 */  addu       $v1, $v1, $v0
    /* 3AC4 80066E24 1C00628C */  lw         $v0, 0x1C($v1)
    /* 3AC8 80066E28 00000000 */  nop
    /* 3ACC 80066E2C 05004018 */  blez       $v0, .L80066E44
    /* 3AD0 80066E30 00000000 */   nop
    /* 3AD4 80066E34 D89A010C */  jal        Stg11_VsPartyUnpick
    /* 3AD8 80066E38 21204002 */   addu      $a0, $s2, $zero
    /* 3ADC 80066E3C 439C0108 */  j          .L8006710C
    /* 3AE0 80066E40 00000000 */   nop
  .L80066E44:
    /* 3AE4 80066E44 1400628C */  lw         $v0, 0x14($v1)
    /* 3AE8 80066E48 00000000 */  nop
    /* 3AEC 80066E4C AF004018 */  blez       $v0, .L8006710C
    /* 3AF0 80066E50 00000000 */   nop
    /* 3AF4 80066E54 839A010C */  jal        Stg11_VsPartyPick
    /* 3AF8 80066E58 21204002 */   addu      $a0, $s2, $zero
    /* 3AFC 80066E5C 439C0108 */  j          .L8006710C
    /* 3B00 80066E60 00000000 */   nop
  .L80066E64:
    /* 3B04 80066E64 A369000C */  jal        Snd_PlayById
    /* 3B08 80066E68 21280000 */   addu      $a1, $zero, $zero
    /* 3B0C 80066E6C 52000586 */  lh         $a1, 0x52($s0)
    /* 3B10 80066E70 66000486 */  lh         $a0, 0x66($s0)
    /* 3B14 80066E74 52000396 */  lhu        $v1, 0x52($s0)
    /* 3B18 80066E78 2310A400 */  subu       $v0, $a1, $a0
    /* 3B1C 80066E7C 04004228 */  slti       $v0, $v0, 0x4
    /* 3B20 80066E80 04004014 */  bnez       $v0, .L80066E94
    /* 3B24 80066E84 2A10A400 */   slt       $v0, $a1, $a0
    /* 3B28 80066E88 FDFF6224 */  addiu      $v0, $v1, -0x3
    /* 3B2C 80066E8C A89B0108 */  j          .L80066EA0
    /* 3B30 80066E90 660002A6 */   sh        $v0, 0x66($s0)
  .L80066E94:
    /* 3B34 80066E94 06004010 */  beqz       $v0, .L80066EB0
    /* 3B38 80066E98 21204002 */   addu      $a0, $s2, $zero
    /* 3B3C 80066E9C 660003A6 */  sh         $v1, 0x66($s0)
  .L80066EA0:
    /* 3B40 80066EA0 21200002 */  addu       $a0, $s0, $zero
    /* 3B44 80066EA4 189A010C */  jal        Stg11_VsPartyOpenRowText
    /* 3B48 80066EA8 21280000 */   addu      $a1, $zero, $zero
    /* 3B4C 80066EAC 21204002 */  addu       $a0, $s2, $zero
  .L80066EB0:
    /* 3B50 80066EB0 7745000C */  jal        Task_SetState1
    /* 3B54 80066EB4 01000524 */   addiu     $a1, $zero, 0x1
    /* 3B58 80066EB8 439C0108 */  j          .L8006710C
    /* 3B5C 80066EBC 00000000 */   nop
  jlabel .L80066EC0
    /* 3B60 80066EC0 1800518E */  lw         $s1, 0x18($s2)
    /* 3B64 80066EC4 00000000 */  nop
    /* 3B68 80066EC8 03002012 */  beqz       $s1, .L80066ED8
    /* 3B6C 80066ECC 01000224 */   addiu     $v0, $zero, 0x1
    /* 3B70 80066ED0 14002212 */  beq        $s1, $v0, .L80066F24
    /* 3B74 80066ED4 00000000 */   nop
  .L80066ED8:
    /* 3B78 80066ED8 FD01043C */  lui        $a0, (0x1FD01A9 >> 16)
    /* 3B7C 80066EDC 688E000C */  jal        Cd_GetFileEntry
    /* 3B80 80066EE0 A9018434 */   ori       $a0, $a0, (0x1FD01A9 & 0xFFFF)
    /* 3B84 80066EE4 40000426 */  addiu      $a0, $s0, 0x40
    /* 3B88 80066EE8 21284000 */  addu       $a1, $v0, $zero
    /* 3B8C 80066EEC 81000624 */  addiu      $a2, $zero, 0x81
    /* 3B90 80066EF0 0780033C */  lui        $v1, %hi(Stg11_VsPromptPos)
    /* 3B94 80066EF4 04826224 */  addiu      $v0, $v1, %lo(Stg11_VsPromptPos)
    /* 3B98 80066EF8 02004794 */  lhu        $a3, 0x2($v0)
    /* 3B9C 80066EFC 04826294 */  lhu        $v0, %lo(Stg11_VsPromptPos)($v1)
    /* 3BA0 80066F00 003C0700 */  sll        $a3, $a3, 16
    /* 3BA4 80066F04 3E4D000C */  jal        Text_OpenPacked
    /* 3BA8 80066F08 25384700 */   or        $a3, $v0, $a3
    /* 3BAC 80066F0C 4000048E */  lw         $a0, 0x40($s0)
    /* 3BB0 80066F10 64000586 */  lh         $a1, 0x64($s0)
    /* 3BB4 80066F14 BA6F000C */  jal        Text_SetInputPad
    /* 3BB8 80066F18 00000000 */   nop
    /* 3BBC 80066F1C 169C0108 */  j          .L80067058
    /* 3BC0 80066F20 00000000 */   nop
  .L80066F24:
    /* 3BC4 80066F24 4000048E */  lw         $a0, 0x40($s0)
    /* 3BC8 80066F28 A94D000C */  jal        Text_WaitYesNo
    /* 3BCC 80066F2C 00000000 */   nop
    /* 3BD0 80066F30 76004010 */  beqz       $v0, .L8006710C
    /* 3BD4 80066F34 00000000 */   nop
    /* 3BD8 80066F38 05005114 */  bne        $v0, $s1, .L80066F50
    /* 3BDC 80066F3C 21204002 */   addu      $a0, $s2, $zero
    /* 3BE0 80066F40 7745000C */  jal        Task_SetState1
    /* 3BE4 80066F44 05000524 */   addiu     $a1, $zero, 0x5
    /* 3BE8 80066F48 439C0108 */  j          .L8006710C
    /* 3BEC 80066F4C 00000000 */   nop
  .L80066F50:
    /* 3BF0 80066F50 7745000C */  jal        Task_SetState1
    /* 3BF4 80066F54 04000524 */   addiu     $a1, $zero, 0x4
    /* 3BF8 80066F58 439C0108 */  j          .L8006710C
    /* 3BFC 80066F5C 00000000 */   nop
  jlabel .L80066F60
    /* 3C00 80066F60 1800518E */  lw         $s1, 0x18($s2)
    /* 3C04 80066F64 00000000 */  nop
    /* 3C08 80066F68 03002012 */  beqz       $s1, .L80066F78
    /* 3C0C 80066F6C 01000224 */   addiu     $v0, $zero, 0x1
    /* 3C10 80066F70 14002212 */  beq        $s1, $v0, .L80066FC4
    /* 3C14 80066F74 00000000 */   nop
  .L80066F78:
    /* 3C18 80066F78 FD01043C */  lui        $a0, (0x1FD01AA >> 16)
    /* 3C1C 80066F7C 688E000C */  jal        Cd_GetFileEntry
    /* 3C20 80066F80 AA018434 */   ori       $a0, $a0, (0x1FD01AA & 0xFFFF)
    /* 3C24 80066F84 40000426 */  addiu      $a0, $s0, 0x40
    /* 3C28 80066F88 21284000 */  addu       $a1, $v0, $zero
    /* 3C2C 80066F8C 81000624 */  addiu      $a2, $zero, 0x81
    /* 3C30 80066F90 0780033C */  lui        $v1, %hi(Stg11_VsPromptPos)
    /* 3C34 80066F94 04826224 */  addiu      $v0, $v1, %lo(Stg11_VsPromptPos)
    /* 3C38 80066F98 02004794 */  lhu        $a3, 0x2($v0)
    /* 3C3C 80066F9C 04826294 */  lhu        $v0, %lo(Stg11_VsPromptPos)($v1)
    /* 3C40 80066FA0 003C0700 */  sll        $a3, $a3, 16
    /* 3C44 80066FA4 3E4D000C */  jal        Text_OpenPacked
    /* 3C48 80066FA8 25384700 */   or        $a3, $v0, $a3
    /* 3C4C 80066FAC 4000048E */  lw         $a0, 0x40($s0)
    /* 3C50 80066FB0 64000586 */  lh         $a1, 0x64($s0)
    /* 3C54 80066FB4 BA6F000C */  jal        Text_SetInputPad
    /* 3C58 80066FB8 00000000 */   nop
    /* 3C5C 80066FBC 169C0108 */  j          .L80067058
    /* 3C60 80066FC0 00000000 */   nop
  .L80066FC4:
    /* 3C64 80066FC4 4000048E */  lw         $a0, 0x40($s0)
    /* 3C68 80066FC8 A94D000C */  jal        Text_WaitYesNo
    /* 3C6C 80066FCC 00000000 */   nop
    /* 3C70 80066FD0 21184000 */  addu       $v1, $v0, $zero
    /* 3C74 80066FD4 4D006010 */  beqz       $v1, .L8006710C
    /* 3C78 80066FD8 00000000 */   nop
    /* 3C7C 80066FDC 05007114 */  bne        $v1, $s1, .L80066FF4
    /* 3C80 80066FE0 21204002 */   addu      $a0, $s2, $zero
    /* 3C84 80066FE4 0580023C */  lui        $v0, %hi(D_80050780)
    /* 3C88 80066FE8 800743A4 */  sh         $v1, %lo(D_80050780)($v0)
    /* 3C8C 80066FEC 0780023C */  lui        $v0, %hi(Stg11_LoadDone)
    /* 3C90 80066FF0 C88543A4 */  sh         $v1, %lo(Stg11_LoadDone)($v0)
  .L80066FF4:
    /* 3C94 80066FF4 419C0108 */  j          .L80067104
    /* 3C98 80066FF8 02000524 */   addiu     $a1, $zero, 0x2
  jlabel .L80066FFC
    /* 3C9C 80066FFC 01000224 */  addiu      $v0, $zero, 0x1
    /* 3CA0 80067000 1800438E */  lw         $v1, 0x18($s2)
    /* 3CA4 80067004 3400518E */  lw         $s1, 0x34($s2)
    /* 3CA8 80067008 0A006210 */  beq        $v1, $v0, .L80067034
    /* 3CAC 8006700C 02006228 */   slti      $v0, $v1, 0x2
    /* 3CB0 80067010 04004014 */  bnez       $v0, .L80067024
    /* 3CB4 80067014 21200002 */   addu      $a0, $s0, $zero
    /* 3CB8 80067018 02000224 */  addiu      $v0, $zero, 0x2
    /* 3CBC 8006701C 12006210 */  beq        $v1, $v0, .L80067068
    /* 3CC0 80067020 00000000 */   nop
  .L80067024:
    /* 3CC4 80067024 2C70000C */  jal        Text_CloseArray
    /* 3CC8 80067028 14000524 */   addiu     $a1, $zero, 0x14
    /* 3CCC 8006702C 169C0108 */  j          .L80067058
    /* 3CD0 80067030 00000000 */   nop
  .L80067034:
    /* 3CD4 80067034 21204002 */  addu       $a0, $s2, $zero
    /* 3CD8 80067038 C54D000C */  jal        Math_RampToZero
    /* 3CDC 8006703C 9C010526 */   addiu     $a1, $s0, 0x19C
    /* 3CE0 80067040 32004014 */  bnez       $v0, .L8006710C
    /* 3CE4 80067044 05060424 */   addiu     $a0, $zero, 0x605
    /* 3CE8 80067048 64000686 */  lh         $a2, 0x64($s0)
    /* 3CEC 8006704C 21282002 */  addu       $a1, $s1, $zero
    /* 3CF0 80067050 1F44000C */  jal        Task_Create
    /* 3CF4 80067054 0300C624 */   addiu     $a2, $a2, 0x3
  .L80067058:
    /* 3CF8 80067058 6045000C */  jal        Task_NextState2
    /* 3CFC 8006705C 21204002 */   addu      $a0, $s2, $zero
    /* 3D00 80067060 439C0108 */  j          .L8006710C
    /* 3D04 80067064 00000000 */   nop
  .L80067068:
    /* 3D08 80067068 0000228E */  lw         $v0, 0x0($s1)
    /* 3D0C 8006706C 00000000 */  nop
    /* 3D10 80067070 26004014 */  bnez       $v0, .L8006710C
    /* 3D14 80067074 21204002 */   addu      $a0, $s2, $zero
    /* 3D18 80067078 419C0108 */  j          .L80067104
    /* 3D1C 8006707C 21280000 */   addu      $a1, $zero, $zero
  .L80067080:
    /* 3D20 80067080 1400438E */  lw         $v1, 0x14($s2)
    /* 3D24 80067084 3400448E */  lw         $a0, 0x34($s2)
    /* 3D28 80067088 10006610 */  beq        $v1, $a2, .L800670CC
    /* 3D2C 8006708C 02006228 */   slti      $v0, $v1, 0x2
    /* 3D30 80067090 03004014 */  bnez       $v0, .L800670A0
    /* 3D34 80067094 00000000 */   nop
    /* 3D38 80067098 14006510 */  beq        $v1, $a1, .L800670EC
    /* 3D3C 8006709C 00000000 */   nop
  .L800670A0:
    /* 3D40 800670A0 0000848C */  lw         $a0, 0x0($a0)
    /* 3D44 800670A4 00000000 */  nop
    /* 3D48 800670A8 03008010 */  beqz       $a0, .L800670B8
    /* 3D4C 800670AC 00000000 */   nop
    /* 3D50 800670B0 7045000C */  jal        Task_SetState0
    /* 3D54 800670B4 02000524 */   addiu     $a1, $zero, 0x2
  .L800670B8:
    /* 3D58 800670B8 21200002 */  addu       $a0, $s0, $zero
    /* 3D5C 800670BC 2C70000C */  jal        Text_CloseArray
    /* 3D60 800670C0 14000524 */   addiu     $a1, $zero, 0x14
    /* 3D64 800670C4 379C0108 */  j          .L800670DC
    /* 3D68 800670C8 00000000 */   nop
  .L800670CC:
    /* 3D6C 800670CC 0000828C */  lw         $v0, 0x0($a0)
    /* 3D70 800670D0 00000000 */  nop
    /* 3D74 800670D4 0D004014 */  bnez       $v0, .L8006710C
    /* 3D78 800670D8 00000000 */   nop
  .L800670DC:
    /* 3D7C 800670DC 5945000C */  jal        Task_NextState1
    /* 3D80 800670E0 21204002 */   addu      $a0, $s2, $zero
    /* 3D84 800670E4 439C0108 */  j          .L8006710C
    /* 3D88 800670E8 00000000 */   nop
  .L800670EC:
    /* 3D8C 800670EC 21204002 */  addu       $a0, $s2, $zero
    /* 3D90 800670F0 C54D000C */  jal        Math_RampToZero
    /* 3D94 800670F4 9C010526 */   addiu     $a1, $s0, 0x19C
    /* 3D98 800670F8 04004014 */  bnez       $v0, .L8006710C
    /* 3D9C 800670FC 21204002 */   addu      $a0, $s2, $zero
    /* 3DA0 80067100 03000524 */  addiu      $a1, $zero, 0x3
  .L80067104:
    /* 3DA4 80067104 7045000C */  jal        Task_SetState0
    /* 3DA8 80067108 00000000 */   nop
  .L8006710C:
    /* 3DAC 8006710C 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 3DB0 80067110 1800B28F */  lw         $s2, 0x18($sp)
    /* 3DB4 80067114 1400B18F */  lw         $s1, 0x14($sp)
    /* 3DB8 80067118 1000B08F */  lw         $s0, 0x10($sp)
    /* 3DBC 8006711C 0800E003 */  jr         $ra
    /* 3DC0 80067120 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg11_VsPartyUpdate
