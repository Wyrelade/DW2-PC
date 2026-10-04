nonmatching Stg40_BitsWinUpdate, 0x194

glabel Stg40_BitsWinUpdate
    /* 3884 80066BE4 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 3888 80066BE8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 388C 80066BEC 21888000 */  addu       $s1, $a0, $zero
    /* 3890 80066BF0 01000424 */  addiu      $a0, $zero, 0x1
    /* 3894 80066BF4 1800BFAF */  sw         $ra, 0x18($sp)
    /* 3898 80066BF8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 389C 80066BFC 1000238E */  lw         $v1, 0x10($s1)
    /* 38A0 80066C00 2C00308E */  lw         $s0, 0x2C($s1)
    /* 38A4 80066C04 11006410 */  beq        $v1, $a0, .L80066C4C
    /* 38A8 80066C08 02006228 */   slti      $v0, $v1, 0x2
    /* 38AC 80066C0C 03004014 */  bnez       $v0, .L80066C1C
    /* 38B0 80066C10 02000224 */   addiu     $v0, $zero, 0x2
    /* 38B4 80066C14 40006210 */  beq        $v1, $v0, .L80066D18
    /* 38B8 80066C18 00000000 */   nop
  .L80066C1C:
    /* 38BC 80066C1C 21200002 */  addu       $a0, $s0, $zero
    /* 38C0 80066C20 2270000C */  jal        Mem_FillWordsNeg1
    /* 38C4 80066C24 01000524 */   addiu     $a1, $zero, 0x1
    /* 38C8 80066C28 0580023C */  lui        $v0, %hi(Save_GameStatePtr)
    /* 38CC 80066C2C 2007428C */  lw         $v0, %lo(Save_GameStatePtr)($v0)
    /* 38D0 80066C30 040000AE */  sw         $zero, 0x4($s0)
    /* 38D4 80066C34 0800428C */  lw         $v0, 0x8($v0)
    /* 38D8 80066C38 21202002 */  addu       $a0, $s1, $zero
    /* 38DC 80066C3C 5145000C */  jal        Task_NextState0
    /* 38E0 80066C40 080002AE */   sw        $v0, 0x8($s0)
    /* 38E4 80066C44 599B0108 */  j          .L80066D64
    /* 38E8 80066C48 00000000 */   nop
  .L80066C4C:
    /* 38EC 80066C4C 1400228E */  lw         $v0, 0x14($s1)
    /* 38F0 80066C50 00000000 */  nop
    /* 38F4 80066C54 03004010 */  beqz       $v0, .L80066C64
    /* 38F8 80066C58 00000000 */   nop
    /* 38FC 80066C5C 14004410 */  beq        $v0, $a0, .L80066CB0
    /* 3900 80066C60 0580023C */   lui       $v0, %hi(Save_GameStatePtr)
  .L80066C64:
    /* 3904 80066C64 21202002 */  addu       $a0, $s1, $zero
    /* 3908 80066C68 B94D000C */  jal        Math_RampToOne
    /* 390C 80066C6C 04000526 */   addiu     $a1, $s0, 0x4
    /* 3910 80066C70 3C004014 */  bnez       $v0, .L80066D64
    /* 3914 80066C74 21200002 */   addu      $a0, $s0, $zero
    /* 3918 80066C78 0780023C */  lui        $v0, %hi(Stg40_BitsLabelText)
    /* 391C 80066C7C E0264324 */  addiu      $v1, $v0, %lo(Stg40_BitsLabelText)
    /* 3920 80066C80 21300000 */  addu       $a2, $zero, $zero
    /* 3924 80066C84 06006794 */  lhu        $a3, 0x6($v1)
    /* 3928 80066C88 E026458C */  lw         $a1, %lo(Stg40_BitsLabelText)($v0)
    /* 392C 80066C8C 04006294 */  lhu        $v0, 0x4($v1)
    /* 3930 80066C90 003C0700 */  sll        $a3, $a3, 16
    /* 3934 80066C94 F26F000C */  jal        Text_OpenById
    /* 3938 80066C98 25384700 */   or        $a3, $v0, $a3
    /* 393C 80066C9C 0000048E */  lw         $a0, 0x0($s0)
    /* 3940 80066CA0 D66F000C */  jal        Text_SetOtLayer
    /* 3944 80066CA4 02000524 */   addiu     $a1, $zero, 0x2
    /* 3948 80066CA8 4F9B0108 */  j          .L80066D3C
    /* 394C 80066CAC 00000000 */   nop
  .L80066CB0:
    /* 3950 80066CB0 2007428C */  lw         $v0, %lo(Save_GameStatePtr)($v0)
    /* 3954 80066CB4 0800048E */  lw         $a0, 0x8($s0)
    /* 3958 80066CB8 0800438C */  lw         $v1, 0x8($v0)
    /* 395C 80066CBC 00000000 */  nop
    /* 3960 80066CC0 2A106400 */  slt        $v0, $v1, $a0
    /* 3964 80066CC4 06004010 */  beqz       $v0, .L80066CE0
    /* 3968 80066CC8 F6FF8424 */   addiu     $a0, $a0, -0xA
    /* 396C 80066CCC 2A108300 */  slt        $v0, $a0, $v1
    /* 3970 80066CD0 02004014 */  bnez       $v0, .L80066CDC
    /* 3974 80066CD4 00000000 */   nop
    /* 3978 80066CD8 21188000 */  addu       $v1, $a0, $zero
  .L80066CDC:
    /* 397C 80066CDC 080003AE */  sw         $v1, 0x8($s0)
  .L80066CE0:
    /* 3980 80066CE0 0580023C */  lui        $v0, %hi(Save_GameStatePtr)
    /* 3984 80066CE4 2007428C */  lw         $v0, %lo(Save_GameStatePtr)($v0)
    /* 3988 80066CE8 0800048E */  lw         $a0, 0x8($s0)
    /* 398C 80066CEC 0800438C */  lw         $v1, 0x8($v0)
    /* 3990 80066CF0 00000000 */  nop
    /* 3994 80066CF4 2A108300 */  slt        $v0, $a0, $v1
    /* 3998 80066CF8 1A004010 */  beqz       $v0, .L80066D64
    /* 399C 80066CFC 0A008424 */   addiu     $a0, $a0, 0xA
    /* 39A0 80066D00 2A106400 */  slt        $v0, $v1, $a0
    /* 39A4 80066D04 02004014 */  bnez       $v0, .L80066D10
    /* 39A8 80066D08 00000000 */   nop
    /* 39AC 80066D0C 21188000 */  addu       $v1, $a0, $zero
  .L80066D10:
    /* 39B0 80066D10 599B0108 */  j          .L80066D64
    /* 39B4 80066D14 080003AE */   sw        $v1, 0x8($s0)
  .L80066D18:
    /* 39B8 80066D18 1400228E */  lw         $v0, 0x14($s1)
    /* 39BC 80066D1C 00000000 */  nop
    /* 39C0 80066D20 03004010 */  beqz       $v0, .L80066D30
    /* 39C4 80066D24 00000000 */   nop
    /* 39C8 80066D28 08004410 */  beq        $v0, $a0, .L80066D4C
    /* 39CC 80066D2C 21202002 */   addu      $a0, $s1, $zero
  .L80066D30:
    /* 39D0 80066D30 21200002 */  addu       $a0, $s0, $zero
    /* 39D4 80066D34 2C70000C */  jal        Text_CloseArray
    /* 39D8 80066D38 01000524 */   addiu     $a1, $zero, 0x1
  .L80066D3C:
    /* 39DC 80066D3C 5945000C */  jal        Task_NextState1
    /* 39E0 80066D40 21202002 */   addu      $a0, $s1, $zero
    /* 39E4 80066D44 599B0108 */  j          .L80066D64
    /* 39E8 80066D48 00000000 */   nop
  .L80066D4C:
    /* 39EC 80066D4C C54D000C */  jal        Math_RampToZero
    /* 39F0 80066D50 04000526 */   addiu     $a1, $s0, 0x4
    /* 39F4 80066D54 03004014 */  bnez       $v0, .L80066D64
    /* 39F8 80066D58 21202002 */   addu      $a0, $s1, $zero
    /* 39FC 80066D5C 7045000C */  jal        Task_SetState0
    /* 3A00 80066D60 03000524 */   addiu     $a1, $zero, 0x3
  .L80066D64:
    /* 3A04 80066D64 1800BF8F */  lw         $ra, 0x18($sp)
    /* 3A08 80066D68 1400B18F */  lw         $s1, 0x14($sp)
    /* 3A0C 80066D6C 1000B08F */  lw         $s0, 0x10($sp)
    /* 3A10 80066D70 0800E003 */  jr         $ra
    /* 3A14 80066D74 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg40_BitsWinUpdate
