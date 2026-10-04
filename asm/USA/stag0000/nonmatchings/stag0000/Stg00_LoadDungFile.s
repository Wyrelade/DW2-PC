nonmatching Stg00_LoadDungFile, 0x50

glabel Stg00_LoadDungFile
    /* E30 80064190 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* E34 80064194 1400B1AF */  sw         $s1, 0x14($sp)
    /* E38 80064198 2188A000 */  addu       $s1, $a1, $zero
    /* E3C 8006419C 2120C000 */  addu       $a0, $a2, $zero
    /* E40 800641A0 1800BFAF */  sw         $ra, 0x18($sp)
    /* E44 800641A4 828E000C */  jal        Cd_GetFileOrNull
    /* E48 800641A8 1000B0AF */   sw        $s0, 0x10($sp)
    /* E4C 800641AC 21804000 */  addu       $s0, $v0, $zero
    /* E50 800641B0 2190010C */  jal        Stg00_RelocDungFile
    /* E54 800641B4 21200002 */   addu      $a0, $s0, $zero
    /* E58 800641B8 060022A6 */  sh         $v0, 0x6($s1)
    /* E5C 800641BC 0C0030AE */  sw         $s0, 0xC($s1)
    /* E60 800641C0 0000028E */  lw         $v0, 0x0($s0)
    /* E64 800641C4 00000000 */  nop
    /* E68 800641C8 100022AE */  sw         $v0, 0x10($s1)
    /* E6C 800641CC 1800BF8F */  lw         $ra, 0x18($sp)
    /* E70 800641D0 1400B18F */  lw         $s1, 0x14($sp)
    /* E74 800641D4 1000B08F */  lw         $s0, 0x10($sp)
    /* E78 800641D8 0800E003 */  jr         $ra
    /* E7C 800641DC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg00_LoadDungFile
