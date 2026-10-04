nonmatching Stg11_StateVsPartySelect, 0x2C4

glabel Stg11_StateVsPartySelect
    /* 2840 80065BA0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2844 80065BA4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2848 80065BA8 21908000 */  addu       $s2, $a0, $zero
    /* 284C 80065BAC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2850 80065BB0 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 2854 80065BB4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2858 80065BB8 1800428E */  lw         $v0, 0x18($s2)
    /* 285C 80065BBC 3400508E */  lw         $s0, 0x34($s2)
    /* 2860 80065BC0 04004014 */  bnez       $v0, .L80065BD4
    /* 2864 80065BC4 2188A000 */   addu      $s1, $a1, $zero
    /* 2868 80065BC8 84002586 */  lh         $a1, 0x84($s1)
    /* 286C 80065BCC EB9D010C */  jal        Stg11_CardStartOp
    /* 2870 80065BD0 04000424 */   addiu     $a0, $zero, 0x4
  .L80065BD4:
    /* 2874 80065BD4 21204002 */  addu       $a0, $s2, $zero
    /* 2878 80065BD8 7E92010C */  jal        Stg11_WatchCardRemoved
    /* 287C 80065BDC 21282002 */   addu      $a1, $s1, $zero
    /* 2880 80065BE0 16004010 */  beqz       $v0, .L80065C3C
    /* 2884 80065BE4 01000224 */   addiu     $v0, $zero, 0x1
    /* 2888 80065BE8 0000048E */  lw         $a0, 0x0($s0)
    /* 288C 80065BEC 00000000 */  nop
    /* 2890 80065BF0 03008010 */  beqz       $a0, .L80065C00
    /* 2894 80065BF4 00000000 */   nop
    /* 2898 80065BF8 7045000C */  jal        Task_SetState0
    /* 289C 80065BFC 02000524 */   addiu     $a1, $zero, 0x2
  .L80065C00:
    /* 28A0 80065C00 280D043C */  lui        $a0, (0xD280006 >> 16)
    /* 28A4 80065C04 78002586 */  lh         $a1, 0x78($s1)
    /* 28A8 80065C08 06008434 */  ori        $a0, $a0, (0xD280006 & 0xFFFF)
    /* 28AC 80065C0C AC4E000C */  jal        Cd_GetFileEntrySubPtr
    /* 28B0 80065C10 FFFFA524 */   addiu     $a1, $a1, -0x1
    /* 28B4 80065C14 21202002 */  addu       $a0, $s1, $zero
    /* 28B8 80065C18 21284000 */  addu       $a1, $v0, $zero
    /* 28BC 80065C1C 564D000C */  jal        Text_PrintIdList
    /* 28C0 80065C20 21300000 */   addu      $a2, $zero, $zero
    /* 28C4 80065C24 21204002 */  addu       $a0, $s2, $zero
    /* 28C8 80065C28 2D92010C */  jal        Stg11_CloseSlotText
    /* 28CC 80065C2C 21282002 */   addu      $a1, $s1, $zero
    /* 28D0 80065C30 00100224 */  addiu      $v0, $zero, 0x1000
    /* 28D4 80065C34 93970108 */  j          .L80065E4C
    /* 28D8 80065C38 8C0022AE */   sw        $v0, 0x8C($s1)
  .L80065C3C:
    /* 28DC 80065C3C 1800438E */  lw         $v1, 0x18($s2)
    /* 28E0 80065C40 00000000 */  nop
    /* 28E4 80065C44 0C006210 */  beq        $v1, $v0, .L80065C78
    /* 28E8 80065C48 02006228 */   slti      $v0, $v1, 0x2
    /* 28EC 80065C4C 06004014 */  bnez       $v0, .L80065C68
    /* 28F0 80065C50 21202002 */   addu      $a0, $s1, $zero
    /* 28F4 80065C54 02000224 */  addiu      $v0, $zero, 0x2
    /* 28F8 80065C58 16006210 */  beq        $v1, $v0, .L80065CB4
    /* 28FC 80065C5C 03000224 */   addiu     $v0, $zero, 0x3
    /* 2900 80065C60 6A006210 */  beq        $v1, $v0, .L80065E0C
    /* 2904 80065C64 00000000 */   nop
  .L80065C68:
    /* 2908 80065C68 2C70000C */  jal        Text_CloseArray
    /* 290C 80065C6C 1A000524 */   addiu     $a1, $zero, 0x1A
    /* 2910 80065C70 7F970108 */  j          .L80065DFC
    /* 2914 80065C74 00000000 */   nop
  .L80065C78:
    /* 2918 80065C78 21204002 */  addu       $a0, $s2, $zero
    /* 291C 80065C7C C54D000C */  jal        Math_RampToZero
    /* 2920 80065C80 8C002526 */   addiu     $a1, $s1, 0x8C
    /* 2924 80065C84 71004014 */  bnez       $v0, .L80065E4C
    /* 2928 80065C88 05060424 */   addiu     $a0, $zero, 0x605
    /* 292C 80065C8C 7E002686 */  lh         $a2, 0x7E($s1)
    /* 2930 80065C90 21280002 */  addu       $a1, $s0, $zero
    /* 2934 80065C94 1F44000C */  jal        Task_Create
    /* 2938 80065C98 0100C624 */   addiu     $a2, $a2, 0x1
    /* 293C 80065C9C 21204002 */  addu       $a0, $s2, $zero
    /* 2940 80065CA0 0580023C */  lui        $v0, %hi(D_80050780)
    /* 2944 80065CA4 6045000C */  jal        Task_NextState2
    /* 2948 80065CA8 800740A4 */   sh        $zero, %lo(D_80050780)($v0)
    /* 294C 80065CAC 93970108 */  j          .L80065E4C
    /* 2950 80065CB0 00000000 */   nop
  .L80065CB4:
    /* 2954 80065CB4 0000028E */  lw         $v0, 0x0($s0)
    /* 2958 80065CB8 00000000 */  nop
    /* 295C 80065CBC 63004014 */  bnez       $v0, .L80065E4C
    /* 2960 80065CC0 0580023C */   lui       $v0, %hi(D_80050780)
    /* 2964 80065CC4 80074284 */  lh         $v0, %lo(D_80050780)($v0)
    /* 2968 80065CC8 00000000 */  nop
    /* 296C 80065CCC 4B004010 */  beqz       $v0, .L80065DFC
    /* 2970 80065CD0 21380000 */   addu      $a3, $zero, $zero
    /* 2974 80065CD4 0780023C */  lui        $v0, %hi(Stg11_VsParty)
    /* 2978 80065CD8 A8844624 */  addiu      $a2, $v0, %lo(Stg11_VsParty)
    /* 297C 80065CDC 7E002386 */  lh         $v1, 0x7E($s1)
    /* 2980 80065CE0 0580043C */  lui        $a0, %hi(Save_GameStatePtr)
    /* 2984 80065CE4 00110300 */  sll        $v0, $v1, 4
    /* 2988 80065CE8 21104300 */  addu       $v0, $v0, $v1
    /* 298C 80065CEC 80100200 */  sll        $v0, $v0, 2
    /* 2990 80065CF0 21104300 */  addu       $v0, $v0, $v1
    /* 2994 80065CF4 80100200 */  sll        $v0, $v0, 2
    /* 2998 80065CF8 2007838C */  lw         $v1, %lo(Save_GameStatePtr)($a0)
    /* 299C 80065CFC E4004224 */  addiu      $v0, $v0, 0xE4
    /* 29A0 80065D00 21186200 */  addu       $v1, $v1, $v0
  .L80065D04:
    /* 29A4 80065D04 21206000 */  addu       $a0, $v1, $zero
    /* 29A8 80065D08 0400C224 */  addiu      $v0, $a2, 0x4
    /* 29AC 80065D0C 5400C524 */  addiu      $a1, $a2, 0x54
  .L80065D10:
    /* 29B0 80065D10 0000488C */  lw         $t0, 0x0($v0)
    /* 29B4 80065D14 0400498C */  lw         $t1, 0x4($v0)
    /* 29B8 80065D18 08004A8C */  lw         $t2, 0x8($v0)
    /* 29BC 80065D1C 0C004B8C */  lw         $t3, 0xC($v0)
    /* 29C0 80065D20 000088AC */  sw         $t0, 0x0($a0)
    /* 29C4 80065D24 040089AC */  sw         $t1, 0x4($a0)
    /* 29C8 80065D28 08008AAC */  sw         $t2, 0x8($a0)
    /* 29CC 80065D2C 0C008BAC */  sw         $t3, 0xC($a0)
    /* 29D0 80065D30 10004224 */  addiu      $v0, $v0, 0x10
    /* 29D4 80065D34 F6FF4514 */  bne        $v0, $a1, .L80065D10
    /* 29D8 80065D38 10008424 */   addiu     $a0, $a0, 0x10
    /* 29DC 80065D3C 0000488C */  lw         $t0, 0x0($v0)
    /* 29E0 80065D40 0400498C */  lw         $t1, 0x4($v0)
    /* 29E4 80065D44 08004A8C */  lw         $t2, 0x8($v0)
    /* 29E8 80065D48 000088AC */  sw         $t0, 0x0($a0)
    /* 29EC 80065D4C 040089AC */  sw         $t1, 0x4($a0)
    /* 29F0 80065D50 08008AAC */  sw         $t2, 0x8($a0)
    /* 29F4 80065D54 00006290 */  lbu        $v0, 0x0($v1)
    /* 29F8 80065D58 00000000 */  nop
    /* 29FC 80065D5C 02004010 */  beqz       $v0, .L80065D68
    /* 2A00 80065D60 0300E224 */   addiu     $v0, $a3, 0x3
    /* 2A04 80065D64 000062A0 */  sb         $v0, 0x0($v1)
  .L80065D68:
    /* 2A08 80065D68 5C006324 */  addiu      $v1, $v1, 0x5C
    /* 2A0C 80065D6C 0100E724 */  addiu      $a3, $a3, 0x1
    /* 2A10 80065D70 0300E228 */  slti       $v0, $a3, 0x3
    /* 2A14 80065D74 E3FF4014 */  bnez       $v0, .L80065D04
    /* 2A18 80065D78 5C00C624 */   addiu     $a2, $a2, 0x5C
    /* 2A1C 80065D7C 0780023C */  lui        $v0, %hi(Stg11_VsParty)
    /* 2A20 80065D80 0580043C */  lui        $a0, %hi(Save_GameStatePtr)
    /* 2A24 80065D84 A884458C */  lw         $a1, %lo(Stg11_VsParty)($v0)
    /* 2A28 80065D88 7E002386 */  lh         $v1, 0x7E($s1)
    /* 2A2C 80065D8C 00000000 */  nop
    /* 2A30 80065D90 40100300 */  sll        $v0, $v1, 1
    /* 2A34 80065D94 21104300 */  addu       $v0, $v0, $v1
    /* 2A38 80065D98 C0100200 */  sll        $v0, $v0, 3
    /* 2A3C 80065D9C 23104300 */  subu       $v0, $v0, $v1
    /* 2A40 80065DA0 2007838C */  lw         $v1, %lo(Save_GameStatePtr)($a0)
    /* 2A44 80065DA4 80100200 */  sll        $v0, $v0, 2
    /* 2A48 80065DA8 21104300 */  addu       $v0, $v0, $v1
    /* 2A4C 80065DAC 58034424 */  addiu      $a0, $v0, 0x358
    /* 2A50 80065DB0 1400A390 */  lbu        $v1, 0x14($a1)
    /* 2A54 80065DB4 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 2A58 80065DB8 09006210 */  beq        $v1, $v0, .L80065DE0
    /* 2A5C 80065DBC 1400A624 */   addiu     $a2, $a1, 0x14
    /* 2A60 80065DC0 21184000 */  addu       $v1, $v0, $zero
  .L80065DC4:
    /* 2A64 80065DC4 0000C290 */  lbu        $v0, 0x0($a2)
    /* 2A68 80065DC8 0100C624 */  addiu      $a2, $a2, 0x1
    /* 2A6C 80065DCC 000082A0 */  sb         $v0, 0x0($a0)
    /* 2A70 80065DD0 0000C290 */  lbu        $v0, 0x0($a2)
    /* 2A74 80065DD4 00000000 */  nop
    /* 2A78 80065DD8 FAFF4314 */  bne        $v0, $v1, .L80065DC4
    /* 2A7C 80065DDC 01008424 */   addiu     $a0, $a0, 0x1
  .L80065DE0:
    /* 2A80 80065DE0 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 2A84 80065DE4 000082A0 */  sb         $v0, 0x0($a0)
    /* 2A88 80065DE8 21204002 */  addu       $a0, $s2, $zero
    /* 2A8C 80065DEC 7045000C */  jal        Task_SetState0
    /* 2A90 80065DF0 03000524 */   addiu     $a1, $zero, 0x3
    /* 2A94 80065DF4 93970108 */  j          .L80065E4C
    /* 2A98 80065DF8 00000000 */   nop
  .L80065DFC:
    /* 2A9C 80065DFC 6045000C */  jal        Task_NextState2
    /* 2AA0 80065E00 21204002 */   addu      $a0, $s2, $zero
    /* 2AA4 80065E04 93970108 */  j          .L80065E4C
    /* 2AA8 80065E08 00000000 */   nop
  .L80065E0C:
    /* 2AAC 80065E0C 21204002 */  addu       $a0, $s2, $zero
    /* 2AB0 80065E10 B94D000C */  jal        Math_RampToOne
    /* 2AB4 80065E14 8C002526 */   addiu     $a1, $s1, 0x8C
    /* 2AB8 80065E18 0C004014 */  bnez       $v0, .L80065E4C
    /* 2ABC 80065E1C 280D043C */   lui       $a0, (0xD280006 >> 16)
    /* 2AC0 80065E20 78002586 */  lh         $a1, 0x78($s1)
    /* 2AC4 80065E24 06008434 */  ori        $a0, $a0, (0xD280006 & 0xFFFF)
    /* 2AC8 80065E28 AC4E000C */  jal        Cd_GetFileEntrySubPtr
    /* 2ACC 80065E2C FFFFA524 */   addiu     $a1, $a1, -0x1
    /* 2AD0 80065E30 21202002 */  addu       $a0, $s1, $zero
    /* 2AD4 80065E34 21284000 */  addu       $a1, $v0, $zero
    /* 2AD8 80065E38 564D000C */  jal        Text_PrintIdList
    /* 2ADC 80065E3C 02000624 */   addiu     $a2, $zero, 0x2
    /* 2AE0 80065E40 21204002 */  addu       $a0, $s2, $zero
    /* 2AE4 80065E44 7745000C */  jal        Task_SetState1
    /* 2AE8 80065E48 07000524 */   addiu     $a1, $zero, 0x7
  .L80065E4C:
    /* 2AEC 80065E4C 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 2AF0 80065E50 1800B28F */  lw         $s2, 0x18($sp)
    /* 2AF4 80065E54 1400B18F */  lw         $s1, 0x14($sp)
    /* 2AF8 80065E58 1000B08F */  lw         $s0, 0x10($sp)
    /* 2AFC 80065E5C 0800E003 */  jr         $ra
    /* 2B00 80065E60 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg11_StateVsPartySelect
