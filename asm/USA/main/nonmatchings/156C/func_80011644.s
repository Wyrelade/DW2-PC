nonmatching func_80011644, 0x64

glabel func_80011644
    /* 1E44 80011644 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1E48 80011648 0580023C */  lui        $v0, %hi(Cd_PreloadIds)
    /* 1E4C 8001164C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1E50 80011650 48095124 */  addiu      $s1, $v0, %lo(Cd_PreloadIds)
    /* 1E54 80011654 9A010424 */  addiu      $a0, $zero, 0x19A
    /* 1E58 80011658 1800BFAF */  sw         $ra, 0x18($sp)
    /* 1E5C 8001165C FD8E000C */  jal        Cd_QueueFile
    /* 1E60 80011660 1000B0AF */   sw        $s0, 0x10($sp)
    /* 1E64 80011664 6400828F */  lw         $v0, %gp_rel(Cd_PreloadCount)($gp)
    /* 1E68 80011668 00000000 */  nop
    /* 1E6C 8001166C 09004018 */  blez       $v0, .L80011694
    /* 1E70 80011670 21800000 */   addu      $s0, $zero, $zero
  .L80011674:
    /* 1E74 80011674 0000248E */  lw         $a0, 0x0($s1)
    /* 1E78 80011678 FD8E000C */  jal        Cd_QueueFile
    /* 1E7C 8001167C 04003126 */   addiu     $s1, $s1, 0x4
    /* 1E80 80011680 6400828F */  lw         $v0, %gp_rel(Cd_PreloadCount)($gp)
    /* 1E84 80011684 01001026 */  addiu      $s0, $s0, 0x1
    /* 1E88 80011688 2A100202 */  slt        $v0, $s0, $v0
    /* 1E8C 8001168C F9FF4014 */  bnez       $v0, .L80011674
    /* 1E90 80011690 00000000 */   nop
  .L80011694:
    /* 1E94 80011694 1800BF8F */  lw         $ra, 0x18($sp)
    /* 1E98 80011698 1400B18F */  lw         $s1, 0x14($sp)
    /* 1E9C 8001169C 1000B08F */  lw         $s0, 0x10($sp)
    /* 1EA0 800116A0 0800E003 */  jr         $ra
    /* 1EA4 800116A4 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80011644
