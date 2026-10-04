/* Handwritten function */
nonmatching Actor_ProjectToScreen, 0x21C

glabel Actor_ProjectToScreen
    /* 111F8 800209F8 3800848C */  lw         $a0, 0x38($a0)
    /* 111FC 800209FC E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 11200 80020A00 14008324 */  addiu      $v1, $a0, 0x14
    /* 11204 80020A04 3000858C */  lw         $a1, 0x30($a0)
    /* 11208 80020A08 3400868C */  lw         $a2, 0x34($a0)
    /* 1120C 80020A0C 3800878C */  lw         $a3, 0x38($a0)
    /* 11210 80020A10 140085AC */  sw         $a1, 0x14($a0)
    /* 11214 80020A14 180086AC */  sw         $a2, 0x18($a0)
    /* 11218 80020A18 1C0087AC */  sw         $a3, 0x1C($a0)
    /* 1121C 80020A1C 0680053C */  lui        $a1, %hi(GsWSMATRIX)
    /* 11220 80020A20 081AA524 */  addiu      $a1, $a1, %lo(GsWSMATRIX)
    /* 11224 80020A24 0000AC8C */  lw         $t4, 0x0($a1)
    /* 11228 80020A28 0400AD8C */  lw         $t5, 0x4($a1)
    /* 1122C 80020A2C 0000CC48 */  ctc2       $t4, $0 /* handwritten instruction */
    /* 11230 80020A30 0008CD48 */  ctc2       $t5, $1 /* handwritten instruction */
    /* 11234 80020A34 0800AC8C */  lw         $t4, 0x8($a1)
    /* 11238 80020A38 0C00AD8C */  lw         $t5, 0xC($a1)
    /* 1123C 80020A3C 1000AE8C */  lw         $t6, 0x10($a1)
    /* 11240 80020A40 0010CC48 */  ctc2       $t4, $2 /* handwritten instruction */
    /* 11244 80020A44 0018CD48 */  ctc2       $t5, $3 /* handwritten instruction */
    /* 11248 80020A48 0020CE48 */  ctc2       $t6, $4 /* handwritten instruction */
    /* 1124C 80020A4C 00008C94 */  lhu        $t4, 0x0($a0)
    /* 11250 80020A50 06008D94 */  lhu        $t5, 0x6($a0)
    /* 11254 80020A54 0C008E94 */  lhu        $t6, 0xC($a0)
    /* 11258 80020A58 00488C48 */  mtc2       $t4, $9 /* handwritten instruction */
    /* 1125C 80020A5C 00508D48 */  mtc2       $t5, $10 /* handwritten instruction */
    /* 11260 80020A60 00588E48 */  mtc2       $t6, $11 /* handwritten instruction */
    /* 11264 80020A64 00000000 */  nop
    /* 11268 80020A68 00000000 */  nop
    /* 1126C 80020A6C 12E0494A */  mvmva      1, 0, 3, 3, 0
    /* 11270 80020A70 00480C48 */  mfc2       $t4, $9 /* handwritten instruction */
    /* 11274 80020A74 00500D48 */  mfc2       $t5, $10 /* handwritten instruction */
    /* 11278 80020A78 00580E48 */  mfc2       $t6, $11 /* handwritten instruction */
    /* 1127C 80020A7C 0000ACA7 */  sh         $t4, 0x0($sp)
    /* 11280 80020A80 0600ADA7 */  sh         $t5, 0x6($sp)
    /* 11284 80020A84 0C00AEA7 */  sh         $t6, 0xC($sp)
    /* 11288 80020A88 02008224 */  addiu      $v0, $a0, 0x2
    /* 1128C 80020A8C 00004C94 */  lhu        $t4, 0x0($v0)
    /* 11290 80020A90 06004D94 */  lhu        $t5, 0x6($v0)
    /* 11294 80020A94 0C004E94 */  lhu        $t6, 0xC($v0)
    /* 11298 80020A98 00488C48 */  mtc2       $t4, $9 /* handwritten instruction */
    /* 1129C 80020A9C 00508D48 */  mtc2       $t5, $10 /* handwritten instruction */
    /* 112A0 80020AA0 00588E48 */  mtc2       $t6, $11 /* handwritten instruction */
    /* 112A4 80020AA4 00000000 */  nop
    /* 112A8 80020AA8 00000000 */  nop
    /* 112AC 80020AAC 12E0494A */  mvmva      1, 0, 3, 3, 0
    /* 112B0 80020AB0 0200A227 */  addiu      $v0, $sp, 0x2
    /* 112B4 80020AB4 00480C48 */  mfc2       $t4, $9 /* handwritten instruction */
    /* 112B8 80020AB8 00500D48 */  mfc2       $t5, $10 /* handwritten instruction */
    /* 112BC 80020ABC 00580E48 */  mfc2       $t6, $11 /* handwritten instruction */
    /* 112C0 80020AC0 00004CA4 */  sh         $t4, 0x0($v0)
    /* 112C4 80020AC4 06004DA4 */  sh         $t5, 0x6($v0)
    /* 112C8 80020AC8 0C004EA4 */  sh         $t6, 0xC($v0)
    /* 112CC 80020ACC 04008224 */  addiu      $v0, $a0, 0x4
    /* 112D0 80020AD0 00004C94 */  lhu        $t4, 0x0($v0)
    /* 112D4 80020AD4 06004D94 */  lhu        $t5, 0x6($v0)
    /* 112D8 80020AD8 0C004E94 */  lhu        $t6, 0xC($v0)
    /* 112DC 80020ADC 00488C48 */  mtc2       $t4, $9 /* handwritten instruction */
    /* 112E0 80020AE0 00508D48 */  mtc2       $t5, $10 /* handwritten instruction */
    /* 112E4 80020AE4 00588E48 */  mtc2       $t6, $11 /* handwritten instruction */
    /* 112E8 80020AE8 00000000 */  nop
    /* 112EC 80020AEC 00000000 */  nop
    /* 112F0 80020AF0 12E0494A */  mvmva      1, 0, 3, 3, 0
    /* 112F4 80020AF4 0400A227 */  addiu      $v0, $sp, 0x4
    /* 112F8 80020AF8 00480C48 */  mfc2       $t4, $9 /* handwritten instruction */
    /* 112FC 80020AFC 00500D48 */  mfc2       $t5, $10 /* handwritten instruction */
    /* 11300 80020B00 00580E48 */  mfc2       $t6, $11 /* handwritten instruction */
    /* 11304 80020B04 00004CA4 */  sh         $t4, 0x0($v0)
    /* 11308 80020B08 06004DA4 */  sh         $t5, 0x6($v0)
    /* 1130C 80020B0C 0C004EA4 */  sh         $t6, 0xC($v0)
    /* 11310 80020B10 0680063C */  lui        $a2, %hi(GsWSMATRIX)
    /* 11314 80020B14 081AC624 */  addiu      $a2, $a2, %lo(GsWSMATRIX)
    /* 11318 80020B18 1400CC8C */  lw         $t4, 0x14($a2)
    /* 1131C 80020B1C 1800CD8C */  lw         $t5, 0x18($a2)
    /* 11320 80020B20 0028CC48 */  ctc2       $t4, $5 /* handwritten instruction */
    /* 11324 80020B24 1C00CE8C */  lw         $t6, 0x1C($a2)
    /* 11328 80020B28 0030CD48 */  ctc2       $t5, $6 /* handwritten instruction */
    /* 1132C 80020B2C 0038CE48 */  ctc2       $t6, $7 /* handwritten instruction */
    /* 11330 80020B30 04006D94 */  lhu        $t5, 0x4($v1)
    /* 11334 80020B34 00006C94 */  lhu        $t4, 0x0($v1)
    /* 11338 80020B38 006C0D00 */  sll        $t5, $t5, 16
    /* 1133C 80020B3C 25608D01 */  or         $t4, $t4, $t5
    /* 11340 80020B40 00008C48 */  mtc2       $t4, $0 /* handwritten instruction */
    /* 11344 80020B44 080061C8 */  lwc2       $1, 0x8($v1)
    /* 11348 80020B48 00000000 */  nop
    /* 1134C 80020B4C 00000000 */  nop
    /* 11350 80020B50 1200484A */  mvmva      1, 0, 0, 0, 0
    /* 11354 80020B54 1400A227 */  addiu      $v0, $sp, 0x14
    /* 11358 80020B58 000059E8 */  swc2       $25, 0x0($v0)
    /* 1135C 80020B5C 04005AE8 */  swc2       $26, 0x4($v0) /* handwritten instruction */
    /* 11360 80020B60 08005BE8 */  swc2       $27, 0x8($v0) /* handwritten instruction */
    /* 11364 80020B64 0000AC8F */  lw         $t4, 0x0($sp)
    /* 11368 80020B68 0400AD8F */  lw         $t5, 0x4($sp)
    /* 1136C 80020B6C 0000CC48 */  ctc2       $t4, $0 /* handwritten instruction */
    /* 11370 80020B70 0008CD48 */  ctc2       $t5, $1 /* handwritten instruction */
    /* 11374 80020B74 0800AC8F */  lw         $t4, 0x8($sp)
    /* 11378 80020B78 0C00AD8F */  lw         $t5, 0xC($sp)
    /* 1137C 80020B7C 1000AE8F */  lw         $t6, 0x10($sp)
    /* 11380 80020B80 0010CC48 */  ctc2       $t4, $2 /* handwritten instruction */
    /* 11384 80020B84 0018CD48 */  ctc2       $t5, $3 /* handwritten instruction */
    /* 11388 80020B88 0020CE48 */  ctc2       $t6, $4 /* handwritten instruction */
    /* 1138C 80020B8C 1400AC8F */  lw         $t4, 0x14($sp)
    /* 11390 80020B90 1800AD8F */  lw         $t5, 0x18($sp)
    /* 11394 80020B94 0028CC48 */  ctc2       $t4, $5 /* handwritten instruction */
    /* 11398 80020B98 1C00AE8F */  lw         $t6, 0x1C($sp)
    /* 1139C 80020B9C 0030CD48 */  ctc2       $t5, $6 /* handwritten instruction */
    /* 113A0 80020BA0 0038CE48 */  ctc2       $t6, $7 /* handwritten instruction */
    /* 113A4 80020BA4 0580073C */  lui        $a3, %hi(Gfx_ZeroSVector)
    /* 113A8 80020BA8 4407E724 */  addiu      $a3, $a3, %lo(Gfx_ZeroSVector)
    /* 113AC 80020BAC 0000E0C8 */  lwc2       $0, 0x0($a3)
    /* 113B0 80020BB0 0400E1C8 */  lwc2       $1, 0x4($a3)
    /* 113B4 80020BB4 00000000 */  nop
    /* 113B8 80020BB8 00000000 */  nop
    /* 113BC 80020BBC 0100184A */  rtps
    /* 113C0 80020BC0 68008224 */  addiu      $v0, $a0, 0x68
    /* 113C4 80020BC4 00004EE8 */  swc2       $14, 0x0($v0)
    /* 113C8 80020BC8 68008384 */  lh         $v1, 0x68($a0)
    /* 113CC 80020BCC 00000000 */  nop
    /* 113D0 80020BD0 A0FE6228 */  slti       $v0, $v1, -0x160
    /* 113D4 80020BD4 0D004014 */  bnez       $v0, .L80020C0C
    /* 113D8 80020BD8 01000224 */   addiu     $v0, $zero, 0x1
    /* 113DC 80020BDC 60010224 */  addiu      $v0, $zero, 0x160
    /* 113E0 80020BE0 2A104300 */  slt        $v0, $v0, $v1
    /* 113E4 80020BE4 09004014 */  bnez       $v0, .L80020C0C
    /* 113E8 80020BE8 01000224 */   addiu     $v0, $zero, 0x1
    /* 113EC 80020BEC 6A008384 */  lh         $v1, 0x6A($a0)
    /* 113F0 80020BF0 00000000 */  nop
    /* 113F4 80020BF4 F0FE6228 */  slti       $v0, $v1, -0x110
    /* 113F8 80020BF8 03004014 */  bnez       $v0, .L80020C08
    /* 113FC 80020BFC 10010224 */   addiu     $v0, $zero, 0x110
    /* 11400 80020C00 03830008 */  j          .L80020C0C
    /* 11404 80020C04 2A104300 */   slt       $v0, $v0, $v1
  .L80020C08:
    /* 11408 80020C08 01000224 */  addiu      $v0, $zero, 0x1
  .L80020C0C:
    /* 1140C 80020C0C 0800E003 */  jr         $ra
    /* 11410 80020C10 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Actor_ProjectToScreen
