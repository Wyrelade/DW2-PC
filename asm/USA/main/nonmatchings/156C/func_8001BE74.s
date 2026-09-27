nonmatching func_8001BE74, 0x74

glabel func_8001BE74
    /* C674 8001BE74 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* C678 8001BE78 1000B0AF */  sw         $s0, 0x10($sp)
    /* C67C 8001BE7C 21808000 */  addu       $s0, $a0, $zero
    /* C680 8001BE80 1400B1AF */  sw         $s1, 0x14($sp)
    /* C684 8001BE84 2188A000 */  addu       $s1, $a1, $zero
    /* C688 8001BE88 09000424 */  addiu      $a0, $zero, 0x9
    /* C68C 8001BE8C FFFF0524 */  addiu      $a1, $zero, -0x1
    /* C690 8001BE90 1800BFAF */  sw         $ra, 0x18($sp)
    /* C694 8001BE94 4445000C */  jal        Task_FindFirst
    /* C698 8001BE98 2130A000 */   addu      $a2, $a1, $zero
    /* C69C 8001BE9C 21184000 */  addu       $v1, $v0, $zero
    /* C6A0 8001BEA0 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* C6A4 8001BEA4 0B000212 */  beq        $s0, $v0, .L8001BED4
    /* C6A8 8001BEA8 00000000 */   nop
    /* C6AC 8001BEAC 09006010 */  beqz       $v1, .L8001BED4
    /* C6B0 8001BEB0 40101000 */   sll       $v0, $s0, 1
    /* C6B4 8001BEB4 21105000 */  addu       $v0, $v0, $s0
    /* C6B8 8001BEB8 80100200 */  sll        $v0, $v0, 2
    /* C6BC 8001BEBC 21105000 */  addu       $v0, $v0, $s0
    /* C6C0 8001BEC0 2C00638C */  lw         $v1, 0x2C($v1)
    /* C6C4 8001BEC4 80100200 */  sll        $v0, $v0, 2
    /* C6C8 8001BEC8 21186200 */  addu       $v1, $v1, $v0
    /* C6CC 8001BECC 200071A0 */  sb         $s1, 0x20($v1)
    /* C6D0 8001BED0 020071A0 */  sb         $s1, 0x2($v1)
  .L8001BED4:
    /* C6D4 8001BED4 1800BF8F */  lw         $ra, 0x18($sp)
    /* C6D8 8001BED8 1400B18F */  lw         $s1, 0x14($sp)
    /* C6DC 8001BEDC 1000B08F */  lw         $s0, 0x10($sp)
    /* C6E0 8001BEE0 0800E003 */  jr         $ra
    /* C6E4 8001BEE4 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8001BE74
