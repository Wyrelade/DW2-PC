nonmatching Stg40_AutomapDrawModes, 0x158

glabel Stg40_AutomapDrawModes
    /* C8F4 8006FC54 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* C8F8 8006FC58 3000B2AF */  sw         $s2, 0x30($sp)
    /* C8FC 8006FC5C 21908000 */  addu       $s2, $a0, $zero
    /* C900 8006FC60 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* C904 8006FC64 21880000 */  addu       $s1, $zero, $zero
    /* C908 8006FC68 2800B0AF */  sw         $s0, 0x28($sp)
    /* C90C 8006FC6C 21804002 */  addu       $s0, $s2, $zero
    /* C910 8006FC70 3400BFAF */  sw         $ra, 0x34($sp)
  .L8006FC74:
    /* C914 8006FC74 0780023C */  lui        $v0, %hi(Stg40_RootState)
    /* C918 8006FC78 602B428C */  lw         $v0, %lo(Stg40_RootState)($v0)
    /* C91C 8006FC7C 00000000 */  nop
    /* C920 8006FC80 7E004284 */  lh         $v0, 0x7E($v0)
    /* C924 8006FC84 00000000 */  nop
    /* C928 8006FC88 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* C92C 8006FC8C 0B002216 */  bne        $s1, $v0, .L8006FCBC
    /* C930 8006FC90 00000000 */   nop
    /* C934 8006FC94 62070286 */  lh         $v0, 0x762($s0)
    /* C938 8006FC98 62070396 */  lhu        $v1, 0x762($s0)
    /* C93C 8006FC9C 20004224 */  addiu      $v0, $v0, 0x20
    /* C940 8006FCA0 00014228 */  slti       $v0, $v0, 0x100
    /* C944 8006FCA4 03004010 */  beqz       $v0, .L8006FCB4
    /* C948 8006FCA8 21200002 */   addu      $a0, $s0, $zero
    /* C94C 8006FCAC 37BF0108 */  j          .L8006FCDC
    /* C950 8006FCB0 20006224 */   addiu     $v0, $v1, 0x20
  .L8006FCB4:
    /* C954 8006FCB4 37BF0108 */  j          .L8006FCDC
    /* C958 8006FCB8 FF000224 */   addiu     $v0, $zero, 0xFF
  .L8006FCBC:
    /* C95C 8006FCBC 62070286 */  lh         $v0, 0x762($s0)
    /* C960 8006FCC0 62070396 */  lhu        $v1, 0x762($s0)
    /* C964 8006FCC4 E0FF4224 */  addiu      $v0, $v0, -0x20
    /* C968 8006FCC8 03004004 */  bltz       $v0, .L8006FCD8
    /* C96C 8006FCCC 21200002 */   addu      $a0, $s0, $zero
    /* C970 8006FCD0 37BF0108 */  j          .L8006FCDC
    /* C974 8006FCD4 E0FF6224 */   addiu     $v0, $v1, -0x20
  .L8006FCD8:
    /* C978 8006FCD8 21100000 */  addu       $v0, $zero, $zero
  .L8006FCDC:
    /* C97C 8006FCDC 620782A4 */  sh         $v0, 0x762($a0)
    /* C980 8006FCE0 62070286 */  lh         $v0, 0x762($s0)
    /* C984 8006FCE4 00000000 */  nop
    /* C988 8006FCE8 25004010 */  beqz       $v0, .L8006FD80
    /* C98C 8006FCEC 00000000 */   nop
    /* C990 8006FCF0 05002012 */  beqz       $s1, .L8006FD08
    /* C994 8006FCF4 01000224 */   addiu     $v0, $zero, 0x1
    /* C998 8006FCF8 13002212 */  beq        $s1, $v0, .L8006FD48
    /* C99C 8006FCFC 21204002 */   addu      $a0, $s2, $zero
    /* C9A0 8006FD00 61BF0108 */  j          .L8006FD84
    /* C9A4 8006FD04 02001026 */   addiu     $s0, $s0, 0x2
  .L8006FD08:
    /* C9A8 8006FD08 0580023C */  lui        $v0, %hi(Dung_StatePtr)
    /* C9AC 8006FD0C 1C07428C */  lw         $v0, %lo(Dung_StatePtr)($v0)
    /* C9B0 8006FD10 21204002 */  addu       $a0, $s2, $zero
    /* C9B4 8006FD14 6810428C */  lw         $v0, 0x1068($v0)
    /* C9B8 8006FD18 50000524 */  addiu      $a1, $zero, 0x50
    /* C9BC 8006FD1C 00004784 */  lh         $a3, 0x0($v0)
    /* C9C0 8006FD20 02004384 */  lh         $v1, 0x2($v0)
    /* C9C4 8006FD24 11000224 */  addiu      $v0, $zero, 0x11
    /* C9C8 8006FD28 1400A2AF */  sw         $v0, 0x14($sp)
    /* C9CC 8006FD2C 1800A2AF */  sw         $v0, 0x18($sp)
    /* C9D0 8006FD30 03000224 */  addiu      $v0, $zero, 0x3
    /* C9D4 8006FD34 1C00A2AF */  sw         $v0, 0x1C($sp)
    /* C9D8 8006FD38 1000A3AF */  sw         $v1, 0x10($sp)
    /* C9DC 8006FD3C 62074286 */  lh         $v0, 0x762($s2)
    /* C9E0 8006FD40 5EBF0108 */  j          .L8006FD78
    /* C9E4 8006FD44 21300000 */   addu      $a2, $zero, $zero
  .L8006FD48:
    /* C9E8 8006FD48 21280000 */  addu       $a1, $zero, $zero
    /* C9EC 8006FD4C 2130A000 */  addu       $a2, $a1, $zero
    /* C9F0 8006FD50 18000224 */  addiu      $v0, $zero, 0x18
    /* C9F4 8006FD54 1000A2AF */  sw         $v0, 0x10($sp)
    /* C9F8 8006FD58 41000224 */  addiu      $v0, $zero, 0x41
    /* C9FC 8006FD5C 1400A2AF */  sw         $v0, 0x14($sp)
    /* CA00 8006FD60 31000224 */  addiu      $v0, $zero, 0x31
    /* CA04 8006FD64 1800A2AF */  sw         $v0, 0x18($sp)
    /* CA08 8006FD68 04000224 */  addiu      $v0, $zero, 0x4
    /* CA0C 8006FD6C 1C00A2AF */  sw         $v0, 0x1C($sp)
    /* CA10 8006FD70 64074286 */  lh         $v0, 0x764($s2)
    /* CA14 8006FD74 20000724 */  addiu      $a3, $zero, 0x20
  .L8006FD78:
    /* CA18 8006FD78 1BBE010C */  jal        Stg40_AutomapDrawWindow
    /* CA1C 8006FD7C 2000A2AF */   sw        $v0, 0x20($sp)
  .L8006FD80:
    /* CA20 8006FD80 02001026 */  addiu      $s0, $s0, 0x2
  .L8006FD84:
    /* CA24 8006FD84 01003126 */  addiu      $s1, $s1, 0x1
    /* CA28 8006FD88 0200222A */  slti       $v0, $s1, 0x2
    /* CA2C 8006FD8C B9FF4014 */  bnez       $v0, .L8006FC74
    /* CA30 8006FD90 00000000 */   nop
    /* CA34 8006FD94 3400BF8F */  lw         $ra, 0x34($sp)
    /* CA38 8006FD98 3000B28F */  lw         $s2, 0x30($sp)
    /* CA3C 8006FD9C 2C00B18F */  lw         $s1, 0x2C($sp)
    /* CA40 8006FDA0 2800B08F */  lw         $s0, 0x28($sp)
    /* CA44 8006FDA4 0800E003 */  jr         $ra
    /* CA48 8006FDA8 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel Stg40_AutomapDrawModes
