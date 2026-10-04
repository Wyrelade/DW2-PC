nonmatching Stg40_ApplyTrapCells, 0xA0

glabel Stg40_ApplyTrapCells
    /* D67C 800709DC 0580043C */  lui        $a0, %hi(D_8005071C)
    /* D680 800709E0 1C07838C */  lw         $v1, %lo(D_8005071C)($a0)
    /* D684 800709E4 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* D688 800709E8 1400B1AF */  sw         $s1, 0x14($sp)
    /* D68C 800709EC 21880000 */  addu       $s1, $zero, $zero
    /* D690 800709F0 2000BFAF */  sw         $ra, 0x20($sp)
    /* D694 800709F4 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* D698 800709F8 1800B2AF */  sw         $s2, 0x18($sp)
    /* D69C 800709FC 1000B0AF */  sw         $s0, 0x10($sp)
    /* D6A0 80070A00 14006284 */  lh         $v0, 0x14($v1)
    /* D6A4 80070A04 00000000 */  nop
    /* D6A8 80070A08 15004018 */  blez       $v0, .L80070A60
    /* D6AC 80070A0C 080D7224 */   addiu     $s2, $v1, 0xD08
    /* D6B0 80070A10 21988000 */  addu       $s3, $a0, $zero
    /* D6B4 80070A14 0A0D7024 */  addiu      $s0, $v1, 0xD0A
  .L80070A18:
    /* D6B8 80070A18 00004492 */  lbu        $a0, 0x0($s2)
    /* D6BC 80070A1C FFFF0592 */  lbu        $a1, -0x1($s0)
    /* D6C0 80070A20 29C2010C */  jal        Stg40_GetCell2
    /* D6C4 80070A24 03005226 */   addiu     $s2, $s2, 0x3
    /* D6C8 80070A28 00004494 */  lhu        $a0, 0x0($v0)
    /* D6CC 80070A2C 01003126 */  addiu      $s1, $s1, 0x1
    /* D6D0 80070A30 F0FF8430 */  andi       $a0, $a0, 0xFFF0
    /* D6D4 80070A34 000044A4 */  sh         $a0, 0x0($v0)
    /* D6D8 80070A38 00000392 */  lbu        $v1, 0x0($s0)
    /* D6DC 80070A3C 1C07658E */  lw         $a1, %lo(D_8005071C)($s3)
    /* D6E0 80070A40 07006324 */  addiu      $v1, $v1, 0x7
    /* D6E4 80070A44 25208300 */  or         $a0, $a0, $v1
    /* D6E8 80070A48 000044A4 */  sh         $a0, 0x0($v0)
    /* D6EC 80070A4C 1400A284 */  lh         $v0, 0x14($a1)
    /* D6F0 80070A50 00000000 */  nop
    /* D6F4 80070A54 2A102202 */  slt        $v0, $s1, $v0
    /* D6F8 80070A58 EFFF4014 */  bnez       $v0, .L80070A18
    /* D6FC 80070A5C 03001026 */   addiu     $s0, $s0, 0x3
  .L80070A60:
    /* D700 80070A60 2000BF8F */  lw         $ra, 0x20($sp)
    /* D704 80070A64 1C00B38F */  lw         $s3, 0x1C($sp)
    /* D708 80070A68 1800B28F */  lw         $s2, 0x18($sp)
    /* D70C 80070A6C 1400B18F */  lw         $s1, 0x14($sp)
    /* D710 80070A70 1000B08F */  lw         $s0, 0x10($sp)
    /* D714 80070A74 0800E003 */  jr         $ra
    /* D718 80070A78 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel Stg40_ApplyTrapCells
