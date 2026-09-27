nonmatching func_8001A01C, 0x2E4

glabel func_8001A01C
    /* A81C 8001A01C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* A820 8001A020 1800B2AF */  sw         $s2, 0x18($sp)
    /* A824 8001A024 21900000 */  addu       $s2, $zero, $zero
    /* A828 8001A028 0480023C */  lui        $v0, %hi(D_80041194)
    /* A82C 8001A02C 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* A830 8001A030 94115324 */  addiu      $s3, $v0, %lo(D_80041194)
    /* A834 8001A034 2000B4AF */  sw         $s4, 0x20($sp)
    /* A838 8001A038 21A04002 */  addu       $s4, $s2, $zero
    /* A83C 8001A03C 2400BFAF */  sw         $ra, 0x24($sp)
    /* A840 8001A040 1400B1AF */  sw         $s1, 0x14($sp)
    /* A844 8001A044 1000B0AF */  sw         $s0, 0x10($sp)
  .L8001A048:
    /* A848 8001A048 0580023C */  lui        $v0, %hi(D_80054C48)
    /* A84C 8001A04C 484C4224 */  addiu      $v0, $v0, %lo(D_80054C48)
    /* A850 8001A050 21808202 */  addu       $s0, $s4, $v0
    /* A854 8001A054 0400038E */  lw         $v1, 0x4($s0)
    /* A858 8001A058 00000000 */  nop
    /* A85C 8001A05C 0800622C */  sltiu      $v0, $v1, 0x8
    /* A860 8001A060 91004010 */  beqz       $v0, .L8001A2A8
    /* A864 8001A064 0180023C */   lui       $v0, %hi(jtbl_8001012C)
    /* A868 8001A068 2C014224 */  addiu      $v0, $v0, %lo(jtbl_8001012C)
    /* A86C 8001A06C 80180300 */  sll        $v1, $v1, 2
    /* A870 8001A070 21186200 */  addu       $v1, $v1, $v0
    /* A874 8001A074 0000628C */  lw         $v0, 0x0($v1)
    /* A878 8001A078 00000000 */  nop
    /* A87C 8001A07C 08004000 */  jr         $v0
    /* A880 8001A080 00000000 */   nop
  jlabel .L8001A084
    /* A884 8001A084 0000028E */  lw         $v0, 0x0($s0)
    /* A888 8001A088 00000000 */  nop
    /* A88C 8001A08C 8E004010 */  beqz       $v0, .L8001A2C8
    /* A890 8001A090 80100200 */   sll       $v0, $v0, 2
    /* A894 8001A094 21105300 */  addu       $v0, $v0, $s3
    /* A898 8001A098 0000428C */  lw         $v0, 0x0($v0)
    /* A89C 8001A09C 00000000 */  nop
    /* A8A0 8001A0A0 02004394 */  lhu        $v1, 0x2($v0)
    /* A8A4 8001A0A4 0000028E */  lw         $v0, 0x0($s0)
    /* A8A8 8001A0A8 00000000 */  nop
    /* A8AC 8001A0AC 80100200 */  sll        $v0, $v0, 2
    /* A8B0 8001A0B0 21105300 */  addu       $v0, $v0, $s3
    /* A8B4 8001A0B4 200003AE */  sw         $v1, 0x20($s0)
    /* A8B8 8001A0B8 0000428C */  lw         $v0, 0x0($v0)
    /* A8BC 8001A0BC 00000000 */  nop
    /* A8C0 8001A0C0 06004494 */  lhu        $a0, 0x6($v0)
    /* A8C4 8001A0C4 FD8E000C */  jal        Cd_QueueFile
    /* A8C8 8001A0C8 240004AE */   sw        $a0, 0x24($s0)
    /* A8CC 8001A0CC A5680008 */  j          .L8001A294
    /* A8D0 8001A0D0 00000000 */   nop
  jlabel .L8001A0D4
    /* A8D4 8001A0D4 2400048E */  lw         $a0, 0x24($s0)
    /* A8D8 8001A0D8 DC8E000C */  jal        Cd_GetFileState
    /* A8DC 8001A0DC 00000000 */   nop
    /* A8E0 8001A0E0 03000324 */  addiu      $v1, $zero, 0x3
    /* A8E4 8001A0E4 79004314 */  bne        $v0, $v1, .L8001A2CC
    /* A8E8 8001A0E8 00000000 */   nop
    /* A8EC 8001A0EC 2400048E */  lw         $a0, 0x24($s0)
    /* A8F0 8001A0F0 6C8F000C */  jal        func_80023DB0
    /* A8F4 8001A0F4 00000000 */   nop
    /* A8F8 8001A0F8 21384000 */  addu       $a3, $v0, $zero
    /* A8FC 8001A0FC 1F80043C */  lui        $a0, (0x801FFFFF >> 16)
    /* A900 8001A100 FFFF8434 */  ori        $a0, $a0, (0x801FFFFF & 0xFFFF)
    /* A904 8001A104 0480033C */  lui        $v1, %hi(D_800411FC)
    /* A908 8001A108 FC116324 */  addiu      $v1, $v1, %lo(D_800411FC)
    /* A90C 8001A10C 80101200 */  sll        $v0, $s2, 2
    /* A910 8001A110 21104300 */  addu       $v0, $v0, $v1
    /* A914 8001A114 0000458C */  lw         $a1, 0x0($v0)
    /* A918 8001A118 2800068E */  lw         $a2, 0x28($s0)
    /* A91C 8001A11C 2110E500 */  addu       $v0, $a3, $a1
    /* A920 8001A120 2B208200 */  sltu       $a0, $a0, $v0
    /* A924 8001A124 03008010 */  beqz       $a0, .L8001A134
    /* A928 8001A128 1F80023C */   lui       $v0, (0x801FFFFC >> 16)
    /* A92C 8001A12C FCFF4234 */  ori        $v0, $v0, (0x801FFFFC & 0xFFFF)
    /* A930 8001A130 23284700 */  subu       $a1, $v0, $a3
  .L8001A134:
    /* A934 8001A134 82280500 */  srl        $a1, $a1, 2
    /* A938 8001A138 5600A010 */  beqz       $a1, .L8001A294
    /* A93C 8001A13C 21180000 */   addu      $v1, $zero, $zero
  .L8001A140:
    /* A940 8001A140 0000E28C */  lw         $v0, 0x0($a3)
    /* A944 8001A144 0400E724 */  addiu      $a3, $a3, 0x4
    /* A948 8001A148 01006324 */  addiu      $v1, $v1, 0x1
    /* A94C 8001A14C 0000C2AC */  sw         $v0, 0x0($a2)
    /* A950 8001A150 2B106500 */  sltu       $v0, $v1, $a1
    /* A954 8001A154 FAFF4014 */  bnez       $v0, .L8001A140
    /* A958 8001A158 0400C624 */   addiu     $a2, $a2, 0x4
    /* A95C 8001A15C A5680008 */  j          .L8001A294
    /* A960 8001A160 00000000 */   nop
  jlabel .L8001A164
    /* A964 8001A164 2000048E */  lw         $a0, 0x20($s0)
    /* A968 8001A168 FD8E000C */  jal        Cd_QueueFile
    /* A96C 8001A16C 00000000 */   nop
    /* A970 8001A170 A5680008 */  j          .L8001A294
    /* A974 8001A174 00000000 */   nop
  jlabel .L8001A178
    /* A978 8001A178 0000028E */  lw         $v0, 0x0($s0)
    /* A97C 8001A17C 00000000 */  nop
    /* A980 8001A180 80100200 */  sll        $v0, $v0, 2
    /* A984 8001A184 21105300 */  addu       $v0, $v0, $s3
    /* A988 8001A188 0000428C */  lw         $v0, 0x0($v0)
    /* A98C 8001A18C 2800058E */  lw         $a1, 0x28($s0)
    /* A990 8001A190 0400448C */  lw         $a0, 0x4($v0)
    /* A994 8001A194 798E000C */  jal        Mem_GetOffsetEntry
    /* A998 8001A198 00000000 */   nop
    /* A99C 8001A19C 21204000 */  addu       $a0, $v0, $zero
    /* A9A0 8001A1A0 002C1200 */  sll        $a1, $s2, 16
    /* A9A4 8001A1A4 91E6000C */  jal        SsVabOpenHead
    /* A9A8 8001A1A8 032C0500 */   sra       $a1, $a1, 16
    /* A9AC 8001A1AC 82680008 */  j          .L8001A208
    /* A9B0 8001A1B0 00000000 */   nop
  jlabel .L8001A1B4
    /* A9B4 8001A1B4 2000048E */  lw         $a0, 0x20($s0)
    /* A9B8 8001A1B8 DC8E000C */  jal        Cd_GetFileState
    /* A9BC 8001A1BC 00000000 */   nop
    /* A9C0 8001A1C0 03000324 */  addiu      $v1, $zero, 0x3
    /* A9C4 8001A1C4 41004314 */  bne        $v0, $v1, .L8001A2CC
    /* A9C8 8001A1C8 00000000 */   nop
    /* A9CC 8001A1CC 2000048E */  lw         $a0, 0x20($s0)
    /* A9D0 8001A1D0 9E8F000C */  jal        Cd_LockFile
    /* A9D4 8001A1D4 00000000 */   nop
    /* A9D8 8001A1D8 0000028E */  lw         $v0, 0x0($s0)
    /* A9DC 8001A1DC 00000000 */  nop
    /* A9E0 8001A1E0 80100200 */  sll        $v0, $v0, 2
    /* A9E4 8001A1E4 21105300 */  addu       $v0, $v0, $s3
    /* A9E8 8001A1E8 0000428C */  lw         $v0, 0x0($v0)
    /* A9EC 8001A1EC 00000000 */  nop
    /* A9F0 8001A1F0 0000448C */  lw         $a0, 0x0($v0)
    /* A9F4 8001A1F4 688E000C */  jal        func_800239A0
    /* A9F8 8001A1F8 00000000 */   nop
    /* A9FC 8001A1FC 08000586 */  lh         $a1, 0x8($s0)
    /* AA00 8001A200 D1E7000C */  jal        func_80039F44
    /* AA04 8001A204 21204000 */   addu      $a0, $v0, $zero
  .L8001A208:
    /* AA08 8001A208 0400038E */  lw         $v1, 0x4($s0)
    /* AA0C 8001A20C 080002A6 */  sh         $v0, 0x8($s0)
    /* AA10 8001A210 01006324 */  addiu      $v1, $v1, 0x1
    /* AA14 8001A214 B3680008 */  j          .L8001A2CC
    /* AA18 8001A218 040003AE */   sw        $v1, 0x4($s0)
  jlabel .L8001A21C
    /* AA1C 8001A21C 0400028E */  lw         $v0, 0x4($s0)
    /* AA20 8001A220 0A0000A6 */  sh         $zero, 0xA($s0)
    /* AA24 8001A224 01004224 */  addiu      $v0, $v0, 0x1
    /* AA28 8001A228 040002AE */  sw         $v0, 0x4($s0)
  jlabel .L8001A22C
    /* AA2C 8001A22C 0000028E */  lw         $v0, 0x0($s0)
    /* AA30 8001A230 0A001186 */  lh         $s1, 0xA($s0)
    /* AA34 8001A234 80100200 */  sll        $v0, $v0, 2
    /* AA38 8001A238 21105300 */  addu       $v0, $v0, $s3
    /* AA3C 8001A23C 0000438C */  lw         $v1, 0x0($v0)
    /* AA40 8001A240 80101100 */  sll        $v0, $s1, 2
    /* AA44 8001A244 21104300 */  addu       $v0, $v0, $v1
    /* AA48 8001A248 0800448C */  lw         $a0, 0x8($v0)
    /* AA4C 8001A24C 00000000 */  nop
    /* AA50 8001A250 10008010 */  beqz       $a0, .L8001A294
    /* AA54 8001A254 00000000 */   nop
    /* AA58 8001A258 2800058E */  lw         $a1, 0x28($s0)
    /* AA5C 8001A25C 798E000C */  jal        Mem_GetOffsetEntry
    /* AA60 8001A260 2C009426 */   addiu     $s4, $s4, 0x2C
    /* AA64 8001A264 21204000 */  addu       $a0, $v0, $zero
    /* AA68 8001A268 08000586 */  lh         $a1, 0x8($s0)
    /* AA6C 8001A26C 55CA000C */  jal        SsSepOpen
    /* AA70 8001A270 10000624 */   addiu     $a2, $zero, 0x10
    /* AA74 8001A274 40181100 */  sll        $v1, $s1, 1
    /* AA78 8001A278 21180302 */  addu       $v1, $s0, $v1
    /* AA7C 8001A27C 0C0062A4 */  sh         $v0, 0xC($v1)
    /* AA80 8001A280 0A000296 */  lhu        $v0, 0xA($s0)
    /* AA84 8001A284 00000000 */  nop
    /* AA88 8001A288 01004224 */  addiu      $v0, $v0, 0x1
    /* AA8C 8001A28C B4680008 */  j          .L8001A2D0
    /* AA90 8001A290 0A0002A6 */   sh        $v0, 0xA($s0)
  .L8001A294:
    /* AA94 8001A294 0400028E */  lw         $v0, 0x4($s0)
    /* AA98 8001A298 00000000 */  nop
    /* AA9C 8001A29C 01004224 */  addiu      $v0, $v0, 0x1
    /* AAA0 8001A2A0 B3680008 */  j          .L8001A2CC
    /* AAA4 8001A2A4 040002AE */   sw        $v0, 0x4($s0)
  .L8001A2A8:
    /* AAA8 8001A2A8 01E8000C */  jal        SsVabTransCompleted
    /* AAAC 8001A2AC 21200000 */   addu      $a0, $zero, $zero
    /* AAB0 8001A2B0 00140200 */  sll        $v0, $v0, 16
    /* AAB4 8001A2B4 05004010 */  beqz       $v0, .L8001A2CC
    /* AAB8 8001A2B8 00000000 */   nop
    /* AABC 8001A2BC 2000048E */  lw         $a0, 0x20($s0)
    /* AAC0 8001A2C0 AE8F000C */  jal        Cd_UnlockFile
    /* AAC4 8001A2C4 00000000 */   nop
  .L8001A2C8:
    /* AAC8 8001A2C8 040000AE */  sw         $zero, 0x4($s0)
  jlabel .L8001A2CC
    /* AACC 8001A2CC 2C009426 */  addiu      $s4, $s4, 0x2C
  .L8001A2D0:
    /* AAD0 8001A2D0 01005226 */  addiu      $s2, $s2, 0x1
    /* AAD4 8001A2D4 0300422A */  slti       $v0, $s2, 0x3
    /* AAD8 8001A2D8 5BFF4014 */  bnez       $v0, .L8001A048
    /* AADC 8001A2DC 00000000 */   nop
    /* AAE0 8001A2E0 2400BF8F */  lw         $ra, 0x24($sp)
    /* AAE4 8001A2E4 2000B48F */  lw         $s4, 0x20($sp)
    /* AAE8 8001A2E8 1C00B38F */  lw         $s3, 0x1C($sp)
    /* AAEC 8001A2EC 1800B28F */  lw         $s2, 0x18($sp)
    /* AAF0 8001A2F0 1400B18F */  lw         $s1, 0x14($sp)
    /* AAF4 8001A2F4 1000B08F */  lw         $s0, 0x10($sp)
    /* AAF8 8001A2F8 0800E003 */  jr         $ra
    /* AAFC 8001A2FC 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8001A01C
