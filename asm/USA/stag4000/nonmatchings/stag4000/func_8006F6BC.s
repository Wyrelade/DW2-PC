nonmatching func_8006F6BC, 0x1B0

glabel func_8006F6BC
    /* C35C 8006F6BC D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* C360 8006F6C0 2800B6AF */  sw         $s6, 0x28($sp)
    /* C364 8006F6C4 0580163C */  lui        $s6, %hi(D_8005071C)
    /* C368 8006F6C8 1C07C28E */  lw         $v0, %lo(D_8005071C)($s6)
    /* C36C 8006F6CC 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* C370 8006F6D0 2400B5AF */  sw         $s5, 0x24($sp)
    /* C374 8006F6D4 2000B4AF */  sw         $s4, 0x20($sp)
    /* C378 8006F6D8 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* C37C 8006F6DC 1800B2AF */  sw         $s2, 0x18($sp)
    /* C380 8006F6E0 1400B1AF */  sw         $s1, 0x14($sp)
    /* C384 8006F6E4 1000B0AF */  sw         $s0, 0x10($sp)
    /* C388 8006F6E8 6810428C */  lw         $v0, 0x1068($v0)
    /* C38C 8006F6EC 21988000 */  addu       $s3, $a0, $zero
    /* C390 8006F6F0 00005184 */  lh         $s1, 0x0($v0)
    /* C394 8006F6F4 02005284 */  lh         $s2, 0x2($v0)
    /* C398 8006F6F8 6C076286 */  lh         $v0, 0x76C($s3)
    /* C39C 8006F6FC 6E076386 */  lh         $v1, 0x76E($s3)
    /* C3A0 8006F700 23A05100 */  subu       $s4, $v0, $s1
    /* C3A4 8006F704 03008016 */  bnez       $s4, .L8006F714
    /* C3A8 8006F708 23A87200 */   subu      $s5, $v1, $s2
    /* C3AC 8006F70C 4D00A012 */  beqz       $s5, .L8006F844
    /* C3B0 8006F710 00000000 */   nop
  .L8006F714:
    /* C3B4 8006F714 21206002 */  addu       $a0, $s3, $zero
    /* C3B8 8006F718 21282002 */  addu       $a1, $s1, $zero
    /* C3BC 8006F71C FDBC010C */  jal        func_8006F3F4
    /* C3C0 8006F720 21304002 */   addu      $a2, $s2, $zero
    /* C3C4 8006F724 0D00801A */  blez       $s4, .L8006F75C
    /* C3C8 8006F728 21206002 */   addu      $a0, $s3, $zero
    /* C3CC 8006F72C FFFF3026 */  addiu      $s0, $s1, -0x1
    /* C3D0 8006F730 21280002 */  addu       $a1, $s0, $zero
    /* C3D4 8006F734 8BBD010C */  jal        func_8006F62C
    /* C3D8 8006F738 FFFF4626 */   addiu     $a2, $s2, -0x1
    /* C3DC 8006F73C 21206002 */  addu       $a0, $s3, $zero
    /* C3E0 8006F740 21280002 */  addu       $a1, $s0, $zero
    /* C3E4 8006F744 8BBD010C */  jal        func_8006F62C
    /* C3E8 8006F748 21304002 */   addu      $a2, $s2, $zero
    /* C3EC 8006F74C 21206002 */  addu       $a0, $s3, $zero
    /* C3F0 8006F750 21280002 */  addu       $a1, $s0, $zero
    /* C3F4 8006F754 8BBD010C */  jal        func_8006F62C
    /* C3F8 8006F758 01004626 */   addiu     $a2, $s2, 0x1
  .L8006F75C:
    /* C3FC 8006F75C 0D008106 */  bgez       $s4, .L8006F794
    /* C400 8006F760 21206002 */   addu      $a0, $s3, $zero
    /* C404 8006F764 01003026 */  addiu      $s0, $s1, 0x1
    /* C408 8006F768 21280002 */  addu       $a1, $s0, $zero
    /* C40C 8006F76C 8BBD010C */  jal        func_8006F62C
    /* C410 8006F770 FFFF4626 */   addiu     $a2, $s2, -0x1
    /* C414 8006F774 21206002 */  addu       $a0, $s3, $zero
    /* C418 8006F778 21280002 */  addu       $a1, $s0, $zero
    /* C41C 8006F77C 8BBD010C */  jal        func_8006F62C
    /* C420 8006F780 21304002 */   addu      $a2, $s2, $zero
    /* C424 8006F784 21206002 */  addu       $a0, $s3, $zero
    /* C428 8006F788 21280002 */  addu       $a1, $s0, $zero
    /* C42C 8006F78C 8BBD010C */  jal        func_8006F62C
    /* C430 8006F790 01004626 */   addiu     $a2, $s2, 0x1
  .L8006F794:
    /* C434 8006F794 0D00A01A */  blez       $s5, .L8006F7CC
    /* C438 8006F798 21206002 */   addu      $a0, $s3, $zero
    /* C43C 8006F79C FFFF2526 */  addiu      $a1, $s1, -0x1
    /* C440 8006F7A0 FFFF5026 */  addiu      $s0, $s2, -0x1
    /* C444 8006F7A4 8BBD010C */  jal        func_8006F62C
    /* C448 8006F7A8 21300002 */   addu      $a2, $s0, $zero
    /* C44C 8006F7AC 21206002 */  addu       $a0, $s3, $zero
    /* C450 8006F7B0 21282002 */  addu       $a1, $s1, $zero
    /* C454 8006F7B4 8BBD010C */  jal        func_8006F62C
    /* C458 8006F7B8 21300002 */   addu      $a2, $s0, $zero
    /* C45C 8006F7BC 21206002 */  addu       $a0, $s3, $zero
    /* C460 8006F7C0 01002526 */  addiu      $a1, $s1, 0x1
    /* C464 8006F7C4 8BBD010C */  jal        func_8006F62C
    /* C468 8006F7C8 21300002 */   addu      $a2, $s0, $zero
  .L8006F7CC:
    /* C46C 8006F7CC 0E00A106 */  bgez       $s5, .L8006F808
    /* C470 8006F7D0 21206002 */   addu      $a0, $s3, $zero
    /* C474 8006F7D4 FFFF2526 */  addiu      $a1, $s1, -0x1
    /* C478 8006F7D8 01005026 */  addiu      $s0, $s2, 0x1
    /* C47C 8006F7DC 8BBD010C */  jal        func_8006F62C
    /* C480 8006F7E0 21300002 */   addu      $a2, $s0, $zero
    /* C484 8006F7E4 21206002 */  addu       $a0, $s3, $zero
    /* C488 8006F7E8 21282002 */  addu       $a1, $s1, $zero
    /* C48C 8006F7EC 8BBD010C */  jal        func_8006F62C
    /* C490 8006F7F0 21300002 */   addu      $a2, $s0, $zero
    /* C494 8006F7F4 21206002 */  addu       $a0, $s3, $zero
    /* C498 8006F7F8 01002526 */  addiu      $a1, $s1, 0x1
    /* C49C 8006F7FC 8BBD010C */  jal        func_8006F62C
    /* C4A0 8006F800 21300002 */   addu      $a2, $s0, $zero
    /* C4A4 8006F804 21206002 */  addu       $a0, $s3, $zero
  .L8006F808:
    /* C4A8 8006F808 21282002 */  addu       $a1, $s1, $zero
    /* C4AC 8006F80C 8BBD010C */  jal        func_8006F62C
    /* C4B0 8006F810 21304002 */   addu      $a2, $s2, $zero
    /* C4B4 8006F814 1C07C38E */  lw         $v1, %lo(D_8005071C)($s6)
    /* C4B8 8006F818 00000000 */  nop
    /* C4BC 8006F81C 6810628C */  lw         $v0, 0x1068($v1)
    /* C4C0 8006F820 00000000 */  nop
    /* C4C4 8006F824 00004294 */  lhu        $v0, 0x0($v0)
    /* C4C8 8006F828 00000000 */  nop
    /* C4CC 8006F82C 6C0762A6 */  sh         $v0, 0x76C($s3)
    /* C4D0 8006F830 6810628C */  lw         $v0, 0x1068($v1)
    /* C4D4 8006F834 00000000 */  nop
    /* C4D8 8006F838 02004294 */  lhu        $v0, 0x2($v0)
    /* C4DC 8006F83C 00000000 */  nop
    /* C4E0 8006F840 6E0762A6 */  sh         $v0, 0x76E($s3)
  .L8006F844:
    /* C4E4 8006F844 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* C4E8 8006F848 2800B68F */  lw         $s6, 0x28($sp)
    /* C4EC 8006F84C 2400B58F */  lw         $s5, 0x24($sp)
    /* C4F0 8006F850 2000B48F */  lw         $s4, 0x20($sp)
    /* C4F4 8006F854 1C00B38F */  lw         $s3, 0x1C($sp)
    /* C4F8 8006F858 1800B28F */  lw         $s2, 0x18($sp)
    /* C4FC 8006F85C 1400B18F */  lw         $s1, 0x14($sp)
    /* C500 8006F860 1000B08F */  lw         $s0, 0x10($sp)
    /* C504 8006F864 0800E003 */  jr         $ra
    /* C508 8006F868 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_8006F6BC
