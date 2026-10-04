nonmatching Digi_InitFromTable, 0x184

glabel Digi_InitFromTable
    /* E424 8001DC24 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* E428 8001DC28 1400B1AF */  sw         $s1, 0x14($sp)
    /* E42C 8001DC2C 2188A000 */  addu       $s1, $a1, $zero
    /* E430 8001DC30 1000B0AF */  sw         $s0, 0x10($sp)
    /* E434 8001DC34 2180C000 */  addu       $s0, $a2, $zero
    /* E438 8001DC38 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* E43C 8001DC3C C676000C */  jal        Enemy_FindSetById
    /* E440 8001DC40 1800B2AF */   sw        $s2, 0x18($sp)
    /* E444 8001DC44 0680033C */  lui        $v1, %hi(D_8005F788)
    /* E448 8001DC48 21904000 */  addu       $s2, $v0, $zero
    /* E44C 8001DC4C 88F7638C */  lw         $v1, %lo(D_8005F788)($v1)
    /* E450 8001DC50 00050224 */  addiu      $v0, $zero, 0x500
    /* E454 8001DC54 00FF6330 */  andi       $v1, $v1, 0xFF00
    /* E458 8001DC58 08006214 */  bne        $v1, $v0, .L8001DC7C
    /* E45C 8001DC5C 21200002 */   addu      $a0, $s0, $zero
    /* E460 8001DC60 03002016 */  bnez       $s1, .L8001DC70
    /* E464 8001DC64 01000224 */   addiu     $v0, $zero, 0x1
    /* E468 8001DC68 1F770008 */  j          .L8001DC7C
    /* E46C 8001DC6C 01001124 */   addiu     $s1, $zero, 0x1
  .L8001DC70:
    /* E470 8001DC70 02002216 */  bne        $s1, $v0, .L8001DC7C
    /* E474 8001DC74 21200002 */   addu      $a0, $s0, $zero
    /* E478 8001DC78 21880000 */  addu       $s1, $zero, $zero
  .L8001DC7C:
    /* E47C 8001DC7C E38B000C */  jal        Mem_Zero
    /* E480 8001DC80 5C000524 */   addiu     $a1, $zero, 0x5C
    /* E484 8001DC84 02000224 */  addiu      $v0, $zero, 0x2
    /* E488 8001DC88 000002A2 */  sb         $v0, 0x0($s0)
    /* E48C 8001DC8C 00111100 */  sll        $v0, $s1, 4
    /* E490 8001DC90 23105100 */  subu       $v0, $v0, $s1
    /* E494 8001DC94 40100200 */  sll        $v0, $v0, 1
    /* E498 8001DC98 21104202 */  addu       $v0, $s2, $v0
    /* E49C 8001DC9C 08004390 */  lbu        $v1, 0x8($v0)
    /* E4A0 8001DCA0 00000000 */  nop
    /* E4A4 8001DCA4 010003A2 */  sb         $v1, 0x1($s0)
    /* E4A8 8001DCA8 FF006430 */  andi       $a0, $v1, 0xFF
    /* E4AC 8001DCAC 0A004394 */  lhu        $v1, 0xA($v0)
    /* E4B0 8001DCB0 00000000 */  nop
    /* E4B4 8001DCB4 140003A6 */  sh         $v1, 0x14($s0)
    /* E4B8 8001DCB8 160003A6 */  sh         $v1, 0x16($s0)
    /* E4BC 8001DCBC 0C004294 */  lhu        $v0, 0xC($v0)
    /* E4C0 8001DCC0 00000000 */  nop
    /* E4C4 8001DCC4 180002A6 */  sh         $v0, 0x18($s0)
    /* E4C8 8001DCC8 D679000C */  jal        Digi_GetDefaultName
    /* E4CC 8001DCCC 1A0002A6 */   sh        $v0, 0x1A($s0)
    /* E4D0 8001DCD0 21284000 */  addu       $a1, $v0, $zero
    /* E4D4 8001DCD4 21200000 */  addu       $a0, $zero, $zero
    /* E4D8 8001DCD8 21180402 */  addu       $v1, $s0, $a0
  .L8001DCDC:
    /* E4DC 8001DCDC 2110A400 */  addu       $v0, $a1, $a0
    /* E4E0 8001DCE0 00004290 */  lbu        $v0, 0x0($v0)
    /* E4E4 8001DCE4 01008424 */  addiu      $a0, $a0, 0x1
    /* E4E8 8001DCE8 4C0062A0 */  sb         $v0, 0x4C($v1)
    /* E4EC 8001DCEC 0E008228 */  slti       $v0, $a0, 0xE
    /* E4F0 8001DCF0 FAFF4014 */  bnez       $v0, .L8001DCDC
    /* E4F4 8001DCF4 21180402 */   addu      $v1, $s0, $a0
    /* E4F8 8001DCF8 00111100 */  sll        $v0, $s1, 4
    /* E4FC 8001DCFC 23105100 */  subu       $v0, $v0, $s1
    /* E500 8001DD00 40100200 */  sll        $v0, $v0, 1
    /* E504 8001DD04 21104202 */  addu       $v0, $s2, $v0
    /* E508 8001DD08 12004390 */  lbu        $v1, 0x12($v0)
    /* E50C 8001DD0C 00000000 */  nop
    /* E510 8001DD10 0D0003A2 */  sb         $v1, 0xD($s0)
    /* E514 8001DD14 FF006430 */  andi       $a0, $v1, 0xFF
    /* E518 8001DD18 13004390 */  lbu        $v1, 0x13($v0)
    /* E51C 8001DD1C 00000000 */  nop
    /* E520 8001DD20 1C0003A6 */  sh         $v1, 0x1C($s0)
    /* E524 8001DD24 14004394 */  lhu        $v1, 0x14($v0)
    /* E528 8001DD28 00000000 */  nop
    /* E52C 8001DD2C 1E0003A6 */  sh         $v1, 0x1E($s0)
    /* E530 8001DD30 16004390 */  lbu        $v1, 0x16($v0)
    /* E534 8001DD34 00000000 */  nop
    /* E538 8001DD38 200003A6 */  sh         $v1, 0x20($s0)
    /* E53C 8001DD3C 17004390 */  lbu        $v1, 0x17($v0)
    /* E540 8001DD40 00000000 */  nop
    /* E544 8001DD44 220003A2 */  sb         $v1, 0x22($s0)
    /* E548 8001DD48 18004390 */  lbu        $v1, 0x18($v0)
    /* E54C 8001DD4C 00000000 */  nop
    /* E550 8001DD50 230003A2 */  sb         $v1, 0x23($s0)
    /* E554 8001DD54 19004290 */  lbu        $v0, 0x19($v0)
    /* E558 8001DD58 D67A000C */  jal        Digi_CalcMaxLevel
    /* E55C 8001DD5C 240002A2 */   sb        $v0, 0x24($s0)
    /* E560 8001DD60 0D000392 */  lbu        $v1, 0xD($s0)
    /* E564 8001DD64 0F0002A2 */  sb         $v0, 0xF($s0)
    /* E568 8001DD68 01000224 */  addiu      $v0, $zero, 0x1
    /* E56C 8001DD6C 03006214 */  bne        $v1, $v0, .L8001DD7C
    /* E570 8001DD70 64000524 */   addiu     $a1, $zero, 0x64
    /* E574 8001DD74 64770008 */  j          .L8001DD90
    /* E578 8001DD78 100000AE */   sw        $zero, 0x10($s0)
  .L8001DD7C:
    /* E57C 8001DD7C 0D000492 */  lbu        $a0, 0xD($s0)
    /* E580 8001DD80 21300000 */  addu       $a2, $zero, $zero
    /* E584 8001DD84 617A000C */  jal        Digi_GetExpToNextLevel
    /* E588 8001DD88 FFFF8424 */   addiu     $a0, $a0, -0x1
    /* E58C 8001DD8C 100002AE */  sw         $v0, 0x10($s0)
  .L8001DD90:
    /* E590 8001DD90 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* E594 8001DD94 1800B28F */  lw         $s2, 0x18($sp)
    /* E598 8001DD98 1400B18F */  lw         $s1, 0x14($sp)
    /* E59C 8001DD9C 1000B08F */  lw         $s0, 0x10($sp)
    /* E5A0 8001DDA0 0800E003 */  jr         $ra
    /* E5A4 8001DDA4 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Digi_InitFromTable
