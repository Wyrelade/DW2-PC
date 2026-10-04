nonmatching Stg40_ListPartyDigi, 0x100

glabel Stg40_ListPartyDigi
    /* B724 8006EA84 21408000 */  addu       $t0, $a0, $zero
    /* B728 8006EA88 21300000 */  addu       $a2, $zero, $zero
    /* B72C 8006EA8C 0580023C */  lui        $v0, %hi(Save_GameStatePtr)
    /* B730 8006EA90 0780033C */  lui        $v1, %hi(D_80072B60)
    /* B734 8006EA94 2007448C */  lw         $a0, %lo(Save_GameStatePtr)($v0)
    /* B738 8006EA98 602B628C */  lw         $v0, %lo(D_80072B60)($v1)
    /* B73C 8006EA9C E4008724 */  addiu      $a3, $a0, 0xE4
    /* B740 8006EAA0 21284000 */  addu       $a1, $v0, $zero
    /* B744 8006EAA4 FA008424 */  addiu      $a0, $a0, 0xFA
    /* B748 8006EAA8 4001A0A4 */  sh         $zero, 0x140($a1)
  .L8006EAAC:
    /* B74C 8006EAAC 0000E290 */  lbu        $v0, 0x0($a3)
    /* B750 8006EAB0 00000000 */  nop
    /* B754 8006EAB4 0200422C */  sltiu      $v0, $v0, 0x2
    /* B758 8006EAB8 27004014 */  bnez       $v0, .L8006EB58
    /* B75C 8006EABC 02000224 */   addiu     $v0, $zero, 0x2
    /* B760 8006EAC0 12000211 */  beq        $t0, $v0, .L8006EB0C
    /* B764 8006EAC4 03000229 */   slti      $v0, $t0, 0x3
    /* B768 8006EAC8 05004010 */  beqz       $v0, .L8006EAE0
    /* B76C 8006EACC 01000224 */   addiu     $v0, $zero, 0x1
    /* B770 8006EAD0 08000211 */  beq        $t0, $v0, .L8006EAF4
    /* B774 8006EAD4 00000000 */   nop
    /* B778 8006EAD8 CEBA0108 */  j          .L8006EB38
    /* B77C 8006EADC 00000000 */   nop
  .L8006EAE0:
    /* B780 8006EAE0 03000224 */  addiu      $v0, $zero, 0x3
    /* B784 8006EAE4 0F000211 */  beq        $t0, $v0, .L8006EB24
    /* B788 8006EAE8 00000000 */   nop
    /* B78C 8006EAEC CEBA0108 */  j          .L8006EB38
    /* B790 8006EAF0 00000000 */   nop
  .L8006EAF4:
    /* B794 8006EAF4 00008284 */  lh         $v0, 0x0($a0)
    /* B798 8006EAF8 00000000 */  nop
    /* B79C 8006EAFC 16004010 */  beqz       $v0, .L8006EB58
    /* B7A0 8006EB00 00000000 */   nop
    /* B7A4 8006EB04 CEBA0108 */  j          .L8006EB38
    /* B7A8 8006EB08 00000000 */   nop
  .L8006EB0C:
    /* B7AC 8006EB0C 00008284 */  lh         $v0, 0x0($a0)
    /* B7B0 8006EB10 00000000 */  nop
    /* B7B4 8006EB14 08004010 */  beqz       $v0, .L8006EB38
    /* B7B8 8006EB18 00000000 */   nop
    /* B7BC 8006EB1C D7BA0108 */  j          .L8006EB5C
    /* B7C0 8006EB20 5C008424 */   addiu     $a0, $a0, 0x5C
  .L8006EB24:
    /* B7C4 8006EB24 00008284 */  lh         $v0, 0x0($a0)
    /* B7C8 8006EB28 00000000 */  nop
    /* B7CC 8006EB2C 02004228 */  slti       $v0, $v0, 0x2
    /* B7D0 8006EB30 09004014 */  bnez       $v0, .L8006EB58
    /* B7D4 8006EB34 00000000 */   nop
  .L8006EB38:
    /* B7D8 8006EB38 4001A294 */  lhu        $v0, 0x140($a1)
    /* B7DC 8006EB3C 00000000 */  nop
    /* B7E0 8006EB40 01004324 */  addiu      $v1, $v0, 0x1
    /* B7E4 8006EB44 00140200 */  sll        $v0, $v0, 16
    /* B7E8 8006EB48 C3130200 */  sra        $v0, $v0, 15
    /* B7EC 8006EB4C 2110A200 */  addu       $v0, $a1, $v0
    /* B7F0 8006EB50 4001A3A4 */  sh         $v1, 0x140($a1)
    /* B7F4 8006EB54 280146A4 */  sh         $a2, 0x128($v0)
  .L8006EB58:
    /* B7F8 8006EB58 5C008424 */  addiu      $a0, $a0, 0x5C
  .L8006EB5C:
    /* B7FC 8006EB5C 0100C624 */  addiu      $a2, $a2, 0x1
    /* B800 8006EB60 2400C228 */  slti       $v0, $a2, 0x24
    /* B804 8006EB64 D1FF4014 */  bnez       $v0, .L8006EAAC
    /* B808 8006EB68 5C00E724 */   addiu     $a3, $a3, 0x5C
    /* B80C 8006EB6C 0780023C */  lui        $v0, %hi(D_80072B60)
    /* B810 8006EB70 602B428C */  lw         $v0, %lo(D_80072B60)($v0)
    /* B814 8006EB74 00000000 */  nop
    /* B818 8006EB78 40014284 */  lh         $v0, 0x140($v0)
    /* B81C 8006EB7C 0800E003 */  jr         $ra
    /* B820 8006EB80 00000000 */   nop
endlabel Stg40_ListPartyDigi
