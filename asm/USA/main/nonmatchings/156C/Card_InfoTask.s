nonmatching Card_InfoTask, 0x31C

glabel Card_InfoTask
    /* 2E618 8003DE18 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 2E61C 8003DE1C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2E620 8003DE20 21808000 */  addu       $s0, $a0, $zero
    /* 2E624 8003DE24 2000BFAF */  sw         $ra, 0x20($sp)
    /* 2E628 8003DE28 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 2E62C 8003DE2C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2E630 8003DE30 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2E634 8003DE34 0000038E */  lw         $v1, 0x0($s0)
    /* 2E638 8003DE38 0A001224 */  addiu      $s2, $zero, 0xA
    /* 2E63C 8003DE3C 1D007210 */  beq        $v1, $s2, .L8003DEB4
    /* 2E640 8003DE40 0B006228 */   slti      $v0, $v1, 0xB
    /* 2E644 8003DE44 05004010 */  beqz       $v0, .L8003DE5C
    /* 2E648 8003DE48 0B000224 */   addiu     $v0, $zero, 0xB
    /* 2E64C 8003DE4C 09006010 */  beqz       $v1, .L8003DE74
    /* 2E650 8003DE50 00000000 */   nop
    /* 2E654 8003DE54 42F80008 */  j          .L8003E108
    /* 2E658 8003DE58 00000000 */   nop
  .L8003DE5C:
    /* 2E65C 8003DE5C 20006210 */  beq        $v1, $v0, .L8003DEE0
    /* 2E660 8003DE60 15000224 */   addiu     $v0, $zero, 0x15
    /* 2E664 8003DE64 A0006210 */  beq        $v1, $v0, .L8003E0E8
    /* 2E668 8003DE68 00000000 */   nop
    /* 2E66C 8003DE6C 42F80008 */  j          .L8003E108
    /* 2E670 8003DE70 00000000 */   nop
  .L8003DE74:
    /* 2E674 8003DE74 0680023C */  lui        $v0, %hi(D_80062F90)
    /* 2E678 8003DE78 902F4224 */  addiu      $v0, $v0, %lo(D_80062F90)
    /* 2E67C 8003DE7C 0680013C */  lui        $at, %hi(D_80062F54)
    /* 2E680 8003DE80 542F20AC */  sw         $zero, %lo(D_80062F54)($at)
    /* 2E684 8003DE84 0680013C */  lui        $at, %hi(D_80062F50)
    /* 2E688 8003DE88 502F20AC */  sw         $zero, %lo(D_80062F50)($at)
    /* 2E68C 8003DE8C 000012AE */  sw         $s2, 0x0($s0)
    /* 2E690 8003DE90 0000438C */  lw         $v1, 0x0($v0)
    /* 2E694 8003DE94 40004224 */  addiu      $v0, $v0, 0x40
    /* 2E698 8003DE98 03190300 */  sra        $v1, $v1, 4
    /* 2E69C 8003DE9C 80180300 */  sll        $v1, $v1, 2
    /* 2E6A0 8003DEA0 21186200 */  addu       $v1, $v1, $v0
    /* 2E6A4 8003DEA4 0000628C */  lw         $v0, 0x0($v1)
    /* 2E6A8 8003DEA8 000060AC */  sw         $zero, 0x0($v1)
    /* 2E6AC 8003DEAC 0580013C */  lui        $at, %hi(D_800506C8)
    /* 2E6B0 8003DEB0 C80622AC */  sw         $v0, %lo(D_800506C8)($at)
  .L8003DEB4:
    /* 2E6B4 8003DEB4 A9FF000C */  jal        func_8003FEA4
    /* 2E6B8 8003DEB8 00000000 */   nop
    /* 2E6BC 8003DEBC 0680043C */  lui        $a0, %hi(D_80062F90)
    /* 2E6C0 8003DEC0 902F848C */  lw         $a0, %lo(D_80062F90)($a0)
    /* 2E6C4 8003DEC4 65FE000C */  jal        _card_info
    /* 2E6C8 8003DEC8 00000000 */   nop
    /* 2E6CC 8003DECC 0000028E */  lw         $v0, 0x0($s0)
    /* 2E6D0 8003DED0 00000000 */  nop
    /* 2E6D4 8003DED4 01004224 */  addiu      $v0, $v0, 0x1
    /* 2E6D8 8003DED8 45F80008 */  j          .L8003E114
    /* 2E6DC 8003DEDC 000002AE */   sw        $v0, 0x0($s0)
  .L8003DEE0:
    /* 2E6E0 8003DEE0 5700010C */  jal        func_8004015C
    /* 2E6E4 8003DEE4 00000000 */   nop
    /* 2E6E8 8003DEE8 8B004010 */  beqz       $v0, .L8003E118
    /* 2E6EC 8003DEEC 21100000 */   addu      $v0, $zero, $zero
    /* 2E6F0 8003DEF0 EBFF000C */  jal        func_8003FFAC
    /* 2E6F4 8003DEF4 00000000 */   nop
    /* 2E6F8 8003DEF8 0680113C */  lui        $s1, %hi(D_80062F90)
    /* 2E6FC 8003DEFC 902F3126 */  addiu      $s1, $s1, %lo(D_80062F90)
    /* 2E700 8003DF00 38003326 */  addiu      $s3, $s1, 0x38
    /* 2E704 8003DF04 0000278E */  lw         $a3, 0x0($s1)
    /* 2E708 8003DF08 21204000 */  addu       $a0, $v0, $zero
    /* 2E70C 8003DF0C 0680013C */  lui        $at, %hi(D_80062F54)
    /* 2E710 8003DF10 542F22AC */  sw         $v0, %lo(D_80062F54)($at)
    /* 2E714 8003DF14 03190700 */  sra        $v1, $a3, 4
    /* 2E718 8003DF18 80180300 */  sll        $v1, $v1, 2
    /* 2E71C 8003DF1C 21287300 */  addu       $a1, $v1, $s3
    /* 2E720 8003DF20 0000A68C */  lw         $a2, 0x0($a1)
    /* 2E724 8003DF24 01000324 */  addiu      $v1, $zero, 0x1
    /* 2E728 8003DF28 0580013C */  lui        $at, %hi(D_800506CC)
    /* 2E72C 8003DF2C CC0626AC */  sw         $a2, %lo(D_800506CC)($at)
    /* 2E730 8003DF30 47008310 */  beq        $a0, $v1, .L8003E050
    /* 2E734 8003DF34 02008228 */   slti      $v0, $a0, 0x2
    /* 2E738 8003DF38 05004010 */  beqz       $v0, .L8003DF50
    /* 2E73C 8003DF3C 02000224 */   addiu     $v0, $zero, 0x2
    /* 2E740 8003DF40 27008010 */  beqz       $a0, .L8003DFE0
    /* 2E744 8003DF44 00000000 */   nop
    /* 2E748 8003DF48 2BF80008 */  j          .L8003E0AC
    /* 2E74C 8003DF4C 00000000 */   nop
  .L8003DF50:
    /* 2E750 8003DF50 2E008210 */  beq        $a0, $v0, .L8003E00C
    /* 2E754 8003DF54 04000224 */   addiu     $v0, $zero, 0x4
    /* 2E758 8003DF58 54008214 */  bne        $a0, $v0, .L8003E0AC
    /* 2E75C 8003DF5C 00000000 */   nop
    /* 2E760 8003DF60 0F00C014 */  bnez       $a2, .L8003DFA0
    /* 2E764 8003DF64 00000000 */   nop
    /* 2E768 8003DF68 0580023C */  lui        $v0, %hi(D_800506C8)
    /* 2E76C 8003DF6C C806428C */  lw         $v0, %lo(D_800506C8)($v0)
    /* 2E770 8003DF70 00000000 */  nop
    /* 2E774 8003DF74 8000422C */  sltiu      $v0, $v0, 0x80
    /* 2E778 8003DF78 09004010 */  beqz       $v0, .L8003DFA0
    /* 2E77C 8003DF7C 00000000 */   nop
    /* 2E780 8003DF80 A9FF000C */  jal        func_8003FEA4
    /* 2E784 8003DF84 00000000 */   nop
    /* 2E788 8003DF88 0000248E */  lw         $a0, 0x0($s1)
    /* 2E78C 8003DF8C 6DFE000C */  jal        _card_clear
    /* 2E790 8003DF90 00000000 */   nop
    /* 2E794 8003DF94 15000224 */  addiu      $v0, $zero, 0x15
    /* 2E798 8003DF98 45F80008 */  j          .L8003E114
    /* 2E79C 8003DF9C 000002AE */   sw        $v0, 0x0($s0)
  .L8003DFA0:
    /* 2E7A0 8003DFA0 0680103C */  lui        $s0, %hi(D_80062F90)
    /* 2E7A4 8003DFA4 902F1026 */  addiu      $s0, $s0, %lo(D_80062F90)
    /* 2E7A8 8003DFA8 01000324 */  addiu      $v1, $zero, 0x1
    /* 2E7AC 8003DFAC 0000028E */  lw         $v0, 0x0($s0)
    /* 2E7B0 8003DFB0 0680043C */  lui        $a0, %hi(D_80062F54)
    /* 2E7B4 8003DFB4 542F848C */  lw         $a0, %lo(D_80062F54)($a0)
    /* 2E7B8 8003DFB8 03110200 */  sra        $v0, $v0, 4
    /* 2E7BC 8003DFBC 80100200 */  sll        $v0, $v0, 2
    /* 2E7C0 8003DFC0 21100202 */  addu       $v0, $s0, $v0
    /* 2E7C4 8003DFC4 06FD000C */  jal        func_8003F418
    /* 2E7C8 8003DFC8 380043AC */   sw        $v1, 0x38($v0)
    /* 2E7CC 8003DFCC 21184000 */  addu       $v1, $v0, $zero
    /* 2E7D0 8003DFD0 01000224 */  addiu      $v0, $zero, 0x1
    /* 2E7D4 8003DFD4 F0FF1026 */  addiu      $s0, $s0, -0x10
    /* 2E7D8 8003DFD8 46F80008 */  j          .L8003E118
    /* 2E7DC 8003DFDC 040003AE */   sw        $v1, 0x4($s0)
  .L8003DFE0:
    /* 2E7E0 8003DFE0 FCFF228E */  lw         $v0, -0x4($s1)
    /* 2E7E4 8003DFE4 0418E300 */  sllv       $v1, $v1, $a3
    /* 2E7E8 8003DFE8 24104300 */  and        $v0, $v0, $v1
    /* 2E7EC 8003DFEC 03004014 */  bnez       $v0, .L8003DFFC
    /* 2E7F0 8003DFF0 04000224 */   addiu     $v0, $zero, 0x4
    /* 2E7F4 8003DFF4 0680013C */  lui        $at, %hi(D_80062F54)
    /* 2E7F8 8003DFF8 542F22AC */  sw         $v0, %lo(D_80062F54)($at)
  .L8003DFFC:
    /* 2E7FC 8003DFFC 0680043C */  lui        $a0, %hi(D_80062F54)
    /* 2E800 8003E000 542F848C */  lw         $a0, %lo(D_80062F54)($a0)
    /* 2E804 8003E004 0DF80008 */  j          .L8003E034
    /* 2E808 8003E008 0000A0AC */   sw        $zero, 0x0($a1)
  .L8003E00C:
    /* 2E80C 8003E00C 0680023C */  lui        $v0, %hi(D_80062F50)
    /* 2E810 8003E010 502F428C */  lw         $v0, %lo(D_80062F50)($v0)
    /* 2E814 8003E014 00000000 */  nop
    /* 2E818 8003E018 01004224 */  addiu      $v0, $v0, 0x1
    /* 2E81C 8003E01C 0680013C */  lui        $at, %hi(D_80062F50)
    /* 2E820 8003E020 502F22AC */  sw         $v0, %lo(D_80062F50)($at)
    /* 2E824 8003E024 03004228 */  slti       $v0, $v0, 0x3
    /* 2E828 8003E028 12004014 */  bnez       $v0, .L8003E074
    /* 2E82C 8003E02C 02000424 */   addiu     $a0, $zero, 0x2
    /* 2E830 8003E030 0000A3AC */  sw         $v1, 0x0($a1)
  .L8003E034:
    /* 2E834 8003E034 06FD000C */  jal        func_8003F418
    /* 2E838 8003E038 00000000 */   nop
    /* 2E83C 8003E03C 21204000 */  addu       $a0, $v0, $zero
    /* 2E840 8003E040 01000224 */  addiu      $v0, $zero, 0x1
    /* 2E844 8003E044 F0FF2326 */  addiu      $v1, $s1, -0x10
    /* 2E848 8003E048 46F80008 */  j          .L8003E118
    /* 2E84C 8003E04C 040064AC */   sw        $a0, 0x4($v1)
  .L8003E050:
    /* 2E850 8003E050 0680023C */  lui        $v0, %hi(D_80062F50)
    /* 2E854 8003E054 502F428C */  lw         $v0, %lo(D_80062F50)($v0)
    /* 2E858 8003E058 00000000 */  nop
    /* 2E85C 8003E05C 01004224 */  addiu      $v0, $v0, 0x1
    /* 2E860 8003E060 0680013C */  lui        $at, %hi(D_80062F50)
    /* 2E864 8003E064 502F22AC */  sw         $v0, %lo(D_80062F50)($at)
    /* 2E868 8003E068 11004228 */  slti       $v0, $v0, 0x11
    /* 2E86C 8003E06C 03004010 */  beqz       $v0, .L8003E07C
    /* 2E870 8003E070 00000000 */   nop
  .L8003E074:
    /* 2E874 8003E074 45F80008 */  j          .L8003E114
    /* 2E878 8003E078 000012AE */   sw        $s2, 0x0($s0)
  .L8003E07C:
    /* 2E87C 8003E07C 06FD000C */  jal        func_8003F418
    /* 2E880 8003E080 01000424 */   addiu     $a0, $zero, 0x1
    /* 2E884 8003E084 21184000 */  addu       $v1, $v0, $zero
    /* 2E888 8003E088 01000224 */  addiu      $v0, $zero, 0x1
    /* 2E88C 8003E08C 0000248E */  lw         $a0, 0x0($s1)
    /* 2E890 8003E090 F0FF2526 */  addiu      $a1, $s1, -0x10
    /* 2E894 8003E094 0400A3AC */  sw         $v1, 0x4($a1)
    /* 2E898 8003E098 03210400 */  sra        $a0, $a0, 4
    /* 2E89C 8003E09C 80200400 */  sll        $a0, $a0, 2
    /* 2E8A0 8003E0A0 21209300 */  addu       $a0, $a0, $s3
    /* 2E8A4 8003E0A4 46F80008 */  j          .L8003E118
    /* 2E8A8 8003E0A8 000080AC */   sw        $zero, 0x0($a0)
  .L8003E0AC:
    /* 2E8AC 8003E0AC 0680043C */  lui        $a0, %hi(D_80062F54)
    /* 2E8B0 8003E0B0 542F848C */  lw         $a0, %lo(D_80062F54)($a0)
    /* 2E8B4 8003E0B4 06FD000C */  jal        func_8003F418
    /* 2E8B8 8003E0B8 00000000 */   nop
    /* 2E8BC 8003E0BC 21284000 */  addu       $a1, $v0, $zero
    /* 2E8C0 8003E0C0 0680043C */  lui        $a0, %hi(D_80062F80)
    /* 2E8C4 8003E0C4 802F8424 */  addiu      $a0, $a0, %lo(D_80062F80)
    /* 2E8C8 8003E0C8 1000838C */  lw         $v1, 0x10($a0)
    /* 2E8CC 8003E0CC 01000224 */  addiu      $v0, $zero, 0x1
    /* 2E8D0 8003E0D0 040085AC */  sw         $a1, 0x4($a0)
    /* 2E8D4 8003E0D4 03190300 */  sra        $v1, $v1, 4
    /* 2E8D8 8003E0D8 80180300 */  sll        $v1, $v1, 2
    /* 2E8DC 8003E0DC 21208300 */  addu       $a0, $a0, $v1
    /* 2E8E0 8003E0E0 46F80008 */  j          .L8003E118
    /* 2E8E4 8003E0E4 480080AC */   sw        $zero, 0x48($a0)
  .L8003E0E8:
    /* 2E8E8 8003E0E8 6600010C */  jal        Card_GetHwEventBits
    /* 2E8EC 8003E0EC 00000000 */   nop
    /* 2E8F0 8003E0F0 09004010 */  beqz       $v0, .L8003E118
    /* 2E8F4 8003E0F4 21100000 */   addu      $v0, $zero, $zero
    /* 2E8F8 8003E0F8 2100010C */  jal        func_80040084
    /* 2E8FC 8003E0FC 00000000 */   nop
    /* 2E900 8003E100 45F80008 */  j          .L8003E114
    /* 2E904 8003E104 000000AE */   sw        $zero, 0x0($s0)
  .L8003E108:
    /* 2E908 8003E108 0180043C */  lui        $a0, %hi(D_80010B9C)
    /* 2E90C 8003E10C 05A8000C */  jal        printf
    /* 2E910 8003E110 9C0B8424 */   addiu     $a0, $a0, %lo(D_80010B9C)
  .L8003E114:
    /* 2E914 8003E114 21100000 */  addu       $v0, $zero, $zero
  .L8003E118:
    /* 2E918 8003E118 2000BF8F */  lw         $ra, 0x20($sp)
    /* 2E91C 8003E11C 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 2E920 8003E120 1800B28F */  lw         $s2, 0x18($sp)
    /* 2E924 8003E124 1400B18F */  lw         $s1, 0x14($sp)
    /* 2E928 8003E128 1000B08F */  lw         $s0, 0x10($sp)
    /* 2E92C 8003E12C 0800E003 */  jr         $ra
    /* 2E930 8003E130 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel Card_InfoTask
