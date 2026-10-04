nonmatching Stg10_StrNext, 0x104

glabel Stg10_StrNext
    /* CAC 8006400C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* CB0 80064010 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* CB4 80064014 21888000 */  addu       $s1, $a0, $zero
    /* CB8 80064018 1800B0AF */  sw         $s0, 0x18($sp)
    /* CBC 8006401C D0071024 */  addiu      $s0, $zero, 0x7D0
    /* CC0 80064020 2000BFAF */  sw         $ra, 0x20($sp)
    /* CC4 80064024 1000A427 */  addiu      $a0, $sp, 0x10
  .L80064028:
    /* CC8 80064028 79B8000C */  jal        StGetNext
    /* CCC 8006402C 1400A527 */   addiu     $a1, $sp, 0x14
    /* CD0 80064030 05004010 */  beqz       $v0, .L80064048
    /* CD4 80064034 FFFF1026 */   addiu     $s0, $s0, -0x1
    /* CD8 80064038 FBFF0016 */  bnez       $s0, .L80064028
    /* CDC 8006403C 1000A427 */   addiu     $a0, $sp, 0x10
    /* CE0 80064040 3F900108 */  j          .L800640FC
    /* CE4 80064044 21100000 */   addu      $v0, $zero, $zero
  .L80064048:
    /* CE8 80064048 0680023C */  lui        $v0, %hi(Stg10_MovieEndFrame)
    /* CEC 8006404C 1400A48F */  lw         $a0, 0x14($sp)
    /* CF0 80064050 0462428C */  lw         $v0, %lo(Stg10_MovieEndFrame)($v0)
    /* CF4 80064054 0800838C */  lw         $v1, 0x8($a0)
    /* CF8 80064058 00000000 */  nop
    /* CFC 8006405C 2B186200 */  sltu       $v1, $v1, $v0
    /* D00 80064060 04006014 */  bnez       $v1, .L80064074
    /* D04 80064064 0680103C */   lui       $s0, %hi(Stg10_StrWidth)
    /* D08 80064068 0680033C */  lui        $v1, %hi(Stg10_StrEndFlag)
    /* D0C 8006406C 01000224 */  addiu      $v0, $zero, 0x1
    /* D10 80064070 FC6162AC */  sw         $v0, %lo(Stg10_StrEndFlag)($v1)
  .L80064074:
    /* D14 80064074 10008394 */  lhu        $v1, 0x10($a0)
    /* D18 80064078 2052028E */  lw         $v0, %lo(Stg10_StrWidth)($s0)
    /* D1C 8006407C 00000000 */  nop
    /* D20 80064080 06004314 */  bne        $v0, $v1, .L8006409C
    /* D24 80064084 0680023C */   lui       $v0, %hi(Stg10_StrHeight)
    /* D28 80064088 12008394 */  lhu        $v1, 0x12($a0)
    /* D2C 8006408C 2452428C */  lw         $v0, %lo(Stg10_StrHeight)($v0)
    /* D30 80064090 00000000 */  nop
    /* D34 80064094 0B004310 */  beq        $v0, $v1, .L800640C4
    /* D38 80064098 0680023C */   lui       $v0, %hi(Stg10_StrWidth)
  .L8006409C:
    /* D3C 8006409C 4170000C */  jal        Gpu_ClearScreens
    /* D40 800640A0 00000000 */   nop
    /* D44 800640A4 1400A38F */  lw         $v1, 0x14($sp)
    /* D48 800640A8 00000000 */  nop
    /* D4C 800640AC 10006294 */  lhu        $v0, 0x10($v1)
    /* D50 800640B0 12006394 */  lhu        $v1, 0x12($v1)
    /* D54 800640B4 205202AE */  sw         $v0, %lo(Stg10_StrWidth)($s0)
    /* D58 800640B8 0680023C */  lui        $v0, %hi(Stg10_StrHeight)
    /* D5C 800640BC 245243AC */  sw         $v1, %lo(Stg10_StrHeight)($v0)
    /* D60 800640C0 0680023C */  lui        $v0, %hi(Stg10_StrWidth)
  .L800640C4:
    /* D64 800640C4 2052448C */  lw         $a0, %lo(Stg10_StrWidth)($v0)
    /* D68 800640C8 1000A28F */  lw         $v0, 0x10($sp)
    /* D6C 800640CC 40180400 */  sll        $v1, $a0, 1
    /* D70 800640D0 21186400 */  addu       $v1, $v1, $a0
    /* D74 800640D4 C2270300 */  srl        $a0, $v1, 31
    /* D78 800640D8 21186400 */  addu       $v1, $v1, $a0
    /* D7C 800640DC 0680043C */  lui        $a0, %hi(Stg10_StrHeight)
    /* D80 800640E0 24528494 */  lhu        $a0, %lo(Stg10_StrHeight)($a0)
    /* D84 800640E4 43180300 */  sra        $v1, $v1, 1
    /* D88 800640E8 240023A6 */  sh         $v1, 0x24($s1)
    /* D8C 800640EC 1C0023A6 */  sh         $v1, 0x1C($s1)
    /* D90 800640F0 260024A6 */  sh         $a0, 0x26($s1)
    /* D94 800640F4 1E0024A6 */  sh         $a0, 0x1E($s1)
    /* D98 800640F8 320024A6 */  sh         $a0, 0x32($s1)
  .L800640FC:
    /* D9C 800640FC 2000BF8F */  lw         $ra, 0x20($sp)
    /* DA0 80064100 1C00B18F */  lw         $s1, 0x1C($sp)
    /* DA4 80064104 1800B08F */  lw         $s0, 0x18($sp)
    /* DA8 80064108 0800E003 */  jr         $ra
    /* DAC 8006410C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel Stg10_StrNext
