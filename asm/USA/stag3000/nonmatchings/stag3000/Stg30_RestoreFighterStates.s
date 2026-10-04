nonmatching Stg30_RestoreFighterStates, 0xE0

glabel Stg30_RestoreFighterStates
    /* B410 8006E770 21400000 */  addu       $t0, $zero, $zero
    /* B414 8006E774 0780023C */  lui        $v0, %hi(Stg30_FighterStateBackup)
    /* B418 8006E778 503A4624 */  addiu      $a2, $v0, %lo(Stg30_FighterStateBackup)
    /* B41C 8006E77C 2168C000 */  addu       $t5, $a2, $zero
    /* B420 8006E780 0780023C */  lui        $v0, %hi(Stg30_Battle)
    /* B424 8006E784 C03C4C24 */  addiu      $t4, $v0, %lo(Stg30_Battle)
    /* B428 8006E788 21288001 */  addu       $a1, $t4, $zero
    /* B42C 8006E78C 2150C000 */  addu       $t2, $a2, $zero
    /* B430 8006E790 2148A000 */  addu       $t1, $a1, $zero
    /* B434 8006E794 21384001 */  addu       $a3, $t2, $zero
    /* B438 8006E798 21582001 */  addu       $t3, $t1, $zero
  .L8006E79C:
    /* B43C 8006E79C 18006325 */  addiu      $v1, $t3, 0x18
    /* B440 8006E7A0 2110E000 */  addu       $v0, $a3, $zero
    /* B444 8006E7A4 5000E424 */  addiu      $a0, $a3, 0x50
  .L8006E7A8:
    /* B448 8006E7A8 00004E8C */  lw         $t6, 0x0($v0)
    /* B44C 8006E7AC 04004F8C */  lw         $t7, 0x4($v0)
    /* B450 8006E7B0 0800588C */  lw         $t8, 0x8($v0)
    /* B454 8006E7B4 0C00598C */  lw         $t9, 0xC($v0)
    /* B458 8006E7B8 00006EAC */  sw         $t6, 0x0($v1)
    /* B45C 8006E7BC 04006FAC */  sw         $t7, 0x4($v1)
    /* B460 8006E7C0 080078AC */  sw         $t8, 0x8($v1)
    /* B464 8006E7C4 0C0079AC */  sw         $t9, 0xC($v1)
    /* B468 8006E7C8 10004224 */  addiu      $v0, $v0, 0x10
    /* B46C 8006E7CC F6FF4414 */  bne        $v0, $a0, .L8006E7A8
    /* B470 8006E7D0 10006324 */   addiu     $v1, $v1, 0x10
    /* B474 8006E7D4 00004E8C */  lw         $t6, 0x0($v0)
    /* B478 8006E7D8 04004F8C */  lw         $t7, 0x4($v0)
    /* B47C 8006E7DC 0800588C */  lw         $t8, 0x8($v0)
    /* B480 8006E7E0 00006EAC */  sw         $t6, 0x0($v1)
    /* B484 8006E7E4 04006FAC */  sw         $t7, 0x4($v1)
    /* B488 8006E7E8 080078AC */  sw         $t8, 0x8($v1)
    /* B48C 8006E7EC 2802428D */  lw         $v0, 0x228($t2)
    /* B490 8006E7F0 04004A25 */  addiu      $t2, $t2, 0x4
    /* B494 8006E7F4 5C00E724 */  addiu      $a3, $a3, 0x5C
    /* B498 8006E7F8 21180D01 */  addu       $v1, $t0, $t5
    /* B49C 8006E7FC 1C0322AD */  sw         $v0, 0x31C($t1)
    /* B4A0 8006E800 40026290 */  lbu        $v0, 0x240($v1)
    /* B4A4 8006E804 21200C01 */  addu       $a0, $t0, $t4
    /* B4A8 8006E808 400382A0 */  sb         $v0, 0x340($a0)
    /* B4AC 8006E80C 46026290 */  lbu        $v0, 0x246($v1)
    /* B4B0 8006E810 5C006B25 */  addiu      $t3, $t3, 0x5C
    /* B4B4 8006E814 460382A0 */  sb         $v0, 0x346($a0)
    /* B4B8 8006E818 4C02C294 */  lhu        $v0, 0x24C($a2)
    /* B4BC 8006E81C 01000825 */  addiu      $t0, $t0, 0x1
    /* B4C0 8006E820 5603A2A4 */  sh         $v0, 0x356($a1)
    /* B4C4 8006E824 5802C294 */  lhu        $v0, 0x258($a2)
    /* B4C8 8006E828 04002925 */  addiu      $t1, $t1, 0x4
    /* B4CC 8006E82C 6203A2A4 */  sh         $v0, 0x362($a1)
    /* B4D0 8006E830 6402C294 */  lhu        $v0, 0x264($a2)
    /* B4D4 8006E834 0200C624 */  addiu      $a2, $a2, 0x2
    /* B4D8 8006E838 6E03A2A4 */  sh         $v0, 0x36E($a1)
    /* B4DC 8006E83C 06000229 */  slti       $v0, $t0, 0x6
    /* B4E0 8006E840 D6FF4014 */  bnez       $v0, .L8006E79C
    /* B4E4 8006E844 0200A524 */   addiu     $a1, $a1, 0x2
    /* B4E8 8006E848 0800E003 */  jr         $ra
    /* B4EC 8006E84C 00000000 */   nop
endlabel Stg30_RestoreFighterStates
