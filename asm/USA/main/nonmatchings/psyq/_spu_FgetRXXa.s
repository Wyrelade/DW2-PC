nonmatching _spu_FgetRXXa, 0x3C

glabel _spu_FgetRXXa
    /* 2B3C8 8003ABC8 0580023C */  lui        $v0, %hi(D_8004FE28)
    /* 2B3CC 8003ABCC 28FE428C */  lw         $v0, %lo(D_8004FE28)($v0)
    /* 2B3D0 8003ABD0 40200400 */  sll        $a0, $a0, 1
    /* 2B3D4 8003ABD4 21208200 */  addu       $a0, $a0, $v0
    /* 2B3D8 8003ABD8 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 2B3DC 8003ABDC 00008494 */  lhu        $a0, 0x0($a0)
    /* 2B3E0 8003ABE0 0500A210 */  beq        $a1, $v0, .L8003ABF8
    /* 2B3E4 8003ABE4 00000000 */   nop
    /* 2B3E8 8003ABE8 0580023C */  lui        $v0, %hi(D_8004FE50)
    /* 2B3EC 8003ABEC 50FE428C */  lw         $v0, %lo(D_8004FE50)($v0)
    /* 2B3F0 8003ABF0 FFEA0008 */  j          .L8003ABFC
    /* 2B3F4 8003ABF4 04104400 */   sllv      $v0, $a0, $v0
  .L8003ABF8:
    /* 2B3F8 8003ABF8 21108000 */  addu       $v0, $a0, $zero
  .L8003ABFC:
    /* 2B3FC 8003ABFC 0800E003 */  jr         $ra
    /* 2B400 8003AC00 00000000 */   nop
endlabel _spu_FgetRXXa
