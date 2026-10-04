nonmatching Stg40_SetLights, 0x84

glabel Stg40_SetLights
    /* 449C 800677FC D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 44A0 80067800 1800B2AF */  sw         $s2, 0x18($sp)
    /* 44A4 80067804 2190A000 */  addu       $s2, $a1, $zero
    /* 44A8 80067808 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 44AC 8006780C 2198C000 */  addu       $s3, $a2, $zero
    /* 44B0 80067810 2000B4AF */  sw         $s4, 0x20($sp)
    /* 44B4 80067814 21A0E000 */  addu       $s4, $a3, $zero
    /* 44B8 80067818 1000B0AF */  sw         $s0, 0x10($sp)
    /* 44BC 8006781C 21800000 */  addu       $s0, $zero, $zero
    /* 44C0 80067820 1400B1AF */  sw         $s1, 0x14($sp)
    /* 44C4 80067824 21888000 */  addu       $s1, $a0, $zero
    /* 44C8 80067828 2400BFAF */  sw         $ra, 0x24($sp)
  .L8006782C:
    /* 44CC 8006782C 21200002 */  addu       $a0, $s0, $zero
    /* 44D0 80067830 59AD000C */  jal        GsSetFlatLight
    /* 44D4 80067834 21282002 */   addu      $a1, $s1, $zero
    /* 44D8 80067838 01001026 */  addiu      $s0, $s0, 0x1
    /* 44DC 8006783C 0300022A */  slti       $v0, $s0, 0x3
    /* 44E0 80067840 FAFF4014 */  bnez       $v0, .L8006782C
    /* 44E4 80067844 10003126 */   addiu     $s1, $s1, 0x10
    /* 44E8 80067848 21204002 */  addu       $a0, $s2, $zero
    /* 44EC 8006784C 21286002 */  addu       $a1, $s3, $zero
    /* 44F0 80067850 D5AE000C */  jal        GsSetAmbient
    /* 44F4 80067854 21308002 */   addu      $a2, $s4, $zero
    /* 44F8 80067858 B5AE000C */  jal        GsSetLightMode
    /* 44FC 8006785C 21200000 */   addu      $a0, $zero, $zero
    /* 4500 80067860 2400BF8F */  lw         $ra, 0x24($sp)
    /* 4504 80067864 2000B48F */  lw         $s4, 0x20($sp)
    /* 4508 80067868 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 450C 8006786C 1800B28F */  lw         $s2, 0x18($sp)
    /* 4510 80067870 1400B18F */  lw         $s1, 0x14($sp)
    /* 4514 80067874 1000B08F */  lw         $s0, 0x10($sp)
    /* 4518 80067878 0800E003 */  jr         $ra
    /* 451C 8006787C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel Stg40_SetLights
