nonmatching Cd_ReadFileAsync, 0xB0

glabel Cd_ReadFileAsync
    /* 14A60 80024260 0580023C */  lui        $v0, %hi(D_80048DB8)
    /* 14A64 80024264 B88D428C */  lw         $v0, %lo(D_80048DB8)($v0)
    /* 14A68 80024268 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 14A6C 8002426C 1800B0AF */  sw         $s0, 0x18($sp)
    /* 14A70 80024270 21808000 */  addu       $s0, $a0, $zero
    /* 14A74 80024274 2000B2AF */  sw         $s2, 0x20($sp)
    /* 14A78 80024278 2190A000 */  addu       $s2, $a1, $zero
    /* 14A7C 8002427C 2400BFAF */  sw         $ra, 0x24($sp)
    /* 14A80 80024280 05004010 */  beqz       $v0, .L80024298
    /* 14A84 80024284 1C00B1AF */   sw        $s1, 0x1C($sp)
  .L80024288:
    /* 14A88 80024288 8890000C */  jal        Cd_PollRead
    /* 14A8C 8002428C 00000000 */   nop
    /* 14A90 80024290 FDFF4014 */  bnez       $v0, .L80024288
    /* 14A94 80024294 00000000 */   nop
  .L80024298:
    /* 14A98 80024298 21200002 */  addu       $a0, $s0, $zero
    /* 14A9C 8002429C F28F000C */  jal        Cd_GetFilePos
    /* 14AA0 800242A0 1000A527 */   addiu     $a1, $sp, 0x10
    /* 14AA4 800242A4 E48F000C */  jal        func_80023F90
    /* 14AA8 800242A8 21200002 */   addu      $a0, $s0, $zero
    /* 14AAC 800242AC 21200002 */  addu       $a0, $s0, $zero
    /* 14AB0 800242B0 0580113C */  lui        $s1, %hi(D_80048DB8)
    /* 14AB4 800242B4 B88D3026 */  addiu      $s0, $s1, %lo(D_80048DB8)
    /* 14AB8 800242B8 040002AE */  sw         $v0, 0x4($s0)
    /* 14ABC 800242BC 080012AE */  sw         $s2, 0x8($s0)
    /* 14AC0 800242C0 100002AE */  sw         $v0, 0x10($s0)
    /* 14AC4 800242C4 140004AE */  sw         $a0, 0x14($s0)
    /* 14AC8 800242C8 EB8F000C */  jal        Cd_GetFileLba
    /* 14ACC 800242CC 180012AE */   sw        $s2, 0x18($s0)
    /* 14AD0 800242D0 0280043C */  lui        $a0, %hi(func_800240E8)
    /* 14AD4 800242D4 B88D238E */  lw         $v1, %lo(D_80048DB8)($s1)
    /* 14AD8 800242D8 E8408424 */  addiu      $a0, $a0, %lo(func_800240E8)
    /* 14ADC 800242DC 1C0002AE */  sw         $v0, 0x1C($s0)
    /* 14AE0 800242E0 01006324 */  addiu      $v1, $v1, 0x1
    /* 14AE4 800242E4 45C1000C */  jal        CdSyncCallback
    /* 14AE8 800242E8 B88D23AE */   sw        $v1, %lo(D_80048DB8)($s1)
    /* 14AEC 800242EC 02000424 */  addiu      $a0, $zero, 0x2
    /* 14AF0 800242F0 A4C1000C */  jal        CdControlF
    /* 14AF4 800242F4 1000A527 */   addiu     $a1, $sp, 0x10
    /* 14AF8 800242F8 2400BF8F */  lw         $ra, 0x24($sp)
    /* 14AFC 800242FC 2000B28F */  lw         $s2, 0x20($sp)
    /* 14B00 80024300 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 14B04 80024304 1800B08F */  lw         $s0, 0x18($sp)
    /* 14B08 80024308 0800E003 */  jr         $ra
    /* 14B0C 8002430C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel Cd_ReadFileAsync
