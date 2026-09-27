nonmatching func_8001C934, 0x54

glabel func_8001C934
    /* D134 8001C934 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* D138 8001C938 1000B0AF */  sw         $s0, 0x10($sp)
    /* D13C 8001C93C 0480103C */  lui        $s0, %hi(D_80041670)
    /* D140 8001C940 7016048E */  lw         $a0, %lo(D_80041670)($s0)
    /* D144 8001C944 1400B1AF */  sw         $s1, 0x14($sp)
    /* D148 8001C948 70161126 */  addiu      $s1, $s0, %lo(D_80041670)
    /* D14C 8001C94C 07008010 */  beqz       $a0, .L8001C96C
    /* D150 8001C950 1800BFAF */   sw        $ra, 0x18($sp)
    /* D154 8001C954 618B000C */  jal        Mem_Free
    /* D158 8001C958 00000000 */   nop
    /* D15C 8001C95C 0400248E */  lw         $a0, 0x4($s1)
    /* D160 8001C960 618B000C */  jal        Mem_Free
    /* D164 8001C964 701600AE */   sw        $zero, %lo(D_80041670)($s0)
    /* D168 8001C968 040020AE */  sw         $zero, 0x4($s1)
  .L8001C96C:
    /* D16C 8001C96C 1800BF8F */  lw         $ra, 0x18($sp)
    /* D170 8001C970 1400B18F */  lw         $s1, 0x14($sp)
    /* D174 8001C974 1000B08F */  lw         $s0, 0x10($sp)
    /* D178 8001C978 0680023C */  lui        $v0, %hi(D_8005F79C)
    /* D17C 8001C97C 9CF740AC */  sw         $zero, %lo(D_8005F79C)($v0)
    /* D180 8001C980 0800E003 */  jr         $ra
    /* D184 8001C984 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8001C934
