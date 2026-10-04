nonmatching Stg30_ResultDraw, 0x15C

glabel Stg30_ResultDraw
    /* E8B4 80071C14 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* E8B8 80071C18 1400B1AF */  sw         $s1, 0x14($sp)
    /* E8BC 80071C1C 21880000 */  addu       $s1, $zero, $zero
    /* E8C0 80071C20 0680023C */  lui        $v0, %hi(Save_GameState)
    /* E8C4 80071C24 2C00B7AF */  sw         $s7, 0x2C($sp)
    /* E8C8 80071C28 20E65724 */  addiu      $s7, $v0, %lo(Save_GameState)
    /* E8CC 80071C2C 0780023C */  lui        $v0, %hi(Stg30_Battle)
    /* E8D0 80071C30 2800B6AF */  sw         $s6, 0x28($sp)
    /* E8D4 80071C34 C03C5624 */  addiu      $s6, $v0, %lo(Stg30_Battle)
    /* E8D8 80071C38 1800B2AF */  sw         $s2, 0x18($sp)
    /* E8DC 80071C3C 2190C002 */  addu       $s2, $s6, $zero
    /* E8E0 80071C40 0780023C */  lui        $v0, %hi(Stg30_ResultParts)
    /* E8E4 80071C44 2000B4AF */  sw         $s4, 0x20($sp)
    /* E8E8 80071C48 00375424 */  addiu      $s4, $v0, %lo(Stg30_ResultParts)
    /* E8EC 80071C4C 3000BFAF */  sw         $ra, 0x30($sp)
    /* E8F0 80071C50 2400B5AF */  sw         $s5, 0x24($sp)
    /* E8F4 80071C54 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* E8F8 80071C58 1000B0AF */  sw         $s0, 0x10($sp)
    /* E8FC 80071C5C 2C00958C */  lw         $s5, 0x2C($a0)
  .L80071C60:
    /* E900 80071C60 0000848E */  lw         $a0, 0x0($s4)
    /* E904 80071C64 688E000C */  jal        Cd_GetFileEntry
    /* E908 80071C68 01001324 */   addiu     $s3, $zero, 0x1
    /* E90C 80071C6C 2B002006 */  bltz       $s1, .L80071D1C
    /* E910 80071C70 21804000 */   addu      $s0, $v0, $zero
    /* E914 80071C74 0300222A */  slti       $v0, $s1, 0x3
    /* E918 80071C78 05004014 */  bnez       $v0, .L80071C90
    /* E91C 80071C7C 04000224 */   addiu     $v0, $zero, 0x4
    /* E920 80071C80 21002212 */  beq        $s1, $v0, .L80071D08
    /* E924 80071C84 21200002 */   addu      $a0, $s0, $zero
    /* E928 80071C88 47C70108 */  j          .L80071D1C
    /* E92C 80071C8C 00000000 */   nop
  .L80071C90:
    /* E930 80071C90 19004292 */  lbu        $v0, 0x19($s2)
    /* E934 80071C94 00000000 */  nop
    /* E938 80071C98 03004014 */  bnez       $v0, .L80071CA8
    /* E93C 80071C9C 21103602 */   addu      $v0, $s1, $s6
    /* E940 80071CA0 47C70108 */  j          .L80071D1C
    /* E944 80071CA4 21980000 */   addu      $s3, $zero, $zero
  .L80071CA8:
    /* E948 80071CA8 4C034290 */  lbu        $v0, 0x34C($v0)
    /* E94C 80071CAC 00000000 */  nop
    /* E950 80071CB0 03004010 */  beqz       $v0, .L80071CC0
    /* E954 80071CB4 21200002 */   addu      $a0, $s0, $zero
    /* E958 80071CB8 31C70108 */  j          .L80071CC4
    /* E95C 80071CBC 21280000 */   addu      $a1, $zero, $zero
  .L80071CC0:
    /* E960 80071CC0 10000524 */  addiu      $a1, $zero, 0x10
  .L80071CC4:
    /* E964 80071CC4 4175000C */  jal        Gfx_HidePartsByMask
    /* E968 80071CC8 00000000 */   nop
    /* E96C 80071CCC 21200002 */  addu       $a0, $s0, $zero
    /* E970 80071CD0 01000524 */  addiu      $a1, $zero, 0x1
    /* E974 80071CD4 2800478E */  lw         $a3, 0x28($s2)
    /* E978 80071CD8 6D75000C */  jal        Gfx_SetPartsNumber
    /* E97C 80071CDC 08000624 */   addiu     $a2, $zero, 0x8
    /* E980 80071CE0 21200002 */  addu       $a0, $s0, $zero
    /* E984 80071CE4 04000524 */  addiu      $a1, $zero, 0x4
    /* E988 80071CE8 1800A78E */  lw         $a3, 0x18($s5)
    /* E98C 80071CEC 6D75000C */  jal        Gfx_SetPartsNumber
    /* E990 80071CF0 08000624 */   addiu     $a2, $zero, 0x8
    /* E994 80071CF4 21200002 */  addu       $a0, $s0, $zero
    /* E998 80071CF8 08000524 */  addiu      $a1, $zero, 0x8
    /* E99C 80071CFC 25004792 */  lbu        $a3, 0x25($s2)
    /* E9A0 80071D00 45C70108 */  j          .L80071D14
    /* E9A4 80071D04 02000624 */   addiu     $a2, $zero, 0x2
  .L80071D08:
    /* E9A8 80071D08 01000524 */  addiu      $a1, $zero, 0x1
    /* E9AC 80071D0C 0800E78E */  lw         $a3, 0x8($s7)
    /* E9B0 80071D10 08000624 */  addiu      $a2, $zero, 0x8
  .L80071D14:
    /* E9B4 80071D14 6D75000C */  jal        Gfx_SetPartsNumber
    /* E9B8 80071D18 00000000 */   nop
  .L80071D1C:
    /* E9BC 80071D1C 03006012 */  beqz       $s3, .L80071D2C
    /* E9C0 80071D20 00000000 */   nop
    /* E9C4 80071D24 2176000C */  jal        Gfx_DrawParts
    /* E9C8 80071D28 21200002 */   addu      $a0, $s0, $zero
  .L80071D2C:
    /* E9CC 80071D2C 0400B526 */  addiu      $s5, $s5, 0x4
    /* E9D0 80071D30 5C005226 */  addiu      $s2, $s2, 0x5C
    /* E9D4 80071D34 01003126 */  addiu      $s1, $s1, 0x1
    /* E9D8 80071D38 0600222A */  slti       $v0, $s1, 0x6
    /* E9DC 80071D3C C8FF4014 */  bnez       $v0, .L80071C60
    /* E9E0 80071D40 04009426 */   addiu     $s4, $s4, 0x4
    /* E9E4 80071D44 3000BF8F */  lw         $ra, 0x30($sp)
    /* E9E8 80071D48 2C00B78F */  lw         $s7, 0x2C($sp)
    /* E9EC 80071D4C 2800B68F */  lw         $s6, 0x28($sp)
    /* E9F0 80071D50 2400B58F */  lw         $s5, 0x24($sp)
    /* E9F4 80071D54 2000B48F */  lw         $s4, 0x20($sp)
    /* E9F8 80071D58 1C00B38F */  lw         $s3, 0x1C($sp)
    /* E9FC 80071D5C 1800B28F */  lw         $s2, 0x18($sp)
    /* EA00 80071D60 1400B18F */  lw         $s1, 0x14($sp)
    /* EA04 80071D64 1000B08F */  lw         $s0, 0x10($sp)
    /* EA08 80071D68 0800E003 */  jr         $ra
    /* EA0C 80071D6C 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel Stg30_ResultDraw
