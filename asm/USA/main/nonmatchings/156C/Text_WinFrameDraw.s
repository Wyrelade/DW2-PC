nonmatching Text_WinFrameDraw, 0x68

glabel Text_WinFrameDraw
    /* A7B4 80019FB4 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* A7B8 80019FB8 21288000 */  addu       $a1, $a0, $zero
    /* A7BC 80019FBC 0480033C */  lui        $v1, %hi(Text_WinFrameParts)
    /* A7C0 80019FC0 1800BFAF */  sw         $ra, 0x18($sp)
    /* A7C4 80019FC4 1400B1AF */  sw         $s1, 0x14($sp)
    /* A7C8 80019FC8 1000B0AF */  sw         $s0, 0x10($sp)
    /* A7CC 80019FCC 0800A28C */  lw         $v0, 0x8($a1)
    /* A7D0 80019FD0 D00F6324 */  addiu      $v1, $v1, %lo(Text_WinFrameParts)
    /* A7D4 80019FD4 80100200 */  sll        $v0, $v0, 2
    /* A7D8 80019FD8 21104300 */  addu       $v0, $v0, $v1
    /* A7DC 80019FDC 0000448C */  lw         $a0, 0x0($v0)
    /* A7E0 80019FE0 2C00B18C */  lw         $s1, 0x2C($a1)
    /* A7E4 80019FE4 688E000C */  jal        Cd_GetFileEntry
    /* A7E8 80019FE8 00000000 */   nop
    /* A7EC 80019FEC 21804000 */  addu       $s0, $v0, $zero
    /* A7F0 80019FF0 21200002 */  addu       $a0, $s0, $zero
    /* A7F4 80019FF4 00002686 */  lh         $a2, 0x0($s1)
    /* A7F8 80019FF8 5475000C */  jal        Gfx_SetPartsScale
    /* A7FC 80019FFC 00100524 */   addiu     $a1, $zero, 0x1000
    /* A800 8001A000 2176000C */  jal        Gfx_DrawParts
    /* A804 8001A004 21200002 */   addu      $a0, $s0, $zero
    /* A808 8001A008 1800BF8F */  lw         $ra, 0x18($sp)
    /* A80C 8001A00C 1400B18F */  lw         $s1, 0x14($sp)
    /* A810 8001A010 1000B08F */  lw         $s0, 0x10($sp)
    /* A814 8001A014 0800E003 */  jr         $ra
    /* A818 8001A018 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Text_WinFrameDraw
