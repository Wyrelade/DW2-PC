nonmatching Stg40_ApplyFloorLayout, 0x100

glabel Stg40_ApplyFloorLayout
    /* DA60 80070DC0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* DA64 80070DC4 0780023C */  lui        $v0, %hi(D_80072B60)
    /* DA68 80070DC8 1800B2AF */  sw         $s2, 0x18($sp)
    /* DA6C 80070DCC 0580123C */  lui        $s2, %hi(D_8005071C)
    /* DA70 80070DD0 1C07448E */  lw         $a0, %lo(D_8005071C)($s2)
    /* DA74 80070DD4 602B438C */  lw         $v1, %lo(D_80072B60)($v0)
    /* DA78 80070DD8 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* DA7C 80070DDC 1400B1AF */  sw         $s1, 0x14($sp)
    /* DA80 80070DE0 1000B0AF */  sw         $s0, 0x10($sp)
    /* DA84 80070DE4 04008290 */  lbu        $v0, 0x4($a0)
    /* DA88 80070DE8 1000658C */  lw         $a1, 0x10($v1)
    /* DA8C 80070DEC 80100200 */  sll        $v0, $v0, 2
    /* DA90 80070DF0 2110A200 */  addu       $v0, $a1, $v0
    /* DA94 80070DF4 0800428C */  lw         $v0, 0x8($v0)
    /* DA98 80070DF8 00000000 */  nop
    /* DA9C 80070DFC 140062AC */  sw         $v0, 0x14($v1)
    /* DAA0 80070E00 540E838C */  lw         $v1, 0xE54($a0)
    /* DAA4 80070E04 2800A294 */  lhu        $v0, 0x28($a1)
    /* DAA8 80070E08 00000000 */  nop
    /* DAAC 80070E0C 0A0062A4 */  sh         $v0, 0xA($v1)
    /* DAB0 80070E10 540E838C */  lw         $v1, 0xE54($a0)
    /* DAB4 80070E14 01000224 */  addiu      $v0, $zero, 0x1
    /* DAB8 80070E18 040062A4 */  sh         $v0, 0x4($v1)
    /* DABC 80070E1C 540E838C */  lw         $v1, 0xE54($a0)
    /* DAC0 80070E20 2E00A290 */  lbu        $v0, 0x2E($a1)
    /* DAC4 80070E24 10000624 */  addiu      $a2, $zero, 0x10
    /* DAC8 80070E28 0C0062A0 */  sb         $v0, 0xC($v1)
    /* DACC 80070E2C 1C07428E */  lw         $v0, %lo(D_8005071C)($s2)
    /* DAD0 80070E30 0000B18C */  lw         $s1, 0x0($a1)
    /* DAD4 80070E34 540E428C */  lw         $v0, 0xE54($v0)
    /* DAD8 80070E38 FF000524 */  addiu      $a1, $zero, 0xFF
    /* DADC 80070E3C 0E005024 */  addiu      $s0, $v0, 0xE
    /* DAE0 80070E40 219C000C */  jal        memset
    /* DAE4 80070E44 21200002 */   addu      $a0, $s0, $zero
    /* DAE8 80070E48 1C07428E */  lw         $v0, %lo(D_8005071C)($s2)
    /* DAEC 80070E4C 00000000 */  nop
    /* DAF0 80070E50 540E428C */  lw         $v0, 0xE54($v0)
    /* DAF4 80070E54 00000000 */  nop
    /* DAF8 80070E58 0D0040A0 */  sb         $zero, 0xD($v0)
    /* DAFC 80070E5C 00002392 */  lbu        $v1, 0x0($s1)
    /* DB00 80070E60 FF000224 */  addiu      $v0, $zero, 0xFF
    /* DB04 80070E64 10006210 */  beq        $v1, $v0, .L80070EA8
    /* DB08 80070E68 00000000 */   nop
    /* DB0C 80070E6C 21284002 */  addu       $a1, $s2, $zero
    /* DB10 80070E70 21204000 */  addu       $a0, $v0, $zero
  .L80070E74:
    /* DB14 80070E74 000003A2 */  sb         $v1, 0x0($s0)
    /* DB18 80070E78 1C07A28C */  lw         $v0, %lo(D_8005071C)($a1)
    /* DB1C 80070E7C 00000000 */  nop
    /* DB20 80070E80 540E438C */  lw         $v1, 0xE54($v0)
    /* DB24 80070E84 00000000 */  nop
    /* DB28 80070E88 0D006290 */  lbu        $v0, 0xD($v1)
    /* DB2C 80070E8C 01003126 */  addiu      $s1, $s1, 0x1
    /* DB30 80070E90 01004224 */  addiu      $v0, $v0, 0x1
    /* DB34 80070E94 0D0062A0 */  sb         $v0, 0xD($v1)
    /* DB38 80070E98 00002392 */  lbu        $v1, 0x0($s1)
    /* DB3C 80070E9C 00000000 */  nop
    /* DB40 80070EA0 F4FF6414 */  bne        $v1, $a0, .L80070E74
    /* DB44 80070EA4 01001026 */   addiu     $s0, $s0, 0x1
  .L80070EA8:
    /* DB48 80070EA8 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* DB4C 80070EAC 1800B28F */  lw         $s2, 0x18($sp)
    /* DB50 80070EB0 1400B18F */  lw         $s1, 0x14($sp)
    /* DB54 80070EB4 1000B08F */  lw         $s0, 0x10($sp)
    /* DB58 80070EB8 0800E003 */  jr         $ra
    /* DB5C 80070EBC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg40_ApplyFloorLayout
