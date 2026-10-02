nonmatching Debug_PutChar, 0xFC

glabel Debug_PutChar
    /* 1AF44 8002A744 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1AF48 8002A748 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1AF4C 8002A74C 21808000 */  addu       $s0, $a0, $zero
    /* 1AF50 8002A750 00260400 */  sll        $a0, $a0, 24
    /* 1AF54 8002A754 03260400 */  sra        $a0, $a0, 24
    /* 1AF58 8002A758 09000224 */  addiu      $v0, $zero, 0x9
    /* 1AF5C 8002A75C 09008210 */  beq        $a0, $v0, .L8002A784
    /* 1AF60 8002A760 1400BFAF */   sw        $ra, 0x14($sp)
    /* 1AF64 8002A764 0A000224 */  addiu      $v0, $zero, 0xA
    /* 1AF68 8002A768 10008214 */  bne        $a0, $v0, .L8002A7AC
    /* 1AF6C 8002A76C FF000232 */   andi      $v0, $s0, 0xFF
    /* 1AF70 8002A770 D1A9000C */  jal        Debug_PutChar
    /* 1AF74 8002A774 0D000424 */   addiu     $a0, $zero, 0xD
    /* 1AF78 8002A778 0580013C */  lui        $at, %hi(D_80049060)
    /* 1AF7C 8002A77C F8A90008 */  j          .L8002A7E0
    /* 1AF80 8002A780 609020AC */   sw        $zero, %lo(D_80049060)($at)
  .L8002A784:
    /* 1AF84 8002A784 D1A9000C */  jal        Debug_PutChar
    /* 1AF88 8002A788 20000424 */   addiu     $a0, $zero, 0x20
    /* 1AF8C 8002A78C 0580023C */  lui        $v0, %hi(D_80049060)
    /* 1AF90 8002A790 6090428C */  lw         $v0, %lo(D_80049060)($v0)
    /* 1AF94 8002A794 00000000 */  nop
    /* 1AF98 8002A798 07004230 */  andi       $v0, $v0, 0x7
    /* 1AF9C 8002A79C 24004010 */  beqz       $v0, .L8002A830
    /* 1AFA0 8002A7A0 00000000 */   nop
    /* 1AFA4 8002A7A4 E1A90008 */  j          .L8002A784
    /* 1AFA8 8002A7A8 00000000 */   nop
  .L8002A7AC:
    /* 1AFAC 8002A7AC 0580013C */  lui        $at, %hi(D_80049071)
    /* 1AFB0 8002A7B0 21082200 */  addu       $at, $at, $v0
    /* 1AFB4 8002A7B4 71902280 */  lb         $v0, %lo(D_80049071)($at)
    /* 1AFB8 8002A7B8 00000000 */  nop
    /* 1AFBC 8002A7BC 97004230 */  andi       $v0, $v0, 0x97
    /* 1AFC0 8002A7C0 07004010 */  beqz       $v0, .L8002A7E0
    /* 1AFC4 8002A7C4 00000000 */   nop
    /* 1AFC8 8002A7C8 0580023C */  lui        $v0, %hi(D_80049060)
    /* 1AFCC 8002A7CC 6090428C */  lw         $v0, %lo(D_80049060)($v0)
    /* 1AFD0 8002A7D0 00000000 */  nop
    /* 1AFD4 8002A7D4 01004224 */  addiu      $v0, $v0, 0x1
    /* 1AFD8 8002A7D8 0580013C */  lui        $at, %hi(D_80049060)
    /* 1AFDC 8002A7DC 609022AC */  sw         $v0, %lo(D_80049060)($at)
  .L8002A7E0:
    /* 1AFE0 8002A7E0 0580063C */  lui        $a2, %hi(D_80049064)
    /* 1AFE4 8002A7E4 6490C68C */  lw         $a2, %lo(D_80049064)($a2)
    /* 1AFE8 8002A7E8 00000000 */  nop
    /* 1AFEC 8002A7EC 2000C228 */  slti       $v0, $a2, 0x20
    /* 1AFF0 8002A7F0 07004014 */  bnez       $v0, .L8002A810
    /* 1AFF4 8002A7F4 00000000 */   nop
    /* 1AFF8 8002A7F8 0680053C */  lui        $a1, %hi(D_800618B0)
    /* 1AFFC 8002A7FC B018A524 */  addiu      $a1, $a1, %lo(D_800618B0)
    /* 1B000 8002A800 69AA000C */  jal        write
    /* 1B004 8002A804 01000424 */   addiu     $a0, $zero, 0x1
    /* 1B008 8002A808 0580013C */  lui        $at, %hi(D_80049064)
    /* 1B00C 8002A80C 649020AC */  sw         $zero, %lo(D_80049064)($at)
  .L8002A810:
    /* 1B010 8002A810 0580033C */  lui        $v1, %hi(D_80049064)
    /* 1B014 8002A814 64906324 */  addiu      $v1, $v1, %lo(D_80049064)
    /* 1B018 8002A818 0000628C */  lw         $v0, 0x0($v1)
    /* 1B01C 8002A81C 0680013C */  lui        $at, %hi(D_800618B0)
    /* 1B020 8002A820 21082200 */  addu       $at, $at, $v0
    /* 1B024 8002A824 B01830A0 */  sb         $s0, %lo(D_800618B0)($at)
    /* 1B028 8002A828 01004224 */  addiu      $v0, $v0, 0x1
    /* 1B02C 8002A82C 000062AC */  sw         $v0, 0x0($v1)
  .L8002A830:
    /* 1B030 8002A830 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1B034 8002A834 1000B08F */  lw         $s0, 0x10($sp)
    /* 1B038 8002A838 0800E003 */  jr         $ra
    /* 1B03C 8002A83C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Debug_PutChar
