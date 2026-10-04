nonmatching func_8006ADF8, 0x9D0

glabel func_8006ADF8
    /* 7A98 8006ADF8 B8FFBD27 */  addiu      $sp, $sp, -0x48
    /* 7A9C 8006ADFC 3800B2AF */  sw         $s2, 0x38($sp)
    /* 7AA0 8006AE00 21908000 */  addu       $s2, $a0, $zero
    /* 7AA4 8006AE04 4400BFAF */  sw         $ra, 0x44($sp)
    /* 7AA8 8006AE08 4000B4AF */  sw         $s4, 0x40($sp)
    /* 7AAC 8006AE0C 3C00B3AF */  sw         $s3, 0x3C($sp)
    /* 7AB0 8006AE10 3400B1AF */  sw         $s1, 0x34($sp)
    /* 7AB4 8006AE14 3000B0AF */  sw         $s0, 0x30($sp)
    /* 7AB8 8006AE18 0400428E */  lw         $v0, 0x4($s2)
    /* 7ABC 8006AE1C 2C00538E */  lw         $s3, 0x2C($s2)
    /* 7AC0 8006AE20 02004014 */  bnez       $v0, .L8006AE2C
    /* 7AC4 8006AE24 0780023C */   lui       $v0, %hi(D_800709B0)
    /* 7AC8 8006AE28 B00940AC */  sw         $zero, %lo(D_800709B0)($v0)
  .L8006AE2C:
    /* 7ACC 8006AE2C 1000518E */  lw         $s1, 0x10($s2)
    /* 7AD0 8006AE30 01000224 */  addiu      $v0, $zero, 0x1
    /* 7AD4 8006AE34 48002212 */  beq        $s1, $v0, .L8006AF58
    /* 7AD8 8006AE38 0200222A */   slti      $v0, $s1, 0x2
    /* 7ADC 8006AE3C 5A024010 */  beqz       $v0, .L8006B7A8
    /* 7AE0 8006AE40 00000000 */   nop
    /* 7AE4 8006AE44 58022016 */  bnez       $s1, .L8006B7A8
    /* 7AE8 8006AE48 21204002 */   addu      $a0, $s2, $zero
    /* 7AEC 8006AE4C 04006386 */  lh         $v1, 0x4($s3)
    /* 7AF0 8006AE50 1400A0AF */  sw         $zero, 0x14($sp)
    /* 7AF4 8006AE54 F5FF6324 */  addiu      $v1, $v1, -0xB
    /* 7AF8 8006AE58 40100300 */  sll        $v0, $v1, 1
    /* 7AFC 8006AE5C 21104300 */  addu       $v0, $v0, $v1
    /* 7B00 8006AE60 40120200 */  sll        $v0, $v0, 9
    /* 7B04 8006AE64 1000A2AF */  sw         $v0, 0x10($sp)
    /* 7B08 8006AE68 06006386 */  lh         $v1, 0x6($s3)
    /* 7B0C 8006AE6C 00000000 */  nop
    /* 7B10 8006AE70 F5FF6324 */  addiu      $v1, $v1, -0xB
    /* 7B14 8006AE74 40100300 */  sll        $v0, $v1, 1
    /* 7B18 8006AE78 21104300 */  addu       $v0, $v0, $v1
    /* 7B1C 8006AE7C 40120200 */  sll        $v0, $v0, 9
    /* 7B20 8006AE80 23100200 */  negu       $v0, $v0
    /* 7B24 8006AE84 1800A2AF */  sw         $v0, 0x18($sp)
    /* 7B28 8006AE88 0000668E */  lw         $a2, 0x0($s3)
    /* 7B2C 8006AE8C 1000A527 */  addiu      $a1, $sp, 0x10
    /* 7B30 8006AE90 80320600 */  sll        $a2, $a2, 10
    /* 7B34 8006AE94 1083000C */  jal        Actor_InitTransform
    /* 7B38 8006AE98 00FCC630 */   andi      $a2, $a2, 0xFC00
    /* 7B3C 8006AE9C 6400628E */  lw         $v0, 0x64($s3)
    /* 7B40 8006AEA0 00000000 */  nop
    /* 7B44 8006AEA4 27004010 */  beqz       $v0, .L8006AF44
    /* 7B48 8006AEA8 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 7B4C 8006AEAC 0C00448E */  lw         $a0, 0xC($s2)
    /* 7B50 8006AEB0 C179000C */  jal        Digi_GetModelFile
    /* 7B54 8006AEB4 00000000 */   nop
    /* 7B58 8006AEB8 21204002 */  addu       $a0, $s2, $zero
    /* 7B5C 8006AEBC 21284000 */  addu       $a1, $v0, $zero
    /* 7B60 8006AEC0 6F7F000C */  jal        Gfx_AttachModel
    /* 7B64 8006AEC4 200065AE */   sw        $a1, 0x20($s3)
    /* 7B68 8006AEC8 21204002 */  addu       $a0, $s2, $zero
    /* 7B6C 8006AECC 1E000524 */  addiu      $a1, $zero, 0x1E
    /* 7B70 8006AED0 03000324 */  addiu      $v1, $zero, 0x3
    /* 7B74 8006AED4 83AA010C */  jal        func_8006AA0C
    /* 7B78 8006AED8 3C0043AC */   sw        $v1, 0x3C($v0)
    /* 7B7C 8006AEDC 03030424 */  addiu      $a0, $zero, 0x303
    /* 7B80 8006AEE0 3400458E */  lw         $a1, 0x34($s2)
    /* 7B84 8006AEE4 1F44000C */  jal        Task_Create
    /* 7B88 8006AEE8 21304002 */   addu      $a2, $s2, $zero
    /* 7B8C 8006AEEC 0680023C */  lui        $v0, %hi(Sys_GameMode)
    /* 7B90 8006AEF0 0F030324 */  addiu      $v1, $zero, 0x30F
    /* 7B94 8006AEF4 88F7448C */  lw         $a0, %lo(Sys_GameMode)($v0)
    /* 7B98 8006AEF8 3800458E */  lw         $a1, 0x38($s2)
    /* 7B9C 8006AEFC 05008310 */  beq        $a0, $v1, .L8006AF14
    /* 7BA0 8006AF00 18030224 */   addiu     $v0, $zero, 0x318
    /* 7BA4 8006AF04 07008210 */  beq        $a0, $v0, .L8006AF24
    /* 7BA8 8006AF08 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 7BAC 8006AF0C D2AB0108 */  j          .L8006AF48
    /* 7BB0 8006AF10 6C0062AE */   sw        $v0, 0x6C($s3)
  .L8006AF14:
    /* 7BB4 8006AF14 21200000 */  addu       $a0, $zero, $zero
    /* 7BB8 8006AF18 0C00438E */  lw         $v1, 0xC($s2)
    /* 7BBC 8006AF1C CCAB0108 */  j          .L8006AF30
    /* 7BC0 8006AF20 2E000224 */   addiu     $v0, $zero, 0x2E
  .L8006AF24:
    /* 7BC4 8006AF24 21200000 */  addu       $a0, $zero, $zero
    /* 7BC8 8006AF28 0C00438E */  lw         $v1, 0xC($s2)
    /* 7BCC 8006AF2C 14000224 */  addiu      $v0, $zero, 0x14
  .L8006AF30:
    /* 7BD0 8006AF30 02006214 */  bne        $v1, $v0, .L8006AF3C
    /* 7BD4 8006AF34 00000000 */   nop
    /* 7BD8 8006AF38 80FB0424 */  addiu      $a0, $zero, -0x480
  .L8006AF3C:
    /* 7BDC 8006AF3C 3400A4AC */  sw         $a0, 0x34($a1)
    /* 7BE0 8006AF40 FFFF0224 */  addiu      $v0, $zero, -0x1
  .L8006AF44:
    /* 7BE4 8006AF44 6C0062AE */  sw         $v0, 0x6C($s3)
  .L8006AF48:
    /* 7BE8 8006AF48 5145000C */  jal        Task_NextState0
    /* 7BEC 8006AF4C 21204002 */   addu      $a0, $s2, $zero
    /* 7BF0 8006AF50 EAAD0108 */  j          .L8006B7A8
    /* 7BF4 8006AF54 00000000 */   nop
  .L8006AF58:
    /* 7BF8 8006AF58 0400428E */  lw         $v0, 0x4($s2)
    /* 7BFC 8006AF5C 00000000 */  nop
    /* 7C00 8006AF60 FFFF4228 */  slti       $v0, $v0, -0x1
    /* 7C04 8006AF64 58004010 */  beqz       $v0, .L8006B0C8
    /* 7C08 8006AF68 00000000 */   nop
    /* 7C0C 8006AF6C 1400428E */  lw         $v0, 0x14($s2)
    /* 7C10 8006AF70 00000000 */  nop
    /* 7C14 8006AF74 03004010 */  beqz       $v0, .L8006AF84
    /* 7C18 8006AF78 02030424 */   addiu     $a0, $zero, 0x302
    /* 7C1C 8006AF7C 2D005110 */  beq        $v0, $s1, .L8006B034
    /* 7C20 8006AF80 00000000 */   nop
  .L8006AF84:
    /* 7C24 8006AF84 21280000 */  addu       $a1, $zero, $zero
    /* 7C28 8006AF88 4445000C */  jal        Task_FindFirst
    /* 7C2C 8006AF8C FFFF0624 */   addiu     $a2, $zero, -0x1
    /* 7C30 8006AF90 21804000 */  addu       $s0, $v0, $zero
    /* 7C34 8006AF94 04020012 */  beqz       $s0, .L8006B7A8
    /* 7C38 8006AF98 00000000 */   nop
    /* 7C3C 8006AF9C 419D010C */  jal        func_80067504
    /* 7C40 8006AFA0 21200002 */   addu      $a0, $s0, $zero
    /* 7C44 8006AFA4 03004988 */  lwl        $t1, 0x3($v0)
    /* 7C48 8006AFA8 00004998 */  lwr        $t1, 0x0($v0)
    /* 7C4C 8006AFAC 00000000 */  nop
    /* 7C50 8006AFB0 2300A9AB */  swl        $t1, 0x23($sp)
    /* 7C54 8006AFB4 2000A9BB */  swr        $t1, 0x20($sp)
    /* 7C58 8006AFB8 04006386 */  lh         $v1, 0x4($s3)
    /* 7C5C 8006AFBC 2000A287 */  lh         $v0, 0x20($sp)
    /* 7C60 8006AFC0 00000000 */  nop
    /* 7C64 8006AFC4 F8016214 */  bne        $v1, $v0, .L8006B7A8
    /* 7C68 8006AFC8 00000000 */   nop
    /* 7C6C 8006AFCC 06006386 */  lh         $v1, 0x6($s3)
    /* 7C70 8006AFD0 2200A287 */  lh         $v0, 0x22($sp)
    /* 7C74 8006AFD4 00000000 */  nop
    /* 7C78 8006AFD8 F3016214 */  bne        $v1, $v0, .L8006B7A8
    /* 7C7C 8006AFDC 00000000 */   nop
    /* 7C80 8006AFE0 5A9D010C */  jal        func_80067568
    /* 7C84 8006AFE4 21200002 */   addu      $a0, $s0, $zero
    /* 7C88 8006AFE8 EF014010 */  beqz       $v0, .L8006B7A8
    /* 7C8C 8006AFEC 00000000 */   nop
    /* 7C90 8006AFF0 1C00648E */  lw         $a0, 0x1C($s3)
    /* 7C94 8006AFF4 4579000C */  jal        Flag_SelectBranch
    /* 7C98 8006AFF8 00000000 */   nop
    /* 7C9C 8006AFFC 6C006426 */  addiu      $a0, $s3, 0x6C
    /* 7CA0 8006B000 0E70000C */  jal        Text_OpenMsgClearChoice
    /* 7CA4 8006B004 21284000 */   addu      $a1, $v0, $zero
    /* 7CA8 8006B008 21200002 */  addu       $a0, $s0, $zero
    /* 7CAC 8006B00C 63AB010C */  jal        func_8006AD8C
    /* 7CB0 8006B010 680070AE */   sw        $s0, 0x68($s3)
    /* 7CB4 8006B014 21200002 */  addu       $a0, $s0, $zero
    /* 7CB8 8006B018 7745000C */  jal        Task_SetState1
    /* 7CBC 8006B01C 21280000 */   addu      $a1, $zero, $zero
    /* 7CC0 8006B020 5945000C */  jal        Task_NextState1
    /* 7CC4 8006B024 21204002 */   addu      $a0, $s2, $zero
    /* 7CC8 8006B028 0780023C */  lui        $v0, %hi(D_800709B4)
    /* 7CCC 8006B02C EAAD0108 */  j          .L8006B7A8
    /* 7CD0 8006B030 B40951AC */   sw        $s1, %lo(D_800709B4)($v0)
  .L8006B034:
    /* 7CD4 8006B034 7079000C */  jal        Flag_GetTableBase
    /* 7CD8 8006B038 00000000 */   nop
    /* 7CDC 8006B03C 6C00648E */  lw         $a0, 0x6C($s3)
    /* 7CE0 8006B040 826F000C */  jal        Text_IsFinished
    /* 7CE4 8006B044 00000000 */   nop
    /* 7CE8 8006B048 D7014010 */  beqz       $v0, .L8006B7A8
    /* 7CEC 8006B04C 6C007026 */   addiu     $s0, $s3, 0x6C
    /* 7CF0 8006B050 E26E000C */  jal        Text_Close
    /* 7CF4 8006B054 21200002 */   addu      $a0, $s0, $zero
    /* 7CF8 8006B058 9E87000C */  jal        Flag_Test
    /* 7CFC 8006B05C 10000424 */   addiu     $a0, $zero, 0x10
    /* 7D00 8006B060 09004010 */  beqz       $v0, .L8006B088
    /* 7D04 8006B064 FEFF0224 */   addiu     $v0, $zero, -0x2
    /* 7D08 8006B068 1C00648E */  lw         $a0, 0x1C($s3)
    /* 7D0C 8006B06C 4579000C */  jal        Flag_SelectBranch
    /* 7D10 8006B070 00000000 */   nop
    /* 7D14 8006B074 21200002 */  addu       $a0, $s0, $zero
    /* 7D18 8006B078 0E70000C */  jal        Text_OpenMsgClearChoice
    /* 7D1C 8006B07C 21284000 */   addu      $a1, $v0, $zero
    /* 7D20 8006B080 EAAD0108 */  j          .L8006B7A8
    /* 7D24 8006B084 00000000 */   nop
  .L8006B088:
    /* 7D28 8006B088 0400438E */  lw         $v1, 0x4($s2)
    /* 7D2C 8006B08C 00000000 */  nop
    /* 7D30 8006B090 05006214 */  bne        $v1, $v0, .L8006B0A8
    /* 7D34 8006B094 21204002 */   addu      $a0, $s2, $zero
    /* 7D38 8006B098 7045000C */  jal        Task_SetState0
    /* 7D3C 8006B09C 03000524 */   addiu     $a1, $zero, 0x3
    /* 7D40 8006B0A0 2CAC0108 */  j          .L8006B0B0
    /* 7D44 8006B0A4 00000000 */   nop
  .L8006B0A8:
    /* 7D48 8006B0A8 7745000C */  jal        Task_SetState1
    /* 7D4C 8006B0AC 21280000 */   addu      $a1, $zero, $zero
  .L8006B0B0:
    /* 7D50 8006B0B0 6800648E */  lw         $a0, 0x68($s3)
    /* 7D54 8006B0B4 7745000C */  jal        Task_SetState1
    /* 7D58 8006B0B8 21280000 */   addu      $a1, $zero, $zero
    /* 7D5C 8006B0BC 0780023C */  lui        $v0, %hi(D_800709B4)
    /* 7D60 8006B0C0 EAAD0108 */  j          .L8006B7A8
    /* 7D64 8006B0C4 B40940AC */   sw        $zero, %lo(D_800709B4)($v0)
  .L8006B0C8:
    /* 7D68 8006B0C8 6400628E */  lw         $v0, 0x64($s3)
    /* 7D6C 8006B0CC 00000000 */  nop
    /* 7D70 8006B0D0 05004010 */  beqz       $v0, .L8006B0E8
    /* 7D74 8006B0D4 00000000 */   nop
    /* 7D78 8006B0D8 C3AA010C */  jal        func_8006AB0C
    /* 7D7C 8006B0DC 21204002 */   addu      $a0, $s2, $zero
    /* 7D80 8006B0E0 3BAC0108 */  j          .L8006B0EC
    /* 7D84 8006B0E4 00000000 */   nop
  .L8006B0E8:
    /* 7D88 8006B0E8 240060AE */  sw         $zero, 0x24($s3)
  .L8006B0EC:
    /* 7D8C 8006B0EC 1400438E */  lw         $v1, 0x14($s2)
    /* 7D90 8006B0F0 00000000 */  nop
    /* 7D94 8006B0F4 03006010 */  beqz       $v1, .L8006B104
    /* 7D98 8006B0F8 01000224 */   addiu     $v0, $zero, 0x1
    /* 7D9C 8006B0FC F7006210 */  beq        $v1, $v0, .L8006B4DC
    /* 7DA0 8006B100 00000000 */   nop
  .L8006B104:
    /* 7DA4 8006B104 1800438E */  lw         $v1, 0x18($s2)
    /* 7DA8 8006B108 01000824 */  addiu      $t0, $zero, 0x1
    /* 7DAC 8006B10C 13006810 */  beq        $v1, $t0, .L8006B15C
    /* 7DB0 8006B110 02006228 */   slti      $v0, $v1, 0x2
    /* 7DB4 8006B114 06004014 */  bnez       $v0, .L8006B130
    /* 7DB8 8006B118 21204002 */   addu      $a0, $s2, $zero
    /* 7DBC 8006B11C 02000224 */  addiu      $v0, $zero, 0x2
    /* 7DC0 8006B120 87006210 */  beq        $v1, $v0, .L8006B340
    /* 7DC4 8006B124 03000224 */   addiu     $v0, $zero, 0x3
    /* 7DC8 8006B128 DB006210 */  beq        $v1, $v0, .L8006B498
    /* 7DCC 8006B12C 00000000 */   nop
  .L8006B130:
    /* 7DD0 8006B130 BA83000C */  jal        Actor_StopAxisMotion
    /* 7DD4 8006B134 02000524 */   addiu     $a1, $zero, 0x2
    /* 7DD8 8006B138 21204002 */  addu       $a0, $s2, $zero
    /* 7DDC 8006B13C 83AA010C */  jal        func_8006AA0C
    /* 7DE0 8006B140 1E000524 */   addiu     $a1, $zero, 0x1E
    /* 7DE4 8006B144 21204002 */  addu       $a0, $s2, $zero
    /* 7DE8 8006B148 01000524 */  addiu      $a1, $zero, 0x1
    /* 7DEC 8006B14C 819D010C */  jal        func_80067604
    /* 7DF0 8006B150 2130A000 */   addu      $a2, $a1, $zero
    /* 7DF4 8006B154 6045000C */  jal        Task_NextState2
    /* 7DF8 8006B158 21204002 */   addu      $a0, $s2, $zero
  .L8006B15C:
    /* 7DFC 8006B15C 21204002 */  addu       $a0, $s2, $zero
    /* 7E00 8006B160 34007026 */  addiu      $s0, $s3, 0x34
    /* 7E04 8006B164 21280002 */  addu       $a1, $s0, $zero
    /* 7E08 8006B168 FFFF0624 */  addiu      $a2, $zero, -0x1
    /* 7E0C 8006B16C F29D010C */  jal        func_800677C8
    /* 7E10 8006B170 05000724 */   addiu     $a3, $zero, 0x5
    /* 7E14 8006B174 2400648E */  lw         $a0, 0x24($s3)
    /* 7E18 8006B178 00000000 */  nop
    /* 7E1C 8006B17C 00F08230 */  andi       $v0, $a0, 0xF000
    /* 7E20 8006B180 1B004010 */  beqz       $v0, .L8006B1F0
    /* 7E24 8006B184 00000000 */   nop
    /* 7E28 8006B188 45AB010C */  jal        func_8006AD14
    /* 7E2C 8006B18C 21204002 */   addu      $a0, $s2, $zero
    /* 7E30 8006B190 21204002 */  addu       $a0, $s2, $zero
    /* 7E34 8006B194 DC9D010C */  jal        func_80067770
    /* 7E38 8006B198 21284000 */   addu      $a1, $v0, $zero
    /* 7E3C 8006B19C 0D004014 */  bnez       $v0, .L8006B1D4
    /* 7E40 8006B1A0 00000000 */   nop
    /* 7E44 8006B1A4 45AB010C */  jal        func_8006AD14
    /* 7E48 8006B1A8 21204002 */   addu      $a0, $s2, $zero
    /* 7E4C 8006B1AC 21204002 */  addu       $a0, $s2, $zero
    /* 7E50 8006B1B0 21280002 */  addu       $a1, $s0, $zero
    /* 7E54 8006B1B4 21304000 */  addu       $a2, $v0, $zero
    /* 7E58 8006B1B8 F29D010C */  jal        func_800677C8
    /* 7E5C 8006B1BC 14000724 */   addiu     $a3, $zero, 0x14
    /* 7E60 8006B1C0 21204002 */  addu       $a0, $s2, $zero
    /* 7E64 8006B1C4 7745000C */  jal        Task_SetState1
    /* 7E68 8006B1C8 01000524 */   addiu     $a1, $zero, 0x1
    /* 7E6C 8006B1CC 26AD0108 */  j          .L8006B498
    /* 7E70 8006B1D0 600060AE */   sw        $zero, 0x60($s3)
  .L8006B1D4:
    /* 7E74 8006B1D4 45AB010C */  jal        func_8006AD14
    /* 7E78 8006B1D8 21204002 */   addu      $a0, $s2, $zero
    /* 7E7C 8006B1DC 21204002 */  addu       $a0, $s2, $zero
    /* 7E80 8006B1E0 5BAB010C */  jal        func_8006AD6C
    /* 7E84 8006B1E4 21284000 */   addu      $a1, $v0, $zero
    /* 7E88 8006B1E8 26AD0108 */  j          .L8006B498
    /* 7E8C 8006B1EC 00000000 */   nop
  .L8006B1F0:
    /* 7E90 8006B1F0 0400428E */  lw         $v0, 0x4($s2)
    /* 7E94 8006B1F4 00000000 */  nop
    /* 7E98 8006B1F8 A7004014 */  bnez       $v0, .L8006B498
    /* 7E9C 8006B1FC 0680023C */   lui       $v0, %hi(Sys_State)
    /* 7EA0 8006B200 7000638E */  lw         $v1, 0x70($s3)
    /* 7EA4 8006B204 70F7428C */  lw         $v0, %lo(Sys_State)($v0)
    /* 7EA8 8006B208 00000000 */  nop
    /* 7EAC 8006B20C 2A186200 */  slt        $v1, $v1, $v0
    /* 7EB0 8006B210 41006010 */  beqz       $v1, .L8006B318
    /* 7EB4 8006B214 40008230 */   andi      $v0, $a0, 0x40
    /* 7EB8 8006B218 3F004010 */  beqz       $v0, .L8006B318
    /* 7EBC 8006B21C 00000000 */   nop
    /* 7EC0 8006B220 3800428E */  lw         $v0, 0x38($s2)
    /* 7EC4 8006B224 00000000 */  nop
    /* 7EC8 8006B228 42004294 */  lhu        $v0, 0x42($v0)
    /* 7ECC 8006B22C 00000000 */  nop
    /* 7ED0 8006B230 FF0F4230 */  andi       $v0, $v0, 0xFFF
    /* 7ED4 8006B234 02004104 */  bgez       $v0, .L8006B240
    /* 7ED8 8006B238 21204002 */   addu      $a0, $s2, $zero
    /* 7EDC 8006B23C FF034224 */  addiu      $v0, $v0, 0x3FF
  .L8006B240:
    /* 7EE0 8006B240 82A20200 */  srl        $s4, $v0, 10
    /* 7EE4 8006B244 DC9D010C */  jal        func_80067770
    /* 7EE8 8006B248 21288002 */   addu      $a1, $s4, $zero
    /* 7EEC 8006B24C 40004230 */  andi       $v0, $v0, 0x40
    /* 7EF0 8006B250 31004010 */  beqz       $v0, .L8006B318
    /* 7EF4 8006B254 01000524 */   addiu     $a1, $zero, 0x1
    /* 7EF8 8006B258 02030424 */  addiu      $a0, $zero, 0x302
    /* 7EFC 8006B25C 4445000C */  jal        Task_FindFirst
    /* 7F00 8006B260 FFFF0624 */   addiu     $a2, $zero, -0x1
    /* 7F04 8006B264 21804000 */  addu       $s0, $v0, $zero
    /* 7F08 8006B268 21880000 */  addu       $s1, $zero, $zero
    /* 7F0C 8006B26C 21204002 */  addu       $a0, $s2, $zero
    /* 7F10 8006B270 C59D010C */  jal        func_80067714
    /* 7F14 8006B274 21288002 */   addu      $a1, $s4, $zero
    /* 7F18 8006B278 03004988 */  lwl        $t1, 0x3($v0)
    /* 7F1C 8006B27C 00004998 */  lwr        $t1, 0x0($v0)
    /* 7F20 8006B280 00000000 */  nop
    /* 7F24 8006B284 2300A9AB */  swl        $t1, 0x23($sp)
    /* 7F28 8006B288 2000A9BB */  swr        $t1, 0x20($sp)
    /* 7F2C 8006B28C 1E000012 */  beqz       $s0, .L8006B308
    /* 7F30 8006B290 00000000 */   nop
  .L8006B294:
    /* 7F34 8006B294 419D010C */  jal        func_80067504
    /* 7F38 8006B298 21200002 */   addu      $a0, $s0, $zero
    /* 7F3C 8006B29C 03004988 */  lwl        $t1, 0x3($v0)
    /* 7F40 8006B2A0 00004998 */  lwr        $t1, 0x0($v0)
    /* 7F44 8006B2A4 00000000 */  nop
    /* 7F48 8006B2A8 2B00A9AB */  swl        $t1, 0x2B($sp)
    /* 7F4C 8006B2AC 2800A9BB */  swr        $t1, 0x28($sp)
    /* 7F50 8006B2B0 2800A387 */  lh         $v1, 0x28($sp)
    /* 7F54 8006B2B4 2000A287 */  lh         $v0, 0x20($sp)
    /* 7F58 8006B2B8 00000000 */  nop
    /* 7F5C 8006B2BC 0D006214 */  bne        $v1, $v0, .L8006B2F4
    /* 7F60 8006B2C0 00000000 */   nop
    /* 7F64 8006B2C4 2A00A387 */  lh         $v1, 0x2A($sp)
    /* 7F68 8006B2C8 2200A287 */  lh         $v0, 0x22($sp)
    /* 7F6C 8006B2CC 00000000 */  nop
    /* 7F70 8006B2D0 08006214 */  bne        $v1, $v0, .L8006B2F4
    /* 7F74 8006B2D4 00000000 */   nop
    /* 7F78 8006B2D8 1400028E */  lw         $v0, 0x14($s0)
    /* 7F7C 8006B2DC 00000000 */  nop
    /* 7F80 8006B2E0 09004014 */  bnez       $v0, .L8006B308
    /* 7F84 8006B2E4 00000000 */   nop
    /* 7F88 8006B2E8 680070AE */  sw         $s0, 0x68($s3)
    /* 7F8C 8006B2EC C2AC0108 */  j          .L8006B308
    /* 7F90 8006B2F0 01001124 */   addiu     $s1, $zero, 0x1
  .L8006B2F4:
    /* 7F94 8006B2F4 1045000C */  jal        Task_FindNext
    /* 7F98 8006B2F8 00000000 */   nop
    /* 7F9C 8006B2FC 21804000 */  addu       $s0, $v0, $zero
    /* 7FA0 8006B300 E4FF0016 */  bnez       $s0, .L8006B294
    /* 7FA4 8006B304 00000000 */   nop
  .L8006B308:
    /* 7FA8 8006B308 03002012 */  beqz       $s1, .L8006B318
    /* 7FAC 8006B30C 00000000 */   nop
    /* 7FB0 8006B310 6045000C */  jal        Task_NextState2
    /* 7FB4 8006B314 21204002 */   addu      $a0, $s2, $zero
  .L8006B318:
    /* 7FB8 8006B318 0400428E */  lw         $v0, 0x4($s2)
    /* 7FBC 8006B31C 00000000 */  nop
    /* 7FC0 8006B320 5D004014 */  bnez       $v0, .L8006B498
    /* 7FC4 8006B324 01000224 */   addiu     $v0, $zero, 0x1
    /* 7FC8 8006B328 1800438E */  lw         $v1, 0x18($s2)
    /* 7FCC 8006B32C 00000000 */  nop
    /* 7FD0 8006B330 59006214 */  bne        $v1, $v0, .L8006B498
    /* 7FD4 8006B334 0780023C */   lui       $v0, %hi(D_800709B0)
    /* 7FD8 8006B338 26AD0108 */  j          .L8006B498
    /* 7FDC 8006B33C B00943AC */   sw        $v1, %lo(D_800709B0)($v0)
  .L8006B340:
    /* 7FE0 8006B340 0400428E */  lw         $v0, 0x4($s2)
    /* 7FE4 8006B344 00000000 */  nop
    /* 7FE8 8006B348 22004014 */  bnez       $v0, .L8006B3D4
    /* 7FEC 8006B34C 21204002 */   addu      $a0, $s2, $zero
    /* 7FF0 8006B350 34006526 */  addiu      $a1, $s3, 0x34
    /* 7FF4 8006B354 FFFF0624 */  addiu      $a2, $zero, -0x1
    /* 7FF8 8006B358 6800708E */  lw         $s0, 0x68($s3)
    /* 7FFC 8006B35C 05000724 */  addiu      $a3, $zero, 0x5
    /* 8000 8006B360 2C00118E */  lw         $s1, 0x2C($s0)
    /* 8004 8006B364 0780023C */  lui        $v0, %hi(D_800709B4)
    /* 8008 8006B368 F29D010C */  jal        func_800677C8
    /* 800C 8006B36C B40948AC */   sw        $t0, %lo(D_800709B4)($v0)
    /* 8010 8006B370 21204002 */  addu       $a0, $s2, $zero
    /* 8014 8006B374 83AA010C */  jal        func_8006AA0C
    /* 8018 8006B378 20000524 */   addiu     $a1, $zero, 0x20
    /* 801C 8006B37C 21200002 */  addu       $a0, $s0, $zero
    /* 8020 8006B380 7745000C */  jal        Task_SetState1
    /* 8024 8006B384 21280000 */   addu      $a1, $zero, $zero
    /* 8028 8006B388 21200002 */  addu       $a0, $s0, $zero
    /* 802C 8006B38C 8545000C */  jal        Task_SetState2
    /* 8030 8006B390 02000524 */   addiu     $a1, $zero, 0x2
    /* 8034 8006B394 680032AE */  sw         $s2, 0x68($s1)
    /* 8038 8006B398 3800428E */  lw         $v0, 0x38($s2)
    /* 803C 8006B39C 21204002 */  addu       $a0, $s2, $zero
    /* 8040 8006B3A0 42004294 */  lhu        $v0, 0x42($v0)
    /* 8044 8006B3A4 3800038E */  lw         $v1, 0x38($s0)
    /* 8048 8006B3A8 00084224 */  addiu      $v0, $v0, 0x800
    /* 804C 8006B3AC 63AB010C */  jal        func_8006AD8C
    /* 8050 8006B3B0 420062A4 */   sh        $v0, 0x42($v1)
    /* 8054 8006B3B4 21204002 */  addu       $a0, $s2, $zero
    /* 8058 8006B3B8 7745000C */  jal        Task_SetState1
    /* 805C 8006B3BC 21280000 */   addu      $a1, $zero, $zero
    /* 8060 8006B3C0 21204002 */  addu       $a0, $s2, $zero
    /* 8064 8006B3C4 8545000C */  jal        Task_SetState2
    /* 8068 8006B3C8 01000524 */   addiu     $a1, $zero, 0x1
    /* 806C 8006B3CC 26AD0108 */  j          .L8006B498
    /* 8070 8006B3D0 00000000 */   nop
  .L8006B3D4:
    /* 8074 8006B3D4 1C00428E */  lw         $v0, 0x1C($s2)
    /* 8078 8006B3D8 00000000 */  nop
    /* 807C 8006B3DC 03004010 */  beqz       $v0, .L8006B3EC
    /* 8080 8006B3E0 00000000 */   nop
    /* 8084 8006B3E4 0D004810 */  beq        $v0, $t0, .L8006B41C
    /* 8088 8006B3E8 00000000 */   nop
  .L8006B3EC:
    /* 808C 8006B3EC 83AA010C */  jal        func_8006AA0C
    /* 8090 8006B3F0 20000524 */   addiu     $a1, $zero, 0x20
    /* 8094 8006B3F4 1C00648E */  lw         $a0, 0x1C($s3)
    /* 8098 8006B3F8 4579000C */  jal        Flag_SelectBranch
    /* 809C 8006B3FC 00000000 */   nop
    /* 80A0 8006B400 6C006426 */  addiu      $a0, $s3, 0x6C
    /* 80A4 8006B404 0E70000C */  jal        Text_OpenMsgClearChoice
    /* 80A8 8006B408 21284000 */   addu      $a1, $v0, $zero
    /* 80AC 8006B40C 6645000C */  jal        Task_NextState3
    /* 80B0 8006B410 21204002 */   addu      $a0, $s2, $zero
    /* 80B4 8006B414 26AD0108 */  j          .L8006B498
    /* 80B8 8006B418 00000000 */   nop
  .L8006B41C:
    /* 80BC 8006B41C 7079000C */  jal        Flag_GetTableBase
    /* 80C0 8006B420 00000000 */   nop
    /* 80C4 8006B424 6C00648E */  lw         $a0, 0x6C($s3)
    /* 80C8 8006B428 826F000C */  jal        Text_IsFinished
    /* 80CC 8006B42C 00000000 */   nop
    /* 80D0 8006B430 19004010 */  beqz       $v0, .L8006B498
    /* 80D4 8006B434 00000000 */   nop
    /* 80D8 8006B438 E26E000C */  jal        Text_Close
    /* 80DC 8006B43C 6C006426 */   addiu     $a0, $s3, 0x6C
    /* 80E0 8006B440 9E87000C */  jal        Flag_Test
    /* 80E4 8006B444 10000424 */   addiu     $a0, $zero, 0x10
    /* 80E8 8006B448 05004010 */  beqz       $v0, .L8006B460
    /* 80EC 8006B44C 21204002 */   addu      $a0, $s2, $zero
    /* 80F0 8006B450 8A45000C */  jal        Task_SetState3
    /* 80F4 8006B454 21280000 */   addu      $a1, $zero, $zero
    /* 80F8 8006B458 26AD0108 */  j          .L8006B498
    /* 80FC 8006B45C 00000000 */   nop
  .L8006B460:
    /* 8100 8006B460 0680023C */  lui        $v0, %hi(Sys_State)
    /* 8104 8006B464 6800638E */  lw         $v1, 0x68($s3)
    /* 8108 8006B468 70F7428C */  lw         $v0, %lo(Sys_State)($v0)
    /* 810C 8006B46C 2C00638C */  lw         $v1, 0x2C($v1)
    /* 8110 8006B470 1E004224 */  addiu      $v0, $v0, 0x1E
    /* 8114 8006B474 700062AC */  sw         $v0, 0x70($v1)
    /* 8118 8006B478 6800648E */  lw         $a0, 0x68($s3)
    /* 811C 8006B47C 7745000C */  jal        Task_SetState1
    /* 8120 8006B480 21280000 */   addu      $a1, $zero, $zero
    /* 8124 8006B484 21204002 */  addu       $a0, $s2, $zero
    /* 8128 8006B488 8545000C */  jal        Task_SetState2
    /* 812C 8006B48C 21280000 */   addu      $a1, $zero, $zero
    /* 8130 8006B490 0780023C */  lui        $v0, %hi(D_800709B4)
    /* 8134 8006B494 B40940AC */  sw         $zero, %lo(D_800709B4)($v0)
  .L8006B498:
    /* 8138 8006B498 2C00638E */  lw         $v1, 0x2C($s3)
    /* 813C 8006B49C 00000000 */  nop
    /* 8140 8006B4A0 25006228 */  slti       $v0, $v1, 0x25
    /* 8144 8006B4A4 BD004010 */  beqz       $v0, .L8006B79C
    /* 8148 8006B4A8 22006228 */   slti      $v0, $v1, 0x22
    /* 814C 8006B4AC BC004014 */  bnez       $v0, .L8006B7A0
    /* 8150 8006B4B0 21204002 */   addu      $a0, $s2, $zero
    /* 8154 8006B4B4 3C00428E */  lw         $v0, 0x3C($s2)
    /* 8158 8006B4B8 00000000 */  nop
    /* 815C 8006B4BC 6000428C */  lw         $v0, 0x60($v0)
    /* 8160 8006B4C0 00000000 */  nop
    /* 8164 8006B4C4 B6004010 */  beqz       $v0, .L8006B7A0
    /* 8168 8006B4C8 00000000 */   nop
    /* 816C 8006B4CC 83AA010C */  jal        func_8006AA0C
    /* 8170 8006B4D0 1E000524 */   addiu     $a1, $zero, 0x1E
    /* 8174 8006B4D4 E8AD0108 */  j          .L8006B7A0
    /* 8178 8006B4D8 21204002 */   addu      $a0, $s2, $zero
  .L8006B4DC:
    /* 817C 8006B4DC 1800428E */  lw         $v0, 0x18($s2)
    /* 8180 8006B4E0 00000000 */  nop
    /* 8184 8006B4E4 03004010 */  beqz       $v0, .L8006B4F4
    /* 8188 8006B4E8 00000000 */   nop
    /* 818C 8006B4EC 1C004310 */  beq        $v0, $v1, .L8006B560
    /* 8190 8006B4F0 00000000 */   nop
  .L8006B4F4:
    /* 8194 8006B4F4 45AB010C */  jal        func_8006AD14
    /* 8198 8006B4F8 21204002 */   addu      $a0, $s2, $zero
    /* 819C 8006B4FC 21804000 */  addu       $s0, $v0, $zero
    /* 81A0 8006B500 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 81A4 8006B504 0B000212 */  beq        $s0, $v0, .L8006B534
    /* 81A8 8006B508 21204002 */   addu      $a0, $s2, $zero
    /* 81AC 8006B50C 5BAB010C */  jal        func_8006AD6C
    /* 81B0 8006B510 21280002 */   addu      $a1, $s0, $zero
    /* 81B4 8006B514 300070AE */  sw         $s0, 0x30($s3)
    /* 81B8 8006B518 45AB010C */  jal        func_8006AD14
    /* 81BC 8006B51C 21204002 */   addu      $a0, $s2, $zero
    /* 81C0 8006B520 21204002 */  addu       $a0, $s2, $zero
    /* 81C4 8006B524 DC9D010C */  jal        func_80067770
    /* 81C8 8006B528 21284000 */   addu      $a1, $v0, $zero
    /* 81CC 8006B52C 06004010 */  beqz       $v0, .L8006B548
    /* 81D0 8006B530 21204002 */   addu      $a0, $s2, $zero
  .L8006B534:
    /* 81D4 8006B534 21204002 */  addu       $a0, $s2, $zero
    /* 81D8 8006B538 7745000C */  jal        Task_SetState1
    /* 81DC 8006B53C 21280000 */   addu      $a1, $zero, $zero
    /* 81E0 8006B540 E8AD0108 */  j          .L8006B7A0
    /* 81E4 8006B544 21204002 */   addu      $a0, $s2, $zero
  .L8006B548:
    /* 81E8 8006B548 34006526 */  addiu      $a1, $s3, 0x34
    /* 81EC 8006B54C 3000668E */  lw         $a2, 0x30($s3)
    /* 81F0 8006B550 F29D010C */  jal        func_800677C8
    /* 81F4 8006B554 14000724 */   addiu     $a3, $zero, 0x14
    /* 81F8 8006B558 6045000C */  jal        Task_NextState2
    /* 81FC 8006B55C 21204002 */   addu      $a0, $s2, $zero
  .L8006B560:
    /* 8200 8006B560 2400628E */  lw         $v0, 0x24($s3)
    /* 8204 8006B564 00000000 */  nop
    /* 8208 8006B568 10004230 */  andi       $v0, $v0, 0x10
    /* 820C 8006B56C 09004014 */  bnez       $v0, .L8006B594
    /* 8210 8006B570 0780023C */   lui       $v0, %hi(D_800709B4)
    /* 8214 8006B574 B409428C */  lw         $v0, %lo(D_800709B4)($v0)
    /* 8218 8006B578 00000000 */  nop
    /* 821C 8006B57C 06004014 */  bnez       $v0, .L8006B598
    /* 8220 8006B580 21204002 */   addu      $a0, $s2, $zero
    /* 8224 8006B584 0400428E */  lw         $v0, 0x4($s2)
    /* 8228 8006B588 00000000 */  nop
    /* 822C 8006B58C 07004010 */  beqz       $v0, .L8006B5AC
    /* 8230 8006B590 00000000 */   nop
  .L8006B594:
    /* 8234 8006B594 21204002 */  addu       $a0, $s2, $zero
  .L8006B598:
    /* 8238 8006B598 83AA010C */  jal        func_8006AA0C
    /* 823C 8006B59C 1F000524 */   addiu     $a1, $zero, 0x1F
    /* 8240 8006B5A0 21204002 */  addu       $a0, $s2, $zero
    /* 8244 8006B5A4 6FAD0108 */  j          .L8006B5BC
    /* 8248 8006B5A8 21280000 */   addu      $a1, $zero, $zero
  .L8006B5AC:
    /* 824C 8006B5AC 83AA010C */  jal        func_8006AA0C
    /* 8250 8006B5B0 25000524 */   addiu     $a1, $zero, 0x25
    /* 8254 8006B5B4 21204002 */  addu       $a0, $s2, $zero
    /* 8258 8006B5B8 01000524 */  addiu      $a1, $zero, 0x1
  .L8006B5BC:
    /* 825C 8006B5BC AA9D010C */  jal        func_800676A8
    /* 8260 8006B5C0 00000000 */   nop
    /* 8264 8006B5C4 0400428E */  lw         $v0, 0x4($s2)
    /* 8268 8006B5C8 00000000 */  nop
    /* 826C 8006B5CC 3E004014 */  bnez       $v0, .L8006B6C8
    /* 8270 8006B5D0 21204002 */   addu      $a0, $s2, $zero
    /* 8274 8006B5D4 21200000 */  addu       $a0, $zero, $zero
    /* 8278 8006B5D8 6000638E */  lw         $v1, 0x60($s3)
    /* 827C 8006B5DC 2400628E */  lw         $v0, 0x24($s3)
    /* 8280 8006B5E0 01006324 */  addiu      $v1, $v1, 0x1
    /* 8284 8006B5E4 10004230 */  andi       $v0, $v0, 0x10
    /* 8288 8006B5E8 06004014 */  bnez       $v0, .L8006B604
    /* 828C 8006B5EC 600063AE */   sw        $v1, 0x60($s3)
    /* 8290 8006B5F0 0780023C */  lui        $v0, %hi(D_800709B4)
    /* 8294 8006B5F4 B409428C */  lw         $v0, %lo(D_800709B4)($v0)
    /* 8298 8006B5F8 00000000 */  nop
    /* 829C 8006B5FC 02004010 */  beqz       $v0, .L8006B608
    /* 82A0 8006B600 05006228 */   slti      $v0, $v1, 0x5
  .L8006B604:
    /* 82A4 8006B604 0D006228 */  slti       $v0, $v1, 0xD
  .L8006B608:
    /* 82A8 8006B608 02004014 */  bnez       $v0, .L8006B614
    /* 82AC 8006B60C 00000000 */   nop
    /* 82B0 8006B610 01000424 */  addiu      $a0, $zero, 0x1
  .L8006B614:
    /* 82B4 8006B614 2C008010 */  beqz       $a0, .L8006B6C8
    /* 82B8 8006B618 21204002 */   addu      $a0, $s2, $zero
    /* 82BC 8006B61C C599010C */  jal        func_80066714
    /* 82C0 8006B620 27001424 */   addiu     $s4, $zero, 0x27
    /* 82C4 8006B624 1800428C */  lw         $v0, 0x18($v0)
    /* 82C8 8006B628 00000000 */  nop
    /* 82CC 8006B62C 22004010 */  beqz       $v0, .L8006B6B8
    /* 82D0 8006B630 21208002 */   addu      $a0, $s4, $zero
    /* 82D4 8006B634 419D010C */  jal        func_80067504
    /* 82D8 8006B638 21204002 */   addu      $a0, $s2, $zero
    /* 82DC 8006B63C 03004988 */  lwl        $t1, 0x3($v0)
    /* 82E0 8006B640 00004998 */  lwr        $t1, 0x0($v0)
    /* 82E4 8006B644 00000000 */  nop
    /* 82E8 8006B648 2300A9AB */  swl        $t1, 0x23($sp)
    /* 82EC 8006B64C 2000A9BB */  swr        $t1, 0x20($sp)
    /* 82F0 8006B650 2000A487 */  lh         $a0, 0x20($sp)
    /* 82F4 8006B654 2200A387 */  lh         $v1, 0x22($sp)
    /* 82F8 8006B658 21288000 */  addu       $a1, $a0, $zero
    /* 82FC 8006B65C 40100300 */  sll        $v0, $v1, 1
    /* 8300 8006B660 02008104 */  bgez       $a0, .L8006B66C
    /* 8304 8006B664 21884300 */   addu      $s1, $v0, $v1
    /* 8308 8006B668 07008524 */  addiu      $a1, $a0, 0x7
  .L8006B66C:
    /* 830C 8006B66C C3100500 */  sra        $v0, $a1, 3
    /* 8310 8006B670 21882202 */  addu       $s1, $s1, $v0
    /* 8314 8006B674 C0100200 */  sll        $v0, $v0, 3
    /* 8318 8006B678 23108200 */  subu       $v0, $a0, $v0
    /* 831C 8006B67C 00140200 */  sll        $v0, $v0, 16
    /* 8320 8006B680 03140200 */  sra        $v0, $v0, 16
    /* 8324 8006B684 01001024 */  addiu      $s0, $zero, 0x1
    /* 8328 8006B688 C599010C */  jal        func_80066714
    /* 832C 8006B68C 04805000 */   sllv      $s0, $s0, $v0
    /* 8330 8006B690 1800428C */  lw         $v0, 0x18($v0)
    /* 8334 8006B694 00000000 */  nop
    /* 8338 8006B698 21105100 */  addu       $v0, $v0, $s1
    /* 833C 8006B69C 00004290 */  lbu        $v0, 0x0($v0)
    /* 8340 8006B6A0 00000000 */  nop
    /* 8344 8006B6A4 24105000 */  and        $v0, $v0, $s0
    /* 8348 8006B6A8 02004010 */  beqz       $v0, .L8006B6B4
    /* 834C 8006B6AC 00000000 */   nop
    /* 8350 8006B6B0 28001424 */  addiu      $s4, $zero, 0x28
  .L8006B6B4:
    /* 8354 8006B6B4 21208002 */  addu       $a0, $s4, $zero
  .L8006B6B8:
    /* 8358 8006B6B8 A369000C */  jal        Snd_PlayById
    /* 835C 8006B6BC 21280000 */   addu      $a1, $zero, $zero
    /* 8360 8006B6C0 600060AE */  sw         $zero, 0x60($s3)
    /* 8364 8006B6C4 21204002 */  addu       $a0, $s2, $zero
  .L8006B6C8:
    /* 8368 8006B6C8 5583000C */  jal        Actor_ApplyAxisMotion
    /* 836C 8006B6CC 02000524 */   addiu     $a1, $zero, 0x2
    /* 8370 8006B6D0 21204002 */  addu       $a0, $s2, $zero
    /* 8374 8006B6D4 34006526 */  addiu      $a1, $s3, 0x34
    /* 8378 8006B6D8 FFFF0624 */  addiu      $a2, $zero, -0x1
    /* 837C 8006B6DC F29D010C */  jal        func_800677C8
    /* 8380 8006B6E0 05000724 */   addiu     $a3, $zero, 0x5
    /* 8384 8006B6E4 5A9D010C */  jal        func_80067568
    /* 8388 8006B6E8 21204002 */   addu      $a0, $s2, $zero
    /* 838C 8006B6EC 12004010 */  beqz       $v0, .L8006B738
    /* 8390 8006B6F0 00000000 */   nop
    /* 8394 8006B6F4 2400628E */  lw         $v0, 0x24($s3)
    /* 8398 8006B6F8 00000000 */  nop
    /* 839C 8006B6FC 00F04230 */  andi       $v0, $v0, 0xF000
    /* 83A0 8006B700 0A004010 */  beqz       $v0, .L8006B72C
    /* 83A4 8006B704 21204002 */   addu      $a0, $s2, $zero
    /* 83A8 8006B708 45AB010C */  jal        func_8006AD14
    /* 83AC 8006B70C 21204002 */   addu      $a0, $s2, $zero
    /* 83B0 8006B710 21204002 */  addu       $a0, $s2, $zero
    /* 83B4 8006B714 DC9D010C */  jal        func_80067770
    /* 83B8 8006B718 21284000 */   addu      $a1, $v0, $zero
    /* 83BC 8006B71C 03004014 */  bnez       $v0, .L8006B72C
    /* 83C0 8006B720 21204002 */   addu      $a0, $s2, $zero
    /* 83C4 8006B724 CCAD0108 */  j          .L8006B730
    /* 83C8 8006B728 01000524 */   addiu     $a1, $zero, 0x1
  .L8006B72C:
    /* 83CC 8006B72C 21280000 */  addu       $a1, $zero, $zero
  .L8006B730:
    /* 83D0 8006B730 7745000C */  jal        Task_SetState1
    /* 83D4 8006B734 00000000 */   nop
  .L8006B738:
    /* 83D8 8006B738 3000638E */  lw         $v1, 0x30($s3)
    /* 83DC 8006B73C 01000224 */  addiu      $v0, $zero, 0x1
    /* 83E0 8006B740 11006210 */  beq        $v1, $v0, .L8006B788
    /* 83E4 8006B744 02006228 */   slti      $v0, $v1, 0x2
    /* 83E8 8006B748 05004010 */  beqz       $v0, .L8006B760
    /* 83EC 8006B74C 02000224 */   addiu     $v0, $zero, 0x2
    /* 83F0 8006B750 09006010 */  beqz       $v1, .L8006B778
    /* 83F4 8006B754 21204002 */   addu      $a0, $s2, $zero
    /* 83F8 8006B758 E8AD0108 */  j          .L8006B7A0
    /* 83FC 8006B75C 00000000 */   nop
  .L8006B760:
    /* 8400 8006B760 05006210 */  beq        $v1, $v0, .L8006B778
    /* 8404 8006B764 03000224 */   addiu     $v0, $zero, 0x3
    /* 8408 8006B768 07006210 */  beq        $v1, $v0, .L8006B788
    /* 840C 8006B76C 21204002 */   addu      $a0, $s2, $zero
    /* 8410 8006B770 E8AD0108 */  j          .L8006B7A0
    /* 8414 8006B774 00000000 */   nop
  .L8006B778:
    /* 8418 8006B778 21204002 */  addu       $a0, $s2, $zero
    /* 841C 8006B77C 01000524 */  addiu      $a1, $zero, 0x1
    /* 8420 8006B780 E5AD0108 */  j          .L8006B794
    /* 8424 8006B784 21300000 */   addu      $a2, $zero, $zero
  .L8006B788:
    /* 8428 8006B788 21204002 */  addu       $a0, $s2, $zero
    /* 842C 8006B78C 21280000 */  addu       $a1, $zero, $zero
    /* 8430 8006B790 01000624 */  addiu      $a2, $zero, 0x1
  .L8006B794:
    /* 8434 8006B794 819D010C */  jal        func_80067604
    /* 8438 8006B798 00000000 */   nop
  .L8006B79C:
    /* 843C 8006B79C 21204002 */  addu       $a0, $s2, $zero
  .L8006B7A0:
    /* 8440 8006B7A0 2A9E010C */  jal        func_800678A8
    /* 8444 8006B7A4 34006526 */   addiu     $a1, $s3, 0x34
  .L8006B7A8:
    /* 8448 8006B7A8 4400BF8F */  lw         $ra, 0x44($sp)
    /* 844C 8006B7AC 4000B48F */  lw         $s4, 0x40($sp)
    /* 8450 8006B7B0 3C00B38F */  lw         $s3, 0x3C($sp)
    /* 8454 8006B7B4 3800B28F */  lw         $s2, 0x38($sp)
    /* 8458 8006B7B8 3400B18F */  lw         $s1, 0x34($sp)
    /* 845C 8006B7BC 3000B08F */  lw         $s0, 0x30($sp)
    /* 8460 8006B7C0 0800E003 */  jr         $ra
    /* 8464 8006B7C4 4800BD27 */   addiu     $sp, $sp, 0x48
endlabel func_8006ADF8
