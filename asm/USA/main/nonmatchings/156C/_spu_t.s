nonmatching _spu_t, 0x280

glabel _spu_t
    /* 2AF78 8003A778 0000A4AF */  sw         $a0, 0x0($sp)
    /* 2AF7C 8003A77C 0400A5AF */  sw         $a1, 0x4($sp)
    /* 2AF80 8003A780 0800A6AF */  sw         $a2, 0x8($sp)
    /* 2AF84 8003A784 0C00A7AF */  sw         $a3, 0xC($sp)
    /* 2AF88 8003A788 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2AF8C 8003A78C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2AF90 8003A790 1C00B027 */  addiu      $s0, $sp, 0x1C
    /* 2AF94 8003A794 01000624 */  addiu      $a2, $zero, 0x1
    /* 2AF98 8003A798 1400BFAF */  sw         $ra, 0x14($sp)
    /* 2AF9C 8003A79C 19008610 */  beq        $a0, $a2, .L8003A804
    /* 2AFA0 8003A7A0 1800A4AF */   sw        $a0, 0x18($sp)
    /* 2AFA4 8003A7A4 02008228 */  slti       $v0, $a0, 0x2
    /* 2AFA8 8003A7A8 05004010 */  beqz       $v0, .L8003A7C0
    /* 2AFAC 8003A7AC 02000224 */   addiu     $v0, $zero, 0x2
    /* 2AFB0 8003A7B0 2F008010 */  beqz       $a0, .L8003A870
    /* 2AFB4 8003A7B4 21100000 */   addu      $v0, $zero, $zero
    /* 2AFB8 8003A7B8 7AEA0008 */  j          .L8003A9E8
    /* 2AFBC 8003A7BC 00000000 */   nop
  .L8003A7C0:
    /* 2AFC0 8003A7C0 05008210 */  beq        $a0, $v0, .L8003A7D8
    /* 2AFC4 8003A7C4 03000224 */   addiu     $v0, $zero, 0x3
    /* 2AFC8 8003A7C8 43008210 */  beq        $a0, $v0, .L8003A8D8
    /* 2AFCC 8003A7CC 21100000 */   addu      $v0, $zero, $zero
    /* 2AFD0 8003A7D0 7AEA0008 */  j          .L8003A9E8
    /* 2AFD4 8003A7D4 00000000 */   nop
  .L8003A7D8:
    /* 2AFD8 8003A7D8 1C00A48F */  lw         $a0, 0x1C($sp)
    /* 2AFDC 8003A7DC 0580023C */  lui        $v0, %hi(D_8004FE50)
    /* 2AFE0 8003A7E0 50FE428C */  lw         $v0, %lo(D_8004FE50)($v0)
    /* 2AFE4 8003A7E4 0580033C */  lui        $v1, %hi(D_8004FE28)
    /* 2AFE8 8003A7E8 28FE638C */  lw         $v1, %lo(D_8004FE28)($v1)
    /* 2AFEC 8003A7EC 06104400 */  srlv       $v0, $a0, $v0
    /* 2AFF0 8003A7F0 0580013C */  lui        $at, %hi(D_8004FE40)
    /* 2AFF4 8003A7F4 40FE22A4 */  sh         $v0, %lo(D_8004FE40)($at)
    /* 2AFF8 8003A7F8 A60162A4 */  sh         $v0, 0x1A6($v1)
    /* 2AFFC 8003A7FC 7AEA0008 */  j          .L8003A9E8
    /* 2B000 8003A800 21100000 */   addu      $v0, $zero, $zero
  .L8003A804:
    /* 2B004 8003A804 0580053C */  lui        $a1, %hi(D_8004FE28)
    /* 2B008 8003A808 28FEA58C */  lw         $a1, %lo(D_8004FE28)($a1)
    /* 2B00C 8003A80C 0580043C */  lui        $a0, %hi(D_8004FE40)
    /* 2B010 8003A810 40FE8494 */  lhu        $a0, %lo(D_8004FE40)($a0)
    /* 2B014 8003A814 A601A294 */  lhu        $v0, 0x1A6($a1)
    /* 2B018 8003A818 0580013C */  lui        $at, %hi(D_8004FE78)
    /* 2B01C 8003A81C 78FE20AC */  sw         $zero, %lo(D_8004FE78)($at)
    /* 2B020 8003A820 09004410 */  beq        $v0, $a0, .L8003A848
    /* 2B024 8003A824 21180000 */   addu      $v1, $zero, $zero
    /* 2B028 8003A828 01006324 */  addiu      $v1, $v1, 0x1
  .L8003A82C:
    /* 2B02C 8003A82C 010F622C */  sltiu      $v0, $v1, 0xF01
    /* 2B030 8003A830 6D004010 */  beqz       $v0, .L8003A9E8
    /* 2B034 8003A834 FEFF0224 */   addiu     $v0, $zero, -0x2
    /* 2B038 8003A838 A601A294 */  lhu        $v0, 0x1A6($a1)
    /* 2B03C 8003A83C 00000000 */  nop
    /* 2B040 8003A840 FAFF4414 */  bne        $v0, $a0, .L8003A82C
    /* 2B044 8003A844 01006324 */   addiu     $v1, $v1, 0x1
  .L8003A848:
    /* 2B048 8003A848 0580033C */  lui        $v1, %hi(D_8004FE28)
    /* 2B04C 8003A84C 28FE638C */  lw         $v1, %lo(D_8004FE28)($v1)
    /* 2B050 8003A850 00000000 */  nop
    /* 2B054 8003A854 AA016294 */  lhu        $v0, 0x1AA($v1)
    /* 2B058 8003A858 00000000 */  nop
    /* 2B05C 8003A85C CFFF4230 */  andi       $v0, $v0, 0xFFCF
    /* 2B060 8003A860 20004234 */  ori        $v0, $v0, 0x20
    /* 2B064 8003A864 AA0162A4 */  sh         $v0, 0x1AA($v1)
    /* 2B068 8003A868 7AEA0008 */  j          .L8003A9E8
    /* 2B06C 8003A86C 21100000 */   addu      $v0, $zero, $zero
  .L8003A870:
    /* 2B070 8003A870 0580053C */  lui        $a1, %hi(D_8004FE28)
    /* 2B074 8003A874 28FEA58C */  lw         $a1, %lo(D_8004FE28)($a1)
    /* 2B078 8003A878 0580043C */  lui        $a0, %hi(D_8004FE40)
    /* 2B07C 8003A87C 40FE8494 */  lhu        $a0, %lo(D_8004FE40)($a0)
    /* 2B080 8003A880 A601A294 */  lhu        $v0, 0x1A6($a1)
    /* 2B084 8003A884 0580013C */  lui        $at, %hi(D_8004FE78)
    /* 2B088 8003A888 78FE26AC */  sw         $a2, %lo(D_8004FE78)($at)
    /* 2B08C 8003A88C 09004410 */  beq        $v0, $a0, .L8003A8B4
    /* 2B090 8003A890 21180000 */   addu      $v1, $zero, $zero
    /* 2B094 8003A894 01006324 */  addiu      $v1, $v1, 0x1
  .L8003A898:
    /* 2B098 8003A898 010F622C */  sltiu      $v0, $v1, 0xF01
    /* 2B09C 8003A89C 52004010 */  beqz       $v0, .L8003A9E8
    /* 2B0A0 8003A8A0 FEFF0224 */   addiu     $v0, $zero, -0x2
    /* 2B0A4 8003A8A4 A601A294 */  lhu        $v0, 0x1A6($a1)
    /* 2B0A8 8003A8A8 00000000 */  nop
    /* 2B0AC 8003A8AC FAFF4414 */  bne        $v0, $a0, .L8003A898
    /* 2B0B0 8003A8B0 01006324 */   addiu     $v1, $v1, 0x1
  .L8003A8B4:
    /* 2B0B4 8003A8B4 0580033C */  lui        $v1, %hi(D_8004FE28)
    /* 2B0B8 8003A8B8 28FE638C */  lw         $v1, %lo(D_8004FE28)($v1)
    /* 2B0BC 8003A8BC 00000000 */  nop
    /* 2B0C0 8003A8C0 AA016294 */  lhu        $v0, 0x1AA($v1)
    /* 2B0C4 8003A8C4 00000000 */  nop
    /* 2B0C8 8003A8C8 30004234 */  ori        $v0, $v0, 0x30
    /* 2B0CC 8003A8CC AA0162A4 */  sh         $v0, 0x1AA($v1)
    /* 2B0D0 8003A8D0 7AEA0008 */  j          .L8003A9E8
    /* 2B0D4 8003A8D4 21100000 */   addu      $v0, $zero, $zero
  .L8003A8D8:
    /* 2B0D8 8003A8D8 0580023C */  lui        $v0, %hi(D_8004FE78)
    /* 2B0DC 8003A8DC 78FE428C */  lw         $v0, %lo(D_8004FE78)($v0)
    /* 2B0E0 8003A8E0 00000000 */  nop
    /* 2B0E4 8003A8E4 02004614 */  bne        $v0, $a2, .L8003A8F0
    /* 2B0E8 8003A8E8 20000424 */   addiu     $a0, $zero, 0x20
    /* 2B0EC 8003A8EC 30000424 */  addiu      $a0, $zero, 0x30
  .L8003A8F0:
    /* 2B0F0 8003A8F0 0580053C */  lui        $a1, %hi(D_8004FE28)
    /* 2B0F4 8003A8F4 28FEA58C */  lw         $a1, %lo(D_8004FE28)($a1)
    /* 2B0F8 8003A8F8 21180000 */  addu       $v1, $zero, $zero
    /* 2B0FC 8003A8FC AA01A294 */  lhu        $v0, 0x1AA($a1)
    /* 2B100 8003A900 FFFF8430 */  andi       $a0, $a0, 0xFFFF
    /* 2B104 8003A904 30004230 */  andi       $v0, $v0, 0x30
    /* 2B108 8003A908 09004410 */  beq        $v0, $a0, .L8003A930
    /* 2B10C 8003A90C 01006324 */   addiu     $v1, $v1, 0x1
  .L8003A910:
    /* 2B110 8003A910 010F622C */  sltiu      $v0, $v1, 0xF01
    /* 2B114 8003A914 34004010 */  beqz       $v0, .L8003A9E8
    /* 2B118 8003A918 FEFF0224 */   addiu     $v0, $zero, -0x2
    /* 2B11C 8003A91C AA01A294 */  lhu        $v0, 0x1AA($a1)
    /* 2B120 8003A920 00000000 */  nop
    /* 2B124 8003A924 30004230 */  andi       $v0, $v0, 0x30
    /* 2B128 8003A928 F9FF4414 */  bne        $v0, $a0, .L8003A910
    /* 2B12C 8003A92C 01006324 */   addiu     $v1, $v1, 0x1
  .L8003A930:
    /* 2B130 8003A930 0580033C */  lui        $v1, %hi(D_8004FE78)
    /* 2B134 8003A934 78FE638C */  lw         $v1, %lo(D_8004FE78)($v1)
    /* 2B138 8003A938 01000224 */  addiu      $v0, $zero, 0x1
    /* 2B13C 8003A93C 05006214 */  bne        $v1, $v0, .L8003A954
    /* 2B140 8003A940 00000000 */   nop
    /* 2B144 8003A944 21EB000C */  jal        _spu_FsetDelayR
    /* 2B148 8003A948 04001026 */   addiu     $s0, $s0, 0x4
    /* 2B14C 8003A94C 58EA0008 */  j          .L8003A960
    /* 2B150 8003A950 0001063C */   lui       $a2, (0x1000201 >> 16)
  .L8003A954:
    /* 2B154 8003A954 17EB000C */  jal        _spu_FsetDelayW
    /* 2B158 8003A958 04001026 */   addiu     $s0, $s0, 0x4
    /* 2B15C 8003A95C 0001063C */  lui        $a2, (0x1000201 >> 16)
  .L8003A960:
    /* 2B160 8003A960 FCFF048E */  lw         $a0, -0x4($s0)
    /* 2B164 8003A964 0580013C */  lui        $at, %hi(D_8004FE7C)
    /* 2B168 8003A968 7CFE24AC */  sw         $a0, %lo(D_8004FE7C)($at)
    /* 2B16C 8003A96C 0000048E */  lw         $a0, 0x0($s0)
    /* 2B170 8003A970 0580053C */  lui        $a1, %hi(D_8004FE2C)
    /* 2B174 8003A974 2CFEA58C */  lw         $a1, %lo(D_8004FE2C)($a1)
    /* 2B178 8003A978 82190400 */  srl        $v1, $a0, 6
    /* 2B17C 8003A97C 3F008230 */  andi       $v0, $a0, 0x3F
    /* 2B180 8003A980 2B100200 */  sltu       $v0, $zero, $v0
    /* 2B184 8003A984 0580043C */  lui        $a0, %hi(D_8004FE7C)
    /* 2B188 8003A988 7CFE848C */  lw         $a0, %lo(D_8004FE7C)($a0)
    /* 2B18C 8003A98C 21186200 */  addu       $v1, $v1, $v0
    /* 2B190 8003A990 0580013C */  lui        $at, %hi(D_8004FE80)
    /* 2B194 8003A994 80FE23AC */  sw         $v1, %lo(D_8004FE80)($at)
    /* 2B198 8003A998 0000A4AC */  sw         $a0, 0x0($a1)
    /* 2B19C 8003A99C 0580023C */  lui        $v0, %hi(D_8004FE80)
    /* 2B1A0 8003A9A0 80FE428C */  lw         $v0, %lo(D_8004FE80)($v0)
    /* 2B1A4 8003A9A4 0580033C */  lui        $v1, %hi(D_8004FE30)
    /* 2B1A8 8003A9A8 30FE638C */  lw         $v1, %lo(D_8004FE30)($v1)
    /* 2B1AC 8003A9AC 00140200 */  sll        $v0, $v0, 16
    /* 2B1B0 8003A9B0 10004234 */  ori        $v0, $v0, 0x10
    /* 2B1B4 8003A9B4 000062AC */  sw         $v0, 0x0($v1)
    /* 2B1B8 8003A9B8 0580033C */  lui        $v1, %hi(D_8004FE78)
    /* 2B1BC 8003A9BC 78FE638C */  lw         $v1, %lo(D_8004FE78)($v1)
    /* 2B1C0 8003A9C0 01000224 */  addiu      $v0, $zero, 0x1
    /* 2B1C4 8003A9C4 03006214 */  bne        $v1, $v0, .L8003A9D4
    /* 2B1C8 8003A9C8 0102C634 */   ori       $a2, $a2, (0x1000201 & 0xFFFF)
    /* 2B1CC 8003A9CC 0001063C */  lui        $a2, (0x1000200 >> 16)
    /* 2B1D0 8003A9D0 0002C634 */  ori        $a2, $a2, (0x1000200 & 0xFFFF)
  .L8003A9D4:
    /* 2B1D4 8003A9D4 0580023C */  lui        $v0, %hi(D_8004FE34)
    /* 2B1D8 8003A9D8 34FE428C */  lw         $v0, %lo(D_8004FE34)($v0)
    /* 2B1DC 8003A9DC 00000000 */  nop
    /* 2B1E0 8003A9E0 000046AC */  sw         $a2, 0x0($v0)
    /* 2B1E4 8003A9E4 21100000 */  addu       $v0, $zero, $zero
  .L8003A9E8:
    /* 2B1E8 8003A9E8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 2B1EC 8003A9EC 1000B08F */  lw         $s0, 0x10($sp)
    /* 2B1F0 8003A9F0 0800E003 */  jr         $ra
    /* 2B1F4 8003A9F4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _spu_t
