nonmatching Stg00_DigiModelInit, 0x6C

glabel Stg00_DigiModelInit
    /* 3A50 80066DB0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 3A54 80066DB4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3A58 80066DB8 2188A000 */  addu       $s1, $a1, $zero
    /* 3A5C 80066DBC 1800BFAF */  sw         $ra, 0x18($sp)
    /* 3A60 80066DC0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3A64 80066DC4 0000228E */  lw         $v0, 0x0($s1)
    /* 3A68 80066DC8 21188000 */  addu       $v1, $a0, $zero
    /* 3A6C 80066DCC 0C0062AC */  sw         $v0, 0xC($v1)
    /* 3A70 80066DD0 0000248E */  lw         $a0, 0x0($s1)
    /* 3A74 80066DD4 2C00708C */  lw         $s0, 0x2C($v1)
    /* 3A78 80066DD8 C179000C */  jal        Digi_GetModelFile
    /* 3A7C 80066DDC 00000000 */   nop
    /* 3A80 80066DE0 140002AE */  sw         $v0, 0x14($s0)
    /* 3A84 80066DE4 0400268E */  lw         $a2, 0x4($s1)
    /* 3A88 80066DE8 0800278E */  lw         $a3, 0x8($s1)
    /* 3A8C 80066DEC 0C00288E */  lw         $t0, 0xC($s1)
    /* 3A90 80066DF0 040006AE */  sw         $a2, 0x4($s0)
    /* 3A94 80066DF4 080007AE */  sw         $a3, 0x8($s0)
    /* 3A98 80066DF8 0C0008AE */  sw         $t0, 0xC($s0)
    /* 3A9C 80066DFC 1000228E */  lw         $v0, 0x10($s1)
    /* 3AA0 80066E00 00000000 */  nop
    /* 3AA4 80066E04 100002AE */  sw         $v0, 0x10($s0)
    /* 3AA8 80066E08 1800BF8F */  lw         $ra, 0x18($sp)
    /* 3AAC 80066E0C 1400B18F */  lw         $s1, 0x14($sp)
    /* 3AB0 80066E10 1000B08F */  lw         $s0, 0x10($sp)
    /* 3AB4 80066E14 0800E003 */  jr         $ra
    /* 3AB8 80066E18 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg00_DigiModelInit
