nonmatching Stg30_InitBattle, 0xAC

glabel Stg30_InitBattle
    /* CE9C 800701FC E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* CEA0 80070200 1800B2AF */  sw         $s2, 0x18($sp)
    /* CEA4 80070204 0780123C */  lui        $s2, %hi(Stg30_Battle)
    /* CEA8 80070208 1000B0AF */  sw         $s0, 0x10($sp)
    /* CEAC 8007020C C03C5026 */  addiu      $s0, $s2, %lo(Stg30_Battle)
    /* CEB0 80070210 21200002 */  addu       $a0, $s0, $zero
    /* CEB4 80070214 E0030524 */  addiu      $a1, $zero, 0x3E0
    /* CEB8 80070218 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* CEBC 8007021C E38B000C */  jal        Mem_Zero
    /* CEC0 80070220 1400B1AF */   sw        $s1, 0x14($sp)
    /* CEC4 80070224 0680023C */  lui        $v0, %hi(Sys_State)
    /* CEC8 80070228 70F75124 */  addiu      $s1, $v0, %lo(Sys_State)
    /* CECC 8007022C 01000424 */  addiu      $a0, $zero, 0x1
    /* CED0 80070230 2000238E */  lw         $v1, 0x20($s1)
    /* CED4 80070234 00030224 */  addiu      $v0, $zero, 0x300
    /* CED8 80070238 00FF6330 */  andi       $v1, $v1, 0xFF00
    /* CEDC 8007023C 06006214 */  bne        $v1, $v0, .L80070258
    /* CEE0 80070240 D40304AE */   sw        $a0, 0x3D4($s0)
    /* CEE4 80070244 0680023C */  lui        $v0, %hi(D_8005D5A0)
    /* CEE8 80070248 A0D54224 */  addiu      $v0, $v0, %lo(D_8005D5A0)
    /* CEEC 8007024C 3D1040A0 */  sb         $zero, 0x103D($v0)
    /* CEF0 80070250 401040A4 */  sh         $zero, 0x1040($v0)
    /* CEF4 80070254 C03C44AE */  sw         $a0, %lo(Stg30_Battle)($s2)
  .L80070258:
    /* CEF8 80070258 2400238E */  lw         $v1, 0x24($s1)
    /* CEFC 8007025C 97000224 */  addiu      $v0, $zero, 0x97
    /* CF00 80070260 09006214 */  bne        $v1, $v0, .L80070288
    /* CF04 80070264 0780033C */   lui       $v1, %hi(D_80074098)
    /* CF08 80070268 9E87000C */  jal        Flag_Test
    /* CF0C 8007026C 88000424 */   addiu     $a0, $zero, 0x88
    /* CF10 80070270 05004010 */  beqz       $v0, .L80070288
    /* CF14 80070274 0780033C */   lui       $v1, %hi(D_80074098)
    /* CF18 80070278 2400228E */  lw         $v0, 0x24($s1)
    /* CF1C 8007027C 00000000 */  nop
    /* CF20 80070280 01004224 */  addiu      $v0, $v0, 0x1
    /* CF24 80070284 240022AE */  sw         $v0, 0x24($s1)
  .L80070288:
    /* CF28 80070288 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* CF2C 8007028C 1800B28F */  lw         $s2, 0x18($sp)
    /* CF30 80070290 1400B18F */  lw         $s1, 0x14($sp)
    /* CF34 80070294 1000B08F */  lw         $s0, 0x10($sp)
    /* CF38 80070298 04000224 */  addiu      $v0, $zero, 0x4
    /* CF3C 8007029C 984062AC */  sw         $v0, %lo(D_80074098)($v1)
    /* CF40 800702A0 0800E003 */  jr         $ra
    /* CF44 800702A4 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg30_InitBattle
