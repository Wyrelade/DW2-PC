nonmatching func_8006D124, 0x19C

glabel func_8006D124
    /* 9DC4 8006D124 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 9DC8 8006D128 2000B4AF */  sw         $s4, 0x20($sp)
    /* 9DCC 8006D12C 21A08000 */  addu       $s4, $a0, $zero
    /* 9DD0 8006D130 D60D043C */  lui        $a0, (0xDD60002 >> 16)
    /* 9DD4 8006D134 2400BFAF */  sw         $ra, 0x24($sp)
    /* 9DD8 8006D138 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 9DDC 8006D13C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 9DE0 8006D140 1400B1AF */  sw         $s1, 0x14($sp)
    /* 9DE4 8006D144 1000B0AF */  sw         $s0, 0x10($sp)
    /* 9DE8 8006D148 2C00918E */  lw         $s1, 0x2C($s4)
    /* 9DEC 8006D14C 688E000C */  jal        Cd_GetFileEntry
    /* 9DF0 8006D150 02008434 */   ori       $a0, $a0, (0xDD60002 & 0xFFFF)
    /* 9DF4 8006D154 D60D043C */  lui        $a0, (0xDD60002 >> 16)
    /* 9DF8 8006D158 688E000C */  jal        Cd_GetFileEntry
    /* 9DFC 8006D15C 02008434 */   ori       $a0, $a0, (0xDD60002 & 0xFFFF)
    /* 9E00 8006D160 21904000 */  addu       $s2, $v0, $zero
    /* 9E04 8006D164 0000428E */  lw         $v0, 0x0($s2)
    /* 9E08 8006D168 00000000 */  nop
    /* 9E0C 8006D16C 2E004010 */  beqz       $v0, .L8006D228
    /* 9E10 8006D170 21984002 */   addu      $s3, $s2, $zero
    /* 9E14 8006D174 0F005026 */  addiu      $s0, $s2, 0xF
  .L8006D178:
    /* 9E18 8006D178 0D00038E */  lw         $v1, 0xD($s0)
    /* 9E1C 8006D17C 20000224 */  addiu      $v0, $zero, 0x20
    /* 9E20 8006D180 1B006210 */  beq        $v1, $v0, .L8006D1F0
    /* 9E24 8006D184 21006228 */   slti      $v0, $v1, 0x21
    /* 9E28 8006D188 05004010 */  beqz       $v0, .L8006D1A0
    /* 9E2C 8006D18C 02000224 */   addiu     $v0, $zero, 0x2
    /* 9E30 8006D190 08006210 */  beq        $v1, $v0, .L8006D1B4
    /* 9E34 8006D194 04000524 */   addiu     $a1, $zero, 0x4
    /* 9E38 8006D198 86B40108 */  j          .L8006D218
    /* 9E3C 8006D19C 28007326 */   addiu     $s3, $s3, 0x28
  .L8006D1A0:
    /* 9E40 8006D1A0 40000224 */  addiu      $v0, $zero, 0x40
    /* 9E44 8006D1A4 15006210 */  beq        $v1, $v0, .L8006D1FC
    /* 9E48 8006D1A8 00000000 */   nop
    /* 9E4C 8006D1AC 86B40108 */  j          .L8006D218
    /* 9E50 8006D1B0 28007326 */   addiu     $s3, $s3, 0x28
  .L8006D1B4:
    /* 9E54 8006D1B4 21300000 */  addu       $a2, $zero, $zero
    /* 9E58 8006D1B8 2800848E */  lw         $a0, 0x28($s4)
    /* 9E5C 8006D1BC FB88000C */  jal        Math_CycleRange
    /* 9E60 8006D1C0 03000724 */   addiu     $a3, $zero, 0x3
    /* 9E64 8006D1C4 FDFF02A2 */  sb         $v0, -0x3($s0)
    /* 9E68 8006D1C8 76FF0224 */  addiu      $v0, $zero, -0x8A
    /* 9E6C 8006D1CC F5FF02A6 */  sh         $v0, -0xB($s0)
    /* 9E70 8006D1D0 4000238E */  lw         $v1, 0x40($s1)
    /* 9E74 8006D1D4 00000000 */  nop
    /* 9E78 8006D1D8 40100300 */  sll        $v0, $v1, 1
    /* 9E7C 8006D1DC 21104300 */  addu       $v0, $v0, $v1
    /* 9E80 8006D1E0 80100200 */  sll        $v0, $v0, 2
    /* 9E84 8006D1E4 B7FF4224 */  addiu      $v0, $v0, -0x49
    /* 9E88 8006D1E8 85B40108 */  j          .L8006D214
    /* 9E8C 8006D1EC F7FF02A6 */   sh        $v0, -0x9($s0)
  .L8006D1F0:
    /* 9E90 8006D1F0 4400228E */  lw         $v0, 0x44($s1)
    /* 9E94 8006D1F4 84B40108 */  j          .L8006D210
    /* 9E98 8006D1F8 2B100200 */   sltu      $v0, $zero, $v0
  .L8006D1FC:
    /* 9E9C 8006D1FC 4400228E */  lw         $v0, 0x44($s1)
    /* 9EA0 8006D200 4C00238E */  lw         $v1, 0x4C($s1)
    /* 9EA4 8006D204 00000000 */  nop
    /* 9EA8 8006D208 26104300 */  xor        $v0, $v0, $v1
    /* 9EAC 8006D20C 2B100200 */  sltu       $v0, $zero, $v0
  .L8006D210:
    /* 9EB0 8006D210 000002A2 */  sb         $v0, 0x0($s0)
  .L8006D214:
    /* 9EB4 8006D214 28007326 */  addiu      $s3, $s3, 0x28
  .L8006D218:
    /* 9EB8 8006D218 0000628E */  lw         $v0, 0x0($s3)
    /* 9EBC 8006D21C 00000000 */  nop
    /* 9EC0 8006D220 D5FF4014 */  bnez       $v0, .L8006D178
    /* 9EC4 8006D224 28001026 */   addiu     $s0, $s0, 0x28
  .L8006D228:
    /* 9EC8 8006D228 21204002 */  addu       $a0, $s2, $zero
    /* 9ECC 8006D22C 04000524 */  addiu      $a1, $zero, 0x4
    /* 9ED0 8006D230 4400278E */  lw         $a3, 0x44($s1)
    /* 9ED4 8006D234 02000624 */  addiu      $a2, $zero, 0x2
    /* 9ED8 8006D238 6D75000C */  jal        Gfx_SetPartsNumber
    /* 9EDC 8006D23C 0100E724 */   addiu     $a3, $a3, 0x1
    /* 9EE0 8006D240 21204002 */  addu       $a0, $s2, $zero
    /* 9EE4 8006D244 08000524 */  addiu      $a1, $zero, 0x8
    /* 9EE8 8006D248 4C00278E */  lw         $a3, 0x4C($s1)
    /* 9EEC 8006D24C 02000624 */  addiu      $a2, $zero, 0x2
    /* 9EF0 8006D250 6D75000C */  jal        Gfx_SetPartsNumber
    /* 9EF4 8006D254 0100E724 */   addiu     $a3, $a3, 0x1
    /* 9EF8 8006D258 2176000C */  jal        Gfx_DrawParts
    /* 9EFC 8006D25C 21204002 */   addu      $a0, $s2, $zero
    /* 9F00 8006D260 0780023C */  lui        $v0, %hi(D_80070A04)
    /* 9F04 8006D264 040A428C */  lw         $v0, %lo(D_80070A04)($v0)
    /* 9F08 8006D268 00000000 */  nop
    /* 9F0C 8006D26C 0C004014 */  bnez       $v0, .L8006D2A0
    /* 9F10 8006D270 00000000 */   nop
    /* 9F14 8006D274 D60D043C */  lui        $a0, (0xDD60003 >> 16)
    /* 9F18 8006D278 688E000C */  jal        Cd_GetFileEntry
    /* 9F1C 8006D27C 03008434 */   ori       $a0, $a0, (0xDD60003 & 0xFFFF)
    /* 9F20 8006D280 21904000 */  addu       $s2, $v0, $zero
    /* 9F24 8006D284 21204002 */  addu       $a0, $s2, $zero
    /* 9F28 8006D288 02000524 */  addiu      $a1, $zero, 0x2
    /* 9F2C 8006D28C 5800278E */  lw         $a3, 0x58($s1)
    /* 9F30 8006D290 6D75000C */  jal        Gfx_SetPartsNumber
    /* 9F34 8006D294 2130A000 */   addu      $a2, $a1, $zero
    /* 9F38 8006D298 2176000C */  jal        Gfx_DrawParts
    /* 9F3C 8006D29C 21204002 */   addu      $a0, $s2, $zero
  .L8006D2A0:
    /* 9F40 8006D2A0 2400BF8F */  lw         $ra, 0x24($sp)
    /* 9F44 8006D2A4 2000B48F */  lw         $s4, 0x20($sp)
    /* 9F48 8006D2A8 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 9F4C 8006D2AC 1800B28F */  lw         $s2, 0x18($sp)
    /* 9F50 8006D2B0 1400B18F */  lw         $s1, 0x14($sp)
    /* 9F54 8006D2B4 1000B08F */  lw         $s0, 0x10($sp)
    /* 9F58 8006D2B8 0800E003 */  jr         $ra
    /* 9F5C 8006D2BC 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8006D124
