nonmatching func_8006CD1C, 0x238

glabel func_8006CD1C
    /* 99BC 8006CD1C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 99C0 8006CD20 2000B2AF */  sw         $s2, 0x20($sp)
    /* 99C4 8006CD24 21908000 */  addu       $s2, $a0, $zero
    /* 99C8 8006CD28 2400BFAF */  sw         $ra, 0x24($sp)
    /* 99CC 8006CD2C 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 99D0 8006CD30 1800B0AF */  sw         $s0, 0x18($sp)
    /* 99D4 8006CD34 2C00428E */  lw         $v0, 0x2C($s2)
    /* 99D8 8006CD38 00000000 */  nop
    /* 99DC 8006CD3C 2C00508C */  lw         $s0, 0x2C($v0)
    /* 99E0 8006CD40 00000000 */  nop
    /* 99E4 8006CD44 18000486 */  lh         $a0, 0x18($s0)
    /* 99E8 8006CD48 1A000586 */  lh         $a1, 0x1A($s0)
    /* 99EC 8006CD4C 29C2010C */  jal        func_800708A4
    /* 99F0 8006CD50 00000000 */   nop
    /* 99F4 8006CD54 01000624 */  addiu      $a2, $zero, 0x1
    /* 99F8 8006CD58 18000486 */  lh         $a0, 0x18($s0)
    /* 99FC 8006CD5C 1A000586 */  lh         $a1, 0x1A($s0)
    /* 9A00 8006CD60 3FC2010C */  jal        func_800708FC
    /* 9A04 8006CD64 21884000 */   addu      $s1, $v0, $zero
    /* 9A08 8006CD68 00002296 */  lhu        $v0, 0x0($s1)
    /* 9A0C 8006CD6C 00000000 */  nop
    /* 9A10 8006CD70 10004234 */  ori        $v0, $v0, 0x10
    /* 9A14 8006CD74 000022A6 */  sh         $v0, 0x0($s1)
    /* 9A18 8006CD78 0000028E */  lw         $v0, 0x0($s0)
    /* 9A1C 8006CD7C 00000000 */  nop
    /* 9A20 8006CD80 00104230 */  andi       $v0, $v0, 0x1000
    /* 9A24 8006CD84 07004010 */  beqz       $v0, .L8006CDA4
    /* 9A28 8006CD88 FFFF0624 */   addiu     $a2, $zero, -0x1
    /* 9A2C 8006CD8C 18000486 */  lh         $a0, 0x18($s0)
    /* 9A30 8006CD90 1A000586 */  lh         $a1, 0x1A($s0)
    /* 9A34 8006CD94 08000292 */  lbu        $v0, 0x8($s0)
    /* 9A38 8006CD98 2138C000 */  addu       $a3, $a2, $zero
    /* 9A3C 8006CD9C FDBA010C */  jal        func_8006EBF4
    /* 9A40 8006CDA0 1000A2AF */   sw        $v0, 0x10($sp)
  .L8006CDA4:
    /* 9A44 8006CDA4 0E000296 */  lhu        $v0, 0xE($s0)
    /* 9A48 8006CDA8 00000000 */  nop
    /* 9A4C 8006CDAC 55014224 */  addiu      $v0, $v0, 0x155
    /* 9A50 8006CDB0 0E0002A6 */  sh         $v0, 0xE($s0)
    /* 9A54 8006CDB4 0C0002A6 */  sh         $v0, 0xC($s0)
    /* 9A58 8006CDB8 1400438E */  lw         $v1, 0x14($s2)
    /* 9A5C 8006CDBC 00000000 */  nop
    /* 9A60 8006CDC0 0700622C */  sltiu      $v0, $v1, 0x7
    /* 9A64 8006CDC4 08004010 */  beqz       $v0, .L8006CDE8
    /* 9A68 8006CDC8 0680023C */   lui       $v0, %hi(jtbl_8006356C)
    /* 9A6C 8006CDCC 6C354224 */  addiu      $v0, $v0, %lo(jtbl_8006356C)
    /* 9A70 8006CDD0 80180300 */  sll        $v1, $v1, 2
    /* 9A74 8006CDD4 21186200 */  addu       $v1, $v1, $v0
    /* 9A78 8006CDD8 0000628C */  lw         $v0, 0x0($v1)
    /* 9A7C 8006CDDC 00000000 */  nop
    /* 9A80 8006CDE0 08004000 */  jr         $v0
    /* 9A84 8006CDE4 00000000 */   nop
  jlabel .L8006CDE8
    /* 9A88 8006CDE8 0000028E */  lw         $v0, 0x0($s0)
    /* 9A8C 8006CDEC FFBF0324 */  addiu      $v1, $zero, -0x4001
    /* 9A90 8006CDF0 24184300 */  and        $v1, $v0, $v1
    /* 9A94 8006CDF4 00104230 */  andi       $v0, $v0, 0x1000
    /* 9A98 8006CDF8 03004010 */  beqz       $v0, .L8006CE08
    /* 9A9C 8006CDFC 000003AE */   sw        $v1, 0x0($s0)
    /* 9AA0 8006CE00 00406234 */  ori        $v0, $v1, 0x4000
    /* 9AA4 8006CE04 000002AE */  sw         $v0, 0x0($s0)
  .L8006CE08:
    /* 9AA8 8006CE08 21204002 */  addu       $a0, $s2, $zero
    /* 9AAC 8006CE0C CDB30108 */  j          .L8006CF34
    /* 9AB0 8006CE10 01000524 */   addiu     $a1, $zero, 0x1
  jlabel .L8006CE14
    /* 9AB4 8006CE14 18000486 */  lh         $a0, 0x18($s0)
    /* 9AB8 8006CE18 1A000586 */  lh         $a1, 0x1A($s0)
    /* 9ABC 8006CE1C 5DC2010C */  jal        func_80070974
    /* 9AC0 8006CE20 00000000 */   nop
    /* 9AC4 8006CE24 FFFF0424 */  addiu      $a0, $zero, -0x1
    /* 9AC8 8006CE28 18000686 */  lh         $a2, 0x18($s0)
    /* 9ACC 8006CE2C 1A000786 */  lh         $a3, 0x1A($s0)
    /* 9AD0 8006CE30 08000292 */  lbu        $v0, 0x8($s0)
    /* 9AD4 8006CE34 21288000 */  addu       $a1, $a0, $zero
    /* 9AD8 8006CE38 FDBA010C */  jal        func_8006EBF4
    /* 9ADC 8006CE3C 1000A2AF */   sw        $v0, 0x10($sp)
    /* 9AE0 8006CE40 21204002 */  addu       $a0, $s2, $zero
    /* 9AE4 8006CE44 00002296 */  lhu        $v0, 0x0($s1)
    /* 9AE8 8006CE48 03000524 */  addiu      $a1, $zero, 0x3
    /* 9AEC 8006CE4C EFFF4230 */  andi       $v0, $v0, 0xFFEF
    /* 9AF0 8006CE50 000022A6 */  sh         $v0, 0x0($s1)
    /* 9AF4 8006CE54 7045000C */  jal        Task_SetState0
    /* 9AF8 8006CE58 000000AE */   sw        $zero, 0x0($s0)
    /* 9AFC 8006CE5C CFB30108 */  j          .L8006CF3C
    /* 9B00 8006CE60 00000000 */   nop
  jlabel .L8006CE64
    /* 9B04 8006CE64 1800518E */  lw         $s1, 0x18($s2)
    /* 9B08 8006CE68 00000000 */  nop
    /* 9B0C 8006CE6C 03002012 */  beqz       $s1, .L8006CE7C
    /* 9B10 8006CE70 01000224 */   addiu     $v0, $zero, 0x1
    /* 9B14 8006CE74 11002212 */  beq        $s1, $v0, .L8006CEBC
    /* 9B18 8006CE78 00000000 */   nop
  .L8006CE7C:
    /* 9B1C 8006CE7C 0000028E */  lw         $v0, 0x0($s0)
    /* 9B20 8006CE80 00000000 */  nop
    /* 9B24 8006CE84 00504234 */  ori        $v0, $v0, 0x5000
    /* 9B28 8006CE88 000002AE */  sw         $v0, 0x0($s0)
    /* 9B2C 8006CE8C 1400438E */  lw         $v1, 0x14($s2)
    /* 9B30 8006CE90 04000224 */  addiu      $v0, $zero, 0x4
    /* 9B34 8006CE94 04006214 */  bne        $v1, $v0, .L8006CEA8
    /* 9B38 8006CE98 2C000524 */   addiu     $a1, $zero, 0x2C
    /* 9B3C 8006CE9C 21204002 */  addu       $a0, $s2, $zero
    /* 9B40 8006CEA0 ABB30108 */  j          .L8006CEAC
    /* 9B44 8006CEA4 2A000524 */   addiu     $a1, $zero, 0x2A
  .L8006CEA8:
    /* 9B48 8006CEA8 21204002 */  addu       $a0, $s2, $zero
  .L8006CEAC:
    /* 9B4C 8006CEAC 37B9010C */  jal        func_8006E4DC
    /* 9B50 8006CEB0 00000000 */   nop
    /* 9B54 8006CEB4 C4B30108 */  j          .L8006CF10
    /* 9B58 8006CEB8 00000000 */   nop
  .L8006CEBC:
    /* 9B5C 8006CEBC 62B9010C */  jal        func_8006E588
    /* 9B60 8006CEC0 21204002 */   addu      $a0, $s2, $zero
    /* 9B64 8006CEC4 1D005114 */  bne        $v0, $s1, .L8006CF3C
    /* 9B68 8006CEC8 21204002 */   addu      $a0, $s2, $zero
    /* 9B6C 8006CECC 37B9010C */  jal        func_8006E4DC
    /* 9B70 8006CED0 28000524 */   addiu     $a1, $zero, 0x28
    /* 9B74 8006CED4 21204002 */  addu       $a0, $s2, $zero
    /* 9B78 8006CED8 CDB30108 */  j          .L8006CF34
    /* 9B7C 8006CEDC 01000524 */   addiu     $a1, $zero, 0x1
  jlabel .L8006CEE0
    /* 9B80 8006CEE0 1800508E */  lw         $s0, 0x18($s2)
    /* 9B84 8006CEE4 00000000 */  nop
    /* 9B88 8006CEE8 03000012 */  beqz       $s0, .L8006CEF8
    /* 9B8C 8006CEEC 01000224 */   addiu     $v0, $zero, 0x1
    /* 9B90 8006CEF0 0B000212 */  beq        $s0, $v0, .L8006CF20
    /* 9B94 8006CEF4 00000000 */   nop
  .L8006CEF8:
    /* 9B98 8006CEF8 21204002 */  addu       $a0, $s2, $zero
    /* 9B9C 8006CEFC 37B9010C */  jal        func_8006E4DC
    /* 9BA0 8006CF00 2B000524 */   addiu     $a1, $zero, 0x2B
    /* 9BA4 8006CF04 35000424 */  addiu      $a0, $zero, 0x35
    /* 9BA8 8006CF08 A369000C */  jal        Snd_PlayById
    /* 9BAC 8006CF0C 21280000 */   addu      $a1, $zero, $zero
  .L8006CF10:
    /* 9BB0 8006CF10 6045000C */  jal        Task_NextState2
    /* 9BB4 8006CF14 21204002 */   addu      $a0, $s2, $zero
    /* 9BB8 8006CF18 CFB30108 */  j          .L8006CF3C
    /* 9BBC 8006CF1C 00000000 */   nop
  .L8006CF20:
    /* 9BC0 8006CF20 62B9010C */  jal        func_8006E588
    /* 9BC4 8006CF24 21204002 */   addu      $a0, $s2, $zero
    /* 9BC8 8006CF28 04005014 */  bne        $v0, $s0, .L8006CF3C
    /* 9BCC 8006CF2C 21204002 */   addu      $a0, $s2, $zero
    /* 9BD0 8006CF30 02000524 */  addiu      $a1, $zero, 0x2
  .L8006CF34:
    /* 9BD4 8006CF34 7745000C */  jal        Task_SetState1
    /* 9BD8 8006CF38 00000000 */   nop
  jlabel .L8006CF3C
    /* 9BDC 8006CF3C 2400BF8F */  lw         $ra, 0x24($sp)
    /* 9BE0 8006CF40 2000B28F */  lw         $s2, 0x20($sp)
    /* 9BE4 8006CF44 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 9BE8 8006CF48 1800B08F */  lw         $s0, 0x18($sp)
    /* 9BEC 8006CF4C 0800E003 */  jr         $ra
    /* 9BF0 8006CF50 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8006CD1C
