nonmatching Task_AllocWithBuffers, 0x88

glabel Task_AllocWithBuffers
    /* 1BB8 800113B8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1BBC 800113BC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1BC0 800113C0 21888000 */  addu       $s1, $a0, $zero
    /* 1BC4 800113C4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 1BC8 800113C8 2190A000 */  addu       $s2, $a1, $zero
    /* 1BCC 800113CC 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 1BD0 800113D0 7544000C */  jal        Task_Alloc
    /* 1BD4 800113D4 1000B0AF */   sw        $s0, 0x10($sp)
    /* 1BD8 800113D8 08002012 */  beqz       $s1, .L800113FC
    /* 1BDC 800113DC 21804000 */   addu      $s0, $v0, $zero
    /* 1BE0 800113E0 21202002 */  addu       $a0, $s1, $zero
    /* 1BE4 800113E4 CF8B000C */  jal        Mem_Alloc
    /* 1BE8 800113E8 02000524 */   addiu     $a1, $zero, 0x2
    /* 1BEC 800113EC 2C0002AE */  sw         $v0, 0x2C($s0)
    /* 1BF0 800113F0 21204000 */  addu       $a0, $v0, $zero
    /* 1BF4 800113F4 E38B000C */  jal        Mem_Zero
    /* 1BF8 800113F8 21282002 */   addu      $a1, $s1, $zero
  .L800113FC:
    /* 1BFC 800113FC 09004012 */  beqz       $s2, .L80011424
    /* 1C00 80011400 21204002 */   addu      $a0, $s2, $zero
    /* 1C04 80011404 CF8B000C */  jal        Mem_Alloc
    /* 1C08 80011408 02000524 */   addiu     $a1, $zero, 0x2
    /* 1C0C 8001140C 21204000 */  addu       $a0, $v0, $zero
    /* 1C10 80011410 21284002 */  addu       $a1, $s2, $zero
    /* 1C14 80011414 E38B000C */  jal        Mem_Zero
    /* 1C18 80011418 340004AE */   sw        $a0, 0x34($s0)
    /* 1C1C 8001141C 83101200 */  sra        $v0, $s2, 2
    /* 1C20 80011420 300002AE */  sw         $v0, 0x30($s0)
  .L80011424:
    /* 1C24 80011424 21100002 */  addu       $v0, $s0, $zero
    /* 1C28 80011428 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 1C2C 8001142C 1800B28F */  lw         $s2, 0x18($sp)
    /* 1C30 80011430 1400B18F */  lw         $s1, 0x14($sp)
    /* 1C34 80011434 1000B08F */  lw         $s0, 0x10($sp)
    /* 1C38 80011438 0800E003 */  jr         $ra
    /* 1C3C 8001143C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Task_AllocWithBuffers
