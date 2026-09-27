nonmatching Snd_PlayById, 0xD0

glabel Snd_PlayById
    /* AE8C 8001A68C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* AE90 8001A690 1800B2AF */  sw         $s2, 0x18($sp)
    /* AE94 8001A694 21908000 */  addu       $s2, $a0, $zero
    /* AE98 8001A698 2000848F */  lw         $a0, %gp_rel(D_80050718)($gp)
    /* AE9C 8001A69C 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* AEA0 8001A6A0 2198A000 */  addu       $s3, $a1, $zero
    /* AEA4 8001A6A4 2000BFAF */  sw         $ra, 0x20($sp)
    /* AEA8 8001A6A8 1400B1AF */  sw         $s1, 0x14($sp)
    /* AEAC 8001A6AC 24009210 */  beq        $a0, $s2, .L8001A740
    /* AEB0 8001A6B0 1000B0AF */   sw        $s0, 0x10($sp)
    /* AEB4 8001A6B4 05006012 */  beqz       $s3, .L8001A6CC
    /* AEB8 8001A6B8 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* AEBC 8001A6BC 04008210 */  beq        $a0, $v0, .L8001A6D0
    /* AEC0 8001A6C0 031A1200 */   sra       $v1, $s2, 8
    /* AEC4 8001A6C4 0469000C */  jal        Snd_StopById
    /* AEC8 8001A6C8 00000000 */   nop
  .L8001A6CC:
    /* AECC 8001A6CC 031A1200 */  sra        $v1, $s2, 8
  .L8001A6D0:
    /* AED0 8001A6D0 C3801200 */  sra        $s0, $s2, 3
    /* AED4 8001A6D4 0580043C */  lui        $a0, %hi(D_80054C48)
    /* AED8 8001A6D8 484C8424 */  addiu      $a0, $a0, %lo(D_80054C48)
    /* AEDC 8001A6DC 1E001032 */  andi       $s0, $s0, 0x1E
    /* AEE0 8001A6E0 40100300 */  sll        $v0, $v1, 1
    /* AEE4 8001A6E4 21104300 */  addu       $v0, $v0, $v1
    /* AEE8 8001A6E8 80100200 */  sll        $v0, $v0, 2
    /* AEEC 8001A6EC 23104300 */  subu       $v0, $v0, $v1
    /* AEF0 8001A6F0 80100200 */  sll        $v0, $v0, 2
    /* AEF4 8001A6F4 21800202 */  addu       $s0, $s0, $v0
    /* AEF8 8001A6F8 21800402 */  addu       $s0, $s0, $a0
    /* AEFC 8001A6FC 0F005132 */  andi       $s1, $s2, 0xF
    /* AF00 8001A700 0C000486 */  lh         $a0, 0xC($s0)
    /* AF04 8001A704 A7D5000C */  jal        SsSepStop
    /* AF08 8001A708 21282002 */   addu      $a1, $s1, $zero
    /* AF0C 8001A70C 21282002 */  addu       $a1, $s1, $zero
    /* AF10 8001A710 7F000624 */  addiu      $a2, $zero, 0x7F
    /* AF14 8001A714 0C000486 */  lh         $a0, 0xC($s0)
    /* AF18 8001A718 13D7000C */  jal        func_80035C4C
    /* AF1C 8001A71C 2138C000 */   addu      $a3, $a2, $zero
    /* AF20 8001A720 21282002 */  addu       $a1, $s1, $zero
    /* AF24 8001A724 01000624 */  addiu      $a2, $zero, 0x1
    /* AF28 8001A728 0C000486 */  lh         $a0, 0xC($s0)
    /* AF2C 8001A72C 81D3000C */  jal        func_80034E04
    /* AF30 8001A730 2138C000 */   addu      $a3, $a2, $zero
    /* AF34 8001A734 02006012 */  beqz       $s3, .L8001A740
    /* AF38 8001A738 00000000 */   nop
    /* AF3C 8001A73C 200092AF */  sw         $s2, %gp_rel(D_80050718)($gp)
  .L8001A740:
    /* AF40 8001A740 2000BF8F */  lw         $ra, 0x20($sp)
    /* AF44 8001A744 1C00B38F */  lw         $s3, 0x1C($sp)
    /* AF48 8001A748 1800B28F */  lw         $s2, 0x18($sp)
    /* AF4C 8001A74C 1400B18F */  lw         $s1, 0x14($sp)
    /* AF50 8001A750 1000B08F */  lw         $s0, 0x10($sp)
    /* AF54 8001A754 0800E003 */  jr         $ra
    /* AF58 8001A758 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel Snd_PlayById
