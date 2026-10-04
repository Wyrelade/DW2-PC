nonmatching func_8006F86C, 0x3E8

glabel func_8006F86C
    /* C50C 8006F86C 98FFBD27 */  addiu      $sp, $sp, -0x68
    /* C510 8006F870 21688000 */  addu       $t5, $a0, $zero
    /* C514 8006F874 5000B0AF */  sw         $s0, 0x50($sp)
    /* C518 8006F878 2180A000 */  addu       $s0, $a1, $zero
    /* C51C 8006F87C 5400B1AF */  sw         $s1, 0x54($sp)
    /* C520 8006F880 0680043C */  lui        $a0, %hi(Sys_State)
    /* C524 8006F884 7C00A58F */  lw         $a1, 0x7C($sp)
    /* C528 8006F888 8000A88F */  lw         $t0, 0x80($sp)
    /* C52C 8006F88C 70F78424 */  addiu      $a0, $a0, %lo(Sys_State)
    /* C530 8006F890 6400B5AF */  sw         $s5, 0x64($sp)
    /* C534 8006F894 6000B4AF */  sw         $s4, 0x60($sp)
    /* C538 8006F898 5C00B3AF */  sw         $s3, 0x5C($sp)
    /* C53C 8006F89C 5800B2AF */  sw         $s2, 0x58($sp)
    /* C540 8006F8A0 2C008A8C */  lw         $t2, 0x2C($a0)
    /* C544 8006F8A4 7800B88F */  lw         $t8, 0x78($sp)
    /* C548 8006F8A8 8400B98F */  lw         $t9, 0x84($sp)
    /* C54C 8006F8AC 8800AE8F */  lw         $t6, 0x88($sp)
    /* C550 8006F8B0 3C018F8C */  lw         $t7, 0x13C($a0)
    /* C554 8006F8B4 6807A485 */  lh         $a0, 0x768($t5)
    /* C558 8006F8B8 FFFFA224 */  addiu      $v0, $a1, -0x1
    /* C55C 8006F8BC C21F0200 */  srl        $v1, $v0, 31
    /* C560 8006F8C0 21104300 */  addu       $v0, $v0, $v1
    /* C564 8006F8C4 43280200 */  sra        $a1, $v0, 1
    /* C568 8006F8C8 FFFF0225 */  addiu      $v0, $t0, -0x1
    /* C56C 8006F8CC C21F0200 */  srl        $v1, $v0, 31
    /* C570 8006F8D0 21104300 */  addu       $v0, $v0, $v1
    /* C574 8006F8D4 43400200 */  sra        $t0, $v0, 1
    /* C578 8006F8D8 2348E500 */  subu       $t1, $a3, $a1
    /* C57C 8006F8DC 6607A285 */  lh         $v0, 0x766($t5)
    /* C580 8006F8E0 02002105 */  bgez       $t1, .L8006F8EC
    /* C584 8006F8E4 2188C000 */   addu      $s1, $a2, $zero
    /* C588 8006F8E8 21480000 */  addu       $t1, $zero, $zero
  .L8006F8EC:
    /* C58C 8006F8EC 01004224 */  addiu      $v0, $v0, 0x1
    /* C590 8006F8F0 21584000 */  addu       $t3, $v0, $zero
    /* C594 8006F8F4 2110E500 */  addu       $v0, $a3, $a1
    /* C598 8006F8F8 02004324 */  addiu      $v1, $v0, 0x2
    /* C59C 8006F8FC 2A106301 */  slt        $v0, $t3, $v1
    /* C5A0 8006F900 02004014 */  bnez       $v0, .L8006F90C
    /* C5A4 8006F904 23280803 */   subu      $a1, $t8, $t0
    /* C5A8 8006F908 21586000 */  addu       $t3, $v1, $zero
  .L8006F90C:
    /* C5AC 8006F90C 0200A104 */  bgez       $a1, .L8006F918
    /* C5B0 8006F910 01008224 */   addiu     $v0, $a0, 0x1
    /* C5B4 8006F914 21280000 */  addu       $a1, $zero, $zero
  .L8006F918:
    /* C5B8 8006F918 21604000 */  addu       $t4, $v0, $zero
    /* C5BC 8006F91C 21100803 */  addu       $v0, $t8, $t0
    /* C5C0 8006F920 02004324 */  addiu      $v1, $v0, 0x2
    /* C5C4 8006F924 2A108301 */  slt        $v0, $t4, $v1
    /* C5C8 8006F928 02004014 */  bnez       $v0, .L8006F934
    /* C5CC 8006F92C 09000224 */   addiu     $v0, $zero, 0x9
    /* C5D0 8006F930 21606000 */  addu       $t4, $v1, $zero
  .L8006F934:
    /* C5D4 8006F934 0300A2A3 */  sb         $v0, 0x3($sp)
    /* C5D8 8006F938 2C000224 */  addiu      $v0, $zero, 0x2C
    /* C5DC 8006F93C 0700A2A3 */  sb         $v0, 0x7($sp)
    /* C5E0 8006F940 0400AEA3 */  sb         $t6, 0x4($sp)
    /* C5E4 8006F944 0500AEA3 */  sb         $t6, 0x5($sp)
    /* C5E8 8006F948 0600AEA3 */  sb         $t6, 0x6($sp)
    /* C5EC 8006F94C 5807A38D */  lw         $v1, 0x758($t5)
    /* C5F0 8006F950 00000000 */  nop
    /* C5F4 8006F954 1C00648C */  lw         $a0, 0x1C($v1)
    /* C5F8 8006F958 1800628C */  lw         $v0, 0x18($v1)
    /* C5FC 8006F95C 1C006394 */  lhu        $v1, 0x1C($v1)
    /* C600 8006F960 00018430 */  andi       $a0, $a0, 0x100
    /* C604 8006F964 03210400 */  sra        $a0, $a0, 4
    /* C608 8006F968 FF034230 */  andi       $v0, $v0, 0x3FF
    /* C60C 8006F96C 83110200 */  sra        $v0, $v0, 6
    /* C610 8006F970 20004234 */  ori        $v0, $v0, 0x20
    /* C614 8006F974 25208200 */  or         $a0, $a0, $v0
    /* C618 8006F978 00026330 */  andi       $v1, $v1, 0x200
    /* C61C 8006F97C 80180300 */  sll        $v1, $v1, 2
    /* C620 8006F980 25208300 */  or         $a0, $a0, $v1
    /* C624 8006F984 1600A4A7 */  sh         $a0, 0x16($sp)
    /* C628 8006F988 4A07A495 */  lhu        $a0, 0x74A($t5)
    /* C62C 8006F98C 4807A295 */  lhu        $v0, 0x748($t5)
    /* C630 8006F990 80210400 */  sll        $a0, $a0, 6
    /* C634 8006F994 02110200 */  srl        $v0, $v0, 4
    /* C638 8006F998 3F004230 */  andi       $v0, $v0, 0x3F
    /* C63C 8006F99C 25208200 */  or         $a0, $a0, $v0
    /* C640 8006F9A0 23102701 */  subu       $v0, $t1, $a3
    /* C644 8006F9A4 18005900 */  mult       $v0, $t9
    /* C648 8006F9A8 2E000324 */  addiu      $v1, $zero, 0x2E
    /* C64C 8006F9AC 0700A3A3 */  sb         $v1, 0x7($sp)
    /* C650 8006F9B0 0E00A4A7 */  sh         $a0, 0xE($sp)
    /* C654 8006F9B4 5807A28D */  lw         $v0, 0x758($t5)
    /* C658 8006F9B8 00000000 */  nop
    /* C65C 8006F9BC 0C004290 */  lbu        $v0, 0xC($v0)
    /* C660 8006F9C0 0D00A5A3 */  sb         $a1, 0xD($sp)
    /* C664 8006F9C4 21104900 */  addu       $v0, $v0, $t1
    /* C668 8006F9C8 03004224 */  addiu      $v0, $v0, 0x3
    /* C66C 8006F9CC 12300000 */  mflo       $a2
    /* C670 8006F9D0 0C00A2A3 */  sb         $v0, 0xC($sp)
    /* C674 8006F9D4 2310B800 */  subu       $v0, $a1, $t8
    /* C678 8006F9D8 18005900 */  mult       $v0, $t9
    /* C67C 8006F9DC 5807A38D */  lw         $v1, 0x758($t5)
    /* C680 8006F9E0 00000000 */  nop
    /* C684 8006F9E4 0C006290 */  lbu        $v0, 0xC($v1)
    /* C688 8006F9E8 2800A827 */  addiu      $t0, $sp, 0x28
    /* C68C 8006F9EC 1500A5A3 */  sb         $a1, 0x15($sp)
    /* C690 8006F9F0 23286901 */  subu       $a1, $t3, $t1
    /* C694 8006F9F4 21104900 */  addu       $v0, $v0, $t1
    /* C698 8006F9F8 03004224 */  addiu      $v0, $v0, 0x3
    /* C69C 8006F9FC 21104500 */  addu       $v0, $v0, $a1
    /* C6A0 8006FA00 1400A2A3 */  sb         $v0, 0x14($sp)
    /* C6A4 8006FA04 5807A28D */  lw         $v0, 0x758($t5)
    /* C6A8 8006FA08 12700000 */  mflo       $t6
    /* C6AC 8006FA0C 23186701 */  subu       $v1, $t3, $a3
    /* C6B0 8006FA10 0C004290 */  lbu        $v0, 0xC($v0)
    /* C6B4 8006FA14 18007900 */  mult       $v1, $t9
    /* C6B8 8006FA18 21208001 */  addu       $a0, $t4, $zero
    /* C6BC 8006FA1C 1D00A4A3 */  sb         $a0, 0x1D($sp)
    /* C6C0 8006FA20 21104900 */  addu       $v0, $v0, $t1
    /* C6C4 8006FA24 03004224 */  addiu      $v0, $v0, 0x3
    /* C6C8 8006FA28 1C00A2A3 */  sb         $v0, 0x1C($sp)
    /* C6CC 8006FA2C 5807A28D */  lw         $v0, 0x758($t5)
    /* C6D0 8006FA30 2138A003 */  addu       $a3, $sp, $zero
    /* C6D4 8006FA34 0C004290 */  lbu        $v0, 0xC($v0)
    /* C6D8 8006FA38 2000AB27 */  addiu      $t3, $sp, 0x20
    /* C6DC 8006FA3C 2500A4A3 */  sb         $a0, 0x25($sp)
    /* C6E0 8006FA40 23209800 */  subu       $a0, $a0, $t8
    /* C6E4 8006FA44 12180000 */  mflo       $v1
    /* C6E8 8006FA48 21104900 */  addu       $v0, $v0, $t1
    /* C6EC 8006FA4C 03004224 */  addiu      $v0, $v0, 0x3
    /* C6F0 8006FA50 18009900 */  mult       $a0, $t9
    /* C6F4 8006FA54 21104500 */  addu       $v0, $v0, $a1
    /* C6F8 8006FA58 2400A2A3 */  sb         $v0, 0x24($sp)
    /* C6FC 8006FA5C 21102E02 */  addu       $v0, $s1, $t6
    /* C700 8006FA60 0A00A2A7 */  sh         $v0, 0xA($sp)
    /* C704 8006FA64 21200602 */  addu       $a0, $s0, $a2
    /* C708 8006FA68 21180302 */  addu       $v1, $s0, $v1
    /* C70C 8006FA6C 0800A4A7 */  sh         $a0, 0x8($sp)
    /* C710 8006FA70 1000A3A7 */  sh         $v1, 0x10($sp)
    /* C714 8006FA74 1200A2A7 */  sh         $v0, 0x12($sp)
    /* C718 8006FA78 1800A4A7 */  sh         $a0, 0x18($sp)
    /* C71C 8006FA7C 2000A3A7 */  sh         $v1, 0x20($sp)
    /* C720 8006FA80 12480000 */  mflo       $t1
    /* C724 8006FA84 21102902 */  addu       $v0, $s1, $t1
    /* C728 8006FA88 1A00A2A7 */  sh         $v0, 0x1A($sp)
    /* C72C 8006FA8C 2200A2A7 */  sh         $v0, 0x22($sp)
  .L8006FA90:
    /* C730 8006FA90 0000F28C */  lw         $s2, 0x0($a3)
    /* C734 8006FA94 0400F38C */  lw         $s3, 0x4($a3)
    /* C738 8006FA98 0800F48C */  lw         $s4, 0x8($a3)
    /* C73C 8006FA9C 0C00F58C */  lw         $s5, 0xC($a3)
    /* C740 8006FAA0 000012AD */  sw         $s2, 0x0($t0)
    /* C744 8006FAA4 040013AD */  sw         $s3, 0x4($t0)
    /* C748 8006FAA8 080014AD */  sw         $s4, 0x8($t0)
    /* C74C 8006FAAC 0C0015AD */  sw         $s5, 0xC($t0)
    /* C750 8006FAB0 1000E724 */  addiu      $a3, $a3, 0x10
    /* C754 8006FAB4 F6FFEB14 */  bne        $a3, $t3, .L8006FA90
    /* C758 8006FAB8 10000825 */   addiu     $t0, $t0, 0x10
    /* C75C 8006FABC 0000F28C */  lw         $s2, 0x0($a3)
    /* C760 8006FAC0 0400F38C */  lw         $s3, 0x4($a3)
    /* C764 8006FAC4 000012AD */  sw         $s2, 0x0($t0)
    /* C768 8006FAC8 040013AD */  sw         $s3, 0x4($t0)
    /* C76C 8006FACC 21384001 */  addu       $a3, $t2, $zero
    /* C770 8006FAD0 5807A38D */  lw         $v1, 0x758($t5)
    /* C774 8006FAD4 2128A003 */  addu       $a1, $sp, $zero
    /* C778 8006FAD8 1C00648C */  lw         $a0, 0x1C($v1)
    /* C77C 8006FADC 1800628C */  lw         $v0, 0x18($v1)
    /* C780 8006FAE0 1C006394 */  lhu        $v1, 0x1C($v1)
    /* C784 8006FAE4 00018430 */  andi       $a0, $a0, 0x100
    /* C788 8006FAE8 03210400 */  sra        $a0, $a0, 4
    /* C78C 8006FAEC FF034230 */  andi       $v0, $v0, 0x3FF
    /* C790 8006FAF0 83110200 */  sra        $v0, $v0, 6
    /* C794 8006FAF4 40004234 */  ori        $v0, $v0, 0x40
    /* C798 8006FAF8 25208200 */  or         $a0, $a0, $v0
    /* C79C 8006FAFC 00026330 */  andi       $v1, $v1, 0x200
    /* C7A0 8006FB00 80180300 */  sll        $v1, $v1, 2
    /* C7A4 8006FB04 25208300 */  or         $a0, $a0, $v1
    /* C7A8 8006FB08 3E00A4A7 */  sh         $a0, 0x3E($sp)
    /* C7AC 8006FB0C 2000A427 */  addiu      $a0, $sp, 0x20
    /* C7B0 8006FB10 4A07A295 */  lhu        $v0, 0x74A($t5)
    /* C7B4 8006FB14 4807A395 */  lhu        $v1, 0x748($t5)
    /* C7B8 8006FB18 01004224 */  addiu      $v0, $v0, 0x1
    /* C7BC 8006FB1C 80110200 */  sll        $v0, $v0, 6
    /* C7C0 8006FB20 02190300 */  srl        $v1, $v1, 4
    /* C7C4 8006FB24 3F006330 */  andi       $v1, $v1, 0x3F
    /* C7C8 8006FB28 25104300 */  or         $v0, $v0, $v1
    /* C7CC 8006FB2C 3600A2A7 */  sh         $v0, 0x36($sp)
  .L8006FB30:
    /* C7D0 8006FB30 0000B28C */  lw         $s2, 0x0($a1)
    /* C7D4 8006FB34 0400B38C */  lw         $s3, 0x4($a1)
    /* C7D8 8006FB38 0800B48C */  lw         $s4, 0x8($a1)
    /* C7DC 8006FB3C 0C00B58C */  lw         $s5, 0xC($a1)
    /* C7E0 8006FB40 0000F2AC */  sw         $s2, 0x0($a3)
    /* C7E4 8006FB44 0400F3AC */  sw         $s3, 0x4($a3)
    /* C7E8 8006FB48 0800F4AC */  sw         $s4, 0x8($a3)
    /* C7EC 8006FB4C 0C00F5AC */  sw         $s5, 0xC($a3)
    /* C7F0 8006FB50 1000A524 */  addiu      $a1, $a1, 0x10
    /* C7F4 8006FB54 F6FFA414 */  bne        $a1, $a0, .L8006FB30
    /* C7F8 8006FB58 1000E724 */   addiu     $a3, $a3, 0x10
    /* C7FC 8006FB5C FF00043C */  lui        $a0, (0xFFFFFF >> 16)
    /* C800 8006FB60 FFFF8434 */  ori        $a0, $a0, (0xFFFFFF & 0xFFFF)
    /* C804 8006FB64 2800A627 */  addiu      $a2, $sp, 0x28
    /* C808 8006FB68 4800A827 */  addiu      $t0, $sp, 0x48
    /* C80C 8006FB6C 0000B28C */  lw         $s2, 0x0($a1)
    /* C810 8006FB70 0400B38C */  lw         $s3, 0x4($a1)
    /* C814 8006FB74 0000F2AC */  sw         $s2, 0x0($a3)
    /* C818 8006FB78 0400F3AC */  sw         $s3, 0x4($a3)
    /* C81C 8006FB7C 00FF053C */  lui        $a1, (0xFF000000 >> 16)
    /* C820 8006FB80 0000438D */  lw         $v1, 0x0($t2)
    /* C824 8006FB84 0000E28D */  lw         $v0, 0x0($t7)
    /* C828 8006FB88 24186500 */  and        $v1, $v1, $a1
    /* C82C 8006FB8C 24104400 */  and        $v0, $v0, $a0
    /* C830 8006FB90 25186200 */  or         $v1, $v1, $v0
    /* C834 8006FB94 24204401 */  and        $a0, $t2, $a0
    /* C838 8006FB98 000043AD */  sw         $v1, 0x0($t2)
    /* C83C 8006FB9C 28004A25 */  addiu      $t2, $t2, 0x28
    /* C840 8006FBA0 0000E28D */  lw         $v0, 0x0($t7)
    /* C844 8006FBA4 21184001 */  addu       $v1, $t2, $zero
    /* C848 8006FBA8 24104500 */  and        $v0, $v0, $a1
    /* C84C 8006FBAC 25104400 */  or         $v0, $v0, $a0
    /* C850 8006FBB0 0000E2AD */  sw         $v0, 0x0($t7)
  .L8006FBB4:
    /* C854 8006FBB4 0000D28C */  lw         $s2, 0x0($a2)
    /* C858 8006FBB8 0400D38C */  lw         $s3, 0x4($a2)
    /* C85C 8006FBBC 0800D48C */  lw         $s4, 0x8($a2)
    /* C860 8006FBC0 0C00D58C */  lw         $s5, 0xC($a2)
    /* C864 8006FBC4 000072AC */  sw         $s2, 0x0($v1)
    /* C868 8006FBC8 040073AC */  sw         $s3, 0x4($v1)
    /* C86C 8006FBCC 080074AC */  sw         $s4, 0x8($v1)
    /* C870 8006FBD0 0C0075AC */  sw         $s5, 0xC($v1)
    /* C874 8006FBD4 1000C624 */  addiu      $a2, $a2, 0x10
    /* C878 8006FBD8 F6FFC814 */  bne        $a2, $t0, .L8006FBB4
    /* C87C 8006FBDC 10006324 */   addiu     $v1, $v1, 0x10
    /* C880 8006FBE0 FF00043C */  lui        $a0, (0xFFFFFF >> 16)
    /* C884 8006FBE4 FFFF8434 */  ori        $a0, $a0, (0xFFFFFF & 0xFFFF)
    /* C888 8006FBE8 00FF053C */  lui        $a1, (0xFF000000 >> 16)
    /* C88C 8006FBEC 0000D28C */  lw         $s2, 0x0($a2)
    /* C890 8006FBF0 0400D38C */  lw         $s3, 0x4($a2)
    /* C894 8006FBF4 000072AC */  sw         $s2, 0x0($v1)
    /* C898 8006FBF8 040073AC */  sw         $s3, 0x4($v1)
    /* C89C 8006FBFC 0000438D */  lw         $v1, 0x0($t2)
    /* C8A0 8006FC00 0000E28D */  lw         $v0, 0x0($t7)
    /* C8A4 8006FC04 24186500 */  and        $v1, $v1, $a1
    /* C8A8 8006FC08 24104400 */  and        $v0, $v0, $a0
    /* C8AC 8006FC0C 25186200 */  or         $v1, $v1, $v0
    /* C8B0 8006FC10 24204401 */  and        $a0, $t2, $a0
    /* C8B4 8006FC14 000043AD */  sw         $v1, 0x0($t2)
    /* C8B8 8006FC18 0000E28D */  lw         $v0, 0x0($t7)
    /* C8BC 8006FC1C 28004A25 */  addiu      $t2, $t2, 0x28
    /* C8C0 8006FC20 24104500 */  and        $v0, $v0, $a1
    /* C8C4 8006FC24 25104400 */  or         $v0, $v0, $a0
    /* C8C8 8006FC28 0000E2AD */  sw         $v0, 0x0($t7)
    /* C8CC 8006FC2C 6400B58F */  lw         $s5, 0x64($sp)
    /* C8D0 8006FC30 6000B48F */  lw         $s4, 0x60($sp)
    /* C8D4 8006FC34 5C00B38F */  lw         $s3, 0x5C($sp)
    /* C8D8 8006FC38 5800B28F */  lw         $s2, 0x58($sp)
    /* C8DC 8006FC3C 5400B18F */  lw         $s1, 0x54($sp)
    /* C8E0 8006FC40 5000B08F */  lw         $s0, 0x50($sp)
    /* C8E4 8006FC44 0680023C */  lui        $v0, %hi(D_8005F79C)
    /* C8E8 8006FC48 9CF74AAC */  sw         $t2, %lo(D_8005F79C)($v0)
    /* C8EC 8006FC4C 0800E003 */  jr         $ra
    /* C8F0 8006FC50 6800BD27 */   addiu     $sp, $sp, 0x68
endlabel func_8006F86C
