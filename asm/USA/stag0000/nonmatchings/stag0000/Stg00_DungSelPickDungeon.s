nonmatching Stg00_DungSelPickDungeon, 0xDC

glabel Stg00_DungSelPickDungeon
    /* E80 800641E0 0680023C */  lui        $v0, %hi(Pad_Repeat)
    /* E84 800641E4 2CF74294 */  lhu        $v0, %lo(Pad_Repeat)($v0)
    /* E88 800641E8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* E8C 800641EC 1400B1AF */  sw         $s1, 0x14($sp)
    /* E90 800641F0 21888000 */  addu       $s1, $a0, $zero
    /* E94 800641F4 1000B0AF */  sw         $s0, 0x10($sp)
    /* E98 800641F8 2180A000 */  addu       $s0, $a1, $zero
    /* E9C 800641FC 00804230 */  andi       $v0, $v0, 0x8000
    /* EA0 80064200 06004010 */  beqz       $v0, .L8006421C
    /* EA4 80064204 1800BFAF */   sw        $ra, 0x18($sp)
    /* EA8 80064208 00000286 */  lh         $v0, 0x0($s0)
    /* EAC 8006420C 00000396 */  lhu        $v1, 0x0($s0)
    /* EB0 80064210 02004018 */  blez       $v0, .L8006421C
    /* EB4 80064214 FFFF6224 */   addiu     $v0, $v1, -0x1
    /* EB8 80064218 000002A6 */  sh         $v0, 0x0($s0)
  .L8006421C:
    /* EBC 8006421C 0680023C */  lui        $v0, %hi(Pad_Repeat)
    /* EC0 80064220 2CF74294 */  lhu        $v0, %lo(Pad_Repeat)($v0)
    /* EC4 80064224 00000000 */  nop
    /* EC8 80064228 00204230 */  andi       $v0, $v0, 0x2000
    /* ECC 8006422C 09004010 */  beqz       $v0, .L80064254
    /* ED0 80064230 0680023C */   lui       $v0, %hi(Pad_Circle)
    /* ED4 80064234 00000286 */  lh         $v0, 0x0($s0)
    /* ED8 80064238 00000396 */  lhu        $v1, 0x0($s0)
    /* EDC 8006423C 01004224 */  addiu      $v0, $v0, 0x1
    /* EE0 80064240 23004228 */  slti       $v0, $v0, 0x23
    /* EE4 80064244 02004010 */  beqz       $v0, .L80064250
    /* EE8 80064248 01006224 */   addiu     $v0, $v1, 0x1
    /* EEC 8006424C 000002A6 */  sh         $v0, 0x0($s0)
  .L80064250:
    /* EF0 80064250 0680023C */  lui        $v0, %hi(Pad_Circle)
  .L80064254:
    /* EF4 80064254 00F7428C */  lw         $v0, %lo(Pad_Circle)($v0)
    /* EF8 80064258 00000000 */  nop
    /* EFC 8006425C 12004018 */  blez       $v0, .L800642A8
    /* F00 80064260 200E043C */   lui       $a0, (0xE20000A >> 16)
    /* F04 80064264 0A008434 */  ori        $a0, $a0, (0xE20000A & 0xFFFF)
    /* F08 80064268 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* F0C 8006426C 020000A6 */  sh         $zero, 0x2($s0)
    /* F10 80064270 688E000C */  jal        Cd_GetFileEntry
    /* F14 80064274 040002A6 */   sh        $v0, 0x4($s0)
    /* F18 80064278 00000586 */  lh         $a1, 0x0($s0)
    /* F1C 8006427C 21202002 */  addu       $a0, $s1, $zero
    /* F20 80064280 80180500 */  sll        $v1, $a1, 2
    /* F24 80064284 21186500 */  addu       $v1, $v1, $a1
    /* F28 80064288 80180300 */  sll        $v1, $v1, 2
    /* F2C 8006428C 21186200 */  addu       $v1, $v1, $v0
    /* F30 80064290 00006684 */  lh         $a2, 0x0($v1)
    /* F34 80064294 6490010C */  jal        Stg00_LoadDungFile
    /* F38 80064298 21280002 */   addu      $a1, $s0, $zero
    /* F3C 8006429C 21202002 */  addu       $a0, $s1, $zero
    /* F40 800642A0 7745000C */  jal        Task_SetState1
    /* F44 800642A4 01000524 */   addiu     $a1, $zero, 0x1
  .L800642A8:
    /* F48 800642A8 1800BF8F */  lw         $ra, 0x18($sp)
    /* F4C 800642AC 1400B18F */  lw         $s1, 0x14($sp)
    /* F50 800642B0 1000B08F */  lw         $s0, 0x10($sp)
    /* F54 800642B4 0800E003 */  jr         $ra
    /* F58 800642B8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg00_DungSelPickDungeon
