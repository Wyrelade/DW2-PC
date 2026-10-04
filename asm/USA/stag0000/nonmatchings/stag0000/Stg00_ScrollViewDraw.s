nonmatching Stg00_ScrollViewDraw, 0x1C8

glabel Stg00_ScrollViewDraw
    /* B3C 80063E9C C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* B40 80063EA0 2400B5AF */  sw         $s5, 0x24($sp)
    /* B44 80063EA4 21A80000 */  addu       $s5, $zero, $zero
    /* B48 80063EA8 0780023C */  lui        $v0, %hi(D_80068AA0)
    /* B4C 80063EAC 3000BEAF */  sw         $fp, 0x30($sp)
    /* B50 80063EB0 A08A5E24 */  addiu      $fp, $v0, %lo(D_80068AA0)
    /* B54 80063EB4 2000B4AF */  sw         $s4, 0x20($sp)
    /* B58 80063EB8 FF00143C */  lui        $s4, (0xFFFFFF >> 16)
    /* B5C 80063EBC FFFF9436 */  ori        $s4, $s4, (0xFFFFFF & 0xFFFF)
    /* B60 80063EC0 0680023C */  lui        $v0, %hi(Sys_State)
    /* B64 80063EC4 70F74224 */  addiu      $v0, $v0, %lo(Sys_State)
    /* B68 80063EC8 3400BFAF */  sw         $ra, 0x34($sp)
    /* B6C 80063ECC 2C00B7AF */  sw         $s7, 0x2C($sp)
    /* B70 80063ED0 2800B6AF */  sw         $s6, 0x28($sp)
    /* B74 80063ED4 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* B78 80063ED8 1800B2AF */  sw         $s2, 0x18($sp)
    /* B7C 80063EDC 1400B1AF */  sw         $s1, 0x14($sp)
    /* B80 80063EE0 1000B0AF */  sw         $s0, 0x10($sp)
    /* B84 80063EE4 2C00978C */  lw         $s7, 0x2C($a0)
    /* B88 80063EE8 5001538C */  lw         $s3, 0x150($v0)
    /* B8C 80063EEC 2C00518C */  lw         $s1, 0x2C($v0)
    /* B90 80063EF0 21900000 */  addu       $s2, $zero, $zero
  .L80063EF4:
    /* B94 80063EF4 C2171500 */  srl        $v0, $s5, 31
    /* B98 80063EF8 2110A202 */  addu       $v0, $s5, $v0
    /* B9C 80063EFC 43100200 */  sra        $v0, $v0, 1
    /* BA0 80063F00 40100200 */  sll        $v0, $v0, 1
    /* BA4 80063F04 23B0A202 */  subu       $s6, $s5, $v0
  .L80063F08:
    /* BA8 80063F08 6666023C */  lui        $v0, (0x66666667 >> 16)
    /* BAC 80063F0C 67664234 */  ori        $v0, $v0, (0x66666667 & 0xFFFF)
    /* BB0 80063F10 18004202 */  mult       $s2, $v0
    /* BB4 80063F14 C3171200 */  sra        $v0, $s2, 31
    /* BB8 80063F18 10400000 */  mfhi       $t0
    /* BBC 80063F1C 83200800 */  sra        $a0, $t0, 2
    /* BC0 80063F20 23208200 */  subu       $a0, $a0, $v0
    /* BC4 80063F24 80180400 */  sll        $v1, $a0, 2
    /* BC8 80063F28 21186400 */  addu       $v1, $v1, $a0
    /* BCC 80063F2C 40180300 */  sll        $v1, $v1, 1
    /* BD0 80063F30 23184302 */  subu       $v1, $s2, $v1
    /* BD4 80063F34 80101600 */  sll        $v0, $s6, 2
    /* BD8 80063F38 21105600 */  addu       $v0, $v0, $s6
    /* BDC 80063F3C 40100200 */  sll        $v0, $v0, 1
    /* BE0 80063F40 21186200 */  addu       $v1, $v1, $v0
    /* BE4 80063F44 80180300 */  sll        $v1, $v1, 2
    /* BE8 80063F48 21187E00 */  addu       $v1, $v1, $fp
    /* BEC 80063F4C 0000648C */  lw         $a0, 0x0($v1)
    /* BF0 80063F50 E072000C */  jal        Gfx_FindOrLoadTexSlot
    /* BF4 80063F54 00000000 */   nop
    /* BF8 80063F58 21202002 */  addu       $a0, $s1, $zero
    /* BFC 80063F5C 80191200 */  sll        $v1, $s2, 6
    /* C00 80063F60 01005226 */  addiu      $s2, $s2, 0x1
    /* C04 80063F64 21804000 */  addu       $s0, $v0, $zero
    /* C08 80063F68 00121500 */  sll        $v0, $s5, 8
    /* C0C 80063F6C 21280002 */  addu       $a1, $s0, $zero
    /* C10 80063F70 0000E68E */  lw         $a2, 0x0($s7)
    /* C14 80063F74 0400E78E */  lw         $a3, 0x4($s7)
    /* C18 80063F78 60FFC624 */  addiu      $a2, $a2, -0xA0
    /* C1C 80063F7C 88FFE724 */  addiu      $a3, $a3, -0x78
    /* C20 80063F80 21306600 */  addu       $a2, $v1, $a2
    /* C24 80063F84 8D8F010C */  jal        Stg00_InitTileSprt
    /* C28 80063F88 21384700 */   addu      $a3, $v0, $a3
    /* C2C 80063F8C 00E1053C */  lui        $a1, (0xE1000600 >> 16)
    /* C30 80063F90 00FF043C */  lui        $a0, (0xFF000000 >> 16)
    /* C34 80063F94 0000228E */  lw         $v0, 0x0($s1)
    /* C38 80063F98 0000638E */  lw         $v1, 0x0($s3)
    /* C3C 80063F9C 24104400 */  and        $v0, $v0, $a0
    /* C40 80063FA0 24187400 */  and        $v1, $v1, $s4
    /* C44 80063FA4 25104300 */  or         $v0, $v0, $v1
    /* C48 80063FA8 24183402 */  and        $v1, $s1, $s4
    /* C4C 80063FAC 000022AE */  sw         $v0, 0x0($s1)
    /* C50 80063FB0 0000628E */  lw         $v0, 0x0($s3)
    /* C54 80063FB4 14003126 */  addiu      $s1, $s1, 0x14
    /* C58 80063FB8 24104400 */  and        $v0, $v0, $a0
    /* C5C 80063FBC 25104300 */  or         $v0, $v0, $v1
    /* C60 80063FC0 000062AE */  sw         $v0, 0x0($s3)
    /* C64 80063FC4 01000224 */  addiu      $v0, $zero, 0x1
    /* C68 80063FC8 030022A2 */  sb         $v0, 0x3($s1)
    /* C6C 80063FCC 10000296 */  lhu        $v0, 0x10($s0)
    /* C70 80063FD0 0006A534 */  ori        $a1, $a1, (0xE1000600 & 0xFFFF)
    /* C74 80063FD4 FF094230 */  andi       $v0, $v0, 0x9FF
    /* C78 80063FD8 25104500 */  or         $v0, $v0, $a1
    /* C7C 80063FDC 040022AE */  sw         $v0, 0x4($s1)
    /* C80 80063FE0 0000228E */  lw         $v0, 0x0($s1)
    /* C84 80063FE4 0000638E */  lw         $v1, 0x0($s3)
    /* C88 80063FE8 24104400 */  and        $v0, $v0, $a0
    /* C8C 80063FEC 24187400 */  and        $v1, $v1, $s4
    /* C90 80063FF0 25104300 */  or         $v0, $v0, $v1
    /* C94 80063FF4 24183402 */  and        $v1, $s1, $s4
    /* C98 80063FF8 000022AE */  sw         $v0, 0x0($s1)
    /* C9C 80063FFC 0000628E */  lw         $v0, 0x0($s3)
    /* CA0 80064000 00000000 */  nop
    /* CA4 80064004 24104400 */  and        $v0, $v0, $a0
    /* CA8 80064008 25104300 */  or         $v0, $v0, $v1
    /* CAC 8006400C 000062AE */  sw         $v0, 0x0($s3)
    /* CB0 80064010 1400422A */  slti       $v0, $s2, 0x14
    /* CB4 80064014 BCFF4014 */  bnez       $v0, .L80063F08
    /* CB8 80064018 08003126 */   addiu     $s1, $s1, 0x8
    /* CBC 8006401C 0100B526 */  addiu      $s5, $s5, 0x1
    /* CC0 80064020 0400A22A */  slti       $v0, $s5, 0x4
    /* CC4 80064024 B3FF4014 */  bnez       $v0, .L80063EF4
    /* CC8 80064028 21900000 */   addu      $s2, $zero, $zero
    /* CCC 8006402C 3400BF8F */  lw         $ra, 0x34($sp)
    /* CD0 80064030 3000BE8F */  lw         $fp, 0x30($sp)
    /* CD4 80064034 2C00B78F */  lw         $s7, 0x2C($sp)
    /* CD8 80064038 2800B68F */  lw         $s6, 0x28($sp)
    /* CDC 8006403C 2400B58F */  lw         $s5, 0x24($sp)
    /* CE0 80064040 2000B48F */  lw         $s4, 0x20($sp)
    /* CE4 80064044 1C00B38F */  lw         $s3, 0x1C($sp)
    /* CE8 80064048 1800B28F */  lw         $s2, 0x18($sp)
    /* CEC 8006404C 0680023C */  lui        $v0, %hi(D_8005F79C)
    /* CF0 80064050 9CF751AC */  sw         $s1, %lo(D_8005F79C)($v0)
    /* CF4 80064054 1400B18F */  lw         $s1, 0x14($sp)
    /* CF8 80064058 1000B08F */  lw         $s0, 0x10($sp)
    /* CFC 8006405C 0800E003 */  jr         $ra
    /* D00 80064060 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel Stg00_ScrollViewDraw
