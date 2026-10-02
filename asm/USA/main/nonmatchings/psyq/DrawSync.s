nonmatching DrawSync, 0x68

glabel DrawSync
    /* 17C80 80027480 0580023C */  lui        $v0, %hi(D_80048F12)
    /* 17C84 80027484 128F4290 */  lbu        $v0, %lo(D_80048F12)($v0)
    /* 17C88 80027488 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 17C8C 8002748C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 17C90 80027490 21808000 */  addu       $s0, $a0, $zero
    /* 17C94 80027494 0200422C */  sltiu      $v0, $v0, 0x2
    /* 17C98 80027498 08004014 */  bnez       $v0, .L800274BC
    /* 17C9C 8002749C 1400BFAF */   sw        $ra, 0x14($sp)
    /* 17CA0 800274A0 0180043C */  lui        $a0, %hi(D_800102C0)
    /* 17CA4 800274A4 C0028424 */  addiu      $a0, $a0, %lo(D_800102C0)
    /* 17CA8 800274A8 0580023C */  lui        $v0, %hi(D_80048F0C)
    /* 17CAC 800274AC 0C8F428C */  lw         $v0, %lo(D_80048F0C)($v0)
    /* 17CB0 800274B0 00000000 */  nop
    /* 17CB4 800274B4 09F84000 */  jalr       $v0
    /* 17CB8 800274B8 21280002 */   addu      $a1, $s0, $zero
  .L800274BC:
    /* 17CBC 800274BC 0580023C */  lui        $v0, %hi(D_80048F08)
    /* 17CC0 800274C0 088F428C */  lw         $v0, %lo(D_80048F08)($v0)
    /* 17CC4 800274C4 00000000 */  nop
    /* 17CC8 800274C8 3C00428C */  lw         $v0, 0x3C($v0)
    /* 17CCC 800274CC 00000000 */  nop
    /* 17CD0 800274D0 09F84000 */  jalr       $v0
    /* 17CD4 800274D4 21200002 */   addu      $a0, $s0, $zero
    /* 17CD8 800274D8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 17CDC 800274DC 1000B08F */  lw         $s0, 0x10($sp)
    /* 17CE0 800274E0 0800E003 */  jr         $ra
    /* 17CE4 800274E4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel DrawSync
