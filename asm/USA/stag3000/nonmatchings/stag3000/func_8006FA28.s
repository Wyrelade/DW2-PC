nonmatching func_8006FA28, 0x250

glabel func_8006FA28
    /* C6C8 8006FA28 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* C6CC 8006FA2C 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* C6D0 8006FA30 1800B2AF */  sw         $s2, 0x18($sp)
    /* C6D4 8006FA34 1400B1AF */  sw         $s1, 0x14($sp)
    /* C6D8 8006FA38 1000B0AF */  sw         $s0, 0x10($sp)
    /* C6DC 8006FA3C 2C00918C */  lw         $s1, 0x2C($a0)
    /* C6E0 8006FA40 21800000 */  addu       $s0, $zero, $zero
    /* C6E4 8006FA44 0000238E */  lw         $v1, 0x0($s1)
    /* C6E8 8006FA48 00000000 */  nop
    /* C6EC 8006FA4C 0900622C */  sltiu      $v0, $v1, 0x9
    /* C6F0 8006FA50 09004010 */  beqz       $v0, .L8006FA78
    /* C6F4 8006FA54 01001224 */   addiu     $s2, $zero, 0x1
    /* C6F8 8006FA58 0680023C */  lui        $v0, %hi(jtbl_800637D4)
    /* C6FC 8006FA5C D4374224 */  addiu      $v0, $v0, %lo(jtbl_800637D4)
    /* C700 8006FA60 80180300 */  sll        $v1, $v1, 2
    /* C704 8006FA64 21186200 */  addu       $v1, $v1, $v0
    /* C708 8006FA68 0000628C */  lw         $v0, 0x0($v1)
    /* C70C 8006FA6C 00000000 */  nop
    /* C710 8006FA70 08004000 */  jr         $v0
    /* C714 8006FA74 00000000 */   nop
  jlabel .L8006FA78
    /* C718 8006FA78 0400248E */  lw         $a0, 0x4($s1)
    /* C71C 8006FA7C 977B000C */  jal        func_8001EE5C
    /* C720 8006FA80 00000000 */   nop
    /* C724 8006FA84 688E000C */  jal        Cd_GetFileEntry
    /* C728 8006FA88 21204000 */   addu      $a0, $v0, $zero
    /* C72C 8006FA8C C7BE0108 */  j          .L8006FB1C
    /* C730 8006FA90 21804000 */   addu      $s0, $v0, $zero
  jlabel .L8006FA94
    /* C734 8006FA94 688E000C */  jal        Cd_GetFileEntry
    /* C738 8006FA98 2D0D043C */   lui       $a0, (0xD2D0000 >> 16)
    /* C73C 8006FA9C 21804000 */  addu       $s0, $v0, $zero
    /* C740 8006FAA0 0780033C */  lui        $v1, %hi(D_80073300)
    /* C744 8006FAA4 0000228E */  lw         $v0, 0x0($s1)
    /* C748 8006FAA8 00336324 */  addiu      $v1, $v1, %lo(D_80073300)
    /* C74C 8006FAAC BFBE0108 */  j          .L8006FAFC
    /* C750 8006FAB0 FCFF4224 */   addiu     $v0, $v0, -0x4
  jlabel .L8006FAB4
    /* C754 8006FAB4 688E000C */  jal        Cd_GetFileEntry
    /* C758 8006FAB8 A101043C */   lui       $a0, (0x1A10000 >> 16)
    /* C75C 8006FABC 21804000 */  addu       $s0, $v0, $zero
    /* C760 8006FAC0 21200002 */  addu       $a0, $s0, $zero
    /* C764 8006FAC4 0780033C */  lui        $v1, %hi(D_8007331C)
    /* C768 8006FAC8 1C336324 */  addiu      $v1, $v1, %lo(D_8007331C)
    /* C76C 8006FACC 0000228E */  lw         $v0, 0x0($s1)
    /* C770 8006FAD0 0400278E */  lw         $a3, 0x4($s1)
    /* C774 8006FAD4 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* C778 8006FAD8 80100200 */  sll        $v0, $v0, 2
    /* C77C 8006FADC 21104300 */  addu       $v0, $v0, $v1
    /* C780 8006FAE0 0000458C */  lw         $a1, 0x0($v0)
    /* C784 8006FAE4 6D75000C */  jal        Gfx_SetPartsNumber
    /* C788 8006FAE8 03000624 */   addiu     $a2, $zero, 0x3
    /* C78C 8006FAEC 0780033C */  lui        $v1, %hi(D_80073310)
    /* C790 8006FAF0 0000228E */  lw         $v0, 0x0($s1)
    /* C794 8006FAF4 10336324 */  addiu      $v1, $v1, %lo(D_80073310)
    /* C798 8006FAF8 FFFF4224 */  addiu      $v0, $v0, -0x1
  .L8006FAFC:
    /* C79C 8006FAFC 80100200 */  sll        $v0, $v0, 2
    /* C7A0 8006FB00 21104300 */  addu       $v0, $v0, $v1
    /* C7A4 8006FB04 0000458C */  lw         $a1, 0x0($v0)
    /* C7A8 8006FB08 4175000C */  jal        Gfx_HidePartsByMask
    /* C7AC 8006FB0C 21200002 */   addu      $a0, $s0, $zero
    /* C7B0 8006FB10 C7BE0108 */  j          .L8006FB1C
    /* C7B4 8006FB14 00000000 */   nop
  jlabel .L8006FB18
    /* C7B8 8006FB18 21900000 */  addu       $s2, $zero, $zero
  .L8006FB1C:
    /* C7BC 8006FB1C 1A004012 */  beqz       $s2, .L8006FB88
    /* C7C0 8006FB20 00000000 */   nop
    /* C7C4 8006FB24 0000028E */  lw         $v0, 0x0($s0)
    /* C7C8 8006FB28 00000000 */  nop
    /* C7CC 8006FB2C 14004010 */  beqz       $v0, .L8006FB80
    /* C7D0 8006FB30 21200002 */   addu      $a0, $s0, $zero
    /* C7D4 8006FB34 00100624 */  addiu      $a2, $zero, 0x1000
    /* C7D8 8006FB38 01000524 */  addiu      $a1, $zero, 0x1
    /* C7DC 8006FB3C 0C000326 */  addiu      $v1, $s0, 0xC
  .L8006FB40:
    /* C7E0 8006FB40 0C00228E */  lw         $v0, 0xC($s1)
    /* C7E4 8006FB44 00000000 */  nop
    /* C7E8 8006FB48 05004610 */  beq        $v0, $a2, .L8006FB60
    /* C7EC 8006FB4C 00000000 */   nop
    /* C7F0 8006FB50 020060A0 */  sb         $zero, 0x2($v1)
    /* C7F4 8006FB54 0C00228E */  lw         $v0, 0xC($s1)
    /* C7F8 8006FB58 D9BE0108 */  j          .L8006FB64
    /* C7FC 8006FB5C 040062AC */   sw        $v0, 0x4($v1)
  .L8006FB60:
    /* C800 8006FB60 020065A0 */  sb         $a1, 0x2($v1)
  .L8006FB64:
    /* C804 8006FB64 10002292 */  lbu        $v0, 0x10($s1)
    /* C808 8006FB68 28008424 */  addiu      $a0, $a0, 0x28
    /* C80C 8006FB6C 000062A0 */  sb         $v0, 0x0($v1)
    /* C810 8006FB70 0000828C */  lw         $v0, 0x0($a0)
    /* C814 8006FB74 00000000 */  nop
    /* C818 8006FB78 F1FF4014 */  bnez       $v0, .L8006FB40
    /* C81C 8006FB7C 28006324 */   addiu     $v1, $v1, 0x28
  .L8006FB80:
    /* C820 8006FB80 2176000C */  jal        Gfx_DrawParts
    /* C824 8006FB84 21200002 */   addu      $a0, $s0, $zero
  .L8006FB88:
    /* C828 8006FB88 0800228E */  lw         $v0, 0x8($s1)
    /* C82C 8006FB8C 00000000 */  nop
    /* C830 8006FB90 33004010 */  beqz       $v0, .L8006FC60
    /* C834 8006FB94 031A0200 */   sra       $v1, $v0, 8
    /* C838 8006FB98 01000224 */  addiu      $v0, $zero, 0x1
    /* C83C 8006FB9C 08006210 */  beq        $v1, $v0, .L8006FBC0
    /* C840 8006FBA0 02006228 */   slti      $v0, $v1, 0x2
    /* C844 8006FBA4 03004014 */  bnez       $v0, .L8006FBB4
    /* C848 8006FBA8 02000224 */   addiu     $v0, $zero, 0x2
    /* C84C 8006FBAC 07006210 */  beq        $v1, $v0, .L8006FBCC
    /* C850 8006FBB0 00000000 */   nop
  .L8006FBB4:
    /* C854 8006FBB4 A101043C */  lui        $a0, (0x1A10026 >> 16)
    /* C858 8006FBB8 F5BE0108 */  j          .L8006FBD4
    /* C85C 8006FBBC 26008434 */   ori       $a0, $a0, (0x1A10026 & 0xFFFF)
  .L8006FBC0:
    /* C860 8006FBC0 A101043C */  lui        $a0, (0x1A10027 >> 16)
    /* C864 8006FBC4 F5BE0108 */  j          .L8006FBD4
    /* C868 8006FBC8 27008434 */   ori       $a0, $a0, (0x1A10027 & 0xFFFF)
  .L8006FBCC:
    /* C86C 8006FBCC A101043C */  lui        $a0, (0x1A10028 >> 16)
    /* C870 8006FBD0 28008434 */  ori        $a0, $a0, (0x1A10028 & 0xFFFF)
  .L8006FBD4:
    /* C874 8006FBD4 688E000C */  jal        Cd_GetFileEntry
    /* C878 8006FBD8 00000000 */   nop
    /* C87C 8006FBDC 21804000 */  addu       $s0, $v0, $zero
    /* C880 8006FBE0 21200002 */  addu       $a0, $s0, $zero
    /* C884 8006FBE4 08002292 */  lbu        $v0, 0x8($s1)
    /* C888 8006FBE8 01000524 */  addiu      $a1, $zero, 0x1
    /* C88C 8006FBEC FFFF4224 */  addiu      $v0, $v0, -0x1
    /* C890 8006FBF0 04284500 */  sllv       $a1, $a1, $v0
    /* C894 8006FBF4 4175000C */  jal        Gfx_HidePartsByMask
    /* C898 8006FBF8 27280500 */   nor       $a1, $zero, $a1
    /* C89C 8006FBFC 0000028E */  lw         $v0, 0x0($s0)
    /* C8A0 8006FC00 00000000 */  nop
    /* C8A4 8006FC04 14004010 */  beqz       $v0, .L8006FC58
    /* C8A8 8006FC08 21200002 */   addu      $a0, $s0, $zero
    /* C8AC 8006FC0C 00100624 */  addiu      $a2, $zero, 0x1000
    /* C8B0 8006FC10 01000524 */  addiu      $a1, $zero, 0x1
    /* C8B4 8006FC14 0C000326 */  addiu      $v1, $s0, 0xC
  .L8006FC18:
    /* C8B8 8006FC18 0C00228E */  lw         $v0, 0xC($s1)
    /* C8BC 8006FC1C 00000000 */  nop
    /* C8C0 8006FC20 05004610 */  beq        $v0, $a2, .L8006FC38
    /* C8C4 8006FC24 00000000 */   nop
    /* C8C8 8006FC28 020060A0 */  sb         $zero, 0x2($v1)
    /* C8CC 8006FC2C 0C00228E */  lw         $v0, 0xC($s1)
    /* C8D0 8006FC30 0FBF0108 */  j          .L8006FC3C
    /* C8D4 8006FC34 040062AC */   sw        $v0, 0x4($v1)
  .L8006FC38:
    /* C8D8 8006FC38 020065A0 */  sb         $a1, 0x2($v1)
  .L8006FC3C:
    /* C8DC 8006FC3C 10002292 */  lbu        $v0, 0x10($s1)
    /* C8E0 8006FC40 28008424 */  addiu      $a0, $a0, 0x28
    /* C8E4 8006FC44 000062A0 */  sb         $v0, 0x0($v1)
    /* C8E8 8006FC48 0000828C */  lw         $v0, 0x0($a0)
    /* C8EC 8006FC4C 00000000 */  nop
    /* C8F0 8006FC50 F1FF4014 */  bnez       $v0, .L8006FC18
    /* C8F4 8006FC54 28006324 */   addiu     $v1, $v1, 0x28
  .L8006FC58:
    /* C8F8 8006FC58 2176000C */  jal        Gfx_DrawParts
    /* C8FC 8006FC5C 21200002 */   addu      $a0, $s0, $zero
  .L8006FC60:
    /* C900 8006FC60 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* C904 8006FC64 1800B28F */  lw         $s2, 0x18($sp)
    /* C908 8006FC68 1400B18F */  lw         $s1, 0x14($sp)
    /* C90C 8006FC6C 1000B08F */  lw         $s0, 0x10($sp)
    /* C910 8006FC70 0800E003 */  jr         $ra
    /* C914 8006FC74 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8006FA28
