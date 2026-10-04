nonmatching Flag_SelectBranch, 0xAC

glabel Flag_SelectBranch
    /* ED14 8001E514 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* ED18 8001E518 1000B0AF */  sw         $s0, 0x10($sp)
    /* ED1C 8001E51C 21808000 */  addu       $s0, $a0, $zero
    /* ED20 8001E520 0680023C */  lui        $v0, %hi(Flag_EntryIter)
    /* ED24 8001E524 60D5448C */  lw         $a0, %lo(Flag_EntryIter)($v0)
    /* ED28 8001E528 1400B1AF */  sw         $s1, 0x14($sp)
    /* ED2C 8001E52C 21880000 */  addu       $s1, $zero, $zero
    /* ED30 8001E530 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* ED34 8001E534 828E000C */  jal        Cd_GetFileOrNull
    /* ED38 8001E538 1800B2AF */   sw        $s2, 0x18($sp)
    /* ED3C 8001E53C 21200002 */  addu       $a0, $s0, $zero
    /* ED40 8001E540 3379000C */  jal        Flag_GetEntry
    /* ED44 8001E544 21904000 */   addu      $s2, $v0, $zero
    /* ED48 8001E548 21804000 */  addu       $s0, $v0, $zero
  .L8001E54C:
    /* ED4C 8001E54C 21200002 */  addu       $a0, $s0, $zero
    /* ED50 8001E550 B878000C */  jal        Flag_GetBranchCondBlock
    /* ED54 8001E554 21282002 */   addu      $a1, $s1, $zero
    /* ED58 8001E558 0E88000C */  jal        Flag_TestConds
    /* ED5C 8001E55C 21204000 */   addu      $a0, $v0, $zero
    /* ED60 8001E560 05004014 */  bnez       $v0, .L8001E578
    /* ED64 8001E564 06000224 */   addiu     $v0, $zero, 0x6
    /* ED68 8001E568 01003126 */  addiu      $s1, $s1, 0x1
    /* ED6C 8001E56C 0600222A */  slti       $v0, $s1, 0x6
    /* ED70 8001E570 F6FF4014 */  bnez       $v0, .L8001E54C
    /* ED74 8001E574 06000224 */   addiu     $v0, $zero, 0x6
  .L8001E578:
    /* ED78 8001E578 02002216 */  bne        $s1, $v0, .L8001E584
    /* ED7C 8001E57C 00000000 */   nop
    /* ED80 8001E580 21880000 */  addu       $s1, $zero, $zero
  .L8001E584:
    /* ED84 8001E584 21200002 */  addu       $a0, $s0, $zero
    /* ED88 8001E588 CE78000C */  jal        Flag_GetBranchSetBlock
    /* ED8C 8001E58C 21282002 */   addu      $a1, $s1, $zero
    /* ED90 8001E590 E288000C */  jal        Flag_ApplySets
    /* ED94 8001E594 21204000 */   addu      $a0, $v0, $zero
    /* ED98 8001E598 80101100 */  sll        $v0, $s1, 2
    /* ED9C 8001E59C 21100202 */  addu       $v0, $s0, $v0
    /* EDA0 8001E5A0 1400428C */  lw         $v0, 0x14($v0)
    /* EDA4 8001E5A4 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* EDA8 8001E5A8 1400B18F */  lw         $s1, 0x14($sp)
    /* EDAC 8001E5AC 1000B08F */  lw         $s0, 0x10($sp)
    /* EDB0 8001E5B0 21105200 */  addu       $v0, $v0, $s2
    /* EDB4 8001E5B4 1800B28F */  lw         $s2, 0x18($sp)
    /* EDB8 8001E5B8 0800E003 */  jr         $ra
    /* EDBC 8001E5BC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Flag_SelectBranch
