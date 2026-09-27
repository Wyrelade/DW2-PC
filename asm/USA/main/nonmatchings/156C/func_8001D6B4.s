nonmatching func_8001D6B4, 0x1D0

glabel func_8001D6B4
    /* DEB4 8001D6B4 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* DEB8 8001D6B8 1800B2AF */  sw         $s2, 0x18($sp)
    /* DEBC 8001D6BC 21908000 */  addu       $s2, $a0, $zero
    /* DEC0 8001D6C0 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* DEC4 8001D6C4 21980000 */  addu       $s3, $zero, $zero
    /* DEC8 8001D6C8 3000BFAF */  sw         $ra, 0x30($sp)
    /* DECC 8001D6CC 2C00B7AF */  sw         $s7, 0x2C($sp)
    /* DED0 8001D6D0 2800B6AF */  sw         $s6, 0x28($sp)
    /* DED4 8001D6D4 2400B5AF */  sw         $s5, 0x24($sp)
    /* DED8 8001D6D8 2000B4AF */  sw         $s4, 0x20($sp)
    /* DEDC 8001D6DC 1400B1AF */  sw         $s1, 0x14($sp)
    /* DEE0 8001D6E0 0B00A010 */  beqz       $a1, .L8001D710
    /* DEE4 8001D6E4 1000B0AF */   sw        $s0, 0x10($sp)
    /* DEE8 8001D6E8 0680033C */  lui        $v1, %hi(D_8005F770)
    /* DEEC 8001D6EC 70F76324 */  addiu      $v1, $v1, %lo(D_8005F770)
    /* DEF0 8001D6F0 1001628C */  lw         $v0, 0x110($v1)
    /* DEF4 8001D6F4 1401638C */  lw         $v1, 0x114($v1)
    /* DEF8 8001D6F8 40014238 */  xori       $v0, $v0, 0x140
    /* DEFC 8001D6FC 0100532C */  sltiu      $s3, $v0, 0x1
    /* DF00 8001D700 F0000224 */  addiu      $v0, $zero, 0xF0
    /* DF04 8001D704 02006214 */  bne        $v1, $v0, .L8001D710
    /* DF08 8001D708 00000000 */   nop
    /* DF0C 8001D70C 02007336 */  ori        $s3, $s3, 0x2
  .L8001D710:
    /* DF10 8001D710 0000428E */  lw         $v0, 0x0($s2)
    /* DF14 8001D714 00000000 */  nop
    /* DF18 8001D718 4F004010 */  beqz       $v0, .L8001D858
    /* DF1C 8001D71C 0680023C */   lui       $v0, %hi(D_8005F770)
    /* DF20 8001D720 70F75724 */  addiu      $s7, $v0, %lo(D_8005F770)
    /* DF24 8001D724 0480153C */  lui        $s5, %hi(D_8004167C)
    /* DF28 8001D728 7C16B126 */  addiu      $s1, $s5, %lo(D_8004167C)
    /* DF2C 8001D72C 18003626 */  addiu      $s6, $s1, 0x18
    /* DF30 8001D730 14005026 */  addiu      $s0, $s2, 0x14
  .L8001D734:
    /* DF34 8001D734 F7FF0292 */  lbu        $v0, -0x9($s0)
    /* DF38 8001D738 FBFF0392 */  lbu        $v1, -0x5($s0)
    /* DF3C 8001D73C 80100200 */  sll        $v0, $v0, 2
    /* DF40 8001D740 21105700 */  addu       $v0, $v0, $s7
    /* DF44 8001D744 3801548C */  lw         $s4, 0x138($v0)
    /* DF48 8001D748 3E006010 */  beqz       $v1, .L8001D844
    /* DF4C 8001D74C 00000000 */   nop
    /* DF50 8001D750 FAFF0292 */  lbu        $v0, -0x6($s0)
    /* DF54 8001D754 00000000 */  nop
    /* DF58 8001D758 0D004010 */  beqz       $v0, .L8001D790
    /* DF5C 8001D75C 00000000 */   nop
    /* DF60 8001D760 06006016 */  bnez       $s3, .L8001D77C
    /* DF64 8001D764 00100224 */   addiu     $v0, $zero, 0x1000
    /* DF68 8001D768 21204002 */  addu       $a0, $s2, $zero
    /* DF6C 8001D76C A773000C */  jal        Gfx_DrawPartSprites
    /* DF70 8001D770 21288002 */   addu      $a1, $s4, $zero
    /* DF74 8001D774 12760008 */  j          .L8001D848
    /* DF78 8001D778 28005226 */   addiu     $s2, $s2, 0x28
  .L8001D77C:
    /* DF7C 8001D77C 100000A6 */  sh         $zero, 0x10($s0)
    /* DF80 8001D780 0E0000A6 */  sh         $zero, 0xE($s0)
    /* DF84 8001D784 0C0000A6 */  sh         $zero, 0xC($s0)
    /* DF88 8001D788 FCFF02AE */  sw         $v0, -0x4($s0)
    /* DF8C 8001D78C 000002AE */  sw         $v0, 0x0($s0)
  .L8001D790:
    /* DF90 8001D790 7C16A38E */  lw         $v1, %lo(D_8004167C)($s5)
    /* DF94 8001D794 0C00028E */  lw         $v0, 0xC($s0)
    /* DF98 8001D798 00000000 */  nop
    /* DF9C 8001D79C 10006214 */  bne        $v1, $v0, .L8001D7E0
    /* DFA0 8001D7A0 00000000 */   nop
    /* DFA4 8001D7A4 04002386 */  lh         $v1, 0x4($s1)
    /* DFA8 8001D7A8 10000286 */  lh         $v0, 0x10($s0)
    /* DFAC 8001D7AC 00000000 */  nop
    /* DFB0 8001D7B0 0B006214 */  bne        $v1, $v0, .L8001D7E0
    /* DFB4 8001D7B4 00000000 */   nop
    /* DFB8 8001D7B8 0800238E */  lw         $v1, 0x8($s1)
    /* DFBC 8001D7BC FCFF028E */  lw         $v0, -0x4($s0)
    /* DFC0 8001D7C0 00000000 */  nop
    /* DFC4 8001D7C4 06006214 */  bne        $v1, $v0, .L8001D7E0
    /* DFC8 8001D7C8 00000000 */   nop
    /* DFCC 8001D7CC 0C00238E */  lw         $v1, 0xC($s1)
    /* DFD0 8001D7D0 0000028E */  lw         $v0, 0x0($s0)
    /* DFD4 8001D7D4 00000000 */  nop
    /* DFD8 8001D7D8 15006210 */  beq        $v1, $v0, .L8001D830
    /* DFDC 8001D7DC 21204002 */   addu      $a0, $s2, $zero
  .L8001D7E0:
    /* DFE0 8001D7E0 7C16AB26 */  addiu      $t3, $s5, %lo(D_8004167C)
    /* DFE4 8001D7E4 0F00088A */  lwl        $t0, 0xF($s0)
    /* DFE8 8001D7E8 0C00089A */  lwr        $t0, 0xC($s0)
    /* DFEC 8001D7EC 1300098A */  lwl        $t1, 0x13($s0)
    /* DFF0 8001D7F0 1000099A */  lwr        $t1, 0x10($s0)
    /* DFF4 8001D7F4 030068A9 */  swl        $t0, 0x3($t3)
    /* DFF8 8001D7F8 000068B9 */  swr        $t0, 0x0($t3)
    /* DFFC 8001D7FC 070069A9 */  swl        $t1, 0x7($t3)
    /* E000 8001D800 040069B9 */  swr        $t1, 0x4($t3)
    /* E004 8001D804 FCFF028E */  lw         $v0, -0x4($s0)
    /* E008 8001D808 21202002 */  addu       $a0, $s1, $zero
    /* E00C 8001D80C 080022AE */  sw         $v0, 0x8($s1)
    /* E010 8001D810 0000028E */  lw         $v0, 0x0($s0)
    /* E014 8001D814 2128C002 */  addu       $a1, $s6, $zero
    /* E018 8001D818 D1B5000C */  jal        func_8002D744
    /* E01C 8001D81C 0C0022AE */   sw        $v0, 0xC($s1)
    /* E020 8001D820 2120C002 */  addu       $a0, $s6, $zero
    /* E024 8001D824 29B5000C */  jal        ScaleMatrix
    /* E028 8001D828 08002526 */   addiu     $a1, $s1, 0x8
    /* E02C 8001D82C 21204002 */  addu       $a0, $s2, $zero
  .L8001D830:
    /* E030 8001D830 0480053C */  lui        $a1, %hi(D_80041694)
    /* E034 8001D834 9416A524 */  addiu      $a1, $a1, %lo(D_80041694)
    /* E038 8001D838 21308002 */  addu       $a2, $s4, $zero
    /* E03C 8001D83C 4174000C */  jal        Gfx_DrawPartQuadsRot
    /* E040 8001D840 21386002 */   addu      $a3, $s3, $zero
  .L8001D844:
    /* E044 8001D844 28005226 */  addiu      $s2, $s2, 0x28
  .L8001D848:
    /* E048 8001D848 0000428E */  lw         $v0, 0x0($s2)
    /* E04C 8001D84C 00000000 */  nop
    /* E050 8001D850 B8FF4014 */  bnez       $v0, .L8001D734
    /* E054 8001D854 28001026 */   addiu     $s0, $s0, 0x28
  .L8001D858:
    /* E058 8001D858 3000BF8F */  lw         $ra, 0x30($sp)
    /* E05C 8001D85C 2C00B78F */  lw         $s7, 0x2C($sp)
    /* E060 8001D860 2800B68F */  lw         $s6, 0x28($sp)
    /* E064 8001D864 2400B58F */  lw         $s5, 0x24($sp)
    /* E068 8001D868 2000B48F */  lw         $s4, 0x20($sp)
    /* E06C 8001D86C 1C00B38F */  lw         $s3, 0x1C($sp)
    /* E070 8001D870 1800B28F */  lw         $s2, 0x18($sp)
    /* E074 8001D874 1400B18F */  lw         $s1, 0x14($sp)
    /* E078 8001D878 1000B08F */  lw         $s0, 0x10($sp)
    /* E07C 8001D87C 0800E003 */  jr         $ra
    /* E080 8001D880 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_8001D6B4
