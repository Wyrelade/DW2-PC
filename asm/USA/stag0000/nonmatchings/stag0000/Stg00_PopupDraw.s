nonmatching Stg00_PopupDraw, 0x250

glabel Stg00_PopupDraw
    /* 484C 80067BAC E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 4850 80067BB0 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 4854 80067BB4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 4858 80067BB8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 485C 80067BBC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 4860 80067BC0 2C00918C */  lw         $s1, 0x2C($a0)
    /* 4864 80067BC4 21800000 */  addu       $s0, $zero, $zero
    /* 4868 80067BC8 0000238E */  lw         $v1, 0x0($s1)
    /* 486C 80067BCC 00000000 */  nop
    /* 4870 80067BD0 0900622C */  sltiu      $v0, $v1, 0x9
    /* 4874 80067BD4 09004010 */  beqz       $v0, .L80067BFC
    /* 4878 80067BD8 01001224 */   addiu     $s2, $zero, 0x1
    /* 487C 80067BDC 0680023C */  lui        $v0, %hi(jtbl_80063484)
    /* 4880 80067BE0 84344224 */  addiu      $v0, $v0, %lo(jtbl_80063484)
    /* 4884 80067BE4 80180300 */  sll        $v1, $v1, 2
    /* 4888 80067BE8 21186200 */  addu       $v1, $v1, $v0
    /* 488C 80067BEC 0000628C */  lw         $v0, 0x0($v1)
    /* 4890 80067BF0 00000000 */  nop
    /* 4894 80067BF4 08004000 */  jr         $v0
    /* 4898 80067BF8 00000000 */   nop
  jlabel .L80067BFC
    /* 489C 80067BFC 0400248E */  lw         $a0, 0x4($s1)
    /* 48A0 80067C00 977B000C */  jal        Skill_GetPartsEntry
    /* 48A4 80067C04 00000000 */   nop
    /* 48A8 80067C08 688E000C */  jal        Cd_GetFileEntry
    /* 48AC 80067C0C 21204000 */   addu      $a0, $v0, $zero
    /* 48B0 80067C10 289F0108 */  j          .L80067CA0
    /* 48B4 80067C14 21804000 */   addu      $s0, $v0, $zero
  jlabel .L80067C18
    /* 48B8 80067C18 688E000C */  jal        Cd_GetFileEntry
    /* 48BC 80067C1C 2D0D043C */   lui       $a0, (0xD2D0000 >> 16)
    /* 48C0 80067C20 21804000 */  addu       $s0, $v0, $zero
    /* 48C4 80067C24 0780033C */  lui        $v1, %hi(Stg00_PopupItemMasks)
    /* 48C8 80067C28 0000228E */  lw         $v0, 0x0($s1)
    /* 48CC 80067C2C 288F6324 */  addiu      $v1, $v1, %lo(Stg00_PopupItemMasks)
    /* 48D0 80067C30 209F0108 */  j          .L80067C80
    /* 48D4 80067C34 FCFF4224 */   addiu     $v0, $v0, -0x4
  jlabel .L80067C38
    /* 48D8 80067C38 688E000C */  jal        Cd_GetFileEntry
    /* 48DC 80067C3C A101043C */   lui       $a0, (0x1A10000 >> 16)
    /* 48E0 80067C40 21804000 */  addu       $s0, $v0, $zero
    /* 48E4 80067C44 21200002 */  addu       $a0, $s0, $zero
    /* 48E8 80067C48 0780033C */  lui        $v1, %hi(Stg00_PopupNumParts)
    /* 48EC 80067C4C 448F6324 */  addiu      $v1, $v1, %lo(Stg00_PopupNumParts)
    /* 48F0 80067C50 0000228E */  lw         $v0, 0x0($s1)
    /* 48F4 80067C54 0400278E */  lw         $a3, 0x4($s1)
    /* 48F8 80067C58 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 48FC 80067C5C 80100200 */  sll        $v0, $v0, 2
    /* 4900 80067C60 21104300 */  addu       $v0, $v0, $v1
    /* 4904 80067C64 0000458C */  lw         $a1, 0x0($v0)
    /* 4908 80067C68 6D75000C */  jal        Gfx_SetPartsNumber
    /* 490C 80067C6C 03000624 */   addiu     $a2, $zero, 0x3
    /* 4910 80067C70 0780033C */  lui        $v1, %hi(Stg00_PopupNumMasks)
    /* 4914 80067C74 0000228E */  lw         $v0, 0x0($s1)
    /* 4918 80067C78 388F6324 */  addiu      $v1, $v1, %lo(Stg00_PopupNumMasks)
    /* 491C 80067C7C FFFF4224 */  addiu      $v0, $v0, -0x1
  .L80067C80:
    /* 4920 80067C80 80100200 */  sll        $v0, $v0, 2
    /* 4924 80067C84 21104300 */  addu       $v0, $v0, $v1
    /* 4928 80067C88 0000458C */  lw         $a1, 0x0($v0)
    /* 492C 80067C8C 4175000C */  jal        Gfx_HidePartsByMask
    /* 4930 80067C90 21200002 */   addu      $a0, $s0, $zero
    /* 4934 80067C94 289F0108 */  j          .L80067CA0
    /* 4938 80067C98 00000000 */   nop
  jlabel .L80067C9C
    /* 493C 80067C9C 21900000 */  addu       $s2, $zero, $zero
  .L80067CA0:
    /* 4940 80067CA0 1A004012 */  beqz       $s2, .L80067D0C
    /* 4944 80067CA4 00000000 */   nop
    /* 4948 80067CA8 0000028E */  lw         $v0, 0x0($s0)
    /* 494C 80067CAC 00000000 */  nop
    /* 4950 80067CB0 14004010 */  beqz       $v0, .L80067D04
    /* 4954 80067CB4 21200002 */   addu      $a0, $s0, $zero
    /* 4958 80067CB8 00100624 */  addiu      $a2, $zero, 0x1000
    /* 495C 80067CBC 01000524 */  addiu      $a1, $zero, 0x1
    /* 4960 80067CC0 0C000326 */  addiu      $v1, $s0, 0xC
  .L80067CC4:
    /* 4964 80067CC4 0C00228E */  lw         $v0, 0xC($s1)
    /* 4968 80067CC8 00000000 */  nop
    /* 496C 80067CCC 05004610 */  beq        $v0, $a2, .L80067CE4
    /* 4970 80067CD0 00000000 */   nop
    /* 4974 80067CD4 020060A0 */  sb         $zero, 0x2($v1)
    /* 4978 80067CD8 0C00228E */  lw         $v0, 0xC($s1)
    /* 497C 80067CDC 3A9F0108 */  j          .L80067CE8
    /* 4980 80067CE0 040062AC */   sw        $v0, 0x4($v1)
  .L80067CE4:
    /* 4984 80067CE4 020065A0 */  sb         $a1, 0x2($v1)
  .L80067CE8:
    /* 4988 80067CE8 10002292 */  lbu        $v0, 0x10($s1)
    /* 498C 80067CEC 28008424 */  addiu      $a0, $a0, 0x28
    /* 4990 80067CF0 000062A0 */  sb         $v0, 0x0($v1)
    /* 4994 80067CF4 0000828C */  lw         $v0, 0x0($a0)
    /* 4998 80067CF8 00000000 */  nop
    /* 499C 80067CFC F1FF4014 */  bnez       $v0, .L80067CC4
    /* 49A0 80067D00 28006324 */   addiu     $v1, $v1, 0x28
  .L80067D04:
    /* 49A4 80067D04 2176000C */  jal        Gfx_DrawParts
    /* 49A8 80067D08 21200002 */   addu      $a0, $s0, $zero
  .L80067D0C:
    /* 49AC 80067D0C 0800228E */  lw         $v0, 0x8($s1)
    /* 49B0 80067D10 00000000 */  nop
    /* 49B4 80067D14 33004010 */  beqz       $v0, .L80067DE4
    /* 49B8 80067D18 031A0200 */   sra       $v1, $v0, 8
    /* 49BC 80067D1C 01000224 */  addiu      $v0, $zero, 0x1
    /* 49C0 80067D20 08006210 */  beq        $v1, $v0, .L80067D44
    /* 49C4 80067D24 02006228 */   slti      $v0, $v1, 0x2
    /* 49C8 80067D28 03004014 */  bnez       $v0, .L80067D38
    /* 49CC 80067D2C 02000224 */   addiu     $v0, $zero, 0x2
    /* 49D0 80067D30 07006210 */  beq        $v1, $v0, .L80067D50
    /* 49D4 80067D34 00000000 */   nop
  .L80067D38:
    /* 49D8 80067D38 A101043C */  lui        $a0, (0x1A10026 >> 16)
    /* 49DC 80067D3C 569F0108 */  j          .L80067D58
    /* 49E0 80067D40 26008434 */   ori       $a0, $a0, (0x1A10026 & 0xFFFF)
  .L80067D44:
    /* 49E4 80067D44 A101043C */  lui        $a0, (0x1A10027 >> 16)
    /* 49E8 80067D48 569F0108 */  j          .L80067D58
    /* 49EC 80067D4C 27008434 */   ori       $a0, $a0, (0x1A10027 & 0xFFFF)
  .L80067D50:
    /* 49F0 80067D50 A101043C */  lui        $a0, (0x1A10028 >> 16)
    /* 49F4 80067D54 28008434 */  ori        $a0, $a0, (0x1A10028 & 0xFFFF)
  .L80067D58:
    /* 49F8 80067D58 688E000C */  jal        Cd_GetFileEntry
    /* 49FC 80067D5C 00000000 */   nop
    /* 4A00 80067D60 21804000 */  addu       $s0, $v0, $zero
    /* 4A04 80067D64 21200002 */  addu       $a0, $s0, $zero
    /* 4A08 80067D68 08002292 */  lbu        $v0, 0x8($s1)
    /* 4A0C 80067D6C 01000524 */  addiu      $a1, $zero, 0x1
    /* 4A10 80067D70 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 4A14 80067D74 04284500 */  sllv       $a1, $a1, $v0
    /* 4A18 80067D78 4175000C */  jal        Gfx_HidePartsByMask
    /* 4A1C 80067D7C 27280500 */   nor       $a1, $zero, $a1
    /* 4A20 80067D80 0000028E */  lw         $v0, 0x0($s0)
    /* 4A24 80067D84 00000000 */  nop
    /* 4A28 80067D88 14004010 */  beqz       $v0, .L80067DDC
    /* 4A2C 80067D8C 21200002 */   addu      $a0, $s0, $zero
    /* 4A30 80067D90 00100624 */  addiu      $a2, $zero, 0x1000
    /* 4A34 80067D94 01000524 */  addiu      $a1, $zero, 0x1
    /* 4A38 80067D98 0C000326 */  addiu      $v1, $s0, 0xC
  .L80067D9C:
    /* 4A3C 80067D9C 0C00228E */  lw         $v0, 0xC($s1)
    /* 4A40 80067DA0 00000000 */  nop
    /* 4A44 80067DA4 05004610 */  beq        $v0, $a2, .L80067DBC
    /* 4A48 80067DA8 00000000 */   nop
    /* 4A4C 80067DAC 020060A0 */  sb         $zero, 0x2($v1)
    /* 4A50 80067DB0 0C00228E */  lw         $v0, 0xC($s1)
    /* 4A54 80067DB4 709F0108 */  j          .L80067DC0
    /* 4A58 80067DB8 040062AC */   sw        $v0, 0x4($v1)
  .L80067DBC:
    /* 4A5C 80067DBC 020065A0 */  sb         $a1, 0x2($v1)
  .L80067DC0:
    /* 4A60 80067DC0 10002292 */  lbu        $v0, 0x10($s1)
    /* 4A64 80067DC4 28008424 */  addiu      $a0, $a0, 0x28
    /* 4A68 80067DC8 000062A0 */  sb         $v0, 0x0($v1)
    /* 4A6C 80067DCC 0000828C */  lw         $v0, 0x0($a0)
    /* 4A70 80067DD0 00000000 */  nop
    /* 4A74 80067DD4 F1FF4014 */  bnez       $v0, .L80067D9C
    /* 4A78 80067DD8 28006324 */   addiu     $v1, $v1, 0x28
  .L80067DDC:
    /* 4A7C 80067DDC 2176000C */  jal        Gfx_DrawParts
    /* 4A80 80067DE0 21200002 */   addu      $a0, $s0, $zero
  .L80067DE4:
    /* 4A84 80067DE4 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 4A88 80067DE8 1800B28F */  lw         $s2, 0x18($sp)
    /* 4A8C 80067DEC 1400B18F */  lw         $s1, 0x14($sp)
    /* 4A90 80067DF0 1000B08F */  lw         $s0, 0x10($sp)
    /* 4A94 80067DF4 0800E003 */  jr         $ra
    /* 4A98 80067DF8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg00_PopupDraw
