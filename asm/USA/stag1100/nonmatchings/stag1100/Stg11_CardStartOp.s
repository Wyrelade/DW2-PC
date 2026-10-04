nonmatching Stg11_CardStartOp, 0x6C

glabel Stg11_CardStartOp
    /* 444C 800677AC E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 4450 800677B0 1400B1AF */  sw         $s1, 0x14($sp)
    /* 4454 800677B4 2188A000 */  addu       $s1, $a1, $zero
    /* 4458 800677B8 0780023C */  lui        $v0, %hi(Stg11_CardTask)
    /* 445C 800677BC D085428C */  lw         $v0, %lo(Stg11_CardTask)($v0)
    /* 4460 800677C0 FF008530 */  andi       $a1, $a0, 0xFF
    /* 4464 800677C4 1800BFAF */  sw         $ra, 0x18($sp)
    /* 4468 800677C8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 446C 800677CC 21204000 */  addu       $a0, $v0, $zero
    /* 4470 800677D0 2C00908C */  lw         $s0, 0x2C($a0)
    /* 4474 800677D4 7745000C */  jal        Task_SetState1
    /* 4478 800677D8 00000000 */   nop
    /* 447C 800677DC FFFF0324 */  addiu      $v1, $zero, -0x1
    /* 4480 800677E0 0200023C */  lui        $v0, (0x22040 >> 16)
    /* 4484 800677E4 000011AE */  sw         $s1, 0x0($s0)
    /* 4488 800677E8 C0881100 */  sll        $s1, $s1, 3
    /* 448C 800677EC 21881102 */  addu       $s1, $s0, $s1
    /* 4490 800677F0 240023AE */  sw         $v1, 0x24($s1)
    /* 4494 800677F4 040003AE */  sw         $v1, 0x4($s0)
    /* 4498 800677F8 21800202 */  addu       $s0, $s0, $v0
    /* 449C 800677FC 382003AE */  sw         $v1, (0x22038 & 0xFFFF)($s0)
    /* 44A0 80067800 402000AE */  sw         $zero, (0x22040 & 0xFFFF)($s0)
    /* 44A4 80067804 1800BF8F */  lw         $ra, 0x18($sp)
    /* 44A8 80067808 1400B18F */  lw         $s1, 0x14($sp)
    /* 44AC 8006780C 1000B08F */  lw         $s0, 0x10($sp)
    /* 44B0 80067810 0800E003 */  jr         $ra
    /* 44B4 80067814 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg11_CardStartOp
