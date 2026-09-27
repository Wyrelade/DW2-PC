nonmatching Cd_FreeFile, 0x58

glabel Cd_FreeFile
    /* 14620 80023E20 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 14624 80023E24 1400BFAF */  sw         $ra, 0x14($sp)
    /* 14628 80023E28 9E8E000C */  jal        Cd_FindCachedFile
    /* 1462C 80023E2C 1000B0AF */   sw        $s0, 0x10($sp)
    /* 14630 80023E30 21804000 */  addu       $s0, $v0, $zero
    /* 14634 80023E34 0C000012 */  beqz       $s0, .L80023E68
    /* 14638 80023E38 03000224 */   addiu     $v0, $zero, 0x3
    /* 1463C 80023E3C 00000386 */  lh         $v1, 0x0($s0)
    /* 14640 80023E40 00000000 */  nop
    /* 14644 80023E44 08006214 */  bne        $v1, $v0, .L80023E68
    /* 14648 80023E48 00000000 */   nop
    /* 1464C 80023E4C 0C00048E */  lw         $a0, 0xC($s0)
    /* 14650 80023E50 618B000C */  jal        Mem_Free
    /* 14654 80023E54 00000000 */   nop
    /* 14658 80023E58 040000AE */  sw         $zero, 0x4($s0)
    /* 1465C 80023E5C 0C0000AE */  sw         $zero, 0xC($s0)
    /* 14660 80023E60 080000AE */  sw         $zero, 0x8($s0)
    /* 14664 80023E64 000000A6 */  sh         $zero, 0x0($s0)
  .L80023E68:
    /* 14668 80023E68 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1466C 80023E6C 1000B08F */  lw         $s0, 0x10($sp)
    /* 14670 80023E70 0800E003 */  jr         $ra
    /* 14674 80023E74 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Cd_FreeFile
