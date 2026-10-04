nonmatching Stg40_TurnQueueRemove, 0xA4

glabel Stg40_TurnQueueRemove
    /* D844 80070BA4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* D848 80070BA8 0580023C */  lui        $v0, %hi(Dung_StatePtr)
    /* D84C 80070BAC 00240400 */  sll        $a0, $a0, 16
    /* D850 80070BB0 1C07428C */  lw         $v0, %lo(Dung_StatePtr)($v0)
    /* D854 80070BB4 03240400 */  sra        $a0, $a0, 16
    /* D858 80070BB8 1400BFAF */  sw         $ra, 0x14($sp)
    /* D85C 80070BBC 1000B0AF */  sw         $s0, 0x10($sp)
    /* D860 80070BC0 B4C2010C */  jal        Stg40_TurnQueueFind
    /* D864 80070BC4 FC0F5024 */   addiu     $s0, $v0, 0xFFC
    /* D868 80070BC8 21284000 */  addu       $a1, $v0, $zero
    /* D86C 80070BCC 1A00A010 */  beqz       $a1, .L80070C38
    /* D870 80070BD0 FEFF0224 */   addiu     $v0, $zero, -0x2
    /* D874 80070BD4 0200A384 */  lh         $v1, 0x2($a1)
    /* D878 80070BD8 00000000 */  nop
    /* D87C 80070BDC 09006210 */  beq        $v1, $v0, .L80070C04
    /* D880 80070BE0 0200A424 */   addiu     $a0, $a1, 0x2
    /* D884 80070BE4 21184000 */  addu       $v1, $v0, $zero
  .L80070BE8:
    /* D888 80070BE8 00008294 */  lhu        $v0, 0x0($a0)
    /* D88C 80070BEC 02008424 */  addiu      $a0, $a0, 0x2
    /* D890 80070BF0 0000A2A4 */  sh         $v0, 0x0($a1)
    /* D894 80070BF4 00008284 */  lh         $v0, 0x0($a0)
    /* D898 80070BF8 00000000 */  nop
    /* D89C 80070BFC FAFF4314 */  bne        $v0, $v1, .L80070BE8
    /* D8A0 80070C00 0200A524 */   addiu     $a1, $a1, 0x2
  .L80070C04:
    /* D8A4 80070C04 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* D8A8 80070C08 0000A2A4 */  sh         $v0, 0x0($a1)
    /* D8AC 80070C0C 16000296 */  lhu        $v0, 0x16($s0)
    /* D8B0 80070C10 1A000386 */  lh         $v1, 0x1A($s0)
    /* D8B4 80070C14 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* D8B8 80070C18 40180300 */  sll        $v1, $v1, 1
    /* D8BC 80070C1C 21180302 */  addu       $v1, $s0, $v1
    /* D8C0 80070C20 160002A6 */  sh         $v0, 0x16($s0)
    /* D8C4 80070C24 00006384 */  lh         $v1, 0x0($v1)
    /* D8C8 80070C28 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* D8CC 80070C2C 02006214 */  bne        $v1, $v0, .L80070C38
    /* D8D0 80070C30 00000000 */   nop
    /* D8D4 80070C34 1A0000A6 */  sh         $zero, 0x1A($s0)
  .L80070C38:
    /* D8D8 80070C38 1400BF8F */  lw         $ra, 0x14($sp)
    /* D8DC 80070C3C 1000B08F */  lw         $s0, 0x10($sp)
    /* D8E0 80070C40 0800E003 */  jr         $ra
    /* D8E4 80070C44 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg40_TurnQueueRemove
