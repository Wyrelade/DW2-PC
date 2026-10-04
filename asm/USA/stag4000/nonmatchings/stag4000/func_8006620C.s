nonmatching func_8006620C, 0x10C

glabel func_8006620C
    /* 2EAC 8006620C 0780023C */  lui        $v0, %hi(D_80072B60)
    /* 2EB0 80066210 602B438C */  lw         $v1, %lo(D_80072B60)($v0)
    /* 2EB4 80066214 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 2EB8 80066218 2400B5AF */  sw         $s5, 0x24($sp)
    /* 2EBC 8006621C 21A88000 */  addu       $s5, $a0, $zero
    /* 2EC0 80066220 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 2EC4 80066224 2800B6AF */  sw         $s6, 0x28($sp)
    /* 2EC8 80066228 2000B4AF */  sw         $s4, 0x20($sp)
    /* 2ECC 8006622C 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 2ED0 80066230 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2ED4 80066234 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2ED8 80066238 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2EDC 8006623C 3000628C */  lw         $v0, 0x30($v1)
    /* 2EE0 80066240 00000000 */  nop
    /* 2EE4 80066244 3F004230 */  andi       $v0, $v0, 0x3F
    /* 2EE8 80066248 02004010 */  beqz       $v0, .L80066254
    /* 2EEC 8006624C 09001624 */   addiu     $s6, $zero, 0x9
    /* 2EF0 80066250 0A001624 */  addiu      $s6, $zero, 0xA
  .L80066254:
    /* 2EF4 80066254 2C00628C */  lw         $v0, 0x2C($v1)
    /* 2EF8 80066258 00000000 */  nop
    /* 2EFC 8006625C 3F004230 */  andi       $v0, $v0, 0x3F
    /* 2F00 80066260 02004010 */  beqz       $v0, .L8006626C
    /* 2F04 80066264 09001424 */   addiu     $s4, $zero, 0x9
    /* 2F08 80066268 0A001424 */  addiu      $s4, $zero, 0xA
  .L8006626C:
    /* 2F0C 8006626C 0680023C */  lui        $v0, %hi(Sys_PacketCursor)
    /* 2F10 80066270 9CF7458C */  lw         $a1, %lo(Sys_PacketCursor)($v0)
    /* 2F14 80066274 1C00C012 */  beqz       $s6, .L800662E8
    /* 2F18 80066278 21900000 */   addu      $s2, $zero, $zero
    /* 2F1C 8006627C 21984002 */  addu       $s3, $s2, $zero
  .L80066280:
    /* 2F20 80066280 15008012 */  beqz       $s4, .L800662D8
    /* 2F24 80066284 21800000 */   addu      $s0, $zero, $zero
    /* 2F28 80066288 21886002 */  addu       $s1, $s3, $zero
  .L8006628C:
    /* 2F2C 8006628C 2120A002 */  addu       $a0, $s5, $zero
    /* 2F30 80066290 21300002 */  addu       $a2, $s0, $zero
    /* 2F34 80066294 E597010C */  jal        func_80065F94
    /* 2F38 80066298 21384002 */   addu      $a3, $s2, $zero
    /* 2F3C 8006629C 2118B102 */  addu       $v1, $s5, $s1
    /* 2F40 800662A0 200F6394 */  lhu        $v1, 0xF20($v1)
    /* 2F44 800662A4 00000000 */  nop
    /* 2F48 800662A8 000F6330 */  andi       $v1, $v1, 0xF00
    /* 2F4C 800662AC 06006010 */  beqz       $v1, .L800662C8
    /* 2F50 800662B0 21284000 */   addu      $a1, $v0, $zero
    /* 2F54 800662B4 2120A002 */  addu       $a0, $s5, $zero
    /* 2F58 800662B8 21300002 */  addu       $a2, $s0, $zero
    /* 2F5C 800662BC 1497010C */  jal        func_80065C50
    /* 2F60 800662C0 21384002 */   addu      $a3, $s2, $zero
    /* 2F64 800662C4 21284000 */  addu       $a1, $v0, $zero
  .L800662C8:
    /* 2F68 800662C8 01001026 */  addiu      $s0, $s0, 0x1
    /* 2F6C 800662CC 2A101402 */  slt        $v0, $s0, $s4
    /* 2F70 800662D0 EEFF4014 */  bnez       $v0, .L8006628C
    /* 2F74 800662D4 0C003126 */   addiu     $s1, $s1, 0xC
  .L800662D8:
    /* 2F78 800662D8 01005226 */  addiu      $s2, $s2, 0x1
    /* 2F7C 800662DC 2A105602 */  slt        $v0, $s2, $s6
    /* 2F80 800662E0 E7FF4014 */  bnez       $v0, .L80066280
    /* 2F84 800662E4 78007326 */   addiu     $s3, $s3, 0x78
  .L800662E8:
    /* 2F88 800662E8 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 2F8C 800662EC 2800B68F */  lw         $s6, 0x28($sp)
    /* 2F90 800662F0 2400B58F */  lw         $s5, 0x24($sp)
    /* 2F94 800662F4 2000B48F */  lw         $s4, 0x20($sp)
    /* 2F98 800662F8 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 2F9C 800662FC 1800B28F */  lw         $s2, 0x18($sp)
    /* 2FA0 80066300 1400B18F */  lw         $s1, 0x14($sp)
    /* 2FA4 80066304 1000B08F */  lw         $s0, 0x10($sp)
    /* 2FA8 80066308 0680023C */  lui        $v0, %hi(Sys_PacketCursor)
    /* 2FAC 8006630C 9CF745AC */  sw         $a1, %lo(Sys_PacketCursor)($v0)
    /* 2FB0 80066310 0800E003 */  jr         $ra
    /* 2FB4 80066314 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_8006620C
