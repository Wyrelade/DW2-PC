nonmatching Task_Alloc, 0x88

glabel Task_Alloc
    /* 19D4 800111D4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 19D8 800111D8 40000424 */  addiu      $a0, $zero, 0x40
    /* 19DC 800111DC 02000524 */  addiu      $a1, $zero, 0x2
    /* 19E0 800111E0 1400BFAF */  sw         $ra, 0x14($sp)
    /* 19E4 800111E4 CF8B000C */  jal        Mem_Alloc
    /* 19E8 800111E8 1000B0AF */   sw        $s0, 0x10($sp)
    /* 19EC 800111EC 21804000 */  addu       $s0, $v0, $zero
    /* 19F0 800111F0 21200002 */  addu       $a0, $s0, $zero
    /* 19F4 800111F4 E38B000C */  jal        Mem_Zero
    /* 19F8 800111F8 40000524 */   addiu     $a1, $zero, 0x40
    /* 19FC 800111FC 21200000 */  addu       $a0, $zero, $zero
    /* 1A00 80011200 0580023C */  lui        $v0, %hi(Task_List)
    /* 1A04 80011204 98074324 */  addiu      $v1, $v0, %lo(Task_List)
  .L80011208:
    /* 1A08 80011208 0400628C */  lw         $v0, 0x4($v1)
    /* 1A0C 8001120C 00000000 */  nop
    /* 1A10 80011210 03004014 */  bnez       $v0, .L80011220
    /* 1A14 80011214 00000000 */   nop
    /* 1A18 80011218 8C440008 */  j          .L80011230
    /* 1A1C 8001121C 040070AC */   sw        $s0, 0x4($v1)
  .L80011220:
    /* 1A20 80011220 01008424 */  addiu      $a0, $a0, 0x1
    /* 1A24 80011224 64008228 */  slti       $v0, $a0, 0x64
    /* 1A28 80011228 F7FF4014 */  bnez       $v0, .L80011208
    /* 1A2C 8001122C 04006324 */   addiu     $v1, $v1, 0x4
  .L80011230:
    /* 1A30 80011230 0580053C */  lui        $a1, %hi(Task_List)
    /* 1A34 80011234 9807A28C */  lw         $v0, %lo(Task_List)($a1)
    /* 1A38 80011238 01008324 */  addiu      $v1, $a0, 0x1
    /* 1A3C 8001123C 2A104300 */  slt        $v0, $v0, $v1
    /* 1A40 80011240 02004010 */  beqz       $v0, .L8001124C
    /* 1A44 80011244 21100002 */   addu      $v0, $s0, $zero
    /* 1A48 80011248 9807A3AC */  sw         $v1, %lo(Task_List)($a1)
  .L8001124C:
    /* 1A4C 8001124C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1A50 80011250 1000B08F */  lw         $s0, 0x10($sp)
    /* 1A54 80011254 0800E003 */  jr         $ra
    /* 1A58 80011258 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Task_Alloc
