nonmatching func_8006DA18, 0x150

glabel func_8006DA18
    /* A6B8 8006DA18 0780023C */  lui        $v0, %hi(D_80072B60)
    /* A6BC 8006DA1C 602B428C */  lw         $v0, %lo(D_80072B60)($v0)
    /* A6C0 8006DA20 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* A6C4 8006DA24 2800BFAF */  sw         $ra, 0x28($sp)
    /* A6C8 8006DA28 2400B3AF */  sw         $s3, 0x24($sp)
    /* A6CC 8006DA2C 2000B2AF */  sw         $s2, 0x20($sp)
    /* A6D0 8006DA30 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* A6D4 8006DA34 1800B0AF */  sw         $s0, 0x18($sp)
    /* A6D8 8006DA38 1400438C */  lw         $v1, 0x14($v0)
    /* A6DC 8006DA3C 1000428C */  lw         $v0, 0x10($v0)
    /* A6E0 8006DA40 0800718C */  lw         $s1, 0x8($v1)
    /* A6E4 8006DA44 34005324 */  addiu      $s3, $v0, 0x34
    /* A6E8 8006DA48 00002392 */  lbu        $v1, 0x0($s1)
    /* A6EC 8006DA4C FF000224 */  addiu      $v0, $zero, 0xFF
    /* A6F0 8006DA50 3E006210 */  beq        $v1, $v0, .L8006DB4C
    /* A6F4 8006DA54 0580123C */   lui       $s2, %hi(D_8005071C)
  .L8006DA58:
    /* A6F8 8006DA58 1C07428E */  lw         $v0, %lo(D_8005071C)($s2)
    /* A6FC 8006DA5C 00000000 */  nop
    /* A700 8006DA60 10004284 */  lh         $v0, 0x10($v0)
    /* A704 8006DA64 00000000 */  nop
    /* A708 8006DA68 0C004228 */  slti       $v0, $v0, 0xC
    /* A70C 8006DA6C 37004010 */  beqz       $v0, .L8006DB4C
    /* A710 8006DA70 00000000 */   nop
    /* A714 8006DA74 71C4010C */  jal        func_800711C4
    /* A718 8006DA78 04000424 */   addiu     $a0, $zero, 0x4
    /* A71C 8006DA7C 21184000 */  addu       $v1, $v0, $zero
    /* A720 8006DA80 01000224 */  addiu      $v0, $zero, 0x1
    /* A724 8006DA84 0A006210 */  beq        $v1, $v0, .L8006DAB0
    /* A728 8006DA88 02006228 */   slti      $v0, $v1, 0x2
    /* A72C 8006DA8C 05004014 */  bnez       $v0, .L8006DAA4
    /* A730 8006DA90 02000224 */   addiu     $v0, $zero, 0x2
    /* A734 8006DA94 0B006210 */  beq        $v1, $v0, .L8006DAC4
    /* A738 8006DA98 03000224 */   addiu     $v0, $zero, 0x3
    /* A73C 8006DA9C 0C006210 */  beq        $v1, $v0, .L8006DAD0
    /* A740 8006DAA0 00000000 */   nop
  .L8006DAA4:
    /* A744 8006DAA4 02003096 */  lhu        $s0, 0x2($s1)
    /* A748 8006DAA8 B7B60108 */  j          .L8006DADC
    /* A74C 8006DAAC 0F001032 */   andi      $s0, $s0, 0xF
  .L8006DAB0:
    /* A750 8006DAB0 0000228E */  lw         $v0, 0x0($s1)
    /* A754 8006DAB4 00000000 */  nop
    /* A758 8006DAB8 02850200 */  srl        $s0, $v0, 20
    /* A75C 8006DABC B7B60108 */  j          .L8006DADC
    /* A760 8006DAC0 0F001032 */   andi      $s0, $s0, 0xF
  .L8006DAC4:
    /* A764 8006DAC4 03003092 */  lbu        $s0, 0x3($s1)
    /* A768 8006DAC8 B7B60108 */  j          .L8006DADC
    /* A76C 8006DACC 0F001032 */   andi      $s0, $s0, 0xF
  .L8006DAD0:
    /* A770 8006DAD0 0000228E */  lw         $v0, 0x0($s1)
    /* A774 8006DAD4 00000000 */  nop
    /* A778 8006DAD8 02870200 */  srl        $s0, $v0, 28
  .L8006DADC:
    /* A77C 8006DADC 16000012 */  beqz       $s0, .L8006DB38
    /* A780 8006DAE0 04000424 */   addiu     $a0, $zero, 0x4
    /* A784 8006DAE4 21280000 */  addu       $a1, $zero, $zero
    /* A788 8006DAE8 00002292 */  lbu        $v0, 0x0($s1)
    /* A78C 8006DAEC 76020624 */  addiu      $a2, $zero, 0x276
    /* A790 8006DAF0 1000A2AF */  sw         $v0, 0x10($sp)
    /* A794 8006DAF4 01002292 */  lbu        $v0, 0x1($s1)
    /* A798 8006DAF8 2138A000 */  addu       $a3, $a1, $zero
    /* A79C 8006DAFC 38B5010C */  jal        func_8006D4E0
    /* A7A0 8006DB00 1400A2AF */   sw        $v0, 0x14($sp)
    /* A7A4 8006DB04 FFFF1026 */  addiu      $s0, $s0, -0x1
    /* A7A8 8006DB08 80101000 */  sll        $v0, $s0, 2
    /* A7AC 8006DB0C 1C07458E */  lw         $a1, %lo(D_8005071C)($s2)
    /* A7B0 8006DB10 21105300 */  addu       $v0, $v0, $s3
    /* A7B4 8006DB14 1000A384 */  lh         $v1, 0x10($a1)
    /* A7B8 8006DB18 00004490 */  lbu        $a0, 0x0($v0)
    /* A7BC 8006DB1C 40180300 */  sll        $v1, $v1, 1
    /* A7C0 8006DB20 CE0C6324 */  addiu      $v1, $v1, 0xCCE
    /* A7C4 8006DB24 2128A300 */  addu       $a1, $a1, $v1
    /* A7C8 8006DB28 0000A4A0 */  sb         $a0, 0x0($a1)
    /* A7CC 8006DB2C 01004290 */  lbu        $v0, 0x1($v0)
    /* A7D0 8006DB30 00000000 */  nop
    /* A7D4 8006DB34 0100A2A0 */  sb         $v0, 0x1($a1)
  .L8006DB38:
    /* A7D8 8006DB38 04003126 */  addiu      $s1, $s1, 0x4
    /* A7DC 8006DB3C 00002392 */  lbu        $v1, 0x0($s1)
    /* A7E0 8006DB40 FF000224 */  addiu      $v0, $zero, 0xFF
    /* A7E4 8006DB44 C4FF6214 */  bne        $v1, $v0, .L8006DA58
    /* A7E8 8006DB48 00000000 */   nop
  .L8006DB4C:
    /* A7EC 8006DB4C 2800BF8F */  lw         $ra, 0x28($sp)
    /* A7F0 8006DB50 2400B38F */  lw         $s3, 0x24($sp)
    /* A7F4 8006DB54 2000B28F */  lw         $s2, 0x20($sp)
    /* A7F8 8006DB58 1C00B18F */  lw         $s1, 0x1C($sp)
    /* A7FC 8006DB5C 1800B08F */  lw         $s0, 0x18($sp)
    /* A800 8006DB60 0800E003 */  jr         $ra
    /* A804 8006DB64 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_8006DA18
