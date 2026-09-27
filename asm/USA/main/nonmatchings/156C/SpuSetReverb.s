nonmatching SpuSetReverb, 0xE8

glabel SpuSetReverb
    /* 2BF94 8003B794 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2BF98 8003B798 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2BF9C 8003B79C 21808000 */  addu       $s0, $a0, $zero
    /* 2BFA0 8003B7A0 06000012 */  beqz       $s0, .L8003B7BC
    /* 2BFA4 8003B7A4 1400BFAF */   sw        $ra, 0x14($sp)
    /* 2BFA8 8003B7A8 01000224 */  addiu      $v0, $zero, 0x1
    /* 2BFAC 8003B7AC 12000212 */  beq        $s0, $v0, .L8003B7F8
    /* 2BFB0 8003B7B0 00000000 */   nop
    /* 2BFB4 8003B7B4 19EE0008 */  j          .L8003B864
    /* 2BFB8 8003B7B8 00000000 */   nop
  .L8003B7BC:
    /* 2BFBC 8003B7BC 0580023C */  lui        $v0, %hi(D_8004FE28)
    /* 2BFC0 8003B7C0 28FE428C */  lw         $v0, %lo(D_8004FE28)($v0)
    /* 2BFC4 8003B7C4 00000000 */  nop
    /* 2BFC8 8003B7C8 AA014494 */  lhu        $a0, 0x1AA($v0)
    /* 2BFCC 8003B7CC 0580013C */  lui        $at, %hi(D_8004FDBC)
    /* 2BFD0 8003B7D0 BCFD20AC */  sw         $zero, %lo(D_8004FDBC)($at)
    /* 2BFD4 8003B7D4 7FFF8330 */  andi       $v1, $a0, 0xFF7F
    /* 2BFD8 8003B7D8 AA0143A4 */  sh         $v1, 0x1AA($v0)
    /* 2BFDC 8003B7DC 840140A4 */  sh         $zero, 0x184($v0)
    /* 2BFE0 8003B7E0 860140A4 */  sh         $zero, 0x186($v0)
    /* 2BFE4 8003B7E4 0580023C */  lui        $v0, %hi(D_8004FDD0)
    /* 2BFE8 8003B7E8 D0FD4224 */  addiu      $v0, $v0, %lo(D_8004FDD0)
    /* 2BFEC 8003B7EC 000040A4 */  sh         $zero, 0x0($v0)
    /* 2BFF0 8003B7F0 19EE0008 */  j          .L8003B864
    /* 2BFF4 8003B7F4 020040A4 */   sh        $zero, 0x2($v0)
  .L8003B7F8:
    /* 2BFF8 8003B7F8 0580023C */  lui        $v0, %hi(D_8004FDC0)
    /* 2BFFC 8003B7FC C0FD428C */  lw         $v0, %lo(D_8004FDC0)($v0)
    /* 2C000 8003B800 00000000 */  nop
    /* 2C004 8003B804 0F005010 */  beq        $v0, $s0, .L8003B844
    /* 2C008 8003B808 00000000 */   nop
    /* 2C00C 8003B80C 0580043C */  lui        $a0, %hi(D_8004FDC4)
    /* 2C010 8003B810 C4FD848C */  lw         $a0, %lo(D_8004FDC4)($a0)
    /* 2C014 8003B814 41EE000C */  jal        _SpuIsInAllocateArea_
    /* 2C018 8003B818 00000000 */   nop
    /* 2C01C 8003B81C 09004010 */  beqz       $v0, .L8003B844
    /* 2C020 8003B820 00000000 */   nop
    /* 2C024 8003B824 0580033C */  lui        $v1, %hi(D_8004FE28)
    /* 2C028 8003B828 28FE638C */  lw         $v1, %lo(D_8004FE28)($v1)
    /* 2C02C 8003B82C 00000000 */  nop
    /* 2C030 8003B830 AA016494 */  lhu        $a0, 0x1AA($v1)
    /* 2C034 8003B834 0580013C */  lui        $at, %hi(D_8004FDBC)
    /* 2C038 8003B838 BCFD20AC */  sw         $zero, %lo(D_8004FDBC)($at)
    /* 2C03C 8003B83C 18EE0008 */  j          .L8003B860
    /* 2C040 8003B840 7FFF8230 */   andi      $v0, $a0, 0xFF7F
  .L8003B844:
    /* 2C044 8003B844 0580033C */  lui        $v1, %hi(D_8004FE28)
    /* 2C048 8003B848 28FE638C */  lw         $v1, %lo(D_8004FE28)($v1)
    /* 2C04C 8003B84C 00000000 */  nop
    /* 2C050 8003B850 AA016494 */  lhu        $a0, 0x1AA($v1)
    /* 2C054 8003B854 0580013C */  lui        $at, %hi(D_8004FDBC)
    /* 2C058 8003B858 BCFD30AC */  sw         $s0, %lo(D_8004FDBC)($at)
    /* 2C05C 8003B85C 80008234 */  ori        $v0, $a0, 0x80
  .L8003B860:
    /* 2C060 8003B860 AA0162A4 */  sh         $v0, 0x1AA($v1)
  .L8003B864:
    /* 2C064 8003B864 0580023C */  lui        $v0, %hi(D_8004FDBC)
    /* 2C068 8003B868 BCFD428C */  lw         $v0, %lo(D_8004FDBC)($v0)
    /* 2C06C 8003B86C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 2C070 8003B870 1000B08F */  lw         $s0, 0x10($sp)
    /* 2C074 8003B874 0800E003 */  jr         $ra
    /* 2C078 8003B878 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel SpuSetReverb
    /* 2C07C 8003B87C 00000000 */  nop
    /* 2C080 8003B880 00000000 */  nop
