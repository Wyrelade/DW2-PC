nonmatching Stg00_GroupViewTask, 0x35C

glabel Stg00_GroupViewTask
    /* 3694 800669F4 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 3698 800669F8 2000B4AF */  sw         $s4, 0x20($sp)
    /* 369C 800669FC 21A08000 */  addu       $s4, $a0, $zero
    /* 36A0 80066A00 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 36A4 80066A04 2800B6AF */  sw         $s6, 0x28($sp)
    /* 36A8 80066A08 2400B5AF */  sw         $s5, 0x24($sp)
    /* 36AC 80066A0C 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 36B0 80066A10 1800B2AF */  sw         $s2, 0x18($sp)
    /* 36B4 80066A14 1400B1AF */  sw         $s1, 0x14($sp)
    /* 36B8 80066A18 1000B0AF */  sw         $s0, 0x10($sp)
    /* 36BC 80066A1C 1000838E */  lw         $v1, 0x10($s4)
    /* 36C0 80066A20 01000224 */  addiu      $v0, $zero, 0x1
    /* 36C4 80066A24 12006210 */  beq        $v1, $v0, .L80066A70
    /* 36C8 80066A28 02006228 */   slti      $v0, $v1, 0x2
    /* 36CC 80066A2C BE004010 */  beqz       $v0, .L80066D28
    /* 36D0 80066A30 00000000 */   nop
    /* 36D4 80066A34 BC006014 */  bnez       $v1, .L80066D28
    /* 36D8 80066A38 02000224 */   addiu     $v0, $zero, 0x2
    /* 36DC 80066A3C 0200043C */  lui        $a0, (0x25800 >> 16)
    /* 36E0 80066A40 00588434 */  ori        $a0, $a0, (0x25800 & 0xFFFF)
    /* 36E4 80066A44 2C00838E */  lw         $v1, 0x2C($s4)
    /* 36E8 80066A48 6C72000C */  jal        Gpu_AllocPacketBufs
    /* 36EC 80066A4C 000062AC */   sw        $v0, 0x0($v1)
    /* 36F0 80066A50 0A9A010C */  jal        Stg00_GroupViewSetVideoMode
    /* 36F4 80066A54 21208002 */   addu      $a0, $s4, $zero
    /* 36F8 80066A58 359A010C */  jal        Stg00_SpawnRandomGroup
    /* 36FC 80066A5C 21208002 */   addu      $a0, $s4, $zero
    /* 3700 80066A60 5145000C */  jal        Task_NextState0
    /* 3704 80066A64 21208002 */   addu      $a0, $s4, $zero
    /* 3708 80066A68 4A9B0108 */  j          .L80066D28
    /* 370C 80066A6C 00000000 */   nop
  .L80066A70:
    /* 3710 80066A70 2C00938E */  lw         $s3, 0x2C($s4)
    /* 3714 80066A74 4CA2010C */  jal        Stg00_FindCamera
    /* 3718 80066A78 21900000 */   addu      $s2, $zero, $zero
    /* 371C 80066A7C 0680033C */  lui        $v1, %hi(Sys_State)
    /* 3720 80066A80 70F76424 */  addiu      $a0, $v1, %lo(Sys_State)
    /* 3724 80066A84 0800838C */  lw         $v1, 0x8($a0)
    /* 3728 80066A88 00000000 */  nop
    /* 372C 80066A8C 4D006018 */  blez       $v1, .L80066BC4
    /* 3730 80066A90 21804000 */   addu      $s0, $v0, $zero
    /* 3734 80066A94 0680153C */  lui        $s5, %hi(Pad_State)
    /* 3738 80066A98 F0F6B126 */  addiu      $s1, $s5, %lo(Pad_State)
    /* 373C 80066A9C 21B08000 */  addu       $s6, $a0, $zero
  .L80066AA0:
    /* 3740 80066AA0 F0F6A28E */  lw         $v0, %lo(Pad_State)($s5)
    /* 3744 80066AA4 00000000 */  nop
    /* 3748 80066AA8 04004010 */  beqz       $v0, .L80066ABC
    /* 374C 80066AAC 21200002 */   addu      $a0, $s0, $zero
    /* 3750 80066AB0 21280000 */  addu       $a1, $zero, $zero
    /* 3754 80066AB4 B49A0108 */  j          .L80066AD0
    /* 3758 80066AB8 20000624 */   addiu     $a2, $zero, 0x20
  .L80066ABC:
    /* 375C 80066ABC 0400228E */  lw         $v0, 0x4($s1)
    /* 3760 80066AC0 00000000 */  nop
    /* 3764 80066AC4 04004010 */  beqz       $v0, .L80066AD8
    /* 3768 80066AC8 21280000 */   addu      $a1, $zero, $zero
    /* 376C 80066ACC E0FF0624 */  addiu      $a2, $zero, -0x20
  .L80066AD0:
    /* 3770 80066AD0 91A2010C */  jal        Stg00_CamRotate
    /* 3774 80066AD4 2138A000 */   addu      $a3, $a1, $zero
  .L80066AD8:
    /* 3778 80066AD8 0800228E */  lw         $v0, 0x8($s1)
    /* 377C 80066ADC 00000000 */  nop
    /* 3780 80066AE0 0A004010 */  beqz       $v0, .L80066B0C
    /* 3784 80066AE4 21200002 */   addu      $a0, $s0, $zero
    /* 3788 80066AE8 21280000 */  addu       $a1, $zero, $zero
    /* 378C 80066AEC 2130A000 */  addu       $a2, $a1, $zero
    /* 3790 80066AF0 56A2010C */  jal        Stg00_CamMoveViewPoint
    /* 3794 80066AF4 E0FF0724 */   addiu     $a3, $zero, -0x20
    /* 3798 80066AF8 21200002 */  addu       $a0, $s0, $zero
    /* 379C 80066AFC 21280000 */  addu       $a1, $zero, $zero
    /* 37A0 80066B00 2130A000 */  addu       $a2, $a1, $zero
    /* 37A4 80066B04 CE9A0108 */  j          .L80066B38
    /* 37A8 80066B08 E0FF0724 */   addiu     $a3, $zero, -0x20
  .L80066B0C:
    /* 37AC 80066B0C 0C00228E */  lw         $v0, 0xC($s1)
    /* 37B0 80066B10 00000000 */  nop
    /* 37B4 80066B14 0A004010 */  beqz       $v0, .L80066B40
    /* 37B8 80066B18 21280000 */   addu      $a1, $zero, $zero
    /* 37BC 80066B1C 2130A000 */  addu       $a2, $a1, $zero
    /* 37C0 80066B20 56A2010C */  jal        Stg00_CamMoveViewPoint
    /* 37C4 80066B24 20000724 */   addiu     $a3, $zero, 0x20
    /* 37C8 80066B28 21200002 */  addu       $a0, $s0, $zero
    /* 37CC 80066B2C 21280000 */  addu       $a1, $zero, $zero
    /* 37D0 80066B30 2130A000 */  addu       $a2, $a1, $zero
    /* 37D4 80066B34 20000724 */  addiu      $a3, $zero, 0x20
  .L80066B38:
    /* 37D8 80066B38 67A2010C */  jal        Stg00_CamMoveRefPoint
    /* 37DC 80066B3C 00000000 */   nop
  .L80066B40:
    /* 37E0 80066B40 1C00228E */  lw         $v0, 0x1C($s1)
    /* 37E4 80066B44 00000000 */  nop
    /* 37E8 80066B48 04004010 */  beqz       $v0, .L80066B5C
    /* 37EC 80066B4C 21200002 */   addu      $a0, $s0, $zero
    /* 37F0 80066B50 21280000 */  addu       $a1, $zero, $zero
    /* 37F4 80066B54 DC9A0108 */  j          .L80066B70
    /* 37F8 80066B58 E0FF0624 */   addiu     $a2, $zero, -0x20
  .L80066B5C:
    /* 37FC 80066B5C 1400228E */  lw         $v0, 0x14($s1)
    /* 3800 80066B60 00000000 */  nop
    /* 3804 80066B64 04004010 */  beqz       $v0, .L80066B78
    /* 3808 80066B68 21280000 */   addu      $a1, $zero, $zero
    /* 380C 80066B6C 20000624 */  addiu      $a2, $zero, 0x20
  .L80066B70:
    /* 3810 80066B70 56A2010C */  jal        Stg00_CamMoveViewPoint
    /* 3814 80066B74 2138A000 */   addu      $a3, $a1, $zero
  .L80066B78:
    /* 3818 80066B78 2000228E */  lw         $v0, 0x20($s1)
    /* 381C 80066B7C 00000000 */  nop
    /* 3820 80066B80 04004010 */  beqz       $v0, .L80066B94
    /* 3824 80066B84 21200002 */   addu      $a0, $s0, $zero
    /* 3828 80066B88 21280000 */  addu       $a1, $zero, $zero
    /* 382C 80066B8C EA9A0108 */  j          .L80066BA8
    /* 3830 80066B90 E0FF0624 */   addiu     $a2, $zero, -0x20
  .L80066B94:
    /* 3834 80066B94 2800228E */  lw         $v0, 0x28($s1)
    /* 3838 80066B98 00000000 */  nop
    /* 383C 80066B9C 04004010 */  beqz       $v0, .L80066BB0
    /* 3840 80066BA0 21280000 */   addu      $a1, $zero, $zero
    /* 3844 80066BA4 20000624 */  addiu      $a2, $zero, 0x20
  .L80066BA8:
    /* 3848 80066BA8 67A2010C */  jal        Stg00_CamMoveRefPoint
    /* 384C 80066BAC 2138A000 */   addu      $a3, $a1, $zero
  .L80066BB0:
    /* 3850 80066BB0 0800C28E */  lw         $v0, 0x8($s6)
    /* 3854 80066BB4 01005226 */  addiu      $s2, $s2, 0x1
    /* 3858 80066BB8 2A104202 */  slt        $v0, $s2, $v0
    /* 385C 80066BBC B8FF4014 */  bnez       $v0, .L80066AA0
    /* 3860 80066BC0 00000000 */   nop
  .L80066BC4:
    /* 3864 80066BC4 0680023C */  lui        $v0, %hi(Pad_Square)
    /* 3868 80066BC8 08F7428C */  lw         $v0, %lo(Pad_Square)($v0)
    /* 386C 80066BCC 00000000 */  nop
    /* 3870 80066BD0 2E004018 */  blez       $v0, .L80066C8C
    /* 3874 80066BD4 07000324 */   addiu     $v1, $zero, 0x7
    /* 3878 80066BD8 0800628E */  lw         $v0, 0x8($s3)
    /* 387C 80066BDC 00000000 */  nop
    /* 3880 80066BE0 01004224 */  addiu      $v0, $v0, 0x1
    /* 3884 80066BE4 02004314 */  bne        $v0, $v1, .L80066BF0
    /* 3888 80066BE8 080062AE */   sw        $v0, 0x8($s3)
    /* 388C 80066BEC 080060AE */  sw         $zero, 0x8($s3)
  .L80066BF0:
    /* 3890 80066BF0 0800638E */  lw         $v1, 0x8($s3)
    /* 3894 80066BF4 00000000 */  nop
    /* 3898 80066BF8 0700622C */  sltiu      $v0, $v1, 0x7
    /* 389C 80066BFC 08004010 */  beqz       $v0, .L80066C20
    /* 38A0 80066C00 0680023C */   lui       $v0, %hi(jtbl_8006340C)
    /* 38A4 80066C04 0C344224 */  addiu      $v0, $v0, %lo(jtbl_8006340C)
    /* 38A8 80066C08 80180300 */  sll        $v1, $v1, 2
    /* 38AC 80066C0C 21186200 */  addu       $v1, $v1, $v0
    /* 38B0 80066C10 0000628C */  lw         $v0, 0x0($v1)
    /* 38B4 80066C14 00000000 */  nop
    /* 38B8 80066C18 08004000 */  jr         $v0
    /* 38BC 80066C1C 00000000 */   nop
  jlabel .L80066C20
    /* 38C0 80066C20 21200002 */  addu       $a0, $s0, $zero
    /* 38C4 80066C24 000A0524 */  addiu      $a1, $zero, 0xA00
    /* 38C8 80066C28 21300000 */  addu       $a2, $zero, $zero
    /* 38CC 80066C2C 219B0108 */  j          .L80066C84
    /* 38D0 80066C30 00EC0724 */   addiu     $a3, $zero, -0x1400
  jlabel .L80066C34
    /* 38D4 80066C34 21200002 */  addu       $a0, $s0, $zero
    /* 38D8 80066C38 00F60524 */  addiu      $a1, $zero, -0xA00
    /* 38DC 80066C3C 21300000 */  addu       $a2, $zero, $zero
    /* 38E0 80066C40 219B0108 */  j          .L80066C84
    /* 38E4 80066C44 00EC0724 */   addiu     $a3, $zero, -0x1400
  jlabel .L80066C48
    /* 38E8 80066C48 21200002 */  addu       $a0, $s0, $zero
    /* 38EC 80066C4C 1F9B0108 */  j          .L80066C7C
    /* 38F0 80066C50 000A0524 */   addiu     $a1, $zero, 0xA00
  jlabel .L80066C54
    /* 38F4 80066C54 21200002 */  addu       $a0, $s0, $zero
    /* 38F8 80066C58 1F9B0108 */  j          .L80066C7C
    /* 38FC 80066C5C 000A0524 */   addiu     $a1, $zero, 0xA00
  jlabel .L80066C60
    /* 3900 80066C60 21200002 */  addu       $a0, $s0, $zero
    /* 3904 80066C64 21280000 */  addu       $a1, $zero, $zero
    /* 3908 80066C68 2130A000 */  addu       $a2, $a1, $zero
    /* 390C 80066C6C 219B0108 */  j          .L80066C84
    /* 3910 80066C70 00280724 */   addiu     $a3, $zero, 0x2800
  jlabel .L80066C74
    /* 3914 80066C74 21200002 */  addu       $a0, $s0, $zero
    /* 3918 80066C78 00F60524 */  addiu      $a1, $zero, -0xA00
  .L80066C7C:
    /* 391C 80066C7C 21300000 */  addu       $a2, $zero, $zero
    /* 3920 80066C80 2138C000 */  addu       $a3, $a2, $zero
  .L80066C84:
    /* 3924 80066C84 80A2010C */  jal        Stg00_CamMoveOrigin
    /* 3928 80066C88 00000000 */   nop
  .L80066C8C:
    /* 392C 80066C8C 0680023C */  lui        $v0, %hi(Pad_Select)
    /* 3930 80066C90 20F7428C */  lw         $v0, %lo(Pad_Select)($v0)
    /* 3934 80066C94 00000000 */  nop
    /* 3938 80066C98 0A004018 */  blez       $v0, .L80066CC4
    /* 393C 80066C9C 03000224 */   addiu     $v0, $zero, 0x3
    /* 3940 80066CA0 0000638E */  lw         $v1, 0x0($s3)
    /* 3944 80066CA4 00000000 */  nop
    /* 3948 80066CA8 03006210 */  beq        $v1, $v0, .L80066CB8
    /* 394C 80066CAC 01006224 */   addiu     $v0, $v1, 0x1
    /* 3950 80066CB0 2F9B0108 */  j          .L80066CBC
    /* 3954 80066CB4 000062AE */   sw        $v0, 0x0($s3)
  .L80066CB8:
    /* 3958 80066CB8 000060AE */  sw         $zero, 0x0($s3)
  .L80066CBC:
    /* 395C 80066CBC 0A9A010C */  jal        Stg00_GroupViewSetVideoMode
    /* 3960 80066CC0 21208002 */   addu      $a0, $s4, $zero
  .L80066CC4:
    /* 3964 80066CC4 0680023C */  lui        $v0, %hi(Pad_State)
    /* 3968 80066CC8 F0F65024 */  addiu      $s0, $v0, %lo(Pad_State)
    /* 396C 80066CCC 3400028E */  lw         $v0, 0x34($s0)
    /* 3970 80066CD0 00000000 */  nop
    /* 3974 80066CD4 03004018 */  blez       $v0, .L80066CE4
    /* 3978 80066CD8 00000000 */   nop
    /* 397C 80066CDC 359A010C */  jal        Stg00_SpawnRandomGroup
    /* 3980 80066CE0 21208002 */   addu      $a0, $s4, $zero
  .L80066CE4:
    /* 3984 80066CE4 1000028E */  lw         $v0, 0x10($s0)
    /* 3988 80066CE8 00000000 */  nop
    /* 398C 80066CEC 07004018 */  blez       $v0, .L80066D0C
    /* 3990 80066CF0 04000324 */   addiu     $v1, $zero, 0x4
    /* 3994 80066CF4 0C00628E */  lw         $v0, 0xC($s3)
    /* 3998 80066CF8 00000000 */  nop
    /* 399C 80066CFC 01004224 */  addiu      $v0, $v0, 0x1
    /* 39A0 80066D00 02004314 */  bne        $v0, $v1, .L80066D0C
    /* 39A4 80066D04 0C0062AE */   sw        $v0, 0xC($s3)
    /* 39A8 80066D08 0C0060AE */  sw         $zero, 0xC($s3)
  .L80066D0C:
    /* 39AC 80066D0C 0680023C */  lui        $v0, %hi(Pad_R2)
    /* 39B0 80066D10 14F7428C */  lw         $v0, %lo(Pad_R2)($v0)
    /* 39B4 80066D14 00000000 */  nop
    /* 39B8 80066D18 03004018 */  blez       $v0, .L80066D28
    /* 39BC 80066D1C 0680033C */   lui       $v1, %hi(Sys_NextGameMode)
    /* 39C0 80066D20 02010224 */  addiu      $v0, $zero, 0x102
    /* 39C4 80066D24 8CF762AC */  sw         $v0, %lo(Sys_NextGameMode)($v1)
  .L80066D28:
    /* 39C8 80066D28 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 39CC 80066D2C 2800B68F */  lw         $s6, 0x28($sp)
    /* 39D0 80066D30 2400B58F */  lw         $s5, 0x24($sp)
    /* 39D4 80066D34 2000B48F */  lw         $s4, 0x20($sp)
    /* 39D8 80066D38 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 39DC 80066D3C 1800B28F */  lw         $s2, 0x18($sp)
    /* 39E0 80066D40 1400B18F */  lw         $s1, 0x14($sp)
    /* 39E4 80066D44 1000B08F */  lw         $s0, 0x10($sp)
    /* 39E8 80066D48 0800E003 */  jr         $ra
    /* 39EC 80066D4C 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel Stg00_GroupViewTask
