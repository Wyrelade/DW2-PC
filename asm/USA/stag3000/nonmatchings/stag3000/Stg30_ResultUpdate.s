nonmatching Stg30_ResultUpdate, 0x2C0

glabel Stg30_ResultUpdate
    /* E5BC 8007191C A0FFBD27 */  addiu      $sp, $sp, -0x60
    /* E5C0 80071920 5800B6AF */  sw         $s6, 0x58($sp)
    /* E5C4 80071924 21B08000 */  addu       $s6, $a0, $zero
    /* E5C8 80071928 01000224 */  addiu      $v0, $zero, 0x1
    /* E5CC 8007192C 5C00BFAF */  sw         $ra, 0x5C($sp)
    /* E5D0 80071930 5400B5AF */  sw         $s5, 0x54($sp)
    /* E5D4 80071934 5000B4AF */  sw         $s4, 0x50($sp)
    /* E5D8 80071938 4C00B3AF */  sw         $s3, 0x4C($sp)
    /* E5DC 8007193C 4800B2AF */  sw         $s2, 0x48($sp)
    /* E5E0 80071940 4400B1AF */  sw         $s1, 0x44($sp)
    /* E5E4 80071944 4000B0AF */  sw         $s0, 0x40($sp)
    /* E5E8 80071948 1000C38E */  lw         $v1, 0x10($s6)
    /* E5EC 8007194C 2C00D28E */  lw         $s2, 0x2C($s6)
    /* E5F0 80071950 3F006210 */  beq        $v1, $v0, .L80071A50
    /* E5F4 80071954 02006228 */   slti      $v0, $v1, 0x2
    /* E5F8 80071958 96004010 */  beqz       $v0, .L80071BB4
    /* E5FC 8007195C 00000000 */   nop
    /* E600 80071960 94006014 */  bnez       $v1, .L80071BB4
    /* E604 80071964 24004426 */   addiu     $a0, $s2, 0x24
    /* E608 80071968 2270000C */  jal        Mem_FillWordsNeg1
    /* E60C 8007196C 0E000524 */   addiu     $a1, $zero, 0xE
    /* E610 80071970 21A80000 */  addu       $s5, $zero, $zero
    /* E614 80071974 0780023C */  lui        $v0, %hi(Stg30_Battle)
    /* E618 80071978 C03C4224 */  addiu      $v0, $v0, %lo(Stg30_Battle)
    /* E61C 8007197C 21884000 */  addu       $s1, $v0, $zero
    /* E620 80071980 18003426 */  addiu      $s4, $s1, 0x18
    /* E624 80071984 21984002 */  addu       $s3, $s2, $zero
    /* E628 80071988 21802002 */  addu       $s0, $s1, $zero
  .L8007198C:
    /* E62C 8007198C 2E000286 */  lh         $v0, 0x2E($s0)
    /* E630 80071990 00000000 */  nop
    /* E634 80071994 06004010 */  beqz       $v0, .L800719B0
    /* E638 80071998 00000000 */   nop
    /* E63C 8007199C 2800028E */  lw         $v0, 0x28($s0)
    /* E640 800719A0 0000438E */  lw         $v1, 0x0($s2)
    /* E644 800719A4 00000000 */  nop
    /* E648 800719A8 21104300 */  addu       $v0, $v0, $v1
    /* E64C 800719AC 280002AE */  sw         $v0, 0x28($s0)
  .L800719B0:
    /* E650 800719B0 25000492 */  lbu        $a0, 0x25($s0)
    /* E654 800719B4 27000592 */  lbu        $a1, 0x27($s0)
    /* E658 800719B8 2800068E */  lw         $a2, 0x28($s0)
    /* E65C 800719BC 617A000C */  jal        Digi_GetExpToNextLevel
    /* E660 800719C0 00000000 */   nop
    /* E664 800719C4 0A004014 */  bnez       $v0, .L800719F0
    /* E668 800719C8 180062AE */   sw        $v0, 0x18($s3)
    /* E66C 800719CC 2E000286 */  lh         $v0, 0x2E($s0)
    /* E670 800719D0 00000000 */  nop
    /* E674 800719D4 06004010 */  beqz       $v0, .L800719F0
    /* E678 800719D8 01000224 */   addiu     $v0, $zero, 0x1
    /* E67C 800719DC 4C0322A2 */  sb         $v0, 0x34C($s1)
    /* E680 800719E0 4EC5010C */  jal        Stg30_LevelUpStats
    /* E684 800719E4 21208002 */   addu      $a0, $s4, $zero
    /* E688 800719E8 7EC60108 */  j          .L800719F8
    /* E68C 800719EC 01003126 */   addiu     $s1, $s1, 0x1
  .L800719F0:
    /* E690 800719F0 4C0320A2 */  sb         $zero, 0x34C($s1)
    /* E694 800719F4 01003126 */  addiu      $s1, $s1, 0x1
  .L800719F8:
    /* E698 800719F8 5C009426 */  addiu      $s4, $s4, 0x5C
    /* E69C 800719FC 04007326 */  addiu      $s3, $s3, 0x4
    /* E6A0 80071A00 0100B526 */  addiu      $s5, $s5, 0x1
    /* E6A4 80071A04 0300A22A */  slti       $v0, $s5, 0x3
    /* E6A8 80071A08 E0FF4014 */  bnez       $v0, .L8007198C
    /* E6AC 80071A0C 5C001026 */   addiu     $s0, $s0, 0x5C
    /* E6B0 80071A10 F505053C */  lui        $a1, (0x5F5E0FF >> 16)
    /* E6B4 80071A14 0680023C */  lui        $v0, %hi(Save_GameState)
    /* E6B8 80071A18 20E64424 */  addiu      $a0, $v0, %lo(Save_GameState)
    /* E6BC 80071A1C 0800828C */  lw         $v0, 0x8($a0)
    /* E6C0 80071A20 0400438E */  lw         $v1, 0x4($s2)
    /* E6C4 80071A24 FFE0A534 */  ori        $a1, $a1, (0x5F5E0FF & 0xFFFF)
    /* E6C8 80071A28 21104300 */  addu       $v0, $v0, $v1
    /* E6CC 80071A2C 080082AC */  sw         $v0, 0x8($a0)
    /* E6D0 80071A30 2A10A200 */  slt        $v0, $a1, $v0
    /* E6D4 80071A34 02004010 */  beqz       $v0, .L80071A40
    /* E6D8 80071A38 00000000 */   nop
    /* E6DC 80071A3C 080085AC */  sw         $a1, 0x8($a0)
  .L80071A40:
    /* E6E0 80071A40 5145000C */  jal        Task_NextState0
    /* E6E4 80071A44 2120C002 */   addu      $a0, $s6, $zero
    /* E6E8 80071A48 EDC60108 */  j          .L80071BB4
    /* E6EC 80071A4C 00000000 */   nop
  .L80071A50:
    /* E6F0 80071A50 1400C28E */  lw         $v0, 0x14($s6)
    /* E6F4 80071A54 00000000 */  nop
    /* E6F8 80071A58 03004010 */  beqz       $v0, .L80071A68
    /* E6FC 80071A5C 21880000 */   addu      $s1, $zero, $zero
    /* E700 80071A60 4E004310 */  beq        $v0, $v1, .L80071B9C
    /* E704 80071A64 0680023C */   lui       $v0, %hi(D_8005F704)
  .L80071A68:
    /* E708 80071A68 0780023C */  lui        $v0, %hi(Stg30_Battle)
    /* E70C 80071A6C C03C5324 */  addiu      $s3, $v0, %lo(Stg30_Battle)
    /* E710 80071A70 0780023C */  lui        $v0, %hi(D_80073690)
    /* E714 80071A74 90365024 */  addiu      $s0, $v0, %lo(D_80073690)
  .L80071A78:
    /* E718 80071A78 00000392 */  lbu        $v1, 0x0($s0)
    /* E71C 80071A7C 09000224 */  addiu      $v0, $zero, 0x9
    /* E720 80071A80 0B006210 */  beq        $v1, $v0, .L80071AB0
    /* E724 80071A84 21106000 */   addu      $v0, $v1, $zero
    /* E728 80071A88 40180200 */  sll        $v1, $v0, 1
    /* E72C 80071A8C 21186200 */  addu       $v1, $v1, $v0
    /* E730 80071A90 C0180300 */  sll        $v1, $v1, 3
    /* E734 80071A94 23186200 */  subu       $v1, $v1, $v0
    /* E738 80071A98 80180300 */  sll        $v1, $v1, 2
    /* E73C 80071A9C 21187300 */  addu       $v1, $v1, $s3
    /* E740 80071AA0 19006290 */  lbu        $v0, 0x19($v1)
    /* E744 80071AA4 00000000 */  nop
    /* E748 80071AA8 35004010 */  beqz       $v0, .L80071B80
    /* E74C 80071AAC 00000000 */   nop
  .L80071AB0:
    /* E750 80071AB0 01000292 */  lbu        $v0, 0x1($s0)
    /* E754 80071AB4 00000000 */  nop
    /* E758 80071AB8 0300422C */  sltiu      $v0, $v0, 0x3
    /* E75C 80071ABC 0D004010 */  beqz       $v0, .L80071AF4
    /* E760 80071AC0 FD01043C */   lui       $a0, (0x1FD0000 >> 16)
    /* E764 80071AC4 01000292 */  lbu        $v0, 0x1($s0)
    /* E768 80071AC8 00000000 */  nop
    /* E76C 80071ACC 40180200 */  sll        $v1, $v0, 1
    /* E770 80071AD0 21186200 */  addu       $v1, $v1, $v0
    /* E774 80071AD4 C0180300 */  sll        $v1, $v1, 3
    /* E778 80071AD8 23186200 */  subu       $v1, $v1, $v0
    /* E77C 80071ADC 80180300 */  sll        $v1, $v1, 2
    /* E780 80071AE0 0780023C */  lui        $v0, %hi(D_80073D24)
    /* E784 80071AE4 243D4224 */  addiu      $v0, $v0, %lo(D_80073D24)
    /* E788 80071AE8 21186200 */  addu       $v1, $v1, $v0
    /* E78C 80071AEC C1C60108 */  j          .L80071B04
    /* E790 80071AF0 2400A3AF */   sw        $v1, 0x24($sp)
  .L80071AF4:
    /* E794 80071AF4 01000292 */  lbu        $v0, 0x1($s0)
    /* E798 80071AF8 688E000C */  jal        Cd_GetFileEntry
    /* E79C 80071AFC 25204400 */   or        $a0, $v0, $a0
    /* E7A0 80071B00 2400A2AF */  sw         $v0, 0x24($sp)
  .L80071B04:
    /* E7A4 80071B04 07000224 */  addiu      $v0, $zero, 0x7
    /* E7A8 80071B08 06002216 */  bne        $s1, $v0, .L80071B24
    /* E7AC 80071B0C 0D000224 */   addiu     $v0, $zero, 0xD
    /* E7B0 80071B10 0000458E */  lw         $a1, 0x0($s2)
    /* E7B4 80071B14 22C5010C */  jal        Stg30_NumToDigits
    /* E7B8 80071B18 08004426 */   addiu     $a0, $s2, 0x8
    /* E7BC 80071B1C 2C00A2AF */  sw         $v0, 0x2C($sp)
    /* E7C0 80071B20 0D000224 */  addiu      $v0, $zero, 0xD
  .L80071B24:
    /* E7C4 80071B24 06002216 */  bne        $s1, $v0, .L80071B40
    /* E7C8 80071B28 80201100 */   sll       $a0, $s1, 2
    /* E7CC 80071B2C 0400458E */  lw         $a1, 0x4($s2)
    /* E7D0 80071B30 22C5010C */  jal        Stg30_NumToDigits
    /* E7D4 80071B34 10004426 */   addiu     $a0, $s2, 0x10
    /* E7D8 80071B38 2C00A2AF */  sw         $v0, 0x2C($sp)
    /* E7DC 80071B3C 80201100 */  sll        $a0, $s1, 2
  .L80071B40:
    /* E7E0 80071B40 24008424 */  addiu      $a0, $a0, 0x24
    /* E7E4 80071B44 03000292 */  lbu        $v0, 0x3($s0)
    /* E7E8 80071B48 21204402 */  addu       $a0, $s2, $a0
    /* E7EC 80071B4C 1000A2AF */  sw         $v0, 0x10($sp)
    /* E7F0 80071B50 02000292 */  lbu        $v0, 0x2($s0)
    /* E7F4 80071B54 1000A527 */  addiu      $a1, $sp, 0x10
    /* E7F8 80071B58 1400A2AF */  sw         $v0, 0x14($sp)
    /* E7FC 80071B5C 0700078A */  lwl        $a3, 0x7($s0)
    /* E800 80071B60 0400079A */  lwr        $a3, 0x4($s0)
    /* E804 80071B64 00000000 */  nop
    /* E808 80071B68 1B00A7AB */  swl        $a3, 0x1B($sp)
    /* E80C 80071B6C 1800A7BB */  swr        $a3, 0x18($sp)
    /* E810 80071B70 1C00A0AF */  sw         $zero, 0x1C($sp)
    /* E814 80071B74 2000A0AF */  sw         $zero, 0x20($sp)
    /* E818 80071B78 096F000C */  jal        Text_Open
    /* E81C 80071B7C 2800A0AF */   sw        $zero, 0x28($sp)
  .L80071B80:
    /* E820 80071B80 01003126 */  addiu      $s1, $s1, 0x1
    /* E824 80071B84 0E00222A */  slti       $v0, $s1, 0xE
    /* E828 80071B88 BBFF4014 */  bnez       $v0, .L80071A78
    /* E82C 80071B8C 08001026 */   addiu     $s0, $s0, 0x8
    /* E830 80071B90 5945000C */  jal        Task_NextState1
    /* E834 80071B94 2120C002 */   addu      $a0, $s6, $zero
    /* E838 80071B98 0680023C */  lui        $v0, %hi(D_8005F704)
  .L80071B9C:
    /* E83C 80071B9C 04F7428C */  lw         $v0, %lo(D_8005F704)($v0)
    /* E840 80071BA0 00000000 */  nop
    /* E844 80071BA4 03004018 */  blez       $v0, .L80071BB4
    /* E848 80071BA8 2120C002 */   addu      $a0, $s6, $zero
    /* E84C 80071BAC 7045000C */  jal        Task_SetState0
    /* E850 80071BB0 03000524 */   addiu     $a1, $zero, 0x3
  .L80071BB4:
    /* E854 80071BB4 5C00BF8F */  lw         $ra, 0x5C($sp)
    /* E858 80071BB8 5800B68F */  lw         $s6, 0x58($sp)
    /* E85C 80071BBC 5400B58F */  lw         $s5, 0x54($sp)
    /* E860 80071BC0 5000B48F */  lw         $s4, 0x50($sp)
    /* E864 80071BC4 4C00B38F */  lw         $s3, 0x4C($sp)
    /* E868 80071BC8 4800B28F */  lw         $s2, 0x48($sp)
    /* E86C 80071BCC 4400B18F */  lw         $s1, 0x44($sp)
    /* E870 80071BD0 4000B08F */  lw         $s0, 0x40($sp)
    /* E874 80071BD4 0800E003 */  jr         $ra
    /* E878 80071BD8 6000BD27 */   addiu     $sp, $sp, 0x60
endlabel Stg30_ResultUpdate
