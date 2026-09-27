nonmatching func_80023BF4, 0x80

glabel func_80023BF4
    /* 143F4 80023BF4 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 143F8 80023BF8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 143FC 80023BFC 21888000 */  addu       $s1, $a0, $zero
    /* 14400 80023C00 1800BFAF */  sw         $ra, 0x18($sp)
    /* 14404 80023C04 9E8E000C */  jal        Cd_FindCachedFile
    /* 14408 80023C08 1000B0AF */   sw        $s0, 0x10($sp)
    /* 1440C 80023C0C 21804000 */  addu       $s0, $v0, $zero
    /* 14410 80023C10 04000012 */  beqz       $s0, .L80023C24
    /* 14414 80023C14 0680023C */   lui       $v0, %hi(D_8005F770)
    /* 14418 80023C18 70F7428C */  lw         $v0, %lo(D_8005F770)($v0)
    /* 1441C 80023C1C 188F0008 */  j          .L80023C60
    /* 14420 80023C20 080002AE */   sw        $v0, 0x8($s0)
  .L80023C24:
    /* 14424 80023C24 AC8E000C */  jal        Cd_FindFreeCacheSlot
    /* 14428 80023C28 00000000 */   nop
    /* 1442C 80023C2C 21804000 */  addu       $s0, $v0, $zero
    /* 14430 80023C30 21202002 */  addu       $a0, $s1, $zero
    /* 14434 80023C34 E48F000C */  jal        func_80023F90
    /* 14438 80023C38 040004AE */   sw        $a0, 0x4($s0)
    /* 1443C 80023C3C C0220200 */  sll        $a0, $v0, 11
    /* 14440 80023C40 CF8B000C */  jal        func_80022F3C
    /* 14444 80023C44 03000524 */   addiu     $a1, $zero, 0x3
    /* 14448 80023C48 0C0002AE */  sw         $v0, 0xC($s0)
    /* 1444C 80023C4C 01000224 */  addiu      $v0, $zero, 0x1
    /* 14450 80023C50 000002A6 */  sh         $v0, 0x0($s0)
    /* 14454 80023C54 01000224 */  addiu      $v0, $zero, 0x1
    /* 14458 80023C58 080000AE */  sw         $zero, 0x8($s0)
    /* 1445C 80023C5C 580082AF */  sw         $v0, %gp_rel(D_80050750)($gp)
  .L80023C60:
    /* 14460 80023C60 1800BF8F */  lw         $ra, 0x18($sp)
    /* 14464 80023C64 1400B18F */  lw         $s1, 0x14($sp)
    /* 14468 80023C68 1000B08F */  lw         $s0, 0x10($sp)
    /* 1446C 80023C6C 0800E003 */  jr         $ra
    /* 14470 80023C70 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80023BF4
