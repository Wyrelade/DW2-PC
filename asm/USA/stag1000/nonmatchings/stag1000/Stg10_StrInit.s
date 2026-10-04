nonmatching Stg10_StrInit, 0x6C

glabel Stg10_StrInit
    /* C40 80063FA0 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* C44 80063FA4 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* C48 80063FA8 21888000 */  addu       $s1, $a0, $zero
    /* C4C 80063FAC 1800B0AF */  sw         $s0, 0x18($sp)
    /* C50 80063FB0 2180A000 */  addu       $s0, $a1, $zero
    /* C54 80063FB4 2000BFAF */  sw         $ra, 0x20($sp)
    /* C58 80063FB8 B091010C */  jal        func_800646C0
    /* C5C 80063FBC 21200000 */   addu      $a0, $zero, $zero
    /* C60 80063FC0 5792010C */  jal        func_8006495C
    /* C64 80063FC4 21200002 */   addu      $a0, $s0, $zero
    /* C68 80063FC8 0680023C */  lui        $v0, %hi(Stg10_StrRingBuf)
    /* C6C 80063FCC E861448C */  lw         $a0, %lo(Stg10_StrRingBuf)($v0)
    /* C70 80063FD0 F5B6000C */  jal        StSetRing
    /* C74 80063FD4 20000524 */   addiu     $a1, $zero, 0x20
    /* C78 80063FD8 01000424 */  addiu      $a0, $zero, 0x1
    /* C7C 80063FDC 21288000 */  addu       $a1, $a0, $zero
    /* C80 80063FE0 FFFF0624 */  addiu      $a2, $zero, -0x1
    /* C84 80063FE4 21380000 */  addu       $a3, $zero, $zero
    /* C88 80063FE8 19B8000C */  jal        StSetStream
    /* C8C 80063FEC 1000A0AF */   sw        $zero, 0x10($sp)
    /* C90 80063FF0 CE8F010C */  jal        Stg10_StrKickCd
    /* C94 80063FF4 21202002 */   addu      $a0, $s1, $zero
    /* C98 80063FF8 2000BF8F */  lw         $ra, 0x20($sp)
    /* C9C 80063FFC 1C00B18F */  lw         $s1, 0x1C($sp)
    /* CA0 80064000 1800B08F */  lw         $s0, 0x18($sp)
    /* CA4 80064004 0800E003 */  jr         $ra
    /* CA8 80064008 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel Stg10_StrInit
