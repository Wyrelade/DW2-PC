nonmatching func_8006D350, 0x7C

glabel func_8006D350
    /* 9FF0 8006D350 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 9FF4 8006D354 1000BFAF */  sw         $ra, 0x10($sp)
    /* 9FF8 8006D358 2C00838C */  lw         $v1, 0x2C($a0)
    /* 9FFC 8006D35C 2F000424 */  addiu      $a0, $zero, 0x2F
    /* A000 8006D360 0680023C */  lui        $v0, %hi(D_8005E620)
    /* A004 8006D364 20E64224 */  addiu      $v0, $v0, %lo(D_8005E620)
    /* A008 8006D368 5E004224 */  addiu      $v0, $v0, 0x5E
  .L8006D36C:
    /* A00C 8006D36C 660040A4 */  sh         $zero, 0x66($v0)
    /* A010 8006D370 FFFF8424 */  addiu      $a0, $a0, -0x1
    /* A014 8006D374 FDFF8104 */  bgez       $a0, .L8006D36C
    /* A018 8006D378 FEFF4224 */   addiu     $v0, $v0, -0x2
    /* A01C 8006D37C 21200000 */  addu       $a0, $zero, $zero
    /* A020 8006D380 21306000 */  addu       $a2, $v1, $zero
    /* A024 8006D384 0680023C */  lui        $v0, %hi(D_8005E620)
    /* A028 8006D388 20E64524 */  addiu      $a1, $v0, %lo(D_8005E620)
  .L8006D38C:
    /* A02C 8006D38C 6000C284 */  lh         $v0, 0x60($a2)
    /* A030 8006D390 6000C394 */  lhu        $v1, 0x60($a2)
    /* A034 8006D394 03004010 */  beqz       $v0, .L8006D3A4
    /* A038 8006D398 00000000 */   nop
    /* A03C 8006D39C 6600A3A4 */  sh         $v1, 0x66($a1)
    /* A040 8006D3A0 0200A524 */  addiu      $a1, $a1, 0x2
  .L8006D3A4:
    /* A044 8006D3A4 01008424 */  addiu      $a0, $a0, 0x1
    /* A048 8006D3A8 43008228 */  slti       $v0, $a0, 0x43
    /* A04C 8006D3AC F7FF4014 */  bnez       $v0, .L8006D38C
    /* A050 8006D3B0 0200C624 */   addiu     $a2, $a2, 0x2
    /* A054 8006D3B4 AB89000C */  jal        Item_SortList
    /* A058 8006D3B8 00000000 */   nop
    /* A05C 8006D3BC 1000BF8F */  lw         $ra, 0x10($sp)
    /* A060 8006D3C0 00000000 */  nop
    /* A064 8006D3C4 0800E003 */  jr         $ra
    /* A068 8006D3C8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006D350
