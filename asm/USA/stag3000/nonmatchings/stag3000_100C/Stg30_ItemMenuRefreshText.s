nonmatching Stg30_ItemMenuRefreshText, 0x1EC

glabel Stg30_ItemMenuRefreshText
    /* 1FF4 80065354 B0FFBD27 */  addiu      $sp, $sp, -0x50
    /* 1FF8 80065358 3400B3AF */  sw         $s3, 0x34($sp)
    /* 1FFC 8006535C 21980000 */  addu       $s3, $zero, $zero
    /* 2000 80065360 0780023C */  lui        $v0, %hi(Stg30_ItemListTextPos)
    /* 2004 80065364 3800B4AF */  sw         $s4, 0x38($sp)
    /* 2008 80065368 90305424 */  addiu      $s4, $v0, %lo(Stg30_ItemListTextPos)
    /* 200C 8006536C 18000824 */  addiu      $t0, $zero, 0x18
    /* 2010 80065370 0780023C */  lui        $v0, %hi(Stg30_ItemMenuScroll)
    /* 2014 80065374 4400B7AF */  sw         $s7, 0x44($sp)
    /* 2018 80065378 F8375724 */  addiu      $s7, $v0, %lo(Stg30_ItemMenuScroll)
    /* 201C 8006537C 4000B6AF */  sw         $s6, 0x40($sp)
    /* 2020 80065380 58001624 */  addiu      $s6, $zero, 0x58
    /* 2024 80065384 4C00BFAF */  sw         $ra, 0x4C($sp)
    /* 2028 80065388 4800BEAF */  sw         $fp, 0x48($sp)
    /* 202C 8006538C 3C00B5AF */  sw         $s5, 0x3C($sp)
    /* 2030 80065390 3000B2AF */  sw         $s2, 0x30($sp)
    /* 2034 80065394 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 2038 80065398 2800B0AF */  sw         $s0, 0x28($sp)
    /* 203C 8006539C 2C00958C */  lw         $s5, 0x2C($a0)
  .L800653A0:
    /* 2040 800653A0 00000000 */  nop
    /* 2044 800653A4 2148B602 */  addu       $t1, $s5, $s6
    /* 2048 800653A8 21800000 */  addu       $s0, $zero, $zero
    /* 204C 800653AC 21F0E002 */  addu       $fp, $s7, $zero
    /* 2050 800653B0 2190A802 */  addu       $s2, $s5, $t0
    /* 2054 800653B4 21880002 */  addu       $s1, $s0, $zero
  .L800653B8:
    /* 2058 800653B8 0000C287 */  lh         $v0, 0x0($fp)
    /* 205C 800653BC 00000000 */  nop
    /* 2060 800653C0 21100202 */  addu       $v0, $s0, $v0
    /* 2064 800653C4 21182201 */  addu       $v1, $t1, $v0
    /* 2068 800653C8 00006290 */  lbu        $v0, 0x0($v1)
    /* 206C 800653CC 00000000 */  nop
    /* 2070 800653D0 1A004010 */  beqz       $v0, .L8006543C
    /* 2074 800653D4 0780023C */   lui       $v0, %hi(Stg30_ItemMenuColumn)
    /* 2078 800653D8 E8374684 */  lh         $a2, %lo(Stg30_ItemMenuColumn)($v0)
    /* 207C 800653DC 21204002 */  addu       $a0, $s2, $zero
    /* 2080 800653E0 03008A8A */  lwl        $t2, 0x3($s4)
    /* 2084 800653E4 00008A9A */  lwr        $t2, 0x0($s4)
    /* 2088 800653E8 00000000 */  nop
    /* 208C 800653EC 1B00AAAB */  swl        $t2, 0x1B($sp)
    /* 2090 800653F0 1800AABB */  swr        $t2, 0x18($sp)
    /* 2094 800653F4 1A00A297 */  lhu        $v0, 0x1A($sp)
    /* 2098 800653F8 2630D300 */  xor        $a2, $a2, $s3
    /* 209C 800653FC 21105100 */  addu       $v0, $v0, $s1
    /* 20A0 80065400 1A00A2A7 */  sh         $v0, 0x1A($sp)
    /* 20A4 80065404 00006590 */  lbu        $a1, 0x0($v1)
    /* 20A8 80065408 01000224 */  addiu      $v0, $zero, 0x1
    /* 20AC 8006540C 1000A2AF */  sw         $v0, 0x10($sp)
    /* 20B0 80065410 1400A0AF */  sw         $zero, 0x14($sp)
    /* 20B4 80065414 1A00A797 */  lhu        $a3, 0x1A($sp)
    /* 20B8 80065418 1800A297 */  lhu        $v0, 0x18($sp)
    /* 20BC 8006541C 2B300600 */  sltu       $a2, $zero, $a2
    /* 20C0 80065420 2000A8AF */  sw         $t0, 0x20($sp)
    /* 20C4 80065424 2400A9AF */  sw         $t1, 0x24($sp)
    /* 20C8 80065428 003C0700 */  sll        $a3, $a3, 16
    /* 20CC 8006542C B294010C */  jal        Stg30_OpenItemText
    /* 20D0 80065430 25384700 */   or        $a3, $v0, $a3
    /* 20D4 80065434 2400A98F */  lw         $t1, 0x24($sp)
    /* 20D8 80065438 2000A88F */  lw         $t0, 0x20($sp)
  .L8006543C:
    /* 20DC 8006543C 04005226 */  addiu      $s2, $s2, 0x4
    /* 20E0 80065440 01001026 */  addiu      $s0, $s0, 0x1
    /* 20E4 80065444 0300022A */  slti       $v0, $s0, 0x3
    /* 20E8 80065448 DBFF4014 */  bnez       $v0, .L800653B8
    /* 20EC 8006544C 0B003126 */   addiu     $s1, $s1, 0xB
    /* 20F0 80065450 04009426 */  addiu      $s4, $s4, 0x4
    /* 20F4 80065454 0C000825 */  addiu      $t0, $t0, 0xC
    /* 20F8 80065458 0200F726 */  addiu      $s7, $s7, 0x2
    /* 20FC 8006545C 01007326 */  addiu      $s3, $s3, 0x1
    /* 2100 80065460 0300622A */  slti       $v0, $s3, 0x3
    /* 2104 80065464 CEFF4014 */  bnez       $v0, .L800653A0
    /* 2108 80065468 3000D626 */   addiu     $s6, $s6, 0x30
    /* 210C 8006546C 0780053C */  lui        $a1, %hi(Stg30_ItemMenuRow)
    /* 2110 80065470 0780023C */  lui        $v0, %hi(Stg30_ItemMenuColumn)
    /* 2114 80065474 F037A524 */  addiu      $a1, $a1, %lo(Stg30_ItemMenuRow)
    /* 2118 80065478 0780033C */  lui        $v1, %hi(Stg30_ItemMenuScroll)
    /* 211C 8006547C E8374684 */  lh         $a2, %lo(Stg30_ItemMenuColumn)($v0)
    /* 2120 80065480 F8376324 */  addiu      $v1, $v1, %lo(Stg30_ItemMenuScroll)
    /* 2124 80065484 40200600 */  sll        $a0, $a2, 1
    /* 2128 80065488 21288500 */  addu       $a1, $a0, $a1
    /* 212C 8006548C 21188300 */  addu       $v1, $a0, $v1
    /* 2130 80065490 21208600 */  addu       $a0, $a0, $a2
    /* 2134 80065494 0000A284 */  lh         $v0, 0x0($a1)
    /* 2138 80065498 00006384 */  lh         $v1, 0x0($v1)
    /* 213C 8006549C 00210400 */  sll        $a0, $a0, 4
    /* 2140 800654A0 21104300 */  addu       $v0, $v0, $v1
    /* 2144 800654A4 21104400 */  addu       $v0, $v0, $a0
    /* 2148 800654A8 2110A202 */  addu       $v0, $s5, $v0
    /* 214C 800654AC 58004590 */  lbu        $a1, 0x58($v0)
    /* 2150 800654B0 00000000 */  nop
    /* 2154 800654B4 1200A010 */  beqz       $a1, .L80065500
    /* 2158 800654B8 0800A426 */   addiu     $a0, $s5, 0x8
    /* 215C 800654BC F400A28E */  lw         $v0, 0xF4($s5)
    /* 2160 800654C0 00000000 */  nop
    /* 2164 800654C4 12004510 */  beq        $v0, $a1, .L80065510
    /* 2168 800654C8 03000224 */   addiu     $v0, $zero, 0x3
    /* 216C 800654CC 0680033C */  lui        $v1, %hi(Stg30_ItemDescTextPos)
    /* 2170 800654D0 F400A5AE */  sw         $a1, 0xF4($s5)
    /* 2174 800654D4 1400A2AF */  sw         $v0, 0x14($sp)
    /* 2178 800654D8 EC336224 */  addiu      $v0, $v1, %lo(Stg30_ItemDescTextPos)
    /* 217C 800654DC 02004794 */  lhu        $a3, 0x2($v0)
    /* 2180 800654E0 EC336294 */  lhu        $v0, %lo(Stg30_ItemDescTextPos)($v1)
    /* 2184 800654E4 21300000 */  addu       $a2, $zero, $zero
    /* 2188 800654E8 1000A0AF */  sw         $zero, 0x10($sp)
    /* 218C 800654EC 003C0700 */  sll        $a3, $a3, 16
    /* 2190 800654F0 B294010C */  jal        Stg30_OpenItemText
    /* 2194 800654F4 25384700 */   or        $a3, $v0, $a3
    /* 2198 800654F8 44950108 */  j          .L80065510
    /* 219C 800654FC 00000000 */   nop
  .L80065500:
    /* 21A0 80065500 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 21A4 80065504 E26E000C */  jal        Text_Close
    /* 21A8 80065508 F400A2AE */   sw        $v0, 0xF4($s5)
    /* 21AC 8006550C F400A0AE */  sw         $zero, 0xF4($s5)
  .L80065510:
    /* 21B0 80065510 4C00BF8F */  lw         $ra, 0x4C($sp)
    /* 21B4 80065514 4800BE8F */  lw         $fp, 0x48($sp)
    /* 21B8 80065518 4400B78F */  lw         $s7, 0x44($sp)
    /* 21BC 8006551C 4000B68F */  lw         $s6, 0x40($sp)
    /* 21C0 80065520 3C00B58F */  lw         $s5, 0x3C($sp)
    /* 21C4 80065524 3800B48F */  lw         $s4, 0x38($sp)
    /* 21C8 80065528 3400B38F */  lw         $s3, 0x34($sp)
    /* 21CC 8006552C 3000B28F */  lw         $s2, 0x30($sp)
    /* 21D0 80065530 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 21D4 80065534 2800B08F */  lw         $s0, 0x28($sp)
    /* 21D8 80065538 0800E003 */  jr         $ra
    /* 21DC 8006553C 5000BD27 */   addiu     $sp, $sp, 0x50
endlabel Stg30_ItemMenuRefreshText
