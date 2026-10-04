nonmatching func_80063E38, 0x1D0

glabel func_80063E38
    /* AD8 80063E38 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* ADC 80063E3C 2000B4AF */  sw         $s4, 0x20($sp)
    /* AE0 80063E40 21A00000 */  addu       $s4, $zero, $zero
    /* AE4 80063E44 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* AE8 80063E48 FF00133C */  lui        $s3, (0xFFFFFF >> 16)
    /* AEC 80063E4C FFFF7336 */  ori        $s3, $s3, (0xFFFFFF & 0xFFFF)
    /* AF0 80063E50 2400B5AF */  sw         $s5, 0x24($sp)
    /* AF4 80063E54 00FF153C */  lui        $s5, (0xFF000000 >> 16)
    /* AF8 80063E58 2C00B7AF */  sw         $s7, 0x2C($sp)
    /* AFC 80063E5C 60FF173C */  lui        $s7, (0xFF600000 >> 16)
    /* B00 80063E60 2800B6AF */  sw         $s6, 0x28($sp)
    /* B04 80063E64 60FF1624 */  addiu      $s6, $zero, -0xA0
    /* B08 80063E68 0680023C */  lui        $v0, %hi(Sys_State)
    /* B0C 80063E6C 70F74224 */  addiu      $v0, $v0, %lo(Sys_State)
    /* B10 80063E70 3400BFAF */  sw         $ra, 0x34($sp)
    /* B14 80063E74 3000BEAF */  sw         $fp, 0x30($sp)
    /* B18 80063E78 1800B2AF */  sw         $s2, 0x18($sp)
    /* B1C 80063E7C 1400B1AF */  sw         $s1, 0x14($sp)
    /* B20 80063E80 1000B0AF */  sw         $s0, 0x10($sp)
    /* B24 80063E84 2C009E8C */  lw         $fp, 0x2C($a0)
    /* B28 80063E88 2C00518C */  lw         $s1, 0x2C($v0)
    /* B2C 80063E8C 5001528C */  lw         $s2, 0x150($v0)
    /* B30 80063E90 04003026 */  addiu      $s0, $s1, 0x4
  .L80063E94:
    /* B34 80063E94 80101400 */  sll        $v0, $s4, 2
    /* B38 80063E98 2110C203 */  addu       $v0, $fp, $v0
    /* B3C 80063E9C 0400448C */  lw         $a0, 0x4($v0)
    /* B40 80063EA0 00000000 */  nop
    /* B44 80063EA4 45008010 */  beqz       $a0, .L80063FBC
    /* B48 80063EA8 4000023C */   lui       $v0, (0x400000 >> 16)
    /* B4C 80063EAC E072000C */  jal        Gfx_FindOrLoadTexSlot
    /* B50 80063EB0 00000000 */   nop
    /* B54 80063EB4 0580033C */  lui        $v1, %hi(Gfx_NeutralRgb)
    /* B58 80063EB8 4C076924 */  addiu      $t1, $v1, %lo(Gfx_NeutralRgb)
    /* B5C 80063EBC 03002689 */  lwl        $a2, 0x3($t1)
    /* B60 80063EC0 00002699 */  lwr        $a2, 0x0($t1)
    /* B64 80063EC4 00000000 */  nop
    /* B68 80063EC8 030006AA */  swl        $a2, 0x3($s0)
    /* B6C 80063ECC 000006BA */  swr        $a2, 0x0($s0)
    /* B70 80063ED0 04000324 */  addiu      $v1, $zero, 0x4
    /* B74 80063ED4 FFFF03A2 */  sb         $v1, -0x1($s0)
    /* B78 80063ED8 64000324 */  addiu      $v1, $zero, 0x64
    /* B7C 80063EDC 21284000 */  addu       $a1, $v0, $zero
    /* B80 80063EE0 030003A2 */  sb         $v1, 0x3($s0)
    /* B84 80063EE4 031C1700 */  sra        $v1, $s7, 16
    /* B88 80063EE8 20FF6228 */  slti       $v0, $v1, -0xE0
    /* B8C 80063EEC 32004014 */  bnez       $v0, .L80063FB8
    /* B90 80063EF0 040016A6 */   sh        $s6, 0x4($s0)
    /* B94 80063EF4 A1006228 */  slti       $v0, $v1, 0xA1
    /* B98 80063EF8 2F004010 */  beqz       $v0, .L80063FB8
    /* B9C 80063EFC 00E1043C */   lui       $a0, (0xE1000600 >> 16)
    /* BA0 80063F00 0C00A390 */  lbu        $v1, 0xC($a1)
    /* BA4 80063F04 40000224 */  addiu      $v0, $zero, 0x40
    /* BA8 80063F08 0C0002A6 */  sh         $v0, 0xC($s0)
    /* BAC 80063F0C 80FF0224 */  addiu      $v0, $zero, -0x80
    /* BB0 80063F10 060002A6 */  sh         $v0, 0x6($s0)
    /* BB4 80063F14 FF000224 */  addiu      $v0, $zero, 0xFF
    /* BB8 80063F18 090000A2 */  sb         $zero, 0x9($s0)
    /* BBC 80063F1C 0E0002A6 */  sh         $v0, 0xE($s0)
    /* BC0 80063F20 080003A2 */  sb         $v1, 0x8($s0)
    /* BC4 80063F24 1400A294 */  lhu        $v0, 0x14($a1)
    /* BC8 80063F28 00068434 */  ori        $a0, $a0, (0xE1000600 & 0xFFFF)
    /* BCC 80063F2C E0014224 */  addiu      $v0, $v0, 0x1E0
    /* BD0 80063F30 80110200 */  sll        $v0, $v0, 6
    /* BD4 80063F34 0A0002A6 */  sh         $v0, 0xA($s0)
    /* BD8 80063F38 14001026 */  addiu      $s0, $s0, 0x14
    /* BDC 80063F3C 0000228E */  lw         $v0, 0x0($s1)
    /* BE0 80063F40 0000438E */  lw         $v1, 0x0($s2)
    /* BE4 80063F44 24105500 */  and        $v0, $v0, $s5
    /* BE8 80063F48 24187300 */  and        $v1, $v1, $s3
    /* BEC 80063F4C 25104300 */  or         $v0, $v0, $v1
    /* BF0 80063F50 000022AE */  sw         $v0, 0x0($s1)
    /* BF4 80063F54 0000428E */  lw         $v0, 0x0($s2)
    /* BF8 80063F58 24183302 */  and        $v1, $s1, $s3
    /* BFC 80063F5C 24105500 */  and        $v0, $v0, $s5
    /* C00 80063F60 25104300 */  or         $v0, $v0, $v1
    /* C04 80063F64 000042AE */  sw         $v0, 0x0($s2)
    /* C08 80063F68 01000224 */  addiu      $v0, $zero, 0x1
    /* C0C 80063F6C FFFF02A2 */  sb         $v0, -0x1($s0)
    /* C10 80063F70 1000A294 */  lhu        $v0, 0x10($a1)
    /* C14 80063F74 14003126 */  addiu      $s1, $s1, 0x14
    /* C18 80063F78 FF094230 */  andi       $v0, $v0, 0x9FF
    /* C1C 80063F7C 25104400 */  or         $v0, $v0, $a0
    /* C20 80063F80 000002AE */  sw         $v0, 0x0($s0)
    /* C24 80063F84 08001026 */  addiu      $s0, $s0, 0x8
    /* C28 80063F88 0000228E */  lw         $v0, 0x0($s1)
    /* C2C 80063F8C 0000438E */  lw         $v1, 0x0($s2)
    /* C30 80063F90 24105500 */  and        $v0, $v0, $s5
    /* C34 80063F94 24187300 */  and        $v1, $v1, $s3
    /* C38 80063F98 25104300 */  or         $v0, $v0, $v1
    /* C3C 80063F9C 24183302 */  and        $v1, $s1, $s3
    /* C40 80063FA0 000022AE */  sw         $v0, 0x0($s1)
    /* C44 80063FA4 0000428E */  lw         $v0, 0x0($s2)
    /* C48 80063FA8 08003126 */  addiu      $s1, $s1, 0x8
    /* C4C 80063FAC 24105500 */  and        $v0, $v0, $s5
    /* C50 80063FB0 25104300 */  or         $v0, $v0, $v1
    /* C54 80063FB4 000042AE */  sw         $v0, 0x0($s2)
  .L80063FB8:
    /* C58 80063FB8 4000023C */  lui        $v0, (0x400000 >> 16)
  .L80063FBC:
    /* C5C 80063FBC 21B8E202 */  addu       $s7, $s7, $v0
    /* C60 80063FC0 01009426 */  addiu      $s4, $s4, 0x1
    /* C64 80063FC4 0A00822A */  slti       $v0, $s4, 0xA
    /* C68 80063FC8 B2FF4014 */  bnez       $v0, .L80063E94
    /* C6C 80063FCC 4000D626 */   addiu     $s6, $s6, 0x40
    /* C70 80063FD0 3400BF8F */  lw         $ra, 0x34($sp)
    /* C74 80063FD4 3000BE8F */  lw         $fp, 0x30($sp)
    /* C78 80063FD8 2C00B78F */  lw         $s7, 0x2C($sp)
    /* C7C 80063FDC 2800B68F */  lw         $s6, 0x28($sp)
    /* C80 80063FE0 2400B58F */  lw         $s5, 0x24($sp)
    /* C84 80063FE4 2000B48F */  lw         $s4, 0x20($sp)
    /* C88 80063FE8 1C00B38F */  lw         $s3, 0x1C($sp)
    /* C8C 80063FEC 1800B28F */  lw         $s2, 0x18($sp)
    /* C90 80063FF0 0680023C */  lui        $v0, %hi(Sys_PacketCursor)
    /* C94 80063FF4 9CF751AC */  sw         $s1, %lo(Sys_PacketCursor)($v0)
    /* C98 80063FF8 1400B18F */  lw         $s1, 0x14($sp)
    /* C9C 80063FFC 1000B08F */  lw         $s0, 0x10($sp)
    /* CA0 80064000 0800E003 */  jr         $ra
    /* CA4 80064004 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_80063E38
