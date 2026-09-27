nonmatching Card_WriteDataTask, 0x1AC

glabel Card_WriteDataTask
    /* 2F130 8003E930 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2F134 8003E934 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2F138 8003E938 21888000 */  addu       $s1, $a0, $zero
    /* 2F13C 8003E93C 1800BFAF */  sw         $ra, 0x18($sp)
    /* 2F140 8003E940 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2F144 8003E944 0000238E */  lw         $v1, 0x0($s1)
    /* 2F148 8003E948 0A001024 */  addiu      $s0, $zero, 0xA
    /* 2F14C 8003E94C 14007010 */  beq        $v1, $s0, .L8003E9A0
    /* 2F150 8003E950 0B006228 */   slti      $v0, $v1, 0xB
    /* 2F154 8003E954 05004010 */  beqz       $v0, .L8003E96C
    /* 2F158 8003E958 1E000224 */   addiu     $v0, $zero, 0x1E
    /* 2F15C 8003E95C 09006010 */  beqz       $v1, .L8003E984
    /* 2F160 8003E960 21100000 */   addu      $v0, $zero, $zero
    /* 2F164 8003E964 B2FA0008 */  j          .L8003EAC8
    /* 2F168 8003E968 00000000 */   nop
  .L8003E96C:
    /* 2F16C 8003E96C 28006210 */  beq        $v1, $v0, .L8003EA10
    /* 2F170 8003E970 20000224 */   addiu     $v0, $zero, 0x20
    /* 2F174 8003E974 4C006210 */  beq        $v1, $v0, .L8003EAA8
    /* 2F178 8003E978 21100000 */   addu      $v0, $zero, $zero
    /* 2F17C 8003E97C B2FA0008 */  j          .L8003EAC8
    /* 2F180 8003E980 00000000 */   nop
  .L8003E984:
    /* 2F184 8003E984 0480043C */  lui        $a0, %hi(Card_InfoTask)
    /* 2F188 8003E988 18DE8424 */  addiu      $a0, $a0, %lo(Card_InfoTask)
    /* 2F18C 8003E98C 0580013C */  lui        $at, %hi(D_800506D4)
    /* 2F190 8003E990 89FE000C */  jal        Card_PushTask
    /* 2F194 8003E994 D40620AC */   sw        $zero, %lo(D_800506D4)($at)
    /* 2F198 8003E998 B1FA0008 */  j          .L8003EAC4
    /* 2F19C 8003E99C 000030AE */   sw        $s0, 0x0($s1)
  .L8003E9A0:
    /* 2F1A0 8003E9A0 0680043C */  lui        $a0, %hi(D_80062F84)
    /* 2F1A4 8003E9A4 842F8424 */  addiu      $a0, $a0, %lo(D_80062F84)
    /* 2F1A8 8003E9A8 0000828C */  lw         $v0, 0x0($a0)
    /* 2F1AC 8003E9AC 00000000 */  nop
    /* 2F1B0 8003E9B0 45004014 */  bnez       $v0, .L8003EAC8
    /* 2F1B4 8003E9B4 01000224 */   addiu     $v0, $zero, 0x1
    /* 2F1B8 8003E9B8 10009024 */  addiu      $s0, $a0, 0x10
  .L8003E9BC:
    /* 2F1BC 8003E9BC 0000048E */  lw         $a0, 0x0($s0)
    /* 2F1C0 8003E9C0 0400058E */  lw         $a1, 0x4($s0)
    /* 2F1C4 8003E9C4 61FD000C */  jal        lseek
    /* 2F1C8 8003E9C8 21300000 */   addu      $a2, $zero, $zero
    /* 2F1CC 8003E9CC 0400038E */  lw         $v1, 0x4($s0)
    /* 2F1D0 8003E9D0 00000000 */  nop
    /* 2F1D4 8003E9D4 F9FF4314 */  bne        $v0, $v1, .L8003E9BC
    /* 2F1D8 8003E9D8 00000000 */   nop
    /* 2F1DC 8003E9DC A9FF000C */  jal        Card_ClearEvents
    /* 2F1E0 8003E9E0 00000000 */   nop
    /* 2F1E4 8003E9E4 0680103C */  lui        $s0, %hi(D_80062F94)
    /* 2F1E8 8003E9E8 942F1026 */  addiu      $s0, $s0, %lo(D_80062F94)
  .L8003E9EC:
    /* 2F1EC 8003E9EC 0000048E */  lw         $a0, 0x0($s0)
    /* 2F1F0 8003E9F0 0C00058E */  lw         $a1, 0xC($s0)
    /* 2F1F4 8003E9F4 0800068E */  lw         $a2, 0x8($s0)
    /* 2F1F8 8003E9F8 69AA000C */  jal        write
    /* 2F1FC 8003E9FC 00000000 */   nop
    /* 2F200 8003EA00 FAFF4014 */  bnez       $v0, .L8003E9EC
    /* 2F204 8003EA04 1E000224 */   addiu     $v0, $zero, 0x1E
    /* 2F208 8003EA08 B1FA0008 */  j          .L8003EAC4
    /* 2F20C 8003EA0C 000022AE */   sw        $v0, 0x0($s1)
  .L8003EA10:
    /* 2F210 8003EA10 5700010C */  jal        Card_GetSwEventBits
    /* 2F214 8003EA14 00000000 */   nop
    /* 2F218 8003EA18 2B004010 */  beqz       $v0, .L8003EAC8
    /* 2F21C 8003EA1C 21100000 */   addu      $v0, $zero, $zero
    /* 2F220 8003EA20 EBFF000C */  jal        Card_WaitSwEvent
    /* 2F224 8003EA24 00000000 */   nop
    /* 2F228 8003EA28 21204000 */  addu       $a0, $v0, $zero
    /* 2F22C 8003EA2C 17008010 */  beqz       $a0, .L8003EA8C
    /* 2F230 8003EA30 00000000 */   nop
    /* 2F234 8003EA34 0580023C */  lui        $v0, %hi(D_800506D4)
    /* 2F238 8003EA38 D406428C */  lw         $v0, %lo(D_800506D4)($v0)
    /* 2F23C 8003EA3C 00000000 */  nop
    /* 2F240 8003EA40 01004224 */  addiu      $v0, $v0, 0x1
    /* 2F244 8003EA44 0580013C */  lui        $at, %hi(D_800506D4)
    /* 2F248 8003EA48 D40622AC */  sw         $v0, %lo(D_800506D4)($at)
    /* 2F24C 8003EA4C 04004228 */  slti       $v0, $v0, 0x4
    /* 2F250 8003EA50 03004010 */  beqz       $v0, .L8003EA60
    /* 2F254 8003EA54 04000224 */   addiu     $v0, $zero, 0x4
    /* 2F258 8003EA58 B1FA0008 */  j          .L8003EAC4
    /* 2F25C 8003EA5C 000030AE */   sw        $s0, 0x0($s1)
  .L8003EA60:
    /* 2F260 8003EA60 0A008214 */  bne        $a0, $v0, .L8003EA8C
    /* 2F264 8003EA64 00000000 */   nop
    /* 2F268 8003EA68 A9FF000C */  jal        Card_ClearEvents
    /* 2F26C 8003EA6C 00000000 */   nop
    /* 2F270 8003EA70 0680043C */  lui        $a0, %hi(D_80062F90)
    /* 2F274 8003EA74 902F848C */  lw         $a0, %lo(D_80062F90)($a0)
    /* 2F278 8003EA78 6DFE000C */  jal        _card_clear
    /* 2F27C 8003EA7C 00000000 */   nop
    /* 2F280 8003EA80 20000224 */  addiu      $v0, $zero, 0x20
    /* 2F284 8003EA84 B1FA0008 */  j          .L8003EAC4
    /* 2F288 8003EA88 000022AE */   sw        $v0, 0x0($s1)
  .L8003EA8C:
    /* 2F28C 8003EA8C 06FD000C */  jal        Card_EventToMcErr
    /* 2F290 8003EA90 00000000 */   nop
    /* 2F294 8003EA94 0680033C */  lui        $v1, %hi(D_80062F80)
    /* 2F298 8003EA98 802F6324 */  addiu      $v1, $v1, %lo(D_80062F80)
    /* 2F29C 8003EA9C 040062AC */  sw         $v0, 0x4($v1)
    /* 2F2A0 8003EAA0 B2FA0008 */  j          .L8003EAC8
    /* 2F2A4 8003EAA4 01000224 */   addiu     $v0, $zero, 0x1
  .L8003EAA8:
    /* 2F2A8 8003EAA8 6600010C */  jal        Card_GetHwEventBits
    /* 2F2AC 8003EAAC 00000000 */   nop
    /* 2F2B0 8003EAB0 05004010 */  beqz       $v0, .L8003EAC8
    /* 2F2B4 8003EAB4 21100000 */   addu      $v0, $zero, $zero
    /* 2F2B8 8003EAB8 2100010C */  jal        Card_WaitHwEvent
    /* 2F2BC 8003EABC 00000000 */   nop
    /* 2F2C0 8003EAC0 000020AE */  sw         $zero, 0x0($s1)
  .L8003EAC4:
    /* 2F2C4 8003EAC4 21100000 */  addu       $v0, $zero, $zero
  .L8003EAC8:
    /* 2F2C8 8003EAC8 1800BF8F */  lw         $ra, 0x18($sp)
    /* 2F2CC 8003EACC 1400B18F */  lw         $s1, 0x14($sp)
    /* 2F2D0 8003EAD0 1000B08F */  lw         $s0, 0x10($sp)
    /* 2F2D4 8003EAD4 0800E003 */  jr         $ra
    /* 2F2D8 8003EAD8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Card_WriteDataTask
