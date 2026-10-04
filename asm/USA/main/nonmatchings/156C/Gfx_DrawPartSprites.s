nonmatching Gfx_DrawPartSprites, 0x268

glabel Gfx_DrawPartSprites
    /* D69C 8001CE9C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* D6A0 8001CEA0 1400B1AF */  sw         $s1, 0x14($sp)
    /* D6A4 8001CEA4 21888000 */  addu       $s1, $a0, $zero
    /* D6A8 8001CEA8 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* D6AC 8001CEAC 1800B2AF */  sw         $s2, 0x18($sp)
    /* D6B0 8001CEB0 1000B0AF */  sw         $s0, 0x10($sp)
    /* D6B4 8001CEB4 0000248E */  lw         $a0, 0x0($s1)
    /* D6B8 8001CEB8 688E000C */  jal        Cd_GetFileEntry
    /* D6BC 8001CEBC 2190A000 */   addu      $s2, $a1, $zero
    /* D6C0 8001CEC0 21804000 */  addu       $s0, $v0, $zero
    /* D6C4 8001CEC4 0000228E */  lw         $v0, 0x0($s1)
    /* D6C8 8001CEC8 FFFF043C */  lui        $a0, (0xFFFF0000 >> 16)
    /* D6CC 8001CECC E072000C */  jal        Gfx_FindOrLoadTexSlot
    /* D6D0 8001CED0 24204400 */   and       $a0, $v0, $a0
    /* D6D4 8001CED4 0680033C */  lui        $v1, %hi(Sys_PacketCursor)
    /* D6D8 8001CED8 21404000 */  addu       $t0, $v0, $zero
    /* D6DC 8001CEDC 9CF7678C */  lw         $a3, %lo(Sys_PacketCursor)($v1)
    /* D6E0 8001CEE0 00000392 */  lbu        $v1, 0x0($s0)
    /* D6E4 8001CEE4 FF000224 */  addiu      $v0, $zero, 0xFF
    /* D6E8 8001CEE8 7E006210 */  beq        $v1, $v0, .L8001D0E4
    /* D6EC 8001CEEC 00000000 */   nop
    /* D6F0 8001CEF0 FF00093C */  lui        $t1, (0xFFFFFF >> 16)
    /* D6F4 8001CEF4 FFFF2935 */  ori        $t1, $t1, (0xFFFFFF & 0xFFFF)
    /* D6F8 8001CEF8 00FF0B3C */  lui        $t3, (0xFF000000 >> 16)
    /* D6FC 8001CEFC 06000626 */  addiu      $a2, $s0, 0x6
    /* D700 8001CF00 0400E524 */  addiu      $a1, $a3, 0x4
  .L8001CF04:
    /* D704 8001CF04 0600C390 */  lbu        $v1, 0x6($a2)
    /* D708 8001CF08 0D002292 */  lbu        $v0, 0xD($s1)
    /* D70C 8001CF0C 00000000 */  nop
    /* D710 8001CF10 6F006214 */  bne        $v1, $v0, .L8001D0D0
    /* D714 8001CF14 04000224 */   addiu     $v0, $zero, 0x4
    /* D718 8001CF18 0B002C8A */  lwl        $t4, 0xB($s1)
    /* D71C 8001CF1C 08002C9A */  lwr        $t4, 0x8($s1)
    /* D720 8001CF20 00000000 */  nop
    /* D724 8001CF24 0300ACA8 */  swl        $t4, 0x3($a1)
    /* D728 8001CF28 0000ACB8 */  swr        $t4, 0x0($a1)
    /* D72C 8001CF2C FFFFA2A0 */  sb         $v0, -0x1($a1)
    /* D730 8001CF30 64000224 */  addiu      $v0, $zero, 0x64
    /* D734 8001CF34 0300A2A0 */  sb         $v0, 0x3($a1)
    /* D738 8001CF38 0500C290 */  lbu        $v0, 0x5($a2)
    /* D73C 8001CF3C 00000000 */  nop
    /* D740 8001CF40 80004230 */  andi       $v0, $v0, 0x80
    /* D744 8001CF44 08004010 */  beqz       $v0, .L8001CF68
    /* D748 8001CF48 66000224 */   addiu     $v0, $zero, 0x66
    /* D74C 8001CF4C 0300A2A0 */  sb         $v0, 0x3($a1)
    /* D750 8001CF50 0500C290 */  lbu        $v0, 0x5($a2)
    /* D754 8001CF54 10000395 */  lhu        $v1, 0x10($t0)
    /* D758 8001CF58 03004230 */  andi       $v0, $v0, 0x3
    /* D75C 8001CF5C 40110200 */  sll        $v0, $v0, 5
    /* D760 8001CF60 DB730008 */  j          .L8001CF6C
    /* D764 8001CF64 21506200 */   addu      $t2, $v1, $v0
  .L8001CF68:
    /* D768 8001CF68 10000A95 */  lhu        $t2, 0x10($t0)
  .L8001CF6C:
    /* D76C 8001CF6C FCFFC294 */  lhu        $v0, -0x4($a2)
    /* D770 8001CF70 04002396 */  lhu        $v1, 0x4($s1)
    /* D774 8001CF74 00000000 */  nop
    /* D778 8001CF78 21104300 */  addu       $v0, $v0, $v1
    /* D77C 8001CF7C 0400A2A4 */  sh         $v0, 0x4($a1)
    /* D780 8001CF80 00000292 */  lbu        $v0, 0x0($s0)
    /* D784 8001CF84 0C000391 */  lbu        $v1, 0xC($t0)
    /* D788 8001CF88 00000000 */  nop
    /* D78C 8001CF8C 21104300 */  addu       $v0, $v0, $v1
    /* D790 8001CF90 0800A2A0 */  sb         $v0, 0x8($a1)
    /* D794 8001CF94 0200C290 */  lbu        $v0, 0x2($a2)
    /* D798 8001CF98 00000000 */  nop
    /* D79C 8001CF9C 0C00A2A4 */  sh         $v0, 0xC($a1)
    /* D7A0 8001CFA0 FEFFC294 */  lhu        $v0, -0x2($a2)
    /* D7A4 8001CFA4 06002396 */  lhu        $v1, 0x6($s1)
    /* D7A8 8001CFA8 00000000 */  nop
    /* D7AC 8001CFAC 21104300 */  addu       $v0, $v0, $v1
    /* D7B0 8001CFB0 0600A2A4 */  sh         $v0, 0x6($a1)
    /* D7B4 8001CFB4 FBFFC290 */  lbu        $v0, -0x5($a2)
    /* D7B8 8001CFB8 00000000 */  nop
    /* D7BC 8001CFBC 0900A2A0 */  sb         $v0, 0x9($a1)
    /* D7C0 8001CFC0 0300C290 */  lbu        $v0, 0x3($a2)
    /* D7C4 8001CFC4 00000000 */  nop
    /* D7C8 8001CFC8 03004014 */  bnez       $v0, .L8001CFD8
    /* D7CC 8001CFCC 0E00A2A4 */   sh        $v0, 0xE($a1)
    /* D7D0 8001CFD0 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* D7D4 8001CFD4 0E00A2A4 */  sh         $v0, 0xE($a1)
  .L8001CFD8:
    /* D7D8 8001CFD8 0800028D */  lw         $v0, 0x8($t0)
    /* D7DC 8001CFDC 00000000 */  nop
    /* D7E0 8001CFE0 0A004010 */  beqz       $v0, .L8001D00C
    /* D7E4 8001CFE4 00000000 */   nop
    /* D7E8 8001CFE8 14000495 */  lhu        $a0, 0x14($t0)
    /* D7EC 8001CFEC 0400C390 */  lbu        $v1, 0x4($a2)
    /* D7F0 8001CFF0 0C002292 */  lbu        $v0, 0xC($s1)
    /* D7F4 8001CFF4 E0018424 */  addiu      $a0, $a0, 0x1E0
    /* D7F8 8001CFF8 21186400 */  addu       $v1, $v1, $a0
    /* D7FC 8001CFFC 21104300 */  addu       $v0, $v0, $v1
    /* D800 8001D000 80110200 */  sll        $v0, $v0, 6
    /* D804 8001D004 13740008 */  j          .L8001D04C
    /* D808 8001D008 0A00A2A4 */   sh        $v0, 0xA($a1)
  .L8001D00C:
    /* D80C 8001D00C 0100C490 */  lbu        $a0, 0x1($a2)
    /* D810 8001D010 1C000295 */  lhu        $v0, 0x1C($t0)
    /* D814 8001D014 00000000 */  nop
    /* D818 8001D018 21208200 */  addu       $a0, $a0, $v0
    /* D81C 8001D01C 0400C290 */  lbu        $v0, 0x4($a2)
    /* D820 8001D020 0C002392 */  lbu        $v1, 0xC($s1)
    /* D824 8001D024 21104400 */  addu       $v0, $v0, $a0
    /* D828 8001D028 21186200 */  addu       $v1, $v1, $v0
    /* D82C 8001D02C 0000C290 */  lbu        $v0, 0x0($a2)
    /* D830 8001D030 1800048D */  lw         $a0, 0x18($t0)
    /* D834 8001D034 80190300 */  sll        $v1, $v1, 6
    /* D838 8001D038 21104400 */  addu       $v0, $v0, $a0
    /* D83C 8001D03C 03110200 */  sra        $v0, $v0, 4
    /* D840 8001D040 3F004230 */  andi       $v0, $v0, 0x3F
    /* D844 8001D044 25186200 */  or         $v1, $v1, $v0
    /* D848 8001D048 0A00A3A4 */  sh         $v1, 0xA($a1)
  .L8001D04C:
    /* D84C 8001D04C 1400A524 */  addiu      $a1, $a1, 0x14
    /* D850 8001D050 00E1043C */  lui        $a0, (0xE1000600 >> 16)
    /* D854 8001D054 00068434 */  ori        $a0, $a0, (0xE1000600 & 0xFFFF)
    /* D858 8001D058 0000E38C */  lw         $v1, 0x0($a3)
    /* D85C 8001D05C 0000428E */  lw         $v0, 0x0($s2)
    /* D860 8001D060 24186B00 */  and        $v1, $v1, $t3
    /* D864 8001D064 24104900 */  and        $v0, $v0, $t1
    /* D868 8001D068 25186200 */  or         $v1, $v1, $v0
    /* D86C 8001D06C 0000E3AC */  sw         $v1, 0x0($a3)
    /* D870 8001D070 2418E900 */  and        $v1, $a3, $t1
    /* D874 8001D074 0000428E */  lw         $v0, 0x0($s2)
    /* D878 8001D078 1400E724 */  addiu      $a3, $a3, 0x14
    /* D87C 8001D07C 24104B00 */  and        $v0, $v0, $t3
    /* D880 8001D080 25104300 */  or         $v0, $v0, $v1
    /* D884 8001D084 000042AE */  sw         $v0, 0x0($s2)
    /* D888 8001D088 01000224 */  addiu      $v0, $zero, 0x1
    /* D88C 8001D08C FFFFA2A0 */  sb         $v0, -0x1($a1)
    /* D890 8001D090 FF094231 */  andi       $v0, $t2, 0x9FF
    /* D894 8001D094 25104400 */  or         $v0, $v0, $a0
    /* D898 8001D098 0000A2AC */  sw         $v0, 0x0($a1)
    /* D89C 8001D09C 0800A524 */  addiu      $a1, $a1, 0x8
    /* D8A0 8001D0A0 0000E38C */  lw         $v1, 0x0($a3)
    /* D8A4 8001D0A4 0000428E */  lw         $v0, 0x0($s2)
    /* D8A8 8001D0A8 24186B00 */  and        $v1, $v1, $t3
    /* D8AC 8001D0AC 24104900 */  and        $v0, $v0, $t1
    /* D8B0 8001D0B0 25186200 */  or         $v1, $v1, $v0
    /* D8B4 8001D0B4 0000E3AC */  sw         $v1, 0x0($a3)
    /* D8B8 8001D0B8 2418E900 */  and        $v1, $a3, $t1
    /* D8BC 8001D0BC 0000428E */  lw         $v0, 0x0($s2)
    /* D8C0 8001D0C0 0800E724 */  addiu      $a3, $a3, 0x8
    /* D8C4 8001D0C4 24104B00 */  and        $v0, $v0, $t3
    /* D8C8 8001D0C8 25104300 */  or         $v0, $v0, $v1
    /* D8CC 8001D0CC 000042AE */  sw         $v0, 0x0($s2)
  .L8001D0D0:
    /* D8D0 8001D0D0 10001026 */  addiu      $s0, $s0, 0x10
    /* D8D4 8001D0D4 00000392 */  lbu        $v1, 0x0($s0)
    /* D8D8 8001D0D8 FF000224 */  addiu      $v0, $zero, 0xFF
    /* D8DC 8001D0DC 89FF6214 */  bne        $v1, $v0, .L8001CF04
    /* D8E0 8001D0E0 1000C624 */   addiu     $a2, $a2, 0x10
  .L8001D0E4:
    /* D8E4 8001D0E4 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* D8E8 8001D0E8 1800B28F */  lw         $s2, 0x18($sp)
    /* D8EC 8001D0EC 1400B18F */  lw         $s1, 0x14($sp)
    /* D8F0 8001D0F0 1000B08F */  lw         $s0, 0x10($sp)
    /* D8F4 8001D0F4 0680023C */  lui        $v0, %hi(Sys_PacketCursor)
    /* D8F8 8001D0F8 9CF747AC */  sw         $a3, %lo(Sys_PacketCursor)($v0)
    /* D8FC 8001D0FC 0800E003 */  jr         $ra
    /* D900 8001D100 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Gfx_DrawPartSprites
