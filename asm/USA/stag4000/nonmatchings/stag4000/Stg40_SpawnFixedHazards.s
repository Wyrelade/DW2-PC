nonmatching Stg40_SpawnFixedHazards, 0x114

glabel Stg40_SpawnFixedHazards
    /* AA7C 8006DDDC 0780023C */  lui        $v0, %hi(D_80072B60)
    /* AA80 8006DDE0 602B428C */  lw         $v0, %lo(D_80072B60)($v0)
    /* AA84 8006DDE4 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* AA88 8006DDE8 1800BFAF */  sw         $ra, 0x18($sp)
    /* AA8C 8006DDEC 1400B1AF */  sw         $s1, 0x14($sp)
    /* AA90 8006DDF0 1000B0AF */  sw         $s0, 0x10($sp)
    /* AA94 8006DDF4 1400428C */  lw         $v0, 0x14($v0)
    /* AA98 8006DDF8 00000000 */  nop
    /* AA9C 8006DDFC 0C00508C */  lw         $s0, 0xC($v0)
    /* AAA0 8006DE00 00000000 */  nop
    /* AAA4 8006DE04 00000392 */  lbu        $v1, 0x0($s0)
    /* AAA8 8006DE08 FF000224 */  addiu      $v0, $zero, 0xFF
    /* AAAC 8006DE0C 33006210 */  beq        $v1, $v0, .L8006DEDC
    /* AAB0 8006DE10 01001126 */   addiu     $s1, $s0, 0x1
  .L8006DE14:
    /* AAB4 8006DE14 71C4010C */  jal        Stg40_RandInt
    /* AAB8 8006DE18 04000424 */   addiu     $a0, $zero, 0x4
    /* AABC 8006DE1C 21184000 */  addu       $v1, $v0, $zero
    /* AAC0 8006DE20 01000224 */  addiu      $v0, $zero, 0x1
    /* AAC4 8006DE24 0D006210 */  beq        $v1, $v0, .L8006DE5C
    /* AAC8 8006DE28 02006228 */   slti      $v0, $v1, 0x2
    /* AACC 8006DE2C 05004014 */  bnez       $v0, .L8006DE44
    /* AAD0 8006DE30 02000224 */   addiu     $v0, $zero, 0x2
    /* AAD4 8006DE34 0F006210 */  beq        $v1, $v0, .L8006DE74
    /* AAD8 8006DE38 03000224 */   addiu     $v0, $zero, 0x3
    /* AADC 8006DE3C 12006210 */  beq        $v1, $v0, .L8006DE88
    /* AAE0 8006DE40 00000000 */   nop
  .L8006DE44:
    /* AAE4 8006DE44 0000028E */  lw         $v0, 0x0($s0)
    /* AAE8 8006DE48 00000000 */  nop
    /* AAEC 8006DE4C 02240200 */  srl        $a0, $v0, 16
    /* AAF0 8006DE50 0F008430 */  andi       $a0, $a0, 0xF
    /* AAF4 8006DE54 A7B70108 */  j          .L8006DE9C
    /* AAF8 8006DE58 021D0200 */   srl       $v1, $v0, 20
  .L8006DE5C:
    /* AAFC 8006DE5C 0000028E */  lw         $v0, 0x0($s0)
    /* AB00 8006DE60 00000000 */  nop
    /* AB04 8006DE64 02260200 */  srl        $a0, $v0, 24
    /* AB08 8006DE68 0F008430 */  andi       $a0, $a0, 0xF
    /* AB0C 8006DE6C A8B70108 */  j          .L8006DEA0
    /* AB10 8006DE70 021F0200 */   srl       $v1, $v0, 28
  .L8006DE74:
    /* AB14 8006DE74 0300228E */  lw         $v0, 0x3($s1)
    /* AB18 8006DE78 00000000 */  nop
    /* AB1C 8006DE7C 0F004430 */  andi       $a0, $v0, 0xF
    /* AB20 8006DE80 A7B70108 */  j          .L8006DE9C
    /* AB24 8006DE84 02190200 */   srl       $v1, $v0, 4
  .L8006DE88:
    /* AB28 8006DE88 0300228E */  lw         $v0, 0x3($s1)
    /* AB2C 8006DE8C 00000000 */  nop
    /* AB30 8006DE90 02220200 */  srl        $a0, $v0, 8
    /* AB34 8006DE94 0F008430 */  andi       $a0, $a0, 0xF
    /* AB38 8006DE98 021B0200 */  srl        $v1, $v0, 12
  .L8006DE9C:
    /* AB3C 8006DE9C 0F006330 */  andi       $v1, $v1, 0xF
  .L8006DEA0:
    /* AB40 8006DEA0 09008010 */  beqz       $a0, .L8006DEC8
    /* AB44 8006DEA4 0580023C */   lui       $v0, %hi(D_8005071C)
    /* AB48 8006DEA8 1C07428C */  lw         $v0, %lo(D_8005071C)($v0)
    /* AB4C 8006DEAC 00000000 */  nop
    /* AB50 8006DEB0 540E428C */  lw         $v0, 0xE54($v0)
    /* AB54 8006DEB4 00000692 */  lbu        $a2, 0x0($s0)
    /* AB58 8006DEB8 0C004590 */  lbu        $a1, 0xC($v0)
    /* AB5C 8006DEBC 00002792 */  lbu        $a3, 0x0($s1)
    /* AB60 8006DEC0 DAB6010C */  jal        Stg40_SpawnHazard
    /* AB64 8006DEC4 21286500 */   addu      $a1, $v1, $a1
  .L8006DEC8:
    /* AB68 8006DEC8 08001026 */  addiu      $s0, $s0, 0x8
    /* AB6C 8006DECC 00000392 */  lbu        $v1, 0x0($s0)
    /* AB70 8006DED0 FF000224 */  addiu      $v0, $zero, 0xFF
    /* AB74 8006DED4 CFFF6214 */  bne        $v1, $v0, .L8006DE14
    /* AB78 8006DED8 08003126 */   addiu     $s1, $s1, 0x8
  .L8006DEDC:
    /* AB7C 8006DEDC 1800BF8F */  lw         $ra, 0x18($sp)
    /* AB80 8006DEE0 1400B18F */  lw         $s1, 0x14($sp)
    /* AB84 8006DEE4 1000B08F */  lw         $s0, 0x10($sp)
    /* AB88 8006DEE8 0800E003 */  jr         $ra
    /* AB8C 8006DEEC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg40_SpawnFixedHazards
