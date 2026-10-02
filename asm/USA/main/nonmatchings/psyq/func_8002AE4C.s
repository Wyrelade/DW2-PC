nonmatching func_8002AE4C, 0x220

glabel func_8002AE4C
    /* 1B64C 8002AE4C FFFF8430 */  andi       $a0, $a0, 0xFFFF
    /* 1B650 8002AE50 FFFFA530 */  andi       $a1, $a1, 0xFFFF
    /* 1B654 8002AE54 0680013C */  lui        $at, %hi(D_80061990)
    /* 1B658 8002AE58 901924AC */  sw         $a0, %lo(D_80061990)($at)
    /* 1B65C 8002AE5C 0680013C */  lui        $at, %hi(D_80061994)
    /* 1B660 8002AE60 941925AC */  sw         $a1, %lo(D_80061994)($at)
    /* 1B664 8002AE64 0680043C */  lui        $a0, %hi(D_80061994)
    /* 1B668 8002AE68 9419848C */  lw         $a0, %lo(D_80061994)($a0)
    /* 1B66C 8002AE6C 0680023C */  lui        $v0, %hi(D_80061990)
    /* 1B670 8002AE70 9019428C */  lw         $v0, %lo(D_80061990)($v0)
    /* 1B674 8002AE74 80230400 */  sll        $a0, $a0, 14
    /* 1B678 8002AE78 1A008200 */  div        $zero, $a0, $v0
    /* 1B67C 8002AE7C 02004014 */  bnez       $v0, .L8002AE88
    /* 1B680 8002AE80 00000000 */   nop
    /* 1B684 8002AE84 0D000700 */  break      7
  .L8002AE88:
    /* 1B688 8002AE88 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 1B68C 8002AE8C 04004114 */  bne        $v0, $at, .L8002AEA0
    /* 1B690 8002AE90 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 1B694 8002AE94 02008114 */  bne        $a0, $at, .L8002AEA0
    /* 1B698 8002AE98 00000000 */   nop
    /* 1B69C 8002AE9C 0D000600 */  break      6
  .L8002AEA0:
    /* 1B6A0 8002AEA0 12200000 */  mflo       $a0
    /* 1B6A4 8002AEA4 0680033C */  lui        $v1, %hi(D_80061A38)
    /* 1B6A8 8002AEA8 381A6324 */  addiu      $v1, $v1, %lo(D_80061A38)
    /* 1B6AC 8002AEAC 0680063C */  lui        $a2, %hi(D_80061A48)
    /* 1B6B0 8002AEB0 481AC624 */  addiu      $a2, $a2, %lo(D_80061A48)
    /* 1B6B4 8002AEB4 F4FF60A4 */  sh         $zero, -0xC($v1)
    /* 1B6B8 8002AEB8 F2FF60A4 */  sh         $zero, -0xE($v1)
    /* 1B6BC 8002AEBC FAFF60A4 */  sh         $zero, -0x6($v1)
    /* 1B6C0 8002AEC0 F6FF60A4 */  sh         $zero, -0xA($v1)
    /* 1B6C4 8002AEC4 FEFF60A4 */  sh         $zero, -0x2($v1)
    /* 1B6C8 8002AEC8 FCFF60A4 */  sh         $zero, -0x4($v1)
    /* 1B6CC 8002AECC 0C0060AC */  sw         $zero, 0xC($v1)
    /* 1B6D0 8002AED0 080060AC */  sw         $zero, 0x8($v1)
    /* 1B6D4 8002AED4 040060AC */  sw         $zero, 0x4($v1)
    /* 1B6D8 8002AED8 00100224 */  addiu      $v0, $zero, 0x1000
    /* 1B6DC 8002AEDC F0FF62A4 */  sh         $v0, -0x10($v1)
    /* 1B6E0 8002AEE0 F8FF62A4 */  sh         $v0, -0x8($v1)
    /* 1B6E4 8002AEE4 000062A4 */  sh         $v0, 0x0($v1)
    /* 1B6E8 8002AEE8 F0FF628C */  lw         $v0, -0x10($v1)
    /* 1B6EC 8002AEEC F4FF658C */  lw         $a1, -0xC($v1)
    /* 1B6F0 8002AEF0 F8FF678C */  lw         $a3, -0x8($v1)
    /* 1B6F4 8002AEF4 FCFF688C */  lw         $t0, -0x4($v1)
    /* 1B6F8 8002AEF8 0000C2AC */  sw         $v0, 0x0($a2)
    /* 1B6FC 8002AEFC 0400C5AC */  sw         $a1, 0x4($a2)
    /* 1B700 8002AF00 0800C7AC */  sw         $a3, 0x8($a2)
    /* 1B704 8002AF04 0C00C8AC */  sw         $t0, 0xC($a2)
    /* 1B708 8002AF08 0000628C */  lw         $v0, 0x0($v1)
    /* 1B70C 8002AF0C 0400658C */  lw         $a1, 0x4($v1)
    /* 1B710 8002AF10 0800678C */  lw         $a3, 0x8($v1)
    /* 1B714 8002AF14 0C00688C */  lw         $t0, 0xC($v1)
    /* 1B718 8002AF18 1000C2AC */  sw         $v0, 0x10($a2)
    /* 1B71C 8002AF1C 1400C5AC */  sw         $a1, 0x14($a2)
    /* 1B720 8002AF20 1800C7AC */  sw         $a3, 0x18($a2)
    /* 1B724 8002AF24 1C00C8AC */  sw         $t0, 0x1C($a2)
    /* 1B728 8002AF28 0680023C */  lui        $v0, %hi(D_800619A8)
    /* 1B72C 8002AF2C A8194224 */  addiu      $v0, $v0, %lo(D_800619A8)
    /* 1B730 8002AF30 F0FF658C */  lw         $a1, -0x10($v1)
    /* 1B734 8002AF34 F4FF678C */  lw         $a3, -0xC($v1)
    /* 1B738 8002AF38 F8FF688C */  lw         $t0, -0x8($v1)
    /* 1B73C 8002AF3C FCFF698C */  lw         $t1, -0x4($v1)
    /* 1B740 8002AF40 000045AC */  sw         $a1, 0x0($v0)
    /* 1B744 8002AF44 040047AC */  sw         $a3, 0x4($v0)
    /* 1B748 8002AF48 080048AC */  sw         $t0, 0x8($v0)
    /* 1B74C 8002AF4C 0C0049AC */  sw         $t1, 0xC($v0)
    /* 1B750 8002AF50 0000658C */  lw         $a1, 0x0($v1)
    /* 1B754 8002AF54 0400678C */  lw         $a3, 0x4($v1)
    /* 1B758 8002AF58 0800688C */  lw         $t0, 0x8($v1)
    /* 1B75C 8002AF5C 0C00698C */  lw         $t1, 0xC($v1)
    /* 1B760 8002AF60 100045AC */  sw         $a1, 0x10($v0)
    /* 1B764 8002AF64 140047AC */  sw         $a3, 0x14($v0)
    /* 1B768 8002AF68 180048AC */  sw         $t0, 0x18($v0)
    /* 1B76C 8002AF6C 1C0049AC */  sw         $t1, 0x1C($v0)
    /* 1B770 8002AF70 100040A4 */  sh         $zero, 0x10($v0)
    /* 1B774 8002AF74 080040A4 */  sh         $zero, 0x8($v0)
    /* 1B778 8002AF78 000040A4 */  sh         $zero, 0x0($v0)
    /* 1B77C 8002AF7C 0680083C */  lui        $t0, %hi(D_800619C8)
    /* 1B780 8002AF80 C8190825 */  addiu      $t0, $t0, %lo(D_800619C8)
    /* 1B784 8002AF84 0000438C */  lw         $v1, 0x0($v0)
    /* 1B788 8002AF88 0400458C */  lw         $a1, 0x4($v0)
    /* 1B78C 8002AF8C 0800478C */  lw         $a3, 0x8($v0)
    /* 1B790 8002AF90 000003AD */  sw         $v1, 0x0($t0)
    /* 1B794 8002AF94 040005AD */  sw         $a1, 0x4($t0)
    /* 1B798 8002AF98 080007AD */  sw         $a3, 0x8($t0)
    /* 1B79C 8002AF9C 0C00438C */  lw         $v1, 0xC($v0)
    /* 1B7A0 8002AFA0 1000458C */  lw         $a1, 0x10($v0)
    /* 1B7A4 8002AFA4 1400478C */  lw         $a3, 0x14($v0)
    /* 1B7A8 8002AFA8 0C0003AD */  sw         $v1, 0xC($t0)
    /* 1B7AC 8002AFAC 100005AD */  sw         $a1, 0x10($t0)
    /* 1B7B0 8002AFB0 140007AD */  sw         $a3, 0x14($t0)
    /* 1B7B4 8002AFB4 1800438C */  lw         $v1, 0x18($v0)
    /* 1B7B8 8002AFB8 1C00458C */  lw         $a1, 0x1C($v0)
    /* 1B7BC 8002AFBC 180003AD */  sw         $v1, 0x18($t0)
    /* 1B7C0 8002AFC0 1C0005AD */  sw         $a1, 0x1C($t0)
    /* 1B7C4 8002AFC4 5555033C */  lui        $v1, (0x55555556 >> 16)
    /* 1B7C8 8002AFC8 56556334 */  ori        $v1, $v1, (0x55555556 & 0xFFFF)
    /* 1B7CC 8002AFCC 0680023C */  lui        $v0, %hi(D_800618F8)
    /* 1B7D0 8002AFD0 F8184224 */  addiu      $v0, $v0, %lo(D_800618F8)
    /* 1B7D4 8002AFD4 000040A4 */  sh         $zero, 0x0($v0)
    /* 1B7D8 8002AFD8 020040A4 */  sh         $zero, 0x2($v0)
    /* 1B7DC 8002AFDC 18008300 */  mult       $a0, $v1
    /* 1B7E0 8002AFE0 0680023C */  lui        $v0, %hi(D_800618FC)
    /* 1B7E4 8002AFE4 FC184224 */  addiu      $v0, $v0, %lo(D_800618FC)
    /* 1B7E8 8002AFE8 000040A4 */  sh         $zero, 0x0($v0)
    /* 1B7EC 8002AFEC 020040A4 */  sh         $zero, 0x2($v0)
    /* 1B7F0 8002AFF0 0680023C */  lui        $v0, %hi(D_80061900)
    /* 1B7F4 8002AFF4 00194224 */  addiu      $v0, $v0, %lo(D_80061900)
    /* 1B7F8 8002AFF8 0680053C */  lui        $a1, %hi(D_80061980)
    /* 1B7FC 8002AFFC 8019A524 */  addiu      $a1, $a1, %lo(D_80061980)
    /* 1B800 8002B000 020040A4 */  sh         $zero, 0x2($v0)
    /* 1B804 8002B004 000040A4 */  sh         $zero, 0x0($v0)
    /* 1B808 8002B008 0680023C */  lui        $v0, %hi(D_800618D0)
    /* 1B80C 8002B00C D0184224 */  addiu      $v0, $v0, %lo(D_800618D0)
    /* 1B810 8002B010 0200A0A4 */  sh         $zero, 0x2($a1)
    /* 1B814 8002B014 C3270400 */  sra        $a0, $a0, 31
    /* 1B818 8002B018 02000324 */  addiu      $v1, $zero, 0x2
    /* 1B81C 8002B01C 10380000 */  mfhi       $a3
    /* 1B820 8002B020 2320E400 */  subu       $a0, $a3, $a0
    /* 1B824 8002B024 0800C4A4 */  sh         $a0, 0x8($a2)
    /* 1B828 8002B028 03000424 */  addiu      $a0, $zero, 0x3
    /* 1B82C 8002B02C 0000A0A4 */  sh         $zero, 0x0($a1)
    /* 1B830 8002B030 030044A0 */  sb         $a0, 0x3($v0)
    /* 1B834 8002B034 070043A0 */  sb         $v1, 0x7($v0)
    /* 1B838 8002B038 10004224 */  addiu      $v0, $v0, 0x10
    /* 1B83C 8002B03C 030044A0 */  sb         $a0, 0x3($v0)
    /* 1B840 8002B040 070043A0 */  sb         $v1, 0x7($v0)
    /* 1B844 8002B044 0680033C */  lui        $v1, %hi(D_80061990)
    /* 1B848 8002B048 90196394 */  lhu        $v1, %lo(D_80061990)($v1)
    /* 1B84C 8002B04C 0680043C */  lui        $a0, %hi(D_80061994)
    /* 1B850 8002B050 94198494 */  lhu        $a0, %lo(D_80061994)($a0)
    /* 1B854 8002B054 01000224 */  addiu      $v0, $zero, 0x1
    /* 1B858 8002B058 0680013C */  lui        $at, %hi(D_80061988)
    /* 1B85C 8002B05C 881922AC */  sw         $v0, %lo(D_80061988)($at)
    /* 1B860 8002B060 0400A3A4 */  sh         $v1, 0x4($a1)
    /* 1B864 8002B064 0800E003 */  jr         $ra
    /* 1B868 8002B068 0600A4A4 */   sh        $a0, 0x6($a1)
endlabel func_8002AE4C
