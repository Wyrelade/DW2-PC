nonmatching Stg30_FightMsgDraw, 0xAC

glabel Stg30_FightMsgDraw
    /* C4C0 8006F820 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* C4C4 8006F824 1400B1AF */  sw         $s1, 0x14($sp)
    /* C4C8 8006F828 21888000 */  addu       $s1, $a0, $zero
    /* C4CC 8006F82C 0780023C */  lui        $v0, %hi(Stg30_FightMsgParts)
    /* C4D0 8006F830 1800BFAF */  sw         $ra, 0x18($sp)
    /* C4D4 8006F834 1000B0AF */  sw         $s0, 0x10($sp)
    /* C4D8 8006F838 0800238E */  lw         $v1, 0x8($s1)
    /* C4DC 8006F83C D0324224 */  addiu      $v0, $v0, %lo(Stg30_FightMsgParts)
    /* C4E0 8006F840 80180300 */  sll        $v1, $v1, 2
    /* C4E4 8006F844 21186200 */  addu       $v1, $v1, $v0
    /* C4E8 8006F848 0000648C */  lw         $a0, 0x0($v1)
    /* C4EC 8006F84C 2C00308E */  lw         $s0, 0x2C($s1)
    /* C4F0 8006F850 688E000C */  jal        Cd_GetFileEntry
    /* C4F4 8006F854 00000000 */   nop
    /* C4F8 8006F858 21204000 */  addu       $a0, $v0, $zero
    /* C4FC 8006F85C 0000828C */  lw         $v0, 0x0($a0)
    /* C500 8006F860 00000000 */  nop
    /* C504 8006F864 12004010 */  beqz       $v0, .L8006F8B0
    /* C508 8006F868 21308000 */   addu      $a2, $a0, $zero
    /* C50C 8006F86C 0C008524 */  addiu      $a1, $a0, 0xC
  .L8006F870:
    /* C510 8006F870 1000A28C */  lw         $v0, 0x10($a1)
    /* C514 8006F874 0400238E */  lw         $v1, 0x4($s1)
    /* C518 8006F878 0200A0A0 */  sb         $zero, 0x2($a1)
    /* C51C 8006F87C 26104300 */  xor        $v0, $v0, $v1
    /* C520 8006F880 0100422C */  sltiu      $v0, $v0, 0x1
    /* C524 8006F884 0300A2A0 */  sb         $v0, 0x3($a1)
    /* C528 8006F888 0000028E */  lw         $v0, 0x0($s0)
    /* C52C 8006F88C 00000000 */  nop
    /* C530 8006F890 0400A2AC */  sw         $v0, 0x4($a1)
    /* C534 8006F894 04000292 */  lbu        $v0, 0x4($s0)
    /* C538 8006F898 2800C624 */  addiu      $a2, $a2, 0x28
    /* C53C 8006F89C 0000A2A0 */  sb         $v0, 0x0($a1)
    /* C540 8006F8A0 0000C28C */  lw         $v0, 0x0($a2)
    /* C544 8006F8A4 00000000 */  nop
    /* C548 8006F8A8 F1FF4014 */  bnez       $v0, .L8006F870
    /* C54C 8006F8AC 2800A524 */   addiu     $a1, $a1, 0x28
  .L8006F8B0:
    /* C550 8006F8B0 2176000C */  jal        Gfx_DrawParts
    /* C554 8006F8B4 00000000 */   nop
    /* C558 8006F8B8 1800BF8F */  lw         $ra, 0x18($sp)
    /* C55C 8006F8BC 1400B18F */  lw         $s1, 0x14($sp)
    /* C560 8006F8C0 1000B08F */  lw         $s0, 0x10($sp)
    /* C564 8006F8C4 0800E003 */  jr         $ra
    /* C568 8006F8C8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg30_FightMsgDraw
