nonmatching func_8002C774, 0xB4

glabel func_8002C774
    /* 1CF74 8002C774 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 1CF78 8002C778 3400B1AF */  sw         $s1, 0x34($sp)
    /* 1CF7C 8002C77C 2188A000 */  addu       $s1, $a1, $zero
    /* 1CF80 8002C780 0BB6023C */  lui        $v0, (0xB60B60B7 >> 16)
    /* 1CF84 8002C784 B7604234 */  ori        $v0, $v0, (0xB60B60B7 & 0xFFFF)
    /* 1CF88 8002C788 18002202 */  mult       $s1, $v0
    /* 1CF8C 8002C78C 3800B2AF */  sw         $s2, 0x38($sp)
    /* 1CF90 8002C790 21908000 */  addu       $s2, $a0, $zero
    /* 1CF94 8002C794 C3171100 */  sra        $v0, $s1, 31
    /* 1CF98 8002C798 3C00BFAF */  sw         $ra, 0x3C($sp)
    /* 1CF9C 8002C79C 3000B0AF */  sw         $s0, 0x30($sp)
    /* 1CFA0 8002C7A0 10300000 */  mfhi       $a2
    /* 1CFA4 8002C7A4 2180D100 */  addu       $s0, $a2, $s1
    /* 1CFA8 8002C7A8 03821000 */  sra        $s0, $s0, 8
    /* 1CFAC 8002C7AC 23800202 */  subu       $s0, $s0, $v0
    /* 1CFB0 8002C7B0 F1B2000C */  jal        func_8002CBC4
    /* 1CFB4 8002C7B4 21200002 */   addu      $a0, $s0, $zero
    /* 1CFB8 8002C7B8 21200002 */  addu       $a0, $s0, $zero
    /* 1CFBC 8002C7BC BDB2000C */  jal        func_8002CAF4
    /* 1CFC0 8002C7C0 21804000 */   addu      $s0, $v0, $zero
    /* 1CFC4 8002C7C4 12002012 */  beqz       $s1, .L8002C810
    /* 1CFC8 8002C7C8 21184000 */   addu      $v1, $v0, $zero
    /* 1CFCC 8002C7CC 21204002 */  addu       $a0, $s2, $zero
    /* 1CFD0 8002C7D0 23100300 */  negu       $v0, $v1
    /* 1CFD4 8002C7D4 1200A2A7 */  sh         $v0, 0x12($sp)
    /* 1CFD8 8002C7D8 00100224 */  addiu      $v0, $zero, 0x1000
    /* 1CFDC 8002C7DC 1000A527 */  addiu      $a1, $sp, 0x10
    /* 1CFE0 8002C7E0 1000B0A7 */  sh         $s0, 0x10($sp)
    /* 1CFE4 8002C7E4 1400A0A7 */  sh         $zero, 0x14($sp)
    /* 1CFE8 8002C7E8 1600A3A7 */  sh         $v1, 0x16($sp)
    /* 1CFEC 8002C7EC 1800B0A7 */  sh         $s0, 0x18($sp)
    /* 1CFF0 8002C7F0 1A00A0A7 */  sh         $zero, 0x1A($sp)
    /* 1CFF4 8002C7F4 1C00A0A7 */  sh         $zero, 0x1C($sp)
    /* 1CFF8 8002C7F8 1E00A0A7 */  sh         $zero, 0x1E($sp)
    /* 1CFFC 8002C7FC 2000A2A7 */  sh         $v0, 0x20($sp)
    /* 1D000 8002C800 2400A0AF */  sw         $zero, 0x24($sp)
    /* 1D004 8002C804 2800A0AF */  sw         $zero, 0x28($sp)
    /* 1D008 8002C808 89B4000C */  jal        MulMatrix
    /* 1D00C 8002C80C 2C00A0AF */   sw        $zero, 0x2C($sp)
  .L8002C810:
    /* 1D010 8002C810 3C00BF8F */  lw         $ra, 0x3C($sp)
    /* 1D014 8002C814 3800B28F */  lw         $s2, 0x38($sp)
    /* 1D018 8002C818 3400B18F */  lw         $s1, 0x34($sp)
    /* 1D01C 8002C81C 3000B08F */  lw         $s0, 0x30($sp)
    /* 1D020 8002C820 0800E003 */  jr         $ra
    /* 1D024 8002C824 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_8002C774
    /* 1D028 8002C828 00000000 */  nop
    /* 1D02C 8002C82C 00000000 */  nop
    /* 1D030 8002C830 00000000 */  nop
