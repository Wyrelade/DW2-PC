nonmatching func_80063A6C, 0xBC

glabel func_80063A6C
    /* 70C 80063A6C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 710 80063A70 1000B0AF */  sw         $s0, 0x10($sp)
    /* 714 80063A74 21808000 */  addu       $s0, $a0, $zero
    /* 718 80063A78 1400BFAF */  sw         $ra, 0x14($sp)
    /* 71C 80063A7C 1000028E */  lw         $v0, 0x10($s0)
    /* 720 80063A80 00000000 */  nop
    /* 724 80063A84 24004014 */  bnez       $v0, .L80063B18
    /* 728 80063A88 0780023C */   lui       $v0, %hi(D_80073CC0)
    /* 72C 80063A8C C03C428C */  lw         $v0, %lo(D_80073CC0)($v0)
    /* 730 80063A90 00000000 */  nop
    /* 734 80063A94 04004010 */  beqz       $v0, .L80063AA8
    /* 738 80063A98 0780023C */   lui       $v0, %hi(D_80073008)
    /* 73C 80063A9C 0830428C */  lw         $v0, %lo(D_80073008)($v0)
    /* 740 80063AA0 B88E0108 */  j          .L80063AE0
    /* 744 80063AA4 0C0002AE */   sw        $v0, 0xC($s0)
  .L80063AA8:
    /* 748 80063AA8 0780043C */  lui        $a0, %hi(D_80072FF0)
    /* 74C 80063AAC 0780033C */  lui        $v1, %hi(D_8007300C)
    /* 750 80063AB0 0680023C */  lui        $v0, %hi(D_8005E5DD)
    /* 754 80063AB4 DDE54290 */  lbu        $v0, %lo(D_8005E5DD)($v0)
    /* 758 80063AB8 0C306324 */  addiu      $v1, $v1, %lo(D_8007300C)
    /* 75C 80063ABC 80100200 */  sll        $v0, $v0, 2
    /* 760 80063AC0 21104300 */  addu       $v0, $v0, $v1
    /* 764 80063AC4 0000428C */  lw         $v0, 0x0($v0)
    /* 768 80063AC8 F02F8424 */  addiu      $a0, $a0, %lo(D_80072FF0)
    /* 76C 80063ACC 80100200 */  sll        $v0, $v0, 2
    /* 770 80063AD0 21104400 */  addu       $v0, $v0, $a0
    /* 774 80063AD4 0000428C */  lw         $v0, 0x0($v0)
    /* 778 80063AD8 00000000 */  nop
    /* 77C 80063ADC 0C0002AE */  sw         $v0, 0xC($s0)
  .L80063AE0:
    /* 780 80063AE0 21200002 */  addu       $a0, $s0, $zero
    /* 784 80063AE4 0480053C */  lui        $a1, %hi(D_80043704)
    /* 788 80063AE8 0437A524 */  addiu      $a1, $a1, %lo(D_80043704)
    /* 78C 80063AEC 1083000C */  jal        Actor_InitTransform
    /* 790 80063AF0 21300000 */   addu      $a2, $zero, $zero
    /* 794 80063AF4 0C00058E */  lw         $a1, 0xC($s0)
    /* 798 80063AF8 6F7F000C */  jal        Gfx_AttachModel
    /* 79C 80063AFC 21200002 */   addu      $a0, $s0, $zero
    /* 7A0 80063B00 21200002 */  addu       $a0, $s0, $zero
    /* 7A4 80063B04 05000324 */  addiu      $v1, $zero, 0x5
    /* 7A8 80063B08 7A7D000C */  jal        Gfx_ResetModelBones
    /* 7AC 80063B0C 3C0043AC */   sw        $v1, 0x3C($v0)
    /* 7B0 80063B10 5145000C */  jal        Task_NextState0
    /* 7B4 80063B14 21200002 */   addu      $a0, $s0, $zero
  .L80063B18:
    /* 7B8 80063B18 1400BF8F */  lw         $ra, 0x14($sp)
    /* 7BC 80063B1C 1000B08F */  lw         $s0, 0x10($sp)
    /* 7C0 80063B20 0800E003 */  jr         $ra
    /* 7C4 80063B24 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80063A6C
