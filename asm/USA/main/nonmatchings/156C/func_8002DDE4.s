nonmatching func_8002DDE4, 0x84

glabel func_8002DDE4
    /* 1E5E4 8002DDE4 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1E5E8 8002DDE8 1800B0AF */  sw         $s0, 0x18($sp)
    /* 1E5EC 8002DDEC 21808000 */  addu       $s0, $a0, $zero
    /* 1E5F0 8002DDF0 0E000424 */  addiu      $a0, $zero, 0xE
    /* 1E5F4 8002DDF4 1000A527 */  addiu      $a1, $sp, 0x10
    /* 1E5F8 8002DDF8 21300000 */  addu       $a2, $zero, $zero
    /* 1E5FC 8002DDFC 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 1E600 8002DE00 55C1000C */  jal        CdControl
    /* 1E604 8002DE04 1000B0A3 */   sb        $s0, 0x10($sp)
    /* 1E608 8002DE08 00010232 */  andi       $v0, $s0, 0x100
    /* 1E60C 8002DE0C 0E004010 */  beqz       $v0, .L8002DE48
    /* 1E610 8002DE10 20000232 */   andi      $v0, $s0, 0x20
    /* 1E614 8002DE14 04004010 */  beqz       $v0, .L8002DE28
    /* 1E618 8002DE18 01000224 */   addiu     $v0, $zero, 0x1
    /* 1E61C 8002DE1C 0680013C */  lui        $at, %hi(D_80061B98)
    /* 1E620 8002DE20 8CB70008 */  j          .L8002DE30
    /* 1E624 8002DE24 981B20AC */   sw        $zero, %lo(D_80061B98)($at)
  .L8002DE28:
    /* 1E628 8002DE28 0680013C */  lui        $at, %hi(D_80061B98)
    /* 1E62C 8002DE2C 981B22AC */  sw         $v0, %lo(D_80061B98)($at)
  .L8002DE30:
    /* 1E630 8002DE30 0380043C */  lui        $a0, %hi(func_8002DF74)
    /* 1E634 8002DE34 8DC2000C */  jal        CdDataCallback
    /* 1E638 8002DE38 74DF8424 */   addiu     $a0, $a0, %lo(func_8002DF74)
    /* 1E63C 8002DE3C 0380043C */  lui        $a0, %hi(func_8002DE68)
    /* 1E640 8002DE40 4DC1000C */  jal        CdReadyCallback
    /* 1E644 8002DE44 68DE8424 */   addiu     $a0, $a0, %lo(func_8002DE68)
  .L8002DE48:
    /* 1E648 8002DE48 1B000424 */  addiu      $a0, $zero, 0x1B
    /* 1E64C 8002DE4C 21280000 */  addu       $a1, $zero, $zero
    /* 1E650 8002DE50 55C1000C */  jal        CdControl
    /* 1E654 8002DE54 21300000 */   addu      $a2, $zero, $zero
    /* 1E658 8002DE58 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 1E65C 8002DE5C 1800B08F */  lw         $s0, 0x18($sp)
    /* 1E660 8002DE60 0800E003 */  jr         $ra
    /* 1E664 8002DE64 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8002DDE4
