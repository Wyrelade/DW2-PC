nonmatching func_8006A000, 0x118

glabel func_8006A000
    /* 6CA0 8006A000 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 6CA4 8006A004 2800B4AF */  sw         $s4, 0x28($sp)
    /* 6CA8 8006A008 21A08000 */  addu       $s4, $a0, $zero
    /* 6CAC 8006A00C 01000224 */  addiu      $v0, $zero, 0x1
    /* 6CB0 8006A010 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 6CB4 8006A014 2400B3AF */  sw         $s3, 0x24($sp)
    /* 6CB8 8006A018 2000B2AF */  sw         $s2, 0x20($sp)
    /* 6CBC 8006A01C 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 6CC0 8006A020 1800B0AF */  sw         $s0, 0x18($sp)
    /* 6CC4 8006A024 1000838E */  lw         $v1, 0x10($s4)
    /* 6CC8 8006A028 2C00938E */  lw         $s3, 0x2C($s4)
    /* 6CCC 8006A02C 32006210 */  beq        $v1, $v0, .L8006A0F8
    /* 6CD0 8006A030 02006228 */   slti      $v0, $v1, 0x2
    /* 6CD4 8006A034 05004010 */  beqz       $v0, .L8006A04C
    /* 6CD8 8006A038 00000000 */   nop
    /* 6CDC 8006A03C 08006010 */  beqz       $v1, .L8006A060
    /* 6CE0 8006A040 21206002 */   addu      $a0, $s3, $zero
    /* 6CE4 8006A044 3EA80108 */  j          .L8006A0F8
    /* 6CE8 8006A048 00000000 */   nop
  .L8006A04C:
    /* 6CEC 8006A04C 02000224 */  addiu      $v0, $zero, 0x2
    /* 6CF0 8006A050 25006210 */  beq        $v1, $v0, .L8006A0E8
    /* 6CF4 8006A054 21206002 */   addu      $a0, $s3, $zero
    /* 6CF8 8006A058 3EA80108 */  j          .L8006A0F8
    /* 6CFC 8006A05C 00000000 */   nop
  .L8006A060:
    /* 6D00 8006A060 2270000C */  jal        Mem_FillWordsNeg1
    /* 6D04 8006A064 02000524 */   addiu     $a1, $zero, 0x2
    /* 6D08 8006A068 21206002 */  addu       $a0, $s3, $zero
    /* 6D0C 8006A06C 21300000 */  addu       $a2, $zero, $zero
    /* 6D10 8006A070 0780123C */  lui        $s2, %hi(D_800709B0)
    /* 6D14 8006A074 B0095226 */  addiu      $s2, $s2, %lo(D_800709B0)
    /* 6D18 8006A078 0780113C */  lui        $s1, %hi(D_8007010C)
    /* 6D1C 8006A07C 0C013126 */  addiu      $s1, $s1, %lo(D_8007010C)
    /* 6D20 8006A080 21382002 */  addu       $a3, $s1, $zero
    /* 6D24 8006A084 0680103C */  lui        $s0, %hi(Save_RosterNames)
    /* 6D28 8006A088 3400428E */  lw         $v0, 0x34($s2)
    /* 6D2C 8006A08C 50E71026 */  addiu      $s0, $s0, %lo(Save_RosterNames)
    /* 6D30 8006A090 1000A0AF */  sw         $zero, 0x10($sp)
    /* 6D34 8006A094 40280200 */  sll        $a1, $v0, 1
    /* 6D38 8006A098 2128A200 */  addu       $a1, $a1, $v0
    /* 6D3C 8006A09C C0280500 */  sll        $a1, $a1, 3
    /* 6D40 8006A0A0 2328A200 */  subu       $a1, $a1, $v0
    /* 6D44 8006A0A4 80280500 */  sll        $a1, $a1, 2
    /* 6D48 8006A0A8 209D010C */  jal        func_80067480
    /* 6D4C 8006A0AC 2128B000 */   addu      $a1, $a1, $s0
    /* 6D50 8006A0B0 04006426 */  addiu      $a0, $s3, 0x4
    /* 6D54 8006A0B4 21300000 */  addu       $a2, $zero, $zero
    /* 6D58 8006A0B8 3800428E */  lw         $v0, 0x38($s2)
    /* 6D5C 8006A0BC 04002726 */  addiu      $a3, $s1, 0x4
    /* 6D60 8006A0C0 1000A0AF */  sw         $zero, 0x10($sp)
    /* 6D64 8006A0C4 40280200 */  sll        $a1, $v0, 1
    /* 6D68 8006A0C8 2128A200 */  addu       $a1, $a1, $v0
    /* 6D6C 8006A0CC C0280500 */  sll        $a1, $a1, 3
    /* 6D70 8006A0D0 2328A200 */  subu       $a1, $a1, $v0
    /* 6D74 8006A0D4 80280500 */  sll        $a1, $a1, 2
    /* 6D78 8006A0D8 209D010C */  jal        func_80067480
    /* 6D7C 8006A0DC 2128B000 */   addu      $a1, $a1, $s0
    /* 6D80 8006A0E0 3CA80108 */  j          .L8006A0F0
    /* 6D84 8006A0E4 00000000 */   nop
  .L8006A0E8:
    /* 6D88 8006A0E8 2C70000C */  jal        Text_CloseArray
    /* 6D8C 8006A0EC 02000524 */   addiu     $a1, $zero, 0x2
  .L8006A0F0:
    /* 6D90 8006A0F0 5145000C */  jal        Task_NextState0
    /* 6D94 8006A0F4 21208002 */   addu      $a0, $s4, $zero
  .L8006A0F8:
    /* 6D98 8006A0F8 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 6D9C 8006A0FC 2800B48F */  lw         $s4, 0x28($sp)
    /* 6DA0 8006A100 2400B38F */  lw         $s3, 0x24($sp)
    /* 6DA4 8006A104 2000B28F */  lw         $s2, 0x20($sp)
    /* 6DA8 8006A108 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 6DAC 8006A10C 1800B08F */  lw         $s0, 0x18($sp)
    /* 6DB0 8006A110 0800E003 */  jr         $ra
    /* 6DB4 8006A114 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_8006A000
