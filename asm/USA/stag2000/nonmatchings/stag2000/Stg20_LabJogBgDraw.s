nonmatching Stg20_LabJogBgDraw, 0x64

glabel Stg20_LabJogBgDraw
    /* 7070 8006A3D0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 7074 8006A3D4 1800B0AF */  sw         $s0, 0x18($sp)
    /* 7078 8006A3D8 21808000 */  addu       $s0, $a0, $zero
    /* 707C 8006A3DC 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 7080 8006A3E0 6F7F000C */  jal        Gfx_AttachModel
    /* 7084 8006A3E4 140D0524 */   addiu     $a1, $zero, 0xD14
    /* 7088 8006A3E8 4882000C */  jal        Actor_UpdateTransform
    /* 708C 8006A3EC 21200002 */   addu      $a0, $s0, $zero
    /* 7090 8006A3F0 3480000C */  jal        Gfx_CalcModelBoneMatrices
    /* 7094 8006A3F4 21200002 */   addu      $a0, $s0, $zero
    /* 7098 8006A3F8 0680023C */  lui        $v0, %hi(D_80063584)
    /* 709C 8006A3FC 21200002 */  addu       $a0, $s0, $zero
    /* 70A0 8006A400 01000524 */  addiu      $a1, $zero, 0x1
    /* 70A4 8006A404 84354924 */  addiu      $t1, $v0, %lo(D_80063584)
    /* 70A8 8006A408 03002389 */  lwl        $v1, 0x3($t1)
    /* 70AC 8006A40C 00002399 */  lwr        $v1, 0x0($t1)
    /* 70B0 8006A410 00000000 */  nop
    /* 70B4 8006A414 1300A3AB */  swl        $v1, 0x13($sp)
    /* 70B8 8006A418 1000A3BB */  swr        $v1, 0x10($sp)
    /* 70BC 8006A41C DA81000C */  jal        Gfx_DrawWireModel
    /* 70C0 8006A420 1000A627 */   addiu     $a2, $sp, 0x10
    /* 70C4 8006A424 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 70C8 8006A428 1800B08F */  lw         $s0, 0x18($sp)
    /* 70CC 8006A42C 0800E003 */  jr         $ra
    /* 70D0 8006A430 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg20_LabJogBgDraw
