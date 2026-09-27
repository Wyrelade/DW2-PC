nonmatching func_8006EC94, 0x2BC

glabel func_8006EC94
    /* B934 8006EC94 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* B938 8006EC98 1000B0AF */  sw         $s0, 0x10($sp)
    /* B93C 8006EC9C 21808000 */  addu       $s0, $a0, $zero
    /* B940 8006ECA0 1800B2AF */  sw         $s2, 0x18($sp)
    /* B944 8006ECA4 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* B948 8006ECA8 1400B1AF */  sw         $s1, 0x14($sp)
    /* B94C 8006ECAC 1C00028E */  lw         $v0, 0x1C($s0)
    /* B950 8006ECB0 3800118E */  lw         $s1, 0x38($s0)
    /* B954 8006ECB4 09004014 */  bnez       $v0, .L8006ECDC
    /* B958 8006ECB8 2190A000 */   addu      $s2, $a1, $zero
    /* B95C 8006ECBC 2000028E */  lw         $v0, 0x20($s0)
    /* B960 8006ECC0 00000000 */  nop
    /* B964 8006ECC4 05004014 */  bnez       $v0, .L8006ECDC
    /* B968 8006ECC8 00000000 */   nop
    /* B96C 8006ECCC BA83000C */  jal        Actor_StopAxisMotion
    /* B970 8006ECD0 01000524 */   addiu     $a1, $zero, 0x1
    /* B974 8006ECD4 3DBB0108 */  j          .L8006ECF4
    /* B978 8006ECD8 00000000 */   nop
  .L8006ECDC:
    /* B97C 8006ECDC 21200002 */  addu       $a0, $s0, $zero
    /* B980 8006ECE0 5583000C */  jal        func_80020D54
    /* B984 8006ECE4 01000524 */   addiu     $a1, $zero, 0x1
    /* B988 8006ECE8 21200002 */  addu       $a0, $s0, $zero
    /* B98C 8006ECEC 8083000C */  jal        func_80020E00
    /* B990 8006ECF0 02000524 */   addiu     $a1, $zero, 0x2
  .L8006ECF4:
    /* B994 8006ECF4 1C00038E */  lw         $v1, 0x1C($s0)
    /* B998 8006ECF8 00000000 */  nop
    /* B99C 8006ECFC 0500622C */  sltiu      $v0, $v1, 0x5
    /* B9A0 8006ED00 08004010 */  beqz       $v0, .L8006ED24
    /* B9A4 8006ED04 0680023C */   lui       $v0, %hi(jtbl_80063784)
    /* B9A8 8006ED08 84374224 */  addiu      $v0, $v0, %lo(jtbl_80063784)
    /* B9AC 8006ED0C 80180300 */  sll        $v1, $v1, 2
    /* B9B0 8006ED10 21186200 */  addu       $v1, $v1, $v0
    /* B9B4 8006ED14 0000628C */  lw         $v0, 0x0($v1)
    /* B9B8 8006ED18 00000000 */  nop
    /* B9BC 8006ED1C 08004000 */  jr         $v0
    /* B9C0 8006ED20 00000000 */   nop
  jlabel .L8006ED24
    /* B9C4 8006ED24 2000038E */  lw         $v1, 0x20($s0)
    /* B9C8 8006ED28 00000000 */  nop
    /* B9CC 8006ED2C 03006010 */  beqz       $v1, .L8006ED3C
    /* B9D0 8006ED30 01000224 */   addiu     $v0, $zero, 0x1
    /* B9D4 8006ED34 32006210 */  beq        $v1, $v0, .L8006EE00
    /* B9D8 8006ED38 00000000 */   nop
  .L8006ED3C:
    /* B9DC 8006ED3C 21200002 */  addu       $a0, $s0, $zero
    /* B9E0 8006ED40 02000524 */  addiu      $a1, $zero, 0x2
    /* B9E4 8006ED44 0780063C */  lui        $a2, %hi(D_800732AC)
    /* B9E8 8006ED48 AC83000C */  jal        Actor_SetAxisMotion
    /* B9EC 8006ED4C AC32C624 */   addiu     $a2, $a2, %lo(D_800732AC)
    /* B9F0 8006ED50 21200002 */  addu       $a0, $s0, $zero
    /* B9F4 8006ED54 9D7C000C */  jal        Anim_HasModelAnim
    /* B9F8 8006ED58 14000524 */   addiu     $a1, $zero, 0x14
    /* B9FC 8006ED5C 05004014 */  bnez       $v0, .L8006ED74
    /* BA00 8006ED60 21200002 */   addu      $a0, $s0, $zero
    /* BA04 8006ED64 6645000C */  jal        Task_NextState3
    /* BA08 8006ED68 21200002 */   addu      $a0, $s0, $zero
    /* BA0C 8006ED6C 66BB0108 */  j          .L8006ED98
    /* BA10 8006ED70 00000000 */   nop
  .L8006ED74:
    /* BA14 8006ED74 14BA010C */  jal        func_8006E850
    /* BA18 8006ED78 14000524 */   addiu     $a1, $zero, 0x14
    /* BA1C 8006ED7C 21200002 */  addu       $a0, $s0, $zero
    /* BA20 8006ED80 01000524 */  addiu      $a1, $zero, 0x1
    /* BA24 8006ED84 0780063C */  lui        $a2, %hi(D_80073294)
    /* BA28 8006ED88 AC83000C */  jal        Actor_SetAxisMotion
    /* BA2C 8006ED8C 9432C624 */   addiu     $a2, $a2, %lo(D_80073294)
    /* BA30 8006ED90 C2BB0108 */  j          .L8006EF08
    /* BA34 8006ED94 00000000 */   nop
  jlabel .L8006ED98
    /* BA38 8006ED98 2000038E */  lw         $v1, 0x20($s0)
    /* BA3C 8006ED9C 00000000 */  nop
    /* BA40 8006EDA0 03006010 */  beqz       $v1, .L8006EDB0
    /* BA44 8006EDA4 01000224 */   addiu     $v0, $zero, 0x1
    /* BA48 8006EDA8 15006210 */  beq        $v1, $v0, .L8006EE00
    /* BA4C 8006EDAC 00000000 */   nop
  .L8006EDB0:
    /* BA50 8006EDB0 17BB010C */  jal        func_8006EC5C
    /* BA54 8006EDB4 21200002 */   addu      $a0, $s0, $zero
    /* BA58 8006EDB8 21200002 */  addu       $a0, $s0, $zero
    /* BA5C 8006EDBC 9D7C000C */  jal        Anim_HasModelAnim
    /* BA60 8006EDC0 15000524 */   addiu     $a1, $zero, 0x15
    /* BA64 8006EDC4 05004014 */  bnez       $v0, .L8006EDDC
    /* BA68 8006EDC8 21200002 */   addu      $a0, $s0, $zero
    /* BA6C 8006EDCC 6645000C */  jal        Task_NextState3
    /* BA70 8006EDD0 21200002 */   addu      $a0, $s0, $zero
    /* BA74 8006EDD4 8CBB0108 */  j          .L8006EE30
    /* BA78 8006EDD8 00000000 */   nop
  .L8006EDDC:
    /* BA7C 8006EDDC 14BA010C */  jal        func_8006E850
    /* BA80 8006EDE0 15000524 */   addiu     $a1, $zero, 0x15
    /* BA84 8006EDE4 21200002 */  addu       $a0, $s0, $zero
    /* BA88 8006EDE8 01000524 */  addiu      $a1, $zero, 0x1
    /* BA8C 8006EDEC 0780063C */  lui        $a2, %hi(D_800732A0)
    /* BA90 8006EDF0 AC83000C */  jal        Actor_SetAxisMotion
    /* BA94 8006EDF4 A032C624 */   addiu     $a2, $a2, %lo(D_800732A0)
    /* BA98 8006EDF8 C2BB0108 */  j          .L8006EF08
    /* BA9C 8006EDFC 00000000 */   nop
  .L8006EE00:
    /* BAA0 8006EE00 3400228E */  lw         $v0, 0x34($s1)
    /* BAA4 8006EE04 00000000 */  nop
    /* BAA8 8006EE08 4B004018 */  blez       $v0, .L8006EF38
    /* BAAC 8006EE0C 21200002 */   addu      $a0, $s0, $zero
    /* BAB0 8006EE10 BA83000C */  jal        Actor_StopAxisMotion
    /* BAB4 8006EE14 01000524 */   addiu     $a1, $zero, 0x1
    /* BAB8 8006EE18 21200002 */  addu       $a0, $s0, $zero
    /* BABC 8006EE1C 340020AE */  sw         $zero, 0x34($s1)
    /* BAC0 8006EE20 6645000C */  jal        Task_NextState3
    /* BAC4 8006EE24 4C0020AE */   sw        $zero, 0x4C($s1)
    /* BAC8 8006EE28 CEBB0108 */  j          .L8006EF38
    /* BACC 8006EE2C 00000000 */   nop
  jlabel .L8006EE30
    /* BAD0 8006EE30 2000038E */  lw         $v1, 0x20($s0)
    /* BAD4 8006EE34 00000000 */  nop
    /* BAD8 8006EE38 03006010 */  beqz       $v1, .L8006EE48
    /* BADC 8006EE3C 01000224 */   addiu     $v0, $zero, 0x1
    /* BAE0 8006EE40 06006210 */  beq        $v1, $v0, .L8006EE5C
    /* BAE4 8006EE44 00000000 */   nop
  .L8006EE48:
    /* BAE8 8006EE48 17BB010C */  jal        func_8006EC5C
    /* BAEC 8006EE4C 21200002 */   addu      $a0, $s0, $zero
    /* BAF0 8006EE50 21200002 */  addu       $a0, $s0, $zero
    /* BAF4 8006EE54 C0BB0108 */  j          .L8006EF00
    /* BAF8 8006EE58 16000524 */   addiu     $a1, $zero, 0x16
  .L8006EE5C:
    /* BAFC 8006EE5C 3C00028E */  lw         $v0, 0x3C($s0)
    /* BB00 8006EE60 00000000 */  nop
    /* BB04 8006EE64 6000428C */  lw         $v0, 0x60($v0)
    /* BB08 8006EE68 00000000 */  nop
    /* BB0C 8006EE6C 32004104 */  bgez       $v0, .L8006EF38
    /* BB10 8006EE70 00000000 */   nop
    /* BB14 8006EE74 6645000C */  jal        Task_NextState3
    /* BB18 8006EE78 21200002 */   addu      $a0, $s0, $zero
    /* BB1C 8006EE7C 2E004012 */  beqz       $s2, .L8006EF38
    /* BB20 8006EE80 00000000 */   nop
    /* BB24 8006EE84 6645000C */  jal        Task_NextState3
    /* BB28 8006EE88 21200002 */   addu      $a0, $s0, $zero
    /* BB2C 8006EE8C CEBB0108 */  j          .L8006EF38
    /* BB30 8006EE90 00000000 */   nop
  jlabel .L8006EE94
    /* BB34 8006EE94 2000038E */  lw         $v1, 0x20($s0)
    /* BB38 8006EE98 00000000 */  nop
    /* BB3C 8006EE9C 03006010 */  beqz       $v1, .L8006EEAC
    /* BB40 8006EEA0 01000224 */   addiu     $v0, $zero, 0x1
    /* BB44 8006EEA4 04006210 */  beq        $v1, $v0, .L8006EEB8
    /* BB48 8006EEA8 00000000 */   nop
  .L8006EEAC:
    /* BB4C 8006EEAC 21200002 */  addu       $a0, $s0, $zero
    /* BB50 8006EEB0 C0BB0108 */  j          .L8006EF00
    /* BB54 8006EEB4 5A000524 */   addiu     $a1, $zero, 0x5A
  .L8006EEB8:
    /* BB58 8006EEB8 3C00028E */  lw         $v0, 0x3C($s0)
    /* BB5C 8006EEBC 00000000 */  nop
    /* BB60 8006EEC0 6000428C */  lw         $v0, 0x60($v0)
    /* BB64 8006EEC4 00000000 */  nop
    /* BB68 8006EEC8 1B004104 */  bgez       $v0, .L8006EF38
    /* BB6C 8006EECC 21200002 */   addu      $a0, $s0, $zero
    /* BB70 8006EED0 7745000C */  jal        Task_SetState1
    /* BB74 8006EED4 21280000 */   addu      $a1, $zero, $zero
    /* BB78 8006EED8 CEBB0108 */  j          .L8006EF38
    /* BB7C 8006EEDC 00000000 */   nop
  jlabel .L8006EEE0
    /* BB80 8006EEE0 2000038E */  lw         $v1, 0x20($s0)
    /* BB84 8006EEE4 00000000 */  nop
    /* BB88 8006EEE8 03006010 */  beqz       $v1, .L8006EEF8
    /* BB8C 8006EEEC 01000224 */   addiu     $v0, $zero, 0x1
    /* BB90 8006EEF0 09006210 */  beq        $v1, $v0, .L8006EF18
    /* BB94 8006EEF4 00000000 */   nop
  .L8006EEF8:
    /* BB98 8006EEF8 21200002 */  addu       $a0, $s0, $zero
    /* BB9C 8006EEFC 64000524 */  addiu      $a1, $zero, 0x64
  .L8006EF00:
    /* BBA0 8006EF00 14BA010C */  jal        func_8006E850
    /* BBA4 8006EF04 00000000 */   nop
  .L8006EF08:
    /* BBA8 8006EF08 6B45000C */  jal        Task_NextState4
    /* BBAC 8006EF0C 21200002 */   addu      $a0, $s0, $zero
    /* BBB0 8006EF10 CEBB0108 */  j          .L8006EF38
    /* BBB4 8006EF14 00000000 */   nop
  .L8006EF18:
    /* BBB8 8006EF18 3C00028E */  lw         $v0, 0x3C($s0)
    /* BBBC 8006EF1C 00000000 */  nop
    /* BBC0 8006EF20 6000428C */  lw         $v0, 0x60($v0)
    /* BBC4 8006EF24 00000000 */  nop
    /* BBC8 8006EF28 03004010 */  beqz       $v0, .L8006EF38
    /* BBCC 8006EF2C 21200002 */   addu      $a0, $s0, $zero
    /* BBD0 8006EF30 7045000C */  jal        Task_SetState0
    /* BBD4 8006EF34 01000524 */   addiu     $a1, $zero, 0x1
  .L8006EF38:
    /* BBD8 8006EF38 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* BBDC 8006EF3C 1800B28F */  lw         $s2, 0x18($sp)
    /* BBE0 8006EF40 1400B18F */  lw         $s1, 0x14($sp)
    /* BBE4 8006EF44 1000B08F */  lw         $s0, 0x10($sp)
    /* BBE8 8006EF48 0800E003 */  jr         $ra
    /* BBEC 8006EF4C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8006EC94
