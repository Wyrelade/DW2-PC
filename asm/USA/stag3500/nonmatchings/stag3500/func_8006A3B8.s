nonmatching func_8006A3B8, 0x54

glabel func_8006A3B8
    /* 7058 8006A3B8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 705C 8006A3BC 1800B2AF */  sw         $s2, 0x18($sp)
    /* 7060 8006A3C0 21908000 */  addu       $s2, $a0, $zero
    /* 7064 8006A3C4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 7068 8006A3C8 21880000 */  addu       $s1, $zero, $zero
    /* 706C 8006A3CC 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 7070 8006A3D0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 7074 8006A3D4 2C00508E */  lw         $s0, 0x2C($s2)
  .L8006A3D8:
    /* 7078 8006A3D8 5A98010C */  jal        func_80066168
    /* 707C 8006A3DC 21200002 */   addu      $a0, $s0, $zero
    /* 7080 8006A3E0 01003126 */  addiu      $s1, $s1, 0x1
    /* 7084 8006A3E4 FCFF201A */  blez       $s1, .L8006A3D8
    /* 7088 8006A3E8 04001026 */   addiu     $s0, $s0, 0x4
    /* 708C 8006A3EC 5C44000C */  jal        Task_DefaultDestroy
    /* 7090 8006A3F0 21204002 */   addu      $a0, $s2, $zero
    /* 7094 8006A3F4 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 7098 8006A3F8 1800B28F */  lw         $s2, 0x18($sp)
    /* 709C 8006A3FC 1400B18F */  lw         $s1, 0x14($sp)
    /* 70A0 8006A400 1000B08F */  lw         $s0, 0x10($sp)
    /* 70A4 8006A404 0800E003 */  jr         $ra
    /* 70A8 8006A408 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8006A3B8
