nonmatching Snd_Init, 0x160

glabel Snd_Init
    /* AF5C 8001A75C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* AF60 8001A760 0580043C */  lui        $a0, %hi(Snd_SeqAttrTable)
    /* AF64 8001A764 480A8424 */  addiu      $a0, $a0, %lo(Snd_SeqAttrTable)
    /* AF68 8001A768 06000524 */  addiu      $a1, $zero, 0x6
    /* AF6C 8001A76C 10000624 */  addiu      $a2, $zero, 0x10
    /* AF70 8001A770 1800BFAF */  sw         $ra, 0x18($sp)
    /* AF74 8001A774 1400B1AF */  sw         $s1, 0x14($sp)
    /* AF78 8001A778 F9D5000C */  jal        SsSetTableSize
    /* AF7C 8001A77C 1000B0AF */   sw        $s0, 0x10($sp)
    /* AF80 8001A780 81D6000C */  jal        SsSetTickMode
    /* AF84 8001A784 00100424 */   addiu     $a0, $zero, 0x1000
    /* AF88 8001A788 B1D4000C */  jal        SsStart2
    /* AF8C 8001A78C 0480103C */   lui       $s0, %hi(Snd_SlotBufSizes)
    /* AF90 8001A790 7F000424 */  addiu      $a0, $zero, 0x7F
    /* AF94 8001A794 09D4000C */  jal        SsSetMVol
    /* AF98 8001A798 21288000 */   addu      $a1, $a0, $zero
    /* AF9C 8001A79C 21200000 */  addu       $a0, $zero, $zero
    /* AFA0 8001A7A0 21288000 */  addu       $a1, $a0, $zero
    /* AFA4 8001A7A4 D9D3000C */  jal        SsSetSerialAttr
    /* AFA8 8001A7A8 01000624 */   addiu     $a2, $zero, 0x1
    /* AFAC 8001A7AC 21200000 */  addu       $a0, $zero, $zero
    /* AFB0 8001A7B0 7F000524 */  addiu      $a1, $zero, 0x7F
    /* AFB4 8001A7B4 B5D5000C */  jal        SsSetSerialVol
    /* AFB8 8001A7B8 2130A000 */   addu      $a2, $a1, $zero
    /* AFBC 8001A7BC 1DD9000C */  jal        SsUtSetReverbType
    /* AFC0 8001A7C0 03000424 */   addiu     $a0, $zero, 0x3
    /* AFC4 8001A7C4 21200000 */  addu       $a0, $zero, $zero
    /* AFC8 8001A7C8 F9D8000C */  jal        SsUtSetReverbDepth
    /* AFCC 8001A7CC 21288000 */   addu      $a1, $a0, $zero
    /* AFD0 8001A7D0 5DD9000C */  jal        SsUtReverbOn
    /* AFD4 8001A7D4 FC111126 */   addiu     $s1, $s0, %lo(Snd_SlotBufSizes)
    /* AFD8 8001A7D8 04000524 */  addiu      $a1, $zero, 0x4
    /* AFDC 8001A7DC FC11048E */  lw         $a0, %lo(Snd_SlotBufSizes)($s0)
    /* AFE0 8001A7E0 0400228E */  lw         $v0, 0x4($s1)
    /* AFE4 8001A7E4 0800238E */  lw         $v1, 0x8($s1)
    /* AFE8 8001A7E8 21208200 */  addu       $a0, $a0, $v0
    /* AFEC 8001A7EC CF8B000C */  jal        Mem_Alloc
    /* AFF0 8001A7F0 21208300 */   addu      $a0, $a0, $v1
    /* AFF4 8001A7F4 21300000 */  addu       $a2, $zero, $zero
    /* AFF8 8001A7F8 FFFF0724 */  addiu      $a3, $zero, -0x1
    /* AFFC 8001A7FC 0580033C */  lui        $v1, %hi(Snd_Slots)
    /* B000 8001A800 484C6324 */  addiu      $v1, $v1, %lo(Snd_Slots)
    /* B004 8001A804 21286000 */  addu       $a1, $v1, $zero
    /* B008 8001A808 2800A2AC */  sw         $v0, 0x28($a1)
    /* B00C 8001A80C FC11038E */  lw         $v1, %lo(Snd_SlotBufSizes)($s0)
    /* B010 8001A810 0400248E */  lw         $a0, 0x4($s1)
    /* B014 8001A814 21104300 */  addu       $v0, $v0, $v1
    /* B018 8001A818 5400A2AC */  sw         $v0, 0x54($a1)
    /* B01C 8001A81C 21104400 */  addu       $v0, $v0, $a0
    /* B020 8001A820 8000A2AC */  sw         $v0, 0x80($a1)
  .L8001A824:
    /* B024 8001A824 0400A0AC */  sw         $zero, 0x4($a1)
    /* B028 8001A828 0000A7AC */  sw         $a3, 0x0($a1)
    /* B02C 8001A82C 0A00A0A4 */  sh         $zero, 0xA($a1)
    /* B030 8001A830 0800A7A4 */  sh         $a3, 0x8($a1)
    /* B034 8001A834 0100C624 */  addiu      $a2, $a2, 0x1
    /* B038 8001A838 0300C228 */  slti       $v0, $a2, 0x3
    /* B03C 8001A83C F9FF4014 */  bnez       $v0, .L8001A824
    /* B040 8001A840 2C00A524 */   addiu     $a1, $a1, 0x2C
    /* B044 8001A844 21200000 */  addu       $a0, $zero, $zero
    /* B048 8001A848 7D69000C */  jal        Snd_SetSlotContent
    /* B04C 8001A84C 01000524 */   addiu     $a1, $zero, 0x1
    /* B050 8001A850 0580023C */  lui        $v0, %hi(Snd_Slots)
    /* B054 8001A854 484C5024 */  addiu      $s0, $v0, %lo(Snd_Slots)
  .L8001A858:
    /* B058 8001A858 0768000C */  jal        Snd_ServiceSlotLoads
    /* B05C 8001A85C 00000000 */   nop
    /* B060 8001A860 1D8F000C */  jal        Cd_ServiceQueue
    /* B064 8001A864 00000000 */   nop
    /* B068 8001A868 0400028E */  lw         $v0, 0x4($s0)
    /* B06C 8001A86C 00000000 */  nop
    /* B070 8001A870 F9FF4014 */  bnez       $v0, .L8001A858
    /* B074 8001A874 01000424 */   addiu     $a0, $zero, 0x1
    /* B078 8001A878 7D69000C */  jal        Snd_SetSlotContent
    /* B07C 8001A87C 0E000524 */   addiu     $a1, $zero, 0xE
    /* B080 8001A880 0580023C */  lui        $v0, %hi(Snd_Slots)
    /* B084 8001A884 484C5024 */  addiu      $s0, $v0, %lo(Snd_Slots)
  .L8001A888:
    /* B088 8001A888 0768000C */  jal        Snd_ServiceSlotLoads
    /* B08C 8001A88C 00000000 */   nop
    /* B090 8001A890 1D8F000C */  jal        Cd_ServiceQueue
    /* B094 8001A894 00000000 */   nop
    /* B098 8001A898 3000028E */  lw         $v0, 0x30($s0)
    /* B09C 8001A89C 00000000 */  nop
    /* B0A0 8001A8A0 F9FF4014 */  bnez       $v0, .L8001A888
    /* B0A4 8001A8A4 00000000 */   nop
    /* B0A8 8001A8A8 1800BF8F */  lw         $ra, 0x18($sp)
    /* B0AC 8001A8AC 1400B18F */  lw         $s1, 0x14($sp)
    /* B0B0 8001A8B0 1000B08F */  lw         $s0, 0x10($sp)
    /* B0B4 8001A8B4 0800E003 */  jr         $ra
    /* B0B8 8001A8B8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Snd_Init
