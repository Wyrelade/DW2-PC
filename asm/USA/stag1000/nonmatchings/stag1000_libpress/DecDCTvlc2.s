/* Handwritten function */
nonmatching DecDCTvlc2, 0x34C

glabel DecDCTvlc2
    /* 1A20 80064D80 0680083C */  lui        $t0, %hi(D_800653A8)
    /* 1A24 80064D84 A8530825 */  addiu      $t0, $t0, %lo(D_800653A8)
    /* 1A28 80064D88 0008C620 */  addi       $a2, $a2, 0x800 /* handwritten instruction */
    /* 1A2C 80064D8C 0100013C */  lui        $at, (0x10000 >> 16)
    /* 1A30 80064D90 2038C100 */  add        $a3, $a2, $at /* handwritten instruction */
    /* 1A34 80064D94 0F008014 */  bnez       $a0, .L80064DD4
    /* 1A38 80064D98 0000098D */   lw        $t1, 0x0($t0)
    /* 1A3C 80064D9C 0680083C */  lui        $t0, %hi(D_800653AC)
    /* 1A40 80064DA0 AC530825 */  addiu      $t0, $t0, %lo(D_800653AC)
    /* 1A44 80064DA4 0000048D */  lw         $a0, 0x0($t0)
    /* 1A48 80064DA8 0400058D */  lw         $a1, 0x4($t0)
    /* 1A4C 80064DAC 0800028D */  lw         $v0, 0x8($t0)
    /* 1A50 80064DB0 0C00038D */  lw         $v1, 0xC($t0)
    /* 1A54 80064DB4 10000C8D */  lw         $t4, 0x10($t0)
    /* 1A58 80064DB8 14000D8D */  lw         $t5, 0x14($t0)
    /* 1A5C 80064DBC 18000F8D */  lw         $t7, 0x18($t0)
    /* 1A60 80064DC0 1C00188D */  lw         $t8, 0x1C($t0)
    /* 1A64 80064DC4 2000198D */  lw         $t9, 0x20($t0)
    /* 1A68 80064DC8 20482901 */  add        $t1, $t1, $t1 /* handwritten instruction */
    /* 1A6C 80064DCC 64000010 */  b          .L80064F60
    /* 1A70 80064DD0 2070A900 */   add       $t6, $a1, $t1 /* handwritten instruction */
  .L80064DD4:
    /* 1A74 80064DD4 20680000 */  add        $t5, $zero, $zero /* handwritten instruction */
    /* 1A78 80064DD8 20780000 */  add        $t7, $zero, $zero /* handwritten instruction */
    /* 1A7C 80064DDC 20C00000 */  add        $t8, $zero, $zero /* handwritten instruction */
    /* 1A80 80064DE0 20C80000 */  add        $t9, $zero, $zero /* handwritten instruction */
    /* 1A84 80064DE4 20482901 */  add        $t1, $t1, $t1 /* handwritten instruction */
    /* 1A88 80064DE8 2070A900 */  add        $t6, $a1, $t1 /* handwritten instruction */
    /* 1A8C 80064DEC 0000898C */  lw         $t1, 0x0($a0)
    /* 1A90 80064DF0 04008C94 */  lhu        $t4, 0x4($a0)
    /* 1A94 80064DF4 06008A94 */  lhu        $t2, 0x6($a0)
    /* 1A98 80064DF8 08008294 */  lhu        $v0, 0x8($a0)
    /* 1A9C 80064DFC 0A008394 */  lhu        $v1, 0xA($a0)
    /* 1AA0 80064E00 FDFF4A21 */  addi       $t2, $t2, -0x3 /* handwritten instruction */
    /* 1AA4 80064E04 02004005 */  bltz       $t2, .L80064E10
    /* 1AA8 80064E08 80620C00 */   sll       $t4, $t4, 10
    /* 1AAC 80064E0C 01000D20 */  addi       $t5, $zero, 0x1 /* handwritten instruction */
  .L80064E10:
    /* 1AB0 80064E10 0C008420 */  addi       $a0, $a0, 0xC /* handwritten instruction */
    /* 1AB4 80064E14 00140200 */  sll        $v0, $v0, 16
    /* 1AB8 80064E18 25104300 */  or         $v0, $v0, $v1
    /* 1ABC 80064E1C 25180000 */  or         $v1, $zero, $zero
    /* 1AC0 80064E20 0000A9AC */  sw         $t1, 0x0($a1)
    /* 1AC4 80064E24 FFFF2931 */  andi       $t1, $t1, 0xFFFF
    /* 1AC8 80064E28 80480900 */  sll        $t1, $t1, 2
    /* 1ACC 80064E2C 04002925 */  addiu      $t1, $t1, 0x4
    /* 1AD0 80064E30 20482501 */  add        $t1, $t1, $a1 /* handwritten instruction */
    /* 1AD4 80064E34 0680083C */  lui        $t0, %hi(D_800653D0)
    /* 1AD8 80064E38 D0530825 */  addiu      $t0, $t0, %lo(D_800653D0)
    /* 1ADC 80064E3C 000009AD */  sw         $t1, 0x0($t0)
    /* 1AE0 80064E40 0200A520 */  addi       $a1, $a1, 0x2 /* handwritten instruction */
  .L80064E44:
    /* 1AE4 80064E44 3500A011 */  beqz       $t5, .L80064F1C
    /* 1AE8 80064E48 82450200 */   srl       $t0, $v0, 22
    /* 1AEC 80064E4C FF030139 */  xori       $at, $t0, 0x3FF
    /* 1AF0 80064E50 85002010 */  beqz       $at, .L80065068
    /* 1AF4 80064E54 0200A520 */   addi      $a1, $a1, 0x2 /* handwritten instruction */
    /* 1AF8 80064E58 FDFFA121 */  addi       $at, $t5, -0x3 /* handwritten instruction */
    /* 1AFC 80064E5C 02002004 */  bltz       $at, .L80064E68
    /* 1B00 80064E60 00FCC120 */   addi      $at, $a2, -0x400 /* handwritten instruction */
    /* 1B04 80064E64 00FC2120 */  addi       $at, $at, -0x400 /* handwritten instruction */
  .L80064E68:
    /* 1B08 80064E68 02460200 */  srl        $t0, $v0, 24
    /* 1B0C 80064E6C 80400800 */  sll        $t0, $t0, 2
    /* 1B10 80064E70 20400101 */  add        $t0, $t0, $at /* handwritten instruction */
    /* 1B14 80064E74 00000995 */  lhu        $t1, 0x0($t0)
    /* 1B18 80064E78 02000A95 */  lhu        $t2, 0x2($t0)
    /* 1B1C 80064E7C 24400000 */  and        $t0, $zero, $zero
    /* 1B20 80064E80 0A004011 */  beqz       $t2, .L80064EAC
    /* 1B24 80064E84 04102201 */   sllv      $v0, $v0, $t1
    /* 1B28 80064E88 20000120 */  addi       $at, $zero, 0x20 /* handwritten instruction */
    /* 1B2C 80064E8C 22082A00 */  sub        $at, $at, $t2 /* handwritten instruction */
    /* 1B30 80064E90 06402200 */  srlv       $t0, $v0, $at
    /* 1B34 80064E94 04004004 */  bltz       $v0, .L80064EA8
    /* 1B38 80064E98 04104201 */   sllv      $v0, $v0, $t2
    /* 1B3C 80064E9C FFFF0B20 */  addi       $t3, $zero, -0x1 /* handwritten instruction */
    /* 1B40 80064EA0 06582B00 */  srlv       $t3, $t3, $at
    /* 1B44 80064EA4 22400B01 */  sub        $t0, $t0, $t3 /* handwritten instruction */
  .L80064EA8:
    /* 1B48 80064EA8 20186A00 */  add        $v1, $v1, $t2 /* handwritten instruction */
  .L80064EAC:
    /* 1B4C 80064EAC 20186900 */  add        $v1, $v1, $t1 /* handwritten instruction */
    /* 1B50 80064EB0 10006130 */  andi       $at, $v1, 0x10
    /* 1B54 80064EB4 05002010 */  beqz       $at, .L80064ECC
    /* 1B58 80064EB8 0F006330 */   andi      $v1, $v1, 0xF
    /* 1B5C 80064EBC 00008994 */  lhu        $t1, 0x0($a0)
    /* 1B60 80064EC0 02008420 */  addi       $a0, $a0, 0x2 /* handwritten instruction */
    /* 1B64 80064EC4 04486900 */  sllv       $t1, $t1, $v1
    /* 1B68 80064EC8 25104900 */  or         $v0, $v0, $t1
  .L80064ECC:
    /* 1B6C 80064ECC FEFFA121 */  addi       $at, $t5, -0x2 /* handwritten instruction */
    /* 1B70 80064ED0 0800201C */  bgtz       $at, .L80064EF4
    /* 1B74 80064ED4 20482803 */   add       $t1, $t9, $t0 /* handwritten instruction */
    /* 1B78 80064ED8 04002010 */  beqz       $at, .L80064EEC
    /* 1B7C 80064EDC 20480803 */   add       $t1, $t8, $t0 /* handwritten instruction */
    /* 1B80 80064EE0 2048E801 */  add        $t1, $t7, $t0 /* handwritten instruction */
    /* 1B84 80064EE4 04000010 */  b          .L80064EF8
    /* 1B88 80064EE8 2078E801 */   add       $t7, $t7, $t0 /* handwritten instruction */
  .L80064EEC:
    /* 1B8C 80064EEC 02000010 */  b          .L80064EF8
    /* 1B90 80064EF0 20C00803 */   add       $t8, $t8, $t0 /* handwritten instruction */
  .L80064EF4:
    /* 1B94 80064EF4 20C82803 */  add        $t9, $t9, $t0 /* handwritten instruction */
  .L80064EF8:
    /* 1B98 80064EF8 80480900 */  sll        $t1, $t1, 2
    /* 1B9C 80064EFC FF032931 */  andi       $t1, $t1, 0x3FF
    /* 1BA0 80064F00 25488901 */  or         $t1, $t4, $t1
    /* 1BA4 80064F04 0100AD21 */  addi       $t5, $t5, 0x1 /* handwritten instruction */
    /* 1BA8 80064F08 F9FFA121 */  addi       $at, $t5, -0x7 /* handwritten instruction */
    /* 1BAC 80064F0C 11002014 */  bnez       $at, .L80064F54
    /* 1BB0 80064F10 0000A9A4 */   sh        $t1, 0x0($a1)
    /* 1BB4 80064F14 0F000010 */  b          .L80064F54
    /* 1BB8 80064F18 FAFFAD21 */   addi      $t5, $t5, -0x6 /* handwritten instruction */
  .L80064F1C:
    /* 1BBC 80064F1C FF010139 */  xori       $at, $t0, 0x1FF
    /* 1BC0 80064F20 51002010 */  beqz       $at, .L80065068
    /* 1BC4 80064F24 0200A520 */   addi      $a1, $a1, 0x2 /* handwritten instruction */
    /* 1BC8 80064F28 80120200 */  sll        $v0, $v0, 10
    /* 1BCC 80064F2C 0A006320 */  addi       $v1, $v1, 0xA /* handwritten instruction */
    /* 1BD0 80064F30 10006130 */  andi       $at, $v1, 0x10
    /* 1BD4 80064F34 05002010 */  beqz       $at, .L80064F4C
    /* 1BD8 80064F38 0F006330 */   andi      $v1, $v1, 0xF
    /* 1BDC 80064F3C 00008994 */  lhu        $t1, 0x0($a0)
    /* 1BE0 80064F40 02008420 */  addi       $a0, $a0, 0x2 /* handwritten instruction */
    /* 1BE4 80064F44 04486900 */  sllv       $t1, $t1, $v1
    /* 1BE8 80064F48 25104900 */  or         $v0, $v0, $t1
  .L80064F4C:
    /* 1BEC 80064F4C 25408801 */  or         $t0, $t4, $t0
    /* 1BF0 80064F50 0000A8A4 */  sh         $t0, 0x0($a1)
  .L80064F54:
    /* 1BF4 80064F54 2308AE00 */  subu       $at, $a1, $t6
    /* 1BF8 80064F58 4F002104 */  bgez       $at, .L80065098
    /* 1BFC 80064F5C 0200A520 */   addi      $a1, $a1, 0x2 /* handwritten instruction */
  .L80064F60:
    /* 1C00 80064F60 C2440200 */  srl        $t0, $v0, 19
    /* 1C04 80064F64 C0400800 */  sll        $t0, $t0, 3
    /* 1C08 80064F68 20400601 */  add        $t0, $t0, $a2 /* handwritten instruction */
    /* 1C0C 80064F6C 0000098D */  lw         $t1, 0x0($t0)
    /* 1C10 80064F70 00000000 */  nop
    /* 1C14 80064F74 11002015 */  bnez       $t1, .L80064FBC
    /* 1C18 80064F78 FF002131 */   andi      $at, $t1, 0xFF
    /* 1C1C 80064F7C 00120200 */  sll        $v0, $v0, 8
    /* 1C20 80064F80 08006320 */  addi       $v1, $v1, 0x8 /* handwritten instruction */
    /* 1C24 80064F84 10006130 */  andi       $at, $v1, 0x10
    /* 1C28 80064F88 05002010 */  beqz       $at, .L80064FA0
    /* 1C2C 80064F8C 0F006330 */   andi      $v1, $v1, 0xF
    /* 1C30 80064F90 00008894 */  lhu        $t0, 0x0($a0)
    /* 1C34 80064F94 02008420 */  addi       $a0, $a0, 0x2 /* handwritten instruction */
    /* 1C38 80064F98 04406800 */  sllv       $t0, $t0, $v1
    /* 1C3C 80064F9C 25104800 */  or         $v0, $v0, $t0
  .L80064FA0:
    /* 1C40 80064FA0 C2450200 */  srl        $t0, $v0, 23
    /* 1C44 80064FA4 80400800 */  sll        $t0, $t0, 2
    /* 1C48 80064FA8 20400701 */  add        $t0, $t0, $a3 /* handwritten instruction */
    /* 1C4C 80064FAC 0000098D */  lw         $t1, 0x0($t0)
    /* 1C50 80064FB0 20580000 */  add        $t3, $zero, $zero /* handwritten instruction */
    /* 1C54 80064FB4 02000010 */  b          .L80064FC0
    /* 1C58 80064FB8 FF002131 */   andi      $at, $t1, 0xFF
  .L80064FBC:
    /* 1C5C 80064FBC 04000B8D */  lw         $t3, 0x4($t0)
  .L80064FC0:
    /* 1C60 80064FC0 04102200 */  sllv       $v0, $v0, $at
    /* 1C64 80064FC4 20186100 */  add        $v1, $v1, $at /* handwritten instruction */
    /* 1C68 80064FC8 10006130 */  andi       $at, $v1, 0x10
    /* 1C6C 80064FCC 05002010 */  beqz       $at, .L80064FE4
    /* 1C70 80064FD0 0F006330 */   andi      $v1, $v1, 0xF
    /* 1C74 80064FD4 00008894 */  lhu        $t0, 0x0($a0)
    /* 1C78 80064FD8 02008420 */  addi       $a0, $a0, 0x2 /* handwritten instruction */
    /* 1C7C 80064FDC 04406800 */  sllv       $t0, $t0, $v1
    /* 1C80 80064FE0 25104800 */  or         $v0, $v0, $t0
  .L80064FE4:
    /* 1C84 80064FE4 024C0900 */  srl        $t1, $t1, 16
    /* 1C88 80064FE8 1F7C2139 */  xori       $at, $t1, 0x7C1F
    /* 1C8C 80064FEC 15002010 */  beqz       $at, .L80065044
    /* 1C90 80064FF0 00FE2139 */   xori      $at, $t1, 0xFE00
    /* 1C94 80064FF4 93FF2010 */  beqz       $at, .L80064E44
    /* 1C98 80064FF8 0000A9A4 */   sh        $t1, 0x0($a1)
    /* 1C9C 80064FFC D8FF6011 */  beqz       $t3, .L80064F60
    /* 1CA0 80065000 0200A520 */   addi      $a1, $a1, 0x2 /* handwritten instruction */
    /* 1CA4 80065004 FFFF6A31 */  andi       $t2, $t3, 0xFFFF
    /* 1CA8 80065008 1F7C4139 */  xori       $at, $t2, 0x7C1F
    /* 1CAC 8006500C 0D002010 */  beqz       $at, .L80065044
    /* 1CB0 80065010 00FE4139 */   xori      $at, $t2, 0xFE00
    /* 1CB4 80065014 8BFF2010 */  beqz       $at, .L80064E44
    /* 1CB8 80065018 0000AAA4 */   sh        $t2, 0x0($a1)
    /* 1CBC 8006501C 02540B00 */  srl        $t2, $t3, 16
    /* 1CC0 80065020 CFFF4011 */  beqz       $t2, .L80064F60
    /* 1CC4 80065024 0200A520 */   addi      $a1, $a1, 0x2 /* handwritten instruction */
    /* 1CC8 80065028 1F7C4139 */  xori       $at, $t2, 0x7C1F
    /* 1CCC 8006502C 05002010 */  beqz       $at, .L80065044
    /* 1CD0 80065030 00FE4139 */   xori      $at, $t2, 0xFE00
    /* 1CD4 80065034 83FF2010 */  beqz       $at, .L80064E44
    /* 1CD8 80065038 0000AAA4 */   sh        $t2, 0x0($a1)
    /* 1CDC 8006503C C8FF0010 */  b          .L80064F60
    /* 1CE0 80065040 0200A520 */   addi      $a1, $a1, 0x2 /* handwritten instruction */
  .L80065044:
    /* 1CE4 80065044 02440200 */  srl        $t0, $v0, 16
    /* 1CE8 80065048 0000A8A4 */  sh         $t0, 0x0($a1)
    /* 1CEC 8006504C 0200A520 */  addi       $a1, $a1, 0x2 /* handwritten instruction */
    /* 1CF0 80065050 00008894 */  lhu        $t0, 0x0($a0)
    /* 1CF4 80065054 02008420 */  addi       $a0, $a0, 0x2 /* handwritten instruction */
    /* 1CF8 80065058 00140200 */  sll        $v0, $v0, 16
    /* 1CFC 8006505C 04406800 */  sllv       $t0, $t0, $v1
    /* 1D00 80065060 BFFF0010 */  b          .L80064F60
    /* 1D04 80065064 25104800 */   or        $v0, $v0, $t0
  .L80065068:
    /* 1D08 80065068 0680083C */  lui        $t0, %hi(D_800653D0)
    /* 1D0C 8006506C D0530825 */  addiu      $t0, $t0, %lo(D_800653D0)
    /* 1D10 80065070 0000098D */  lw         $t1, 0x0($t0)
    /* 1D14 80065074 00FE0834 */  ori        $t0, $zero, 0xFE00
  .L80065078:
    /* 1D18 80065078 2308A900 */  subu       $at, $a1, $t1
    /* 1D1C 8006507C 04002104 */  bgez       $at, .L80065090
    /* 1D20 80065080 00000000 */   nop
    /* 1D24 80065084 0000A8A4 */  sh         $t0, 0x0($a1)
    /* 1D28 80065088 FBFF0010 */  b          .L80065078
    /* 1D2C 8006508C 0200A520 */   addi      $a1, $a1, 0x2 /* handwritten instruction */
  .L80065090:
    /* 1D30 80065090 0800E003 */  jr         $ra
    /* 1D34 80065094 20100000 */   add       $v0, $zero, $zero /* handwritten instruction */
  .L80065098:
    /* 1D38 80065098 0680083C */  lui        $t0, %hi(D_800653AC)
    /* 1D3C 8006509C AC530825 */  addiu      $t0, $t0, %lo(D_800653AC)
    /* 1D40 800650A0 000004AD */  sw         $a0, 0x0($t0)
    /* 1D44 800650A4 040005AD */  sw         $a1, 0x4($t0)
    /* 1D48 800650A8 080002AD */  sw         $v0, 0x8($t0)
    /* 1D4C 800650AC 0C0003AD */  sw         $v1, 0xC($t0)
    /* 1D50 800650B0 10000CAD */  sw         $t4, 0x10($t0)
    /* 1D54 800650B4 14000DAD */  sw         $t5, 0x14($t0)
    /* 1D58 800650B8 18000FAD */  sw         $t7, 0x18($t0)
    /* 1D5C 800650BC 1C0018AD */  sw         $t8, 0x1C($t0)
    /* 1D60 800650C0 200019AD */  sw         $t9, 0x20($t0)
    /* 1D64 800650C4 0800E003 */  jr         $ra
    /* 1D68 800650C8 01000220 */   addi      $v0, $zero, 0x1 /* handwritten instruction */
endlabel DecDCTvlc2
    /* 1D6C 800650CC 00000000 */  nop
