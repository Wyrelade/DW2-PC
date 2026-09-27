nonmatching func_800721A8, 0xA8

glabel func_800721A8
    /* EE48 800721A8 0780023C */  lui        $v0, %hi(D_80072BC0)
    /* EE4C 800721AC C02B428C */  lw         $v0, %lo(D_80072BC0)($v0)
    /* EE50 800721B0 00000000 */  nop
    /* EE54 800721B4 2C00468C */  lw         $a2, 0x2C($v0)
    /* EE58 800721B8 00000000 */  nop
    /* EE5C 800721BC BC00C224 */  addiu      $v0, $a2, 0xBC
    /* EE60 800721C0 B400C2AC */  sw         $v0, 0xB4($a2)
    /* EE64 800721C4 B800C0AC */  sw         $zero, 0xB8($a2)
    /* EE68 800721C8 0000828C */  lw         $v0, 0x0($a0)
    /* EE6C 800721CC 00000000 */  nop
    /* EE70 800721D0 1D004010 */  beqz       $v0, .L80072248
    /* EE74 800721D4 2138C000 */   addu      $a3, $a2, $zero
  .L800721D8:
    /* EE78 800721D8 BC00E324 */  addiu      $v1, $a3, 0xBC
    /* EE7C 800721DC 21108000 */  addu       $v0, $a0, $zero
    /* EE80 800721E0 20008524 */  addiu      $a1, $a0, 0x20
  .L800721E4:
    /* EE84 800721E4 0000488C */  lw         $t0, 0x0($v0)
    /* EE88 800721E8 0400498C */  lw         $t1, 0x4($v0)
    /* EE8C 800721EC 08004A8C */  lw         $t2, 0x8($v0)
    /* EE90 800721F0 0C004B8C */  lw         $t3, 0xC($v0)
    /* EE94 800721F4 000068AC */  sw         $t0, 0x0($v1)
    /* EE98 800721F8 040069AC */  sw         $t1, 0x4($v1)
    /* EE9C 800721FC 08006AAC */  sw         $t2, 0x8($v1)
    /* EEA0 80072200 0C006BAC */  sw         $t3, 0xC($v1)
    /* EEA4 80072204 10004224 */  addiu      $v0, $v0, 0x10
    /* EEA8 80072208 F6FF4514 */  bne        $v0, $a1, .L800721E4
    /* EEAC 8007220C 10006324 */   addiu     $v1, $v1, 0x10
    /* EEB0 80072210 0000488C */  lw         $t0, 0x0($v0)
    /* EEB4 80072214 0400498C */  lw         $t1, 0x4($v0)
    /* EEB8 80072218 08004A8C */  lw         $t2, 0x8($v0)
    /* EEBC 8007221C 000068AC */  sw         $t0, 0x0($v1)
    /* EEC0 80072220 040069AC */  sw         $t1, 0x4($v1)
    /* EEC4 80072224 08006AAC */  sw         $t2, 0x8($v1)
    /* EEC8 80072228 B800C28C */  lw         $v0, 0xB8($a2)
    /* EECC 8007222C 2C008424 */  addiu      $a0, $a0, 0x2C
    /* EED0 80072230 01004224 */  addiu      $v0, $v0, 0x1
    /* EED4 80072234 B800C2AC */  sw         $v0, 0xB8($a2)
    /* EED8 80072238 0000828C */  lw         $v0, 0x0($a0)
    /* EEDC 8007223C 00000000 */  nop
    /* EEE0 80072240 E5FF4014 */  bnez       $v0, .L800721D8
    /* EEE4 80072244 2C00E724 */   addiu     $a3, $a3, 0x2C
  .L80072248:
    /* EEE8 80072248 0800E003 */  jr         $ra
    /* EEEC 8007224C 00000000 */   nop
endlabel func_800721A8
