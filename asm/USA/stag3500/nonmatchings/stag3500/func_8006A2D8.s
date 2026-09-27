nonmatching func_8006A2D8, 0xE0

glabel func_8006A2D8
    /* 6F78 8006A2D8 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 6F7C 8006A2DC 2400B3AF */  sw         $s3, 0x24($sp)
    /* 6F80 8006A2E0 21988000 */  addu       $s3, $a0, $zero
    /* 6F84 8006A2E4 01000224 */  addiu      $v0, $zero, 0x1
    /* 6F88 8006A2E8 2800BFAF */  sw         $ra, 0x28($sp)
    /* 6F8C 8006A2EC 2000B2AF */  sw         $s2, 0x20($sp)
    /* 6F90 8006A2F0 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 6F94 8006A2F4 1800B0AF */  sw         $s0, 0x18($sp)
    /* 6F98 8006A2F8 1000638E */  lw         $v1, 0x10($s3)
    /* 6F9C 8006A2FC 2C00728E */  lw         $s2, 0x2C($s3)
    /* 6FA0 8006A300 1D006210 */  beq        $v1, $v0, .L8006A378
    /* 6FA4 8006A304 02006228 */   slti      $v0, $v1, 0x2
    /* 6FA8 8006A308 24004010 */  beqz       $v0, .L8006A39C
    /* 6FAC 8006A30C 00000000 */   nop
    /* 6FB0 8006A310 22006014 */  bnez       $v1, .L8006A39C
    /* 6FB4 8006A314 21880000 */   addu      $s1, $zero, $zero
    /* 6FB8 8006A318 21804002 */  addu       $s0, $s2, $zero
  .L8006A31C:
    /* 6FBC 8006A31C 4898010C */  jal        func_80066120
    /* 6FC0 8006A320 21200002 */   addu      $a0, $s0, $zero
    /* 6FC4 8006A324 01003126 */  addiu      $s1, $s1, 0x1
    /* 6FC8 8006A328 FCFF201A */  blez       $s1, .L8006A31C
    /* 6FCC 8006A32C 04001026 */   addiu     $s0, $s0, 0x4
    /* 6FD0 8006A330 21204002 */  addu       $a0, $s2, $zero
    /* 6FD4 8006A334 3F0D053C */  lui        $a1, (0xD3F0008 >> 16)
    /* 6FD8 8006A338 6998010C */  jal        func_800661A4
    /* 6FDC 8006A33C 0800A534 */   ori       $a1, $a1, (0xD3F0008 & 0xFFFF)
    /* 6FE0 8006A340 02000224 */  addiu      $v0, $zero, 0x2
    /* 6FE4 8006A344 1000A2AF */  sw         $v0, 0x10($sp)
    /* 6FE8 8006A348 04000224 */  addiu      $v0, $zero, 0x4
    /* 6FEC 8006A34C 1400A2AF */  sw         $v0, 0x14($sp)
    /* 6FF0 8006A350 0800628E */  lw         $v0, 0x8($s3)
    /* 6FF4 8006A354 00000000 */  nop
    /* 6FF8 8006A358 80100200 */  sll        $v0, $v0, 2
    /* 6FFC 8006A35C 2110A203 */  addu       $v0, $sp, $v0
    /* 7000 8006A360 1000458C */  lw         $a1, 0x10($v0)
    /* 7004 8006A364 21204002 */  addu       $a0, $s2, $zero
    /* 7008 8006A368 F398010C */  jal        func_800663CC
    /* 700C 8006A36C 27280500 */   nor       $a1, $zero, $a1
    /* 7010 8006A370 5145000C */  jal        Task_NextState0
    /* 7014 8006A374 21206002 */   addu      $a0, $s3, $zero
  .L8006A378:
    /* 7018 8006A378 2800648E */  lw         $a0, 0x28($s3)
    /* 701C 8006A37C 04000524 */  addiu      $a1, $zero, 0x4
    /* 7020 8006A380 21300000 */  addu       $a2, $zero, $zero
    /* 7024 8006A384 0C89000C */  jal        Math_PingPongRange
    /* 7028 8006A388 07000724 */   addiu     $a3, $zero, 0x7
    /* 702C 8006A38C 21204002 */  addu       $a0, $s2, $zero
    /* 7030 8006A390 06000524 */  addiu      $a1, $zero, 0x6
    /* 7034 8006A394 4899010C */  jal        func_80066520
    /* 7038 8006A398 21304000 */   addu      $a2, $v0, $zero
  .L8006A39C:
    /* 703C 8006A39C 2800BF8F */  lw         $ra, 0x28($sp)
    /* 7040 8006A3A0 2400B38F */  lw         $s3, 0x24($sp)
    /* 7044 8006A3A4 2000B28F */  lw         $s2, 0x20($sp)
    /* 7048 8006A3A8 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 704C 8006A3AC 1800B08F */  lw         $s0, 0x18($sp)
    /* 7050 8006A3B0 0800E003 */  jr         $ra
    /* 7054 8006A3B4 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_8006A2D8
