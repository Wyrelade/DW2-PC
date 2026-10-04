nonmatching Stg30_CameraDraw, 0xAC

glabel Stg30_CameraDraw
    /* D908 80070C68 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* D90C 80070C6C 3400BFAF */  sw         $ra, 0x34($sp)
    /* D910 80070C70 3000B0AF */  sw         $s0, 0x30($sp)
    /* D914 80070C74 2C00908C */  lw         $s0, 0x2C($a0)
    /* D918 80070C78 00000000 */  nop
    /* D91C 80070C7C 7C000426 */  addiu      $a0, $s0, 0x7C
    /* D920 80070C80 D1B5000C */  jal        RotMatrixYXZ
    /* D924 80070C84 20000526 */   addiu     $a1, $s0, 0x20
    /* D928 80070C88 6C00028E */  lw         $v0, 0x6C($s0)
    /* D92C 80070C8C 7000038E */  lw         $v1, 0x70($s0)
    /* D930 80070C90 7400048E */  lw         $a0, 0x74($s0)
    /* D934 80070C94 0000058E */  lw         $a1, 0x0($s0)
    /* D938 80070C98 1C0000AE */  sw         $zero, 0x1C($s0)
    /* D93C 80070C9C 340002AE */  sw         $v0, 0x34($s0)
    /* D940 80070CA0 380003AE */  sw         $v1, 0x38($s0)
    /* D944 80070CA4 3C0004AE */  sw         $a0, 0x3C($s0)
    /* D948 80070CA8 1000A5AF */  sw         $a1, 0x10($sp)
    /* D94C 80070CAC 0400028E */  lw         $v0, 0x4($s0)
    /* D950 80070CB0 00000000 */  nop
    /* D954 80070CB4 1400A2AF */  sw         $v0, 0x14($sp)
    /* D958 80070CB8 0800028E */  lw         $v0, 0x8($s0)
    /* D95C 80070CBC 00000000 */  nop
    /* D960 80070CC0 1800A2AF */  sw         $v0, 0x18($sp)
    /* D964 80070CC4 0C00028E */  lw         $v0, 0xC($s0)
    /* D968 80070CC8 00000000 */  nop
    /* D96C 80070CCC 1C00A2AF */  sw         $v0, 0x1C($sp)
    /* D970 80070CD0 1000028E */  lw         $v0, 0x10($s0)
    /* D974 80070CD4 00000000 */  nop
    /* D978 80070CD8 2000A2AF */  sw         $v0, 0x20($sp)
    /* D97C 80070CDC 1400038E */  lw         $v1, 0x14($s0)
    /* D980 80070CE0 1C000226 */  addiu      $v0, $s0, 0x1C
    /* D984 80070CE4 2800A0AF */  sw         $zero, 0x28($sp)
    /* D988 80070CE8 2C00A2AF */  sw         $v0, 0x2C($sp)
    /* D98C 80070CEC 2400A3AF */  sw         $v1, 0x24($sp)
    /* D990 80070CF0 1800048E */  lw         $a0, 0x18($s0)
    /* D994 80070CF4 51AD000C */  jal        GsSetProjection
    /* D998 80070CF8 00000000 */   nop
    /* D99C 80070CFC 59B0000C */  jal        GsSetRefView2
    /* D9A0 80070D00 1000A427 */   addiu     $a0, $sp, 0x10
    /* D9A4 80070D04 3400BF8F */  lw         $ra, 0x34($sp)
    /* D9A8 80070D08 3000B08F */  lw         $s0, 0x30($sp)
    /* D9AC 80070D0C 0800E003 */  jr         $ra
    /* D9B0 80070D10 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel Stg30_CameraDraw
